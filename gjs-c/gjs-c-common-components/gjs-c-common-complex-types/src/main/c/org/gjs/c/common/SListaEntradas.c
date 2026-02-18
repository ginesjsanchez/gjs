#include "SListaEntradas.h"

#include "TiposDatosConfig.h"




SListaEntradas * SLisEtrCrear ()
{
	SListaEntradas * p_lisObj;
	
	p_lisObj = (SListaEntradas *) MemReservar ( sizeof ( SListaEntradas ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLispCrear ();
	}
	return ( p_lisObj );
}

void SLisEtrDestruir ( SListaEntradas ** p_p_lisObj )
{
	SListaEntradas * p_lisObj;
	
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

int SLisEtrEsValida ( SListaEntradas * p_lisObj )
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

int SLisEtrEstaVacia ( SListaEntradas * p_lisObj )
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

int SLisEtrNumElementos ( SListaEntradas * p_lisObj )
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

int SLisEtrExiste ( SListaEntradas * p_lisObj, const char * p_cNombre )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cNombre ) )
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SLisEtrNumElementos ( p_lisObj ) ) && ( iRes == 0 ) )
		{
			if ( CadComparar ( SEtrNombre ( SLisEtrElemento ( p_lisObj, iElem ) ), p_cNombre ) == 1 )
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


SEntrada * SLisEtrBuscar ( SListaEntradas * p_lisObj, const char * p_cNombre )
{
	SEntrada *	p_etrRes;
	int			iEnc;
	int			iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cNombre ) )
	{
		iEnc = 0;
		iElem = 0;
		while ( ( iElem < SLisEtrNumElementos ( p_lisObj ) ) && ( iEnc == 0 ) )
		{
			p_etrRes = SLisEtrElemento ( p_lisObj, iElem );
			iEnc = CadComparar ( SEtrNombre ( p_etrRes ), p_cNombre );
			iElem = iElem + 1;
		}
		if ( iEnc == 0 )
		{
			p_etrRes = NULL;
		}
	}
	else
	{
		p_etrRes = NULL;
	}
	return ( p_etrRes );
}

SEntrada * SLisEtrElemento ( SListaEntradas * p_lisObj, int iElem )
{
	SEntrada *	p_etrRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_etrRes = (SEntrada *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		p_etrRes = NULL;
	}
	return ( p_etrRes );
}

const char * SLisEtrNombreElemento ( SListaEntradas * p_lisObj, int iElem )
{
	const char * p_cRes;

	SEntrada * p_etrRes = SLisEtrElemento ( p_lisObj, iElem );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_cRes = SEtrNombre ( p_etrRes );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

const char * SLisEtrDefinicionElemento ( SListaEntradas * p_lisObj, int iElem )
{
	const char * p_cRes;

	SEntrada * p_etrRes = SLisEtrElemento ( p_lisObj, iElem );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_cRes = SEtrDefinicion ( p_etrRes );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SLisEtrInsertar ( SListaEntradas * p_lisObj, SEntrada * p_etrDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_etrDatos ) )
	{
		iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_etrDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtrInsertarExt ( SListaEntradas * p_lisObj, const char * p_cNombre, const char * p_cDefinicion )
{
	return ( SLisEtrInsertar ( p_lisObj, SEtrCrearExt ( p_cNombre, p_cDefinicion ) ) );
}

int SLisEtrEliminar ( SListaEntradas * p_lisObj, const char * p_cNombre )
{
	int			iEnc;
	int			iElem;
	int			iRes;
	SEntrada *	p_etrRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cNombre ) )
	{
		iEnc = 0;
		iElem = 0;
		iRes = -1;
		while ( ( iElem < SLisEtrNumElementos ( p_lisObj ) ) && ( iEnc == 0 ) )
		{
			p_etrRes = SLisEtrElemento ( p_lisObj, iElem );
			iEnc = CadComparar ( SEtrNombre ( p_etrRes ), p_cNombre );
			if ( iEnc == 1 )
			{
				iRes = SLisEtrEliminarElem ( p_lisObj, iElem );
			}
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisEtrEliminarElem ( SListaEntradas * p_lisObj, int iElem )
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

int SLisEtrVaciar ( SListaEntradas * p_lisObj )
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


int	SLisEtrLiberacionMemoriaActivada ( SListaEntradas * p_lisObj )
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

void SLisEtrActivarLiberacionMemoria ( SListaEntradas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}

void SLisEtrDesactivarLiberacionMemoria ( SListaEntradas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}



