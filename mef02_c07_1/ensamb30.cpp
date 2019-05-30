#include "ensamb30.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensamb30 (vector<int> ind, Matrix3d aelt, Vector3d belt, MatrixXd &a, VectorXd &b) {
    
    /* ENSAMB30: Ensamblado de la matriz del sistema.
                 Matriz y vector elementales de dimensión 3.
                 Matrices llenas.

    Entradas:
    - ind:  índices de las posiciones en la matriz global.
    - aelt: matriz elemental (dimensión 3).
    - belt: vector elemental (dimensión 3).

    Entrada/salida:
    - a: (puntero a la) matriz global.
    - b: (punto a) vector global.
    */
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            a (ind[i],ind[j]) += aelt (i,j);  
        }
        b (ind[i]) += belt (i);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensamb30 (vector<int> ind, Matrix3d aelt, Vector3d belt, SparseMatrix <double> &a, VectorXd &b) {
    
    /* ENSAMB30: Ensamblado de la matriz del sistema.
                 Matriz y vector elementales de dimensión 3.
                 Matrices huecas.

    Entradas:
    - ind:  índices de las posiciones en la matriz global.
    - aelt: matriz elemental (dimensión 3).
    - belt: vector elemental (dimensión 3).

    Entrada/salida:
    - a: (puntero a la) matriz global.
    - b: (punto a) vector global.
    */
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            a.coeffRef (ind[i],ind[j]) += aelt (i,j);  
        }
        b (ind[i]) += belt (i);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensamb30 (vector<int> ind, Matrix3d aelt, SparseMatrix <double> &a) {
    
    /* ENSAMB30: Ensamblado de la matriz del sistema.
                 Matriz elemental de dimensión 3.
                 Matrices huecas.

    Entradas:
    - ind:  índices de las posiciones en la matriz global.
    - aelt: matriz elemental (dimensión 3).

    Entrada/salida:
    - a: (puntero a la) matriz global.
    */
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            a.coeffRef (ind[i],ind[j]) += aelt (i,j);  
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void ensamb30 (vector<int> ind, Vector3d belt, VectorXd &b) {
    
    /* ENSAMB30: Ensamblado de un vector.
                 Vector elementales de dimensión 3.

    Entradas:
    - ind:  índices de las posiciones en la matriz global.
    - belt: vector elemental (dimensión 3).

    Entrada/salida:
    - b: (punto a) vector global.
    */
    
    for (int i=0; i<3; i++) {
        b (ind[i]) += belt (i);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

