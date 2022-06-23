#include <sstream>
#include <vector>
#include <string>
#include "DetectorPersona.hpp"


vector<Rect> DetectorPersona::detectPersonaRectangle(const Mat& frame) {
	vector<Rect> cuerpos;
	hog.detectMultiScale(frame, cuerpos, 0, Size(2, 2), Size(4, 4), 1.05, 2, false);

	return cuerpos;
}