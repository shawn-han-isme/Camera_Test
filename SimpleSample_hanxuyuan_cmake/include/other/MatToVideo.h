#include <opencv2/opencv.hpp>
#include <iostream>
 
namespace sp
{
    class MatToVideo
    {
    private:
        /* data */
            VideoWriter  frame_writer; //定义OpenCV自带的写视频指针

    public:
        MatToVideo(/* args */);
        ~MatToVideo();
        int record(cv::Mat &input_frame);
    };
    
    MatToVideo::MatToVideo(/* args */)
    {
            //frame_writer = cvCreateVideoWriter("../Video/origin.avi",  CV_FOURCC('M','J','P','G'), 20.0, cvSize(320, 240), false);
            frame_writer.open("../Video/origin.avi",  CV_FOURCC('M','J','P','G'), 120, cvSize(640, 480), false);

    }
    
    MatToVideo::~MatToVideo()
    {
    }
    
    int MatToVideo:: record(cv::Mat &input_frame)
{
    // cv::VideoWriter writer("E:\\out.avi",CV_FOURCC('X','V','I','D'),20,cv::Size(320,240),true);//Size要和图片尺寸保持一致
    // char filename[50];
    // for (int i = 1; i < 644; i++)
    // {
    //     sprintf(filename,"E:\\pic\\%d.bmp",i);
    //     frame=cv::imread(filename);
    //     if(frame.empty())   break;
    //     writer<<frame;
    // }
    // std::cout<<"write end!"<<std::endl;
    // cv::destroyAllWindows();


    //初始化视频参数,参数意义分别为 文件名、压缩格式、帧率、分辨率、是否彩色视频(false代表灰度图)

    // cvWriteFrame(frame_writer, &IplImage(input_frame));
    // IplImage *qImg=&temp;
    IplImage temp = IplImage(input_frame);
    IplImage *qImg=&temp;
    frame_writer.write(input_frame);//cvWriteFrame(frame_writer, qImg);
    //IplImage temp = IplImage;
    //IplImage *qImg=&IplImage;

    char c = cv::waitKey(1);
          switch (c)
        {

             case 'q':
           {
               //cvReleaseVideoWriter(&frame_writer);
                      return -1;
                                    
        }

        }
}
}
