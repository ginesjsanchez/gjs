#include "SListaEnterosLargos.h"

#include "TiposDatosConfig.h"




SListaEnterosLargos * SLisEntlCrear ()
{
	SListaEnterosLargos * p_lisObj;
	
	p_lisObj = (SListaEnterosLargos *) MemReservar ( sizeof ( SListaEnterosLargos ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLisCrear ();
	}
	return ( p_lisObj );
}

void SLisEntlDestruir ( SListaEnterosLargos ** p_p_lisObj )
{
	SListaEnterosLargos * p_lisObj;
	
	if ( ES_VALIDO ( p_p_lisObj ) )
	{
		p_lisObj = *p_p_lisObj;

		if ( ES_VALIDO ( p_lisObj ) )
		{
			SLisDestruir ( &(p_lisObj->p_lisDatos) );
			MemLiberar ( (void **) p_p_lisObj );
		}
	}
}

int SLisEntlEsValida ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisEsValida ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlEstaVacia ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisEstaVacia ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlNumElementos ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisNumElementos ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

long long SLisEntlElemento ( SListaEnterosLargos * p_lisObj, int iElem )
{
	long long		llRes;
	SElemento *		p_elmObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = SLisElemento ( p_lisObj->p_lisDatos, iElem );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			llRes = SElmEntero ( p_elmObj );
		}
		else
		{
			llRes = -1;
		}
	}
	else
	{
		llRes = -1;
	}
	return ( llRes );
}

int SLisEntlEstablecerElem ( SListaEnterosLargos * p_lisObj, int iPos, long long llDato )
{
	int			iRes;
	SElemento *	p_elmObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = SLisElemento ( p_lisObj->p_lisDatos, iPos );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			iRes = SElmEscribirEntero ( p_elmObj, llDato );
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEntlInsertarElem ( SListaEnterosLargos * p_lisObj, int iPosAnt, long long llDato )
{
	int			iRes;
	SElemento *	p_elmObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = SElmCrearEntero ();
		if ( ES_VALIDO ( p_elmObj ) )
		{
			if ( SElmEscribirEntero ( p_elmObj, llDato ) == 1 )
			{
				iRes = SLisInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, p_elmObj );
			}
			else 
			{
				iRes = -1;
			}
			if ( iRes != 1 )
			{
				SElmDestruir ( &p_elmObj );
			}
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEntlInsertarAlInicio ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	return ( SLisEntlInsertarElem ( p_lisObj, -1, llDato ) );
}

int SLisEntlInsertarAlFinal ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisEntlInsertarElem ( p_lisObj, SLisEntlNumElementos ( p_lisObj ), llDato );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEntlEliminarElem ( SListaEnterosLargos * p_lisObj, int iElem )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisEliminarElem ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEntlVaciar ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisVaciar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEntlPosicion ( SListaEnterosLargos * p_lisObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisPosicion ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

long long SLisEntlActual ( SListaEnterosLargos * p_lisObj )
{
	SElemento *		p_elmObj;
	long long		llRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = ( SElemento * ) SLisActual ( p_lisObj->p_lisDatos );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			llRes = SElmEntero ( p_elmObj );
		}
		else
		{
			llRes = -1;
		}
	}
	else
	{
		llRes = 0;
	}
	return ( llRes );
}

void SLisEntlInicio ( SListaEnterosLargos * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisInicio ( p_lisObj->p_lisDatos );
	}
}

void SLisEntlFinal ( SListaEnterosLargos * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisFinal ( p_lisObj->p_lisDatos );
	}
}

void SLisEntlSiguiente ( SListaEnterosLargos * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisSiguiente ( p_lisObj->p_lisDatos );
	}
}

void SLisEntlAnterior ( SListaEnterosLargos * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisAnterior ( p_lisObj->p_lisDatos );
	}
}

void SLisEntlMoverA ( SListaEnterosLargos * p_lisObj, int iElem )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisMoverA ( p_lisObj->p_lisDatos, iElem );
	}
}

void SLisEntlDeposicionar ( SListaEnterosLargos * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLisDeposicionar ( p_lisObj->p_lisDatos );
	}
}

int SLisEntlEsNulo ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLisEsNulo ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlEstaEnFinal ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLisEstaEnFinal ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlEstaEnIncio ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLisEstaEnIncio ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlInsertar ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	return ( SLisEntlInsertarDetras ( p_lisObj, llDato ) );
}

int SLisEntlInsertarDelante ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	int			iRes;
	SElemento *	p_elmObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = SElmCrearEntero ();
		if ( ES_VALIDO ( p_elmObj ) )
		{
			if ( SElmEscribirEntero ( p_elmObj, llDato ) == 1 )
			{
				iRes = SLisInsertarDelante ( p_lisObj->p_lisDatos, p_elmObj );
			}
			else
			{
				iRes = -1;
			}
			if ( iRes != 1 )
			{
				SElmDestruir ( &p_elmObj );
			}
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlInsertarDetras ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	int			iRes;
	SElemento *	p_elmObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_elmObj = SElmCrearEntero ();
		if ( ES_VALIDO ( p_elmObj ) )
		{
			if ( SElmEscribirEntero ( p_elmObj, llDato ) == 1 )
			{
				iRes = SLisInsertarDetras ( p_lisObj->p_lisDatos, p_elmObj );
			}
			else
			{
				iRes = -1;
			}
			if ( iRes != 1 )
			{
				SElmDestruir ( &p_elmObj );
			}
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlEliminar ( SListaEnterosLargos * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLisEliminar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEntlExiste ( SListaEnterosLargos * p_lisObj, long long llDato )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj )  ) 
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SLisEntlNumElementos ( p_lisObj ) ) && ( iRes == 0 ) )
		{
			if ( SLisEntlElemento ( p_lisObj, iElem ) == llDato )
			{
				iRes = 1;
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}




