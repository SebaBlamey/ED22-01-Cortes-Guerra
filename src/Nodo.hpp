#ifndef NODO_
#define NODO_

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class Nodo
{
private:
    Mat img;
    Nodo* next;
    Nodo* l;
    Nodo* r;

    int id;
    int veces;
    int FactorE; // Factor equilibrio del nodo;
public:

    Nodo(Mat img, int n, int num);
    Nodo* getNext();
    void setIzq(Nodo* n);
    void setDer(Nodo* n);
    Nodo* getIzq();
    Nodo* getDer();
    Mat getImg();
    void setImg(Mat frame);
    void setNext(Nodo* n);
    int getVeces();
    void setVeces(int n);
    int getId();
    void setId(int num);
    int getFactorE();
    void setFactorE(int num);

};


#endif