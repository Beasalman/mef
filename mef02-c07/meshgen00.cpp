#include <iostream>
using std::cout;
#include <vector>

#include "meshgen00.h"

/* --------------------------------------------------------------------------- */

void meshgen00 (cmalla2d01 *m, cnodo2d a, cnodo2d b, 
                std::map <int, cnodo2d *> &gnodos,
                std::map <int, celem2d *> &geltos, 
                std::map <int, carista *> &garistas) {

    /* Generación de una malla (2x2).

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

    m->nsom = 4;
    m->nelt = 2;
    m->naristas = 5;

    cnodo2d *newnode;
    celem2d *newelt;
    carista *newside;
    cfrontera2d *newfr;

    /* ----------------------------------------------------------------------- */
    // Nodos.

    m->nsom = 4;
    newnode = new cnodo2d (0, a.x, a.y);        // Creo un puntero al nuevo nodo.
    gnodos[0] = newnode;                      // Almaceno el puntero.
    m->nodos[0] = newnode;                    // Almaceno el puntero.

    newnode = new cnodo2d (1, b.x, a.y);
    gnodos[1] = newnode;
    m->nodos[1] = newnode;

    newnode = new cnodo2d (2, a.x, b.y);
    gnodos[2] = newnode;
    m->nodos[2] = newnode;

    newnode = new cnodo2d (3, b.x, b.y);
    gnodos[3] = newnode;
    m->nodos[3] = newnode;
    
    /* ----------------------------------------------------------------------- */
    // Aristas.

    m->naristas = 5;
    newside = new carista (0, m->nodos[0], m->nodos[1]);
    newside->tipo = 0;
    garistas[0] = newside;
    m->aristas[0] = newside;

    newside = new carista (1, m->nodos[1], m->nodos[3]);
    newside->tipo = 0;
    garistas[1] = newside;
    m->aristas[1] = newside;

    newside = new carista (2, m->nodos[2], m->nodos[3]);
    newside->tipo = 0;
    garistas[2] = newside;
    m->aristas[2] = newside;

    newside = new carista (3, m->nodos[0], m->nodos[2]);
    newside->tipo = 0;
    garistas[3] = newside;
    m->aristas[3] = newside;

    newside = new carista (4, m->nodos[0], m->nodos[3]);
    garistas[4] = newside;
    m->aristas[4] = newside;
/*cout << " mark " << m->aristas[0]->mark << "\n";
cout << " mark " << m->aristas[1]->mark << "\n";
cout << " mark " << m->aristas[2]->mark << "\n";
cout << " mark " << m->aristas[3]->mark << "\n";
cout << " mark " << m->aristas[4]->mark << "\n";*/
    /* ----------------------------------------------------------------------- */
    // Elementos.

    m->nelt = 2;
    newelt = new celem2d (0, m->nodos[2], m->nodos[0], m->nodos[3], m->aristas[4], m->aristas[2], m->aristas[3]);
    geltos[0] = newelt;
    m->eltos[0] = newelt;

    newelt = new celem2d (1, m->nodos[1], m->nodos[3], m->nodos[0], m->aristas[4], m->aristas[0], m->aristas[1]);
    geltos[1] = newelt;
    m->eltos[1] = newelt;

//    m->eltos[0]->vecinos[0] = m->eltos[1];
//    m->eltos[0]->vecinos[1] = NULL;
//    m->eltos[0]->vecinos[2] = NULL;
//
//    m->eltos[1]->vecinos[0] = m->eltos[0];
//    m->eltos[1]->vecinos[1] = NULL;
//    m->eltos[1]->vecinos[2] = NULL;

    /* ----------------------------------------------------------------------- */
    // Fronteras.

    newfr = new cfrontera2d (0);
    newfr->nodos.push_back (m->nodos[0]);
    newfr->nodos.push_back (m->nodos[1]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (1);
    newfr->nodos.push_back (m->nodos[1]);
    newfr->nodos.push_back (m->nodos[3]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (2);
    newfr->nodos.push_back (m->nodos[2]);
    newfr->nodos.push_back (m->nodos[3]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (3);
    newfr->nodos.push_back (m->nodos[0]);
    newfr->nodos.push_back (m->nodos[2]);
    m->fronteras.push_back(newfr);

    m->aristas[0]->frontera = m->fronteras[0];
    m->aristas[1]->frontera = m->fronteras[1];
    m->aristas[2]->frontera = m->fronteras[2];
    m->aristas[3]->frontera = m->fronteras[3];

    /* ----------------------------------------------------------------------- */
    // Nodos vecinos en los cuatro puntos cardinales.

    //m->nodos[0]->east = m->nodos[1];
    //m->nodos[0]->north = m->nodos[2];

    //m->nodos[1]->west = m->nodos[0];
    //m->nodos[1]->north = m->nodos[3];

    //m->nodos[2]->east = m->nodos[3];
    //m->nodos[2]->south = m->nodos[0];

    //m->nodos[3]->west = m->nodos[2];
    //m->nodos[3]->south = m->nodos[1];

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

