#include "dirichlet21.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet21 (cmalla2d01 *m, double (*f)(double,double), SparseMatrix <double> &a, VectorXd &b) {

    /* DIRICHLET21: Condiciones de contorno Dirichlet sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.
    - f: función que describre las condiciones sobre la frontera de toda la malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;
    cnodo2d *nod;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet21 (cfrontera2d *fr, double (*f)(double,double), SparseMatrix <double> &a, VectorXd &b) {

    /* DIRICHLET21: Condiciones de contorno Dirichlet sobre una única frontera.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.
    - f: función que describre las condiciones sobre la frontera de toda la malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cnodo2d *nod;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
        b (k) = arroba * f (nod->x,nod->y);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

