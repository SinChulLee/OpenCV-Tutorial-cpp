// Uncomment the following line if you are compiling this code in Visual Studio
// #include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// int main(int argc, char **argv)
// {
//     // Read the image file
//     Mat image = imread("C:\\Users\\dltls\\OpenCV_C++\\cat.jpg");

//     // Check for failure
//     if (image.empty())
//     {
//         cout << "Could not open or find the image" << endl;
//         cin.get(); // wait for any key press
//         return -1;
//     }

//     String windowName = "The cat"; // Name of the window

//     namedWindow(windowName); // Create a window

//     imshow(windowName, image); // Show our image inside the created window.

//     waitKey(0); // Wait for any keystroke in the window

//     destroyWindow(windowName); // destroy the created window

//     return 0;
// }

// Create a Blank Image & Display
int main(int argc, char **argv)
{
    // create a new image which consists of
    // 3 channels
    // image depth of 8 bits
    // 800 x 600 of resolution (800 wide and 600 high)
    // each pixels initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectively.
    Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));

    String windowName = "Window with Blank Image"; // Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // Show our image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); // destroy the created window

    return 0;
}