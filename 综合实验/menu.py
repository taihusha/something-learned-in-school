import tkinter as  tk
from tkinter import filedialog
from tkinter import *
import tkinter.messagebox
import numpy as np
import cv2

def imageReader1():
    '''打开选择文件夹对话框'''
    root = tk.Tk()
    root.withdraw()

    Filepath = filedialog.askopenfilename() #获得选择好的文件
    e1.set(Filepath)
def imageReader2():
    '''打开选择文件夹对话框'''
    root = tk.Tk()
    root.withdraw()

    Filepath = filedialog.askopenfilename() #获得选择好的文件
    e2.set(Filepath)
#function.边缘检测
def edgeDetection():
    Filepath=imgRE.get().strip()
    image=cv2.imread(Filepath,0)
    #构造一个3×3的结构元素 
    element = cv2.getStructuringElement(cv2.MORPH_RECT,(3, 3))
    dilate = cv2.dilate(image, element)
    erode = cv2.erode(image, element)

    #将两幅图像相减获得边，第一个参数是膨胀后的图像，第二个参数是腐蚀后的图像
    result = cv2.absdiff(dilate,erode)

    #上面得到的结果是灰度图，将其二值化以便更清楚的观察结果
    retval, result = cv2.threshold(result, 40, 255, cv2.THRESH_BINARY); 
    #反色，即对二值图每个像素取反
    result = cv2.bitwise_not(result); 
    #显示图像
    cv2.imshow("result",result); 
    save(Filepath,result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#function.图像去噪
def deNoising():
    Filepath=imgRE.get().strip()
    img=cv2.imread(Filepath)
    result=cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21)
    cv2.imshow('result',result)
    save(Filepath,result)
