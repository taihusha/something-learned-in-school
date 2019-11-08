import numpy as np 
import cv2
from matplotlib import pyplot as plt 
img=cv2.imread('E:/python_opencv_test/TIM20191019140345.png')

def hisEqulColor(img):
    ycrcb = cv2.cvtColor(img, cv2.COLOR_BGR2YCR_CB)
    channels = cv2.split(ycrcb)
    print(len(channels))
    cv2.equalizeHist(channels[0], channels[0])
    cv2.equalizeHist(channels[1], channels[1])
    cv2.equalizeHist(channels[2], channels[2])
    cv2.merge(channels, ycrcb)
    cv2.cvtColor(ycrcb, cv2.COLOR_YCR_CB2BGR, img)
    return img

cv2.imshow('im1', img)
cv2.waitKey(0)

eq = hisEqulColor(img)
cv2.imshow('image2',eq )
cv2.waitKey(0)
cv2.destroyAllWindows()