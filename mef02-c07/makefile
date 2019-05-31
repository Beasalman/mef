# Compilador.

CC = g++

# Opciones de compilación.

#-- CFLAG1 = -O0 -c -g -I /usr/include/eigen3/         # Portátil
#CFLAG1 = -O0 -c -g -I /opt/eigen-3.2.2/            # Despacho
#CFLAG1 = -O0 -c -g -I. -I/ufs/bsm/Documents/Eigen/            # Despacho
CFLAG1 = -O0 -c -g -I. -I../Eigen/            # Despacho
CFLAG2 = -O0


all: mef

mef: mef.o \
     alas.o \
     baric01.o \
     bicgstab01.o \
     carac1d.o \
     carac02.o \
     carista.o \
     cbs.o \
     cbscall.o \
     cbsput.o \
     cconv00.o \
     cconv01.o \
     cconvection2d.o \
     ccurve.o \
     ccurve01.o \
     cdatamesh.o \
     cdatanum.o \
     cdataprob.o \
     cdiffusion2d.o \
     cdiffusion00.o \
     cdiffusion01.o \
     cdiffusion02.o \
     cdir1d.o \
     cdir1dcall.o \
     cdir1dput.o \
     cdomain2d.o \
     celem1d.o \
     celem2d.o \
     cfrontera1d.o \
     cfrontera2d.o \
     cfunc11.o \
     cgauss02.o \
     cgauss1d.o \
     cintegra1d.o \
     cmalla1d.o \
     cmalla2d01.o \
     cmark.o \
     cmark00.o \
     cmark01.o \
     cmark02.o \
     cmark03.o \
     cmark04.o \
     cnodo1d.o \
     cnodo2d.o \
     cnormal.o \
     conjgr01.o \
     cpayoff.o \
     cpayoffcall.o \
     cpayoffput.o \
     csecond.o \
     csecond00.o \
     csecond01.o \
     csecond03.o \
     csimpson1d.o \
     ctrapecio1d.o \
     cvelocity1d.o \
     cvelocity1d0.o \
     dataread.o \
     dirichlet00.o \
     dirichlet20.o \
     dirichlet21.o \
     dirichlet22.o \
     dirichlet22z.o \
     dirichlet23.o \
	 elmat1d2gdl02.o \
	 elmat1d2gdl03.o \
	 elvec1d2gdl02.o \
     ensamb30.o \
     ensmat.o \
     ensvec.o \
     error02.o \
     fprint11.o \
     fprint12.o \
     fprint13.o \
     fprint14.o \
     fprint15.o \
     fprint16.o \
     fprint17.o \
     fprint18.o \
     fprint19.o \
     fprint20.o \
     globalmat02.o \
     globalmat12.o \
     globalmat13.o \
     globalmat14.o \
     globalvec02.o \
     globalvec03.o \
     globalvec11.o \
     globalvec12.o \
     globalvec13.o \
     localiza00.o \
     localiza01.o \
     mat3d11.o \
     mat3d12.o \
     mat3d13.o \
     matvec11.o \
     matvec12.o \
     matvecreduce.o \
     meshcopy.o \
     meshgen00.o \
     meshgen01.o \
     meshgen01b.o \
     meshgen01c.o \
     meshgen02.o \
     meshgen03.o \
     meshgen2d1d.o \
     meshmark01.o \
     meshref01.o \
     meshref02.o \
     negative.o \
     norm.o \
     optioneuro01.o \
     optioneuro02.o \
     positive.o \
     prolong.o \
     reft100.o \
     reft101.o \
     reft110.o \
     reft111.o \
     remesh02.o \
     remesh03.o \
     remesh04.o \
     util01.o \
     util02.o \
     util03.o \
     vec3d11.o \
     vec3d12.o

	$(CC) $(CFLAG2) -o mef.exe mef.o \
     alas.o \
     baric01.o \
     bicgstab01.o \
     carac1d.o \
     carac02.o \
     carista.o \
     cbs.o \
     cbscall.o \
     cbsput.o \
     cconv00.o \
     cconv01.o \
     cconvection2d.o \
     ccurve.o \
     ccurve01.o \
     cdatamesh.o \
     cdatanum.o \
     cdataprob.o \
     cdiffusion2d.o \
     cdiffusion00.o \
     cdiffusion01.o \
     cdiffusion02.o \
     cdir1d.o \
     cdir1dcall.o \
     cdir1dput.o \
     cdomain2d.o \
     celem1d.o \
     celem2d.o \
     cfrontera1d.o \
     cfrontera2d.o \
     cfunc11.o \
     cgauss02.o \
     cgauss1d.o \
     cintegra1d.o \
     cmalla1d.o \
     cmalla2d01.o \
     cmark.o \
     cmark00.o \
     cmark01.o \
     cmark02.o \
     cmark03.o \
     cmark04.o \
     cnodo1d.o \
     cnodo2d.o \
     cnormal.o \
     conjgr01.o \
     cpayoff.o \
     cpayoffcall.o \
     cpayoffput.o \
     csecond.o \
     csecond00.o \
     csecond01.o \
     csecond03.o \
     csimpson1d.o \
     ctrapecio1d.o \
     cvelocity1d.o \
     cvelocity1d0.o \
     dataread.o \
     dirichlet00.o \
     dirichlet20.o \
     dirichlet21.o \
     dirichlet22.o \
     dirichlet22z.o \
     dirichlet23.o \
	 elmat1d2gdl02.o \
	 elmat1d2gdl03.o \
	 elvec1d2gdl02.o \
     ensamb30.o \
     ensmat.o \
     ensvec.o \
     error02.o \
     fprint11.o \
     fprint12.o \
     fprint13.o \
     fprint14.o \
     fprint15.o \
     fprint16.o \
     fprint17.o \
     fprint18.o \
     fprint19.o \
     fprint20.o \
     globalmat02.o \
     globalmat12.o \
     globalmat13.o \
     globalmat14.o \
     globalvec02.o \
     globalvec03.o \
     globalvec11.o \
     globalvec12.o \
     globalvec13.o \
     localiza00.o \
     localiza01.o \
     mat3d11.o \
     mat3d12.o \
     mat3d13.o \
     matvec11.o \
     matvec12.o \
     matvecreduce.o \
     meshcopy.o \
     meshgen00.o \
     meshgen01.o \
     meshgen01b.o \
     meshgen01c.o \
     meshgen02.o \
     meshgen03.o \
     meshgen2d1d.o \
     meshmark01.o\
     meshref01.o \
     meshref02.o \
     negative.o \
     norm.o \
     optioneuro01.o \
     optioneuro02.o \
     positive.o \
     prolong.o \
     reft100.o \
     reft101.o \
     reft110.o \
     reft111.o \
     remesh02.o \
     remesh03.o \
     remesh04.o \
     util01.o \
     util02.o \
     util03.o \
     vec3d11.o \
     vec3d12.o

