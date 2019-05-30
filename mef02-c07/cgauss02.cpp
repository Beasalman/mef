#include "cgauss02.h"

/* ---------------------------------------------------------------- */

cgauss02::cgauss02 () {

    n = 0;
}

/* ---------------------------------------------------------------- */

cgauss02::cgauss02 (int opt) {

    if (opt == 1) {

        // Vértices del triángulo.

        double c16 = 1.0 / 6.0;

        n = 3;
        x.resize (n, 0);
        y.resize (n, 0);
        peso.resize (n, 0);

        x[0] = 1.0;
        y[0] = 0.0;
        peso[0] = c16;

        x[1] = 0.0;
        y[1] = 1.0;
        peso[1] = c16;

        x[2] = 0.0;
        y[2] = 0.0;
        peso[2] = c16;
    }
    
    /* ------------------------------------------------------------ */

    else if (opt == 2) {

        // Puntos medios de los lados del triángulo.

        double c16 = 1.0 / 6.0;
        double c23 = 2.0 / 3.0;

        n = 3;
        x.resize (n, 0);
        y.resize (n, 0);
        peso.resize (n, 0);

        x[0] = 0.5;
        y[0] = 0.0;
        peso[0] = c16;

        x[1] = 0.0;
        y[1] = 0.5;
        peso[1] = c16;

        x[2] = 0.5;
        y[2] = 0.5;
        peso[2] = c16;
    }

    /* ------------------------------------------------------------ */

    else if (opt == 3) {

        // Nodos interiores en el triángulo.

        double c16 = 1.0 / 6.0;
        double c23 = 2.0 / 3.0;

        n = 3;
        x.resize (n, 0);
        y.resize (n, 0);
        peso.resize (n, 0);

        x[0] = c16;
        y[0] = c23;
        peso[0] = c16;

        x[1] = c23;
        y[1] = c16;
        peso[1] = c16;

        x[2] = c16;
        y[2] = c16;
        peso[2] = c16;
    }

    /* ------------------------------------------------------------ */

    else if (opt == 4) {

        // Nodos interiores en el cuadrado.

        n = 4;
        x.resize (n, 0);
        y.resize (n, 0);
        peso.resize (n, 0);

        x[0] = 0.0;
        y[0] = 0.0;
        peso[0] = 0.25;

        x[1] = 1.0;
        y[1] = 0.0;
        peso[1] = 0.25;

        x[2] = 0.0;
        y[2] = 1.0;
        peso[2] = 0.25;

        x[3] = 1.0;
        y[3] = 1.0;
        peso[3] = 0.25;
    }

    /* ------------------------------------------------------------ */

    else if (opt == 5) {

        // Nodos interiores en el cuadrado.

        double s35 = sqrt (3.0 / 5.0);
        double s1 = 0.5 * (1.0 - s35);
        double s2 =  0.5 * (1.0 + s35);
        double c324 = 1.0 / 324.0;
        double c25 = 25.0 * c324;
        double c40 = 40.0 * c324;
        double c64 = 64.0 * c324;

        n = 9;
        x.resize (n, 0);
        y.resize (n, 0);
        peso.resize (n, 0);

        x[0] = s1;
        y[0] = s1;
        peso[0] = c25;

        x[1] = 0.0;
        y[1] = s1;
        peso[1] = c40;

        x[2] = s2;
        y[2] = s1;
        peso[2] = c25;

        x[3] = s1;
        y[3] = 0.0;
        peso[3] = c40;

        x[4] = 0.0;
        y[4] = 0.0;
        peso[4] = c64;

        x[5] = s2;
        y[5] = 0.0;
        peso[5] = c40;

        x[6] = s1;
        y[6] = s2;
        peso[6] = c25;

        x[7] = 0.0;
        y[7] = s2;
        peso[7] = c40;

        x[8] = s2;
        y[8] = s2;
        peso[8] = c25;
    }
}

/* ---------------------------------------------------------------- */

