import cv2
import numpy as np
from matplotlib import pyplot as plt

img=cv2.imread('E:/python_opencv_test/messigray.png',0)
f = np.fft.fft2(img)#傅里叶变换
fshift = np.fft.fftshift(f)#沿两个方向平移N/2
#构建振幅
magnitude_spectrum = 20*np.log(np.abs(fshift))
plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(magnitude_spectrum, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()
