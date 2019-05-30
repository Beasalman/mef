#include "ensvec.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensvec (vector <int> ind, Vector2d belt, VectorXd &b) {
    
    /* ENSVEC: Ensamblado de un vector.

    Entradas:
    - ind:  índices de las posiciones en el vector global.
    - aelt: vector elemental.

    Entrada/salida:
    - a: (puntero al) vector global.
    */
    
    int n = ind.size ();
    for (int i=0; i<n; i++) {
        b (ind[i]) += belt (i);  
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

