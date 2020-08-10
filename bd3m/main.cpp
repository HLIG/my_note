#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/xphoto/bm3d_image_denoising.hpp>
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
    //Load an Image
    Mat img = imread("1.jpg", cv::IMREAD_GRAYSCALE);
    namedWindow("Image", cv::WINDOW_GUI_EXPANDED);
    imshow("Image", img);


    //Blur Effect
    GaussianBlur(img, img, cv::Size(3, 3), 0);
    cv::xphoto::bm3dDenoising(img, img);  // ???? 

    namedWindow("Output", cv::WINDOW_GUI_EXPANDED);
    imshow("Output", img);

    //Wait Key press
    cv::waitKey(0);

    //destroy
    cv::destroyWindow("Image");
    cv::destroyWindow("BlurEffect");

    return 0;
}