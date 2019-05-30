#include "meshgen2d1d.h"

// ---------------------------------------------------------------------------

cmalla1d *meshgen2d1d (cmalla2d01 *m) {

    /* Generación de una malla 1d a partir de otra 2d.

    Entrada:
    - m: (puntero a) malla 2D.

    Salida:
    - p: (puntero a) malla 1D.
    */

    set <double> s;
    vector <double> v0;
    vector <cnodo1d *> v1;

    // -----------------------------------------------------------------------
    // Extracción de las coordenadas de los nodos.
	
    for (int i=0; i<m->nsom; i++) {
        s.insert (m->nodos[i]->x);
     }
    v0.assign (s.begin (), s.end ());

    for (int i=0; i<v0.size(); i++) {
        v1.push_back (new cnodo1d (i, v0[i]));
    }

    // -----------------------------------------------------------------------
    // Construcción de la malla 1D.

    int ns = v1.size ();
    int ne = ns - 1;
    cmalla1d *p = new cmalla1d (0, ns, ne, v0);

    for (int i=0; i<ne; i++) {
        p->eltos.push_back (new celem1d (i, v1[i], v1[i+1]));
    }
    
    p->fronteras.push_back (new cfrontera1d (0, v1[0]));
    p->fronteras.push_back (new cfrontera1d (1, v1[ns-1]));

    // -----------------------------------------------------------------------
    // Cálculo del jacobiano de cada elemento.

    for (int i=0; i<ne; i++) {
        p->eltos[i]->jacobiano ();
    }

    return p;
}

// -----------------------------------------------------------------------------------------

