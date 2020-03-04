import numpy as np 
import cv2
img=np.zeros((512,512,3),np.uint8)
cv2.line(img,(0,0),(511,511),(255,0,0),5)#线
cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)#矩形
cv2.circle(img,(477,63),63,(0,0,255),-1)#圆
cv2.ellipse(img,(256,256),(100,50),0,0,180,255,-1)#椭圆
pts=np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)
pts=pts.reshape((-1,1,2))
cv2.polylines(img,[pts],True,(0,255,255))#多边形
cv2.imshow('image',img)
k=cv2.waitKey(0)
if k==27:
  cv2.destroyAllWindows()