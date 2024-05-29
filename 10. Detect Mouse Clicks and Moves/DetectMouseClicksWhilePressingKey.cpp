#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void *userdata)
{
    // 마우스 좌클릭
    if (flags == (EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON))
    {
        cout << "Left mouse button is clicked while pressing CTRL key - position (" << x << ", " << y << ")" << endl;
    }
    // 마우스 우클릭
    else if (flags == (EVENT_FLAG_RBUTTON + EVENT_FLAG_SHIFTKEY))
    {
        cout << "Right mouse button is clicked while pressing SHIFT key - position (" << x << ", " << y << ")" << endl;
    }
    // 마우스 움직임
    else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
    {
        cout << "Mouse is moved over the window while pressing ALT key - position (" << x << ", " << y << ")" << endl;
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