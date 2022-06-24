#ifndef LISTA_ENLAZADA
#define LISTA_ENLAZADA

#include "Nodo.hpp"
using namespace std;
using namespace cv;

class ListaEnlazada
{
private:
    int cantidad;
    Nodo* first;
public:
    ListaEnlazada();
    int getCantidad();
    Nodo* getFirst();
	void setFirst(Nodo* n);
	void setCantidad(int c);
	void anadir(Mat img,int n,int num);
	void anadir(Nodo* nuevo);
	void ordenar2();    
};


#endif