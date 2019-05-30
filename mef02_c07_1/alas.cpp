#include "alas.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void alas (SparseMatrix <double> a, VectorXd b, VectorXd psi, VectorXd &u, double beta, 
           double eps, int niter, int &k) {
    
    /* ALAS: Resolución de un sistema de inecuaciones lineales.
             Problema con obstáculo inferior.

    Entradas:
    - a:   matriz.
    - b:   vector segundo miembro.
    - psi: obstáculo.

    Entrada/salida:
    - u: solución.
    */

    // ---------------------------------------------------------------------------

    // *************************************************************
    //cout << "\n [ALAS] Matriz del sistema: " << endl;
    //cout << a << endl;
    //cout << " [ALAS] Obstáculo: " << endl;
    //cout << psi << endl;
    //cout << " [ALAS] Aproximación inicial" << endl;
    //cout << u << endl;
    // *************************************************************

    int n = b.size ();
    int n1, n2;
    double err;

    VectorXd u0 (n);
    VectorXd p (n);
    VectorXd q (n);
 
    u0 = util02 (psi);
    u = util02 (psi);

    p = a * u;
    for (int i=0; i<n; i++) {
        p (i) = min (0.0, b(i) - p(i));
    }

    // ---------------------------------------------------------------------------
    // Bucle iterativo.

    for (k=0; k<niter; k++) {

        // *************************************************************
        //cout << " [ALAS]      Iter: " << k << endl;
        // *************************************************************

        vector <int> activos;
        vector <int> libres;

        q = p + beta * (u - psi);
        for (int i=0; i<n; i++) {
            q (i) = min (0.0, q(i));
            if (q(i) < 0.0) {
                activos.push_back (i);
            } else {
                libres.push_back (i);
            }
        }

        // -----------------------------------------------------------------------
        // Sistema reducido.

        // *************************************************************
        //cout << " [ALAS]              Nodos activos: ";
        //for (int j=0; j<activos.size(); j++) cout << " " << activos[j];
        //cout << endl;
        //cout << " [ALAS]              Nodos libres: ";
        //for (int j=0; j<libres.size(); j++) cout << " " << libres[j];
        //cout << endl;
        //cout << " [ALAS]              Construimos y resolvemos el sistemas reducido" << endl;
        // *************************************************************

        n1 = libres.size ();
        VectorXd ui (n1);
        if (activos.size () > 0) {
            // *************************************************************
            //cout << " [ALAS]                   activos.size() > 0" << endl;
            // *************************************************************

            n1 = libres.size ();
            n2 = activos.size ();

            SparseMatrix <double> aii (n1, n1);
            matvecreduce (a, libres, aii);

            SparseMatrix <double> aij (n1, n2);
            matvecreduce (a, libres, activos, aij);

            VectorXd psij (n2);
            matvecreduce (psi, activos, psij);

            VectorXd bi (n1);
            matvecreduce (b, libres, bi);

            VectorXd bk (n1);
            bk = bi - aij * psij;

            SparseLU <SparseMatrix <double> > solver;
            aii.makeCompressed();
            solver.compute (aii);
            ui = solver.solve (bk);

        } else {
            // *************************************************************
            //cout << " [ALAS]                   activos.size() = 0" << endl;
            //cout << a << endl;
            // *************************************************************

            SparseLU <SparseMatrix <double> > solver;
            a.makeCompressed();
            solver.compute (a);
            ui = solver.solve (b);

            // *************************************************************
            //cout << " [ALAS]   ui:" << endl;
            //cout << ui << endl;
            // *************************************************************
        }

        u = util02 (psi);
        for (int i=0; i<n1; i++) {
            // *************************************************************
            //cout << " [ALAS]   i: " << i << "    libres(i): " << libres[i] << endl;
            // *************************************************************
            u (libres [i]) = ui (i);
        }

        // *************************************************************
        //cout << " [ALAS]   u:" << endl;
        //cout << u << endl;
        //cout << " [ALAS]   b:" << endl;
        //cout << b << endl;
        // *************************************************************

        p = b - a * u;

        // -----------------------------------------------------------------------
        // Test de convergencia.

        // *************************************************************
        //cout << " [ALAS]              Test de convergencia" << endl;
        // *************************************************************

        err = (u - u0).norm () / u.norm ();
        if (err < eps) break;
        u0 = util02 (u);
    }
    // *************************************************************
    //cout << " [ALAS]   u:" << endl;
    //cout << u << endl;
    // *************************************************************
    k += 1;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */



