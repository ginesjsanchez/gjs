
#ifndef _ORG_GJS_C_CC_SARBOLBINENTEROS_H
#define _ORG_GJS_C_CC_SARBOLBINENTEROS_H












#include <SArbolBin.h>




typedef struct
{
	SArbolBin * p_arbbObj;
	
} SArbolBinEnteros;




SArbolBinEnteros * SArbBinEntCrear ();

void SArbBinEntDestruir ( SArbolBinEnteros ** p_p_arbbObj );

int SArbBinEntRaiz ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntEstablecerRaiz ( SArbolBinEnteros * p_arbbObj, int iValor );

int SArbBinEntEstaVacio ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntNiveles ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntNumNodos ( SArbolBinEnteros * p_arbbObj );

void SArbBinEntVaciar ( SArbolBinEnteros * p_arbbObj );

int SArbBinEntActual ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntEstActual ( SArbolBinEnteros * p_arbbObj, int iValor );

int SArbBinEntPadre ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntHijoDer ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntHijoIzq ( SArbolBinEnteros * p_arbbObj );

int SArbBinEntTienePadre ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHijos ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHermano ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntEsHijoIzqDelPadre ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntEsHijoDerDelPadre ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHijoIzq ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHijoDer ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHermanoIzq ( SArbolBinEnteros * p_arbbObj );
int SArbBinEntTieneHermanoDer ( SArbolBinEnteros * p_arbbObj );

void SArbBinEntMoverARaiz ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAPadre ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAHijoIzq ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAHijoDer ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAHermano ( SArbolBinEnteros * p_arbbObj );

void SArbBinEntMoverAPrimPreorden ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverASigPreorden ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAAntPreorden ( SArbolBinEnteros * p_arbbObj );
void SArbBinEntMoverAUltPreorden ( SArbolBinEnteros * p_arbbObj );

void SArbBinEntDesposicionar ( SArbolBinEnteros * p_arbbObj );
int	SArbBinEntEstaPosicionado ( SArbolBinEnteros * p_arbbObj );

int SArbBinEntEnraizar ( SArbolBinEnteros * p_arbbObj, int iValor );

int SArbBinEntVerificar ( SArbolBinEnteros * p_arbbObj, int iCorregir );


#endif



