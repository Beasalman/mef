#include "conjgr01.h"

/* ----------------------------------------------------------------------------------------------------- */

void conjgr01 (SparseMatrix <double> a, VectorXd b, VectorXd &x, int niter, double eps, int &iter, int &conv) {

    /* CONJGR01: Método de gradiente conjugado.

    Entradas:
    - a:     matriz del sistema.
    - b:     vector segundo miembro.
    - niter: número máximo de iteraciones.
    - eps:   error relativo máximo.

    Entrada/salidas:
    - x:    solución del sistema de ecuaciones.
    - iter: iteraciones realizadas.
    - conv: indicador de convergencia.
    */

    int k;
    int n = b.size ();
    double alpha, beta, r2, s2, emax;

    VectorXd p (n), r (n), ap (n);

    // ***************************************************************
    //VectorXd uu (n);
    //for (int i=0; i<n; i++) uu (i) = 1.0 * i;
    //b = a * uu;
    // ***************************************************************

    /* ------------------------------------------------------------------------------------------------- */
    // Inicialización.

    r = b - a * x;             // Residuo.
    r2 = r.dot (r);
    emax = eps * eps * r2;
    p = util02 (r);            // Dirección de descenso.

    // ********************************************************************************************
    //cout << " [CONJGR01] r2: " << r2 << "       emax: " << emax << endl;
    // ********************************************************************************************

    // Bucle iterativo.
  	
    for (k=0; k<niter; k++) {
        ap = a * p;
        alpha = r2 / p.dot (ap);

        x = x + alpha * p;           // x += alpha * p;
        r = r - alpha * ap;          // r -= alpha * ap;

        // ********************************************************************************************
        //cout << " r: " << endl;
        //cout << r << endl;
        // ********************************************************************************************

        s2 = r.dot (r);
        // ********************************************************************************************
        cout << "     GC iter: " << k << "        s2: " << s2 << "         emax: " << emax << endl;
        // ********************************************************************************************
        if (s2 < emax) {
            conv = 1;
            iter = k + 1;
            break;
        }

        // ********************************************************************************************
        //cout << " x: " << endl;
        //cout << x << endl;
        // ********************************************************************************************

        beta = s2 / r2;
        p = r + beta * p;
        r2 = s2;
    }
}

/* ----------------------------------------------------------------------------------------------------- */