mef.o: mef.cpp mef.h
	$(CC) $(CFLAG1) mef.cpp
alas.o: alas.cpp alas.h
	$(CC) $(CFLAG1) alas.cpp
baric01.o: baric01.cpp baric01.h
	$(CC) $(CFLAG1) baric01.cpp
bicgstab01.o: bicgstab01.cpp bicgstab01.h
	$(CC) $(CFLAG1) bicgstab01.cpp
carac1d.o: carac1d.cpp carac1d.h
	$(CC) $(CFLAG1) carac1d.cpp
carac02.o: carac02.cpp carac02.h
	$(CC) $(CFLAG1) carac02.cpp
carista.o: carista.cpp carista.h
	$(CC) $(CFLAG1) carista.cpp
cbs.o: cbs.cpp cbs.h
	$(CC) $(CFLAG1) cbs.cpp
cbscall.o: cbscall.cpp cbscall.h
	$(CC) $(CFLAG1) cbscall.cpp
cbsput.o: cbsput.cpp cbsput.h
	$(CC) $(CFLAG1) cbsput.cpp
cconv00.o: cconv00.cpp cconv00.h
	$(CC) $(CFLAG1) cconv00.cpp
cconv01.o: cconv01.cpp cconv01.h
	$(CC) $(CFLAG1) cconv01.cpp
cconvection2d.o: cconvection2d.cpp cconvection2d.h
	$(CC) $(CFLAG1) cconvection2d.cpp
ccurve.o: ccurve.cpp ccurve.h
	$(CC) $(CFLAG1) ccurve.cpp
ccurve01.o: ccurve01.cpp ccurve01.h
	$(CC) $(CFLAG1) ccurve01.cpp
cdatamesh.o: cdatamesh.cpp cdatamesh.h
	$(CC) $(CFLAG1) cdatamesh.cpp
cdatanum.o: cdatanum.cpp cdatanum.h
	$(CC) $(CFLAG1) cdatanum.cpp
cdataprob.o: cdataprob.cpp cdataprob.h
	$(CC) $(CFLAG1) cdataprob.cpp
cdiffusion2d.o: cdiffusion2d.cpp cdiffusion2d.h
	$(CC) $(CFLAG1) cdiffusion2d.cpp
