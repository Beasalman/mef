#include "fprint19.h"

/* ------------------------------------------------------------------------------------ */

void fprint19 (int level, int itp, VectorXd u) {

    /* FPRINT19: Escritura de la aproximación numérica del valor sin riesgo.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    char nomfic[20];
    int long1 = sprintf (nomfic, "svnorisk%02dt%03d.dat", level, itp);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores del vector.

    int n = u.size ();
    for (int i=0; i<n; i++) {
        fic << i << " ";
        fic << setprecision (8) << u(i) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

