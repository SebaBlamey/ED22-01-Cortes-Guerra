#ifndef PERSONADETECTOR_H
#define PERSONADETECTOR_H
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class DetectorPersona {

public:
	DetectorPersona() : imgWidth(4), imgHeight(4) {
		hog_d.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	}
	vector<Rect> detectPersonaRectangle(const Mat& frame);

private:
	const int imgWidth;
	const int imgHeight;
	HOGDescriptor hog, hog_d;
};


#endif