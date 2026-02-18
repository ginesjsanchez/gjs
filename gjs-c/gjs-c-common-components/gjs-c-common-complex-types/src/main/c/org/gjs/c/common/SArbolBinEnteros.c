#include "SArbolBinEnteros.h"

#include "TiposDatosConfig.h"









SArbolBinEnteros * SArbBinEntCrear () 
{
	SArbolBinEnteros * p_arbbObj;
	
	p_arbbObj = (SArbolBinEnteros *) MemReservar ( sizeof ( SArbolBinEnteros ) );
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_arbbObj->p_arbbObj = SArbBinCrear ();
	}
	return ( p_arbbObj );
}

void SArbBinEntDestruir ( SArbolBinEnteros ** p_p_arbbObj )
{
	SArbolBinEnteros * p_arbbObj;
	
	if ( ES_VALIDO ( p_p_arbbObj ) )
	{
		p_arbbObj = *p_p_arbbObj;
		if ( ES_VALIDO ( p_arbbObj ) )
		{
			SArbBinDestruir ( &(p_arbbObj->p_arbbObj) );
			MemLiberar ( (void **) p_p_arbbObj );
		}
	}
}

int SArbBinEntRaiz ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEntero ( SArbBinRaiz ( p_arbbObj->p_arbbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEstablecerRaiz ( SArbolBinEnteros * p_arbbObj, int iValor )
{
	int 		iRes;
	SNodoBin *	p_nodbObj;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_nodbObj = SNodBinCrearEntero ( iValor );	
		if ( SArbBinEstablecerRaiz ( p_arbbObj->p_arbbObj, p_nodbObj ) == 1 )
		{
			iRes = 1;
		}
		else
		{
			SNodBinDestruir ( &p_nodbObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEstaVacio ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinEstaVacio ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntNiveles ( SArbolBinEnteros * p_arbbObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iNiveles = SArbBinNiveles ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iNiveles = 0;
	}
	return ( iNiveles );
}

int SArbBinEntNumNodos ( SArbolBinEnteros * p_arbbObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iNodos = SArbBinNumNodos ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iNodos = 0;
	}
	return ( iNodos );
}

void SArbBinEntVaciar ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinVaciar ( p_arbbObj->p_arbbObj );
	}
}

int SArbBinEntActual ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEntero ( SArbBinActual ( p_arbbObj->p_arbbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEstActual ( SArbolBinEnteros * p_arbbObj, int iValor )
{
	int 		iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEstablecerEntero ( SArbBinActual ( p_arbbObj->p_arbbObj ), iValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntPadre ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEntero ( SArbBinPadre ( p_arbbObj->p_arbbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntHijoDer ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEntero ( SArbBinHijoDer ( p_arbbObj->p_arbbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntHijoIzq ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SNodBinEntero ( SArbBinHijoIzq ( p_arbbObj->p_arbbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return (iRes );
}

int SArbBinEntTienePadre ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTienePadre ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHijos ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHijos ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHermano ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHermano ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEsHijoIzqDelPadre ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinEsHijoIzqDelPadre ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEsHijoDerDelPadre ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinEsHijoDerDelPadre ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHijoIzq ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHijoIzq ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHijoDer ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHijoDer ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHermanoIzq ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHermanoIzq ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntTieneHermanoDer ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinTieneHermanoDer ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SArbBinEntMoverARaiz ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverARaiz ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAPadre ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAPadre ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAHijoIzq ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAHijoIzq ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAHijoDer ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAHijoDer ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAHermano ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAHermano ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAPrimPreorden ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAPrimPreorden ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverASigPreorden ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverASigPreorden ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAAntPreorden ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAAntPreorden ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntMoverAUltPreorden ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverAUltPreorden ( p_arbbObj->p_arbbObj );
	}
}

void SArbBinEntDesposicionar ( SArbolBinEnteros * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinDesposicionar ( p_arbbObj->p_arbbObj );
	}
}

int	SArbBinEntEstaPosicionado ( SArbolBinEnteros * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinEstaPosicionado ( p_arbbObj->p_arbbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntEnraizar ( SArbolBinEnteros * p_arbbObj, int iValor )
{
	SNodoBin * 	p_nodbObj;
	int 		iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_nodbObj = SNodBinCrearEntero ( iValor );	
		if ( SArbBinEnraizar ( p_arbbObj->p_arbbObj, p_nodbObj ) == 1 )
		{
			iRes = 1;
		}
		else
		{
			SNodBinDestruir ( &p_nodbObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbBinEntVerificar ( SArbolBinEnteros * p_arbbObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		iRes = SArbBinVerificar ( p_arbbObj->p_arbbObj, iCorregir );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}



