#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int h_lo = 50;
int s_lo = 50;
int v_lo = 50;
int h_hi = 255;
int s_hi = 255;
int v_hi = 255;

int main() {
  VideoCapture cam;
  cam.open(0);                      // Opens the in-built webcam
  Mat bgr, hsv, mask, dst, kernel;
  kernel = getStructuringElement(MORPH_RECT, Size(7, 7), Point(-1, -1));

  while (true) {
    cam >> bgr;                   // capture image from the camera
    imshow("bgr", bgr);        // display the image in matrix frame
    cvtColor(bgr, hsv, COLOR_BGR2HSV);  // convert the image to HSV
    imshow("hsv", hsv);
    
    inRange(hsv, Scalar(h_lo, s_lo, v_lo), Scalar(h_hi, s_hi, v_hi), mask);
    erode(mask, mask, kernel);
    dilate(mask, mask, kernel);

    imshow("mask", mask);
    cvtColor(mask, mask, COLOR_GRAY2BGR);
    bitwise_and(mask, bgr, dst);
    imshow("dst", dst);



    if ((char)waitKey(10)=='x')
      exit(0);
  }
  return 0;
}
