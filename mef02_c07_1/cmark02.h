#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::max;

#ifndef cmark_h_
    #include "cmark.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cmark02_h_
#define cmark02_h_

class cmark02 : public cmark {

    public:

        cmark02 (double);
        void operator () (cmalla2d01 *);
};

#endif

/* ----------------------------------------------------------------------- */
