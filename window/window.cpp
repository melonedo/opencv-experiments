#ifndef PRECOMPILE_CMAKE
#include <opencv2/opencv.hpp>
#endif

using namespace cv;

int main() {
    Mat img = imread("img/pic.jpg");
    namedWindow("unnamed", WINDOW_AUTOSIZE);
    imshow("unnamed", img);
    waitKey(0);
    return 0;
}
