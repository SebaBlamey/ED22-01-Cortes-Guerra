#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.hpp"
#include "Persona.hpp"
#include "ListaEnlazada.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Detector detector;
    Mat frame;
    string framePath = "/home/seba/Documentos/opencv/images/image1680.png";
    frame = imread(framePath);
    detector.toggleMode();
    //cout << detector.modeName() << endl;
    if (frame.empty())
    {
        cout << "[ ! ] Imagen no encontrada" << endl;  
    }
    else
    {
        cout << "[ - ] Imagen encontrada" << endl;
        int opcion = 2;
        ListaEnlazada* nuevaLista = new ListaEnlazada();
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

        waitKey(0);
    }

    
    return 0;
}