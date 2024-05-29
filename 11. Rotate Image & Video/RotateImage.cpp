#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 이미지 불러오기
    Mat imgOriginal = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png", 1);

    if (imgOriginal.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // 원본 이미지 표시
    const char *pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage, WINDOW_AUTOSIZE);
    imshow(pzOriginalImage, imgOriginal);

    const char *pzRotatedImage = "Rotated Image";
    namedWindow(pzRotatedImage, WINDOW_AUTOSIZE);

    int iAngle = 180;
    createTrackbar("Angle", pzRotatedImage, &iAngle, 360);

    int iImageHeight = imgOriginal.rows / 2;
    int iImageWidth = imgOriginal.cols / 2;

    while (true)
    {
        Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHeight), (iAngle - 180), 1);

        // 이미지 회전
        Mat imgRotated;
        warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());

        imshow(pzRotatedImage, imgRotated);

        int iRet = waitKey(30);
        if (iRet == 27) // ESC 키를 누르면 종료
        {
            break;
        }
    }

    return 0;
}