#function.透视变换
count = 0
vertex_list=[]
def myAffine(img,vertex_list):
    pts1 = np.float32(vertex_list)
    pts2 = np.float32([[0,0],[300,0],[300,300],[0,300]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(img, M, (500, 500))
    return dst
def mark_point(event,x,y,flags,img):
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
def perspectiveTransform():
    Filepath=imgRE.get().strip()
    img=cv2.imread(Filepath)
    cv2.namedWindow('image')
    cv2.setMouseCallback('image', mark_point,img)
    while 1:

        cv2.imshow('image', img)
        k = cv2.waitKey(1)
        if count==4:
            dst = myAffine(img,vertex_list)
            cv2.imshow('dst',dst)
        if k == 27:  # wait for ESC key to exit
            cv2.destroyAllWindows()
            break
        if k == 's':
            save(Filepath,dst)

#funciont.直方图均衡化
def equHist():
    Filepath=imgRE.get().strip()
    img1=cv2.imread(Filepath,0)
    img2=cv2.imread(Filepath)
    equ=cv2.equalizeHist(img1)
    # 彩色图像均衡化,需要分解通道 对每一个通道均衡化
    (b, g, r) = cv2.split(img2)
    bH = cv2.equalizeHist(b)
    gH = cv2.equalizeHist(g)
    rH = cv2.equalizeHist(r)
    # 合并每一个通道
    result = cv2.merge((bH, gH, rH))
    cv2.imshow('灰度图结果',equ)
    cv2.imshow("彩色图像结果", result)
    save(Filepath,result)
    cv2.waitKey(0)

#function.直方图规定化
def specificationHist():
    Filepath1=imgRE.get().strip()
    Filepath2=imgRE2.get().strip()
    img1=cv2.imread(Filepath1,1)
    img2=cv2.imread(Filepath2,1)
    img_hsv1 = cv2.cvtColor(img1, cv2.COLOR_BGR2HSV)     # bgr转hsv 
    img_hsv2 = cv2.cvtColor(img2, cv2.COLOR_BGR2HSV) 
    
    color = ('h', 's', 'v')
    for i, col in enumerate(color):
        # histr = cv2.calcHist([img_hsv1], [i], None, [256], [0, 256])
        hist1, bins = np.histogram(img_hsv1[:, :, i].ravel(), 256, [0, 256])  
        hist2, bins = np.histogram(img_hsv2[:, :, i].ravel(), 256, [0, 256])
        cdf1 = hist1.cumsum()  # 灰度值0-255的累计值数组
        cdf2 = hist2.cumsum()
        cdf1_hist = hist1.cumsum() / cdf1.max()  # 灰度值的累计值的比率
        cdf2_hist = hist2.cumsum() / cdf2.max()

        diff_cdf = [[0 for j in range(256)] for k in range(256)]  # diff_cdf 里是每2个灰度值比率间的差值
        for j in range(256):                                     
            for k in range(256):
                diff_cdf[j][k] = abs(cdf1_hist[j] - cdf2_hist[k])
        lut = [0 for j in range(256)]        # 映射表

        for j in range(256):
            min = diff_cdf[j][0]
            index = 0
            for k in range(256):            # 直方图规定化的映射原理
                if min > diff_cdf[j][k]:
                    min = diff_cdf[j][k]
                    index = k
            lut[j] = ([j, index])
        h = int(img_hsv1.shape[0])
        w = int(img_hsv1.shape[1])
        for j in range(h):                   # 对原图像进行灰度值的映射
            for k in range(w):
                img_hsv1[j, k, i] = lut[img_hsv1[j, k, i]][1]

    hsv_img1 = cv2.cvtColor(img_hsv1, cv2.COLOR_HSV2BGR)   # hsv转bgr
    hsv_img2 = cv2.cvtColor(img_hsv2, cv2.COLOR_HSV2BGR) 
    cv2.namedWindow('firstpic', 0)
    cv2.resizeWindow('firstpic', 670, 900)
    cv2.namedWindow('targetpic', 0)
    cv2.resizeWindow('targetpic', 670, 900)
    cv2.namedWindow('defpic', 0)
    cv2.resizeWindow('defpic', 670, 900)

    cv2.imshow('firstpic', img1)
    cv2.imshow('targetpic',img2)
    # cv2.imshow('img1', img_hsv1)
    cv2.imshow('defpic', hsv_img1)
    save(Filepath1,hsv_img1)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#function.图像匹配
def match():
    Filepath1=imgRE.get().strip()
    Filepath2=imgRE2.get().strip()
    target = cv2.imread(Filepath1)
    #读取模板图片
    template = cv2.imread(Filepath2)
    #获得模板图片的高宽尺寸
    theight, twidth = template.shape[:2]
    #执行模板匹配，采用的匹配方式cv2.TM_SQDIFF_NORMED
    result = cv2.matchTemplate(target,template,cv2.TM_SQDIFF_NORMED)
    #归一化处理
    cv2.normalize( result, result, 0, 1, cv2.NORM_MINMAX, -1 )
    #寻找矩阵（一维数组当做向量，用Mat定义）中的最大值和最小值的匹配结果及其位置
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    #匹配值转换为字符串
    #对于cv2.TM_SQDIFF及cv2.TM_SQDIFF_NORMED方法min_val越趋近与0匹配度越好，匹配位置取min_loc
    #对于其他方法max_val越趋近于1匹配度越好，匹配位置取max_loc
    strmin_val = str(min_val)
    #绘制矩形边框，将匹配区域标注出来
    #min_loc：矩形定点
    #(min_loc[0]+twidth,min_loc[1]+theight)：矩形的宽高
    #(0,0,225)：矩形的边框颜色；2：矩形边框宽度
    cv2.rectangle(target,min_loc,(min_loc[0]+twidth,min_loc[1]+theight),(0,0,225),2)
    #显示结果,并将匹配值显示在标题栏上
    cv2.imshow("match",template)
    cv2.imshow("MatchResult"+strmin_val,target)
    cv2.waitKey()
    cv2.destroyAllWindows()
#function.均值滤波处理
def blur():
    Filepath=imgRE.get().strip()
    img=cv2.imread(Filepath)
    blur5 = cv2.blur(img,(5,5))
    cv2.imshow('result',blur5)
    save(Filepath,blur5)
    cv2.waitKey()
    cv2.destroyAllWindows()
#function.添加文字
point=[0,0]
count2=0
def mark_positon(event,x,y,flags,img):
    global point,count2
    count2=0
    if event == cv2.EVENT_LBUTTONDOWN:
        point[0]=x
        point[1]=y
        print(point)
        count2=1
        return
def emotion():
    Filepath=imgRE.get().strip()
    text=imgRE2.get()
    img=cv2.imread(Filepath)
    addText=img.copy()
    cv2.namedWindow('image')
    cv2.setMouseCallback('image',mark_positon,img)
    l=len(point)
    while 1:
        cv2.imshow('image', img)
        k = cv2.waitKey(1)
        if count2==1:
            cv2.putText(addText,text,(point[l-2],point[l-1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,0), 2) 
            cv2.imshow('result',addText)

        if k == 27:  # wait for ESC key to exit
            cv2.destroyAllWindows()
            break
        if k == 's':
            save(Filepath,addText)
#functino.滤镜制作
#寻找最大轮廓，传入的是一个二值的黑白图
def filtersMake():
    Filepath=imgRE.get().strip()
    cloudpath=imgRE2.get().strip()
    src=cv2.imread(Filepath)
    sky_img=cv2.imread(cloudpath)
    hsv_img=cv2.cvtColor(src,cv2.COLOR_BGR2HSV)
    planes=cv2.split(hsv_img)
    planes[2]=cv2.equalizeHist(planes[2])
    mer_img=cv2.merge(planes)

    lower_red = np.array([100,48,40])
    upper_red = np.array([124,255,255])
    range_img=cv2.inRange(mer_img,lower_red,upper_red)

    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (10, 10))
    Erode_img=cv2.erode(range_img,kernel)
    Dilation_img = cv2.dilate(Erode_img, kernel)

    ret, mask = cv2.threshold(Dilation_img, 150, 255, cv2.THRESH_BINARY)
    notmask = cv2.bitwise_not(mask)
    frontpic = cv2.bitwise_and(src, src, mask=notmask)
    
    sky_resize=cv2.resize(sky_img,(src.shape[1],src.shape[0]))
    backimage = cv2.bitwise_and(sky_resize, sky_resize, mask=mask)
    merge_img = cv2.add(backimage, frontpic)
    cv2.imshow('src',src)
    cv2.imshow('new_img',merge_img)
    save(Filepath,merge_img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
#function.保存图片
def save(Filepath,img):
    if tk.messagebox.askyesno('提示', '要保存此图片吗'):
        x = Filepath.split(".", 1)
        cv2.imwrite(x[0]+"_2."+x[1],img)

window = tk.Tk()
window .title("图像处理软件")
window.geometry('500x300')
window.resizable(False,False)

fm1=Frame(window)
imgRL = tk.Label(fm1, text ="输入要处理的图片：")
imgRL.pack(side=LEFT)
e1 = StringVar()
imgRE = tk.Entry(fm1, show = None, width = 40, textvariable = e1)
imgRE.pack()
b_selFromF = tk.Button(fm1,text = "从文件夹查找", command=imageReader1)
b_selFromF.pack()
fm1.pack(side=TOP,fill=X)

fm2=Frame(window)
imgRL2 = tk.Label(fm2, text ="若进行直方图规定或图像匹配，则再输入一张处理的图片(制作表情包时此处输入文字)：")
imgRL2.pack()
e2 =StringVar()
imgRE2 = tk.Entry(fm2, show = None, width = 40, textvariable = e2)
imgRE2.pack()
b_selFromF2 = tk.Button(fm2,text = "从文件夹查找", command=imageReader2)
b_selFromF2.pack()
fm2.pack(side=TOP,fill=X)

fm3=Frame(window)
b_eD = tk.Button(fm3,text = "得到图像轮廓",command = edgeDetection,width=20)
b_eD.grid(row=0,column=0)
b_qz = tk.Button(fm3,text = "图像去噪",command = deNoising,width=20)
b_qz.grid(row=0,column=1)
b_ts = tk.Button(fm3,text = "透视变换",command = perspectiveTransform,width=20)
b_ts.grid(row=0,column=2)
b_zfjh = tk.Button(fm3,text = "直方图均衡化",command = equHist,width=20)
b_zfjh.grid(row=1,column=0)
b_zfgd = tk.Button(fm3,text = "直方图规定化",command = specificationHist,width=20)
b_zfgd.grid(row=1,column=1)
b_txpp = tk.Button(fm3,text = "图像匹配",command = match,width=20)
b_txpp.grid(row=1,column=2)
b_jzlb = tk.Button(fm3,text = "均值滤波",command = blur,width=20)
b_jzlb.grid(row=2,column=0)
b_bqzz = tk.Button(fm3,text = "表情包制作",command = emotion,width=20)
b_bqzz.grid(row=2,column=1)
b_ndmm = tk.Button(fm3,text = "滤镜制作",command = filtersMake,width=20)
b_ndmm.grid(row=2,column=2)
fm3.pack()


window.mainloop()