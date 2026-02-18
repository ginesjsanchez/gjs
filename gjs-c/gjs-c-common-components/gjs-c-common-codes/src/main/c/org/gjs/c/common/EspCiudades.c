/***************************************************************************/
/*                        EspCiudades.cpp                                  */
/*-------------------------------------------------------------------------*/
/* Librería: Geodesia                                                      */
/* Versión:  1.1.0                                                         */
/* Fecha:    21/11/2006                                                    */
/* Autor:    Ginés Jiménez Sánchez                                         */
/*-------------------------------------------------------------------------*/
/* Descripción:                                                            */
/* Fichero de código fuente que contiene la implementación de las rutinas  */
/* para la validación y consulta de datos de ciudades.                     */
/*-------------------------------------------------------------------------*/
/* NOTA DEL AUTOR:                                                         */
/* Este módulo está extraído de una librería más completa creada por el    */
/* mismo autor. Por favor, el autor ruega que se le informe de cualquier   */
/* error detectado, así como cualquier añadido o modificación realizado.   */
/* Pueden reportar de los mismos enviando un correo electrónico a la       */
/* dirección: gines_jimenez@safe-mail.net. Gracias.                        */
/***************************************************************************/

#include "EspCiudades.h"



#include <Base.h>
#include <Texto.h>




const char * CiudEspLiteral ( int iId )
{
	if ( iId == CIUD_ESP_MADRID )
	{
		return ( CIUD_ESP_TXT_MADRID );
	}
	else if ( iId == CIUD_ESP_BARCELONA ) 
	{
		return ( CIUD_ESP_TXT_BARCELONA );
	}
	else 
	{
		return ( NULL );
	}
}

const char * CiudEspCodigo ( int iId )
{
	if ( iId == CIUD_ESP_MADRID )
	{
		return ( CIUD_ESP_COD_MADRID );
	}
	else if ( iId == CIUD_ESP_BARCELONA ) 
	{
		return ( CIUD_ESP_COD_BARCELONA );
	}
	else 
	{
		return ( NULL );
	}
}

int CiudEspId ( const char * p_cLit )
{
	int iRes;

	if ( ES_VALIDO ( p_cLit ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_cLit, CIUD_ESP_TXT_MADRID ) == 1 )
		{
			iRes = CIUD_ESP_MADRID;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cLit, CIUD_ESP_TXT_BARCELONA ) == 1 )	
		{
			iRes = CIUD_ESP_BARCELONA;
		}
		else 
		{
			iRes = CIUD_ESP_NINGUNO;
		}
	}
	else 
	{
		iRes = CIUD_ESP_NINGUNO;
	}
	return ( iRes );
}

int CiudEspIdPorCodigo ( const char * p_cCod )
{
	int iRes;

	if ( ES_VALIDO ( p_cCod ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_cCod, CIUD_ESP_COD_MADRID ) == 1 )
		{
			iRes = CIUD_ESP_MADRID;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cCod, CIUD_ESP_COD_BARCELONA ) == 1 )	
		{
			iRes = CIUD_ESP_BARCELONA;
		}
		else 
		{
			iRes = CIUD_ESP_NINGUNO;
		}
	}
	else 
	{
		iRes = CIUD_ESP_NINGUNO;
	}
	return ( iRes );
}

int CiudEspEsValido ( int iId )
{
	int iRes; 

	if ( ( iId == CIUD_ESP_MADRID ) ||
		 ( iId == CIUD_ESP_BARCELONA ) )	
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

long CiudEspLongitud ( int iId )
{
	long lRes;

	if ( iId == CIUD_ESP_MADRID )
	{
		lRes = CIUD_ESP_LON_MADRID;
	}
	else if ( iId == CIUD_ESP_BARCELONA )
	{
		lRes = CIUD_ESP_LON_BARCELONA;
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

long CiudEspLatitud ( int iId )
{
	long lRes;

	if ( iId == CIUD_ESP_MADRID )
	{
		lRes = CIUD_ESP_LAT_MADRID;
	}
	else if ( iId == CIUD_ESP_BARCELONA )
	{
		lRes = CIUD_ESP_LAT_BARCELONA;
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

long CiudEspAltitud ( int iId )
{
	long lRes;

	if ( iId == CIUD_ESP_MADRID )
	{
		lRes = CIUD_ESP_ALT_MADRID;
	}
	else if ( iId == CIUD_ESP_BARCELONA )
	{
		lRes = CIUD_ESP_ALT_BARCELONA;
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}




