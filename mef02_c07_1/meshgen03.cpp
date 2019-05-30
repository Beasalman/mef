#include <iostream>
using std::cout;
#include <vector>

#include "meshgen03.h"

/* --------------------------------------------------------------------------- */

void meshgen03 (cmalla2d01 *m, cnodo2d a, cnodo2d b, 
                std::map <int, cnodo2d *> &gnodos,
                std::map <int, celem2d *> &geltos, 
                std::map <int, carista *> &garistas) {

    /* Generación de una malla de un dominio con forma de L.

    Entradas:
    - m:  malla (puntero a ...).
    - a:  vértice inferior izquierdo (clase NODO).
    - b:  vértice superior derecho (clase NODO).
    - 
    - 
    - 
    -
    */

    /* ----------------------------------------------------------------------- */

    m->nsom = 12;
    m->nelt = 10;
    m->naristas = 21;
    m->nfr = 7;

    cnodo2d *newnode;
    celem2d *newelt;
    carista *newside;
    cfrontera2d *newfr;

    /* ----------------------------------------------------------------------- */
    // Nodos.

    double c1 = 1.0 / 3.0;
    double c2 = 2.0 / 3.0;

    newnode = new cnodo2d (0, a.x, b.y);        // Creo un puntero al nuevo nodo.
    gnodos[0] = newnode;                      // Almaceno el puntero.
    m->nodos[0] = newnode;                    // Almaceno el puntero.

    newnode = new cnodo2d (1, c2*a.x+c1*b.x, b.y);
    gnodos[1] = newnode;
    m->nodos[1] = newnode;

    newnode = new cnodo2d (2, c1*a.x+c2*b.x, b.y);
    gnodos[2] = newnode;
    m->nodos[2] = newnode;

    newnode = new cnodo2d (3, b.x, b.y);
    gnodos[3] = newnode;
    m->nodos[3] = newnode;
    
    newnode = new cnodo2d (4, a.x, 0.5*(a.y+b.y));
    gnodos[4] = newnode;
    m->nodos[4] = newnode;
    
    newnode = new cnodo2d (5, c2*a.x+c1*b.x, 0.5*(a.y+b.y), 1.0);
    gnodos[5] = newnode;
    m->nodos[5] = newnode;
    
    newnode = new cnodo2d (6, c1*a.x+c2*b.x, 0.5*(a.y+b.y), 1.0);
    gnodos[6] = newnode;
    m->nodos[6] = newnode;
    
    newnode = new cnodo2d (7, b.x, 0.5*(a.y+b.y));
    gnodos[7] = newnode;
    m->nodos[7] = newnode;
    
    newnode = new cnodo2d (8, a.x, a.y);
    gnodos[8] = newnode;
    m->nodos[8] = newnode;
    
    newnode = new cnodo2d (9, c2*a.x+c1*b.x, a.y);
    gnodos[9] = newnode;
    m->nodos[9] = newnode;
    
    newnode = new cnodo2d (10, c1*a.x+c2*b.x, a.y);
    gnodos[10] = newnode;
    m->nodos[10] = newnode;
    
    newnode = new cnodo2d (11, b.x, a.y);
    gnodos[11] = newnode;
    m->nodos[11] = newnode;
    
    /* ----------------------------------------------------------------------- */
    // Aristas.

    newside = new carista (0, m->nodos[0], m->nodos[1]);
    newside->tipo = 0;
    garistas[0] = newside;
    m->aristas[0] = newside;

    newside = new carista (1, m->nodos[2], m->nodos[1]);
    newside->tipo = 0;
    garistas[1] = newside;
    m->aristas[1] = newside;

    newside = new carista (2, m->nodos[2], m->nodos[3]);
    newside->tipo = 0;
    garistas[2] = newside;
    m->aristas[2] = newside;

    newside = new carista (3, m->nodos[4], m->nodos[5]);
    garistas[3] = newside;
    m->aristas[3] = newside;

    newside = new carista (4, m->nodos[5], m->nodos[6]);
    newside->tipo = 0;
    garistas[4] = newside;
    m->aristas[4] = newside;

    newside = new carista (5, m->nodos[6], m->nodos[7]);
    garistas[5] = newside;
    m->aristas[5] = newside;

    newside = new carista (6, m->nodos[8], m->nodos[9]);
    newside->tipo = 0;
    garistas[6] = newside;
    m->aristas[6] = newside;

    newside = new carista (7, m->nodos[10], m->nodos[11]);
    newside->tipo = 0;
    garistas[7] = newside;
    m->aristas[7] = newside;

    newside = new carista (8, m->nodos[0], m->nodos[4]);
    newside->tipo = 0;
    garistas[8] = newside;
    m->aristas[8] = newside;

    newside = new carista (9, m->nodos[1], m->nodos[4]);
    garistas[9] = newside;
    m->aristas[9] = newside;

    newside = new carista (10, m->nodos[1], m->nodos[5]);
    garistas[10] = newside;
    m->aristas[10] = newside;

    newside = new carista (11, m->nodos[1], m->nodos[6]);
    garistas[11] = newside;
    m->aristas[11] = newside;

    newside = new carista (12, m->nodos[2], m->nodos[6]);
    garistas[12] = newside;
    m->aristas[12] = newside;

    newside = new carista (13, m->nodos[6], m->nodos[3]);
    garistas[13] = newside;
    m->aristas[13] = newside;

    newside = new carista (14, m->nodos[3], m->nodos[7]);
    newside->tipo = 0;
    garistas[14] = newside;
    m->aristas[14] = newside;

    newside = new carista (15, m->nodos[4], m->nodos[8]);
    newside->tipo = 0;
    garistas[15] = newside;
    m->aristas[15] = newside;

    newside = new carista (16, m->nodos[4], m->nodos[9]);
    garistas[16] = newside;
    m->aristas[16] = newside;

    newside = new carista (17, m->nodos[5], m->nodos[9]);
    newside->tipo = 0;
    garistas[17] = newside;
    m->aristas[17] = newside;

    newside = new carista (18, m->nodos[6], m->nodos[10]);
    newside->tipo = 0;
    garistas[18] = newside;
    m->aristas[18] = newside;

    newside = new carista (19, m->nodos[6], m->nodos[11]);
    garistas[19] = newside;
    m->aristas[19] = newside;

    newside = new carista (20, m->nodos[7], m->nodos[11]);
    newside->tipo = 0;
    garistas[20] = newside;
    m->aristas[20] = newside;

    /* ----------------------------------------------------------------------- */
    // Elementos.

    newelt = new celem2d (0, m->nodos[8], m->nodos[9], m->nodos[4], m->aristas[16], m->aristas[15], m->aristas[6]);
    geltos[0] = newelt;
    m->eltos[0] = newelt;

    newelt = new celem2d (1, m->nodos[5], m->nodos[4], m->nodos[9], m->aristas[16], m->aristas[17], m->aristas[3]);
    geltos[1] = newelt;
    m->eltos[1] = newelt;

    newelt = new celem2d (2, m->nodos[5], m->nodos[1], m->nodos[4], m->aristas[9], m->aristas[3], m->aristas[10]);
    geltos[2] = newelt;
    m->eltos[2] = newelt;

    newelt = new celem2d (3, m->nodos[0], m->nodos[4], m->nodos[1], m->aristas[9], m->aristas[0], m->aristas[8]);
    geltos[3] = newelt;
    m->eltos[3] = newelt;

    newelt = new celem2d (4, m->nodos[5], m->nodos[6], m->nodos[1], m->aristas[11], m->aristas[10], m->aristas[4]);
    geltos[4] = newelt;
    m->eltos[4] = newelt;

    newelt = new celem2d (5, m->nodos[2], m->nodos[1], m->nodos[6], m->aristas[11], m->aristas[12], m->aristas[1]);
    geltos[5] = newelt;
    m->eltos[5] = newelt;

    newelt = new celem2d (6, m->nodos[2], m->nodos[6], m->nodos[3], m->aristas[13], m->aristas[2], m->aristas[12]);
    geltos[6] = newelt;
    m->eltos[6] = newelt;

    newelt = new celem2d (7, m->nodos[7], m->nodos[3], m->nodos[6], m->aristas[13], m->aristas[5], m->aristas[14]);
    geltos[7] = newelt;
    m->eltos[7] = newelt;

    newelt = new celem2d (8, m->nodos[7], m->nodos[6], m->nodos[11], m->aristas[19], m->aristas[20], m->aristas[5]);
    geltos[8] = newelt;
    m->eltos[8] = newelt;

    newelt = new celem2d (9, m->nodos[10], m->nodos[11], m->nodos[6], m->aristas[19], m->aristas[18], m->aristas[7]);
    geltos[9] = newelt;
    m->eltos[9] = newelt;

    // Renumeración local.

    for (int i=0; i<m->nelt; i++) {
        m->eltos[i]->sort ();
    }

    /* ----------------------------------------------------------------------- */
    // Fronteras.

    newfr = new cfrontera2d (0);
    newfr->nodos.push_back (m->nodos[0]);
    newfr->nodos.push_back (m->nodos[1]);
    newfr->nodos.push_back (m->nodos[2]);
    newfr->nodos.push_back (m->nodos[3]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (1);
    newfr->nodos.push_back (m->nodos[3]);
    newfr->nodos.push_back (m->nodos[7]);
    newfr->nodos.push_back (m->nodos[11]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (2);
    newfr->nodos.push_back (m->nodos[11]);
    newfr->nodos.push_back (m->nodos[10]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (3);
    newfr->nodos.push_back (m->nodos[10]);
    newfr->nodos.push_back (m->nodos[6]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (4);
    newfr->nodos.push_back (m->nodos[6]);
    newfr->nodos.push_back (m->nodos[5]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (5);
    newfr->nodos.push_back (m->nodos[5]);
    newfr->nodos.push_back (m->nodos[9]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (6);
    newfr->nodos.push_back (m->nodos[9]);
    newfr->nodos.push_back (m->nodos[8]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (7);
    newfr->nodos.push_back (m->nodos[8]);
    newfr->nodos.push_back (m->nodos[4]);
    newfr->nodos.push_back (m->nodos[0]);
    m->fronteras.push_back(newfr);

    m->aristas[0]->frontera = m->fronteras[0];
    m->aristas[1]->frontera = m->fronteras[0];
    m->aristas[2]->frontera = m->fronteras[0];
    m->aristas[4]->frontera = m->fronteras[4];
    m->aristas[6]->frontera = m->fronteras[6];
    m->aristas[7]->frontera = m->fronteras[2];
    m->aristas[8]->frontera = m->fronteras[7];
    m->aristas[14]->frontera = m->fronteras[1];
    m->aristas[15]->frontera = m->fronteras[7];
    m->aristas[17]->frontera = m->fronteras[5];
    m->aristas[18]->frontera = m->fronteras[3];
    m->aristas[20]->frontera = m->fronteras[1];

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

