#include <iostream>
using std::cout;
#include <vector>

#include "meshgen01b.h"

/* --------------------------------------------------------------------------- */

void meshgen01b (cmalla2d01 *m, cnodo2d a, cnodo2d b, 
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
    // Datos de la ranura.  Deberían entrar como argumentos.

    cnodo2d p = cnodo2d (0, 0.35, 0.5);
    cnodo2d q = cnodo2d (0, 0.65, 0.5);

    /* ----------------------------------------------------------------------- */

    m->nsom = 8;
    m->nelt = 8;
    m->naristas = 15;

    cnodo2d *newnode;
    celem2d *newelt;
    carista *newside;
    cfrontera2d *newfr;

    /* ----------------------------------------------------------------------- */
    // Nodos.

    // **************************************************************************************************
    //cout << " [MESHGEN01]      Nodo A: " << "     x: " << a.x << "     y: " << a.y << endl;
    //cout << " [MESHGEN01]      Nodo B: " << "     x: " << b.x << "     y: " << b.y << endl;
    // **************************************************************************************************
    
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
    
    newnode = new cnodo2d (4, p.x, p.y, 1.0);
    gnodos[4] = newnode;
    m->nodos[4] = newnode;
    
    newnode = new cnodo2d (5, q.x, q.y, 1.0);
    gnodos[5] = newnode;
    m->nodos[5] = newnode;
    
    newnode = new cnodo2d (6, 0.5*(a.x+b.x), a.y);
    gnodos[6] = newnode;
    m->nodos[6] = newnode;
    
    newnode = new cnodo2d (7, 0.5*(a.x+b.x), b.y);
    gnodos[7] = newnode;
    m->nodos[7] = newnode;
    
    /* ----------------------------------------------------------------------- */
    // Aristas.

    newside = new carista (0, m->nodos[0], m->nodos[6]);
    garistas[0] = newside;
    m->aristas[0] = newside;

    newside = new carista (1, m->nodos[6], m->nodos[1]);
    garistas[1] = newside;
    m->aristas[1] = newside;

    newside = new carista (2, m->nodos[2], m->nodos[7]);
    garistas[2] = newside;
    m->aristas[2] = newside;

    newside = new carista (3, m->nodos[7], m->nodos[3]);
    garistas[3] = newside;
    m->aristas[3] = newside;

    newside = new carista (4, m->nodos[4], m->nodos[5]);
    garistas[4] = newside;
    m->aristas[4] = newside;

    newside = new carista (5, m->nodos[0], m->nodos[2]);
    garistas[5] = newside;
    m->aristas[5] = newside;

    newside = new carista (6, m->nodos[1], m->nodos[3]);
    garistas[6] = newside;
    m->aristas[6] = newside;

    newside = new carista (7, m->nodos[2], m->nodos[4]);
    garistas[7] = newside;
    m->aristas[7] = newside;

    newside = new carista (8, m->nodos[4], m->nodos[7]);
    garistas[8] = newside;
    m->aristas[8] = newside;

    newside = new carista (9, m->nodos[7], m->nodos[5]);
    garistas[9] = newside;
    m->aristas[9] = newside;

    newside = new carista (10, m->nodos[5], m->nodos[3]);
    garistas[10] = newside;
    m->aristas[10] = newside;

    newside = new carista (11, m->nodos[0], m->nodos[4]);
    garistas[11] = newside;
    m->aristas[11] = newside;

    newside = new carista (12, m->nodos[4], m->nodos[6]);
    garistas[12] = newside;
    m->aristas[12] = newside;

    newside = new carista (13, m->nodos[6], m->nodos[5]);
    garistas[13] = newside;
    m->aristas[13] = newside;

    newside = new carista (14, m->nodos[5], m->nodos[1]);
    garistas[14] = newside;
    m->aristas[14] = newside;

    /* ----------------------------------------------------------------------- */
    // Elementos.

    newelt = new celem2d (0, m->nodos[4], m->nodos[0], m->nodos[6], m->aristas[0], m->aristas[12], m->aristas[11]);
    geltos[0] = newelt;
    m->eltos[0] = newelt;

    newelt = new celem2d (1, m->nodos[6], m->nodos[5], m->nodos[4], m->aristas[4], m->aristas[12], m->aristas[13]);
    geltos[1] = newelt;
    m->eltos[1] = newelt;

    newelt = new celem2d (2, m->nodos[5], m->nodos[6], m->nodos[1], m->aristas[1], m->aristas[14], m->aristas[13]);
    geltos[2] = newelt;
    m->eltos[2] = newelt;

    newelt = new celem2d (3, m->nodos[5], m->nodos[1], m->nodos[3], m->aristas[6], m->aristas[10], m->aristas[14]);
    geltos[3] = newelt;
    m->eltos[3] = newelt;

    newelt = new celem2d (4, m->nodos[5], m->nodos[3], m->nodos[7], m->aristas[3], m->aristas[9], m->aristas[10]);
    geltos[4] = newelt;
    m->eltos[4] = newelt;

    newelt = new celem2d (5, m->nodos[7], m->nodos[4], m->nodos[5], m->aristas[4], m->aristas[9], m->aristas[8]);
    geltos[5] = newelt;
    m->eltos[5] = newelt;

    newelt = new celem2d (6, m->nodos[4], m->nodos[7], m->nodos[2], m->aristas[2], m->aristas[7], m->aristas[8]);
    geltos[6] = newelt;
    m->eltos[6] = newelt;

    newelt = new celem2d (7, m->nodos[4], m->nodos[2], m->nodos[0], m->aristas[5], m->aristas[11], m->aristas[7]);
    geltos[7] = newelt;
    m->eltos[7] = newelt;

    // Renumeración local.

    for (int i=0; i<m->nelt; i++) {
        m->eltos[i]->sort ();
    }

    /* ----------------------------------------------------------------------- */
    // Fronteras.

    newfr = new cfrontera2d (0);
    newfr->nodos.push_back (m->nodos[0]);
    newfr->nodos.push_back (m->nodos[6]);
    newfr->nodos.push_back (m->nodos[1]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (1);
    newfr->nodos.push_back (m->nodos[1]);
    newfr->nodos.push_back (m->nodos[3]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (2);
    newfr->nodos.push_back (m->nodos[2]);
    newfr->nodos.push_back (m->nodos[7]);
    newfr->nodos.push_back (m->nodos[3]);
    m->fronteras.push_back(newfr);

    newfr = new cfrontera2d (3);
    newfr->nodos.push_back (m->nodos[0]);
    newfr->nodos.push_back (m->nodos[2]);
    m->fronteras.push_back(newfr);

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

