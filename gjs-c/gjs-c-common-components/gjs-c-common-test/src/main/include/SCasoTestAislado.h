#ifndef _ORG_GJS_C_CC_C_TEST_CASOTESTAISLADO_H
#define _ORG_GJS_C_CC_C_TEST_CASOTESTAISLADO_H

#include <Funciones.h>

#include <SCasoTest.h>


typedef struct
{
	SCasoTest * p_caststObj;
	int			iCodigo;

} SCasoTestAislado;

SCasoTestAislado * SCasTstaCrear ( const char * p_cId, PFUNINTV p_fTest, int iCodigoEsperado );
void SCasTstaDestruir ( SCasoTestAislado ** p_p_caststObj );

int SCasTstaEjecutar ( SCasoTestAislado * p_caststObj );


#endif