// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 이미지 파일 읽기
    Mat image = imread("C:\\Users\\dltls\\OpenCV_C++\\img_dir\\dog.jpg");

    // 파일 읽기에 실패했을 경우
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    /*
    필요에 따라 이미지를 변경합니다
    예.
    1. 이미지의 밝기(brightness)/대비(contrast) 변경
    2. 매끄러운(smooth)/흐린(blur) 이미지로 변경
    3. 이미지 잘라내기(crop)
    4. 이미지 회전(rotate)
    5. 이미지에 도형 그리기
    */

    // 이미지를 jpg파일로 write하기, 경로를 지정하면 지정된 경로에 저장된다.
    bool isSuccess = imwrite("C:\\Users\\dltls\\OpenCV_C++\\3. Save Images & Videos to File\\MyImage.jpg", image);
    // bool isSuccess = imwrite("MyImage.png", image); //이미지를 PNG파일로 write하기
    if (isSuccess == false)
    {
        cout << "Failed to save the image" << endl;
        cin.get(); // 키 입력까지 wait
        return -1;
    }

    cout << "Image is succusfully saved to a file" << endl;

    String windowName = "The Saved Image"; // window의 이름
    namedWindow(windowName);               // window 생성
    imshow(windowName, image);             // 생성된 window에 이미지 표시

    waitKey(0); // window에서 키입력까지 wait

    destroyWindow(windowName); // 생성된 window destroy

    return 0;
}