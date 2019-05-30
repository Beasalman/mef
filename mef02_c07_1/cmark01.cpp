#include "cmark01.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Marcado de elementos: 

cmark01::cmark01 () {

    this->sigma = 0.0;
}

/* ----------------------------------------------------------- */

void cmark01::operator () (cmalla2d01 *m) {

    /* CMARK01: Refinamiento de mallado: marcado de elementos y aristas.
                Se hereda el criterio desde la malla inicial.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i;
    double w;

    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        w = ef->nodos[0]->w + ef->nodos[1]->w + ef->nodos[2]->w;

        if (w > 0.0 && w < 3.0) {
            ef->aristas[0]->mark = 1;
        }
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

