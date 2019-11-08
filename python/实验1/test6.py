import numpy as np 
import cv2 
mode=False
def mouseClick(event,x,y,flags,param):
    global mode
    if event==cv2.EVENT_LBUTTONDOWN:
        
        mode=not mode
cv2.namedWindow('frame')
cap = cv2.VideoCapture('E:/python_opencv_test/vtest.avi')
cv2.setMouseCallback('frame',mouseClick)
while(cap.isOpened()):
    ret,frame = cap.read()
    if ret:
        if mode==True:
            cv2.putText(frame,"opencv",(210,540), cv2.FONT_HERSHEY_SIMPLEX, 1, (55,255,155), 2)
      #  cv2.putText(frame,"opencv",(210,540), cv2.FONT_HERSHEY_SIMPLEX, 1, (55,255,155), 2)
        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
cap.release()
cv2.destroyAllWindows()