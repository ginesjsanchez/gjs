#include "SListaReferencias.h"

#include "TiposBasicosConfig.h"




SListaReferencias * SLisRefCrear ()
{
	SListaReferencias * p_lisObj;
	
	p_lisObj = (SListaReferencias *) MemReservar ( sizeof ( SListaReferencias ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLispCrear ();
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
	return ( p_lisObj );
}

void SLisRefDestruir ( SListaReferencias ** p_p_lisObj )
{
	SListaReferencias * p_lisObj;
	
	if ( ES_VALIDO ( p_p_lisObj ) )
	{
		p_lisObj = *p_p_lisObj;

		if ( ES_VALIDO ( p_lisObj ) )
		{
			SLisRefVaciar ( p_lisObj );
			SLispDestruir ( &(p_lisObj->p_lisDatos) );
			MemLiberar ( (void **) p_p_lisObj );
		}
	}
}

int SLisRefEsValida ( SListaReferencias * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEsValida ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisRefEstaVacia ( SListaReferencias * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEstaVacia ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 1;
	}
	return ( iRes );
}

int SLisRefNumElementos ( SListaReferencias * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispNumElementos ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SReferencia * SLisRefElemento ( SListaReferencias * p_lisObj, int iElem )
{
	SReferencia *	p_refRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_refRes = (SReferencia *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		p_refRes = NULL;
	}
	return ( p_refRes );
}

const char * SLisRefAliasElemento ( SListaReferencias * p_lisObj, int iElem )
{
	const char * 	p_cRes;
	SReferencia *	p_refObj;
	
	p_refObj = SLisRefElemento ( p_lisObj, iElem );
	if ( ES_VALIDO ( p_refObj ) )
	{
		p_cRes = SRefObtenerAlias ( p_refObj );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

void * SLisRefDatosElemento ( SListaReferencias * p_lisObj, int iElem )
{
	void * 			p_vRes;
	SReferencia *	p_refObj;
	
	p_refObj = SLisRefElemento ( p_lisObj, iElem );
	if ( ES_VALIDO ( p_refObj ) )
	{
		p_vRes = SRefObtenerDatos ( p_refObj );
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

int SLisRefInsertar ( SListaReferencias * p_lisObj, SReferencia * p_refDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		SLispInicio ( p_lisObj->p_lisDatos );
		while ( SRefEsMenor ( ( SReferencia * ) SLispActual ( p_lisObj->p_lisDatos ), p_refDatos ) &&
			( SLispEstaEnFinal ( p_lisObj->p_lisDatos ) == 0 ) )
		{
			SLispSiguiente ( p_lisObj->p_lisDatos );
		}
		if ( SLispEstaEnFinal ( p_lisObj->p_lisDatos ) == 1 )
		{
			iRes = SLispInsertar ( p_lisObj->p_lisDatos, ( byte * ) p_refDatos );
		}
		else
		{
			iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, ( byte * ) p_refDatos );
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisRefInsertarExt ( SListaReferencias * p_lisObj, const char * p_cAlias, void * p_vDato )
{
	int iRes;

	SReferencia * p_refObj = SRefCrear ( p_cAlias, p_vDato );
	if ( ES_VALIDO ( p_refObj ) )
	{
		iRes = SLisRefInsertar ( p_lisObj, p_refObj );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisRefVaciar ( SListaReferencias * p_lisObj )
{
	int 			iRes;
	SReferencia * 	p_refObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		for ( int iElem = 0; iElem < SLisRefNumElementos ( p_lisObj ); iElem = iElem + 1 )
		{
			p_refObj = SLisRefElemento ( p_lisObj, iElem );
			SRefDestruir ( &p_refObj );
		}
		iRes = SLispVaciar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisRefEliminar ( SListaReferencias * p_lisObj, const char * p_cAlias )
{
	int				iEnc;
	int				iElem;
	int				iRes;
	SReferencia *	p_refRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cAlias ) )
	{
		iEnc = 0;
		iElem = 0;
		iRes = -1;
		while ( ( iElem < SLisRefNumElementos ( p_lisObj ) ) && ( iEnc == 0 ) )
		{
			p_refRes = SLisRefElemento ( p_lisObj, iElem );
			iEnc = CadComparar ( SRefObtenerAlias ( p_refRes ), p_cAlias );
			if ( iEnc == 1 )
			{
				iRes = SLisRefEliminarElem ( p_lisObj, iElem );
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisRefEliminarElem ( SListaReferencias * p_lisObj, int iElem )
{
	int 			iRes;
	SReferencia * 	p_refObj;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_refObj = SLisRefElemento ( p_lisObj, iElem );
		SRefDestruir ( &p_refObj );
		iRes = SLispEliminarElem ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisRefExiste ( SListaReferencias * p_lisObj, const char * p_cAlias )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cAlias )  )
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SLisRefNumElementos ( p_lisObj ) ) && ( iRes == 0 ) )
		{
			if ( CadComparar ( SRefObtenerAlias ( SLisRefElemento ( p_lisObj, iElem ) ), p_cAlias ) == 1 )
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

SReferencia * SLisRefBuscar ( SListaReferencias * p_lisObj, const char * p_cAlias )
{
	SReferencia *	p_refRes;
	int 			iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cAlias )  )
	{
		p_refRes = NULL;
		iElem = 0;
		while ( ( iElem < SLisRefNumElementos ( p_lisObj ) ) && ( p_refRes == NULL ) )
		{
			if ( CadComparar ( SRefObtenerAlias ( SLisRefElemento ( p_lisObj, iElem ) ), p_cAlias ) == 1 )
			{
				p_refRes = SLisRefElemento ( p_lisObj, iElem );
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		p_refRes = NULL;
	}
	return ( p_refRes );
}

int	SLisRefLiberacionMemoriaActivada ( SListaReferencias * p_lisObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SLisRefActivarLiberacionMemoria ( SListaReferencias * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}

void SLisRefDesactivarLiberacionMemoria ( SListaReferencias * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}



