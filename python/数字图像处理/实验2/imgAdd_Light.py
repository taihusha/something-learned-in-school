import numpy as np 
import cv2
img1=cv2.imread('E:/python_opencv_test/flower2.jpg')
img2=cv2.imread('E:/python_opencv_test/diamond2.jpg')
img3=cv2.imread('E:/python_opencv_test/badwoman.jpg')

dst1=img1+img2
dst2=cv2.addWeighted(img1,0.7,img2,0.3,0)
img31=cv2.add(img3,80)
img32=cv2.subtract(img3,80)
img33=cv2.multiply(img3,1.5)
cv2.imshow('dst1',dst1)
cv2.imshow('dst2',dst2)
cv2.imshow('img',img3)
cv2.imshow('img1',img31)
cv2.imshow('img2',img32)
cv2.imshow('img3',img33)
cv2.waitKey(0)
cv2.destroyAllWindows()