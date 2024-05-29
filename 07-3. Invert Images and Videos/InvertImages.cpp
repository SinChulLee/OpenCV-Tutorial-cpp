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
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    // 원본 이미지 표시
    namedWindow("MyWindow", WINDOW_AUTOSIZE);
    imshow("MyWindow", img);

    // 이미지 반전 (색상 반전)
    Mat img_inverted;
    bitwise_not(img, img_inverted);

    // 반전된 이미지 표시
    namedWindow("Inverted", WINDOW_AUTOSIZE);
    imshow("Inverted", img_inverted);

    waitKey(0);

    // 창 닫기
    destroyAllWindows();

    return 0;
}
