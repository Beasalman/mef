#include "fprint14.h"

/* ------------------------------------------------------------------------------------ */

void fprint14 (SparseMatrix <double> a, VectorXd b) {

    /* FPRINT14: 

    Entradas:
    */

    int n = b.size ();

    // Apertura del archivo.

    std::ofstream fic;
    fic.open ("matriz-y-vector.m", std::fstream::out);

    fic << "n = " << n << ";\n";
    fic << "a = zeros (n);" << "\n";
    fic << "b = zeros (n,1);" << "\n\n";

    // Matriz.

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (abs (a.coeffRef (i,j)) > 1.e-12) {
                fic << "a (" << i+1 << "," << j+1 << ") = ";
                fic << setprecision (8) << a.coeffRef (i,j) << ";\n";
            }
        }
    }

    // Segundo miembro.

    for (int i=0; i<n; i++) {
        fic << "b (" << i+1 << ") = ";
        fic << setprecision (8) << b (i) << ";\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

