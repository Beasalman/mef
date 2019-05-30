#include "matvec11.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void matvec11 (cmalla2d01 *m, cgauss02 *g, cdiffusion2d *diff, csecond *sec, SparseMatrix<double> &a, VectorXd &b) {

    /* MATVEC11:

    */

    celem2d *ef;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    Matrix3d aelt01;
    Vector3d belt01;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        aelt01 = Matrix3d::Zero ();
        belt01 = Vector3d::Zero ();

        mat3d11 (ef, g, diff, aelt01);
        vec3d11 (ef, g, sec, belt01);

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, aelt01, belt01, a, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

