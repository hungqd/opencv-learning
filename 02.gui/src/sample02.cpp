#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int blurAmount = 15;

void onChange(int pos, void *userInput)
{
    std::cout << "onChange(pos=" << pos << ")" << std::endl;
    if (pos < 0)
    {
        return;
    }
    cv::Mat imgBlur;
    cv::Mat *img = (cv::Mat *)userInput;
    cv::blur(*img, imgBlur, cv::Size(pos, pos));
    cv::imshow("Lena", imgBlur);
}

void onMouse(int event, int x, int y, int flags, void *userInput)
{
    std::cout << "onMouse(event=" << event
              << ", x= " << x
              << ", y= " << y
              << ", flags= " << flags << ")"
              << std::endl;
    if (event != cv::EVENT_LBUTTONDOWN)
    {
        return;
    }
    cv::Mat *img = (cv::Mat *)userInput;
    cv::circle(*img, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), 3);
    onChange(blurAmount, img);
}

int main()
{
    cv::Mat lena = cv::imread("../../data/lena.png");
    cv::namedWindow("Lena");
    cv::createTrackbar("Lena", "Lena", &blurAmount, 30, onChange, &lena);
    cv::setMouseCallback("Lena", onMouse, &lena);
    cv::imshow("Lena", lena);
    onChange(blurAmount, &lena);
    cv::waitKey(0);
    cv::destroyWindow("Lena");
    return 0;
}