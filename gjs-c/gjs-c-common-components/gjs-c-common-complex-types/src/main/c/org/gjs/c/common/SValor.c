#include "SValor.h"

#include "TiposDatosConfig.h"








static void SValInicializar ( SValor * p_valObj, int iTipo, int iMaxTam );



SValor * SValCrearDef ()
{
	SValor * p_valObj;

	p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
	if ( ES_VALIDO ( p_valObj ) )
	{
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_DEFECTO, CAD_TAM_DEFECTO );
	}
	return ( p_valObj );
}

SValor * SValCrear ( int iTipo )
{
    SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
        p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, iTipo, CAD_TAM_DEFECTO );
    }
	return ( p_valObj );
}

SValor * SValCrearExt ( int iTipo, int iMaxTam )
{
    SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
        p_valObj->p_cadValor = NULL;
        SValInicializar ( p_valObj, iTipo, iMaxTam );
    }
	return ( p_valObj );
}

SValor * SValCrearEntero ( int iValor )
{
    SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_ENTERO, 0 );
		SValEstablecerValorEntero ( p_valObj, iValor );
	}
	return ( p_valObj );
}

SValor * SValCrearEnteroLargo ( long lValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_ENTERO, 0 );
		SValEstablecerValorEnteroLargo ( p_valObj, lValor );
	}
	return ( p_valObj );
}

SValor * SValCrearEnteroSinSigno ( unsigned int uiValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_ENTERO, 0 );
		SValEstablecerValorEnteroSinSigno ( p_valObj, uiValor );
	}
	return ( p_valObj );
}

SValor * SValCrearEnteroLargoSinSigno ( unsigned long ulValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_ENTERO, 0 );
		SValEstablecerValorEnteroLargoSinSigno ( p_valObj, ulValor );
	}
	return ( p_valObj );
}

SValor * SValCrearReal ( float fValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_REAL, 0 );
		SValEstablecerValorReal ( p_valObj, fValor );
	}
	return ( p_valObj );
}

SValor * SValCrearRealDoble ( double dValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_NUMERO_REAL, 0 );
		SValEstablecerValorRealDoble ( p_valObj, dValor );
	}
	return ( p_valObj );
}

SValor * SValCrearCadena ( const char * p_cValor )
{
   SValor * p_valObj;

    p_valObj = (SValor *) MemReservar ( sizeof ( SValor ) );
    if ( ES_VALIDO ( p_valObj ) )
    {
		p_valObj->p_cadValor = NULL;
		SValInicializar ( p_valObj, TIP_CADENA, 0 );
		SValEstablecerValorLiteral ( p_valObj, p_cValor );
	}
	return ( p_valObj );
}

void SValDestruir ( SValor ** p_p_valObj )
{
	SValor * p_valObj;
	
	if ( ES_VALIDO ( p_p_valObj ) )
	{
		p_valObj = *p_p_valObj;
		if ( ES_VALIDO ( p_valObj ) )
		{
			SCadcDestruir ( &(p_valObj->p_cadValor) );
		}
		MemLiberar ( (void**) p_p_valObj );
	}
}

int SValTipo ( SValor * p_valObj )
{
	int iRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		iRes = p_valObj->iTipo;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SValEsValido ( SValor * p_valObj )
{
	int iRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ( TipEsValido ( p_valObj->iTipo ) == 1 ) && ( SCadcEsValida ( p_valObj->p_cadValor ) == 1 ) )
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

SCadenaConv * SValValor ( SValor * p_valObj )
{
	SCadenaConv * p_cadRes;
	
	if ( ES_VALIDO ( p_valObj ) )
	{
		p_cadRes = p_valObj->p_cadValor;
	}
	else
	{
		p_cadRes = NULL;
	}
	return ( p_cadRes );
}

byte SValValorByte ( SValor * p_valObj )
{
	byte byRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				byRes = ( byte ) SCadcValorEntero ( p_valObj->p_cadValor );
			}
			else
			{
				byRes = 0;
			}
		}
		else
		{
			byRes = 0;
		}
	}
	else
	{
		byRes = 0;
	}
	return ( byRes );
}

