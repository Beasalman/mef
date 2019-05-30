# include "vec3d11.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void vec3d11 (celem2d *ef, cgauss02 *g, csecond *sec, Vector3d &b, double t) {

    /* VEC3D11: Vector elemental.
                Segundo miembro de la clase CFUNC11.

       Entradas:
       - ef:  elemento finito.
       - g:   nodos y pesos de integración numérica.
       - sec: (puntero a) función segundo miembro.
       - t:   instante de tiempo (real).
 
       Salidas:
       - b: vector elemental.

       Observaciones:
       - la numeración local de los nodos en el triángulo de referencia es la siguiente:
               nodo 0: vértice de coordenadas (0,0)
               nodo 1: vértice de coordenadas (1,0)
               nodo 2: vértice de coordenadas (0,1)
    */

    double fp;

    Vector2d z;
    Vector2d p;

    /* ----------------------------------------------------------------- */

    for (int k=0; k<g->n; k++) {
        z (0) = g->x [k];
        z (1) = g->y [k];
        p = ef->ck * z + ef->dk;
        fp = (*sec) (p(0), p(1), t);

        b (0) += g->peso [k] * (1.0 - g->x [k] - g->y [k]) * fp;
        b (1) += g->peso [k] * g->x [k] * fp;
        b (2) += g->peso [k] * g->y [k] * fp;
    }
    b = ef->jac * b;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

void vec3d11 (celem2d *ef, cgauss02 *g, csecond *sec, Vector3d &b) {

    /* VEC3D11: Vector elemental.
                Segundo miembro de la clase CFUNC11.

       Entradas:
       - ef:  elemento finito.
       - g:   nodos y pesos de integración numérica.
       - sec: (puntero a) función segundo miembro.
                    
       Salidas:
       - b: vector elemental.

       Observaciones:
       - la numeración local de los nodos en el triángulo de referencia es la siguiente:
               nodo 0: vértice de coordenadas (0,0)
               nodo 1: vértice de coordenadas (1,0)
               nodo 2: vértice de coordenadas (0,1)
    */

    double fp;

    Vector2d z;
    Vector2d p;

    /* ----------------------------------------------------------------- */

    for (int k=0; k<g->n; k++) {
        z (0) = g->x [k];
        z (1) = g->y [k];
        p = ef->ck * z + ef->dk;
        fp = (*sec) (p(0), p(1));

        b (0) += g->peso [k] * (1.0 - g->x [k] - g->y [k]) * fp;
        b (1) += g->peso [k] * g->x [k] * fp;
        b (2) += g->peso [k] * g->y [k] * fp;
    }
    b = ef->jac * b;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

