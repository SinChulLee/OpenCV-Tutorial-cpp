#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

void MyCallbackForBrightness(int iValueForBrightness, void *userData)
{
     Mat dst;
     int iValueForContrast = *(static_cast<int *>(userData));

     // 밝기&대비 값 계산
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;

     // 계산값 출력
     cout << "MyCallbackForBrightness : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

     // 밝기&대비 조절
     src.convertTo(dst, -1, dContrast, iBrightness);

     // 밝기&대비가 조절된 이미지 의 밝기&대비 표시
     imshow("My Window", dst);
}

void MyCallbackForContrast(int iValueForContrast, void *userData)
{
     Mat dst;
     int iValueForBrightness = *(static_cast<int *>(userData));

     // 밝기&대비 값 계산
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;

     // 계산값 출력
     cout << "MyCallbackForContrast : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

     // 밝기&대비 조절
     src.convertTo(dst, -1, dContrast, iBrightness);

     // 밝기&대비가 조절된 이미지 의 밝기&대비 표시
     imshow("My Window", dst);
}

int main(int argc, char **argv)
{
     // 이미지 읽기
     src = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png");

     // 이미지 읽기에 실패할 경우
     if (src.data == false)
     {
          cout << "Error loading the image" << endl;
          return -1;
     }

     // window 생성
     namedWindow("My Window", 1);

     int iValueForBrightness = 50;
     int iValueForContrast = 50;

     // 밝기를 변경할 트랙바 생성
     createTrackbar("Brightness", "My Window", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);

     // 대비를 변경할 트랙바 생성
     createTrackbar("Contrast", "My Window", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);

     imshow("My Window", src);

     // 키 입력까지 Wait
     waitKey(0);

     return 0;
}