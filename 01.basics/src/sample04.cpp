#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // Construct a matrix.
    cv::Mat mat(cv::Size(5, 5), CV_32F);
    std::cout << mat << std::endl;

    // Construct matrix with initial value.
    cv::Mat mz = cv::Mat::zeros(5, 5, CV_32F);
    std::cout << mz << std::endl;
    cv::Mat mo = cv::Mat::ones(5, 5, CV_32F);
    std::cout << mo << std::endl;

    // Construct identity matrix.
    cv::Mat m = cv::Mat::eye(5, 5, CV_32F);
    std::cout << m << std::endl;

    // Matrix operations.
    cv::Mat a = cv::Mat::eye(cv::Size(3, 2), CV_32F);
    cv::Mat b = cv::Mat::ones(cv::Size(3, 2), CV_32F);
    cv::Mat c = a + b;
    std::cout << c << std::endl;
    cv::Mat d = a - b;
    std::cout << d << std::endl;

    cv::Mat m1= cv::Mat::eye(2,3, CV_32F); 
    cv::Mat m2= cv::Mat::ones(3,2, CV_32F);
    std::cout << m1 * 2 << std::endl;
    std::cout << m1.mul(cv::Mat::ones(2, 3, CV_32F)) << std::endl; // Element-wise multiplication.
    std::cout << m1 * m2 << std::endl;

    return 0;
}