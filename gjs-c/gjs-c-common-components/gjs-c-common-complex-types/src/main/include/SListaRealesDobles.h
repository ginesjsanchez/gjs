#ifndef _ORG_GJS_C_CC_SLISTAREALESDOBLE_H
#define _ORG_GJS_C_CC_SLISTAREALESDOBLE_H








#include <SLista.h>



typedef struct
{
	SLista * p_lisDatos;

} SListaRealesDobles;





SListaRealesDobles * SLisRealdCrear ();


void SLisRealdDestruir ( SListaRealesDobles ** p_p_lisObj );

int SLisRealdEsValida ( SListaRealesDobles * p_lisObj );
int SLisRealdEstaVacia ( SListaRealesDobles * p_lisObj );

// Operaciones sin cursor:
int SLisRealdNumElementos ( SListaRealesDobles * p_lisObj );
double SLisRealdElemento ( SListaRealesDobles * p_lisObj, int iElem );

int SLisRealdInsertarElem ( SListaRealesDobles * p_lisObj, int iPosAnt, double dDato );
int SLisRealdInsertarAlInicio ( SListaRealesDobles * p_lisObj, double dDato );
int SLisRealdInsertarAlFinal ( SListaRealesDobles * p_lisObj, double dDato );

int SLisRealdEliminarElem ( SListaRealesDobles * p_lisObj, int iElem );

int SLisRealdVaciar ( SListaRealesDobles * p_lisObj );

// Operaciones dependientes del cursor:
int SLisRealdPosicion ( SListaRealesDobles * p_lisObj );
double SLisRealdActual ( SListaRealesDobles * p_lisObj );

void SLisRealdInicio ( SListaRealesDobles * p_lisObj );
void SLisRealdFinal ( SListaRealesDobles * p_lisObj );
void SLisRealdSiguiente ( SListaRealesDobles * p_lisObj );
void SLisRealdAnterior ( SListaRealesDobles * p_lisObj );
void SLisRealdMoverA ( SListaRealesDobles * p_lisObj, int iElem );
void SLisRealdDeposicionar ( SListaRealesDobles * p_lisObj );

int SLisRealdEsNulo ( SListaRealesDobles * p_lisObj );
int SLisRealdEstaEnFinal ( SListaRealesDobles * p_lisObj );
int SLisRealdEstaEnIncio ( SListaRealesDobles * p_lisObj );

int SLisRealdInsertar ( SListaRealesDobles * p_lisObj, double dDato );
int SLisRealdInsertarDelante ( SListaRealesDobles * p_lisObj, double dDato );
int SLisRealdInsertarDetras ( SListaRealesDobles * p_lisObj, double dDato );
int SLisRealdEliminar ( SListaRealesDobles * p_lisObj );

int SLisRealdExiste ( SListaRealesDobles * p_lisObj, double dDato );



#endif



