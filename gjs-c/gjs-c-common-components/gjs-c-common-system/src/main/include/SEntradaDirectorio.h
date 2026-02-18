#ifndef _ORG_GJS_C_CC_SENTRADADIRECTORIO_H
#define _ORG_GJS_C_CC_SENTRADADIRECTORIO_H




	/*



#include <SCadena.h>
//#include <SPath.h>
//#include <SFichero.h>
#include <SDirectorio.h>









typedef struct     
{
	SCadena *		p_cadEntrada;
	SDirectorio * 	p_dirInfo;
	
} SEntradaDirectorio;

SEntradaDirectorio ( const char * _ORG_GJS_C_CC_p_cEntrada );
SEntradaDirectorio ( SCadena * _ORG_GJS_C_CC_p_cadEntrada );

~SEntradaDirectorio ();

SCadena * Entrada ();
const char * Valor ();
SPath * Ruta ();

int EsSubdirectorio ();
int EsFichero ();

SFichero * Fichero ();
SDirectorio * Subdirectorio (); 

SDirectorio * Directorio (); 
void EstablecerDirectorio ( SDirectorio * _ORG_GJS_C_CC_p_dirInfo );

int EsIgual ( SEntradaDirectorio * _ORG_GJS_C_CC_p_edirObj );
int EsMenor ( SEntradaDirectorio * _ORG_GJS_C_CC_p_edirObj );
int EsMayor ( SEntradaDirectorio * _ORG_GJS_C_CC_p_edirObj );

*/

#endif

