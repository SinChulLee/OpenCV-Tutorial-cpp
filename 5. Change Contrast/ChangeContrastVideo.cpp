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

    // 읽기에 실패할 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // 각 이미지의 window naems 정의
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    // 이미지의 windows 생성 및 열기
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오의 매 프레임 읽기

        // 비디오의 끝에서 while loop 종료
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameContrastHigh2;
        frame.convertTo(frameContrastHigh2, -1, 2, 0); // contrast를 2만큼 증가

        Mat frameContrastHigh4;
        frame.convertTo(frameContrastHigh4, -1, 4, 0); // contrast를 4만큼 증가

        Mat frameContrastLow0_5;
        frame.convertTo(frameContrastLow0_5, -1, 0.5, 0); // contrast를 0.5만큼 감소

        Mat frameContrastLow0_25;
        frame.convertTo(frameContrastLow0_25, -1, 0.25, 0); // contrast를 0.25만큼 감소

        // 생성된 windows 안에 이미지 표시
        imshow(windowNameOriginalImage, frame);
        imshow(windowNameContrastHigh2, frameContrastHigh2);
        imshow(windowNameContrastHigh4, frameContrastHigh4);
        imshow(windowNameContrastLow0_5, frameContrastLow0_5);
        imshow(windowNameContrastLow0_25, frameContrastLow0_25);

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