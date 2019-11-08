import numpy as np 
import cv2
img=cv2.imread('E:/python_opencv_test/flower1.jpg')
img2=cv2.imread('E:/python_opencv_test/flower1.jpg',0)
res1=cv2.resize(img,None,fx=0.5,fy=0.5,interpolation=cv2.INTER_CUBIC)
res3=cv2.resize(img2,None,fx=0.5,fy=0.5,interpolation=cv2.INTER_CUBIC)
height,width=img.shape[:2]
res2=cv2.resize(img,(2*width,2*height),interpolation=cv2.INTER_CUBIC)

M=cv2.getRotationMatrix2D((height/2,width/2),90,0.6)
dst=cv2.warpAffine(res3,M,(height,width))
while(1):
    cv2.imshow('res',img)
    cv2.imshow('res1',res1)
    cv2.imshow('res2',res2)
    cv2.imshow('after',dst)
    if cv2.waitKey(1)&0xFF==27:
        break
cv2.destroyAllWindows()