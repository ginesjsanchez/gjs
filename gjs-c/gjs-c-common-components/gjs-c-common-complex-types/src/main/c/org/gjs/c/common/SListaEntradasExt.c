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

int SLisEtxInsertarElem ( SListaEntradasExt * p_lisObj, int iPosAnt, SEntradaExt * p_etxDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_etxDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtxInsertarAlInicio ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	return ( SLisEtxInsertarElem ( p_lisObj, -1, p_etxDatos ) );
}

int SLisEtxInsertarAlFinal ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisEtxInsertarElem ( p_lisObj, SLisEtxNumElementos ( p_lisObj ), p_etxDatos );
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

int SLisEtxPosicion ( SListaEntradasExt * p_lisObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispPosicion ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

SEntradaExt * SLisEtxActual ( SListaEntradasExt * p_lisObj )
{
	SEntradaExt *	p_etxRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_etxRes = (SEntradaExt *) SLispActual ( p_lisObj->p_lisDatos );
	}
	else
	{
		p_etxRes = NULL;
	}
	return ( p_etxRes );
}

void SLisEtxInicio ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispInicio ( p_lisObj->p_lisDatos );
	}
}

void SLisEtxFinal ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispFinal ( p_lisObj->p_lisDatos );
	}
}

void SLisEtxSiguiente ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispSiguiente ( p_lisObj->p_lisDatos );
	}
}

void SLisEtxAnterior ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispAnterior ( p_lisObj->p_lisDatos );
	}
}

void SLisEtxMoverA ( SListaEntradasExt * p_lisObj, int iElem )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispMoverA ( p_lisObj->p_lisDatos, iElem );
	}
}

void SLisEtxDeposicionar ( SListaEntradasExt * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDeposicionar ( p_lisObj->p_lisDatos );
	}
}

int SLisEtxEsNulo ( SListaEntradasExt * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEsNulo ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEtxEstaEnFinal ( SListaEntradasExt * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEstaEnFinal ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEtxEstaEnIncio ( SListaEntradasExt * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEstaEnIncio ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEtxInsertar ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	return ( SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_etxDatos ) );
}

int SLisEtxInsertarDelante ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_etxDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisEtxInsertarDetras ( SListaEntradasExt * p_lisObj, SEntradaExt * p_etxDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_etxDatos );
	}
	else
	{
		iRes = 0;
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



