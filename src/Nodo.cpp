#include <opencv2/opencv.hpp>
#include "Nodo.hpp"

Nodo::Nodo(Mat frame, int n, int num)
{
    img = frame;
    next = NULL;
    l = NULL;
    r = NULL;
    id = num;
    veces = n;
}
Nodo* Nodo::getNext()
{
    return next;
}
void Nodo::setIzq(Nodo* n)
{
    l = n;
}
void Nodo::setDer(Nodo* n)
{
    r = n;
}
Nodo* Nodo::getIzq()
{
    return l;
}
Nodo* Nodo::getDer()
{
    return r;
}
Mat Nodo::getImg()
{
    return img;
}
void Nodo::setImg(Mat frame)
{
    img = frame;
}
void Nodo::setNext(Nodo* n)
{
    next = n;
}
int Nodo::getVeces() {
	return veces;
}
void Nodo::setVeces(int n) {
	veces = n;
}
int Nodo::getId() {
	return id;
}
void Nodo::setId(int num) {
	id = num;
}
int Nodo::getFactorE() {
	return FactorE;
}
void Nodo::setFactorE(int num) {
	FactorE = num;
}
