#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::max;

#ifndef cmark_h_
    #include "cmark.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cmark04_h_
#define cmark04_h_

class cmark04 : public cmark {

    public:

        cmark04 ();
        void operator () (cmalla2d01 *, VectorXd, VectorXd);
};

#endif

/* ----------------------------------------------------------------------- */
