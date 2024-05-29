// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 이미지 파일 읽기
    Mat image = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\flower.jpg");

    // 파일 읽기 실패할 경우
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // 3x3 kernel 이미지 침식
    Mat image_eroded_with_3x3_kernel;
    erode(image, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(3, 3)));

    // 5x5 kernel 이미지 침식
    Mat image_eroded_with_5x5_kernel;
    erode(image, image_eroded_with_5x5_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

    // windows names 정의
    String window_name = "Blue Flowers";
    String window_name_eroded_with_3x3_kernel = "Blue Flowers eroded with 3 x 3 kernel";
    String window_name_eroded_with_5x5_kernel = "Blue Flowers eroded with 5 x 5 kernel";

    // names를 가진 windows 생성
    namedWindow(window_name);
    namedWindow(window_name_eroded_with_3x3_kernel);
    namedWindow(window_name_eroded_with_5x5_kernel);

    // 생성된 windows에 이미지 표시
    imshow(window_name, image);
    imshow(window_name_eroded_with_3x3_kernel, image_eroded_with_3x3_kernel);
    imshow(window_name_eroded_with_5x5_kernel, image_eroded_with_5x5_kernel);

    waitKey(0); // 키 입력까지 Wait

    destroyAllWindows(); // 열려 있는 모든 windows 닫기

    return 0;
}