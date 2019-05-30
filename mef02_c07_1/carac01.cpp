#include "carac01.h"

/* --------------------------------------------------------------------------- */

cnodo2d carac01 (cnodo2d *q, double deltat, int nt, vector <double> v) {

    /* CARAC01: Desplazamiento de un punto sobre la curva característica.
                Velocidad constante.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - v:      velocidad.

       Salidas:
       - p: punto desplazado.
    */

    cnodo2d p;                             // Creación del nuevo punto.
    p = cnodo2d (-1, q->x, q->y);
    p.x -= v[0] * deltat;
    p.y -= v[1] * deltat;

    return p;
}

/* --------------------------------------------------------------------------- */

cnodo2d carac01 (cnodo2d *q, double deltat, int nt, vector <double> (*v)(double,double)) {

    /* CARAC01: Desplazamiento de un punto sobre la curva característica.
                Velocidad dependiente de la posición espacial.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - v:      función velocidad.

       Salidas:
       - p: punto desplazado.
    */

    cnodo2d p;                               // Creación del nuevo punto.
    p = cnodo2d (-1, q->x, q->y);

    double dt = deltat / nt;
    vector <double> w;

    for (int i=0; i<nt; i++) {
        w = v (p.x, p.y);
        p.x -= w[0] * dt;
        p.y -= w[1] * dt;                // Habría que comprobar si nos salimos del dominio.
    }

    return p;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

