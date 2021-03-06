# haralick-textural-feature-analysis

The Haralick texture features are used for image classification. These features capture information about the patterns that emerge in patterns of texture. The features are calculated by construction of a co-occurrence matrix that is traditionally computationally expensive. Once the co-occurrence matrix has been constructed, calculations of the 13 features are done.

![Haralick features](https://github.com/adipai/haralick-textural-feature-analysis/blob/master/form.gif)

### Angular Second Momentum
The ASM measures the local uniformity of the gray levels. When pixels are very similar, the ASM value will be large

### Contrast
Contrast (Moment 2 or standard deviation) is a measure of intensity or grey level variations between the reference pixel and its neighbour. Large contrast reflects large intensity differences in GLCM.

### Correlation
Correlation feature shows the linear dependency of gray level values in the cooccurrence matrix

### Sum of squares: variance
Sum of squares, puts relatively high weights on the elements that differ from the value of matrix.

### Inverse Difference moment
Inverse difference moment is the measure of local homogeneity

### Sum average
Sum average measures the sum of the average of all grey levels.

### Sum variance
Variance is a measure of heterogeneity and is strongly correlated to first order statistical variable such as standard deviation. Variance increases when the gray level values differ from their mean.

### Sum entropy
Sum Entropy, is a measure of non-uniformity in the image or the complexity of the texture.

### Entropy
Entropy measures the disorder of an image and it achieves its largest value when all elements in P matrix are equal

### Difference variance
The difference variance measure is defined as the variance of px−y, in a manner similar to its sum counterpart

### Difference entropy
The Difference Entropy is a measure of randomness or lack of structure or order in the image contrast.

### Information measures of correlation
Information measures of correlation is correlations of various parameters measured using different techniques

## Requirements
```
python 3.x - scipy, matplotlib, numpy
c/gcc compiler
```
## Execution
```
$python read_image.py
<input the image pathname>
<A text file called sample is created which has 2x2 matrix of grayscale representation of the image>
$gcc feature_calculations.c
```
## References
1.  R. M. Haralick, K. Shanmugam, and I. Dinstein, “Textural features for image classification,” IEEE Transactions on Systems, Man and  Cybernetics, vol. 3, no. 6, pp. 610–621, 1973.	

2.  R. M. Haralick, “Statistical and structural approaches to texture,” Proceedings of the IEEE, vol. 67, no. 5, pp. 786–804, 1979.

3.	https://www.hindawi.com/journals/ijbi/2015/267807/

4.	https://arxiv.org/pdf/1205.4831.pdf

5.	https://www.ijltet.org/wp-content/uploads/2013/11/38.pdf
