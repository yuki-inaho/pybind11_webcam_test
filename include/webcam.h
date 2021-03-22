#pragma once
#include <opencv2/opencv.hpp>
#include <mutex>

class WebcamCpp
{
public:
    WebcamCpp(int32_t video_index);
    ~WebcamCpp();
    bool update();
    cv::Mat get();

private:
    cv::VideoCapture cam_;
    cv::Mat frame_;
    bool is_ready;
    std::mutex mtx_;
};