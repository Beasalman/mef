#include "globalvec02.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec02 (cmalla1d *m, cgauss1d *g, vector <double> caracpoint, vector <celem1d *> caracelt, 
                  VectorXd uold, VectorXd &b) {

    /* GLOBALVEC02: Construcción del vector global correspondiente al término de características.
                    Problema unidimensional.
                    Vectores elementales de dimensión dos (un grado de libertad por nodo).
    */

    int kef;
    celem1d *ef;
    std::vector <int> indices (2);
    Vector2d belt;
    vector <double> cpoint (g->n);
    vector <celem1d *> celt (g->n);

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (int nef=0; nef<m->eltos.size(); nef++) {
        ef = m->eltos [nef];

        // Indices de los nodos.

        for (int k=0; k<ef->nodos.size(); k++) {
            indices [k] = ef->nodos[k]->id;
        }

        // Puntos desplazados.

        for (int k=0; k<g->n; k++) {
            kef = g->n * ef->id + k;
            cpoint [k] = caracpoint [kef];
            celt [k] = caracelt [kef];
        }

        // Vector elemental y ensamblado.

        belt = Vector2d::Zero ();
        elvec1d2gdl02 (ef, g, cpoint, celt, uold, belt);
        ensvec (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

