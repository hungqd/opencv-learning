#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Writing to file storage.
**/
int main()
{
    cv::FileStorage fs("test.yml", cv::FileStorage::WRITE);
    int fps = 5;
    fs << "fps" << fps;
    cv::Mat m1 = cv::Mat::eye(2, 3, CV_32F);
    cv::Mat m2 = cv::Mat::ones(3, 2, CV_32F);
    cv::Mat result = (m1 + 1) * (m2 + 3);
    fs << "Result" << result;
    fs.release();

    cv::FileStorage fs2("test.yml", cv::FileStorage::READ);
    cv::Mat r;
    fs2["Result"] >> r;
    fs2.release();
    std::cout << r << std::endl;

    return 0;
}