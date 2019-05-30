#include "globalvec12.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec12 (cmalla2d01 *m, cgauss02 *g, VectorXd v, VectorXd &b) {

    /* GLOBALVEC12: Segundo miembro, contribución del término de características.

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

    // ************************************************************************************
    //cout << "\n [GLOBALVEC12]    " << endl;
    //for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
    //    ef = ielt->second;
    //    cout << "     Elemento: " << ef->id;
    //    cout << "   eltosdesplazados.size: " << ef->eltosdesplazados.size();
    //    cout << "   nodosdesplazados.size: " << ef->nodosdesplazados.size();
    //    cout << endl;
    //}
    // ************************************************************************************

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        // ************************************************************************************
        //cout << "\n [GLOBALVEC12]    ef->id: " << ef->id << endl;
        // ************************************************************************************

        // Puntos desplazados y valores interpolados.

        for (int i=0; i<g->n; i++) {

            // ************************************************************************************
            //cout << " [GLOBALVEC12]         i: " << i << endl;
            // ************************************************************************************

            elt = ef->eltosdesplazados [i];
            b1 = ef->nodosdesplazados[i]->x;
            b2 = ef->nodosdesplazados[i]->y;
            b0 = 1.0 - b1 - b2;
            w (i) = b0 * v (elt->nodos[0]->id) + b1 * v (elt->nodos[1]->id) + b2 * v (elt->nodos[2]->id);
        }

        // ************************************************************************************
        //cout << " [GLOBALVEC12]             Llamamos a VEC3D12 " << endl;
        // ************************************************************************************

        vec3d12 (ef, g, w, belt);

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

