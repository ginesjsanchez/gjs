
#ifndef _ORG_GJS_C_CC_C_COMMON_SARBOLBINPTR_H
#define _ORG_GJS_C_CC_C_COMMON_SARBOLBINPTR_H










#include <SNodoBinPtr.h>




typedef struct
{
	SNodoBinPtr * p_nodbpRaiz;
	SNodoBinPtr * p_nodbpActual;

} SArbolBinPtr;




SArbolBinPtr * SArbBinPtrCrear ();

void SArbBinPtrDestruir ( SArbolBinPtr ** p_p_arbbObj );

SNodoBinPtr * SArbBinPtrRaiz ( SArbolBinPtr * p_arbbpObj );

int SArbBinPtrEstablecerRaiz ( SArbolBinPtr * p_arbbpObj, SNodoBinPtr * p_nodbpObj );

int SArbBinPtrEstaVacio ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrNiveles ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrNumNodos ( SArbolBinPtr * p_arbbpObj );

void SArbBinPtrVaciar ( SArbolBinPtr * p_arbbpObj );

SNodoBinPtr * SArbBinPtrActual ( SArbolBinPtr * p_arbbpObj );

SNodoBinPtr * SArbBinPtrPadre ( SArbolBinPtr * p_arbbpObj );
SNodoBinPtr * SArbBinPtrHijoDer ( SArbolBinPtr * p_arbbpObj );
SNodoBinPtr * SArbBinPtrHijoIzq ( SArbolBinPtr * p_arbbpObj );

int SArbBinPtrTienePadre ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHijos ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHermano ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrEsHijoIzqDelPadre ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrEsHijoDerDelPadre ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHijoIzq ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHijoDer ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHermanoIzq ( SArbolBinPtr * p_arbbpObj );
int SArbBinPtrTieneHermanoDer ( SArbolBinPtr * p_arbbpObj );

void SArbBinPtrMoverARaiz ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAPadre ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAHijoIzq ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAHijoDer ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAHermano ( SArbolBinPtr * p_arbbpObj );

void SArbBinPtrMoverAPrimPreorden ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverASigPreorden ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAAntPreorden ( SArbolBinPtr * p_arbbpObj );
void SArbBinPtrMoverAUltPreorden ( SArbolBinPtr * p_arbbpObj );

void SArbBinPtrDesposicionar ( SArbolBinPtr * p_arbbpObj );
int	SArbBinPtrEstaPosicionado ( SArbolBinPtr * p_arbbpObj );

int SArbBinPtrEnraizar ( SArbolBinPtr * p_arbbpObj, SNodoBinPtr * p_nodbpObj );

int SArbBinPtrVerificar ( SArbolBinPtr * p_arbbpObj, int iCorregir );


#endif



