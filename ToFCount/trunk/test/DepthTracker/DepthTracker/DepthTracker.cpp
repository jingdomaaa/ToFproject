// DepthTracker.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/tracking.hpp>
using namespace std;
using namespace cv;
#pragma comment(lib, "opencv_highgui400d.lib")
#pragma comment(lib, "opencv_core400d.lib")
#pragma comment(lib, "opencv_imgproc400d.lib")
#pragma comment(lib, "opencv_imgcodecs400d.lib")
#pragma comment(lib, "opencv_videoio400d.lib")
#pragma comment(lib, "opencv_objdetect400d.lib")
#pragma comment(lib, "opencv_tracking400d.lib")

char data_root[] = "D:\\Datasets\\PeopleCounting";
char dataset_tag[] = "25_20160410_back";
char depth_data_file[] = "2016_04_09_21_16_19BackDepth.avi";
char depth_file_path[256];
cv::Mat image;
int main()
{
	int key;
	Mat im_color;
	Rect2d roi;
	// create a tracker object
	Ptr<Tracker> tracker = TrackerKCF::create();
	int frame_count = 0;
	int number_to_train_on = 20;
	//cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
	//cv::namedWindow("Color", cv::WINDOW_AUTOSIZE);
	sprintf(depth_file_path, "%s\\%s\\normal\\crowd\\%s", data_root, dataset_tag, depth_data_file);
	cv::VideoCapture cap;
	cap.open(depth_file_path);
	cap >> image;
	roi = selectROI("tracker", image);
	//quit if ROI was not selected
	if (roi.width == 0 || roi.height == 0)
	{
		cv::destroyAllWindows();
		exit(0);
	}
	// initialize the tracker
	tracker->init(image, roi);
	while (1) {
		cap >> image;
		if (!image.data)
		{
			cv::destroyAllWindows();
			exit(0);
		}
		
		// update the tracking result
		tracker->update(image, roi);
		// draw the tracked object
		rectangle(image, roi, Scalar(0, 255, 0), 2, 1);
		
		cout << frame_count << endl;
		//cv::imshow("Image", image);
		applyColorMap(image, im_color, COLORMAP_RAINBOW);
		cv::imshow("tracker", im_color);
		if ((key = cv::waitKey(7)) == 27 || key == 'q' || key == 'Q') 
			break; //Allow early exit on space, esc, q
		frame_count++;
		
	}
	//cv::destroyAllWindows();
	getchar();
}

