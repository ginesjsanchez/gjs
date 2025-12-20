/******************************************************************************/
/*                              CadenasBase.cpp                               */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* generales para el manejo general de cadenas.                               */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "CadenasBase.h"



#include "BaseConfig.h"
#include "Memoria.h"
#include "Errores.h"






char * CadCrear ( int iLong )
{
	char *	p_cCad;
	//int		iPos;

	p_cCad = NULL;
	if ( iLong >= 0 )
	{
		p_cCad = (char *) MemReservar ( ( iLong + 1 ) * sizeof ( char ) );
		if ( ES_VALIDO ( p_cCad ) )
		{
			//for ( iPos = 0; iPos <= iLong; iPos = iPos + 1 ) 
			//{	
			//	p_cCad [ iPos ] = (char) 0; 
			//}
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( p_cCad );
}

int CadLongitud ( const char * p_cAsciiz )
{
	int iMax;
	int iTam;
	int iCar;
	int iFin;

	iCar = 0;
	iTam = 0;
	iFin = 0;
	if ( ES_VALIDO ( p_cAsciiz ) ) 
	{ 
		iMax = CAD_BASE_MAX_TAM;
		while ( ( iCar < iMax ) && ( iFin == 0 ) )
		{
			if ( p_cAsciiz [ iCar ] == (char) 0 )
			{
				iFin = 1;
			}
			else
			{
				iTam = iTam + 1;
			}
			iCar = iCar +1;
		}
	}
	else
	{
		iTam = -1;
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iTam );
}

int CadLongitudSeg ( const char * p_cAsciiz, int iMax )
{
	int iTam;
	int iCar;
	int iFin;

	iCar = 0;
	iTam = 0;
	iFin = 0;
	if ( ES_VALIDO ( p_cAsciiz ) ) 
	{
		if ( ( iMax < 0 ) || ( iMax > CAD_BASE_MAX_TAM ) )
		{
			iMax = CAD_BASE_MAX_TAM;
		}
		while ( ( iCar < iMax ) && ( iFin == 0 ) )
		{
			if ( p_cAsciiz [ iCar ] == (char) 0 )
			{
				iFin = 1;
			}
			else
			{
				iTam = iTam + 1;
			}
			iCar = iCar +1;
		}
	}
	else
	{
		iTam = -1;
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iTam );
}

void CadInicializar ( char * p_cAsciiz, int iMax )
{
	int	iMax1;
	int	iPos;
	int iFin;

	if ( ES_VALIDO ( p_cAsciiz ) )
	{
		if ( iMax > 0 ) 
		{
			iMax1 = iMax;
		}
		else
		{
			iMax1 = CAD_BASE_MAX_TAM;
		}
		iFin = 0;
		iPos = 0;
		while ( ( iPos < iMax1 ) && ( iFin == 0 ) )
		{
			if ( ( iMax <= 0 ) && ( p_cAsciiz [ iPos ] != (char) 0 ) )
			{
				iFin = 1;
			}
			else
			{
				p_cAsciiz [ iPos ] = (char) 0; 
			}
			iPos = iPos + 1; 
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
}

char * CadDuplicar ( const char * p_cAsciiz )
{
	int		iLong;
	int		iPos;
	char *	p_cCopia;

	iLong = CadLongitud ( p_cAsciiz ); 
	if ( iLong >= 0 )
	{
		p_cCopia = CadCrear ( iLong );
		if ( ES_VALIDO ( p_cCopia ) )
		{
			for ( iPos = 0; iPos < iLong; iPos = iPos + 1 ) 
			{	
				p_cCopia [ iPos ] = p_cAsciiz [ iPos ]; 
			}
			p_cCopia [ iLong ] = (char) 0;
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
		p_cCopia = NULL;
	}
	return ( p_cCopia );
}

char * CadDuplicarSeg ( const char * p_cAsciiz, int iMax )
{
	int		iLong;
	int		iPos;
	char *	p_cCopia;

	iLong = CadLongitudSeg ( p_cAsciiz, iMax ); 
	if ( iLong >= 0 )
	{
		p_cCopia = CadCrear ( iLong );
		if ( ES_VALIDO ( p_cCopia ) )
		{
			for ( iPos = 0; iPos < iLong; iPos = iPos + 1 ) 
			{	
				p_cCopia [ iPos ] = p_cAsciiz [ iPos ]; 
			}
			p_cCopia [ iLong ] = (char) 0;
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
		p_cCopia = NULL;
	}
	return ( p_cCopia );
}

unichar * CadUniCrear ( int iLong )
{
# if ( defined ( MODO_UNICODE ) )
	unichar *	p_ucCad;
	int			iPos;
# endif 

# if ( !defined ( MODO_UNICODE ) )
	return ( (unichar *) CadCrear ( iLong ) );
# else
	p_ucCad = NULL;
	if ( iLong >= 0 )
	{
		p_ucCad = (unichar *) MemReservar ( ( iLong + 1 ) * sizeof ( unichar ) );
		if ( ES_VALIDO ( p_ucCad ) )
		{
			for ( iPos = 0; iPos <= iLong; iPos = iPos + 1 ) 
			{	
				p_ucCad [ iPos ] = (unichar) 0; 
			}
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( p_ucCad );
# endif 
}

int CadUniLongitud ( const unichar * p_ucValor )
{
	int	iMax;
	int iTam;
	int iCar;
	int iFin;

	iCar = 0;
	iTam = 0;
	iFin = 0;
	if ( ES_VALIDO ( p_ucValor ) ) 
	{ 
		iMax = CAD_BASE_MAX_TAM;
		while ( ( iCar < iMax ) && ( iFin == 0 ) )
		{
			if ( p_ucValor [ iCar ] == (unichar) 0 )
			{
				iFin = 1;
			}
			else
			{
				iTam = iTam + 1;
			}
			iCar = iCar +1;
		}
	}
	else
	{
		iTam = -1;
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iTam );
}

int CadUniLongitudSeg ( const unichar * p_ucValor, int iMax )
{
	int iTam;
	int iCar;
	int iFin;

	iCar = 0;
	iTam = 0;
	iFin = 0;
	if ( ES_VALIDO ( p_ucValor ) ) 
	{ 
		if ( ( iMax < 0 ) || ( iMax > CAD_BASE_MAX_TAM ) )
		{
			iMax = CAD_BASE_MAX_TAM;
		}
		while ( ( iCar < iMax ) && ( iFin == 0 ) )
		{
			if ( p_ucValor [ iCar ] == (unichar) 0 )
			{
				iFin = 1;
			}
			else
			{
				iTam = iTam + 1;
			}
			iCar = iCar +1;
		}
	}
	else
	{
		iTam = -1;
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iTam );
}

void CadUniInicializar ( unichar * p_ucValor, int iMax )
{
	int	iMax1;
	int	iPos;
	int	iFin;

	if ( ES_VALIDO ( p_ucValor ) )
	{
		if ( iMax > 0 ) 
		{
			iMax1 = iMax;
		}
		else
		{
			iMax1 = CAD_BASE_MAX_TAM;
		}
		iFin = 0;
		iPos = 0;
		while ( ( iPos < iMax1 ) && ( iFin == 0 ) )
		{
			if ( ( iMax <= 0 ) && ( p_ucValor [ iPos ] != (unichar) 0 ) )
			{
				iFin = 1;
			}
			else
			{
				p_ucValor [ iPos ] = (unichar) 0; 
			}
			iPos = iPos + 1; 
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
}

unichar * CadUniDuplicar ( const unichar * p_ucValor )
{
	int		iLong;
	int		iPos;
	unichar *	p_cCopia;

	iLong = CadUniLongitud ( p_ucValor ); 
	if ( iLong >= 0 )
	{
		p_cCopia = CadUniCrear ( iLong );
		if ( ES_VALIDO ( p_cCopia ) )
		{
			for ( iPos = 0; iPos < iLong; iPos = iPos + 1 ) 
			{	
				p_cCopia [ iPos ] = p_ucValor [ iPos ]; 
			}
			p_cCopia [ iLong ] = (unichar) 0;
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
		p_cCopia = NULL;
	}
	return ( p_cCopia );
}

void CadImprimir ( const char * p_cAsciiz )
{
	if ( ES_VALIDO ( p_cAsciiz ) )
	{
		printf ( "%s\n", p_cAsciiz );
	}
}





