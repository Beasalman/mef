#include "interpola01.h"

/* --------------------------------------------------------------------------- */

void interpola01 (cmalla2d01 *m, VectorXd u, cmalla1d01 *p, VectorXd &w) {

    /* Interpolación de un vector definido sobre una malla 1D a un vector definido sobre una malla 2D.

    Entradas:
    - m: (puntero a) malla.
    - u: vector sobre la malla anterior.
    - p: (puntero a) malla.

    Salida:
    - w: 
    */

    double x, h0, h1, h;
//    cnodo1d *nod, *nodp0, *nodp1;
    cnodo2d *nod;
//    cnodo2d *nodp0, *nodp1;
    map <double, vector <int> > aux;
    set <double> keys;
    set <double> iterator :: it;

    /* ----------------------------------------------------------------------- */
    // Diccionario inverso: abscisas --> nodos.

    for (int i=0; i<m->nsom; i++) {
        nod = m->nodos [i];
        if (keys.find (nod->x) != keys.end()) {
            aux [nod->x].push_back (i);
        } else {
            aux [nod->x] = {i};
            keys.insert (nod->x);
        }
    }

    /* ----------------------------------------------------------------------- */
    // Recorremos las abscisas almacenadas en KEYS.

    int jold = 1;
    for (it=keys.begin(); it!=keys.end(); it++) {
        x = *it;
        for (int j=jold; j<p->nsom; j++) {
            nodj0 = p->nodos [j-1];
            nodj1 = p->nodos [j];
            if (nodj0->x <= x && x <= nodj1->x) {
                h0 = nod->x - nodj0->x;
                h1 = nodj1->x - nod->x;
                h = h0 + h1;
                z = (h1 * u (nodj0->id) + h0 * u (nodj1->id)) / h;
                jold = j;                                    // o j-1?
                break;
            }
        }

    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