cdiffusion00.o: cdiffusion00.cpp cdiffusion00.h
	$(CC) $(CFLAG1) cdiffusion00.cpp
cdiffusion01.o: cdiffusion01.cpp cdiffusion01.h
	$(CC) $(CFLAG1) cdiffusion01.cpp
cdiffusion02.o: cdiffusion02.cpp cdiffusion02.h
	$(CC) $(CFLAG1) cdiffusion02.cpp
cdir1d.o: cdir1d.cpp cdir1d.h
	$(CC) $(CFLAG1) cdir1d.cpp
cdir1dcall.o: cdir1dcall.cpp cdir1dcall.h
	$(CC) $(CFLAG1) cdir1dcall.cpp
cdir1dput.o: cdir1dput.cpp cdir1dput.h
	$(CC) $(CFLAG1) cdir1dput.cpp
cdomain2d.o: cdomain2d.cpp cdomain2d.h
	$(CC) $(CFLAG1) cdomain2d.cpp
celem1d.o: celem1d.cpp celem1d.h
	$(CC) $(CFLAG1) celem1d.cpp
celem2d.o: celem2d.cpp celem2d.h
	$(CC) $(CFLAG1) celem2d.cpp
cfrontera1d.o: cfrontera1d.cpp cfrontera1d.h
	$(CC) $(CFLAG1) cfrontera1d.cpp
cfrontera2d.o: cfrontera2d.cpp cfrontera2d.h
	$(CC) $(CFLAG1) cfrontera2d.cpp
cfunc11.o: cfunc11.cpp cfunc11.h
	$(CC) $(CFLAG1) cfunc11.cpp
cgauss02.o: cgauss02.cpp cgauss02.h
	$(CC) $(CFLAG1) cgauss02.cpp
cgauss1d.o: cgauss1d.cpp cgauss1d.h
	$(CC) $(CFLAG1) cgauss1d.cpp
cintegra1d.o: cintegra1d.cpp cintegra1d.h
	$(CC) $(CFLAG1) cintegra1d.cpp
cmalla1d.o: cmalla1d.cpp cmalla1d.h
	$(CC) $(CFLAG1) cmalla1d.cpp
cmalla2d01.o: cmalla2d01.cpp cmalla2d01.h
	$(CC) $(CFLAG1) cmalla2d01.cpp
cmark.o: cmark.cpp cmark.h
	$(CC) $(CFLAG1) cmark.cpp
cmark00.o: cmark00.cpp cmark00.h
	$(CC) $(CFLAG1) cmark00.cpp
cmark01.o: cmark01.cpp cmark01.h
	$(CC) $(CFLAG1) cmark01.cpp
cmark02.o: cmark02.cpp cmark02.h
	$(CC) $(CFLAG1) cmark02.cpp
cmark03.o: cmark03.cpp cmark03.h
	$(CC) $(CFLAG1) cmark03.cpp
cmark04.o: cmark04.cpp cmark04.h
	$(CC) $(CFLAG1) cmark04.cpp
cnodo1d.o: cnodo1d.cpp cnodo1d.h
	$(CC) $(CFLAG1) cnodo1d.cpp
cnodo2d.o: cnodo2d.cpp cnodo2d.h
	$(CC) $(CFLAG1) cnodo2d.cpp
cnormal.o: cnormal.cpp cnormal.h
	$(CC) $(CFLAG1) cnormal.cpp
conjgr01.o: conjgr01.cpp conjgr01.h
	$(CC) $(CFLAG1) conjgr01.cpp
cpayoff.o: cpayoff.cpp cpayoff.h
	$(CC) $(CFLAG1) cpayoff.cpp
cpayoffcall.o: cpayoffcall.cpp cpayoffcall.h
	$(CC) $(CFLAG1) cpayoffcall.cpp
cpayoffput.o: cpayoffput.cpp cpayoffput.h
	$(CC) $(CFLAG1) cpayoffput.cpp
csecond.o: csecond.cpp csecond.h
	$(CC) $(CFLAG1) csecond.cpp
csecond00.o: csecond00.cpp csecond00.h
	$(CC) $(CFLAG1) csecond00.cpp
csecond01.o: csecond01.cpp csecond01.h
	$(CC) $(CFLAG1) csecond01.cpp
csecond03.o: csecond03.cpp csecond03.h
	$(CC) $(CFLAG1) csecond03.cpp
csimpson1d.o: csimpson1d.cpp csimpson1d.h
	$(CC) $(CFLAG1) csimpson1d.cpp
