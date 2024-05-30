#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 이미지 불러오기
    Mat img = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\DetectingContours.jpg");

    if (img.empty())
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }

    // 원본 이미지 표시
    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", img);

    // 원본 이미지를 가우시안 커널을 사용하여 부드럽게 처리하여 노이즈 제거
    GaussianBlur(img, img, Size(3, 3), 0);

    // 원본 이미지를 그레이스케일로 변환
    Mat imgGrayScale;
    cvtColor(img, imgGrayScale, COLOR_BGR2GRAY);

    // 그레이스케일 이미지 표시
    namedWindow("GrayScale Image", WINDOW_AUTOSIZE);
    imshow("GrayScale Image", imgGrayScale);

    // 그레이스케일 이미지를 이진화하여 더 나은 결과를 얻기 위해 임계값 처리
    threshold(imgGrayScale, imgGrayScale, 100, 255, THRESH_BINARY_INV);

    // 이진화된 이미지 표시
    namedWindow("Thresholded Image", WINDOW_AUTOSIZE);
    imshow("Thresholded Image", imgGrayScale);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // 이미지에서 모든 컨투어 찾기
    findContours(imgGrayScale, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0));

    // 각 컨투어를 반복
    for (size_t i = 0; i < contours.size(); i++)
    {
        vector<Point> result;
        approxPolyDP(contours[i], result, arcLength(contours[i], true) * 0.02, true);

        // 컨투어의 꼭지점이 3개이고 삼각형의 면적이 100 픽셀보다 큰 경우
        if (result.size() == 3 && fabs(contourArea(result)) > 100)
        {
            // 삼각형 주위에 선 그리기
            line(img, result[0], result[1], Scalar(255, 0, 0), 4);
            line(img, result[1], result[2], Scalar(255, 0, 0), 4);
            line(img, result[2], result[0], Scalar(255, 0, 0), 4);
        }
    }

    // 식별된 모양이 표시된 이미지 표시
    namedWindow("Tracked", WINDOW_AUTOSIZE);
    imshow("Tracked", img);

    waitKey(0); // 키 입력 대기

    // 모든 창 닫기
    destroyAllWindows();

    return 0;
}
