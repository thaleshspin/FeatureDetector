#ifndef HOUGH_LINE_DETECTION_H
#define HOUGH_LINE_DETECTION_H

#include <iostream>
#include <math.h>
#include <time.h>
//#include <cv.h>
//#include <highgui.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

void probabilistic_hough_trans(Mat src, vector<Vec4i> &lines);

#endif
