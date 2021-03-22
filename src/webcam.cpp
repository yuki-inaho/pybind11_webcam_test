#include "webcam.h"

WebcamCpp::WebcamCpp(int32_t video_index)
{
    cam_ = cv::VideoCapture(video_index);
    if (!cam_.isOpened())
    {
        std::cerr << "!cam_.isOpened()" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    is_ready = false;
}

WebcamCpp::~WebcamCpp(){
    cam_.release();
}

bool WebcamCpp::update()
{
    mtx_.lock();
    bool status;
    status = cam_.read(frame_);
    is_ready = status;
    mtx_.unlock();
    return status;
}

cv::Mat WebcamCpp::get()
{
    mtx_.lock();
    cv::Mat frame_to_get = frame_.clone();
    is_ready = false;
    mtx_.unlock();
    return frame_to_get;
}
