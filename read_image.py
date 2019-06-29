from scipy import misc

import matplotlib.pyplot as plt

import matplotlib.cm as cm

import numpy as np


#function to find average of pixels

def average(pixel):

return (pixel[0] + pixel[1] + pixel[2]) / 3


#init image

pathname=input("ENTER PATH OF IMAGE:")

image=misc.imread(pathname)


#to display image

plt.imshow(image)

plt.show()


#init 2D numpy array

gray = np.zeros((image.shape[0], image.shape[1]))


#to find the grey scale image with absolute integer values for rownum in range(len(image)):
for colnum in range(len(image[rownum])):

gray[rownum][colnum] = int(round(average(image[rownum][colnum])))


#to display grayscale image

plt.imshow(gray, cmap = cm.Greys_r)

plt.show()


#write grayscale values into file filename=input("ENTER NAME OF FILE:") np.savetxt(filename,gray,fmt=‘%i',delimiter=',',newline='\r\n')
