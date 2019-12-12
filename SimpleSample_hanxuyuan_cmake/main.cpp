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
    
    //默认值：
    int64_t nX = 0;
    int64_t nY = 0;
    int64_t nWidth = 1280;
    int64_t nHeight = 1024;

    
    // int64_t nX ;
    // int64_t nY ;
    // int64_t nWidth ;
    // int64_t nHeight;


    cv::Mat mat;
    ICameraPtr cameraSptr; //相机流

    //实例内存流
    IStreamSourcePtr streamPtr = sp::startCamera(cameraSptr, nX, nY, nWidth, nHeight);
    sp::MatToVideo matToVideo;
   
    // VideoWriter  frame_writer;
    // frame_writer.open("out.avi", //路径
    //                   VideoWriter::fourcc('X', '2', '6', '4'), //编码格式
    //                   120, //帧率
    //                   Size(640,
    //                        480));

    // if (!frame_writer.isOpened()) {
    //     cout << "VideoWriter open failed!" << endl;
    //     getchar();
    //     return -1;
    // }


    //开始转换Mat
    while (1)
    {
        mat = sp::getCvMat(streamPtr);
        //frame_writer.write(mat);
        matToVideo.record(mat);
        cv::imshow("video", mat);
        if(cv::waitKey(10) >= 0) break;
    }
    
    int camera_is_stoped = sp::stopCamera(cameraSptr);

    return 0;

}
