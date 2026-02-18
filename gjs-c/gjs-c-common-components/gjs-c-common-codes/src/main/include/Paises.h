
#ifndef _ORG_GJS_C_CC_PAISES_H
#define _ORG_GJS_C_CC_PAISES_H





#define PAIS_NINGUNO				0

#define PAIS_ESPANA					724
#define PAIS_PORTUGAL				620



#define PAIS_COD_ESPANA				"ESP"
#define PAIS_COD_PORTUGAL			"PRT"



#define PAIS_TXT_ESPANA				"España"
#define PAIS_TXT_PORTUGAL			"Portugal"






const char * PaisLiteral ( int iId );
const char * PaisCodigo ( int iId );
int PaisId ( const char * p_cLit );
int PaisIdPorCodigo ( const char * p_cCod );
int PaisEsValido ( int iId );





#endif
