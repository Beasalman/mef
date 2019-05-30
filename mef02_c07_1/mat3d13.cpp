# include "mat3d13.h"

/* --------------------------------------------------------------------- */

void mat3d13 (celem2d *ef, cgauss02 *g, Matrix3d &a) {

    /* MAT3D12: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de masa: Int [y u v dx dy]

       Entradas:
       - ef: elemento actual.
       - g: nodos y pesos de integración.

       Entrada/salida:
       - a: matriz elemental.

       Observaciones:
       - la numeración local de los nodos en el triángulo de referencia es la siguiente:
               nodo 0: vértice de coordenadas (0,0)
               nodo 1: vértice de coordenadas (1,0)
               nodo 2: vértice de coordenadas (0,1)
    */

    // Coeficientes de la matriz elemental.

    Vector2d p, z;
    MatrixXd pk (1,3);

    for (int k=0; k<g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;

        pk (0,0) = 1.0 - z [0] - z [1];
        pk (0,1) = z [0];
        pk (0,2) = z [1];

        a += g->peso[k] * (p(1) * pk.transpose() * pk);
    }
    a = ef->jac * a;
}

/* --------------------------------------------------------------------- */

