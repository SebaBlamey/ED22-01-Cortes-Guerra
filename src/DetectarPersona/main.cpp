#include <iostream>
#include "opencv2\highgui.hpp"
#include <opencv2/opencv.hpp>
#include "DetectorPersona.hpp"
using namespace cv;
using namespace std;

// Driver code
int main(int argc, char** argv) 
{
    string pathImage = "C:/Users/eweew/Pictures/image1680";
    string path = "C:/Users/eweew/Videos/Video_003.avi";
    //VideoCapture cap(path); //Mat frame;

    DetectorPersona pdetector;

    
    while (1) {
        cout << "Ejecutando el While" << endl;
        Mat frame;
        //cap >> frame;
        //cap.read(frame);
        frame = imread(pathImage);

        auto personDetector = pdetector.detectPersonaRectangle(frame);
        Scalar color(0, 0, 255);
        for (const auto& fm : personDetector) {
            rectangle(frame, fm, color, 4);
        }

        if (frame.empty()) break;
        imshow("Frame", frame);
        

        char c = (char)waitKey(27);
        if (c == 27) break;
    }
    //cap.release();
    destroyAllWindows();
    return 0;
}
