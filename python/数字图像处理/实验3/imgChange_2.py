import numpy as np 
import cv2

img1=cv2.imread('E:/python_opencv_test/dark_flower.tif')
img2=cv2.imread('E:/python_opencv_test/shudu.png')

rows,cols,ch=img1.shape
pts11=np.float32([[50,50],[200,50],[50,200]])#仿射变换，变换前三个点的坐标
pts12=np.float32([[10,100],[200,50],[100,250]])#变换后三个点的坐标

pts21 = np.float32([[56,65],[368,52],[28,387],[389,390]])#透视变换
pts22 = np.float32([[56,65],[368,52],[28,387],[389,390]])

M1=cv2.getAffineTransform(pts11,pts12)
M2=cv2.getPerspectiveTransform(pts21,pts22)

dst1=cv2.warpAffine(img1,M1,(cols,rows))
dst2=cv2.warpPerspective(img2,M2,(200,200))
cv2.imshow('Input1',img1)
cv2.imshow('Output1',dst1)
cv2.imshow('Input2',img2)
cv2.imshow('Output2',dst2)

cv2.waitKey(0)
cv2.destroyAllWindows()