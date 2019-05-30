#include "cmark04.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cmark04::cmark04 () {

    this->sigma = 0.0;
}

/* ----------------------------------------------------------- */

void cmark04::operator () (cmalla2d01 *m, VectorXd u, VectorXd psi) {

    /* CMARK04: Refinamiento de mallado: marcado de elementos y aristas.
                Contacto con la frontera libre.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    int i, k;
    double z;
    cnodo2d *nod;
    celem2d *ef;
    std::map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        z = 0.0;
        for (i=0; i<ef->nodos.size(); i++) {
            k = ef->nodos [i]->id;
            z += abs (u(k) - psi(k));
        }

        if (z > 0.0) {
            ef->mark = 1;
            ef->aristas[0]->mark = 1;
        }
    }
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

