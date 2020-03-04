import numpy as np
import cv2
cap = cv2.VideoCapture(0)
cap.set(5,10)
# 要替换的背景
img_back=cv2.imread('E:/python_opencv_test/hust.jpg')
fourcc = cv2.VideoWriter_fourcc(*'XVID')
while True:
    ret,frame = cap.read()
    if ret == False:
        continue
    #获取图片的尺寸
    rows, cols, channels = frame.shape
 
    lower_color = np.array([120, 120, 120])
    upper_color = np.array([250, 250, 250])
    # 创建掩图
    fgmask = cv2.inRange(frame, lower_color, upper_color)
    cv2.imshow('Mask', fgmask)
 
    # 腐蚀膨胀
    erode = cv2.erode(fgmask, None, iterations=1)
    cv2.imshow('erode', erode)
    dilate = cv2.dilate(erode, None, iterations=1)
    cv2.imshow('dilate', dilate)
 
    rows, cols = dilate.shape
    img_back=img_back[0:rows,0:cols]
    #print(img_back)
    # #根据掩图和原图进行抠图
    img2_fg = cv2.bitwise_and(img_back, img_back, mask=dilate)
    Mask_inv = cv2.bitwise_not(dilate)
    img3_fg = cv2.bitwise_and(frame, frame, mask=Mask_inv)
    finalImg=img2_fg+img3_fg
    cv2.imshow('res', finalImg)
 
    k = cv2.waitKey(10) & 0xFF
    if k == 27:
        break
    if k==ord('s'):
        out =cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))
cap.release()
cv2.destroyAllWindows()
