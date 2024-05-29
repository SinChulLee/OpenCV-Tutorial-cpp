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

    // 파일 읽기에 실패했는지
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // color 이미지를 grayscale 이미지로 변경
    cvtColor(image, image, COLOR_BGR2GRAY);

    // 히스토그램 균등화
    Mat hist_equalized_image;
    equalizeHist(image, hist_equalized_image);

    // windows의 names 정의
    String windowNameOfOriginalImage = "Original Image";
    String windowNameOfHistogramEqualized = "Histogram Equalized Image";

    // 위의 names들을 가진 windows 생성
    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

    // 생성된 windows 안에 이미지 표시
    imshow(windowNameOfOriginalImage, image);
    imshow(windowNameOfHistogramEqualized, hist_equalized_image);

    waitKey(0); // 키 입력까지 Wait

    destroyAllWindows(); // 열려 있는 windows들 Destroy

    return 0;
}