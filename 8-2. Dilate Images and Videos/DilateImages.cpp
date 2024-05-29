#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 이미지 파일 읽기
    Mat img = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\Car_Original_Image.jpg");

    // 파일 읽기 실패할 경우
    if (img.empty())
    {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // 원본 이미지 표시
    namedWindow("MyWindow", WINDOW_AUTOSIZE);
    imshow("MyWindow", img);

    // 5x5 kernel 이미지 팽창
    Mat img_dilated;
    dilate(img, img_dilated, getStructuringElement(MORPH_RECT, Size(5, 5)), Point(-1, -1), 2);

    // 팽창된 이미지 표시
    namedWindow("Dilated", WINDOW_AUTOSIZE);
    imshow("Dilated", img_dilated);

    waitKey(0);

    // 창 닫기
    destroyAllWindows();

    return 0;
}
