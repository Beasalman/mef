#include "dirichlet20.h"

/* ------------------------------------------------------------------------------- */

void dirichlet20 (cmalla2d01 *m, MatrixXd &a, VectorXd &b) {

    /* DIRICHLET20: Condiciones de contorno Dirichlet homogéneas.
                    Problema bidimensional.
                    Matrices llenas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            k = fr->nodos[i]->id;
            a (k,k) = arroba;
            b (k) = 0.0;
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet20 (cmalla2d01 *m, SparseMatrix <double> &a, VectorXd &b) {

    /* DIRICHLET20: Condiciones de contorno Dirichlet homogéneas.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            k = fr->nodos[i]->id;
            a.coeffRef (k,k) = arroba;
            b (k) = 0.0;
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet20 (cmalla2d01 *m, SparseMatrix <double> &a) {

    /* DIRICHLET20: Condiciones de contorno Dirichlet homogéneas.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    */

    int i, j, k;
    cfrontera2d *fr;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            k = fr->nodos[i]->id;
            a.coeffRef (k,k) = arroba;
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet20 (cmalla2d01 *m, VectorXd &b) {

    /* DIRICHLET20: Condiciones de contorno Dirichlet homogéneas.
                    Problema bidimensional.
                    Vector.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            k = fr->nodos[i]->id;
            b (k) = 0.0;
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

