#include "SListaEntradasExt.h"

#include "TiposDatosConfig.h"




SListaEntradasExt * SLisEtxCrear ()
{
	SListaEntradasExt * p_lisObj;
	
	p_lisObj = (SListaEntradasExt *) MemReservar ( sizeof ( SListaEntradasExt ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLispCrear ();
	}
	return ( p_lisObj );
}

void SLisEtxDestruir ( SListaEntradasExt ** p_p_lisObj )
{
	SListaEntradasExt * p_lisObj;
	
	if ( ES_VALIDO ( p_p_lisObj ) )
	{
		p_lisObj = *p_p_lisObj;

		if ( ES_VALIDO ( p_lisObj ) )
		{
			SLispDestruir ( &(p_lisObj->p_lisDatos) );
			MemLiberar ( (void **) p_p_lisObj );
		}
	}
}

int SLisEtxEsValida ( SListaEntradasExt * p_lisObj )
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

int SLisEtxEstaVacia ( SListaEntradasExt * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEstaVacia ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEtxNumElementos ( SListaEntradasExt * p_lisObj )
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

SEntradaExt * SLisEtxElemento ( SListaEntradasExt * p_lisObj, int iElem )
{
	SEntradaExt *	p_etxRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_etxRes = (SEntradaExt *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		p_etxRes = NULL;
	}
	return ( p_etxRes );
}

int SLisEtxInsertar ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_etxDatos ) )
	{
		SLispInicio ( p_lisObj->p_lisDatos );
		while ( SEtxEsMenor ( ( SEntradaExt * ) SLispActual ( p_lisObj->p_lisDatos ), p_etxDatos ) &&
			( SLispEstaEnFinal ( p_lisObj->p_lisDatos ) == 0 ) )
		{
			SLispSiguiente ( p_lisObj->p_lisDatos );
		}
		if ( SLispEstaEnFinal ( p_lisObj->p_lisDatos ) == 1 )
		{
			iRes = SLispInsertar ( p_lisObj->p_lisDatos, ( byte * ) p_etxDatos );
		}
		else
		{
			iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, ( byte * ) p_etxDatos );
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtxVaciar ( SListaEntradasExt * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispVaciar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtxEliminar ( SListaEntradasExt * p_lisObj, const char * p_cNombre )
{
	int				iEnc;
	int				iElem;
	int				iRes;
	SEntradaExt *	p_etxRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cNombre ) )
	{
		iEnc = 0;
		iElem = 0;
		iRes = -1;
		while ( ( iElem < SLisEtxNumElementos ( p_lisObj ) ) && ( iEnc == 0 ) )
		{
			p_etxRes = SLisEtxElemento ( p_lisObj, iElem );
			iEnc = CadComparar ( SEtxNombre ( p_etxRes ), p_cNombre );
			if ( iEnc == 1 )
			{
				iRes = SLisEtxEliminarElem ( p_lisObj, iElem );
			}
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtxEliminarElem ( SListaEntradasExt * p_lisObj, int iElem )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEliminarElem ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtxExiste ( SListaEntradasExt * p_lisObj, const char * p_cNombre )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cNombre )  )
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SLisEtxNumElementos ( p_lisObj ) ) && ( iRes == 0 ) )
		{
			if ( CadComparar ( SEtxNombre ( SLisEtxElemento ( p_lisObj, iElem ) ), p_cNombre ) == 1 )
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

int	SLisEtxLiberacionMemoriaActivada ( SListaEntradasExt * p_lisObj )
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

void SLisEtxActivarLiberacionMemoria ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}

void SLisEtxDesactivarLiberacionMemoria ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}



