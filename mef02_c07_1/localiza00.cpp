#include "localiza00.h"

/* --------------------------------------------------------------------------- */

bool localiza00 (cmalla2d01 *m, cnodo2d *p) {

    /* LOCALIZA00: Pertenencia de un punto a un dominio.

       Entradas:
       - m: malla (sencilla) del dominio.
       - p: punto a localizar.

       Salidas:
       - z: 
    */

    bool z = false;
    map <int, celem2d *>::iterator ielt;

    for (ielt=m->eltos.begin(); ielt != m->eltos.end(); ielt++) {
        if (ielt->second->contains (p)) {
            z = true;
            break;
        }
    }

    return z;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

