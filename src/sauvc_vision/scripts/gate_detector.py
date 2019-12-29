#!/usr/bin/env python
# https://www.pyimagesearch.com/2018/11/19/mask-r-cnn-with-opencv/


# import the necessary packages
import numpy as np
import cv2 as cv
import os
import time

import rospy
from std_msgs.msg import String

image = cv.CreateMat(480, 640, cv.CV_8UC3)

def subscriber_callback(data):
	rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def detector():
    pub = rospy.Publisher('sauvc/vision/gate', String, queue_size=10)
    rospy.Subscriber("sauvc/vision/gate", String, subscriber_callback)
    rospy.init_node('gate_detector')
    rate = rospy.Rate(10) # 10hz

    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        detector()
    except rospy.ROSInterruptException:
        pass
