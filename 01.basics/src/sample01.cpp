#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>

/**
 * Reading/writing image.
**/
int main()
{
    // cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_VERBOSE);
    // auto path = cv::samples::findFile("lena.jpg");
    // std::cout << "Path: " << path << std::endl;

    cv::Mat color = cv::imread("../../data/lena.png");
    cv::Mat gray = cv::imread("../../data/lena.png", cv::ImreadModes::IMREAD_GRAYSCALE);

    if (!color.data)
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    int rows = color.rows;
    int cols = color.cols;
    cv::Vec3b pixel = color.at<cv::Vec3b>(rows - 1, cols - 1);
    std::cout << "Pixel: " << pixel << std::endl;

    cv::imshow("Color Image", color);
    cv::waitKey(0);
}