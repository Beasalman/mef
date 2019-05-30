#include "cmark02.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Marcado de elementos: 

cmark02::cmark02 (double s) {

    this->sigma = s;
}

/* ----------------------------------------------------------- */

void cmark02::operator () (cmalla2d01 *m) {

    /* CMARK02: Refinamiento de mallado: marcado de elementos y aristas.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i;
    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    double criterio = 0.0;

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        criterio = max (criterio, ef->estimador);
    }
    criterio = this->sigma * criterio;

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        if (ef->estimador >= criterio) {
            ef->mark = 1;
            ef->aristas[0]->mark = 1;
        }
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

