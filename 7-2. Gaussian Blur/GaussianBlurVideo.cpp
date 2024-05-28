// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // 읽을 비디오 파일 열기
    VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\A Herd of Deer Running.mp4");

    // 파일 읽기에 실패할 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // window names 정의
    String window_name_of_original_video = "Original Video";
    String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Gaussian Kernel";

    // 위의 names를 가진 window 생성
    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_blurred_with_5x5_kernel, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오의 프레임 읽기
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        // 5x5 Gaussian kernel 프레임 blur
        Mat frame_blurred_with_5x5_kernel;
        GaussianBlur(frame, frame_blurred_with_5x5_kernel, Size(5, 5), 0);

        // 생성된 windows에 프레임 표시
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

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