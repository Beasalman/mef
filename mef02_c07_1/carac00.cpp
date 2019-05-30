#include "carac00.h"

/* --------------------------------------------------------------------------- */

cnodo2d carac00 (cnodo2d *q, double deltat, int nt, vector <double> v, cmalla2d01 *m) {

    /* CARAC00: Desplazamiento de un punto sobre la curva característica.
                Velocidad constante.
                Método de Euler explícito.
                Comprobación sobre pertenencia al dominio.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - nt:     número de pasos de tiempo del método de Euler.
       - v:      función velocidad.
       - m:      (puntero a) malla inicial del dominio.

       Salidas:
       - p: punto desplazado.
    */

    cnodo2d p = carac01 (q, deltat, nt, v);
    if (!localiza00 (m,&p)) {
        p = carac02 (q, deltat, nt, v, m);
    }

    return p;
}

/* --------------------------------------------------------------------------- */

cnodo2d carac00 (cnodo2d *q, double deltat, int nt, vector <double> (*v)(double,double), cmalla2d01 *m) {

    /* CARAC00: Desplazamiento de un punto sobre la curva característica.
                Velocidad variable, dependiente únicamente de la posición espacial.
                Método de Euler explícito.
                Comprobación sobre pertenencia al dominio.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - nt:     número de pasos de tiempo del método de Euler.
       - v:      función velocidad.
       - m:      (puntero a) malla inicial del dominio.

       Salidas:
       - p: punto desplazado.
    */

    cnodo2d p = carac02 (q, deltat, nt, v, m);

    return p;
}

/* --------------------------------------------------------------------------- */

cnodo2d carac00 (cnodo2d *q, double deltat, int nt, double t, vector <double> (*v)(double,double,double), cmalla2d01 *m) {

    /* CARAC00: Desplazamiento de un punto sobre la curva característica.
                Velocidad variable, dependiente de la posición espacial y del tiempo.
                Método de Euler explícito.
                Comprobación sobre pertenencia al dominio.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - nt:     número de pasos de tiempo del método de Euler.
       - t:      instante de tiempo actual.
       - v:      función velocidad.
       - m:      (puntero a) malla inicial del dominio.

       Salidas:
       - p: punto desplazado.
    */

    cnodo2d p = carac02 (q, deltat, nt, t, v, m);

    return p;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

