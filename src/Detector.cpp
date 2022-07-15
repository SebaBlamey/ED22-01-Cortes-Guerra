#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include "ListaEnlazada.hpp"
#include "BinarySearchTree.hpp"

using namespace cv;
using namespace std;


#include "Detector.hpp"

void Detector::toggleMode() { m = (m == Default ? Daimler : Default); }
    
string Detector::modeName() const { return (m == Default ? "Default" : "Daimler"); }

vector<Persona> Detector::detect(InputArray img, ListaEnlazada* lista, int opcion)
{
        // Run the detector with default parameters. to get a higher hit-rate
        // (and more false alarms, respectively), decrease the hitThreshold and
        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
        vector<Rect> found;
        Mat resizedDown;
        if (m == Default)
            hog.detectMultiScale(img, found, 0, Size(2,2), Size(4,4), 1.05, 2, false);
        else if (m == Daimler)
            hog_d.detectMultiScale(img, found, 1, Size(2,2), Size(4,4), 1.05, 3, true);

        // Convertir un objeto Rect a un objeto persona
        vector<Persona> personas;

        for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i){
            Rect &r = *i;
            Persona p(r);
            personas.push_back(p);

            bool iguales= false;

            if(opcion == 1 )
            {
                // ListaEnlazada
                
                Nodo* current = lista->getFirst();
                if(current == NULL)
                {
                    lista->anadir(resizedDown.clone(),0,0);
                }
                else
                {
                    while(current != NULL)
                    {
                        double dist = norm(resizedDown, current->getImg(), NORM_L2);
                        if(dist<0.0)
                        {
                            iguales = true;
                            current->setVeces(current->getVeces() + 1);
                            break;
                        }
                        current = current->getNext();
                    }
                }
                if(iguales!=true)
                {
                    lista->anadir(resizedDown.clone(),0,0);
                }
            }
            else if (opcion == 2)
            {
                // Arboles binarios
                BinarySearchTree abb;
                ListaEnlazada* cuerpos = new ListaEnlazada();

                Nodo* current = cuerpos->getFirst();
                while(current != nullptr){
                    abb.insertI(current->getImg());
                    current = current -> getNext();
                }
            }
        }
        
        return personas;
}

void Detector::adjustRect(Rect & r) const{
        // The HOG detector returns slightly larger rectangles than the real objects,
        // so we slightly shrink the rectangles to get a nicer output.
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
}