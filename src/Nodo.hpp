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

    // Constructor de la clase nodo
    Nodo(Mat img, int n, int num);
    /**
     * @brief Funcion que retorna el nodo siguiente.
     * 
     * @return Nodo* nodo siguiente.
     */
    Nodo* getNext();
    /**
     * @brief Funcion para cambiar el nodo izquierdo de un nodo padre.
     * 
     * @param n nodo al cual se le quiere cambiar el izquierdo.
     */
    void setIzq(Nodo* n);
    /**
     * @brief Funcion para cambiar el nodo derecho de un nodo padre.
     * 
     * @param n nodo al cual se le quiere cambiar el derecho.
     */
    void setDer(Nodo* n);
    /**
     * @brief Funcion que retorna el nodo izquierdo de un padre.
     * 
     * @return Nodo* nodo izquierdo.
     */
    Nodo* getIzq();
    /**
     * @brief Funcion que retorna el nodo derecho de un padre.
     * 
     * @return Nodo* nodo derecho.
     */
    Nodo* getDer();
    /**
     * @brief Funcion que retorna la imagen guardada en un nodo
     * 
     * @return Mat imagen del nodo
     */
    Mat getImg();
    /**
     * @brief funcion que cambia la imagen de un nodo
     * 
     * @param frame imagen nueva del nodo
     */
    void setImg(Mat frame);
    /**
     * @brief funcion que cambia el nodo siguiente de otro
     * 
     * @param n nuevo nodo siguiente.
     */
    void setNext(Nodo* n);
    /**
     * @brief Funcion que retorna la cantidad de veces que se repite la imagen en un nodo
     * 
     * @return int entero que representa la cantidad de veces que se repite la imagen
     */
    int getVeces();
    /**
     * @brief Funcion que permite cambiar la cantidad de veces que se repite una imagen en un nodo.
     * 
     * @param n entero que representa la nueva cantidad de veces que se repite la imagen.
     */
    void setVeces(int n);
    /**
     * @brief Funcion que retorna la ID perteneciente a un nodo
     * 
     * @return int entero que representa la ID del nodo
     */
    int getId();
    /**
     * @brief Funcion que permite cambiar la ID de un nodo
     * 
     * @param num entero que representa la nueva ID que tendra el nodo
     */
    void setId(int num);
    /**
     * @brief Funcion que permite obtener el factor de quilibrio de un nodo
     * 
     * @return int entero que representa el factor equilibrio del nodo
     */
    int getFactorE();
    /**
     * @brief Funcion que cambia el factor de equilibrio de un nodo
     * 
     * @param int entero que representa el nuevo factor de equilibrio.
     */
    void setFactorE(int num);

};


#endif