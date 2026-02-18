
#ifndef _ORG_GJS_C_CC_SARBOLCONECTIVO_H
#define _ORG_GJS_C_CC_SARBOLCONECTIVO_H




#include <Funciones.h>

#include <SConector.h>
#include <SNodoConector.h>





typedef struct
{
	SNodoConector * p_nodcRaiz;			
	SNodoConector *	p_nodcActual;		
	
} SArbolConectivo;


SArbolConectivo * SArbCnctCrear ();

void SArbCnctDestruir ( SArbolConectivo ** p_p_arbcObj );

SNodoConector * SArbCnctRaiz ( SArbolConectivo * p_arbcObj );

int SArbCnctEstablecerRaiz ( SArbolConectivo * p_arbcObj, SNodoConector * p_nodcObj );

int SArbCnctEstaVacio ( SArbolConectivo * p_arbcObj );

int SArbCnctValorActual ( SArbolConectivo * p_arbcObj );
SNodoConector * SArbCnctActual ( SArbolConectivo * p_arbcObj );

SNodoConector * SArbCnctPadre ( SArbolConectivo * p_arbcObj );   
int SArbCnctValorPadre ( SArbolConectivo * p_arbcObj );

int SArbCnctTieneDatos ( SArbolConectivo * p_arbcObj );
int SArbCnctTieneDatosIzq ( SArbolConectivo * p_arbcObj );
int SArbCnctTieneDatosDer ( SArbolConectivo * p_arbcObj );
void * SArbCnctDatosIzq ( SArbolConectivo * p_arbcObj );
void * SArbCnctDatosDer( SArbolConectivo * p_arbcObj );

int SArbCnctValorHijoDer ( SArbolConectivo * p_arbcObj );
int SArbCnctHijoDerEsConector ( SArbolConectivo * p_arbcObj );
SNodoConector * SArbCnctHijoDer ( SArbolConectivo * p_arbcObj );
void * SArbCnctHijoDerDatos ( SArbolConectivo * p_arbcObj );

int SArbCnctValorHijoIzq ( SArbolConectivo * p_arbcObj );
int SArbCnctHijoIzqEsConector ( SArbolConectivo * p_arbcObj );
SNodoConector * SArbCnctHijoIzq ( SArbolConectivo * p_arbcObj );
void * SArbCnctHijoIzqDatos ( SArbolConectivo * p_arbcObj );

// NOTA: Por defecto no elimina las hojas ya que desconoce su tipo. Hay que pasarle un procedimiento que lo haga
void SArbCnctVaciar ( SArbolConectivo * p_arbcObj );
void SArbCnctVaciarExt ( SArbolConectivo * p_arbcObj, PPRCPPV fDestruccion );

int SArbCnctTienePadre ( SArbolConectivo * p_arbcObj );
int SArbCnctTieneHijos ( SArbolConectivo * p_arbcObj );
int SArbCnctTieneHijoIzq ( SArbolConectivo * p_arbcObj );
int SArbCnctTieneHijoDer ( SArbolConectivo * p_arbcObj );

int SArbCnctEstaEnRaiz ( SArbolConectivo * p_arbcObj );
int SArbCnctEstaEnCopa ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverARaiz ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAPadre ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAHijoIzq ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAHijoDer ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAHermano ( SArbolConectivo * p_arbcObj );

void SArbCnctMoverAPrimPreorden ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverASigPreorden ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAAntPreorden ( SArbolConectivo * p_arbcObj );
void SArbCnctMoverAUltPreorden ( SArbolConectivo * p_arbcObj );

void SArbCnctDesposicionar ( SArbolConectivo * p_arbcObj );
int	SArbCnctEstaPosicionado ( SArbolConectivo * p_arbcObj );

int SArbCnctEnraizar ( SArbolConectivo * p_arbcObj, SNodoConector * p_nodcObj );
int SArbCnctEnraizarDatos ( SArbolConectivo * p_arbcObj, void * p_vDatos );




#endif



