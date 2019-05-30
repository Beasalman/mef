#include "fprint15.h"

/* ------------------------------------------------------------------------------------ */

void fprint15 (SparseMatrix <double> a, VectorXd b) {

    /* FPRINT13: 

    Entradas:
    */

    int n = b.size ();

    // ************************************************************************
    /*
    cout << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (abs(a.coeffRef (i,j)) > 1.e-12) {
                cout << " a (" << i << "," << j << ") = " << a.coeffRef (i,j) << endl;
            }
        }
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << " b (" << i << ") = " << b (i) << endl;
    }
    cout << endl;

    VectorXd u (n);

    ConjugateGradient <SparseMatrix <double> > solver;
    solver.compute (a);
    u = solver.solve (b);

    //-- BiCGSTAB <SparseMatrix <double> > solver;
    //-- solver.compute (a);
    //-- u = solver.solve (b);

    //-- SparseLU <SparseMatrix <double> > solver;
    //-- solver.analyzePattern (a);
    //-- solver.factorize (a);
    //-- u = solver.solve (b);

    for (int i=0; i<n; i++) {
        cout << " u (" << i << ") = " << u (i) << endl;
    }
    cout << " Número de iteraciones: " << solver.iterations () << endl;
    cout << endl;
    */
    // ************************************************************************

    // Apertura del archivo.

    std::ofstream fic;
    fic.open ("matriz-morse-y-vector.py", std::fstream::out);

    fic << "import numpy as np" << "\n\n";
    fic << "n = " << n << "\n";

    // Matriz en formato Morse simétrica.

    VectorXd diag (n + 1);
    vector <int> col;
    vector <double> aa;

    int k = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (abs (a.coeffRef (i,j)) > 1.e-12) {
                k += 1;
                aa.push_back (a.coeffRef (i,j)); 
                col.push_back (j);
            }
        }
        diag (i) = k;
    }

    int naa = aa.size ();
    fic << "\n";
    fic << "aa = np.zeros (" << naa << ", 'f')" << "\n";
    for (int i=0; i<naa; i++) {
        fic << "aa [" << i << "] = " << aa [i] << "\n";
    }

    // Puntero diagonal.

    fic << "\n";
    fic << "diag = np.zeros (n+1, 'i')" << "\n";
    diag (n) = diag (n-1) + 1;
    for (int i=0; i<=n; i++) {
        fic << "diag [" << i << "] = " << diag (i) << "\n";
    }

    // Puntero columna.

    int ncol = col.size ();
    fic << "\n";
    fic << "col = np.zeros (" << ncol << ", 'i')" << "\n";
    for (int i=0; i<ncol; i++) {
        fic << "col [" << i << "] = " << col [i] << "\n";
    }

    // Segundo miembro.

    fic << "\n";
    fic << "b = np.zeros (n, 'f')" << "\n\n";
    for (int i=0; i<n; i++) {
        fic << "b [" << i << "] = ";
        fic << setprecision (8) << b (i) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

