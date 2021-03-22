#pragma once

#include <opencv2/opencv.hpp>
#include <mutex>
#include "struct.h"
#include "string.h"

class WebcamCpp
{
public:
    WebcamCpp(CameraInformation camera_info);
    ~WebcamCpp();
    bool update();
    cv::Mat get();

private:
    cv::VideoCapture cam_;
    cv::Mat frame_;
    bool is_ready;
    CameraInformation camera_info_;
    std::mutex mtx_;
};