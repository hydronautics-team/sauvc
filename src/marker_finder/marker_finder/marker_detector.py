#!/usr/bin/env python3

from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import cv2
import numpy as np
import imutils

import rclpy
from rclpy.node import Node

from stingray_interfaces.msg import Bbox as marker_msg
from stingray_interfaces.msg import BboxArray as ObjectsArray
from stingray_interfaces.srv import SetEnableObjectDetection as detector_toggle_srv
from stingray_interfaces.srv import SetEnableObjectDetectionRequest as detector_toggle_req
from stingray_interfaces.srv import SetEnableObjectDetectionResponse as detector_toggle_res



class MarkerDetector(Node):
    def __init__(self):
        super().__init__("marker_finder")
        self.declare_parameter("~image_topic_name")
        self.declare_parameter("~box_topic_name")
        self.declare_parameter("~debug")
        self.declare_parameter("~debug_image_name")
        self.declare_parameter("~kernel")
        self.declare_parameter("~sigma")
        self.declare_parameter("~closure")
        self.declare_parameter("~light")
        self.declare_parameter("~grayness")

        self.image_sub = self.create_subscription(Image, 
                                                  self.get_parameter("~image_topic_name").get_parameter_value().string_value, 
                                                  self.image_callback, 
                                                  1)
        self.box_topic = self.create_publisher(ObjectsArray, 
                                               self.get_parameter("~box_topic_name").get_parameter_value().string_value, 
                                               1)

        self.service = self.create_service(detector_toggle_srv, 
                                           "marker_detection_switch", 
                                           self.enable_detector)
        self.detection_enabled = False

        if self.get_parameter("~debug").get_parameter_value().bool_value:
            self.image_pub = self.create_publisher(Image, 
                                                   self.get_parameter("~debug_image_name").get_parameter_value().string_value, 
                                                   1)
        
        
        self.cv_bridge = CvBridge()
        
    def image_callback(self, image_topic: Image, topic: str):
        try:
            if not self.detection_enabled:
                return
            
            cv_image = self.cv_bridge.imgmsg_to_cv2(image_topic, "bgr8")
            rect = self.detect_marker(cv_image)
            if bool(rect):
                msg = self.form_message(rect)
                msg_arr = ObjectsArray()
                msg_arr.objects.append(msg)
                self.box_topic.publish(msg_arr)
                
                if self.debug:
                    cv_image = self.draw_boundary(cv_image, rect)
                    
            ros_image = self.cv_bridge.cv2_to_imgmsg(cv_image, "bgr8")
            self.image_pub.publish(ros_image)
                
        except CvBridgeError as e:
            self.get_logger().error(e)
    
    def detect_marker(self, cv_image):
        processed_img = self.preprocess(cv_image)
        mask_img = self.create_mask(processed_img)
        return self.get_boundary(mask_img)
    
    def preprocess(self, raw_image):
        blurred = cv2.GaussianBlur(raw_image, (self.ksize, self.ksize), self.sigma)
        hls = cv2.cvtColor(blurred, cv2.COLOR_BGR2HLS)
        return hls
    
    def create_mask(self, processed_image):
        light_channel = np.array(processed_image[::1])
        max_light = light_channel.max()
        light_border_value = int(max_light * self.obj_light)

        saturation_channel = np.array(processed_image[:1:])
        max_saturation = saturation_channel.max()
        saturation_border_value = int(max_saturation * self.obj_gray)

        upper_white = np.array([255, 255, 255])
        lower_white = np.array([0, light_border_value, saturation_border_value])
        mask = cv2.inRange(processed_image, lower_white, upper_white)
        mask = cv2.dilate(mask, None, iterations=10)
        mask = cv2.erode(mask, None, iterations=10)
        return mask
    
    def get_boundary(self, mask_image):
        contours = cv2.findContours(mask_image, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        contours = imutils.grab_contours(contours)
        
        bounding_rectangles = []
        biggest_rectangle = []
        max_area = 0
        for contour in contours:
            approx_contour = cv2.approxPolyDP(contour, 15, True)
            bounding_rectangles.append(cv2.boundingRect(approx_contour))

            area = bounding_rectangles[-1][2] * bounding_rectangles[-1][3]
            if area > max_area:
                biggest_rectangle = bounding_rectangles[-1]
                max_area = area
        return biggest_rectangle
    
    def draw_boundary(self, cv_image, bounding_rectangle):
        color = (160, 32, 240)
        cv2.rectangle(cv_image, (int(bounding_rectangle[0]), int(bounding_rectangle[1])), \
        (int(bounding_rectangle[0]+bounding_rectangle[2]), int(bounding_rectangle[1]+bounding_rectangle[3])), color, 10)
        return cv_image
    
    def enable_detector(self, request: detector_toggle_req) -> detector_toggle_res:
        self.detection_enabled = request.enabled
        response = detector_toggle_res()
        response.success = True
        response.message = "Tamam"
        return response

    def form_message(self, bounding_rectangle) -> marker_msg:
        msg = marker_msg()
        msg.name = "marker"
        msg.confidence = 1
        msg.top_left_x = int(bounding_rectangle[0])
        msg.top_left_y = int(bounding_rectangle[1])
        msg.bottom_right_x = int(bounding_rectangle[0] + bounding_rectangle[2])
        msg.bottom_right_y = int(bounding_rectangle[1] + bounding_rectangle[3])
        return msg


def main(args=None):
    rclpy.init(args=args)

    marker_node = MarkerDetector()

    rclpy.spin(marker_node)

    marker_node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()