#include "carac1d.h"

/* ------------------------------------------------------------------------------------------------ */

void carac1d (cmalla1d *m, cgauss1d *g, cvelocity1d *velo, ccurve *cc, vector<double> &caracpoint, vector <celem1d *> &caracelt) {

    /* CARAC1D: Cálculo de los puntos desplazados sobre las curvas características.

    Entradas:
    - m: malla.
    - g: nodos y pesos de integración.

    Salidas:
    - caracpoint: vector que almacena los puntos desplazados sobre la característica.
    - caracelt:   vector que almacena el elemento al que pertenece cada uno de los puntos anteriores.
    */

    double xm, xk, point;
    celem1d *ef, *elt;
    cnodo1d *nod;
    vector <celem1d *> pcarac;

    // Bucle sobre los elementos.

    for (int i=0; i<m->nelt; i++) {
        ef = m->eltos[i];

        // Bucle sobre los nodos de integración.

        for (int k=0; k<g->n; k++) {
            xk = ef->xm + 0.5 * ef->h * g->x[k];             // Punto en el intervalo real.
            point = (*cc) (xk);                              // Desplazamiento sobre la característica.
            elt = m->locp (point, velo, ef);                 // Localización en el nuevo elemento.
            caracpoint.push_back (point);                    // Salvaguarda del punto desplazado y del elemento.
            caracelt.push_back (elt);
        }
    }
}

/* ------------------------------------------------------------------------------------------------ */
