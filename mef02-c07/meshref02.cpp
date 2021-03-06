#include "meshref02.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void meshref02 (vector <cmalla2d01 *> &mallas, int &level, cgauss02 *g, cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
                map <int, celem2d *> &geltos, map <int, cnodo2d *> &gnodos, map <int, carista *> &garistas, cmark *fmark,
                VectorXd &uold, VectorXd &u, SparseMatrix <double, ColMajor> &a, cconvection2d *velocity01, cconvection2d *velocity02, 
                cdiffusion2d *diff) {

    /* MESHREF02: Refinamiento de mallado y prolongación de variables.
 
    Entradas:
    */

    cnodo2d *nod, *nodb, *nodc;
    celem2d *ef, *efc;
    cfrontera2d *fr;
    map <int, celem2d*> :: iterator ielt;
    Vector2d y, z;

    // -----------------------------------------------------------------------------------------
    // Última malla y nueva malla (copia).

    cmalla2d01 *m = mallas.back ();
    cmalla2d01 *pz = new cmalla2d01 (*m);            // Copia de la malla anterior en una nueva.
    meshref01 (pz, gnodos, geltos, garistas, dmesh.tref1, dmesh.sigma, fmark);       // Refinamiento.
    pz->domain = new cdomain2d (&dmesh.vii, &dmesh.vsd);
    pz->id = m->id + 1;
    mallas.push_back (pz);
    pz->fprint01 (pz->id);

    // Redimensionamiento de vectores.

    //uold.resize (pz->nsom);

    // Prolongación.

    VectorXd uaux (pz->nsom);
    prolong (m, u, pz, uaux);
    u.resize (pz->nsom);
    util02 (uaux, u);

    prolong (m, uold, pz, uaux);
    uold.resize (pz->nsom);
    util02 (uaux, uold);

    // Última malla.

    m->id = level + 1;
    level = m->id;

    // -------------------------------------------------------------------------
    // Cálculo de las nuevas curvas características.

    for (ielt=pz->eltos.begin(); ielt!=pz->eltos.end(); ielt++) {
        ef = ielt->second;
        ef->eltosdesplazados.clear ();
        ef->nodosdesplazados.clear ();
        for (int i=0; i<g->n; i++) {
            y (0) = g->x [i];
            y (1) = g->y [i];
            z = ef->ck * y + ef->dk;
            nodc = new cnodo2d (-1, 0., 0.);
            nodc = carac02 (z, dnum.caracdeltat, 10, velocity01, m);

            efc = localiza01 (mallas, level, nodc);
            ef->eltosdesplazados.push_back (efc);

            nodb = new cnodo2d (-1, 0., 0.);
            baric01 (efc, nodc, nodb);
            ef->nodosdesplazados.push_back (nodb);
        }
    }

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados de la frontera 1. Almacenamos sus coordenadas baricéntricas.

    fr = pz->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        z (0) = nod->x;
        z (1) = nod->y;
        nodc = new cnodo2d (-1, 0., 0.);
        nodc = carac02 (z, dnum.caracdeltat, 10, velocity02, m);
    
        efc = localiza01 (mallas, level, nodc);
        nod->eltodesplazado = efc;
    
        nodb = new cnodo2d (-1, 0., 0.);
        baric01 (efc, nodc, nodb);
        nod->nododesplazado = nodb;
    }

    // Actualización de la matriz del sistema.

    a.resize (pz->nsom, pz->nsom);
    globalmat13 (pz, g, dnum.caracdeltat, dprob.r, diff, a);
    dirichlet22 (pz, a);
    a.makeCompressed ();
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

