#include <iostream>
#include <opencv2/highgui.hpp>

int main()
{
    cv::Mat lena = cv::imread("../../data/lena.png");
    if (!lena.data)
    {
        std::cerr << "Can't load image" << std::endl;
        return -1;
    }
    cv::namedWindow("Lena", cv::WINDOW_NORMAL);
    cv::imshow("Lena", lena);
    cv::resizeWindow("Lena", 512, 512);
    cv::waitKey(0);
    cv::destroyWindow("Lena");

    for (int i = 0; i < 10; i++)
    {
        std::ostringstream ss;
        ss << "Photo" << i;
        cv::namedWindow(ss.str());
        cv::moveWindow(ss.str(), 20 * i, 20 * i);
        cv::imshow(ss.str(), lena);
    }
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}