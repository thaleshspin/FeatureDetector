#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
//#include <cv.h>
//#include <highgui.h>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "img_processing.h"
#include "line_detection.h"
#include "line_feature_detection.h"
#include "feature_extraction.h"
#include "dis_ang_translation.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "clustering.h"

using namespace cv;
using namespace std;

#define VIDEO


int main(int argc, char **argv)
{
	vector<field_point> result_intersections;
	vector<goalposts> goalPosts;
	loadFile("clustering.txt");

#ifndef VIDEO
	Mat img_rgb;
	img_rgb = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	clustering(img_rgb);
	extract_features(img_rgb, result_intersections, goalPosts);
	for (int i = 0; i < goalPosts.size(); i++)
	{
		//cout << "Feature " << i << endl;
		//dis_bear test = pixel2dis_bear(normalizePixelPosition(img_rgb, goalPosts[i].root_position));
		//cout << "distance " << test.distance << endl;
		//cout << "angle " << test.bearing << endl;
		//cout << "--------------" << endl;
	}

	for (int i = 0; i < result_intersections.size(); i++)
	{
		//cout << "Intersection " << i << endl;
		//cout << result_intersections[i].position.y << endl;
		//cout << result_intersections[i].type << endl;
	}

	//imshow("va1", img_rgb);
	waitKey(0);
#endif
#ifdef VIDEO

	VideoCapture cap(argv[1]);

	// Check if camera opened successfully
	if (!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	while (1)
	{

		Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, bre ak immediately
		if (frame.empty())
			break;
		clustering(frame);
		extract_features(frame, result_intersections, goalPosts);
		for (int i = 0; i < goalPosts.size(); i++)
		{
			//cout << "Feature " << i << endl;
			//dis_bear test = pixel2dis_bear(normalizePixelPosition(img_rgb, goalPosts[i].root_position));
			//cout << "distance " << test.distance << endl;
			//cout << "angle " << test.bearing << endl;
			//cout << "--------------" << endl;
		}

		for (int i = 0; i < result_intersections.size(); i++)
		{
			//cout << "Intersection " << i << endl;
			//cout << result_intersections[i].position.y << endl;
			//cout << result_intersections[i].type << endl;
		}

		// Press  ESC on keyboard to exit
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	destroyAllWindows();

#endif
	return 0;
}
