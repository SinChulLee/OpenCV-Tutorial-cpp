// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // 내장 카메라 열기 -> cap()
    // cap(비디오 파일 경로)를 통해 영상 파일을 열 수 있다.
    VideoCapture cap(0);
    // VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\A Herd of Deer Running.mp4");

    // 파일 읽기에 실패한 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video camera" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));   // 비디오 프레임의 넓이
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); // 비디오 프레임의 높이

    Size frame_size(frame_width, frame_height);
    int frames_per_second = 10;

    // VideoWriter 객체 생성 및 초기화
    VideoWriter oVideoWriter("C:\\Users\\dltls\\OpenCV_C++\\3. Save Images & Videos to File\\MyVideo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
                             frames_per_second, frame_size, true);

    // VideoWriter 객체가 성공적으로 초기화되지 않았을 경우 프로그램 종료
    if (oVideoWriter.isOpened() == false)
    {
        cout << "Cannot save the video to a file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    string window_name = "My Camera Feed";
    namedWindow(window_name); // window 생성 및 이름 설정

    while (true)
    {
        Mat frame;
        bool isSuccess = cap.read(frame); // 웹캠(cap(0) 또는 비디오 파일의 프레임 읽기

        // 읽을 프레임이 없을 경우 while loop 종료
        if (isSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); // 키 입력까지 wait
            break;
        }

        /*
        필요에 따라 프레임을 변경할 수 있다.
        예.
        1. 이미지의 밝기(brightness)/대비(contrast) 변경
        2. 매끄러운(Smooth)/흐린(Blur) 이미지로 변경
        3. 이미지 잘라내기(crop)
        4. 이미지 회전(rotate)
        5. 이미지에 도형 그리기
        */

        // 파일에 비디오 프레임 쓰기(저장하기)
        oVideoWriter.write(frame);

        // 생성된 window에 프레임 표시
        imshow(window_name, frame);

        // 키를 누를 때까지 10밀리초 동안 wait.
        // 'Esc' 키를 누르면 While Loop을 해제.
        // 10밀리초 이내에 어떤 키도 누르지 않거나 다른 키를 누르면 루프를 계속 진행.
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
    }

    // 비디오 파일 플러시 및 닫기
    oVideoWriter.release();

    return 0;
}