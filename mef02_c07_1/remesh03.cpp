#include "remesh03.h"

/* --------------------------------------------------------------------------- */

void remesh03 (cmalla2d01 *m, map <int, celem2d *> &geltos, map <int, carista *> &garistas) {

    /* Refinamiento de mallado: 
          - creación de los hijos de cada elemento
          - creación de nuevas aristas.

    Entradas:
    - m:        (puntero a) malla.
    - geltos:   diccionario de todos los elementos.
    - garistas: diccionario de todas las aristas.
    */

    /* ----------------------------------------------------------------------- */

    int i, j, k;
    celem2d *ef;
    celem2d *newelt;
    carista *art;
    carista *newart;
    map <int, carista *> :: iterator ia;
    map <int, celem2d *> :: iterator ie;
//    map <int, celem2d *> :: iterator ielt;
    vector <int> eltind;

    /* ----------------------------------------------------------------------- */
    // Índices de los elementos en este momento.

    j = 0;
    for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
        ef = ie->second;
        eltind.push_back (ef->id);
        j = max (ef->id, j);
    }
    j += 1;          // Indice del siguiente elemento a añadir.

    // Índices de las aristas en este momento.

    k = 0;
    for (ia=m->aristas.begin(); ia!=m->aristas.end(); ia++) {
        art = ia->second;
        k = max (art->id, k);
    }
    k += 1;          // Indice de la siguiente arista a añadir.

    /* ----------------------------------------------------------------------- */

    for (int ii=0; ii<eltind.size(); ii++) {
        ef = m->eltos[eltind[ii]];
        i = ef->id;

        if (ef->mark > 0) {

            // División en 2 subtriángulos.

            if (ef->aristas[1]->mark == 0 && ef->aristas[2]->mark == 0) {
	//std::cout <<  " 2 subtriangulos \n";
                reft100 (m, geltos, garistas, i, j, k);
                j += 2;
                k += 1;
                m->nelt += 2;
            }

            // División en 4 subtriángulos.

            else if (ef->aristas[1]->mark == 1 && ef->aristas[2]->mark == 1) {

	//std::cout <<  " 4 subtriangulos \n";
                reft111 (m, geltos, garistas, i, j, k);
                j += 4;
                k += 3;
                m->nelt += 4;
            }

            // División en 3 subtriángulos.

            else if (ef->aristas[1]->mark == 1 && ef->aristas[2]->mark == 0) {

                reft110 (m, geltos, garistas, i, j, k);
                j += 3;
                k += 2;
                m->nelt += 3;
            }

            // División en 3 subtriángulos.

            else if (ef->aristas[1]->mark == 0 && ef->aristas[2]->mark == 1) {
                reft101 (m, geltos, garistas, i, j, k);
                j += 3;
                k += 2;
                m->nelt += 3;
            }

            // Borramos el elemento refinado.

            m->eltos.erase (i);
            m->nelt -= 1;

        } else {                            // Si el elemento no se subdivide, le asignamos como único hijo a él mismo.
            ef->hijos.push_back (ef);
        }
    }

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

