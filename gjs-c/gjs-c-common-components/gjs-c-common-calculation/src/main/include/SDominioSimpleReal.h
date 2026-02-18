#ifndef _ORG_GJS_C_CC_DOMINIOSIMPLEREAL_H
#define _ORG_GJS_C_CC_DOMINIOSIMPLEREAL_H


#include <SExtremoDominioReal.h>



// TODO: Sin implementar



typedef struct
{
	SExtremoDominioReal * p_extA;
	SExtremoDominioReal * p_extB;

} SDominioSimpleReal;


SDominioSimpleReal * SDomSimRCrear ( double dValorA, double dValorB, int iIncluidoA, int iIncluidoB );
SDominioSimpleReal * SDomSimRCrearHastaInfinito ( double dValor, int iIncluido );
SDominioSimpleReal * SDomSimRCrearDesdeMenosInfinito ( double dValor, int iIncluido );
SDominioSimpleReal * SDomSimRCrearEjeReal ();
SDominioSimpleReal * SDomSimRCrearPuntoSingular ( double dValor );
SDominioSimpleReal * SDomSimRCrearExtremos ( SExtremoDominioReal * p_extA, SExtremoDominioReal * p_extB );
int SDomSimRDestruir ( SDominioSimpleReal ** p_p_domsObj );

int SDomSimREsValido ( SDominioSimpleReal * p_domsObj );

int SDomSimREsPuntoSingular ( SDominioSimpleReal * pdomsObj );
SExtremoDominioReal * SDomSimRA ( SDominioSimpleReal * pdomsObj );
SExtremoDominioReal * SDomSimRB ( SDominioSimpleReal * pdomsObj );

double SDomSimRValorA ( SDominioSimpleReal * pdomsObj );
int SDomSimREstaIncluidoA ( SDominioSimpleReal * p_domsObj );
int SDomSimREsMenosInfinitoA ( SDominioSimpleReal * p_domsObj );
double SDomSimRValorB ( SDominioSimpleReal * p_domsObj );
int SDomSimREstaIncluidoB ( SDominioSimpleReal * p_domsObj );
int SDomSimREsInfinitoB ( SDominioSimpleReal * p_domsObj );

int SDomSimREstaIncluido ( SDominioSimpleReal * p_domsObj, double dValor );
int SDomSimREstaIncluidoOrigen ( SDominioSimpleReal * p_domsObj );
int SDomSimREstaIncluidoInfinito ( SDominioSimpleReal * p_domsObj );
int SDomSimREstaIncluidoMenosInfinito ( SDominioSimpleReal * p_domsObj );

SDominioSimpleReal * SDomSimRDuplicar ( SDominioSimpleReal * p_domsObj );

#endif

