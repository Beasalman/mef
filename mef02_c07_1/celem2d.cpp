#include "celem2d.h"

/* --------------------------------------------------------------------------- */

celem2d::celem2d () {

    id = -1000;

    mark = 0;
    tiporef = 0;
    nhijos = 0;

//    ck.resize (2,2);
//    dk.resize (2,1);
};

/* -------------------------------------------------------------- */

celem2d::celem2d (int n) {

    id = n;

    mark = 0;
    tiporef = 0;
    nhijos = 0;

//    ck.resize (2,2);
//    dk.resize (2,1);
};

/* -------------------------------------------------------------- */

celem2d::celem2d (int n, cnodo2d *a, cnodo2d *b, cnodo2d *c) {

    id = n;

    // ****************************************************
    //cout << "       Construimos el elemento " << n << endl;
    // ****************************************************

    this->nodos.push_back (a);
    this->nodos.push_back (b);
    this->nodos.push_back (c);

    // ****************************************************
    //cout << "           Hemos añadido los nodos " << endl;
    // ****************************************************

    mark = 0;
    tiporef = 0;
    nhijos = 0;

    // ****************************************************
    //cout << "           Hemos iniciado tres parámetros " << endl;
    // ****************************************************

//    ck.resize (2,2);
//    dk.resize (2,1);

    // ****************************************************
    //cout << "           Salimos del constructor " << endl;
    // ****************************************************

};

/* -------------------------------------------------------------- */

celem2d::celem2d (int n, cnodo2d *a, cnodo2d *b, cnodo2d *c, cnodo2d *d) {

    id = n;

    this->nodos.push_back (a);
    this->nodos.push_back (b);
    this->nodos.push_back (c);
    this->nodos.push_back (d);

    mark = 0;
    tiporef = 0;
    nhijos = 0;

//    ck.resize (2,2);
//    dk.resize (2,1);
};

/* -------------------------------------------------------------- */

celem2d::celem2d (int n, cnodo2d *a, cnodo2d *b, cnodo2d *c, carista *p, carista *q, carista *r) {

    id = n;

    this->nodos.push_back (a);
    this->nodos.push_back (b);
    this->nodos.push_back (c);

    this->aristas.push_back (p);
    this->aristas.push_back (q);
    this->aristas.push_back (r);

    mark = 0;
    tiporef = 0;
    nhijos = 0;

//    ck.resize (2,2);
//    dk.resize (2,1);
};

/* -------------------------------------------------------------- */

void celem2d::sort () {

    // Ordenación de los vértices y aristas del triángulo.
    // Colocamos en primer lugar la arista más larga y el vértice opuesto a la misma.

    double long0, long1, long2;
    cnodo2d *z;
    carista *y;

    long0 = this->aristas[0]->length ();
    long1 = this->aristas[1]->length ();
    long2 = this->aristas[2]->length ();

/*
    double a0x, a0y, a1x, a1y, a2x, a2y, long0, long1, long2;
    cnodo2d *z;
    carista *y;

    a0x = this->nodos[1]->x - this->nodos[2]->x;

    a0x = this->nodos[1]->x - this->nodos[2]->x;
    a0y = this->nodos[1]->y - this->nodos[2]->y;
    a1x = this->nodos[0]->x - this->nodos[2]->x;
    a1y = this->nodos[0]->y - this->nodos[2]->y;
    a2x = this->nodos[0]->x - this->nodos[1]->x;
    a2y = this->nodos[0]->y - this->nodos[1]->y;
    long0 = sqrt (a0x*a0x + a0y*a0y);
    long1 = sqrt (a1x*a1x + a1y*a1y);
    long2 = sqrt (a2x*a2x + a2y*a2y);
*/

    if (long1 >= long0 && long1 >= long2) {
        z = this->nodos[1];
        this->nodos[1] = this->nodos[2];
        this->nodos[2] = this->nodos[0];
        this->nodos[0] = z;
        y = this->aristas[1];
        this->aristas[1] = this->aristas[2];
        this->aristas[2] = this->aristas[0];
        this->aristas[0] = y;
    }
    else if (long2 >= long0 && long2 >= long1) {
        z = this->nodos[2];
        this->nodos[2] = this->nodos[1];
        this->nodos[1] = this->nodos[0];
        this->nodos[0] = z;
        y = this->aristas[2];
        this->aristas[2] = this->aristas[1];
        this->aristas[1] = this->aristas[0];
        this->aristas[0] = y;
    }
};

/* -------------------------------------------------------------- */

void celem2d::superficie () {

//    double ck00, ck01, ck10, ck11;
//    cfull this->ck (2,2);
//    cfull this->dk (2,1);

//    ck00 = this->nodos[1]->x - this->nodos[0]->x;
//    ck01 = this->nodos[2]->x - this->nodos[0]->x;
//    ck10 = this->nodos[1]->y - this->nodos[0]->y;
//    ck11 = this->nodos[2]->y - this->nodos[0]->y;

    this->ck (0,0) = this->nodos[1]->x - this->nodos[0]->x;
    this->ck (0,1) = this->nodos[2]->x - this->nodos[0]->x;
    this->ck (1,0) = this->nodos[1]->y - this->nodos[0]->y;
    this->ck (1,1) = this->nodos[2]->y - this->nodos[0]->y;

    this->dk (0) = this->nodos[0]->x;
    this->dk (1) = this->nodos[0]->y;

    this->jac = abs (ck(0,0) * ck(1,1) - ck(0,1) * ck(1,0));
    this->area = 0.5 * this->jac;
};

/* -------------------------------------------------------------- */

