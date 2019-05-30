#include "dataread.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dataread (cdataprob &dprob, cdatamesh &dmesh, cdatanum &dnum) {

    /* DATAREAD: Lectura de datos.

    Entrada/salida:
    - dprob:
    - dmesh:
    - dnum:  
    */

    char nomfic0[21];
    char nomfic1[21];
    char nomfic2[20];
    int emesh, efnum, eprob, long1;

    // ---------------------------------------------------------------

    cout << "\n Extensiones de los archivos de datos " << endl;
    cout << "\n                Datos del problema:   ";
    cin >> eprob;
    long1 = sprintf(nomfic0,"dprob%02d.dat",eprob);
  
   // cout<<nomfic0<<"222222"<<endl;
    dprob.read (nomfic0);

    // ---------------------------------------------------------------

    cout << "                Datos de la malla:    ";
    cin >> emesh;
    long1 = sprintf (nomfic1, "dmesh%02d.dat", emesh);

    dmesh.read (nomfic1);

    // ---------------------------------------------------------------

    cout << "                Datos numéricos:      ";
    cin >> efnum;
    long1 = sprintf (nomfic2, "dnum%02d.dat", efnum);

    dnum.read (nomfic2);
    cout << endl;

    // ---------------------------------------------------------------
    // Paso temporal.

    dnum.caracdeltat = (dprob.tfin - dprob.tini) / dnum.caracniter;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

