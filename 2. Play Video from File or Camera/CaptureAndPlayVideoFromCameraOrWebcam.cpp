// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // 기본 비디오 카메라 열기
    VideoCapture cap(0);

    // 실패했을 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video camera" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);   // 비디오 프레임의 넓이
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); // 비디오 프레임의 높이

    cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

    string window_name = "My Camera Feed";
    namedWindow(window_name); // "My Camera Feed"이름을 가진 window 생성

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오 프레임 읽기

        // 프레임을 캡처할 수 없는 경우 While 루프 break
        if (bSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); // 키 입력까지 wait
            break;
        }

        // 생성된 window에 frame 표시
        imshow(window_name, frame);

        // 키를 누를 때까지 10ms 동안 wait.
        // 'Esc' 키를 누르면 While Loop을 해제.
        // 10ms 내에 어떤 키를 누르지 않거나 다른 키를 누르면 루프를 계속 진행
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}