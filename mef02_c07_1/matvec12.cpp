#include "matvec12.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void matvec12 (cmalla2d01 *m, cgauss02 *g, double deltat, double theta, csecond01 *sec, SparseMatrix<double> &a, VectorXd &b) {

    /* MATVEC12:
                 Matrices llenas.

    */

    celem2d *ef;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    Matrix3d aelt, aelt01, aelt02;
    Vector3d belt, belt01, belt02;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        aelt = Matrix3d::Zero ();
        aelt01 = Matrix3d::Zero ();
        aelt02 = Matrix3d::Zero ();
        belt01 = Vector3d::Zero ();

        mat3d11 (ef, g, aelt01);
        mat3d12 (ef, g, aelt02);
        vec3d11 (ef, g, sec, belt01);

        aelt = aelt02 + theta * deltat * aelt01;

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, aelt, belt01, a, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

