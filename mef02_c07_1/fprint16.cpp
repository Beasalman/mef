#include "fprint16.h"

/* ------------------------------------------------------------------------------------ */

void fprint16 (SparseMatrix <double> a, VectorXd b) {

    /* FPRINT16: 

    Entradas:
    */

    int n = b.size ();

    // Apertura del archivo.

    std::ofstream fic;
    fic.open ("matriz-morse-y-vector.m", std::fstream::out);

//    fic << "import numpy as np" << "\n\n";
    fic << "n = " << n << ";\n";

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
    fic << "aa = zeros (" << naa << ",1);" << "\n";
    for (int i=0; i<naa; i++) {
        fic << "aa (" << i+1 << ") = " << aa [i] << ";\n";
    }

    // Puntero diagonal.

    fic << "\n";
    fic << "diag = zeros (n+1,1);" << "\n";
    diag (n) = diag (n-1) + 1;
    for (int i=0; i<=n; i++) {
        fic << "diag (" << i+1 << ") = " << diag (i) + 1 << ";\n";
    }

    // Puntero columna.

    int ncol = col.size ();
    fic << "\n";
    fic << "col = zeros (" << ncol << ",1);" << "\n";
    for (int i=0; i<ncol; i++) {
        fic << "col (" << i+1 << ") = " << col [i] + 1 << ";\n";
    }

    // Segundo miembro.

    fic << "\n";
    fic << "b = zeros (n,1);" << "\n\n";
    for (int i=0; i<n; i++) {
        fic << "b (" << i+1 << ") = ";
        fic << setprecision (8) << b (i) << ";\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

