/***************************************************************************/
/*                        Paises.cpp                                       */
/*-------------------------------------------------------------------------*/
/* Librería: Geodesia                                                      */
/* Versión:  1.1.0                                                         */
/* Fecha:    21/11/2006                                                    */
/* Autor:    Ginés Jiménez Sánchez                                         */
/*-------------------------------------------------------------------------*/
/* Descripción:                                                            */
/* Fichero de código fuente que contiene la implementación de las rutinas  */
/* para la validación y el trabajo con el estándar ISO 3166-1.             */
/*-------------------------------------------------------------------------*/
/* NOTA DEL AUTOR:                                                         */
/* Este módulo está extraído de una librería más completa creada por el    */
/* mismo autor. Por favor, el autor ruega que se le informe de cualquier   */
/* error detectado, así como cualquier añadido o modificación realizado.   */
/* Pueden reportar de los mismos enviando un correo electrónico a la       */
/* dirección: gines_jimenez@safe-mail.net. Gracias.                        */
/***************************************************************************/

#include "Paises.h"



#include <Base.h>
#include <Texto.h>



const char * PaisLiteral ( int iId )
{
	if ( iId == PAIS_ESPANA )
	{
		return ( PAIS_TXT_ESPANA );
	}
	else if ( iId == PAIS_PORTUGAL ) 
	{
		return ( PAIS_TXT_PORTUGAL );
	}
	else 
	{
		return ( NULL );
	}
}

const char * PaisCodigo ( int iId )
{
	if ( iId == PAIS_ESPANA )
	{
		return ( PAIS_COD_ESPANA );
	}
	else if ( iId == PAIS_PORTUGAL ) 
	{
		return ( PAIS_COD_PORTUGAL );
	}
	else 
	{
		return ( NULL );
	}
}

int PaisId ( const char * p_cLit )
{
	int iRes;

	if ( ES_VALIDO ( p_cLit ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_cLit, PAIS_TXT_ESPANA ) == 1 )
		{
			iRes = PAIS_ESPANA;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cLit, PAIS_TXT_PORTUGAL ) == 1 )	
		{
			iRes = PAIS_PORTUGAL;
		}
		else 
		{
			iRes = PAIS_NINGUNO;
		}
	}
	else 
	{
		iRes = PAIS_NINGUNO;
	}
	return ( iRes );
}

int PaisIdPorCodigo ( const char * p_cCod )
{
	int iRes;

	if ( ES_VALIDO ( p_cCod ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_cCod, PAIS_COD_ESPANA ) == 1 )
		{
			iRes = PAIS_ESPANA;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cCod, PAIS_COD_PORTUGAL ) == 1 )	
		{
			iRes = PAIS_PORTUGAL;
		}
		else 
		{
			iRes = PAIS_NINGUNO;
		}
	}
	else 
	{
		iRes = PAIS_NINGUNO;
	}
	return ( iRes );
}

int PaisEsValido ( int iId )
{
	int iRes; 

	if ( ( iId == PAIS_ESPANA ) ||
		 ( iId == PAIS_PORTUGAL ) )	
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

