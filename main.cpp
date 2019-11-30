#include "opencv2/opencv.hpp"

int main()
{
    // cv::VideoCapture cap("/dev/v4l/by-id/usb-Dahua_Technology_A5131CU210_5K03135PAK00002-video-index0");
    cv::VideoCapture cap(1);
    cv::Mat mat;
    for(;;)
    {
        cap >> mat;
		cv::Mat grey;
        cv::cvtColor(mat, grey, CV_RGB2GRAY);
        cv::threshold(grey, grey, 170, 255, CV_THRESH_BINARY);
        cv::imshow("Video", mat);
		cv::imshow("grey",grey);
        if(cv::waitKey(10) >= 0) break;
    }
    return 0;
}

