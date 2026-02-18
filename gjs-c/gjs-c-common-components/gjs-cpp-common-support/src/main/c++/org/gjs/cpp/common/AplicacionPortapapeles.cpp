/******************************************************************************/
/*                         AplicacionPortapapeles.cpp                         */
/*----------------------------------------------------------------------------*/
/* Librería:  Aplicacion                                                      */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de algunas         */
/* para manejo del portapapeles de Windows.                                   */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/



#include "AplicacionPortapapeles.h"

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

#if ( defined ( WIN ) ) 



void AplicPplesLimpiar ()
{
	if ( OpenClipboard ( GetActiveWindow () ) != 0 )
	{
		EmptyClipboard ();
	    CloseClipboard ();
	}
}

void AplicPplesCopiar ( const string & sTexto )
{
	DWORD	dwTam;
	HANDLE	hMem;

	if ( OpenClipboard ( GetActiveWindow () ) != 0 )
	{
		EmptyClipboard ();

		dwTam = ((DWORD) sTexto.lenght() )) + 1;
		if ( dwTam > 0 )
		{
			hMem = GlobalAlloc ( GMEM_FIXED, dwTam );
			if ( hMem != NULL )
			{
				CopyMemory ( hMem, sTexto.c_str(), dwTam );
				//if ( SetClipboardData ( CF_DSPTEXT, hMem ) == NULL )
				if ( SetClipboardData ( CF_OEMTEXT, hMem ) == NULL )
				{
					// Error:
					GlobalFree ( hMem );
				}
			}
		}
	}
    CloseClipboard();
}

string AplicPplesContenido ( int iLimpiar )
{
	DWORD	dwTam;
	HANDLE	hMem;
	string 	sRes = "";

	if ( OpenClipboard ( GetActiveWindow () ) != 0 )
	{
		//hMem = GetClipboardData ( CF_DSPTEXT );
		hMem = GetClipboardData ( CF_OEMTEXT );
		if ( hMem != NULL )
		{
			dwTam =  GlobalSize ( hMem );
			if ( dwTam > 1 )
			{
				vector<char> buffer = vector<char>  ( dwTam - 1 );
				CopyMemory ( buffer.data(), hMem, dwTam - 1 );
				if ( iLimpiar == 1 )
				{
					EmptyClipboard ();
				}
				sRes = string ( buffer.data() );
			}
		}
	}
    CloseClipboard();
	return ( sRes );
}


#endif


 			}
		}
	}
}
