#include "util01.h"

/* --------------------------------------------------------------------------- */

void util01 (cmalla2d01 *m) {

    /* 

    Entradas:
    - m: (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    map <int, celem2d *>::iterator ielt;
    for (ielt=m->eltos.begin(); ielt != m->eltos.end(); ielt++) {
        m->auxelt.push_back (ielt->second);
    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

