#include "cmark03.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cmark03::cmark03 () {

    this->sigma = 0.0;
}

/* ----------------------------------------------------------- */

void cmark03::operator () (cmalla2d01 *m) {

    /* CMARK03: Refinamiento de mallado: marcado de elementos y aristas.
                Circunferencia centrada.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i;
    double d;
    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        d = sqrt (pow (ef->cdg.x-0.5,2) + pow (ef->cdg.y-0.5,2));

        if (0.20 <= d && d <= 0.40 && ef->cdg.x >= 0.5) {
            ef->mark = 1;
            ef->aristas[0]->mark = 1;
        }
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

