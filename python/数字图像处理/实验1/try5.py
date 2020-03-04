import cv2
import numpy as np

mode =0
#创建回调函数
def OnMouse(event,x,y,flags,param):
    global x0,y0,x1,y1
    if mode==0 and event==cv2.EVENT_LBUTTONDOWN:
        x0, y0 = x, y
        cv2.circle(img, (x, y), 20, (255, 245, 190), 2)
        print('正在画圆\n')
        print("按键盘的'r'切换画矩形")

    if mode ==1 and event == cv2.EVENT_LBUTTONDOWN:
        x1,y1 =x,y
    elif mode == 1 and event == cv2.EVENT_MOUSEMOVE and flags == cv2.EVENT_FLAG_LBUTTON:
        print('正在绘制矩形')
        cv2.rectangle(img,(x1,y1),(x,y),(190,255,0),-1)

img = 255*np.ones((480,480,3),np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image',OnMouse)

while(1):
    cv2.imshow('image',img)
    k = cv2.waitKey(1)
    if k==ord('l'):
        mode=0
    elif k==ord('r'):
        mode = 1
    elif k==ord('t'):
        mode =2
    elif k==ord('q'):
        break
cv2.destroyAllWindows()
