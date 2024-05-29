#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    // 비디오 파일 열기
    VideoCapture cap("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\A Herd of Deer Running.mp4");

    // 열기에 실패한 경우 프로그램 종료
    if (!cap.isOpened())
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }

    const char *pzOriginalWindowName = "Original Video";
    namedWindow(pzOriginalWindowName, WINDOW_AUTOSIZE);

    const char *pzRotatingWindowName = "Rotated Video";
    namedWindow(pzRotatingWindowName, WINDOW_AUTOSIZE);

    int iAngle = 180;
    createTrackbar("Angle", pzRotatingWindowName, &iAngle, 360);

    while (true)
    {
        Mat matOriginalFrame;

        // 비디오에서 새로운 프레임 읽기
        bool bSuccess = cap.read(matOriginalFrame);

        // 읽기에 실패한 경우 루프 종료
        if (!bSuccess)
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

        imshow(pzOriginalWindowName, matOriginalFrame);

        // 아핀 변환 행렬 얻기
        Mat matRotation = getRotationMatrix2D(Point(matOriginalFrame.cols / 2, matOriginalFrame.rows / 2), (iAngle - 180), 1);

        // 이미지 회전
        Mat matRotatedFrame;
        warpAffine(matOriginalFrame, matRotatedFrame, matRotation, matOriginalFrame.size());

        imshow(pzRotatingWindowName, matRotatedFrame);

        // 'esc' 키가 30ms 동안 눌리면 루프 종료
        if (waitKey(30) == 27)
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}
