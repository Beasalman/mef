#include "error02.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

double error02 (VectorXd uh, VectorXd ua) {

    /* ERROR02: Cálculo del error relativo entre la aproximación numérica y la solución analítica.
                Norma 2.

    Entradas:
    - uh: aproximación numérica.
    - ua: solución analítica discretizada en los nodos.

    Salida:
    - err: error relativo.
    */

    double s1 = 0.0;
    double s2 = 0.0;
    double a1, a2;

    // --------------------------------------------------------------------

    for (int i=0; i<uh.size(); i++) {
        a2 = ua (i);
        a1 = uh (i) - a2;
        s1 += a1 * a1;
        s2 += a2 * a2;
    }

    return sqrt (s1 / s2);
} 

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

