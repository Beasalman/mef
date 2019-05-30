#include "remesh01a.h"

/* --------------------------------------------------------------------------- */

void remesh01a (cmalla2d01 *m) {

    /* REMESH01A: Refinamiento de mallado: marcado de elementos y aristas.
                  Refinamiento uniforme.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i;
    double w;

    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    // Refinamiento uniforme.

    int aux = m->nelt;

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        if (aux > 0) {
            ef = ie->second;
            ef->mark = 1;
            ef->aristas[0]->mark = 1;
            aux -= 1;
        }
    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

