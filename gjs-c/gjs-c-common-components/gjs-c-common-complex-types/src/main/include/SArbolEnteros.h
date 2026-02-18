#ifndef _ORG_GJS_C_CC_SARBOLENTEROS_H
#define _ORG_GJS_C_CC_SARBOLENTEROS_H













#include <SArbol.h>



typedef struct 
{
	SArbol * p_arbObj;
	
} SArbolEnteros;



SArbolEnteros * SArbEntCrear ();

void SArbEntDestruir ( SArbolEnteros ** p_p_arbObj );

int SArbEntRaiz ( SArbolEnteros * p_arbObj );

int SArbEntEstablecerRaiz ( SArbolEnteros * p_arbObj, int iValor );

int SArbEntEstaVacio ( SArbolEnteros * p_arbObj );
int SArbEntNiveles ( SArbolEnteros * p_arbObj );
int SArbEntNumNodos ( SArbolEnteros * p_arbObj );

int SArbEntVaciar ( SArbolEnteros * p_arbObj );

int SArbEntActual ( SArbolEnteros * p_arbObj );
int SArbEntEstActual ( SArbolEnteros * p_arbObj, int iValor );

void SArbEntMoverARaiz ( SArbolEnteros * p_arbObj );
void SArbEntMoverAPadre ( SArbolEnteros * p_arbObj );
void SArbEntMoverAHijo ( SArbolEnteros * p_arbObj, int iHijo );
void SArbEntMoverAPrimHijo ( SArbolEnteros * p_arbObj );
void SArbEntMoverAUltHijo ( SArbolEnteros * p_arbObj );
void SArbEntMoverAPrimHermano ( SArbolEnteros * p_arbObj );
void SArbEntMoverASigHermano ( SArbolEnteros * p_arbObj );
void SArbEntMoverAAntHermano ( SArbolEnteros * p_arbObj );
void SArbEntMoverAUltHermano ( SArbolEnteros * p_arbObj );

void SArbEntMoverAPrimPreorden ( SArbolEnteros * p_arbObj );
void SArbEntMoverASigPreorden ( SArbolEnteros * p_arbObj );
void SArbEntMoverAAntPreorden ( SArbolEnteros * p_arbObj );
void SArbEntMoverAUltPreorden ( SArbolEnteros * p_arbObj );

void SArbEntDesposicionar ( SArbolEnteros * p_arbObj );
int	SArbEntEstaPosicionado ( SArbolEnteros * p_arbObj );

int SArbEntEnraizar ( SArbolEnteros * p_arbObj, int iValor );

int SArbEntVerificar ( SArbolEnteros * p_arbObj, int iCorregir );




#endif

