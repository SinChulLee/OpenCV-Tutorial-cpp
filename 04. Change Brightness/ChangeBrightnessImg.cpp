// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 이미지 파일 읽기
    Mat image = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png");

    // 파일 읽기 실패할 경우
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    Mat imageBrighnessHigh50;
    image.convertTo(imageBrighnessHigh50, -1, 1, 50); // 밝기 50 증가

    Mat imageBrighnessHigh100;
    image.convertTo(imageBrighnessHigh100, -1, 1, 100); // 밝기 100 증가

    Mat imageBrighnessLow50;
    image.convertTo(imageBrighnessLow50, -1, 1, -50); // 밝기 50 감소

    Mat imageBrighnessLow100;
    image.convertTo(imageBrighnessLow100, -1, 1, -100); // 밝기 100 감소

    // 이미지의 window name 정의
    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    // window 생성 및 열기
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    // 생성된 window 안에 이미지 표시
    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
    imshow(windowNameWithBrightnessHigh100, imageBrighnessHigh100);
    imshow(windowNameBrightnessLow50, imageBrighnessLow50);
    imshow(windowNameBrightnessLow100, imageBrighnessLow100);

    waitKey(0); // 키 입력까지 wait

    destroyAllWindows(); // 열린 모든 window 닫기

    return 0;
}