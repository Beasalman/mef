#include "reft100.h"

/* --------------------------------------------------------------------------- */

void reft100 (cmalla2d01 *m, map <int, celem2d *> &geltos, map <int, carista *> &garistas, 
              int i, int j, int k) {

    /* Refinamiento de un triángulo en dos subtriángulos.
          - creación de los hijos de cada elemento
          - creación de nuevas aristas.

    Entradas:
    - m:        (puntero a) malla.
    - geltos:   diccionario de todos los elementos.
    - garistas: diccionario de todas las aristas.
    - j:        índice del siguiente elemento a crear.
    */

    /* ----------------------------------------------------------------------- */

    cnodo2d *n0, *n1, *n2, *m0;
    celem2d *ef;
    celem2d *newelt;
    carista *q0, *r1, *r2, *a0, *a1, *a2;

    /* ----------------------------------------------------------------------- */
    // Elemento original.

    ef = geltos [i];
    ef->nhijos = 2;
    ef->tiporef = 2;

    n0 = ef->nodos[0];
    n1 = ef->nodos[1];
    n2 = ef->nodos[2];

    a0 = ef->aristas[0];
    a1 = ef->aristas[1];
    a2 = ef->aristas[2];

    m0 = a0->nodohijo;

    /* ----------------------------------------------------------------------- */
    // Aristas hijas de la arista A0.

    r1 = m->nodart [std::make_pair (n1->id, m0->id)];
    try {
        r2 = m->nodart [std::make_pair (m0->id, n2->id)];
    } catch (int e) {
        r2 = m->nodart [std::make_pair (n2->id, m0->id)];
    }
    
    // Nueva arista.

    q0 = new carista (k, m0, n0);
    garistas[k] = q0;
    m->aristas[k] = q0;
    m->naristas += 1;

    /* ----------------------------------------------------------------------- */
    // Elemento hijo 1.

    // **********************************************************************************************
    //cout << " [REFT100] Vamos a subdividir el elemento en dos" << endl;
    //cout << "               ef: " << ef->id; 
    // **********************************************************************************************

    newelt = new celem2d (j);
    newelt->padre = ef;
    ef->hijos.push_back (newelt);
    geltos[j] = newelt;
    m->eltos[j] = newelt;

    newelt->nodos.push_back (m0);
    newelt->nodos.push_back (n0);
    newelt->nodos.push_back (n1);

    newelt->aristas.push_back (a2);
    newelt->aristas.push_back (r1);
    newelt->aristas.push_back (q0);

    // **********************************************************************************************
    //cout << "      newelt: " << ef->id; 
    // **********************************************************************************************

    // Elemento hijo 2.

    newelt = new celem2d (j+1);
    newelt->padre = ef;
    ef->hijos.push_back (newelt);
    geltos[j+1] = newelt;
    m->eltos[j+1] = newelt;

    newelt->nodos.push_back (m0);
    newelt->nodos.push_back (n2);
    newelt->nodos.push_back (n0);

    newelt->aristas.push_back (a1);
    newelt->aristas.push_back (q0);
    newelt->aristas.push_back (r2);

    // **********************************************************************************************
    //cout << "      newelt: " << ef->id << endl; 
    // **********************************************************************************************

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

