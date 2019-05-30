#include "globalvec11.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec11 (cmalla2d01 *m, cgauss02 *g, csecond *sec, VectorXd &b, double t) {

    /* GLOBALVEC11: Término fuente.

    */

    celem2d *ef;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    Vector3d belt;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    b.setZero ();
    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        belt.setZero ();
        vec3d11 (ef, g, sec, belt, t);

        // ***********************************************************************************
        //cout << " [GLOBALVEC11]    Elemento: " << ef->id << "       belt(0): " << belt(0) << "       belt(1): " << belt(1) << "       belt(2): " << belt(2) << endl;
        // ***********************************************************************************

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec11 (cmalla2d01 *m, cgauss02 *g, csecond *sec, VectorXd &b) {

    /* GLOBALVEC11: Término fuente.

    */

    celem2d *ef;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    Vector3d belt;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    b.setZero ();
    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        vec3d11 (ef, g, sec, belt);

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

