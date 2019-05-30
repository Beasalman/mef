#include "meshref01.h"

/* --------------------------------------------------------------------------- */

void meshref01 (cmalla2d01 *m, map <int, cnodo2d *> &gnodos, map <int, celem2d *> &geltos, 
                map <int, carista *> &garistas, int tref, double sigma, cmark *fmark) {

    /* Generación de una malla (2x2) y refinamientos posteriores.

    Entradas:
    - m:        (puntero a) la malla actual.
    - gnodos: 
    - geltos: 
    - garistas: 
    */

    // ----------------------------------------------------------------------- 
//cout << " meshref01   Malla: " << m->id << "      Nodos: " << m->nsom << endl;
    // *****************************************************************************************************************
    //cout << " [MESHREF01]  Elementos de la malla  -  Número: " << m->eltos.size() << "  -  Indices: ";
    //map <int, celem2d*> :: iterator ieltt;
    //for (ieltt=m->eltos.begin(); ieltt!=m->eltos.end(); ieltt++) {
    //    cout << " " << ieltt->second->id;
    //}
    //cout << endl;
    // *****************************************************************************************************************

    (*fmark) (m);                       // Marcado de los elementos que cumplen el criterio.

    remesh02 (m);                       // Marcado de nuevos elementos y aristas, para asegurar la conformidad.

    // *****************************************************************************************************************
    //map <int, carista*> :: iterator iart;
    //carista *art;
    //for (iart=m->aristas.begin(); iart!=m->aristas.end(); iart++) {
    //    art = iart->second;
    //    if (art->frontera != NULL) {
    //        cout << " [MESHREF01]    Arista: " << art->id << "      en la frontera: " << art->frontera->id << endl;
    //    } else {
    //        cout << " [MESHREF01]    Arista: " << art->id << "      en la frontera NULL" << endl;
    //    }
    //}
    // *****************************************************************************************************************

    remesh04 (m,gnodos,garistas);       // Creamos los nuevos nodos en las aristas marcadas
                                        // y las aristas que surgen como subdivisión.

//cout << " meshref04   Malla: " << m->id << "      Nodos: " << m->nsom << endl;
    m->gnodart ();                      // Generación del diccionario NODART ((nodo,nodo) --> arista).

    remesh03 (m,geltos,garistas);       // Creamos los hijos de los elementos marcados
                                        // y las nuevas aristas "interiores".

//cout << " meshref03   Malla: " << m->id << "      Nodos: " << m->nsom << endl;
    map <int, celem2d*> :: iterator ielt;
    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ielt->second->superficie ();
        ielt->second->cdgcompute ();
    }

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

