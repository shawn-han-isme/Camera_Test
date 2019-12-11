# include <opencv2/opencv.hpp>
#ifndef __unix__
#include <Winsock2.h>
#else
#include <arpa/inet.h>
#endif
#include "GenICam/System.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include "GenICam/GigE/GigECamera.h"
#include "GenICam/GigE/GigEInterface.h"
#include "Infra/PrintLog.h"
#include "StreamRetrieve.h"
#include "Memory/SharedPtr.h"
#include "include/Camera/video.h"
#include "include/Media/ImageConvert.h"
#include "other/MatToVideo.h"

# include "camera.hpp"

int main()
{
    //设置ROI参数
    
    // 默认值：
    // int64_t nX = 0;
    // int64_t nY = 0;
    // int64_t nWidth = 1280;
    // int64_t nHeight = 1024;

    int64_t nX = 320;
    int64_t nY = 256;
    int64_t nWidth = 640;
    int64_t nHeight = 512;


    cv::Mat mat;
    ICameraPtr cameraSptr; //相机流

    //实例内存流
    IStreamSourcePtr streamPtr = sp::startCamera(cameraSptr, nX, nY, nWidth, nHeight);
    sp::MatToVideo matToVideo;

    //开始转换Mat
    while (1)
    {
        mat = sp::getCvMat(streamPtr);
        matToVideo.record(mat);
        cv::imshow("video", mat);
        if(cv::waitKey(10) >= 0) break;
    }
    
    int camera_is_stoped = sp::stopCamera(cameraSptr);

    return 0;

}
