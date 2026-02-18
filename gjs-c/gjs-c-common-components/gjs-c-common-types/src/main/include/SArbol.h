#ifndef _ORG_GJS_C_CC_C_COMMON_SARBOL_H
#define _ORG_GJS_C_CC_C_COMMON_SARBOL_H











#include <SNodo.h>




typedef struct
{
	SNodo * p_nodRaiz;
	SNodo * p_nodActual;

} SArbol;



SArbol * SArbCrear ();

void SArbDestruir ( SArbol ** p_p_arbObj );

SNodo * SArbRaiz ( SArbol * p_arbObj );

int SArbEstablecerRaiz ( SArbol * p_arbObj, SNodo * p_nodObj );

int SArbEstaVacio ( SArbol * p_arbObj );
int SArbNiveles ( SArbol * p_arbObj );
int SArbNumNodos ( SArbol * p_arbObj );

int SArbVaciar ( SArbol * p_arbObj );

SNodo * SArbActual ( SArbol * p_arbObj );

void SArbMoverARaiz ( SArbol * p_arbObj );
void SArbMoverAPadre ( SArbol * p_arbObj );
void SArbMoverAHijo ( SArbol * p_arbObj, int iHijo );
void SArbMoverAPrimHijo ( SArbol * p_arbObj );
void SArbMoverAUltHijo ( SArbol * p_arbObj );
void SArbMoverAPrimHermano ( SArbol * p_arbObj );
void SArbMoverASigHermano ( SArbol * p_arbObj );
void SArbMoverAAntHermano ( SArbol * p_arbObj );
void SArbMoverAUltHermano ( SArbol * p_arbObj );

void SArbMoverAPrimPreorden ( SArbol * p_arbObj );
void SArbMoverASigPreorden ( SArbol * p_arbObj );
void SArbMoverAAntPreorden ( SArbol * p_arbObj );
void SArbMoverAUltPreorden ( SArbol * p_arbObj );

void SArbDesposicionar ( SArbol * p_arbObj );
int	SArbEstaPosicionado ( SArbol * p_arbObj );

int SArbEnraizar ( SArbol * p_arbObj, SNodo * p_nodObj );

int SArbVerificar ( SArbol * p_arbObj, int iCorregir );




#endif

