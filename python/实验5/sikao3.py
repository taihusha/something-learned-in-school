import cv2
import numpy as np
from matplotlib import pyplot as plt
img=cv2.imread('E:/python_opencv_test/messigray.png',0)
#傅里叶变换
f = np.fft.fft2(img)
fshift1 = np.fft.fftshift(f)
#高通滤波设置
rows, cols = img.shape
crow,ccol = int(rows/2), int(cols/2)
fshift1[crow-30:crow+30, ccol-30:ccol+30] = 0
#傅里叶逆变换
f_ishift_h = np.fft.ifftshift(fshift1)
img_back = np.fft.ifft2(f_ishift_h)
img_back = np.abs(img_back)
#低通滤波设置
#傅里叶变换
dft = cv2.dft(np.float32(img), flags = cv2.DFT_COMPLEX_OUTPUT)
fshift2 = np.fft.fftshift(dft)
#设置低通滤波器
mask = np.zeros((rows, cols, 2), np.uint8)
mask[crow-30:crow+30, ccol-30:ccol+30] = 1
#掩膜图像和频谱图像乘积
f = fshift2 * mask
#傅里叶逆变换
ishift = np.fft.ifftshift(f)
iimg = cv2.idft(ishift)
img_di = cv2.magnitude(iimg[:,:,0], iimg[:,:,1])
#设置带通滤波器
mask1=np.ones(img.shape,np.uint8)
mask1[crow-30:crow+30,ccol-30:ccol+30]=0
mask2=np.zeros(img.shape,np.uint8)
mask2[crow-30:crow+30,ccol-30:ccol+30]=1
mask_d=mask1*mask2
#傅里叶逆变换
dft2=cv2.dft(np.float32(img),flags=cv2.DFT_COMPLEX_OUTPUT)
#f1=np.fft.fft2(img)
f1shift=np.fft.fftshift(dft2)
f1shift=f1shift*mask
f2shift=np.fft.ifftshift(f1shift)
imgdai=np.fft.ifft2(f2shift)
imgdai=np.abs(imgdai)
imgdai = 255-(imgdai-np.amin(imgdai))/(np.amax(imgdai)-np.amin(imgdai))
#图像合成
result=np.dstack([img_back,imgdai,img_di])
plt.subplot(141),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(142),plt.imshow(img_back, cmap = 'gray')
plt.title('Image after HPF'), plt.xticks([]), plt.yticks([])
plt.subplot(143),plt.imshow(img_di, cmap = 'gray')
plt.title('Image after LPF'), plt.xticks([]), plt.yticks([])
plt.subplot(144),plt.imshow(result)
plt.title('Out put Image'), plt.xticks([]), plt.yticks([])
plt.show()