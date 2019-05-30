#include "matvecreduce.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void matvecreduce (SparseMatrix <double> a, vector <int> libres, SparseMatrix <double> &b) {
    
    /* MATVECREDUCE: Reducción de una matriz a las filas y columnas indicadas.

    Entradas:
    - a:      matriz.
    - libres: índices de los nodos libres.

    Entrada/salida:
    - b: (puntero a la) matriz.
    */
 
    int n = libres.size ();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            b.coeffRef (i,j) = a.coeffRef (libres[i], libres[j]);
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void matvecreduce (SparseMatrix <double> a, vector <int> libres, vector <int> activos, SparseMatrix <double> &b) {
    
    /* MATVECREDUCE: Reducción de una matriz a las filas y columnas indicadas.

    Entradas:
    - a: matriz.
    - libres: índices de los nodos libres.
    - activos: índices de los nodos activos.

    Entrada/salida:
    - b: (puntero a la) matriz.
    */
 
    int n = libres.size ();
    int m = activos.size ();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            b.coeffRef (i,j) = a.coeffRef (libres[i], activos[j]);
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void matvecreduce (VectorXd a, vector <int> ind, VectorXd &b) {
    
    /* MATVECREDUCE: Reducción de un vector a las filas indicadas.

    Entradas:
    - a:   vector.
    - ind: índices de los nodos.

    Entrada/salida:
    - b: (puntero al) vector
    */
 
    int n = ind.size ();
    for (int i=0; i<n; i++) {
        b (i) = a (ind[i]);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