int SValValorBooleano ( SValor * p_valObj )
{
	int iRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( SCadcValorEntero ( p_valObj->p_cadValor ) == 0 )
				{
					iRes = 0;
				}
				else
				{
					iRes = 1;
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

unsigned long SValValorNatural ( SValor * p_valObj )
{
	unsigned long ulRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
			{
				ulRes = (unsigned long) SCadcValorEnteroLargo ( p_valObj->p_cadValor );
			}
			else
			{
				ulRes = 0;
			}
		}
		else
		{
			ulRes = 0;
		}
	}
	else
	{
		ulRes = 0;
	}
	return ( ulRes );
}

long SValValorEntero ( SValor * p_valObj )
{
	long lRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsEntero ( p_valObj->iTipo ) == 1 )
			{
				lRes = SCadcValorEnteroLargo ( p_valObj->p_cadValor );
			}
			else
			{
				lRes = 0;
			}
		}
		else
		{
			lRes = 0;
		}
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

double SValValorReal ( SValor * p_valObj )
{
	double dRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsReal ( p_valObj->iTipo ) == 1 )
			{
				dRes = SCadcValorRealDoble ( p_valObj->p_cadValor );
			}
			else
			{
				dRes = 0.0;
			}
		}
		else
		{
			dRes = 0.0;
		}
	}
	else
	{
		dRes = 0.0;
	}
	return ( dRes );
}

const char * SValValorCadena ( SValor * p_valObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( TipEsCadena ( p_valObj->iTipo ) == 1 )
			{
				p_cRes = SCadValorConstante ( SCadcCadena ( p_valObj->p_cadValor ) );
			}
			else
			{
				p_cRes = NULL;
			}
		}
		else
		{
			p_cRes = NULL;
		}
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

byte * SValValorBinario ( SValor * p_valObj )
{
	// TODO
	return ( NULL );
}

int SValMaxTam ( SValor * p_valObj )
{
	int iRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			iRes = SCadMaxTam ( SCadcCadena ( p_valObj->p_cadValor ) );
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

void SValEstablecerValorByte ( SValor * p_valObj, byte byValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( byValor != 0 )
				{
					byValor = 1;
				}
			}
			SCadcCopiarCaracter ( p_valObj->p_cadValor, byValor );
		}
	}
}

void SValEstablecerValorEntero ( SValor * p_valObj, int iValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( iValor != 0 )
				{
					iValor = 1;
				}
				SCadcCopiarEntero ( p_valObj->p_cadValor, iValor );
			}
			else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
			{
				if ( iValor < 0 )
				{
					iValor = 0;
				}
				SCadcCopiarEntero ( p_valObj->p_cadValor, iValor );
			}
			else 
			{
				SCadcCopiarEntero ( p_valObj->p_cadValor, iValor );
			}
		}
	}
}

void SValEstablecerValorEnteroLargo ( SValor * p_valObj, long lValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( lValor != 0 )
				{
					lValor = 1;
				}
				SCadcCopiarEnteroLargo ( p_valObj->p_cadValor, lValor );
			}
			else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
			{
				if ( lValor < 0 )
				{
					lValor = 0;
				}
				SCadcCopiarEnteroLargo ( p_valObj->p_cadValor, lValor );
			}
			else 
			{
				SCadcCopiarEnteroLargo ( p_valObj->p_cadValor, lValor );
			}
		}
	}
}

void SValEstablecerValorEnteroSinSigno ( SValor * p_valObj, unsigned int uiValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( uiValor != 0 )
				{
					uiValor = 1;
				}
				SCadcCopiarEnteroSinSigno ( p_valObj->p_cadValor, uiValor );
			}
			else 
			{
				SCadcCopiarEnteroSinSigno ( p_valObj->p_cadValor, uiValor );
			}
		}
	}
}

