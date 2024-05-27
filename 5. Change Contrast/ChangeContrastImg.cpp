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

    // 파일 읽기에 실패할 경우
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    Mat imageContrastHigh2;
    image.convertTo(imageContrastHigh2, -1, 2, 0); // contrast를 2만큼 증가

    Mat imageContrastHigh4;
    image.convertTo(imageContrastHigh4, -1, 4, 0); // contrast를 4만큼 증가

    Mat imageContrastLow0_5;
    image.convertTo(imageContrastLow0_5, -1, 0.5, 0); // contrast를 0.5만큼 감소

    Mat imageContrastLow0_25;
    image.convertTo(imageContrastLow0_25, -1, 0.25, 0); // contrast를 0.25만큼 감소

    // 각 이미지들의 window names 정의
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    // 이미지들의 windows 생성 및 열기
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    // 생성된 windows안에 img들 표시
    imshow(windowNameOriginalImage, image);
    imshow(windowNameContrastHigh2, imageContrastHigh2);
    imshow(windowNameContrastHigh4, imageContrastHigh4);
    imshow(windowNameContrastLow0_5, imageContrastLow0_5);
    imshow(windowNameContrastLow0_25, imageContrastLow0_25);

    waitKey(0); // 키 입력까지 wait

    destroyAllWindows(); // 열려 있는 모든 windows 닫기(destroy)

    return 0;
}