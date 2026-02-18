#ifndef _ORG_GJS_C_CC_CPP_ENTORNO_H
#define _ORG_GJS_C_CC_CPP_ENTORNO_H


#include <CppCommon.h>


using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


/* Algunas funciones generales de configuración del entorno: */
#if ( defined ( WIN ) )
bool EntInicializar ( bool bConsola, const string & sNombre, int iVersion, int iSubversion, int iRevision = 0, unsigned long ulFecha = 0, const string & sDirTemporal = "", bool bVaciarDirTemporal= false );
#else
bool EntInicializar ( bool bConsola, const string & sNombre, int iVersion, int iSubversion, int iRevision = 0, unsigned long ulFecha = 0, const string & sDirTemporal = "", const string & sNomProceso = "", bool bVaciarDirTemporal= false );
#endif

void EntFinalizar ();

bool EntEstaInicializado ();


const string * EntDirectorioDatos ();
const string * EntDirectorioSeguridad ();
const string * EntDirectorioLog ();

void EntEstablecerDirectorioDatos ( const string & sDir, bool bVaciar= false, bool bCrear= true );
void EntEstablecerDirectorioSeguridad ( const string & sDir, bool bVaciar= false, bool bCrear= true );
void EntEstablecerDirectorioLog ( const string & sDir, bool bVaciar= false, bool bCrear= true );





 			}
		}
	}
}


#endif
