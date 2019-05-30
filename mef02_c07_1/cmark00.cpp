#include "cmark00.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Marcado de elementos: refinamiento uniforme.

cmark00::cmark00 () {

    this->sigma = 0.0;
}

/* ----------------------------------------------------------- */

void cmark00::operator () (cmalla2d01 *m) {

    /* CMARK00: Refinamiento de mallado: marcado de elementos y aristas.
                Refinamiento uniforme.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i;
    int aux = m->nelt;
    double w;
    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        if (aux > 0) {
            ef = ie->second;
            ef->mark = 1;
            ef->aristas[0]->mark = 1;
            aux -= 1;
        }
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

