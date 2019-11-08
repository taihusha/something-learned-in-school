import numpy as np
import math
import cv2
def rgb2hsi(img_rgb):
    rows = int(img_rgb.shape[0])
    cols = int(img_rgb.shape[1])
    B, G, R = cv2.split(img_rgb)
    # 归一化到[0,1]
    B = B / 255.0
    G = G / 255.0
    R = R / 255.0
    img_hsi = img_rgb.copy()
    H, S, I = cv2.split(img_hsi)
    for i in range(rows):
        for j in range(cols):
            num = 0.5 * ((R[i, j] - G[i, j]) + (R[i, j] - B[i, j]))
            den = np.sqrt((R[i, j] - G[i, j]) ** 2 + (R[i, j] - B[i, j]) * (G[i, j] - B[i, j]))
            theta = float(np.arccos(num / den))
            if den == 0:
                H = 0
            elif B[i, j] <= G[i, j]:
                H = theta
            else:
                H = 2 * np.pi - theta
            min_RGB = min(min(B[i, j], G[i, j]), R[i, j])
            sum = B[i, j] + G[i, j] + R[i, j]
            if sum == 0:
                S = 0
            else:
                S = 1 - 3 * min_RGB / sum
            H = H / (2 * np.pi)
            I = sum / 3.0
# 为了便于理解，常常对结果做扩充，即 [0°，360°],[0,100],[0,255]
#            img_hsi[i, j, 0] = H * 360
#            img_hsi[i, j, 1] = S * 100
#            img_hsi[i, j, 2] = I * 255
# 或者为了便于计算直方图，都扩充为0~255（同RGB）
            img_hsi[i, j, 0] = H * 255
            img_hsi[i, j, 1] = S * 255
            img_hsi[i, j, 2] = I * 255
    return img_hsi
def HSI2RGB(hsi_img):
    """
    这是将HSI图像转化为RGB图像的函数
    :param hsi_img: HSI彩色图像
    :return: RGB图像
    """
    # 保存原始图像的行列数
    row = np.shape(hsi_img)[0]
    col = np.shape(hsi_img)[1]
    #对原始图像进行复制
    rgb_img = hsi_img.copy()
    #对图像进行通道拆分
    H,S,I = cv2.split(hsi_img)
    #把通道归一化到[0,1]
    [H,S,I] = [ i/ 255.0 for i in ([H,S,I])]
    R,G,B = H,S,I
    for i in range(row):
        h = H[i]*2*np.pi
        #H大于等于0小于120度时
        a1 = h >=0
        a2 = h < 2*np.pi/3
        a = a1 & a2         #第一种情况的花式索引
        tmp = np.cos(np.pi / 3 - h)
        b = I[i] * (1 - S[i])
        r = I[i]*(1+S[i]*np.cos(h)/tmp)
        g = 3*I[i]-r-b
        B[i][a] = b[a]
        R[i][a] = r[a]
        G[i][a] = g[a]
        #H大于等于120度小于240度
        a1 = h >= 2*np.pi/3
        a2 = h < 4*np.pi/3
        a = a1 & a2         #第二种情况的花式索引
        tmp = np.cos(np.pi - h)
        r = I[i] * (1 - S[i])
        g = I[i]*(1+S[i]*np.cos(h-2*np.pi/3)/tmp)
        b = 3 * I[i] - r - g
        R[i][a] = r[a]
        G[i][a] = g[a]
        B[i][a] = b[a]
        #H大于等于240度小于360度
        a1 = h >= 4 * np.pi / 3
        a2 = h < 2 * np.pi
        a = a1 & a2             #第三种情况的花式索引
        tmp = np.cos(5 * np.pi / 3 - h)
        g = I[i] * (1-S[i])
        b = I[i]*(1+S[i]*np.cos(h-4*np.pi/3)/tmp)
        r = 3 * I[i] - g - b
        B[i][a] = b[a]
        G[i][a] = g[a]
        R[i][a] = r[a]
    rgb_img[:,:,0] = B*255
    rgb_img[:,:,1] = G*255
    rgb_img[:,:,2] = R*255
    return rgb_img
img=cv2.imread('E:/python_opencv_test/Fig6.png',1)
cv2.imshow('original',img)
img_hsi=rgb2hsi(img)
cv2.imshow('orig',img_hsi)
H, S, I = cv2.split(img_hsi)
Ih=cv2.equalizeHist(I)
res=cv2.merge((H,S,Ih),)
cv2.imshow('result',res)
res2=HSI2RGB(res)
cv2.imshow('result_rgb',res2)
cv2.waitKey(0)
cv2.destroyAllWindows()