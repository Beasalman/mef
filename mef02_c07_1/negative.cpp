#include "negative.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double negative (double x) {
    
    /* NEGATIVE: Parte negativa de un número.

    Entradas:
    - x: número real.

    Salida:
    - y: parte positiva de X.
    */
    
    double y = 0.0;
    if (x < 0.0) {
        y = x;
    }

    return y;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

VectorXd negative (VectorXd x) {
    
    /* POSITIVE: Parte positiva de las componentes de un vector.

    Entradas:
    - x: vector.

    Salida:
    - y: vector que contiene la parte positiva de cada componente de X.
    */
    
    int n = x.size();
    VectorXd y = VectorXd::Zero (n);
    for (int i=0; i<n; i++) {
        if (x(i) < 0.0) {
            y(i) = x(i);
        }
    }

    return y;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

