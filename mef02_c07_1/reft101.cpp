#include "reft101.h"

/* --------------------------------------------------------------------------- */

void reft101 (cmalla2d01 *m, map <int, celem2d *> &geltos, map <int, carista *> &garistas,
              int i, int j, int k) {

    /* Refinamiento de un triángulo en tres subtriángulos (caso 101).
          - creación de los hijos de cada elemento
          - creación de nuevas aristas.

    Entradas:
    - m:        (puntero a) malla.
    - geltos:   diccionario de todos los elementos.
    - garistas: diccionario de todas las aristas.

    */

    /* ----------------------------------------------------------------------- */

    cnodo2d *n0, *n1, *n2, *m0, *m2;
    celem2d *ef;
    celem2d *newelt;
    carista *a0, *a1, *a2, *q0, *q2, *r1, *r2, *r3, *r4;

    /* ----------------------------------------------------------------------- */
    // Elemento original.

    ef = geltos [i];
    ef->nhijos = 3;
    ef->tiporef = 32;

    n0 = ef->nodos[0];
    n1 = ef->nodos[1];
    n2 = ef->nodos[2];

    a0 = ef->aristas[0];
    a1 = ef->aristas[1];
    a2 = ef->aristas[2];

    m0 = a0->nodohijo;
    m2 = a2->nodohijo;

    /* ----------------------------------------------------------------------- */
    // Aristas hijas.

    r1 = m->nodart [std::make_pair (n1->id, m0->id)];
    r2 = m->nodart [std::make_pair (n2->id, m0->id)];
    r3 = m->nodart [std::make_pair (n0->id, m2->id)];
    r4 = m->nodart [std::make_pair (n1->id, m2->id)];

    // Nuevas aristas.

    q0 = new carista (k, m0, n0);
    garistas[k] = q0;
    m->aristas[k] = q0;

    q2 = new carista (k+1, m0, m2);
    garistas[k+1] = q2;
    m->aristas[k+1] = q2;

    m->naristas += 2;        // Creo que no es necesario. En todo caso, hay que ver si está bien sumado.

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
    newelt->nodos.push_back (m2);
    newelt->nodos.push_back (n1);
    newelt->nodos.push_back (m0);

    newelt->aristas.push_back (r1);
    newelt->aristas.push_back (q2);
    newelt->aristas.push_back (r4);

    /* ----------------------------------------------------------------------- */
    // Elemento hijo 2.

    newelt = new celem2d (j+1);
    newelt->padre = ef;
    ef->hijos.push_back (newelt);
    geltos[j+1] = newelt;
    m->eltos[j+1] = newelt;
    newelt->nodos.push_back (m2);
    newelt->nodos.push_back (m0);
    newelt->nodos.push_back (n0);

    newelt->aristas.push_back (q0);
    newelt->aristas.push_back (r3);
    newelt->aristas.push_back (q2);

    /* ----------------------------------------------------------------------- */
    // Elemento hijo 3.

    newelt = new celem2d (j+2);
    newelt->padre = ef;
    ef->hijos.push_back (newelt);
    geltos[j+2] = newelt;
    m->eltos[j+2] = newelt;
    newelt->nodos.push_back (m0);
    newelt->nodos.push_back (n2);
    newelt->nodos.push_back (n0);

    newelt->aristas.push_back (a1);
    newelt->aristas.push_back (q0);
    newelt->aristas.push_back (r2);

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

