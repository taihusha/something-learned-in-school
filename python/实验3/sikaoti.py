import numpy as np 
import cv2
ix,iy=-1,-1
#x1,y1,x2,y2,x3,y3,x4,y4=-1,-1,-1,-1,-1,-1,-1,-1
drawing=False
count=0
img=cv2.imread('E:/python_opencv_test/dark_flower.tif')
rows,cols,ch=img.shape
rect=[[0,-1],[0,-1],[0,-1],[0,-1]]
def mousePick(event,x,y,flags,param):
    global ix,iy,drawing,rect,count,img
    if count<4:
        if event==cv2.EVENT_LBUTTONDOWN:
            rect[count]=[x,y]
            print(x,y)
        elif event==cv2.EVENT_LBUTTONUP:
            """  if count>0:
                cv2.line(img,(rect[count-1][0],rect[count-1][1]),(rect[count][0],rect[count][1]),(255,0,0),3)#线 """
            count=count+1
            print(count)
    if count==4:
        img2=img.copy()
        pts1=np.float32([rect[0],rect[1],rect[2]])
        pts2=np.float32([[0,0],[300,0],[0,300]])
        M=cv2.getAffineTransform(pts1,pts2)
        dst1=cv2.warpAffine(img2,M,(cols,rows))
        cv2.imshow('output',dst1)
        pts21 = np.float32([rect])#透视变换
        pts22 = np.float32([[0,0],[rows,0],[0,cols],[rows,cols]])
        M2=cv2.getPerspectiveTransform(pts21,pts22)
        dst2=cv2.warpPerspective(img2,M2,(cols,rows))
        cv2.imshow('out',dst2)
"""     if event==cv2.EVENT_LBUTTONDOWN:
        ix,iy=x,y
      #  rect[0] = [x,y]
        drawing=True
    elif event==cv2.EVENT_MOUSEMOVE and flags==cv2.EVENT_FLAG_LBUTTON:
        if drawing==True:
            img2=img.copy()
            pts1=np.float32([[ix,iy],[ix,y],[x,y]])
            pts2=np.float32([[ix,iy+50],[ix,y],[iy+50,ix+y]])
            M=cv2.getAffineTransform(pts1,pts2)
            dst1=cv2.warpAffine(img2,M,(cols,rows))
            cv2.imshow('output',dst1)

            pts21 = np.float32([[ix,iy],[ix,y],[x,y],[x,iy]])#透视变换
            pts22 = np.float32([[0,0],[300,0],[0,300],[300,300]])
            M2=cv2.getPerspectiveTransform(pts21,pts22)
            dst2=cv2.warpPerspective(img2,M2,(cols,rows))
            cv2.imshow('out',dst2)
    elif event==cv2.EVENT_LBUTTONUP:
        cv2.rectangle(img,(ix,iy),(x,y),(0,255,0),2)  """
       
        
cv2.namedWindow('original')
cv2.setMouseCallback('original',mousePick)
cv2.imshow('original',img)

cv2.waitKey(0)
cv2.destroyAllWindows()
