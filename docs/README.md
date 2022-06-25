![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Sebastián Cortés Blamey (Programador)
* Felipe Guerra Blamey (Programador)

## Resumen 

> La primera tarea comenzo creando un codigo el cual sera capáz de recibir un video encerrando a las personas que atraviesen una "zona" demarcada por una linea donde luego serán encerradas en un rectangulo el cual ayudara a distinguir a las personas unas de otras, estas personas antes mencionadas deben ser contadas una vez entran y salen del centro comercial mientras que a su vez se calcula la velocidad de estas según el parametro de personas por minuto. Una vez realizado este codigo se paso a la siguiente parte, donde se comienza a diferenciar a estas personas por sus diferentes caracteristicas fisicas, ya que la principal problematica del taller hasta el monmento es esta, lo cual se realizo según histogramas basados en el modelo de OpenCV HOG + Linear SVM ideado según el metodo de Dalal y Triggs el cual puede ser utilizado para realizar la deteccion de peatones tanto en imagenes como en secuencias de video.

## 1. Introducción

Se sabe que en un centro comercial pueden entrar y salir diferentes personas de las cuales para el mismo centro le es importante saber cuantas pueden llegar a ser, ya que esto los ayudaria a llevar un registro de cuantas personas entraron y salieron durante un periodo de tiempo determinado. Es por esto que se crea un programa el cual se va a situar en un punto fijo y estrategico del centro comercial el cual va a tener captura de las personas que entran y salen sin tener una repetición de estas en caso de que una misma persona pueda entrar y salir en más de una o más oportunidades. Por otra parte, un dato importante para el mismo centro comercial es cuales son las horas con mayor ingreso y salida de persona para asi conocer el periodo de tiempo en el que se ocasiona más trafico de personas y por lo tanto mayor demanda para el centro comercial. 


### 1.1 Descripción del problema

Según lo indicado en el laboratorio, un local/centro comercial necesita saber cuantas personas ingresan a este mismo y la forma más facil es realizando un programa en el que haga todo de forma automatica y así poder llevar un registro de estos mismos.

### 1.2 Objetivos 

**Objetivo General**

Calcular la entrada y salida de personas dentro de un centro comercial sin que estas se repitan en la contabilidad.


**Objetivos específicos**

1. Desarrollar un programa capaz de detectar a las personas que pasan por video.
2. Categorizar a las personas, es decir, diferenciarlas unas de otras.
3. Registrar las diferentes personas que ingresan al local.
4. Implementar el reconocimiento de objetos según el histograma realizado según el modelo de HOG+Linear SVM.

### 1.3 Solución propuesta

La solución propuesta se baso en diferenciar a las personas según histogramas y las distancias que tenian estas mismas una de otras siendo agregadas de forma unica a listas enlazadas.

## 2. Materiales y métodos

El trabajo se desea realizar utilizando Visual Studio y OpenCV basandonos en diferentes ideas basadas en Python y sus distintas librerias dirigidas al trabajo de detectar distintos objetos.

### 2.1 Instalación

El IDE utilizado fue Visual Studio 2022 con la libreria de OPENCV con su version 4.6.0 instaladas en el sistema operativo Linux.

### 2.2 Diseño 

Explicar los componentes (módulos o clases) utilizados para resolver el problema. Indicar arquitectura propuesta, diagrama de clases u otro artefacto que estime conveniente para explicar el diseño de su implimentación.

### 2.3 Implementación

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

El resultado obtenido fue contar con el conocimiento de cuantas personas entraron y salieron al centro comercial según la zona demarcada.

## 4. Conclusiones

Culminado el taller podemos llegar a tener un pequeño conocimiento de lo que se trata en un pequeño rango la Vision artificial y el procesamiento de imagen ya que trabajamos con detectar a distintas personas diferenciando a unas de otras y contabilizando a estas mismas según una zona demarcada y asi ver de una forma optima cual podria llegar a ser la hora peak de un centro comercial, buscar y encontrar a cierta persona, etc.


# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

## Anexo C: Conocimiento del modelo de OpenCV HOG + Linear SVM

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. Pardo Herrera, C. J. (2019). HISTOGRAMA DE GRADIENTES ORIENTADOS PARA LA DETECCIÓN DE PEATONES (Python + OpenCV). Linkedin. Recuperado 24 de junio de 2022, de https://www.linkedin.com/pulse/detecci%C3%B3n-de-peatones-con-python-y-opencv-hog-svm-pardo-herrera/?originalSubdomain=es
2. Bekios, J. (2021, 12 octubre). Taller-01: Instalación de las librerías de OpenCV para Visual Studio en C++. Youtube. Recuperado 24 de junio de 2022, de https://www.youtube.com/watch?v=Hu7ArOaFm2g
3.Bekios, J. (2022, 10 junio). Ayudantía de Taller 2022–01 Clase 03-Parte 02/02: Detectar personas y calcular centroides en C++. Youtube. Recuperado 24 de junio de 2022, de https://www.youtube.com/watch?v=Y7AaLqLyJI8