ctrapecio1d.o: ctrapecio1d.cpp ctrapecio1d.h
	$(CC) $(CFLAG1) ctrapecio1d.cpp
cvelocity1d.o: cvelocity1d.cpp cvelocity1d.h
	$(CC) $(CFLAG1) cvelocity1d.cpp
cvelocity1d0.o: cvelocity1d0.cpp cvelocity1d0.h
	$(CC) $(CFLAG1) cvelocity1d0.cpp
dataread.o: dataread.cpp dataread.h
	$(CC) $(CFLAG1) dataread.cpp
dirichlet00.o: dirichlet00.cpp dirichlet00.h
	$(CC) $(CFLAG1) dirichlet00.cpp
dirichlet20.o: dirichlet20.cpp dirichlet20.h
	$(CC) $(CFLAG1) dirichlet20.cpp
dirichlet21.o: dirichlet21.cpp dirichlet21.h
	$(CC) $(CFLAG1) dirichlet21.cpp
dirichlet22.o: dirichlet22.cpp dirichlet22.h
	$(CC) $(CFLAG1) dirichlet22.cpp
dirichlet22z.o: dirichlet22z.cpp dirichlet22z.h
	$(CC) $(CFLAG1) dirichlet22z.cpp
dirichlet23.o: dirichlet23.cpp dirichlet23.h
	$(CC) $(CFLAG1) dirichlet23.cpp
elmat1d2gdl02.o: elmat1d2gdl02.cpp elmat1d2gdl02.h
	$(CC) $(CFLAG1) elmat1d2gdl02.cpp
elmat1d2gdl03.o: elmat1d2gdl03.cpp elmat1d2gdl03.h
	$(CC) $(CFLAG1) elmat1d2gdl03.cpp
elvec1d2gdl02.o: elvec1d2gdl02.cpp elvec1d2gdl02.h
	$(CC) $(CFLAG1) elvec1d2gdl02.cpp
ensamb30.o: ensamb30.cpp ensamb30.h
	$(CC) $(CFLAG1) ensamb30.cpp
ensmat.o: ensmat.cpp ensmat.h
	$(CC) $(CFLAG1) ensmat.cpp
ensvec.o: ensvec.cpp ensvec.h
	$(CC) $(CFLAG1) ensvec.cpp
error02.o: error02.cpp error02.h
	$(CC) $(CFLAG1) error02.cpp
fprint11.o: fprint11.cpp fprint11.h
	$(CC) $(CFLAG1) fprint11.cpp
fprint12.o: fprint12.cpp fprint12.h
	$(CC) $(CFLAG1) fprint12.cpp
fprint13.o: fprint13.cpp fprint13.h
	$(CC) $(CFLAG1) fprint13.cpp
fprint14.o: fprint14.cpp fprint14.h
	$(CC) $(CFLAG1) fprint14.cpp
fprint15.o: fprint15.cpp fprint15.h
	$(CC) $(CFLAG1) fprint15.cpp
fprint16.o: fprint16.cpp fprint16.h
	$(CC) $(CFLAG1) fprint16.cpp
fprint17.o: fprint17.cpp fprint17.h
	$(CC) $(CFLAG1) fprint17.cpp
fprint18.o: fprint18.cpp fprint18.h
	$(CC) $(CFLAG1) fprint18.cpp
fprint19.o: fprint19.cpp fprint19.h
	$(CC) $(CFLAG1) fprint19.cpp
fprint20.o: fprint20.cpp fprint20.h
	$(CC) $(CFLAG1) fprint20.cpp
globalmat02.o: globalmat02.cpp globalmat02.h
	$(CC) $(CFLAG1) globalmat02.cpp
globalmat12.o: globalmat12.cpp globalmat12.h
	$(CC) $(CFLAG1) globalmat12.cpp
globalmat13.o: globalmat13.cpp globalmat13.h
	$(CC) $(CFLAG1) globalmat13.cpp
globalmat14.o: globalmat14.cpp globalmat14.h
	$(CC) $(CFLAG1) globalmat14.cpp
globalvec02.o: globalvec02.cpp globalvec02.h
	$(CC) $(CFLAG1) globalvec02.cpp
globalvec03.o: globalvec03.cpp globalvec03.h
	$(CC) $(CFLAG1) globalvec03.cpp
globalvec11.o: globalvec11.cpp globalvec11.h
	$(CC) $(CFLAG1) globalvec11.cpp
globalvec12.o: globalvec12.cpp globalvec12.h
	$(CC) $(CFLAG1) globalvec12.cpp
