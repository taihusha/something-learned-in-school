#import numpy as np 
#import cv2
#
#ix,iy=-1,-1
#drawing=False
#img=cv2.imread('flower.tif')
#rows,cols,ch=img.shape
#def mousePick(event,x,y,flags,param):
#    global ix,iy,drawing
#    rect = np.zeros((4, 2), dtype = "float32")
#    if event==cv2.EVENT_LBUTTONDOWN:
#        ix,iy=x,y
#      #  rect[0] = [x,y]
#        drawing=True
#    elif event==cv2.EVENT_MOUSEMOVE and flags==cv2.EVENT_FLAG_LBUTTON:
#        if drawing==True:
#            img2=img.copy()
#            pts1=np.float32([[ix,iy],[ix,y],[x,y]])
#            pts2=np.float32([[ix,iy+50],[ix,y],[iy+50,ix+y]])
#            M=cv2.getAffineTransform(pts1,pts2)#已知变换前与变换后的坐标，返回相应的变换矩阵
#            dst1=cv2.warpAffine(img2,M,(cols,rows))#根据变换矩阵，计算变换后的图像（输入图像，变换矩阵, 图像大小）
#            cv2.imshow('output',dst1)
#
#            pts21 = np.float32([[ix,iy],[ix,y],[x,y],[x,iy]])#透视变换
#            pts22 = np.float32([[0,0],[300,0],[0,300],[300,300]])
#            M2=cv2.getPerspectiveTransform(pts21,pts22)#已知变换前与变换后的坐标，返回相应的变换矩阵
#            dst2=cv2.warpPerspective(img2,M2,(cols,rows))#根据变换矩阵，计算变换后的图像
#            cv2.imshow('out',dst2)
##    elif event==cv2.EVENT_LBUTTONUP:
##        cv2.rectangle(img,(ix,iy),(x,y),(0,255,0),2) #画矩形
#       
#cv2.namedWindow('original')
#cv2.setMouseCallback('original',mousePick)
#cv2.imshow('original',img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()
import cv2
import numpy as np
count=0
def myAffine(img,vertex_list):
    pts1 = np.float32(vertex_list)
    pts2 = np.float32([[0,0],[300,0],[300,300],[0,300]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(img, M, (500, 500))
    return dst
def mark_point(event,x,y,flags,param):
    global count,vertex_list
    if count == 4:
        # print( vertex_list)
        cv2.line(img, (vertex_list[0][0],vertex_list[0][1]), (vertex_list[1][0],vertex_list[1][1]), (0, 0, 255), 1)
        cv2.line(img, (vertex_list[1][0],vertex_list[1][1]), (vertex_list[2][0], vertex_list[2][1]), (0, 0, 255), 1)
        cv2.line(img, (vertex_list[2][0], vertex_list[2][1]), (vertex_list[3][0], vertex_list[3][1]), (0, 0, 255), 1)
        cv2.line(img, (vertex_list[3][0], vertex_list[3][1]), (vertex_list[0][0], vertex_list[0][1]), (0, 0, 255), 1)
        return
    if event == cv2.EVENT_LBUTTONDOWN:
        cv2.circle(img,(x,y),1,(0, 0, 255),4)
        vertex_list.append([x,y])
        count=count+1
        print(x,y)


img = cv2.imread('E:/python_opencv_test/dark_flower.tif')
count = 0
vertex_list=[]
# img=np.zeros((512,512,3),np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image', mark_point)
while 1:

    cv2.imshow('image', img)
    k = cv2.waitKey(1)
    if count==4:
        dst = myAffine(img,vertex_list)
        cv2.imshow('dst',dst)
    if k == 27:  # wait for ESC key to exit
        cv2.destroyAllWindows()
        break