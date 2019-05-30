#include "fprint17.h"

/* ------------------------------------------------------------------------------------ */

void fprint17 (int level, cmalla2d01 *m, VectorXd v) {

    /* FPRINT17: Escritura de la solución de Black-Scholes.
                 Función de dos variables espaciales.

    Entradas:
    - level: nivel actual.
    */

    double x, y;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sbs%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        fic << i << " ";
        fic << setprecision (8) << v(i) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