void SValEstablecerValorEnteroLargoSinSigno ( SValor * p_valObj, unsigned long ulValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( ulValor != 0 )
				{
					ulValor = 1;
				}
				SCadcCopiarEnteroLargoSinSigno ( p_valObj->p_cadValor, ulValor );
			}
			else 
			{
				SCadcCopiarEnteroLargoSinSigno ( p_valObj->p_cadValor, ulValor );
			}
		}
	}
}

void SValEstablecerValorReal ( SValor * p_valObj, float fValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( fValor != 0.0 )
				{
					fValor = 1.0;
				}
				SCadcCopiarReal ( p_valObj->p_cadValor, fValor );
			}
			else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
			{
				if ( fValor < 0.0 )
				{
					fValor = 0.0;
				}
				SCadcCopiarReal ( p_valObj->p_cadValor, fValor );
			}
			else 
			{
				SCadcCopiarReal ( p_valObj->p_cadValor, fValor );
			}
		}
	}
}

void SValEstablecerValorRealDoble ( SValor * p_valObj, double dValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
			{
				if ( dValor != 0.0 )
				{
					dValor = 1.0;
				}
				SCadcCopiarRealDoble ( p_valObj->p_cadValor, dValor );
			}
			else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
			{
				if ( dValor < 0.0 )
				{
					dValor = 0.0;
				}
				SCadcCopiarRealDoble ( p_valObj->p_cadValor, dValor );
			}
			else 
			{
				SCadcCopiarRealDoble ( p_valObj->p_cadValor, dValor );
			}
		}
	}
}

void SValEstablecerValorBinario ( SValor * p_valObj, byte * p_byValor ) {
	// TODO
}

void SValEstablecerValorLiteral ( SValor * p_valObj, const char * p_cValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( ES_VALIDO ( p_cValor ) )
			{
				if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
				{
					if ( CadEsNumericaExt ( p_cValor, 1 ) == 1 )
					{
						if ( p_cValor [ 0 ] == '1' )
						{
							SCadcCopiarEntero ( p_valObj->p_cadValor, 1 );
						}
						else
						{
							SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
						}
					}
					else
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
					}
				}
				else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
				{
					if ( ( CadEsNumerica ( p_cValor ) == 1 ) && ( p_cValor [ 0 ] != '-' ) )
					{
						SCadcCopiarLit ( p_valObj->p_cadValor, p_cValor );
					}
					else
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
					}
				}
				else if ( TipEsNumero ( p_valObj->iTipo ) == 1 )
				{
					if ( CadEsNumerica ( p_cValor ) == 0 )
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
					}
					else
					{
						SCadcCopiarLit ( p_valObj->p_cadValor, p_cValor );
					}
				}
				else
				{
					SCadcCopiarLit ( p_valObj->p_cadValor, p_cValor );
				}
			}
		}
	}
}

void SValEstablecerValorCadena ( SValor * p_valObj, SCadena * p_cadValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SValEstablecerValorLiteral ( p_valObj, SCadValorConstante ( p_cadValor ) );
		}
	}
}

void SValEstablecerValor ( SValor * p_valObj, SCadenaConv * p_cadValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( ES_VALIDO ( p_cadValor ) )
			{
				if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
				{
					if ( SCadcValorEntero (p_cadValor ) != 0 )
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 1 );
					}
					else
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
					}
				}
				else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
				{
					if ( SCadcValorEnteroLargo ( p_cadValor ) < 0 )
					{
						SCadcCopiarEntero ( p_valObj->p_cadValor, 0 );
					}
					else
					{
						SCadcCopiarEnteroLargo ( p_valObj->p_cadValor, SCadcValorEnteroLargo ( p_cadValor ) );
					}
				}
				else if ( TipEsEntero ( p_valObj->iTipo ) == 1 )
				{
					SCadcCopiarEnteroLargo ( p_valObj->p_cadValor, SCadcValorEnteroLargo ( p_cadValor ) );
				}
				else if ( TipEsReal ( p_valObj->iTipo ) == 1 )
				{
					SCadcCopiarRealDoble ( p_valObj->p_cadValor, SCadcValorRealDoble ( p_cadValor ) );
				}
				else 
				{
					SCadcCopiar ( p_valObj->p_cadValor, p_cadValor );
				}
			}
		}
	}
}

