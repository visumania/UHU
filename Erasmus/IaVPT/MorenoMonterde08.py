import cv2
import numpy as np
import os
from matplotlib import pyplot as plt

os.system("clear")

# LABORATORY 8

pathVideo = "slow_traffic_small.mp4"

kernel = np.ones((5,5),np.uint8)
cap = cv2.VideoCapture(pathVideo)
fourcc = cv2.VideoWriter_fourcc(*'DIVX')

outTELEA = cv2.VideoWriter('TELEA.avi', fourcc, int(cap.get(5)), (int(cap.get(3)), int(cap.get(4))))
outNS = cv2.VideoWriter('NS.avi', fourcc, int(cap.get(5)), (int(cap.get(3)), int(cap.get(4))))

fgbg = cv2.bgsegm.createBackgroundSubtractorMOG()

while(cap.isOpened()):
    ret, frame = cap.read()
    grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    fgmask = fgbg.apply(grayFrame)
    opening = cv2.morphologyEx(fgmask, cv2.MORPH_OPEN, kernel)
    closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)
    dst_TELEA = cv2.inpaint(frame,closing,3,cv2.INPAINT_TELEA)
    dst_NS = cv2.inpaint(frame,closing,3,cv2.INPAINT_NS)

    #cv2.imshow('dst_TELEA', dst_TELEA)
    outTELEA.write(dst_TELEA)
    outNS.write(dst_NS)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


cap.release()
outTELEA.release()
outNS.release()
cv2.destroyAllWindows()

print("Finished.")