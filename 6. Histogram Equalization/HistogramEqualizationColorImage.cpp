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

    // BGR이미지를 YCrCb color space 이미지로 변환
    Mat hist_equalized_image;
    cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

    // 이미지를 Y, Cr 및 Cb 채널의 3개 채널로 나누어 std::vector에 저장
    vector<Mat> vec_channels;
    split(hist_equalized_image, vec_channels);

    // Y 채널로 히스토그램 균등화
    equalizeHist(vec_channels[0], vec_channels[0]);

    // 벡터에서 3개의 채널을 병합하여 YCrCB 색상 공간에서 색상 이미지를 형성
    merge(vec_channels, hist_equalized_image);

    // 히스토그램 균등화 이미지를 YCrCb에서 BGR 색 공간으로 다시 변환
    cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

    // windows의 names 정의
    String windowNameOfOriginalImage = "Original Image";
    String windowNameOfHistogramEqualized = "Histogram Equalized Color Image";

    // names을 가진 windows 생성
    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

    // 생성된 windows안에 이미지들을 표시
    imshow(windowNameOfOriginalImage, image);
    imshow(windowNameOfHistogramEqualized, hist_equalized_image);

    waitKey(0); // 키 입력까지 Wait

    destroyAllWindows(); //  모든 열려있는 windows Destroy

    return 0;
}