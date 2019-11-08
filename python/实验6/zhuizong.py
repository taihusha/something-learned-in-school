import cv2
import numpy as np
cap=cv2.VideoCapture(0)
es = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (9, 4))
while(1):
    # 获取每一帧
    ret,frame=cap.read()
    # 转换到HSV
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    # 设定蓝色的阈值
    lower_blue=np.array([110,50,50])
    upper_blue=np.array([130,255,255])
    # 根据阈值构建掩模
    kernel = np.ones((5,5),np.uint8)
    mask=cv2.inRange(hsv,lower_blue,upper_blue)
    #mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel) 
    #绘制轮廓
    conts,hierarchy =cv2.findContours(mask.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    cv2.drawContours(frame,conts,-1,(0,255,0),3)
    # 对原图像和掩模进行位运算  
    res=cv2.bitwise_and(frame,frame,mask=mask)
    frame = cv2.erode(frame,kernel,iterations = 1)
    frame = cv2.dilate(frame,kernel,iterations = 1)
    #frame = cv2.morphologyEx(frame, cv2.MORPH_OPEN, kernel) 
    # 显示图像
    cv2.imshow('frame',frame)
    cv2.imshow('mask',mask)
    cv2.imshow('res',res)
    k=cv2.waitKey(5)&0xFF
    if k==27:
        break
# 关闭窗口
cv2.destroyAllWindows()
