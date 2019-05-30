#include "util03.h"

/* ------------------------------------------------------------------------------------ */

VectorXd util03 (cmalla2d01 *m, canalitica2d *analyt, double t) {

    /* UTIL03: Volcado de la solución analítica en un vector.

    Entradas:
    - m:      (puntero a) malla.
    - analyt: (puntero a) función que describe la solución analítica.
    - t:      instante de tiempo (real).

    Salidas:
    - ua: solución analítica discretizada sobre los nodos de la malla.
    */

    cnodo2d *nod;
    VectorXd ua = VectorXd::Zero (m->nsom);

    for (int i=0; i<m->nsom; i++) {
        nod = m->nodos [i];
        ua (i) = (*analyt) (nod->x, nod->y, t);
    }
    return ua;
}

/* ------------------------------------------------------------------------------------ */

