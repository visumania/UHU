import cv2
import numpy as np
import os

os.system("clear")

#LABORATORY 3

pathImage = "image.jpg"
image = cv2.imread(pathImage)
cv2.imshow("originalImage", image)

#IMAGE PROCESSING BASICS

"""gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
thresh = cv2.threshold(gray,127,255, cv2.THRESH_BINARY)
cv2.imshow("imageThresold", gray)
cv2.imwrite("out.bmp", image)

cv2.waitKey(0)"""

#MORPHOLOGICAL ALGORITHMS

"""image = cv2.imread(pathImage,0)
kernel = np.ones((5,5),np.uint8)
erosion = cv2.erode(image,kernel,iterations = 1)
dilation = cv2.dilate(image,kernel,iterations = 1)
opening = cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel)
closing = cv2.morphologyEx(image, cv2.MORPH_CLOSE, kernel)
gradient = cv2.morphologyEx(image, cv2.MORPH_GRADIENT, kernel)

cv2.imshow('imageErosion', erosion)
cv2.imshow('imageDilation', gradient)
cv2.imshow('imgageOpening', opening)
cv2.imshow('imgageClosing', closing)
cv2.imshow('imageGradient', gradient)

cv2.waitKey(0) """

#SHAPE DETECTION ALGORITHM

"""#Change the colour-space
LUV = cv2.cvtColor(image, cv2.COLOR_BGR2LUV)

#Find edges
edges = cv2.Canny(LUV, 10, 100)

#Find Contours
contours, hierarchy = cv2.findContours(edges,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

#Find Number of contours
print("Number of Contours is: " + str(len(contours)))

#Draw yellow border around two contours
cv2.drawContours(image, contours, 0, (0, 230, 255), 6)
cv2.drawContours(image, contours, 2, (0, 230, 255), 6)

#Show the image with contours
cv2.imshow('contoursImage', image)
cv2.waitKey(0)"""


#READING AND SAVING VIDEO

"""#Create an object to read from frontal camera
video = cv2.VideoCapture(0)

#We need to check if camera is opened previously or not
if(video.isOpened() == False):
    print("Error reading video file")

while(True):
    # Capturing frame-by-frame
    ret, frame = video.read()

    # Change the frame to gray
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

#When everything done, release the capture
video.release()
cv2.destroyAllWindows()

#Create an object to read from frontal camera
video = cv2.VideoCapture(0)

#We need to check if camera is opened previously or not
if(video.isOpened() == False):
    print("Error reading video file")

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))

while(video.isOpened()):
    ret, frame = video.read()

    if ret==True:
        frame = cv2.flip(frame,0)

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

# Release everything if job is finished
video.release()
out.release()
cv2.destroyAllWindows()"""

print("Finished.")