# include "mat3d11.h"

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [grad(u) grad(v) dx]
                         
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

    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    for (int k = 0; k < g->n; k++) {
        a += ((dpkT * (cki * (ckiT * dpk))) * g->peso[k]);
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, double (*diff)(double,double), Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [a(x,y) grad(u) grad(v) dx]
                         
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

    Vector2d p, z;
    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    // Bucle sobre los nodos de integración.

    for (int k = 0; k < g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;
        a += ((dpkT * (cki * (ckiT * dpk))) * g->peso[k]) * diff (p(0), p(1));
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, double t, double (*diff)(double,double,double), Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [a(x,y,t) grad(u) grad(v) dx]
                         
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

    Vector2d p, z;
    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    // Bucle sobre los nodos de integración.

    for (int k = 0; k < g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;
        a += ((dpkT * (cki * (ckiT * dpk))) * g->peso[k]) * diff (p(0), p(1), t);
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, Matrix2d (*diff)(double,double), Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [A(x,y) grad(u) grad(v) dx]
                         
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

    Vector2d p, z;
    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    // Bucle sobre los nodos de integración.

    for (int k = 0; k < g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;
        a += (dpkT * (cki * (diff (p(0),p(1)) * (ckiT * dpk)))) * g->peso[k];
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, double t, Matrix2d (*diff)(double,double,double), Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [A(x,y,t) grad(u) grad(v) dx]
                         
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

    Vector2d p, z;
    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    // Bucle sobre los nodos de integración.

    for (int k = 0; k < g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;
        a += (dpkT * (cki * (diff (p(0),p(1),t) * (ckiT * dpk)))) * g->peso[k];
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

void mat3d11 (celem2d *ef, cgauss02 *g, cdiffusion2d *diff, Matrix3d &a) {

    /* MAT3D11: Matriz elemental.
                Triángulo, tres grados de libertad (vértices).
                Término de difusión: Int [A(x,y) grad(u) grad(v) dx]
                         
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

    Vector2d p, z;
    Matrix2d cki = ef->ck.inverse ();
    Matrix2d ckiT = cki.transpose ();
    Matrix2d mdiff;

    // Coeficientes de la matriz elemental: término de difusión.

    MatrixXd dpk (2,3);
    dpk (0,0) = -1.0;
    dpk (0,1) = 1.0;
    dpk (0,2) = 0.0;
    dpk (1,0) = -1.0;
    dpk (1,1) = 0.0;
    dpk (1,2) = 1.0;
    MatrixXd dpkT = dpk.transpose ();

    // Bucle sobre los nodos de integración.

    for (int k = 0; k < g->n; k++) {
        z (0) = g->x[k];
        z (1) = g->y[k];
        p = ef->ck * z + ef->dk;
        mdiff = (*diff)(p(0),p(1));
        a += (dpkT * (cki * (mdiff * (ckiT * dpk)))) * g->peso[k];
    }
    a = a * ef->jac;
}

/* --------------------------------------------------------------------- */

