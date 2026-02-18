
#ifndef _ORG_GJS_C_CC_SNODOCONECTOR_H
#define _ORG_GJS_C_CC_SNODOCONECTOR_H





#include <SConector.h>








typedef struct
{
	SConector * p_cnctPadre;
	SConector * p_cnctHijoIzq;
	SConector * p_cnctHijoDer;
	
	int			iValor;

} SNodoConector;



SNodoConector * SNodCnctCrearDef ();
SNodoConector * SNodCnctCrear ( int iValor );

void SNodCnctDestruir ( SNodoConector ** p_p_nodcObj );

int SNodCnctEsValido ( SNodoConector * p_nodcObj ); 

int SNodCnctValor ( SNodoConector * p_nodcObj );
int SNodCnctEstablecerValor ( SNodoConector * p_nodcObj, int iValor );

void * SNodCnctPadre ( SNodoConector * p_nodcObj );
void * SNodCnctHijoDer ( SNodoConector * p_nodcObj );
void * SNodCnctHijoIzq ( SNodoConector * p_nodcObj );
SConector * SNodCnctConectorPadre ( SNodoConector * p_nodcObj );
SConector * SNodCnctConectorHijoDer ( SNodoConector * p_nodcObj );
SConector * SNodCnctConectorHijoIzq ( SNodoConector * p_nodcObj );
int SNodCnctTipoPadre ( SNodoConector * p_nodcObj );
int SNodCnctTipoHijoIzq ( SNodoConector * p_nodcObj );
int SNodCnctTipoHijoDer ( SNodoConector * p_nodcObj );

int SNodCnctTienePadre ( SNodoConector * p_nodcObj );
int SNodCnctTieneHijos ( SNodoConector * p_nodcObj );
int SNodCnctTieneHijoIzq ( SNodoConector * p_nodcObj );
int SNodCnctTieneHijoDer ( SNodoConector * p_nodcObj );

int SNodCnctEmpadronar ( SNodoConector * p_nodcObj, void * p_vPadre, int iTipo );
void SNodCnctDesempadronar ( SNodoConector * p_nodcObj );
void SNodCnctLimpiarHijoIzq ( SNodoConector * p_nodcObj );
void SNodCnctLimpiarHijoDer ( SNodoConector * p_nodcObj );
int SNodCnctEstHijoIzq ( SNodoConector * p_nodcObj, void * p_vHijo, int iTipo );
int SNodCnctEstHijoDer ( SNodoConector * p_nodcObj, void * p_vHijo, int iTipo );
int SNodCnctIntercambiarHijos ( SNodoConector * p_nodcObj );
void SNodCnctLimpiarHijos ( SNodoConector * p_nodcObj );

int	SNodCnctEsHijo ( SNodoConector * p_nodcObj, void * p_vHijo );
int	SNodCnctEsHijoIzq ( SNodoConector * p_nodcObj, void * p_vHijo );
int	SNodCnctEsHijoDer ( SNodoConector * p_nodcObj, void * p_vHijo );

SNodoConector * SNodCnctDuplicar ( SNodoConector * p_nodcObj );


 



#endif
