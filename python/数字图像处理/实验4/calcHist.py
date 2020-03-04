import numpy as np 
import cv2
from matplotlib import pyplot as plt 
img=cv2.imread('E:/python_opencv_test/flowers.tif',0)
img2=cv2.imread('E:/python_opencv_test/flowers.tif',1)
#cv2:calcHist(images; channels; mask; histSize; ranges[; hist[; accumulate]])
#统计直方图  hist=cv2.calcHist([img],[0],None,[256],[0,256])
#hist,bins = np.histogram(img.ravel(),256,[0,256])
color=('b','g','r')
for i,col in enumerate(color):
    histr=cv2.calcHist([img2],[i],None,[256],[0,256])
    plt.plot(histr,color=col)
    plt.xlim([0,256])
plt.hist(img.ravel(),256,[0,256])
plt.show()