/* void celem2d::vnormal () {

    vector <double> t0 (2);
    vector <double> t1 (2);
    vector <double> t2 (2);
    vector <double> v0 (2);
    vector <double> v1 (2);
    vector <double> v2 (2);

    t0 [0] = this->nodos[2]->x - this->nodos[1]->x;
    t0 [1] = this->nodos[2]->y - this->nodos[1]->y;
    t1 [0] = this->nodos[0]->x - this->nodos[2]->x;
    t1 [1] = this->nodos[0]->y - this->nodos[2]->y;
    t2 [0] = this->nodos[1]->x - this->nodos[0]->x;
    t2 [1] = this->nodos[1]->y - this->nodos[0]->y;
    v0 [0] = -t0[1];
    v0 [1] =  t0[0];
    v1 [0] = -t1[1];
    v1 [1] =  t1[0];
    v2 [0] = -t2[1];
    v2 [1] =  t2[0];

    double z;

    z = 1.0 / norma02 (v0);
    v0 [0] = z * v0[0];
    v0 [1] = z * v0[1];
    if (v0[0] * t0[1] - v0[1] * t0[0] < 0.0) {
        v0 [0] = - v0 [0];
        v0 [1] = - v0 [1];
    }

    z = 1.0 / norma02 (v1);
    v1 [0] = z * v1[0];
    v1 [1] = z * v1[1];
    if (v1[0] * t1[1] - v1[1] * t1[0] < 0.0) {
        v1 [0] = - v1 [0];
        v1 [1] = - v1 [1];
    }

    z = 1.0 / norma02 (v2);
    v2 [0] = z * v2[0];
    v2 [1] = z * v2[1];
    if (v2[0] * t2[1] - v2[1] * t2[0] < 0.0) {
        v2 [0] = - v2 [0];
        v2 [1] = - v2 [1];
    }
    
//    this->v01 [0] = v0 [0];
//    this->v01 [1] = v0 [1];
//    this->v02 [0] = v1 [0];
//    this->v02 [1] = v1 [1];
//    this->v03 [0] = v2 [0];
//    this->v03 [1] = v2 [1];

// array2D.resize(HEIGHT);
//   for (int i = 0; i < HEIGHT; ++i)
//           array2D[i].resize(WIDTH);

// this->normales.resize (3);
//     for (int i=0; i<3; ++i)
//         this->normales[i].resize (2);
// 
// //    this->normales.push_back (v0);
// //    this->normales.push_back (v1);
// //    this->normales.push_back (v2);
};
*/

/* -------------------------------------------------------------- */

void celem2d::cdgcompute () {

    int ns = this->nodos.size ();
    double xx = 0.0;
    double yy = 0.0;
    cnodo2d *nod;
    for (int i=0; i<ns; i++) {
        nod = this->nodos [i];
        xx += nod->x;
        yy += nod->y;
    }
    this->cdg = cnodo2d (0, xx/ns, yy/ns);
};

/* -------------------------------------------------------------- */

bool celem2d::contains (cnodo2d *nod) {

    double eps = 1.e-12;
    double eps1 = 1.0 + eps;

    double a1 = this->nodos[0]->x;
    double a2 = this->nodos[0]->y;
    double b1 = this->nodos[1]->x;
    double b2 = this->nodos[1]->y;
    double c1 = this->nodos[2]->x;
    double c2 = this->nodos[2]->y;
    double p1 = nod->x;
    double p2 = nod->y;

    double v0x = (c1 - a1);
    double v0y = (c2 - a2);
    double v1x = (b1 - a1);
    double v1y = (b2 - a2);
    double v2x = (p1 - a1);
    double v2y = (p2 - a2);

    double d00 = v0x * v0x + v0y * v0y;
    double d01 = v0x * v1x + v0y * v1y;
    double d02 = v0x * v2x + v0y * v2y;
    double d11 = v1x * v1x + v1y * v1y;
    double d12 = v1x * v2x + v1y * v2y;
    double denom = 1.0 / (d00 * d11 - d01 * d01);
    double u = (d11 * d02 - d01 * d12) * denom;
    double v = (d00 * d12 - d01 * d02) * denom;

    return (u >= -eps && v >= -eps && u+v <= eps1);
}

/* -------------------------------------------------------------- */

void celem2d::print01 () {

//    printf ("     Elemento  %5d            Nodos (%4d, %4d, %4d)\n", this->id, this->nodos[0]->id, this->nodos[1]->id, this->nodos[2]->id);
    printf ("   %5d            Nodos (%4d, %4d, %4d)\n", this->id, this->nodos[0]->id, this->nodos[1]->id, this->nodos[2]->id);
};

/* -------------------------------------------------------------- */

void celem2d::print02 () {

    printf ("       Elemento  %3d            Nodos (%4d, %4d, %4d)", this->id, this->nodos[0]->id, this->nodos[1]->id, this->nodos[2]->id);
    printf ("       Aristas (%4d, %4d, %4d)            Mark = %1d\n", this->aristas[0]->id, this->aristas[1]->id, this->aristas[2]->id, this->mark);

//    printf ("     %3d        %4d  %4d  %4d", this->id, this->nodos[0]->id, this->nodos[1]->id, this->nodos[2]->id);
//    printf ("     %4d  %4d  %4d      %4d\n", this->aristas[0]->id, this->aristas[1]->id, this->aristas[2]->id, this->mark);
};

/* -------------------------------------------------------------- */

void celem2d::print03 () {

    printf ("       Elemento  %3d            Nodos (%4d, %4d, %4d)", this->id, this->nodos[0]->id, this->nodos[1]->id, this->nodos[2]->id);
    printf ("            Vecinos (");
    for (int i=0; i<3; i++) {
        if (this->vecinos[i] == NULL) {
            printf ("  -1");
        } else {
            printf (" %4d", this->vecinos[i]->id);
        }
    }
    printf (")\n");
};

/* --------------------------------------------------------------------------- */

