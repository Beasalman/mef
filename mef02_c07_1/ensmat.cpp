#include "ensmat.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensmat (vector <int> ind, Matrix2d aelt, SparseMatrix <double> &a) {
    
    /* ENSMAT: Ensamblado de una matriz hueca.

    Entradas:
    - ind:  índices de las posiciones en la matriz global.
    - aelt: matriz elemental (dimensión 3).

    Entrada/salida:
    - a: (puntero a la) matriz global.
    */
    
    int n = ind.size ();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            a.coeffRef (ind[i],ind[j]) += aelt (i,j);  
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

