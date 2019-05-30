#include "optioneuro01.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void optioneuro01 (vector <cmalla2d01 *> mallas, int level, cmalla2d01 *m, cgauss02 *g, cgauss1d *g1, cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
                   map <int, celem2d *> geltos, map <int, cnodo2d *> gnodos, map <int, carista *> garistas, cbs *bs, cmark *fmark,
                   VectorXd &vold, VectorXd &uold, cdiffusion2d *diff, cconvection2d *velocity01, cconvection2d *velocity02) {

    /* OPTIONEURO01: Opción europea 2D.
                     Sin refinamiento de mallado a lo largo del tiempo.
 
    Entradas:
    - m: (puntero a) malla actual.
    - g: 
    - dmesh: 
    */

    int j;
    double errj, z1d;
    cnodo2d *nod, *nodb, *nodc;
    celem2d *ef, *efc;
    cfrontera2d *fr;
    map <int, celem2d*> :: iterator ielt;
    Vector2d y, z;

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados sobre la malla 2D. Almacenamos sus coordenadas baricéntricas.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;
        for (int i=0; i<g->n; i++) {
            y (0) = g->x [i];
            y (1) = g->y [i];
            z = ef->ck * y + ef->dk;
            nodc = new cnodo2d (-1, 0., 0.);
            nodc = carac02 (z, dnum.caracdeltat, 10, velocity01, m);

            efc = localiza01 (mallas, level, nodc);
            ef->eltosdesplazados.push_back (efc);

            nodb = new cnodo2d (-1, 0., 0.);
            baric01 (efc, nodc, nodb);
            ef->nodosdesplazados.push_back (nodb);
        }
    }

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados de la frontera 1. Almacenamos sus coordenadas baricéntricas.

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        z (0) = nod->x;
        z (1) = nod->y;
        nodc = new cnodo2d (-1, 0., 0.);
        nodc = carac02 (z, dnum.caracdeltat, 10, velocity02, m);

        efc = localiza01 (mallas, level, nodc);
        nod->eltodesplazado = efc;

        nodb = new cnodo2d (-1, 0., 0.);
        baric01 (efc, nodc, nodb);
        nod->nododesplazado = nodb;
    }

	//-----------------------------------------------------------------------------------------------
	
	//C�lculo de la malla 1d para el calculo de la solucion de BS con riesgo de contrapartida

	map <int, cnodo1d *> gnodos1d;
	map <int, celem1d *> geltos1d;
	

   
	//int numnod1d = m->fronteras[0]->nodos.size();
	//int nelt1d = numnod1d - 1;
	//cmalla1d *meshBS = new cmalla1d(1, numnod1d, nelt1d, m->fronteras[0]->nodos);
	cmalla1d *meshBS = meshgen2d1d(m);

	int numnod1d = meshBS->nsom;
	SparseMatrix <double, ColMajor> a1d (numnod1d,numnod1d);

		
	double nu;
	VectorXd bc1d (meshBS->nsom);
	VectorXd b1d (meshBS->nsom);
	VectorXd bu1d (meshBS->nsom);
	VectorXd u1d (meshBS->nsom);
	VectorXd uold1d (meshBS->nsom);
	//	MatrixXd solu1d_domain (fr->nodos.size(),meshBS->nsom,dnum.caracniter);
	//	MatrixXd solu1d_domain = MatrixXd::Zero (fr->nodos.size(),meshBS->nsom,dnum.caracniter);
	float solu1d_domain[fr->nodos.size()][meshBS->nsom][dnum.caracniter];
	for (int i=0; i<fr->nodos.size(); i++) {
	//matriz para la frontera 2 nu = nuinf
		nu = fr->nodos [i]->y;
		globalmat02 (meshBS, g1, dprob, dnum, nu, a1d);   
		dirichlet00(meshBS,a1d);
		a1d.makeCompressed ();
		SparseLU <SparseMatrix <double> > solver;
		solver.compute (a1d);
		 VectorXd v1d1 = VectorXd::Zero (meshBS->nsom);
		 VectorXd ur1d = VectorXd::Zero (meshBS->nsom);
		 double tau = dprob.tini;
	
		// ----------------------------------------------------------------------------
		for (int n=0; n<dnum.caracniter; n++) {
		    tau += dnum.caracdeltat;
		    // Cálculo de los puntos desplazados de la malla 1d. Se guardan en caracpoint y caracelt	
		    cvelocity1d *velocity03 = new cvelocity1d(nu, dprob.rr);
		    cvelocity1d *velocity04 = new cvelocity1d0(dprob.rr);
		    /* VectorXd caracpoint (meshBS->nsom);
		    VectorXd caracpointfr (meshBS->nsom);
		    caracpoint = VectorXd::Zero (meshBS->nsom);
		    caracpointfr = VectorXd::Zero (meshBS->nsom);*/
		    vector <double> caracpoint;
		    vector<double> caracpointfr;
		    vector <celem1d *> caracelt;
		    vector <celem1d *> caraceltfr;
		    ccurve *cc = NULL;
		    ccurve *ccfr = NULL;
		    // meshBS->nodos.begin(), meshBS->nodos.end()
		    cc = new ccurve01(velocity03, dnum.caracdeltat, meshBS->nodos[0]->s, meshBS->nodos[numnod1d-1]->s);
		    ccfr = new ccurve01(velocity04, dnum.caracdeltat, meshBS->nodos[0]->s, meshBS->nodos[numnod1d-1]->s);
		    carac1d (meshBS, g1, velocity03, cc, caracpoint, caracelt); //Obtencion del elemento y nodo desplazado de la malla 1d
     
		//-----------------------------------------------------------------------------------------------
			
		    
		    globalvec02 (meshBS, g1, caracpoint, caracelt, uold1d, bc1d);
		
		    for (int k=0; k<meshBS->nsom; k++) {
			v1d1 (k) = (*bs) (m->nodos[k]->x, nu, tau);
	        	ur1d[k] = -(dprob.sF + dprob.lambdaC * (1-dprob.RC)) * positive (v1d1(k)) - dprob.lambdaC * (1-dprob.RC) * negative(v1d1(k));
	            }
	
		    globalvec03 (meshBS, g1, ur1d, bu1d);
		    b1d = dnum.caracdeltat * bu1d + bc1d;
	        
		    //Curva con la caracteristica que afecta solo a la frontera
		    carac1d (meshBS, g1, velocity04, ccfr, caracpointfr, caraceltfr);
		    celem1d *effr = caraceltfr.back();//Elemento donde cae S_inf con la curva caracteritica
		    double xiSinf = caracpointfr.back();
		    VectorXd Ufr(meshBS->nfr);	        
		    double Uoldfr = ((xiSinf-effr->nodos[0]->x)*uold1d(effr->nodos[1]->x) + (effr->nodos[1]->x-xiSinf)*uold1d(effr->nodos[0]->x))/(effr->nodos[1]->x-effr->nodos[0]->x);
	        
		    Ufr[0] = (uold1d(0) + dnum.caracdeltat*ur1d(0))/(1 + (dprob.r + dprob.lambdaB + dprob.lambdaC)*dnum.caracdeltat);
	            Ufr[1] = (Uoldfr - ur1d(numnod1d-1))/(1 + (dprob.r + dprob.lambdaB + dprob.lambdaC)*dnum.caracdeltat);
		    dirichlet00(meshBS, b1d, Ufr);
	            u1d = solver.solve (b1d);
        
	            for (int k=0; k<meshBS->nsom;k++){
		         //solu1d_domain(i,k,n) = u1d(k);			
		  	 solu1d_domain[i][k][n] = u1d(k);			
		    }			
		
	        util02 (u1d, uold1d);

	
		}
	}
	

    // ----------------------------------------------------------------------------
    // Matriz (hueca) del sistema de ecuaciones


    SparseMatrix <double, ColMajor> a (m->nsom,m->nsom);
    SparseMatrix <double, ColMajor> au (m->nsom,m->nsom);
    globalmat13 (m, g, dnum.caracdeltat, dprob.r, diff, a);
    double rlblc = dprob.r + dprob.lambdaB + dprob.lambdaC;
    globalmat13 (m, g, dnum.caracdeltat, rlblc, diff, au);
    dirichlet22 (m, a);
    dirichlet22 (m, au);
    a.makeCompressed ();
    au.makeCompressed ();

    SparseLU <SparseMatrix <double> > solver;
    solver.compute (a);
    solver.compute (au);

    // ----------------------------------------------------------------------------
    // Vectores: características, punto fijo y vector global.

    VectorXd bc (m->nsom);
    VectorXd bcu (m->nsom);
    VectorXd br (m->nsom);
    VectorXd b (m->nsom);
    VectorXd bu (m->nsom);
	
    // Vectores: soluciones numérica y analítica.

   // VectorXd v (m->nsom);
   // VectorXd u (m->nsom);
    VectorXd u = VectorXd::Zero (m->nsom);
    VectorXd v = VectorXd::Zero (m->nsom);
    VectorXd vrisk (m->nsom);
    //VectorXd ua = VectorXd::Zero (m->nsom);
    VectorXd ur = VectorXd::Zero (m->nsom);
    VectorXd vant = VectorXd::Zero (m->nsom);
    VectorXd uant = VectorXd::Zero (m->nsom);
    VectorXd v1d = VectorXd::Zero (m->nsom);
    // VectorXd u1d = VectorXd::Zero (m->nsom);

    // ----------------------------------------------------------------------------
    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real    \n");
    printf ("    Step       Time  \n\n");

    int n = 0;
    double t = dprob.tfin;
    double tau = dprob.tini;

    printf ("   %5d", n);
    printf ("   %8.3f", t);
    printf ("\n");

    int itp = 0;
    for (int n=0; n<dnum.caracniter; n++) {
        t -= dnum.caracdeltat;
        tau += dnum.caracdeltat;
        printf ("   %5d", n+1);
        printf ("   %8.3f", t);

        // Valor de la opción.

        for (int i=0; i<m->nsom; i++) {
            v1d (i) = (*bs) (m->nodos[i]->x, m->nodos[i]->y, tau);
        }



	//----------------------------------------------------------------
	/*//Valor del XVA en el dominio total para cada instante de tiempo

	for (int k=0; k<meshBS->nsom; k++) { 
		for (int j=0; i<fr->nodos.size(); i++){
	    	 u1d_total (i) = solu1d_domain[j][k][n]; 
		} 
	}*/
	//----------------------------------------------------------------

        // Vector del término de características.

        bc = VectorXd::Zero (m->nsom);
        bcu = VectorXd::Zero (m->nsom);
        globalvec12 (m, g, vold, bc);
        globalvec12 (m, g, uold, bcu);

        // Bucle de punto fijo.

       // j = 0;
       // util02 (vold, vant);
       // util02 (uold, uant);
       // errj = 1.0 + dnum.pfemax;

	b = bc;
        dirichlet22 (m, v1d, b);
        v = solver.solve (b);

        //segundo miembro del XVA
        //bk = VectorXd::Zero (m->nsom);
        ur = VectorXd::Zero (m->nsom);
        for (int i=0; i<m->nsom; i++) {
        	ur[i] = -(dprob.sF + dprob.lambdaC * (1-dprob.RC)) * positive (v(i)) - dprob.lambdaC * (1-dprob.RC) * negative(v(i));
        }
        globalvec13 (m, g, ur, br);

	/*float solu1d_domain_t[fr->nodos.size()][meshBS->nsom];
	for  (int i=0; i<fr->nodos.size(); i++) {
	  for (int k=0; k<meshBS->nsom; k++) {
	    solu1d_domain_t[i][k] =  solu1d_domain[i][k][n];
	  }
	  }*/
	VectorXd u1d_nu = VectorXd::Zero (fr->nodos.size());
	for  (int i=0; i<fr->nodos.size(); i++) {
	  u1d_nu(i) =  solu1d_domain[i][meshBS->nsom][n];	  
	}

	VectorXd u1d_S = VectorXd::Zero (meshBS->nsom);
	for (int k=0; k<meshBS->nsom; k++) {
	   u1d_S(k) =  solu1d_domain[fr->nodos.size()-1][k][n];
        }

        bu = dnum.caracdeltat * br + bcu;


	

	// dirichlet22 (m, solu1d_domain_t, bu);
	dirichlet22 (m, meshBS, u1d_nu, u1d_S, bu);

        u = solver.solve (bu);

        vrisk = v + u;
       /* while ((j < dnum.pfniter) && (errj > dnum.pfemax)) {
            j += 1;

            // Vector segundo miembro.

            //bk = VectorXd::Zero (m->nsom);
            //uk = VectorXd::Zero (m->nsom);
           // for (int i=0; i<m->nsom; i++) {
           //     uk[i] = -dprob.hinf * m->nodos[i]->y * positive (uant(i) + v(i));
            //}
            //globalvec13 (m, g, uk, bk);

            // Resolución del sistema lineal.

            //b = dnum.caracdeltat * bk + bc;
            b = bc;
            dirichlet22 (m, v1d, b);
            u = solver.solve (b);

            //errj = error02 (u, uant);
            //util02 (u, uant);
        }*/
        

        // Reactualización y salvaguarda de resultados.
	
        util02 (v, vold);
        util02 (u, uold);
        if (n % dnum.nitp == 0) {
            itp += 1;
            fprint19 (level, itp, v);                    // Aproximación numérica.
            fprint11 (level, itp, u);  
            fprint18 (level, itp, vrisk);
            //fprint17 (level, m, v1d);                      // Solución de BS.
        }
        cout << endl;

        // ----------------------------------------------------------------------------
        // Refinamiento de la malla y prolongación de magnitudes.

        /*
        if ((n+1) % dnum.nitp == 0) {

            // ***************************************************************************
            //cout << endl;
            //cout << " [SOLVER03]    m->nsom = " << m->nsom << endl;
            //cout << " [SOLVER03]    mallas.size() = " << mallas.size() << endl;
            // ***************************************************************************

            meshref02 (mallas, level, g, dprob, dmesh, dnum, geltos, gnodos, garistas, fmark, uold, u,
                       a, velocity, diff);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos salido de MESHREF02" << endl;
            //cout << " [SOLVER03]    mallas.size() = " << mallas.size() << endl;
            // ***************************************************************************

            m = mallas.back ();
            bc.resize (m->nsom);
            b.resize (m->nsom);
            ua.resize (m->nsom);
            v.resize (m->nsom);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos redimensionado los vectores" << endl;
            // ***************************************************************************

            solver.compute (a);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos recalculado SOLVER" << endl;
            //cout << " [SOLVER03]    m->nsom = " << m->nsom << endl;
            //cout << endl;
            // ***************************************************************************

        }
        */
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

