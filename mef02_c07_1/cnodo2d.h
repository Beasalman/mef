#include <iostream>
using std::cout;
using std::endl;

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
using std::vector;

//#ifndef carista_h_           // Lo declaramos más abajo, de otra manera, para evitar error de compilación.
//    #include "carista.h"
//#endif
//#ifndef celem2d_h_
//    #include "celem2d.h"
//#endif

/* -------------------------------------------------------------   */

#ifndef cnodo2d_h_
#define cnodo2d_h_

class carista;                 // Para evitar error de compilación: #include nested too deeply
class celem2d;                 // Para evitar error de compilación: #include nested too deeply

class cnodo2d {

    public:
        int id;
        double x;
        double y;
        double w;          // "Indicador".
        vector <cnodo2d *> v1nodos;
//        cnodo2d* arr[] = {NULL, NULL};
//        vector <cnodo2d *> nodp (arr, ARRAY_END(ARR);
//        vector <cnodo2d *> nodp = vector <cnodo2d *>(2);
        carista *aristamadre;                   // Debería sustituir a la línea anterior.

        double ua;         // Solución analítica.
        double uh;         // Aproximación numérica de la solución.

        cnodo2d *nododesplazado;    // Posición del nodo desplazado sobre la característica. Solo se usa para la frontera 1.
        celem2d *eltodesplazado;    // Elemento al que pertenece el anterior.

//        cnodo2d *north;
//        cnodo2d *south;
//        cnodo2d *east;
//        cnodo2d *west;

        /* -----------------------------------------------------   */

        cnodo2d ();
        cnodo2d (int);
        cnodo2d (int, double, double);
        cnodo2d (int, double, double, double);
        void print ();
};

#endif

/* -------------------------------------------------------------   */

