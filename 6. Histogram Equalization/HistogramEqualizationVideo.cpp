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

    // 파일 읽기 실패한 경우 프로그램 종료
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // windows의 names 정의
    String windowNameOfOriginalImage = "Original Video";
    String windowNameOfHistogramEqualized = "Histogram Equalized Video";

    // 위의 names를 가진 windows 생성
    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 비디오 파일의 프레임 읽기

        // 비디오의 끝에서 while loop 종료
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        // BGR이미지를 YCrCb color space 이미지로 변환
        Mat hist_equalized_image;
        cvtColor(frame, hist_equalized_image, COLOR_BGR2YCrCb);

        // 이미지를 Y, Cr 및 Cb 채널의 3개 채널로 나누어 std::vector에 저장
        vector<Mat> vec_channels;
        split(hist_equalized_image, vec_channels);

        // Y 채널로 히스토그램 균등화
        equalizeHist(vec_channels[0], vec_channels[0]);

        // 벡터에서 3개의 채널을 병합하여 YCrCB 색상 공간에서 색상 이미지를 형성
        merge(vec_channels, hist_equalized_image);

        // 히스토그램 균등화 이미지를 YCrCb에서 BGR 색 공간으로 다시 변환
        cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

        // 생성된 windows에 프레임 표시
        imshow(windowNameOfOriginalImage, frame);
        imshow(windowNameOfHistogramEqualized, hist_equalized_image);

        // 10 밀리초 동안 키 입력이 발생할때까지 wait.
        // 'Esc'키가 입력되면 while loop 종료
        // 다른 키가 입력되거나 10 밀리초 동안 키 입력이 없다면 loop 계속 진행
        if (waitKey(5) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
    }

    destroyAllWindows(); // 열려있는 모든 windows Destroy

    return 0;
}