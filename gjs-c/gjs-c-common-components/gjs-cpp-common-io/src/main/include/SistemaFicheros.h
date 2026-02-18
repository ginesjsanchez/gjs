/******************************************************************************/
/*                             SistemaFicheros.h                              */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene los prototipos de algunas rutinas de      */
/* de carácter general de operaciones con el sistema de ficheros.             */
/* Mantiene un objeto global privado de clase CSistemaFicheros que puede      */
/* utilizarse para moverse por el árbol de directorios.                       */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_SISTEMAFICHEROS_H
#define _ORG_GJS_C_CC_CPP_SISTEMAFICHEROS_H


#include <string>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


bool SisEsDirectorioValido ( const string & sDirectorio );
bool SisEsSubdirectorioValido ( const string & sSubdirectorio );
bool SisEsFicheroValido ( const string & sFichero );
int SisFicheroTieneExtension ( const string & sFichero );

int SisDirectorioNumSubdirectorios ( const string & sDirectorio );
string SisDirectorioSubdirectorio ( const string & sDirectorio, int iNivel = -1 );
string SisDirectorioSuperior ( const string & sDirectorio );

string SisFicheroExtension ( const string & sFichero );
string SisFicheroNombre ( const string & sFichero );
string SisComponerFichero ( const string & sNombre, const string & sExtension );

string SisRutaDirectorio ( const string & sRuta );
string SisRutaFichero ( const string & sRuta );
int SisRutaNumSubdirectorios ( const string & sRuta );
string SisRutaSubdirectorio ( const string & sRuta, int iNivel = -1 );
string SisComponerRuta ( const string & sDirectorio, const string & sFichero, int iDirActualPorDef = 1 );
string SisComponerRutaExt ( const string & sDirectorio, const string & sSubdirectorio, const string & sFichero, int iDirActualPorDef = 1 );

string SisNormalizarRuta ( string & sRuta );

bool SisEsRutaValida ( const string & sRuta );


string SisDirectorioActual ();
bool SisEstDirectorioActual ( const string & sDirectorio );

string SisCadenaDirectorioSistema ();

bool SisExisteFichero ( const string & sRuta );
bool SisExisteFicheroExt ( const string & sDirectorio, const string & sFichero );
bool SisExisteDirectorio ( const string & sRuta );
bool SisExisteDirectorioExt ( const string & sDirectorio, const string & sSubdirectorio );

bool SisCrearFichero ( const string & sRuta );
bool SisCrearFicheroExt ( const string & sDirectorio, const string & sFichero );
bool SisCrearDirectorio ( const string & sDirectorio );
bool SisCrearDirectorioExt ( const string & sDirectorio, const string & sSubdirectorio );

bool SisEliminarFichero ( const string & sRuta );
bool SisEliminarFicheroExt ( const string & sDirectorio, const string & sFichero );
string SisMascaraBusquedaEnDirectorio ( const string & sDirectorio );
bool SisEliminarDirectorio ( const string & sDirectorio );
bool SisEliminarDirectorioExt ( const string & sDirectorio, const string & sSubdirectorio );
bool SisVaciarDirectorio ( const string & sDirectorio );
bool SisVaciarDirectorioExt ( const string & sDirectorio, const string & sSubdirectorio );
bool SisCopiarFichero ( const string & sRutaOrig, const string & sRutaDest, bool bEliminar = 1 );
bool SisCopiarFicheroExt ( const string & sDirOrig, const string & sFicOrig, const string & sDirDest, const string & sFicDest = NULL, bool bEliminar = 1 );
bool SisMoverFichero ( const string & sRutaOrig, const string & sRutaDest, bool bEliminar = 1 );
bool SisMoverFicheroExt ( const string & sDirOrig, const string & sFicOrig, const string & sDirDest, const string & sFicDest = NULL, bool bEliminar = 1 );

bool SisRutaComprimida ( const string & sRuta );
bool SisRutaEncriptada ( const string & sRuta );
bool SisRutaOculta ( const string & sRuta );
bool SisFicheroEsAccesible ( const string & sRuta );
bool SisRutaDeSoloLectura ( const string & sRuta );
bool SisRutaDelSistema ( const string & sRuta );
bool SisFicheroEsTemporal ( const string & sRuta );
bool SisFicheroAsociadoAAplicacion ( const string & sRuta );
bool SisFicheroConOptimizacionEspacial ( const string & sRuta );

bool SisRutaDesactivarModoSoloLectura ( const string & sRuta );


bool SisEsFicheroC ( const string & sRuta );
bool SisEsFicheroCodigoC ( const string & sRuta );
bool SisEsFicheroCabeceraC ( const string & sRuta );
bool SisEsFicheroXML ( const string & sRuta );
bool SisEsFicheroHTML ( const string & sRuta );
bool SisEsFicheroSHP ( const string & sRuta );
bool SisEsFicheroDBF ( const string & sRuta );


		
 			}
		}
	}
}

#endif

