#include <iostream>
#include <opencv2/opencv.hpp>
#include "ListaEnlazada.hpp"

using namespace std;
using namespace cv;

ListaEnlazada::ListaEnlazada()
{
    cantidad = 0;
    first = NULL;
}
int ListaEnlazada::getCantidad(){
    return cantidad;
}
void ListaEnlazada::setCantidad(int c)
{
    cantidad = c;
}
Nodo* ListaEnlazada::getFirst()
{
    return first;
}
void ListaEnlazada::setFirst(Nodo* n)
{
    first = n;
}
void ListaEnlazada::anadir(Mat img, int n, int num)
{
    Nodo* nuevo = new Nodo(img, n, num);
    if(first == NULL)
    {
        first = nuevo;
        nuevo -> setId(1);
        nuevo -> setVeces(1);
    }
    else
    {
        nuevo -> setNext(first);
        first = nuevo;
        nuevo->setId(cantidad-1);
        nuevo->setVeces(1);
    }
    cantidad++;
}
void ListaEnlazada::anadir(Nodo* nuevo)
{
    if(first == NULL)
    {
        first = nuevo;
    }
    else
    {
        nuevo->setNext(first);
        first = nuevo;
    }
    cantidad++;
}
void ListaEnlazada::ordenar2()
{
    Nodo* actual = first;
    Nodo* siguiente = first;
    int t;
    Mat img;
    int id;

    while (actual -> getNext() != NULL)
    {
        siguiente = actual->getNext();

        while(siguiente != NULL)
        {
            if (actual->getVeces() > siguiente->getVeces())
            {
                t = siguiente->getVeces();
                id = siguiente->getId();
                img = siguiente->getImg();
                siguiente->setVeces(actual->getVeces());
                siguiente->setId(actual->getId());
                siguiente->setImg(actual->getImg());
                actual->setVeces(t);
                actual->setId(id);
                actual->setImg(img);
            }
            siguiente = siguiente->getNext();
        }
        actual = actual->getNext();
        siguiente = actual->getNext();
    }
}