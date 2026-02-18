#include "SEntrada.h"

#include "TiposDatosConfig.h"

SEntrada * SEtrCrearDef ()
{
	return ( SEtrCrear ( NULL ) );
}

SEntrada * SEtrCrear ( const char * p_cNombre )
{
	SEntrada * p_etrObj;
	
	p_etrObj = (SEntrada *) MemReservar ( sizeof ( SEntrada ) );
	if ( ES_VALIDO ( p_etrObj ) )
	{
		if ( SEtrEstablecerNombre ( p_etrObj,  p_cNombre ) == 1 )
		{
			p_etrObj->p_cDefinicion = NULL;
		}
		else
		{
			SEtrDestruir ( &p_etrObj );
		}
	}
	return ( p_etrObj );
}

SEntrada * SEtrCrearExt ( const char * p_cNombre, const char * p_cDefinicion )
{
	SEntrada * p_etrObj;

	p_etrObj = SEtrCrear ( p_cNombre );
	if ( ES_VALIDO ( p_etrObj ) )
	{
		if ( SEtrEstablecerDefinicion ( p_etrObj, p_cDefinicion ) == 0 )
		{
			SEtrDestruir ( &p_etrObj );
		}
	}
	return ( p_etrObj );
}

void SEtrDestruir ( SEntrada ** p_p_etrObj )
{
	SEntrada * p_etrObj;
	
	if ( ES_VALIDO ( p_p_etrObj ) )
	{
		p_etrObj = *p_p_etrObj;

		if ( ES_VALIDO ( p_etrObj ) )
		{
			MemLiberar ( (void **) &(p_etrObj->p_cNombre) );
			MemLiberar ( (void **) &(p_etrObj->p_cDefinicion) );
			MemLiberar ( (void **) p_p_etrObj );
		}
	}
}

int SEtrEsValido ( SEntrada * p_etrObj )
{
	int iRes;

	if ( ES_VALIDO ( p_etrObj ) )
	{
		if ( ( CadEsTokenValido ( p_etrObj->p_cNombre ) == 1 ) &&
			 ( CadLongitud ( p_etrObj->p_cDefinicion ) > 0 ) )
		{
			iRes = PatEvaluar ( p_etrObj->p_cNombre, p_etrObj->p_cDefinicion );
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

const char * SEtrNombre ( SEntrada * p_etrObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_etrObj ) )
	{
		p_cRes = p_etrObj->p_cNombre;
	}
	else
	{
		p_cRes = 0;
	}
	return ( p_cRes );
}

const char * SEtrDefinicion ( SEntrada * p_etrObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_etrObj ) )
	{
		p_cRes = (const char *) p_etrObj->p_cDefinicion;
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SEtrEstablecer ( SEntrada * p_etrObj, const char * p_cNombre, const char * p_cDefinicion )
{
	int iRes;

	if ( SEtrEsValido ( p_etrObj ) == 1 )
	{
		if ( CadEsTokenValido ( p_cNombre ) == 1 )
		{
			if ( ( CadCopiar ( p_etrObj->p_cNombre, p_cNombre ) == 1 ) &&
				 ( CadCopiar ( p_etrObj->p_cDefinicion, p_cDefinicion ) == 1 ) )
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


int SEtrEstablecerNombre ( SEntrada * p_etrObj, const char * p_cNombre )
{
	int iRes;

	if ( SEtrEsValido ( p_etrObj ) == 1 )
	{
		if ( CadEsTokenValido ( p_cNombre ) == 1 )
		{
			iRes = CadCopiar ( p_etrObj->p_cNombre, p_cNombre );
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


int SEtrEstablecerDefinicion ( SEntrada * p_etrObj, const char * p_cDefinicion )
{
	int iRes;

	if ( SEtrEsValido ( p_etrObj ) == 1 )
	{
		iRes = CadCopiar ( p_etrObj->p_cDefinicion, p_cDefinicion );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SEntrada * SEtrDuplicar (  SEntrada * p_etrObj )
{
	SEntrada * p_etrRes;

	if ( SEtrEsValido ( p_etrObj ) == 1 ) 
	{
		p_etrRes = SEtrCrear ( p_etrObj->p_cNombre );
		if ( ES_VALIDO ( p_etrRes ) )
		{
			SEtrEstablecerDefinicion ( p_etrRes, p_etrObj->p_cDefinicion );
		}
	}
	else
	{
		p_etrRes = NULL;
	}
	return ( p_etrRes );
}

int SEtrEsIgual ( SEntrada * p_etrObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtrEsValido ( p_etrObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etrObj->p_cNombre, p_cNombre ) == 1 )
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

int SEtrEsMenor ( SEntrada * p_etrObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtrEsValido ( p_etrObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etrObj->p_cNombre, p_cNombre ) == 2 )
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

int SEtrEsMayor ( SEntrada * p_etrObj, const char * p_cNombre )
{
	int iRes;

	if ( ( SEtrEsValido ( p_etrObj ) == 1 ) && ( CadEsTokenValido ( p_cNombre ) == 1 ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_etrObj->p_cNombre, p_cNombre ) == 3 )
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


