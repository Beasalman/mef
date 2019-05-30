#include "dirichlet23.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet23 (cmalla2d01 *m, SparseMatrix <double> &a) {

    /* DIRICHLET23: Condiciones de contorno sobre todas las fronteras de la malla.
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
    cnodo2d *nod;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    fr = m->fronteras [0];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
    }

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
    }

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
    }

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet23 (cmalla2d01 *m, VectorXd v, VectorXd vhk, VectorXd vhold, double deltatau, double f, 
                  double hinf, double sinf, cpayoff *payoff, VectorXd &b) {

    /* DIRICHLET23: Condiciones de contorno sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m:     (puntero a) malla.
    - v:     valor sin riesgo.
    - vhk:   valor con riesgo en el paso anterior.
    - vhold: valor con riesgo en el instante anterior, combinado con características.

    Entrada/salida:
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;
    cnodo2d *nod;
    celem2d *elt;

    double arroba = 1.e+15;
    double coef = 1.0 / (1.0 + deltatau * f);
    double c1, b0, b1, b2, bc;

    // ---------------------------------------------------------------------------

    fr = m->fronteras [0];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        b (k) = arroba * v (k);
    }

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];

        elt = nod->eltodesplazado;
        b1 = nod->nododesplazado->x;
        b2 = nod->nododesplazado->y;
        b0 = 1.0 - b1 - b2;
        bc = b0 * vhold (elt->nodos[0]->id) + b1 * vhold (elt->nodos[1]->id) + b2 * vhold (elt->nodos[2]->id);

        k = nod->id;
        c1 = -deltatau * hinf * nod->y * positive (vhk(k)) + bc;
        b (k) = arroba * max (coef * c1, (*payoff)(nod->x)); 
    }

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        b (k) = 0.0;
    }

    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

