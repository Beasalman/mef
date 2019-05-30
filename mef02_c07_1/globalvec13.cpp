#include "globalvec13.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec13 (cmalla2d01 *m, cgauss02 *g, VectorXd v, VectorXd &b) {

    /* GLOBALVEC13: Segundo miembro, integral de una función discreta.

    Entradas:
    - m: (puntero a) malla.
    - g: (puntero a) nodos de integración.
    - v: vector que contiene los valores que vamos a interpolar sobre los nodos desplazados.

    Entrada/salida:
    - b: vector global.
    */

    celem2d *ef, *elt;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    double z, b0, b1, b2;
    Vector3d w, belt;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        // Interpolación del vector W en los nodos de cuadratura.

        for (int i=0; i<g->n; i++) {
            b1 = ef->nodos[i]->x;
            b2 = ef->nodos[i]->y;
            b0 = 1.0 - b1 - b2;
            w (i) = v (indices[0]) * b0 + v (indices[1]) * b1 + v (indices[2]) * b2;
        }

        // Integración.

        vec3d12 (ef, g, w, belt);
        ensamb30 (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

