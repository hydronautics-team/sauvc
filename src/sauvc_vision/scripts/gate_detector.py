#!/usr/bin/env python
# https://www.pyimagesearch.com/2018/11/19/mask-r-cnn-with-opencv/


# import the necessary packages
import numpy as np
import cv2 as cv
import os
import time
import argparse

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--input", required=True,
	help="path to input video")
ap.add_argument("-n", "--network", required=True,
	help="base path to network directory")
ap.add_argument("-v", "--visualize", type=int, default=0,
	help="whether or not we are going to visualize each instance")
ap.add_argument("-c", "--confidence", type=float, default=0.5,
	help="minimum probability to filter weak detections")
args = vars(ap.parse_args())

# loading the labels
labelsPath = os.path.sep.join(["labels.txt"])
LABELS = open(labelsPath).read().strip().split("\n")

# load the set of colors that will be used when visualizing a given
# instance segmentation
colorsPath = os.path.sep.join(["colors.txt"])
COLORS = open(colorsPath).read().strip().split("\n")
COLORS = [np.array(c.split(",")).astype("int") for c in COLORS]
# COLORS = np.array(COLORS, dtype="uint8")

# derive the paths to the Mask R-CNN weights and model configuration
weightsPath = os.path.sep.join([args["network"],
	"frozen_inference_graph.pb"])
configPath = os.path.sep.join([args["network"],
	"opencv_graph.pbtxt"])

# load our NET from disk
print("[INFO] loading %s from disk..." % (args['network']))
cvNet = cv.dnn.readNetFromTensorflow(weightsPath, configPath)

# initialize the video stream
cap = cv.VideoCapture(args["input"])

# loop over frames from the video file stream
while (cap.isOpened()):
    # read the next frame from the file
    ret, frame = cap.read()
    
    # construct a blob from the input frame and then perform a
    # forward pass of the Mask R-CNN, giving us (1) the bounding box
    # coordinates of the objects in the image
    rows = frame.shape[0]
    cols = frame.shape[1]
    cvNet.setInput(cv.dnn.blobFromImage(frame, size=(300, 300), swapRB=True, crop=False))
    start = time.time()
    cvOut = cvNet.forward()
    end = time.time()

    # show timing information and volume information on NET
    print("[INFO] %s took {:.6f} seconds".format(end - start) % (args['network']))
    print("[INFO] boxes shape: {}".format(cvOut.shape))

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
        if confidence > args["confidence"]:
            # clone our original image so we can draw on it
            clone = frame.copy()
     
            # scale the bounding box coordinates back relative to the
            # size of the image and then compute the width and the height
            # of the bounding box
            box = cvOut[0, 0, i, 3:7] * np.array([cols, rows, cols, rows])
            (startX, startY, endX, endY) = box.astype("int")
            boxW = endX - startX
            boxH = endY - startY 
            cv.rectangle(frame, (startX, startY), (endX, endY), color, 4)  

            # draw the predicted label and associated probability of the
            # instance segmentation on the image
            text = "{}: {:.4f}".format(LABELS[classID], confidence)
            cv.putText(frame, text, (startX, startY - 5),
                cv.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
            # print (color)

    cv.imshow('img', frame)

    if cv.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv.destroyAllWindows()