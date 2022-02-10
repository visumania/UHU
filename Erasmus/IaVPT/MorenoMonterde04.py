import cv2
import numpy as np
import os


os.system("clear")

#LABORATORY 4

pathVideo = 'video.mp4'
kernel = np.ones((5,5),np.uint8)
video = cv2.VideoCapture(pathVideo)
fgbg = cv2.bgsegm.createBackgroundSubtractorMOG()

#We need to check if camera is opened previously or not
if(video.isOpened() == False):
    print("Error reading video file")

while(True):
    ret, frame = video.read()

    #Background subtraction
    LUV = cv2.cvtColor(frame, cv2.COLOR_BGR2LUV)
    fgmask = fgbg.apply(LUV)

    #Morphological filters
    opening = cv2.morphologyEx(fgmask, cv2.MORPH_OPEN, kernel)
    closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)

    #Countour detection and counting
    edges = cv2.Canny(closing, 10, 100)
    contours, hierarchy = cv2.findContours(edges,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    print("Number of contours is: " + str(len(contours)))
    cv2.drawContours(closing, contours, -1, (0, 230, 255), 6)

    cv2.imshow('test', closing)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video.release()
cv2.destroyAllWindows()

print("Finished.")