
#ifndef _ORG_GJS_C_CC_SMENSAJES_H
#define _ORG_GJS_C_CC_SMENSAJES_H



// TODO: Cambiar a lista ordenada
#include <SListaPtr.h>
#include <SCadena.h>


typedef struct
{
	SListaPtr * p_lisMensajes;
	
} SMensajes;



SMensajes * SMsjCrear ();

void SMsjDestruir ( SMensajes ** p_p_msjObj );

int SMsjInsertar ( SMensajes * p_msjObj, unsigned long uiCodigo, SCadena * p_cadTexto );
int SMsjInsertarLit ( SMensajes * p_msjObj, unsigned long uiCodigo, const char * p_cTexto );

int SMsjExisteCodigo ( SMensajes * p_msjObj, unsigned long uiCodigo );
int SMsjNumMensajes ( SMensajes * p_msjObj );
SCadena * SMsjTexto ( SMensajes * p_msjObj, unsigned long uiCodigo );

void SMsjLimpiar ( SMensajes * p_msjObj );
int SMsjCargar ( SMensajes * p_msjObj, const char * p_cFichero );




#endif

