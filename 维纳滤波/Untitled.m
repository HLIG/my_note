close all
clear
RGB =imread('1.jpg');
I=rgb2gray(RGB);
figure(1);
subplot(1, 1, 1);
imshow(I);
title('original image');
J =imnoise(I, 'gaussian', 0,0.005);
figure(2);
subplot(1, 2, 1);
imshow(J);
title('gaussian blurred image')
J0=wiener2(J,[10,10]);
subplot(1, 2, 2);
imshow(J0);
title('image tracked with wiener fliter')



PSF1= fspecial('disk', 10);
K=imfilter(I, PSF1, 'circular', 'conv');
figure(4)
subplot(1, 2, 1)
imshow(K);
title(' Blurred Image');
K0=deconvwnr(K,PSF1);
subplot(1, 2, 2);
imshow(K0);
title('image tracked with wiener fliter')

