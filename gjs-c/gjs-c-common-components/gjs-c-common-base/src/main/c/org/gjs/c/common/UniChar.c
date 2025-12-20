/******************************************************************************/
/*                                UniChar.cpp                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de algunas ru-     */
/* tinas relacionadas con el tratamiento de cadenas Unicode.                  */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "UniChar.h"

#include "Memoria.h"
#include "CadenasBase.h"


char UnicodeAscii ( unichar ucValor )
{
	return ( (char) ( ucValor | 0x00FF ) );
}

unichar AsciiAUnicode ( char cValor )
{
	return ( 0x00FF & (unichar) cValor );
}

char * CadUnicodeAAsciiz ( const unichar * p_ucUnicode )
{
	char *	p_cRes;
	int		iLong;

	if ( ES_VALIDO ( p_ucUnicode ) )
	{
		//iLong = wcslen ( p_ucUnicode );
		p_cRes = NULL;
#    if ( defined ( WIN ) )
#	  if ( defined ( VC ) && ( _MSC_VER < 1600 ) )
		iLong = WideCharToMultiByte ( JUEG_CAR_OEM_LATIN_I, 0, (const unsigned short *) p_ucUnicode, -1, p_cRes, 0, NULL, NULL );
#	  else // GNU
		iLong = WideCharToMultiByte ( JUEG_CAR_OEM_LATIN_I, 0, (LPCWSTR) p_ucUnicode, -1, (LPSTR) p_cRes, 0, NULL, NULL );
#	  endif
#    else
		// PENDIENTE:
		iLong = 0; //wcslen ( p_ucUnicode );
#    endif
		if ( iLong > 0 )
		{
			p_cRes = (char *) MemReservar ( iLong * sizeof ( char ) );
#	     if ( defined ( WIN ) )
#		  if ( defined ( VC ) && ( _MSC_VER < 1600 ) )
			if ( WideCharToMultiByte ( JUEG_CAR_OEM_LATIN_I, 0, (const unsigned short *) p_ucUnicode, -1, p_cRes, iLong, NULL, NULL ) == 0 )
#		  else // GNU
			if ( WideCharToMultiByte ( JUEG_CAR_OEM_LATIN_I, 0, (LPCWSTR) p_ucUnicode, -1, (LPSTR) p_cRes, iLong, NULL, NULL ) == 0 )
#		  endif
#		 else
			// PENDIENTE:
			if (1)
#	     endif
			{
				p_cRes = NULL;
			}
		}
		else
		{
			p_cRes = NULL;
		}
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

unichar * CadAsciizAUnicode ( const char * p_cAsciiz )
{
	unichar *	p_ucRes;
	int			iLongWC;

	if ( ES_VALIDO ( p_cAsciiz ) )
	{
		p_ucRes = NULL;
#    if ( defined ( WIN ) )
#	  if ( defined ( VC ) && ( _MSC_VER < 1600 ) )
		iLongWC = MultiByteToWideChar ( JUEG_CAR_OEM_LATIN_I, 0, p_cAsciiz, iLong + 1, (unsigned short *) p_ucRes, 0 );
#	  else // GNU
		iLongWC = MultiByteToWideChar ( JUEG_CAR_OEM_LATIN_I, 0, (LPCSTR) p_cAsciiz, iLong + 1, (LPWSTR) p_ucRes, 0 );
#	  endif
#    else
		// PENDIENTE:
		iLongWC = 0;
#    endif
		if ( iLongWC > 0 )
		{
			p_ucRes = (unichar *) MemReservar ( iLongWC * sizeof ( unichar ) );
#	     if ( defined ( WIN ) )
#		  if ( defined ( VC ) && ( _MSC_VER < 1600 ) )
			if ( MultiByteToWideChar ( JUEG_CAR_OEM_LATIN_I, 0, p_cAsciiz, iLong + 1, (unsigned short *) p_ucRes, iLongWC ) == 0)
#		  else // GNU
			if ( MultiByteToWideChar ( JUEG_CAR_OEM_LATIN_I, 0, (LPCSTR) p_cAsciiz, iLong + 1, (LPWSTR) p_ucRes, iLongWC ) == 0)
#		  endif
#		 else
			// PENDIENTE:
#	     endif
			{
				p_ucRes = NULL;
			}
		}
		else
		{
			p_ucRes = NULL;
		}
	}
	else
	{
		p_ucRes = NULL;
	}
	return ( p_ucRes );
}







