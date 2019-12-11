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

# include "camera.hpp"

int main()
{
    cv::Mat mat;
    ICameraPtr cameraSptr;
    IStreamSourcePtr streamPtr = sp::startCamera(cameraSptr);

    //开始转换Mat
    while (1)
    {
        mat = sp::getCvMat(streamPtr);
        cv::imshow("video", mat);
        if(cv::waitKey(10) >= 0) break;
    }
    
    int camera_is_stoped = sp::stopCamera(cameraSptr);

    return 0;

}
