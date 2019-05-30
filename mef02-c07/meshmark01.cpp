#include "meshmark01.h"

/* --------------------------------------------------------------------------- */

void meshmark01 (cmalla2d01 *m, int k) {

    /* 

    Entradas:
    - m: (puntero a) la malla actual.
    - k: 
    */

    /* ----------------------------------------------------------------------- */

    cnodo2d p;
    cnodo2d *pp;
    celem2d *ef;
    map <int, celem2d *> :: iterator ie;

    if ((k == 3) || (k == 9) || (k == 15)) {
        for (int i=0; i<m->nsom; i++) {
            m->nodos[i]->w = 0.0;
        }

        cnodo2d p = cnodo2d (-1, 0.48, 0.98);
        pp = &p;

        for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
            ef = ie->second;
            if (ef->contains (pp)) {
                ef->nodos[0]->w = 1.0;
                break;
            }
        }
    }

/*
    if ((k == 6) || (k == 12) || (k == 18)) {
        for (int i=0; i<m->nsom; i++) {
            m->nodos[i]->w = 0.0;
        }

        cnodo2d p = cnodo2d (-1, 0.12, 0.02);
        pp = &p;

        for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
            ef = ie->second;
            if (ef->contains (pp)) {
                ef->nodos[0]->w = 1.0;
                break;
            }
        }
    }
    */

    // **************************************************************
    cout << "\n [MESHMARK01] Iteración " << k << "        Punto P: " << pp->x << " " << pp->y << endl;
    // **************************************************************

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

