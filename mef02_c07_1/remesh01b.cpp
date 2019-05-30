#include "remesh01b.h"

/* --------------------------------------------------------------------------- */

void remesh01b (cmalla2d01 *m) {

    /* REMESH01B: Refinamiento de mallado: marcado de elementos y aristas.
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
//            ef->aristas[1]->mark = 1;
//            ef->aristas[2]->mark = 1;
        }
    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

