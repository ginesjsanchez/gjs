#ifndef _ORG_GJS_C_CC_SLISTAENTRADASEXT_H
#define _ORG_GJS_C_CC_SLISTAENTRADASEXT_H








#include <SListaPtr.h>
#include <SEntradaExt.h>



typedef struct
{
	SListaPtr * p_lisDatos;

} SListaEntradasExt;


SListaEntradasExt * SLisEtxCrear ();


void SLisEtxDestruir ( SListaEntradasExt ** p_p_lisObj );

int SLisEtxEsValida ( SListaEntradasExt * p_lisObj );
int SLisEtxEstaVacia ( SListaEntradasExt * p_lisObj );

int SLisEtxNumElementos ( SListaEntradasExt * p_lisObj );
int SLisEtxExiste ( SListaEntradasExt * p_lisObj, const char * p_cNombre );
SEntradaExt * SLisEtxBuscar ( SListaEntradasExt * p_lisObj, const char * p_cNombre );
SEntradaExt * SLisEtxElemento ( SListaEntradasExt * p_lisObj, int iElem );
const char * SLisEtxNombreElemento ( SListaEntradasExt * p_lisObj, int iElem );
const char * SLisEtxDefinicionElemento ( SListaEntradasExt * p_lisObj, int iElem );

int SLisEtxInsertar ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etrDatos );
int SLisEtxInsertarExt ( SListaEntradasExt * p_lisObj, const char * p_cNombre, const char * p_cDefinicion );

int SLisEtxEliminar ( SListaEntradasExt * p_lisObj, const char * p_cNombre );
int SLisEtxEliminarElem ( SListaEntradasExt * p_lisObj, int iElem );

int SLisEtxVaciar ( SListaEntradasExt * p_lisObj );

int	SLisEtxLiberacionMemoriaActivada ( SListaEntradasExt * p_lisObj );
void SLisEtxActivarLiberacionMemoria ( SListaEntradasExt * p_lisObj );
void SLisEtxDesactivarLiberacionMemoria ( SListaEntradasExt * p_lisObj );



#endif



