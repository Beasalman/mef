#include "prolong.h"

/* --------------------------------------------------------------------------- */

void prolong (cmalla2d01 *m, VectorXd u, cmalla2d01 *p, VectorXd &w) {

    /* PROLONG: interpolación de los valores de U (en la malla M) sobre una malla más fina (P).

    Entradas:
    - m: (puntero a) malla gruesa.
    - u: vector sobre la malla anterior.
    - p: (puntero a) malla fina.

    Salida:
    - w: vector interpolado sobre la nueva malla (P).
    */

    cnodo2d *nod, *nodp0, *nodp1;
    carista *art;

    /* ----------------------------------------------------------------------- */
    // Nodos de la malla gruesa.

    for (int i=0; i<m->nsom; i++) {
        w (i) = u (i);
    }

    // Nodos de la malla fina no contenidos en la malla gruesa.

    int n1 = m->nsom;
    for (int i=n1; i<p->nsom; i++) {
        nod = p->nodos [i];
        art = nod->aristamadre;
        nodp0 = art->nodos [0];
        nodp1 = art->nodos [1];
        w (i) = 0.5 * (u(nodp0->id) + u(nodp1->id));
    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

