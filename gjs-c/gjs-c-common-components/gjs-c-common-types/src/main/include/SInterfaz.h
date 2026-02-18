#ifndef _ORG_GJS_C_CC_C_COMMON_SINTERFAZ_H
#define _ORG_GJS_C_CC_C_COMMON_SINTERFAZ_H





#include <SDefPrimitiva.h>
#include <SSecuenciaPtr.h>



typedef struct 
{
	unsigned long	ulId;
	char *			p_cNombre;

	SSecuenciaPtr *	p_secPrimitivas;


} SInterfaz; 



SInterfaz * SIntfzCrear ( unsigned long ulId, const char * p_cNombre );

void SIntfzDestruir ( SInterfaz ** p_p_intrfzObj );

int SIntfzEsValido ( SInterfaz * p_intrfzObj );

unsigned long SIntfzId ( SInterfaz * p_intrfzObj );
const char * SIntfzNombre ( SInterfaz * p_intrfzObj );

int SIntfzCrearPrimitiva ( SInterfaz * p_intrfzObj, const char * p_cNombre, int iTipo );
int SIntfzNumPrimitivas ( SInterfaz * p_intrfzObj );
SDefPrimitiva * SIntfzPrimitiva ( SInterfaz * p_intrfzObj, int iPrimitiva );



#endif
