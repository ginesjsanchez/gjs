/******************************************************************************/
/*                                Version.cpp                                */
/*----------------------------------------------------------------------------*/
/* Librería:  Aplicacion                                                      */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la clase de     */
/* datos Version.                                                            */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "Version.h"

#include "CommonSupportConfig.h"








using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {




Version::Version () 
{
	Inicializar ();
}

Version::Version ( int _iVersion, int _iSubversion, int _iRevision, long lFecVersion ) 
{
	Inicializar ();
	Establecer ( _iVersion, _iSubversion, _iRevision, lFecVersion );
}

Version::Version ( int _iVersion, int _iSubversion, int _iRevision, const ::org::gjs::cpp::common::Fecha & fecVersion )
{
	Inicializar ();
	Establecer ( _iVersion, _iSubversion, _iRevision, fecVersion );
}

Version::~Version ()
{
}

int Version::Ver () const
{
	return ( iVersion );
}

int Version::Subver () const
{
	return ( iSubversion );
}

int Version::Rev () const
{
	return ( iRevision );
}

::org::gjs::cpp::common::Fecha Version::Fecha () const
{
	return ( (::org::gjs::cpp::common::Fecha) *this );
}

string Version::CadenaVersion ( int iCorta )
{
	string sRes;

	if ( ( iCorta == 0 ) && ( iRevision >= 0 ) )
	{
		sRes = format ( VER_FORM_CADENA, iVersion, iSubversion, iRevision );
	}
	else
	{
		sRes = format ( VER_FORM_CADENA_CORTO, iVersion, iSubversion );
	}
	return ( sRes );
}

bool Version::EsValida ()
{
	return ( ( iVersion > 0 ) && ( iSubversion >= 0 ) && 
		Fecha::EsValida () );
}

bool Version::EstablecerVer ( int _iVersion )
{
	bool bRes = true;

	if ( _iVersion > 0 )
	{
		iVersion = _iVersion;
		bRes = true;
	}
	else
	{
		iVersion = 0;
	}
	return ( bRes );
}

bool Version::EstablecerSubver ( int _iSubversion )
{
	bool bRes = true;

	if ( _iSubversion >= 0 )
	{
		iSubversion = _iSubversion;
		bRes = true;
	}
	else
	{
		iSubversion = -1;
	}
	return ( bRes );
}

bool Version::EstablecerRev ( int _iRevision )
{
	bool bRes = true;

	if ( _iRevision >= 0 )
	{
		iRevision = _iRevision;
		bRes = true;
	}
	else
	{
		iRevision = -1;
	}
	return ( bRes );
}

bool Version::EstablecerFecha ( long lFecVersion )
{
	return ( Fecha::Establecer ( lFecVersion ) );
}

bool Version::EstablecerFecha ( const ::org::gjs::cpp::common::Fecha & fecVersion )
{
	return ( Fecha::Establecer ( fecVersion.Valor() ) );
}

bool Version::Establecer ( int _iVersion, int _iSubversion, int _iRevision, long lFecVersion )
{
	return ( EstablecerVer ( _iVersion ) &&
		 EstablecerSubver ( _iSubversion ) &&
		 EstablecerRev ( _iRevision ) &&
		 EstablecerFecha ( lFecVersion ) );
}


bool Version::Establecer ( int _iVersion, int _iSubversion, int _iRevision, const ::org::gjs::cpp::common::Fecha & fecVersion ) 
{
	return (  EstablecerVer ( _iVersion )&&
		  EstablecerSubver ( _iSubversion ) &&
		  EstablecerRev ( _iRevision )&&
		  EstablecerFecha ( fecVersion ) );
}

void Version::Imprimir ()
{
	cout << format ( VER_FORM_MENSAJE, iVersion, iSubversion, iRevision, Fecha::Formatear ( VERSION_FEC_FORMATO ) );
}

void Version::Inicializar ()
{
	iVersion = 1;
	iSubversion = 0;
	iRevision = 0;
	Fecha::Establecer ( (long) 0 );
}



 			}
		}
	}
}




