#include "SEntradaExt.h"

#include "TiposDatosConfig.h"


SEntradaExt * SEtxCrearDef ()
{
	return ( SEtxCrear ( NULL ) );
}

SEntradaExt * SEtxCrear ( const char * p_cNombre )
{
	SEntradaExt * p_etxObj;
	
	p_etxObj = (SEntradaExt *) MemReservar ( sizeof ( SEntradaExt ) );
	if ( ES_VALIDO ( p_etxObj ) )
	{
		if ( SEtxEstablecerNombre ( p_etxObj,  p_cNombre ) == 1 )
		{
			p_etxObj->p_lisDefiniciones = NULL;
		}
		else
		{
			SEtxDestruir ( &p_etxObj );
		}
	}
	return ( p_etxObj );
}

SEntradaExt * SEtxCrearExt ( const char * p_cNombre, const char * p_cDefinicion )
{
	SEntradaExt * p_etxObj;

	p_etxObj = SEtxCrear ( p_cNombre );
	if ( ES_VALIDO ( p_etxObj ) )
	{
		if ( SEtxInsertarDefinicion ( p_etxObj, p_cDefinicion ) == 0 )
		{
			SEtxDestruir ( &p_etxObj );
		}
	}
	return ( p_etxObj );
}

void SEtxDestruir ( SEntradaExt ** p_p_etxObj )
{
	SEntradaExt * p_etxObj;
	
	if ( ES_VALIDO ( p_p_etxObj ) )
	{
		p_etxObj = *p_p_etxObj;

		if ( ES_VALIDO ( p_etxObj ) )
		{
			MemLiberar ( (void **) &(p_etxObj->p_cNombre) );
			MemLiberar ( (void **) &(p_etxObj->p_lisDefiniciones) );
			MemLiberar ( (void **) p_p_etxObj );
		}
	}
}

int SEtxEsValido ( SEntradaExt * p_etxObj )
{
	int iRes;

	if ( ES_VALIDO ( p_etxObj ) )
	{
		if ( ( CadEsTokenValido ( p_etxObj->p_cNombre ) == 1 ) &&
			 ( SLisLitNumElementos ( p_etxObj->p_lisDefiniciones ) > 0 ) )
		{
			iRes = 1; //PatEvaluar ( p_etxObj->p_cNombre, p_etxObj->p_lisDefiniciones );
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

const char * SEtxNombre ( SEntradaExt * p_etxObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_etxObj ) )
	{
		p_cRes = p_etxObj->p_cNombre;
	}
	else
	{
		p_cRes = 0;
	}
	return ( p_cRes );
}

const char * SEtxDefinicionPrinc ( SEntradaExt * p_etxObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_etxObj ) )
	{
		p_cRes = SLisLitElemento ( p_etxObj->p_lisDefiniciones, 0 );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SEtxEstablecer ( SEntradaExt * p_etxObj, const char * p_cNombre, const char * p_cDefinicion )
{
	int		iRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		if ( CadEsTokenValido ( p_cDefinicion ) == 1 )
		{
			if ( ( CadCopiar ( p_etxObj->p_cNombre, p_cNombre ) == 1 ) && 
				( SEtxEstablecerDefinicionPrinc ( p_etxObj, p_cDefinicion ) == 1 ) )
			{
				iRes = 1;
			}
			else
			{
				iRes = 0;
			}
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEtxEstablecerNombre ( SEntradaExt * p_etxObj, const char * p_cNombre )
{
	int iRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		if ( CadEsTokenValido ( p_cNombre ) == 1 )
		{
			iRes = CadCopiar ( p_etxObj->p_cNombre, p_cNombre );
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEtxEstablecerDefinicionPrinc ( SEntradaExt * p_etxObj, const char * p_cDefinicion )
{
	return ( SEtxEstablecerDefinicion ( p_etxObj, 0, p_cDefinicion ) );
}

int SEtxNumDefiniciones ( SEntradaExt * p_etxObj )
{
	int iRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		iRes = SLisLitNumElementos ( p_etxObj->p_lisDefiniciones );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

const char * SEtxDefinicion ( SEntradaExt * p_etxObj, int iDef )
{
	const char * p_cRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		p_cRes = SLisLitElemento ( p_etxObj->p_lisDefiniciones, iDef );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SEtxEstablecerDefinicion ( SEntradaExt * p_etxObj, int iDef, const char * p_cDefinicion ) 
{
	int iRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		iRes = SLisLitEstablecerElem ( p_etxObj->p_lisDefiniciones, iDef, (char *) p_cDefinicion );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEtxInsertarDefinicion ( SEntradaExt * p_etxObj, const char * p_cDefinicion )
{
	int iRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 )
	{
		iRes = SLisLitInsertarAlFinal ( p_etxObj->p_lisDefiniciones, (char *) p_cDefinicion );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SEntradaExt * SEtxDuplicar (  SEntradaExt * p_etxObj )
{
	int					iDef;
	SEntradaExt *		p_etxRes;

	if ( SEtxEsValido ( p_etxObj ) == 1 ) 
	{
		p_etxRes = SEtxCrear ( p_etxObj->p_cNombre );
		if ( ES_VALIDO ( p_etxRes ) )
		{
			for ( iDef = 0; iDef < SEtxNumDefiniciones ( p_etxObj ); iDef = iDef + 1 )
			{
				SEtxInsertarDefinicion ( p_etxRes, SEtxDefinicion ( p_etxObj, iDef ) );
			}
		}
	}
	else
	{
		p_etxRes = NULL;
	}
	return ( p_etxRes );
}

int SEtxEsIgual ( SEntradaExt * p_etxObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtxEsValido ( p_etxObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etxObj->p_cNombre, p_cNombre ) == 1 )
		{
			iRes = 1;
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEtxEsMenor ( SEntradaExt * p_etxObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtxEsValido ( p_etxObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etxObj->p_cNombre, p_cNombre ) == 2 )
		{
			iRes = 1;
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEtxEsMayor ( SEntradaExt * p_etxObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtxEsValido ( p_etxObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etxObj->p_cNombre, p_cNombre ) == 3 )
		{
			iRes = 1;
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


