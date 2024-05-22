// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 이미지 파일 읽기
    Mat image = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\cat.jpg");

    // 파일 읽기에 실패할 경우
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력 까지 wait
        return -1;
    }

    String windowName = "The cat"; // window 창의 이름

    namedWindow(windowName); // window 생성

    imshow(windowName, image); // 생성된 window에 이미지 표시

    waitKey(0); // window에서 키입력까지 wait

    destroyWindow(windowName); // 생성된 window를 destroy

    return 0;
}
