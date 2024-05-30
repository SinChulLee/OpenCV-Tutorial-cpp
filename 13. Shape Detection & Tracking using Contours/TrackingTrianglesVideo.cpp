#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgTracking;
int lastX1 = -1;
int lastY1 = -1;
int lastX2 = -1;
int lastY2 = -1;

void trackObject(Mat &imgThresh)
{
    vector<vector<Point>> contours;
    vector<Point> result;
    findContours(imgThresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++)
    {
        approxPolyDP(contours[i], result, arcLength(contours[i], true) * 0.02, true);
        if (result.size() == 3 && fabs(contourArea(result)) > 100)
        {
            int posX = (result[0].x + result[1].x + result[2].x) / 3;
            int posY = (result[0].y + result[1].y + result[2].y) / 3;

            if (posX > 360)
            {
                if (lastX1 >= 0 && lastY1 >= 0 && posX >= 0 && posY >= 0)
                {
                    line(imgTracking, Point(posX, posY), Point(lastX1, lastY1), Scalar(0, 0, 255), 4);
                }
                lastX1 = posX;
                lastY1 = posY;
            }
            else
            {
                if (lastX2 >= 0 && lastY2 >= 0 && posX >= 0 && posY >= 0)
                {
                    line(imgTracking, Point(posX, posY), Point(lastX2, lastY2), Scalar(255, 0, 0), 4);
                }
                lastX2 = posX;
                lastY2 = posY;
            }
        }
    }
}

int main()
{
    // 비디오 파일을 메모리에 로드
    VideoCapture capture("C:\\Users\\dltls\\OpenCV_C++\\video_dir\\TrackingVideo.mp4");
    if (!capture.isOpened())
    {
        cout << "Capture failure" << endl;
        return -1;
    }

    Mat frame;
    capture >> frame;
    if (frame.empty())
        return -1;

    // 원본 비디오와 동일한 크기의 빈 이미지를 생성하고 'imgTracking'에 할당
    imgTracking = Mat::zeros(frame.size(), CV_8UC3);

    namedWindow("Video", WINDOW_AUTOSIZE);

    // 비디오의 각 프레임을 반복
    while (true)
    {
        capture >> frame;
        if (frame.empty())
            break;

        Mat frameCopy = frame.clone();

        // 가우시안 커널을 사용하여 원본 이미지를 부드럽게 처리
        GaussianBlur(frameCopy, frameCopy, Size(3, 3), 0);

        // 원본 이미지를 그레이스케일로 변환
        Mat imgGrayScale;
        cvtColor(frameCopy, imgGrayScale, COLOR_BGR2GRAY);

        // 그레이스케일 이미지를 이진화하여 더 나은 결과를 얻기 위해 임계값 처리
        threshold(imgGrayScale, imgGrayScale, 100, 255, THRESH_BINARY_INV);

        // 공의 위치 추적
        trackObject(imgGrayScale);

        // 추적 이미지를 프레임에 추가
        add(frameCopy, imgTracking, frameCopy);

        imshow("Video", frameCopy);

        // 10ms 동안 대기
        int c = waitKey(10);
        // 'ESC' 키가 눌리면 루프 종료
        if ((char)c == 27)
            break;
    }

    destroyAllWindows();

    return 0;
}
