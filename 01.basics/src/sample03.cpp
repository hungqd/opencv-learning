#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Types.
**/
int main()
{
    // Vec
    // Scalar.
    // Point.
    cv::Point2i p(3, 4);
    std::cout << "Point: " << p << ". norm: " << cv::norm(p) << std::endl;

    // Size.
    cv::Size s(100, 100);
    std::cout << "Size: " << s << ", area: " << s.area() << std::endl;

    // Rect.
    cv::Mat img = cv::imread("../../data/lena.png");
    cv::Rect rect_roi(0, 0, 300, 300);
    cv::Mat img_roi = img(rect_roi);
    cv::imshow("Image ROI", img_roi);

    // RotatedRect
    cv::Mat rect(600, 600, CV_8UC3, cv::Scalar(0));
    cv::RotatedRect rrect(cv::Point2f(300, 300), cv::Size2f(300, 150), 30);
    cv::Point2f vertices[4];
    rrect.points(vertices);
    for (int i = 0; i < 4; i++)
    {
        cv::line(rect, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
    }
    cv::Rect brect = rrect.boundingRect();
    cv::rectangle(rect, brect, cv::Scalar(255, 0, 0), 2);
    cv::imshow("Rect", rect);
    cv::waitKey();

    return 0;
}