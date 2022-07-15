#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class Persona
{
private:
    int xComienzo;
    int yComienzo;
    int xFin;
    int yFin;
    int xCentro;
    int yCentro;
public:
    // Constructor de la clase
    Persona(cv::Rect&);

    /**
     * @brief Funcion que retorna la posicion inicial X de la persona
     * 
     * @return int entero que representa la posicion inicial X de la persona
     */
    int getXComienzo();
    /**
     * @brief Funcion que retorna la posicion inicial Y de la persona
     * 
     * @return int entero que representa la posicion inicial Y de la persona.
     */
    int getYComienzo();
    /**
     * @brief Funcion que reotnra la posicion final X de la persona
     * 
     * @return int entero que representa la posicion final X de la persona
     */
    int getXFin();
    /**
     * @brief Funcion que retorna la posicion final Y de la persona
     * 
     * @return int entero que representa la posicion final Y de la persona
     */
    int getYFin();
    /**
     * @brief Funcion que retorna la posicion X central de la persona
     * 
     * @return int entero que representa la posicion X central de la persona
     */
    int getXCentro();
    /**
     * @brief Funcino que retorna la posicion Y central de la persona
     * 
     * @return int entero que representa la posicion Y central de la persona
     */
    int getYCentro();
};

#endif