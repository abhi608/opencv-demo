#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  VideoCapture cam;
  cam.open(0);                      // Opens the in-built webcam
  Mat bgr;

  while (true) {
    cam >> bgr;                   // capture image from the camera
    imshow("bgr", bgr);        // display the image in matrix frame

    if ((char)waitKey(10)=='x') // press 'x' to exit
      exit(0);
  }
  return 0;
}
