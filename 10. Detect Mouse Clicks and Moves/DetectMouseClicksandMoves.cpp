#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void *userdata)
{
    // 마우스 좌클릭
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    // 마우스 우클릭
    else if (event == EVENT_RBUTTONDOWN)
    {
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    // 마우스 중간 클릭
    else if (event == EVENT_MBUTTONDOWN)
    {
        cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    // 마우스 움직임
    else if (event == EVENT_MOUSEMOVE)
    {
        cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
    }
}

int main(int argc, char **argv)
{
    // 이미지 파일 읽기
    Mat img = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png");

    // 이미지 읽기 실패할 경우
    if (img.empty())
    {
        cout << "Error loading the image" << endl;
        return -1;
    }

    // window 생성
    namedWindow("My Window", 1);

    // 마우스 이벤트 콜백 함수 세팅
    setMouseCallback("My Window", CallBackFunc, NULL);

    // 이미지 표시
    imshow("My Window", img);

    // 키 입력까지 wait
    waitKey(0);

    return 0;
}