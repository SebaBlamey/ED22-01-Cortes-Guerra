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
    // Constructor de la clase
    ListaEnlazada();
    /**
     * @brief Funcion que retorna la cantidad de elementos 
     * dentro de la lista enlazada.
     * @return entero con la cantidad de nodos en la lista
     */
    int getCantidad();
    /**
     * @brief Funcion que retorna el primer elemento de 
     * la lista.
     * @return el primer nodo de la lista 
     */
    Nodo* getFirst();
    /**
     * @brief Funcion que cambia el primer nodo de la lista
     * @param Nodo que se transformara en el primer nodo.
     */
	void setFirst(Nodo* n);
    /**
     * @brief Funcion para cambiar la cantidad total de elemntos
     * dentro de la lista enlazada.
     * @param entero que indica la cantidad de elementos.
     */
	void setCantidad(int c);
    /**
     * @brief Funcion que anade un nuevo elemento a la lista.
     * 
     * @param img imagen que se guardara en el nuevo nodo.
     * @param n entero que se establecera como la ID del nodo.
     * @param num entero que se establecera como la cantidad de veces
     * que aparece ela imagen del nodo
     */
	void anadir(Mat img,int n,int num);
    /**
     * @brief Funcion que anade un nuevo nodo a la lista enlazada.
     * 
     * @param nuevo nodo que se va a anadir a la lista enlazada.
     */
	void anadir(Nodo* nuevo);
};


#endif