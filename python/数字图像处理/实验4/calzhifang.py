import numpy as np 
import cv2
from matplotlib import pyplot as plt 

img=cv2.imread('E:/python_opencv_test/fig1.tif',0)
img2=cv2.imread('E:/python_opencv_test/fig2.tif',0)
#求累积直方图
hist,bins=np.histogram(img.flatten(),256,[0,256])
cdf=hist.cumsum()
cdf_normalized=cdf*hist.max()/cdf.max()
plt.plot(cdf_normalized,color='b')
plt.hist(img.flatten(),256,[0,256],color='r')
plt.xlim([0,256])
plt.legend(('cdf','histogram'),loc='upper left') 
plt.show()
#直方图均衡化
equ=cv2.equalizeHist(img2)
res=np.hstack((img2,equ))
cv2.imwrite('hist.jpg',res)
cv2.imshow('frame',res)
cv2.waitKey(0)
cv2.destroyAllWindows()
