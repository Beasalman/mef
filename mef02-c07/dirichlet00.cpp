#include "dirichlet00.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void dirichlet00 (cmalla1d *m, SparseMatrix <double> &a) {

    /* DIRICHLET00: Condiciones de contorno Dirichlet homogéneas sobre la matriz.
                    Almacenamiento en matriz hueca.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    */

    int i, k;
    cfrontera1d *fr;
    cnodo1d *nod;

    // ---------------------------------------------------------------------------

   for (i=0; i<m->nfr; i++) {
        fr = m->fronteras [i];

        nod = fr->nodo;
        k = nod->id;
        a.coeffRef (k,k) = m->arroba;
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void dirichlet00 (cmalla1d *m, VectorXd &b) {

    /* DIRICHLET00: Condiciones de contorno Dirichlet homogéneas sobre el vector.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: vector segundo miembro.
    */

    int i, k;
    cfrontera1d *fr;
    cnodo1d *nod;

    // ---------------------------------------------------------------------------

    for (i=0; i<m->nfr; i++) {
        fr = m->fronteras [i];

        nod = fr->nodo;
        k = nod->id;
        b (k) = 0.0;
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void dirichlet00 (cmalla1d *m, VectorXd &b, Vector2d dirich) {

    /* DIRICHLET00: Condiciones de contorno Dirichlet no homogéneas sobre el vector.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: vector segundo miembro.
    */

    int i, k;
    cfrontera1d *fr;
    cnodo1d *nod;

    // ---------------------------------------------------------------------------

    for (i=0; i<m->nfr; i++) {
        fr = m->fronteras [i];

        nod = fr->nodo;
        k = nod->id;
        b (k) = m->arroba * dirich (i);
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
