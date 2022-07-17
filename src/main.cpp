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
#include <string.h>
#include <dirent.h>


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
    // Se inicializa el detector de cuerpos.
    Detector detector;
    Mat frame;
    string framePath = "/home/seba/Documentos/opencv/images/image1680.png";
    const char* imagePath = "/home/seba/Documentos/opencv/images/";
    frame = imread(framePath);
    detector.toggleMode();
    // En caso que la ruta entregada no exista retorna este mensaje.
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
        if(opcionUsuario == 1) // Administrador
        {
            string pass = "";
            cout << "Ingrese la contrasena -> ";
            cin >> pass;
            if(pass == "ADMIN"){ 
                cout << "Las imagenes que registra la camara de seguridad son: " << endl;
                /* Se recorre el directorio dado y se despliegan los archivos 
                 * que hay en su interior
                */
                DIR *dir;
                struct dirent *ent;
                if ((dir = opendir (imagePath)) != NULL) {
                    while((ent = readdir (dir)) != NULL){
                        cout << ent->d_name << endl;
                    }
                    closedir(dir);
                }
                string nombreImagen = "";
                cout << "Ingrese el nombre de la imagen (sin .png) -> ";
                cin >> nombreImagen;
                if ((dir = opendir (imagePath)) != NULL) {
                    while((ent = readdir (dir)) != NULL){
                        string value = ent -> d_name;
                        if(strcasecmp(value.c_str(), nombreImagen.c_str())){
                            frame = imread("/home/seba/Documentos/opencv/images/"+nombreImagen+".png");
                            cout << "[ - ] Arboles Binarios" << endl;
                            ListaEnlazada* nuevaLista = new ListaEnlazada();
                            // Se registran las personas ingresadas en la imagen.
                            vector<Persona> found = detector.detect(frame, nuevaLista,opcionEstructura);
                            int numeroPersona = 1;
                            Nodo* current = nuevaLista->getFirst();
                            cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
                            cout << "[ - ] Cantidad de personas por hora -> " << found.end() - found.begin() << "\n" <<endl;
                            // Por cada persona registrada se dibuja su rectangulo
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
                            break;
                        }
                    }
                    closedir(dir);
                }
                else{
                    cout << "[ ! ] Imagen no encontrada."<<endl;
                }

            }else{
                cout << "Contrasena incorrecta" << endl;
            }
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
                // Se registran las personas ingresadas en la imagen.
                vector<Persona> found = detector.detect(frame, nuevaLista,opcionEstructura);
                int numeroPersona = 1;
                Nodo* current = nuevaLista->getFirst();
                cout << "[ - ] Cantidad elementos en lista [ "<< nuevaLista->getCantidad() - 1 <<" ]"<<endl;
                cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
                cout << "[ - ] Cantidad de personas por hora -> " << found.end() - found.begin() << endl;
                // Por cada persona registrada se dibuja su rectangulo
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
                // Se registran las personas ingresadas en la imagen.
                vector<Persona> found = detector.detect(frame, nuevaLista,opcionEstructura);
                int numeroPersona = 1;
                Nodo* current = nuevaLista->getFirst();
                cout << "[ - ] Cantidad de personas detectadas [ "<< found.end() - found.begin() <<" ]\n"<<endl;
                cout << "[ - ] Cantidad de personas por hora -> " << found.end() - found.begin() << "\n" <<endl;
                // Por cada persona registrada se dibuja su rectangulo
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
    }
    return 0;
}