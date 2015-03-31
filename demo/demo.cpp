#include <sstream>
#include <string>
#include <iostream>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int h_min = 45;
int s_min = 65;
int v_min = 52;
int h_max = 75;
int s_max = 220;
int v_max = 89;

void on_trackbar(int, void*) {
    //cout << "on_trackbar called" << endl;
}

void createTrackbars() {
    namedWindow("Trackbars",0);
    createTrackbar("H_MIN", "Trackbars", &h_min, 255, on_trackbar);
    createTrackbar("H_MAX", "Trackbars", &h_max, 255, on_trackbar);
    createTrackbar("S_MIN", "Trackbars", &s_min, 255, on_trackbar);
    createTrackbar("S_MAX", "Trackbars", &s_max, 255, on_trackbar);
    createTrackbar("V_MIN", "Trackbars", &v_min, 255, on_trackbar);
    createTrackbar("V_MAX", "Trackbars", &v_max, 255, on_trackbar);

}

void morphOps (Mat src) {
    Mat tmp;
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3,3));
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8,8));
    erode(src, tmp, erodeElement);
    dilate(tmp, src, dilateElement);
}

int main() {
    Mat cameraFeed, hsv, mask, temp;
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    Moments moment;
    int x=0,y=0;
    bool track = false;
    VideoCapture cam;
    cam.open(0);
    createTrackbars();
    while (true) {
        cam >> cameraFeed;
        cvtColor(cameraFeed, hsv, COLOR_BGR2HSV);

        inRange(hsv, Scalar(h_min, s_min, v_min), Scalar(h_max, s_max, v_max), mask);
        morphOps(mask);
        mask.copyTo(temp);
        findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
        if(track && contours.size() > 0){
            int j, maxindex, maxarea=0, area;
            for(j=0; j< contours.size(); j++)
            {
                moment = moments((Mat)contours.at(j));
                area= moment.m00;
                if(area>maxarea)
                {
                    maxarea = area;
                    maxindex = j;
                }
            }
            moment = moments((Mat)contours.at(maxindex));
            x = moment.m10/maxarea;
            y = moment.m01/maxarea;
            circle(cameraFeed, Point(x,y), 20, Scalar(0,255,0), 2);
        }
        imshow("Camera", mask);
        imshow("CameraFeed", cameraFeed);

        char ch = waitKey(10);
        if (ch == 'q')
            exit(0);
        if (ch == 't')
            track = !track;
    }

    return 0;
}
