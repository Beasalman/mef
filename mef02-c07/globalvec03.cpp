#include "globalvec03.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalvec03 (cmalla1d *m, cgauss1d *g, VectorXd v, VectorXd &b) {

    /* GLOBALVEC02: Construcción del vector global correspondiente al término de características.
                    Problema unidimensional.
                    Vectores elementales de dimensión dos (un grado de libertad por nodo).
    */

    int kef;
    float c1,c2, vcar;
    celem1d *ef;
    cnodo1d *nod1, *nod2;
    std::vector <int> indices (2);
    // std::vector <float> hatp(2):
      Vector2d belt, hatp;
    vector <double> cpoint (g->n);
    
    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (int nef=0; nef<m->eltos.size(); nef++) {
        ef = m->eltos [nef];

        // Indices de los nodos.

        for (int k=0; k<ef->nodos.size(); k++) {
            indices [k] = ef->nodos[k]->id;
        }
		belt = Vector2d::Zero ();

		for (int i=0; i<g->n; i++){
	                       
	        nod1 = ef->nodos[0];             // Nodos del elemento 
	        nod2 = ef->nodos[1];
	
	
	        hatp (0) = 0.5 * (1.0 - g->x[i]);
	        hatp (1) = 0.5 * (1.0 + g->x[i]);
	
	       c2 = g->x[i] - nod1->x;         // Pesos para interpolación.
	       c1 = nod2->x - g->x[i];
	       vcar = (c1 * v [nod1->id] + c2 * v [nod2->id]) / ef->h;    // Interpolación.
	
	       hatp (0) = 0.5 * (1.0 - g->x[i]);
	       hatp (1) = 0.5 * (1.0 + g->x[i]);
	
	       belt(0) += g->peso[i] * vcar * hatp (0);
	       belt(1) += g->peso[i] * vcar * hatp (1);
	    }
	    belt = ef->jac * belt; 
       
        // Vector elemental y ensamblado.

        
        ensvec (indices, belt, b);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

