#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgOriginal;
int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
int iImageCenterY = 0;
int iImageCenterX = 0;
const char *pzRotatedImage = "Rotated Image";

void CallbackForTrackBar(int, void *)
{
    Mat matRotation = getRotationMatrix2D(Point(iImageCenterX, iImageCenterY), (iAngle - 180), iScale / 50.0);

    // 이미지 회전
    Mat imgRotated;
    warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size(), INTER_LINEAR, iBorderMode, Scalar());

    imshow(pzRotatedImage, imgRotated);
}

int main(int argc, char **argv)
{
    // 이미지 불러오기
    imgOriginal = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png", 1);

    if (imgOriginal.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    iImageCenterY = imgOriginal.rows / 2;
    iImageCenterX = imgOriginal.cols / 2;

    // 원본 이미지 표시
    const char *pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage, WINDOW_AUTOSIZE);
    imshow(pzOriginalImage, imgOriginal);

    // "Rotated Image" 창과 3개의 트랙바 생성
    namedWindow(pzRotatedImage, WINDOW_AUTOSIZE);
    createTrackbar("Angle", pzRotatedImage, &iAngle, 360, CallbackForTrackBar);
    createTrackbar("Scale", pzRotatedImage, &iScale, 100, CallbackForTrackBar);
    createTrackbar("Border Mode", pzRotatedImage, &iBorderMode, 5, CallbackForTrackBar);

    int iDummy = 0;
    CallbackForTrackBar(iDummy, &iDummy);

    waitKey(0);

    return 0;
}