void SValEstablecerValorNumerico ( SValor * p_valObj, SCadenaNumerica * p_cadValor )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SValEstablecerValor ( p_valObj, SCadnCadenaConv ( p_cadValor ) );
		}
	}
}

void SValAsignar ( SValor * p_valObj, SValor * p_valValor )
{
	if ( ES_VALIDO ( p_valObj ) && ES_VALIDO ( p_valValor ) )
	{
		SValInicializar ( p_valObj, SValTipo ( p_valValor ), SValMaxTam ( p_valValor ) );
		SValEstablecerValor ( p_valObj, SValValor ( p_valValor ) );
	}
}

void SValLimpiar ( SValor * p_valObj )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			SCadLimpiar ( SCadcCadena ( p_valObj->p_cadValor ) );
			if ( ( TipEsBooleano ( p_valObj->iTipo ) == 1 ) || 
				 ( TipEsNumero ( p_valObj->iTipo ) == 1 ) )
			{
				SCadcCopiar ( p_valObj->p_cadValor, 0 );
			}
		}
	}
}

int SValTieneValor ( SValor * p_valObj )
{
	int iRes;

	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( ES_VALIDO ( p_valObj->p_cadValor ) )
		{
			if ( SCadLongitud ( SCadcCadena ( p_valObj->p_cadValor ) ) > 0 )
			{
				if ( ( TipEsBooleano ( p_valObj->iTipo ) == 1 ) || 
					 ( TipEsNumero ( p_valObj->iTipo ) == 1 ) )
				{
					if ( SCadcEsNumerica ( p_valObj->p_cadValor ) == 1 )
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
					iRes = 1;
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

static void SValInicializar ( SValor * p_valObj, int iTipo, int iMaxTam )
{
	if ( ES_VALIDO ( p_valObj ) )
	{
		if ( TipEsValido ( p_valObj->iTipo ) == 1 )
		{
			p_valObj->iTipo = iTipo;
		}
		else
		{
			p_valObj->iTipo = TIP_DEFECTO;
		}
		if ( TipEsCadena ( p_valObj->iTipo ) == 1 )
		{
			if ( iMaxTam <= 0 )
			{
				iMaxTam = CAD_TAM_DEFECTO;
			}
			p_valObj->p_cadValor = SCadcCrear ( iMaxTam );
		}
		else if ( TipEsBooleano ( p_valObj->iTipo ) == 1 )
		{
			p_valObj->p_cadValor = SCadcCrear ( 1 );
		}
		else if ( TipEsNatural ( p_valObj->iTipo ) == 1 )
		{
			p_valObj->p_cadValor = SCadcCrear ( TIP_MAX_TAM_CAD_ENTERO_LARGO );
		}
		else if ( TipEsEntero ( p_valObj->iTipo ) == 1 )
		{
			p_valObj->p_cadValor = SCadcCrear ( TIP_MAX_TAM_CAD_ENTERO_LARGO );
		}
		else if ( TipEsReal ( p_valObj->iTipo ) == 1 )
		{
			p_valObj->p_cadValor = SCadcCrear ( TIP_MAX_TAM_CAD_REAL_DOBLE );
		}
		else
		{
			p_valObj->iTipo = TIP_NINGUNO;
			p_valObj->p_cadValor = NULL;
		}
	}
}

SValor * SValDuplicar ( SValor * p_valObj )
{
    SValor * p_valRes;

	if ( ES_VALIDO ( p_valObj ) )
    {
		  p_valRes = SValCrearExt ( p_valObj->iTipo, SValMaxTam ( p_valObj ) );
		  if ( ES_VALIDO ( p_valRes ) )
		  {
			  SValEstablecerValor ( p_valRes, p_valObj->p_cadValor );
		  }
	}
	else
	{
		p_valRes = NULL;
	}
	return ( p_valRes );
}



