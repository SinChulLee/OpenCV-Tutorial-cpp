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

    // 3x3 kernel 이미지 blur
    Mat image_blurred_with_3x3_kernel;
    blur(image, image_blurred_with_3x3_kernel, Size(3, 3));

    // 5x5 kernel 이미지 blur
    Mat image_blurred_with_5x5_kernel;
    blur(image, image_blurred_with_5x5_kernel, Size(5, 5));

    // windows names 정의
    String window_name = "The Guitar";
    String window_name_blurred_with_3x3_kernel = "The Guitar Blurred with 3 x 3 Kernel";
    String window_name_blurred_with_5x5_kernel = "The Guitar Blurred with 5 x 5 Kernel";

    // 위의 names를 가진 windows 생성
    namedWindow(window_name);
    namedWindow(window_name_blurred_with_3x3_kernel);
    namedWindow(window_name_blurred_with_5x5_kernel);

    // 생성된 windows 안에 이미지 표시
    imshow(window_name, image);
    imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0); // window에서 키 입력까지 Wait

    destroyAllWindows(); // 열려 있는 windows 닫기(destroy)

    return 0;
}