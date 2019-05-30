#include "elvec1d2gdl02.h"

/* ----------------------------------------------------------------------------------------- */

void elvec1d2gdl02 (celem1d *ef, cgauss1d *g, vector <double> cpoint, 
                    vector <celem1d *> celt, VectorXd uold, Vector2d &b) {

    /* ELVEC1D2GDL02: Vector elemental correspondiente al término de características.
     
       Entradas:
       - ef:         elemento actual.
       - g:          nodos y pesos de integración.
       - caracpoint: punto desplazado sobre la característica.
       - caracelt:   elemento al que pertenece el punto desplazado.
	
       Salidas:
       - b: vector elemental.
    */
    
    Vector2d hatp;
    celem1d *efi;
    cnodo1d *nod1, *nod2;
    double c1, c2, ucar;
    
    for (int i=0; i<g->n; i++){
        efi = celt [i];                   // Elemento al que pertenece el punto desplazado.
        nod1 = efi->nodos[0];             // Nodos del elemento anterior.
        nod2 = efi->nodos[1];

        c2 = cpoint[i] - nod1->x;         // Pesos para interpolación.
        c1 = nod2->x - cpoint[i];
        ucar = (c1 * uold [nod1->id] + c2 * uold [nod2->id]) / efi->h;    // Interpolación.

        hatp (0) = 0.5 * (1.0 - g->x[i]);
        hatp (1) = 0.5 * (1.0 + g->x[i]);

        b(0) += g->peso[i] * ucar * hatp (0);
        b(1) += g->peso[i] * ucar * hatp (1);
    }
    b = ef->jac * b; 
}

/* ----------------------------------------------------------------------------------------- */

