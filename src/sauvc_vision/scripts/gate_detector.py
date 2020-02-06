#!/usr/bin/env python
# https://www.pyimagesearch.com/2018/11/19/mask-r-cnn-with-opencv/

# import the necessary packages
import rospy
import rospkg
import cv2 as cv
from cv_bridge import CvBridge, CvBridgeError
import numpy as np
import time
import os

from sensor_msgs.msg import Image

class gate_detector:
	def __init__(self, topic, device, confidence):
		self.bridge = CvBridge()
		self.image_sub = rospy.Subscriber(topic, Image, self.callback, queue_size=1)
		# get ros parameters
		self.device = device
		self.confidence = confidence
		# other
		rospack = rospkg.RosPack()
		rospack.list() 
		path = rospack.get_path('sauvc_vision')
		self.labels = path + "/net/labels.txt"
		self.colors = path + "/net/colors.txt"
		self.weights = path + "/net/frozen_inference_graph.pb"
		self.config = path + "/net/opencv_graph.pbtxt"
		rospy.loginfo(self.labels)
		rospy.loginfo(os.getcwd())
	
	def callback(self,data):
		try:
			cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
			self.detector(cv_image)
			rospy.loginfo(rospy.get_caller_id())
		except CvBridgeError as e:
			print(e)
		cv.imshow("Image window", cv_image)
		cv.waitKey(3)

	def detector(self, image):
		# loading the labels
		LABELS = open(self.labels).read().strip().split("\n")

		# load the set of colors that will be used when visualizing a given
		# instance segmentation
		COLORS = open(self.colors).read().strip().split("\n")
		COLORS = [np.array(c.split(",")).astype("int") for c in COLORS]

		# load our NET from disk
		rospy.loginfo("loading NET from disk...")
		cvNet = cv.dnn.readNetFromTensorflow(self.weights, self.config)

		# construct a blob from the input image and then perform a
		# forward pass, giving us the bounding box
		# coordinates of the objects in the image
		rows = image.shape[0]
		cols = image.shape[1]
		cvNet.setInput(cv.dnn.blobFromImage(image, size=(300, 300), swapRB=True, crop=False))
		start = time.time()
		cvOut = cvNet.forward()
		end = time.time()

		# show timing information and volume information on NET
		rospy.loginfo("Took {:.6f} seconds".format(end - start))
		rospy.loginfo("Boxes shape: {}".format(cvOut.shape))

		# loop over the number of detected objects
		for i in range(0, cvOut.shape[2]):
			# extract the class ID of the detection along with the confidence
			# (i.e., probability) associated with the prediction
			classID = int(cvOut[0, 0, i, 1])
			confidence = cvOut[0, 0, i, 2]
			color = COLORS[classID]
			color = [int(c) for c in color]

			# filter out weak predictions by ensuring the detected probability
			# is greater than the minimum probability
			if confidence > self.confidence:
				# scale the bounding box coordinates back relative to the
				# size of the image and then compute the width and the height
				# of the bounding box
				box = cvOut[0, 0, i, 3:7] * np.array([cols, rows, cols, rows])
				(startX, startY, endX, endY) = box.astype("int")
				boxW = endX - startX
				boxH = endY - startY 
				cv.rectangle(image, (startX, startY), (endX, endY), color, 4)  

				# draw the predicted label and associated probability of the
				# instance segmentation on the image
				text = "{}: {:.4f}".format(LABELS[classID], confidence)
				cv.putText(image, text, (startX, startY - 5),
					cv.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
				# print (color)

if __name__ == '__main__':
	rospy.init_node('gate_detector')
	# parameters
	source_topic = rospy.get_param('~source_topic')
	video_device = rospy.get_param('~video_device')
	net_confidence = int(rospy.get_param('~net_confidence'))
	
	try:
		gt = gate_detector(source_topic, video_device, net_confidence)
		rospy.spin()
	except rospy.ROSInterruptException:
		print("Shutting down")
	cv.destroyAllWindows()
