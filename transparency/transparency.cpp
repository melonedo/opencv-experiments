#ifndef PRECOMPILE_CMAKE
#include <opencv2/opencv.hpp>
#endif

using namespace cv;

Mat background, foreground, mixed;

auto window_name = "transparency-slider";
auto trackbar_name = "transparency";

void slider_callback(int value, void*) {
  Range row_range{100, 100 + foreground.rows};
  Range col_range{100, 100 + foreground.cols};
  Mat dst = mixed(row_range, col_range);
  Mat src = background(row_range, col_range);
  addWeighted(src, 1. - value / 100., foreground, value / 100., 0, dst);
  imshow(window_name, mixed);
}

int main() {
  namedWindow(window_name, WINDOW_AUTOSIZE);
  background = imread("img/pic.jpg");
  Mat foreground_raw = imread("img/mark.jpg");
  mixed = background.clone();
  resize(foreground_raw, foreground, {200, 200});
  createTrackbar(trackbar_name, window_name, NULL, 100, slider_callback);
  // 会调用上述callback
  setTrackbarPos(trackbar_name, window_name, 50);
  waitKey();
  return 0;
}
