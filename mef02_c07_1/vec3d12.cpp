# include "vec3d12.h"

/* --------------------------------------------------------------------- */

void vec3d12 (celem2d *ef, cgauss02 *g, Vector3d w, Vector3d &b) {

    /* VEC3D12: Vector elemental.
                Contribución de una función discreta sobre un triángulo.

       Entradas:
       - ef: elemento finito.
       - g:  nodos y pesos de integración numérica.
       - w:  vector.
                    
       Salidas:
       - b: vector elemental.

       Observaciones:
       - la numeración local de los nodos en el triángulo de referencia es la siguiente:
               nodo 0: vértice de coordenadas (0,0)
               nodo 1: vértice de coordenadas (1,0)
               nodo 2: vértice de coordenadas (0,1)
    */

    double wp;      // Vector W interpolado en los nodos de cuadratura.
    double b0;      // Coordenada baricéntrica 0.

    /* ----------------------------------------------------------------- */

    for (int k=0; k<g->n; k++) {
        b0 = 1.0 - g->x [k] - g->y [k];
        wp = b0 * w (0) + g->x [k] * w (1) + g->y [k] * w (2);

        b (0) += g->peso [k] * b0 * wp;
        b (1) += g->peso [k] * g->x [k] * wp;
        b (2) += g->peso [k] * g->y [k] * wp;
    }
    b = ef->jac * b;
}

/* --------------------------------------------------------------------- */

