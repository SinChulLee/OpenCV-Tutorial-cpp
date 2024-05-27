// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 읽을 비디오 파일 열기
    VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\A Herd of Deer Running.mp4");

    // 실패할 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // window names 정의
    String windowNameOriginalVideo = "Original Video";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    // 위의 window names들을 가진 windows 생성 및 열기
    namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오의 프레임 읽기

        // 비디오의 끝에서 while loop 종료
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameBrighnessHigh50;
        frame.convertTo(frameBrighnessHigh50, -1, 1, 50); // 밝기 50 증가

        Mat frameBrighnessHigh100;
        frame.convertTo(frameBrighnessHigh100, -1, 1, 100); // 밝기 100 증가

        Mat frameBrighnessLow50;
        frame.convertTo(frameBrighnessLow50, -1, 1, -50); // 밝기 50 감소

        Mat frameBrighnessLow100;
        frame.convertTo(frameBrighnessLow100, -1, 1, -100); // 밝기 100 감소

        // 생성된 windows안에 위의 프레임들을 표시
        imshow(windowNameOriginalVideo, frame);
        imshow(windowNameBrightnessHigh50, frameBrighnessHigh50);
        imshow(windowNameWithBrightnessHigh100, frameBrighnessHigh100);
        imshow(windowNameBrightnessLow50, frameBrighnessLow50);
        imshow(windowNameBrightnessLow100, frameBrighnessLow100);

        // 10 밀리초 동안 키 입력이 발생할때까지 wait.
        // 'Esc'키가 입력되면 while loop 종료
        // 다른 키가 입력되거나 10 밀리초 동안 키 입력이 없다면 loop 계속 진행
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}