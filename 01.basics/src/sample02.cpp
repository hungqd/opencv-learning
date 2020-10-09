#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utility.hpp>

const char *keys = {
    "{help h usage ? || print this message}"
    "{@video || Video file, if not defined try to use webcamera}"};

/**
 * Reading videos and cameras.
**/
int main(int argc, char **argv)
{
    cv::CommandLineParser parser(argc, argv, keys);
    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    if (!parser.check())
    {
        parser.printErrors();
        return -1;
    }
    std::string videoFile = parser.get<std::string>(0);
    cv::VideoCapture cap;
    if (videoFile != "")
    {
        std::cout << "Opening video file: " << videoFile << std::endl;
        cap.open(videoFile);
    }
    else
    {
        std::cout << "Opening camera device..." << std::endl;
        cap.open(0);
    }
    if (!cap.isOpened())
    {
        std::cerr << "Failed to VideoCapture" << std::endl;
        return -1;
    }
    cv::namedWindow("Video", 1);
    while (true)
    {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        cv::imshow("Video", frame);
        if (cv::waitKey(30) >= 0)
        {
            break;
        }
    }
    cap.release();
}