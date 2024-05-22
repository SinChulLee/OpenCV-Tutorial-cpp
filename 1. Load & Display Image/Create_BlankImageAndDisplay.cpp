// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 빈 이미지 생성 및 표시
int main(int argc, char **argv)
{
    // 3개의 채널로 구성된 새로운 이미지를 생성
    // 이미지 depth -> 8bit
    // 800 x 600 해상도 (넓이 800, 높이 600)
    // 각 픽셀은 Blue, Green, Red에 대해 각각 (100, 250, 30) 값으로 초기화.
    Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));

    String windowName = "Window with Blank Image"; // window의 이름

    namedWindow(windowName); // window 생성

    imshow(windowName, image); // 생성된 window에 image 표시

    waitKey(0); // window에서 키 입력까지 wait

    destroyWindow(windowName); // 생성된 window destroy

    return 0;
}
