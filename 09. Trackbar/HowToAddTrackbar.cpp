#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    // 이미지 읽기
    Mat src = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Lenna.png");

    // 이미지 읽기에 실패할 경우
    if (!src.data)
    {
        cout << "Error loading the image" << endl;
        return -1;
    }

    // window 생성
    namedWindow("My Window", 1);

    // 밝기를 조절할 트랙바 생성
    int iSliderValue1 = 50;
    createTrackbar("Brightness", "My Window", &iSliderValue1, 100);

    // 대비를 조절할 트랙바 생성
    int iSliderValue2 = 50;
    createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

    while (true)
    {
        // 이미지의 밝기와 대비 조절
        Mat dst;
        int iBrightness = iSliderValue1 - 50;
        double dContrast = iSliderValue2 / 50.0;
        src.convertTo(dst, -1, dContrast, iBrightness);

        // 조정된 이미지의 밝기와 대비를 보여준다.
        imshow("My Window", dst);

        // 사용자가 50ms 동안 키를 누를 때까지 wait
        int iKey = waitKey(50);

        // 사용자가 'ESC' key를 누를 경우 종료
        if (iKey == 27)
        {
            break;
        }
    }

    return 0;
}