globalvec13.o: globalvec13.cpp globalvec13.h
	$(CC) $(CFLAG1) globalvec13.cpp
localiza00.o: localiza00.cpp localiza00.h
	$(CC) $(CFLAG1) localiza00.cpp
localiza01.o: localiza01.cpp localiza01.h
	$(CC) $(CFLAG1) localiza01.cpp
mat3d11.o: mat3d11.cpp mat3d11.h
	$(CC) $(CFLAG1) mat3d11.cpp
mat3d12.o: mat3d12.cpp mat3d12.h
	$(CC) $(CFLAG1) mat3d12.cpp
mat3d13.o: mat3d13.cpp mat3d13.h
	$(CC) $(CFLAG1) mat3d13.cpp
matvec11.o: matvec11.cpp matvec11.h
	$(CC) $(CFLAG1) matvec11.cpp
matvec12.o: matvec12.cpp matvec12.h
	$(CC) $(CFLAG1) matvec12.cpp
matvecreduce.o: matvecreduce.cpp matvecreduce.h
	$(CC) $(CFLAG1) matvecreduce.cpp
meshcopy.o: meshcopy.cpp meshcopy.h
	$(CC) $(CFLAG1) meshcopy.cpp
meshgen00.o: meshgen00.cpp meshgen00.h
	$(CC) $(CFLAG1) meshgen00.cpp
meshgen01.o: meshgen01.cpp meshgen01.h
	$(CC) $(CFLAG1) meshgen01.cpp
meshgen01b.o:meshgen01b.cpp meshgen01b.h
	$(CC) $(CFLAG1) meshgen01b.cpp
meshgen01c.o: meshgen01c.cpp meshgen01c.h
	$(CC) $(CFLAG1) meshgen01c.cpp
meshgen02.o: meshgen02.cpp meshgen02.h
	$(CC) $(CFLAG1) meshgen02.cpp
meshgen03.o: meshgen03.cpp meshgen03.h
	$(CC) $(CFLAG1) meshgen03.cpp
meshgen2d1d.o: meshgen2d1d.cpp meshgen2d1d.h
	$(CC) $(CFLAG1) meshgen2d1d.cpp
meshmark01.o: meshmark01.cpp meshmark01.h
	$(CC) $(CFLAG1) meshmark01.cpp
meshref01.o: meshref01.cpp meshref01.h
	$(CC) $(CFLAG1) meshref01.cpp
meshref02.o: meshref02.cpp meshref02.h
	$(CC) $(CFLAG1) meshref02.cpp
negative.o: negative.cpp negative.h
	$(CC) $(CFLAG1) negative.cpp
norm.o: norm.cpp norm.h
	$(CC) $(CFLAG1) norm.cpp
optioneuro01.o: optioneuro01.cpp optioneuro01.h
	$(CC) $(CFLAG1) optioneuro01.cpp
optioneuro02.o: optioneuro02.cpp optioneuro02.h
	$(CC) $(CFLAG1) optioneuro02.cpp
positive.o: positive.cpp positive.h
	$(CC) $(CFLAG1) positive.cpp
prolong.o: prolong.cpp prolong.h
	$(CC) $(CFLAG1) prolong.cpp
reft100.o: reft100.cpp reft100.h
	$(CC) $(CFLAG1) reft100.cpp
reft101.o: reft101.cpp reft101.h
	$(CC) $(CFLAG1) reft101.cpp
reft110.o: reft110.cpp reft110.h
	$(CC) $(CFLAG1) reft110.cpp
reft111.o: reft111.cpp reft111.h
	$(CC) $(CFLAG1) reft111.cpp
remesh02.o: remesh02.cpp remesh02.h
	$(CC) $(CFLAG1) remesh02.cpp
remesh03.o: remesh03.cpp remesh03.h
	$(CC) $(CFLAG1) remesh03.cpp
remesh04.o: remesh04.cpp remesh04.h
	$(CC) $(CFLAG1) remesh04.cpp
util01.o: util01.cpp util01.h
	$(CC) $(CFLAG1) util01.cpp
util02.o: util02.cpp util02.h
	$(CC) $(CFLAG1) util02.cpp
util03.o: util03.cpp util03.h
	$(CC) $(CFLAG1) util03.cpp
vec3d11.o: vec3d11.cpp vec3d11.h
	$(CC) $(CFLAG1) vec3d11.cpp
vec3d12.o: vec3d12.cpp vec3d12.h
	$(CC) $(CFLAG1) vec3d12.cpp

clean:
	touch mef.exe
	rm mef.exe *.o

