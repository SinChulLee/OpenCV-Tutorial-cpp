#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\red_rose.mp4"); // 웹캠에서 비디오 캡처

    if (!cap.isOpened()) // 웹캠을 열 수 없는 경우 프로그램 종료
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }

    namedWindow("Control", WINDOW_AUTOSIZE); // "Control"이라는 이름의 창 생성

    // 빨간색 물체에 대한 값 가정 수치
    int iLowH = 0;
    int iHighH = 179;

    int iLowS = 0;
    int iHighS = 255;

    int iLowV = 0;
    int iHighV = 255;

    // "Control" 창에 트랙바 생성
    createTrackbar("LowH", "Control", &iLowH, 179); // Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);

    createTrackbar("LowS", "Control", &iLowS, 255); // Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    createTrackbar("LowV", "Control", &iLowV, 255); // Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // 비디오에서 새로운 프레임 읽기

        if (!bSuccess) // 읽기에 실패한 경우 루프 종료
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        Mat imgHSV;

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); // 캡처한 프레임을 BGR에서 HSV로 변환

        Mat imgThresholded;

        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); // 이미지 임계값 처리

        // 모폴로지 열림(전경의 작은 물체 제거)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        // 모폴로지 닫힘(전경의 작은 구멍 채우기)
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        imshow("Thresholded Image", imgThresholded); // 임계값 처리된 이미지 표시
        imshow("Original", imgOriginal);             // 원본 이미지 표시

        if (waitKey(30) == 27) // 30ms 동안 'esc' 키 입력 대기. 'esc' 키가 입력되면 루프 종료
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}