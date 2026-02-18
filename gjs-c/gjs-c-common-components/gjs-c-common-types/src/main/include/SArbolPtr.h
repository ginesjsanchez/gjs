#ifndef _ORG_GJS_C_CC_C_COMMON_SARBOLPTR_H
#define _ORG_GJS_C_CC_C_COMMON_SARBOLPTR_H




#include <SNodoPtr.h>




typedef struct
{
	SNodoPtr * p_nodRaiz;
	SNodoPtr * p_nodActual;

} SArbolPtr;





SArbolPtr * SArbPtrCrear ();

void SArbPtrDestruir ( SArbolPtr ** p_p_arbObj );

SNodoPtr * SArbPtrRaiz ( SArbolPtr * p_arbpObj );

int SArbPtrEstablecerRaiz ( SArbolPtr * p_arbpObj, SNodoPtr * p_nodpObj );

int SArbPtrEstaVacio ( SArbolPtr * p_arbpObj );
int SArbPtrNiveles ( SArbolPtr * p_arbpObj );
int SArbPtrNumNodos ( SArbolPtr * p_arbpObj );

int SArbPtrVaciar ( SArbolPtr * p_arbpObj );

SNodoPtr * SArbPtrActual ( SArbolPtr * p_arbpObj );

void SArbPtrMoverARaiz ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAPadre ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAHijo ( SArbolPtr * p_arbpObj, int iHijo );
void SArbPtrMoverAPrimHijo ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAUltHijo ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAPrimHermano ( SArbolPtr * p_arbpObj );
void SArbPtrMoverASigHermano ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAAntHermano ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAUltHermano ( SArbolPtr * p_arbpObj );

void SArbPtrMoverAPrimPreorden ( SArbolPtr * p_arbpObj );
void SArbPtrMoverASigPreorden ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAAntPreorden ( SArbolPtr * p_arbpObj );
void SArbPtrMoverAUltPreorden ( SArbolPtr * p_arbpObj );

void SArbPtrDesposicionar ( SArbolPtr * p_arbpObj );
int	SArbPtrEstaPosicionado ( SArbolPtr * p_arbpObj );

int SArbPtrEnraizar ( SArbolPtr * p_arbpObj, SNodoPtr * p_nodpObj );

int SArbPtrVerificar ( SArbolPtr * p_arbpObj, int iCorregir );




#endif

