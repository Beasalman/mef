#include "carac02.h"

/* --------------------------------------------------------------------------- */

cnodo2d* carac02 (Vector2d q, double deltat, int nt, cconvection2d *conv, cmalla2d01 *m) {

    /* CARAC02: Desplazamiento de un punto sobre la curva característica.
                Velocidad variable, dependiente únicamente de la posición espacial.
                Método de Euler explícito.
                Comprobación sobre pertenencia al dominio.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - nt:     número de pasos de tiempo del método de Euler.
       - conv:   función velocidad.
       - m:      (puntero a) malla inicial del dominio.

       Salidas:
       - p: punto desplazado.
    */
    // -----------------------------------------------------------------------

    cnodo2d *p = new cnodo2d (-1, q(0), q(1));
    cnodo2d *pnext = new cnodo2d (-1, q(0), q(1));          // Creación del nuevo punto.

    double dt = deltat / nt;
    Vector2d w;

    for (int i=0; i<nt; i++) {
        w = (*conv) (p->x, p->y);
        pnext->x = p->x - w(0) * dt;
        pnext->y = p->y - w(1) * dt;

        if (m->domain->contains(pnext)) {
            p->x = pnext->x;
            p->y = pnext->y;
        } else {
            break;
        }
    }
    return p;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */









/*
cnodo2d carac02 (cnodo2d *q, double deltat, int nt, vector <double> v, cmalla2d01 *m) {
*/

    /* CARAC02: Desplazamiento de un punto sobre la curva característica.
                Velocidad constante.
                Método de Euler explícito.
                Comprobación sobre pertenencia al dominio.

       Entradas:
       - q:      punto a desplazar.
       - deltat: paso de tiempo.
       - v:      función velocidad.
       - m:      (puntero a) malla inicial del dominio.

       Salidas:
       - p: punto desplazado.
    */

/*
    cnodo2d p, pnext;                       // Creación del nuevo punto.
    p = cnodo2d (-1, q->x, q->y);

    double dt = deltat / nt;

    for (int i=0; i<nt; i++) {
        pnext.x = p.x - v[0] * dt;
        pnext.y = p.y - v[1] * dt;

        if (!localiza00 (m, &pnext)) {
            break;
        }
        p = pnext;
    }

    return p;
}
*/

/* --------------------------------------------------------------------------- */

/*
cnodo2d carac02 (cnodo2d *q, double deltat, int nt, vector <double> (*v)(double,double), cmalla2d01 *m) {
*/

    /* CARAC02: Desplazamiento de un punto sobre la curva característica.
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

/*
    cnodo2d p, pnext;                               // Creación del nuevo punto.
    p = cnodo2d (-1, q->x, q->y);

    double dt = deltat / nt;
    vector <double> w;

    for (int i=0; i<nt; i++) {
        w = v (p.x, p.y);
        pnext.x = p.x - w[0] * dt;
        pnext.y = p.y - w[1] * dt;

        if (!localiza00 (m, &pnext)) {
            break;
        }
        p = pnext;
    }

    return p;
}
*/

/* --------------------------------------------------------------------------- */

/*
cnodo2d carac02 (cnodo2d *q, double deltat, int nt, double t, vector <double> (*v)(double,double,double), cmalla2d01 *m) {
*/

    /* CARAC02: Desplazamiento de un punto sobre la curva característica.
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

/*
    double ti = t;
    cnodo2d p, pnext;                               // Creación del nuevo punto.
    p = cnodo2d (-1, q->x, q->y);

    double dt = deltat / nt;
    vector <double> w;

    for (int i=0; i<nt; i++) {
        ti = ti - dt;
        w = v (p.x, p.y, ti);
        pnext.x = p.x - w[0] * dt;
        pnext.y = p.y - w[1] * dt;

        if (!localiza00 (m, &pnext)) {
            break;
        }
        p = pnext;
    }

    return p;
}
*/

/* --------------------------------------------------------------------------- */

