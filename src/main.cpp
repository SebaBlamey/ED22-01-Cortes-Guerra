#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.hpp"
#include "Persona.hpp"
#include "ListaEnlazada.hpp"
#include <filesystem>
#include <string>

using namespace std;
using namespace cv;

void desplegarMenu(){
    cout << "-------------------------------------------"<<endl;
    cout << " -- MENU --" << endl;
    cout << "1.- Administrador.\n2.- Guardia" << endl;
    cout << "-------------------------------------------"<<endl;
}

void desplegarMenuEstructura(){
    cout << "-------------------------------------------"<<endl;
    cout << " -- ESTRUCTURA --" << endl;
    cout << "1.- Listas Enlazadas.\n2.- Arboles Binarios." << endl;
    cout << "-------------------------------------------"<<endl;
}

int main(int argc, char** argv)
{
    Detector detector;
    Mat frame;
    string framePath = "/home/seba/Documentos/opencv/images/image1680.png";
    string imagesPath = "/home/seba/Documentos/opencv/images/";
    frame = imread(framePath);
    detector.toggleMode();
    if (frame.empty())
    {
        cout << "[ ! ] Imagen no encontrada" << endl;  
    }
    else
    {
        cout << "[ - ] Imagen encontrada" << endl;
        desplegarMenu();
        int opcionEstructura = 0;
        int opcionUsuario = 0;
        cout << "Seleccione su opcion -> ";
        cin >> opcionUsuario;
        while (opcionUsuario != 1 && opcionUsuario != 2)
        {
            cout << "[ ERROR ] Opcion ingresada no valida." << endl;
            desplegarMenu();
            cout << "Seleccione su opcion -> ";
            cin >> opcionUsuario;
        }
        if(opcionUsuario == 2) // Guardia
        {
            desplegarMenuEstructura();
            cout << "Seleccione la estructura que desea utilizar -> ";
            cin >> opcionEstructura;
            while(opcionEstructura != 1 && opcionEstructura != 2)
            {
                cout << "[ ERROR ] Opcion ingresada no valida." << endl;
                desplegarMenuEstructura();
                cout << "Seleccione la estructura que desea utilizar -> ";
                cin >> opcionEstructura;
            }
            if(opcionEstructura == 1) // Imagen con Lista Enlazada
            {
                cout << "[ - ] Lista Enlazada"<< endl;
                ListaEnlazada* nuevaLista = new ListaEnlazada();
                vector<Persona> found = detector.detect(frame, nuevaLista,opcionEstructura);
                int numeroPersona = 1;
                Nodo* current = nuevaLista->getFirst();
                cout << "[ - ] Cantidad elementos en lista [ "<< nuevaLista->getCantidad() - 1 <<" ]"<<endl;
                cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
                for(vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
                {
                    cout << "Persona numero: "<< to_string(numeroPersona) << endl;
                    Persona &p = *i;
                    cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ") "<<endl;
                    cout << endl;
                    rectangle(frame, Point(p.getXComienzo(), p.getYComienzo()), Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
                    circle(frame, Point(p.getXCentro(), p.getYCentro()), 3, Scalar(0, 0, 255), 3);
                    circle(frame, Point(p.getXComienzo(), p.getYComienzo()), 3, Scalar(255, 0, 255), 2);
                    circle(frame, Point(p.getXFin(), p.getYFin()), 3, Scalar(0, 255, 255), 2);

                    numeroPersona++;
                }

                imshow("People detector",frame);

                waitKey(0);
            }
            else if (opcionEstructura == 2) // Imagen con Arboles Binarios
            {
                cout << "[ - ] Arboles Binarios" << endl;
                ListaEnlazada* nuevaLista = new ListaEnlazada();
                vector<Persona> found = detector.detect(frame, nuevaLista,opcionEstructura);
                int numeroPersona = 1;
                Nodo* current = nuevaLista->getFirst();
                cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
                for(vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
                {
                    cout << "Persona numero: "<< to_string(numeroPersona) << endl;
                    Persona &p = *i;
                    cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ") "<<endl;
                    cout << endl;
                    rectangle(frame, Point(p.getXComienzo(), p.getYComienzo()), Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
                    circle(frame, Point(p.getXCentro(), p.getYCentro()), 3, Scalar(0, 0, 255), 3);
                    circle(frame, Point(p.getXComienzo(), p.getYComienzo()), 3, Scalar(255, 0, 255), 2);
                    circle(frame, Point(p.getXFin(), p.getYFin()), 3, Scalar(0, 255, 255), 2);

                    numeroPersona++;
                }

                imshow("People detector",frame);

                waitKey(0);
            }
        }
        /*ListaEnlazada* nuevaLista = new ListaEnlazada();
        vector<Persona> found = detector.detect(frame, nuevaLista,opcion);
        int numeroPersona = 1;
        Nodo* current = nuevaLista->getFirst();
        if(opcion == 1 ) cout << "[ - ] Lista enlazada" << endl;
        else if(opcion == 2) cout << "[ - ] Arboles binarios" << endl;
        cout << "[ - ] Cantidad elementos en lista [ "<< nuevaLista->getCantidad() - 1 <<" ]"<<endl;
        cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
        for(vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
        {
            cout << "Persona numero: "<< to_string(numeroPersona) << endl;
            Persona &p = *i;
            cout << "(" << p.getXComienzo() << ", " << p.getYComienzo() << ") "<<endl;
            cout << endl;
            rectangle(frame, Point(p.getXComienzo(), p.getYComienzo()), Point(p.getXFin(), p.getYFin()), cv::Scalar(0, 255, 0), 2);
            circle(frame, Point(p.getXCentro(), p.getYCentro()), 3, Scalar(0, 0, 255), 3);
            circle(frame, Point(p.getXComienzo(), p.getYComienzo()), 3, Scalar(255, 0, 255), 2);
            circle(frame, Point(p.getXFin(), p.getYFin()), 3, Scalar(0, 255, 255), 2);

            numeroPersona++;
        }

        imshow("People detector",frame);

        waitKey(0);*/
    }
    return 0;
}