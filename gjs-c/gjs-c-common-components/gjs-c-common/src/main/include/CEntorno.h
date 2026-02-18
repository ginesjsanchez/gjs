#ifndef _ORG_GJS_C_CC_C_ENTORNO_H
#define _ORG_GJS_C_CC_C_ENTORNO_H


#include <CCommon.h>



/* Algunas funciones generales de configuración del entorno: */
int EntInicializar ( int iConsola, const char * p_cNombre, int iVersion, int iSubversion );
#if ( defined ( WIN ) )
int EntInicializarExt ( int iConsola, const char * p_cNombre, int iVersion, int iSubversion, int iRevision, unsigned long ulFecha, const char * p_cDirTemporal, int iVaciarDirTemporal );
#else
int EntInicializarExt ( int iConsola, const char * p_cNombre, int iVersion, int iSubversion, int iRevision, unsigned long ulFecha, const char * p_cDirTemporal, const char * p_cNomProceso, int iVaciarDirTemporal );
#endif

void EntFinalizar ();

int EntEstaInicializado ();


const char * EntDirectorioDatos ();
const char * EntDirectorioSeguridad ();
const char * EntDirectorioLog ();

void EntEstablecerDirectorioDatos ( const char * p_cDir );
void EntEstablecerDirectorioSeguridad ( const char * p_cDir );
void EntEstablecerDirectorioLog ( const char * p_cDir );
void EntEstablecerDirectorioDatosExt ( const char * p_cDir, int iVaciar, int iCrear );
void EntEstablecerDirectorioSeguridadExt ( const char * p_cDir, int iVaciar, int iCrear );
void EntEstablecerDirectorioLogExt ( const char * p_cDir, int iVaciar, int iCrear );




#endif
