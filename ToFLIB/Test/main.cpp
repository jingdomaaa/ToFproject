
#include "ToFLIB.h"
#pragma comment(lib, "ToFLIB.lib")

#include <iostream>
using namespace std;

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
#pragma comment(lib, "opencv_highgui400.lib")
#pragma comment(lib, "opencv_core400.lib")


Mat frame_ir = Mat(480, 640, CV_8UC3);
char window_name_ir[] = "IR VIEW";

void IR_display(unsigned char* buffer)
{
	int position = 0;
	for (int i = 0; i < 480; i++)
	{
		for (int j = 0; j < 640; j++)
		{
			position = 2 * 640 * i + 2 * j;
			frame_ir.at<uchar>(i, j * 3 + 0) = *(buffer + position);
			frame_ir.at<uchar>(i, j * 3 + 1) = *(buffer + position);
			frame_ir.at<uchar>(i, j * 3 + 2) = *(buffer + position);
		}
	}
	imshow(window_name_ir, frame_ir);
	return;
}

int main()
{
	
	unsigned char* temp = NULL;
	int key = 0;

	while (1)
	{
		key = waitKey(3);
		if (key == 27) temp = uGetBuffer(STOP, STOP);
		else temp = uGetBuffer(NEARMODE, IRVIEW);

		if (temp == NULL) break;
		else IR_display(temp);
	}
	
	return 0;
}