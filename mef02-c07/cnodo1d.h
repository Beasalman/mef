#include <iostream>
using std::cout;
using std::endl;

#include <stdio.h>

/* ---------------------------------------------------------------------------------------- */

#ifndef cnodo1d_h_
#define cnodo1d_h_

class cnodo1d {

    public:
        int id;
        double x;          // Abscisas de la malla: variable auxiliar, x = ln (S/E).
        double s;          // Abscisas de la malla: valor del subyacente.

        double ua;         // Solución analítica (variable auxiliar H).
        double va;         // Solución analítica (valor del derivado, V).
        double uh;         // Aproximación del valor de la función H.
        double vh;         // Aproximación del valor del activo.
    
        cnodo1d ();
        cnodo1d (int);
        cnodo1d (int,double);
        void print ();
};

#endif

/* ---------------------------------------------------------------------------------------- */

