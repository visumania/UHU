import cv2
import numpy as np
from matplotlib import pyplot as plt
import os
import sys

os.system("clear")

#LABORATORY 6

#TASK 1

#HOUGH TRANSFORM

filename = 'water_coins.jpg'
src = cv2.imread(cv2.samples.findFile(filename), cv2.IMREAD_COLOR)

gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
gray = cv2.medianBlur(gray, 5)

rows = gray.shape[0]
noCircles = 0 #Variable counter of circles
circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, rows / 8, param1=100, param2=30,minRadius=0, maxRadius=0)

if circles is not None:
    circles = np.uint16(np.around(circles))
    for i in circles[0, :]:
        center = (i[0], i[1])

        # circle center
        cv2.circle(src, center, 1, (0, 100, 100), 3)

        # circle outline
        radius = i[2]
        cv2.circle(src, center, radius, (0, 255, 0), 3)

        noCircles += 1

print("Number of circles are: " + str(noCircles))

cv2.imshow("detected circles", src)
cv2.waitKey(0)

#MORPHOLOGICAL FILTERS , DRAWCOUNTOURS AND FINDCOUNTOURS

filename = 'water_coins.jpg'
img = cv2.imread(filename)

kernel = np.ones((5,5),np.uint8)
erosion = cv2.erode(img,kernel,iterations = 1)
dilation = cv2.dilate(erosion,kernel,iterations = 1)
opening = cv2.morphologyEx(dilation, cv2.MORPH_OPEN, kernel)
closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)

LUV = cv2.cvtColor(closing, cv2.COLOR_BGR2LUV)
edges = cv2.Canny(LUV, 10, 100)

contours, hierarchy = cv2.findContours(edges,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

print("Number of Contours is: " + str(len(contours)))

cv2.drawContours(closing, contours, -2, (255, 0, 0), 6)
cv2.imshow('Countours', closing)

cv2.waitKey(0)

#TASK 2

img = cv2.imread('goat.jpg',0)
img2 = img.copy()
img3 = cv2.imread('ball.jpg',0)
template = cv2.imread('messi_face.jpg',0)
w, h = template.shape[::-1]

img3 = cv2.resize(img3,(w,h))

# All the 6 methods for comparison in a list
methods = ['cv2.TM_CCOEFF', 'cv2.TM_CCOEFF_NORMED', 'cv2.TM_CCORR',
            'cv2.TM_CCORR_NORMED', 'cv2.TM_SQDIFF', 'cv2.TM_SQDIFF_NORMED']

for meth in methods:
    img = img2.copy()
    method = eval(meth)

    # Apply template Matching
    res = cv2.matchTemplate(img,template,method)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

    # If the method is TM_SQDIFF or TM_SQDIFF_NORMED, take minimum
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc

    bottom_right = (top_left[0] + w, top_left[1] + h)

    cv2.rectangle(img,top_left, bottom_right, 255, 2)
    img[top_left[1]:top_left[1]+template.shape[0], top_left[0]:top_left[0]+template.shape[1]] = img3 

    plt.subplot(121),plt.imshow(res,cmap = 'gray')
    plt.title('Matching Result'), plt.xticks([]), plt.yticks([])
    plt.subplot(122),plt.imshow(img,cmap = 'gray')
    plt.title('Detected Point'), plt.xticks([]), plt.yticks([])
    plt.suptitle(meth)
    
    plt.show()

print("Finished.")