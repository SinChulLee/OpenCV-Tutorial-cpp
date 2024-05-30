#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 이미지 불러오기
    Mat img = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\FindingContours.png");

    if (img.empty())
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }

    // 원본 이미지 표시
    namedWindow("Raw", WINDOW_AUTOSIZE);
    imshow("Raw", img);

    // 원본 이미지를 그레이스케일로 변환
    Mat imgGrayScale;
    cvtColor(img, imgGrayScale, COLOR_BGR2GRAY);

    // 그레이스케일 이미지를 이진화하여 더 나은 결과를 얻기 위해 임계값 처리
    threshold(imgGrayScale, imgGrayScale, 128, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // 이미지에서 모든 윤곽선 찾기
    findContours(imgGrayScale, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0));

    // 각 윤곽선을 반복
    for (size_t i = 0; i < contours.size(); i++)
    {
        vector<Point> result;
        approxPolyDP(contours[i], result, arcLength(contours[i], true) * 0.02, true);

        // 윤곽선의 꼭지점이 3개인 경우 (삼각형)
        if (result.size() == 3)
        {
            line(img, result[0], result[1], Scalar(255, 0, 0), 4);
            line(img, result[1], result[2], Scalar(255, 0, 0), 4);
            line(img, result[2], result[0], Scalar(255, 0, 0), 4);
        }
        // 윤곽선의 꼭지점이 4개인 경우 (사각형)
        else if (result.size() == 4)
        {
            line(img, result[0], result[1], Scalar(0, 255, 0), 4);
            line(img, result[1], result[2], Scalar(0, 255, 0), 4);
            line(img, result[2], result[3], Scalar(0, 255, 0), 4);
            line(img, result[3], result[0], Scalar(0, 255, 0), 4);
        }
        // 윤곽선의 꼭지점이 7개인 경우 (칠각형)
        else if (result.size() == 7)
        {
            for (size_t j = 0; j < 7; j++)
            {
                line(img, result[j], result[(j + 1) % 7], Scalar(0, 0, 255), 4);
            }
        }
    }

    // 모양이 식별된 이미지 표시
    namedWindow("Tracked", WINDOW_AUTOSIZE);
    imshow("Tracked", img);

    waitKey(0); // 키 입력 대기

    // 모든 창 닫기
    destroyAllWindows();

    return 0;
}
