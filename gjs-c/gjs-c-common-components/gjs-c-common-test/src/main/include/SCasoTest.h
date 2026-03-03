#ifndef _ORG_GJS_C_CC_C_TEST_CASOTEST_H
#define _ORG_GJS_C_CC_C_TEST_CASOTEST_H

#include <ResultadoCasoTest.h>
#include <Funciones.h>




typedef struct
{
	char * p_cIdCaso;
	PFUNINTV p_fTestCaso;

} SCasoTest;

SCasoTest * SCasTstCrear ( const char * p_cId, PFUNINTV p_fTest );
void SCasTstDestruir ( SCasoTest ** p_p_caststObj );
		
char * SCasTstObtenerId ( SCasoTest * p_caststObj );
int SCasTstEjecutar ( SCasoTest * p_caststObj );


#endif