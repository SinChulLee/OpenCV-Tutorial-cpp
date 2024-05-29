// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // video 파일 열기
    VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\A Herd of Deer Running.mp4");

    // 파일 열기에 실패했을 경우, 프로그램 exit
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // 비디오를 중간에 시작하려면 다음 행에 대한 주석을 취소.
    // cap.set(CAP_PROP_POS_MSEC, 300);

    // 비디오의 FPS 추출
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per seconds : " << fps << endl;

    String window_name = "My First Video";

    namedWindow(window_name, WINDOW_NORMAL); // window 생성

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오의 frame read

        // 비디오가 끝날때 while 루프 중단
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
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