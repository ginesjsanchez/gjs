#include "SArbolBin.h"


#include "TiposBasicosConfig.h"








SArbolBin * SArbBinCrear ()
{
	SArbolBin * p_arbbObj;

	p_arbbObj = (SArbolBin *) MemReservar ( sizeof ( SArbolBin ) );
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_arbbObj->p_nodbRaiz = NULL;
		p_arbbObj->p_nodbActual = NULL;
	}
	return ( p_arbbObj );
}

void SArbBinDestruir ( SArbolBin ** p_p_arbbObj )
{
	SArbolBin * p_arbbObj;

	if ( ES_VALIDO ( p_p_arbbObj ) )
	{
		p_arbbObj = *p_p_arbbObj;
		if ( ES_VALIDO ( p_arbbObj ) )
		{
			SArbBinVaciar ( p_arbbObj );
			MemLiberar ( (void **) p_p_arbbObj );
		}
	}
}

SNodoBin * SArbBinRaiz ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_nodbRes = p_arbbObj->p_nodbRaiz;
	}
	else
	{
		p_nodbRes = NULL;
	}
	return ( p_nodbRes );
}

int SArbBinEstablecerRaiz ( SArbolBin * p_arbbObj, SNodoBin * p_nodbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_arbbObj->p_nodbRaiz = p_nodbObj;
		if ( ES_VALIDO ( p_arbbObj->p_nodbRaiz ) )
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

int SArbBinEstaVacio ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_NULO ( p_arbbObj->p_nodbRaiz ) )
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

int SArbBinNiveles ( SArbolBin * p_arbbObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbRaiz ) )
		{
			iNiveles = SNodBinNivelesInferiores ( p_arbbObj->p_nodbRaiz ) + 1;
		}
		else
		{
			iNiveles = 0;
		}
	}
	else
	{
		iNiveles = 0;
	}
	return ( iNiveles );
}

int SArbBinNumNodos ( SArbolBin * p_arbbObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbRaiz ) )
		{
			iNodos = SNodBinNodosInferiores ( p_arbbObj->p_nodbRaiz ) + 1;
		}
		else
		{
			iNodos = 0;
		}
	}
	else
	{
		iNodos = 0;
	}
	return ( iNodos );
}

void SArbBinVaciar ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbObj;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbRaiz ) )
		{
			SArbBinMoverAPrimPreorden ( p_arbbObj );
			while ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
			{
				p_nodbObj = p_arbbObj->p_nodbActual;
				SArbBinMoverASigPreorden ( p_arbbObj );
				SNodBinDestruir ( &p_nodbObj, 0 );
			}
		}
	}
}

SNodoBin * SArbBinActual ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_nodbRes = p_arbbObj->p_nodbActual;
	}
	else
	{
		p_nodbRes = NULL;
	}
	return ( p_nodbRes );
}

SNodoBin * SArbBinPadre ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_nodbRes = SNodBinPadre ( p_arbbObj->p_nodbActual );
		}
		else
		{
			p_nodbRes = NULL;
		}
	}
	else
	{
		p_nodbRes = NULL;
	}
	return ( p_nodbRes );
}

SNodoBin * SArbBinHijoDer ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_nodbRes = SNodBinHijoDer ( p_arbbObj->p_nodbActual );
		}
		else
		{
			p_nodbRes = NULL;
		}
	}
	else
	{
		p_nodbRes = NULL;
	}
	return ( p_nodbRes );
}

SNodoBin * SArbBinHijoIzq ( SArbolBin * p_arbbObj )
{
	SNodoBin * p_nodbRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_nodbRes = SNodBinHijoIzq ( p_arbbObj->p_nodbActual );
		}
		else
		{
			p_nodbRes = NULL;
		}
	}
	else
	{
		p_nodbRes = NULL;
	}
	return ( p_nodbRes );
}

int SArbBinTienePadre ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTienePadre ( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHijos ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHijos( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHermano ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHermano ( p_arbbObj->p_nodbActual );
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

int SArbBinEsHijoIzqDelPadre ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinEsHijoIzqDelPadre ( p_arbbObj->p_nodbActual );
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

int SArbBinEsHijoDerDelPadre ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinEsHijoDerDelPadre ( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHijoIzq ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHijoIzq ( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHijoDer ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHijoDer ( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHermanoIzq ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHermanoIzq ( p_arbbObj->p_nodbActual );
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

int SArbBinTieneHermanoDer ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			iRes = SNodBinTieneHermanoDer ( p_arbbObj->p_nodbActual );
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

void SArbBinMoverARaiz ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_arbbObj->p_nodbActual = p_arbbObj->p_nodbRaiz;
	}
}

void SArbBinMoverAPadre ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_arbbObj->p_nodbActual = SNodBinPadre ( p_arbbObj->p_nodbActual );
		}
	}
}

void SArbBinMoverAHijoIzq ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_arbbObj->p_nodbActual = SNodBinHijoIzq ( p_arbbObj->p_nodbActual );
		}
	}
}

void SArbBinMoverAHijoDer ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			p_arbbObj->p_nodbActual = SNodBinHijoDer ( p_arbbObj->p_nodbActual );
		}
	}
}

void SArbBinMoverAHermano ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			if ( SNodBinEsHijoIzqDelPadre ( p_arbbObj->p_nodbActual ) == 1 )
			{
				SArbBinMoverAPadre ( p_arbbObj );
				SArbBinMoverAHijoDer ( p_arbbObj );
			}
			else
			{
				SArbBinMoverAPadre ( p_arbbObj );
				SArbBinMoverAHijoIzq ( p_arbbObj );
			}
		}
	}
}

void SArbBinMoverAPrimPreorden ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverARaiz ( p_arbbObj );
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			while ( ES_VALIDO ( p_arbbObj->p_nodbActual ) && ( SNodBinTieneHijos ( p_arbbObj->p_nodbActual ) == 1 ) )
			{
				SArbBinMoverAHijoIzq ( p_arbbObj );
			}
		}
	}
}

void SArbBinMoverASigPreorden ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			if ( SNodBinEsHijoIzqDelPadre ( p_arbbObj->p_nodbActual ) == 1 )
			{
				if ( SNodBinTieneHermano ( p_arbbObj->p_nodbActual ) == 1 )
				{
					SArbBinMoverAHermano ( p_arbbObj );
					while ( ES_VALIDO ( p_arbbObj->p_nodbActual ) && ( SNodBinTieneHijos ( p_arbbObj->p_nodbActual ) == 1 ) )
					{
						SArbBinMoverAHijoIzq ( p_arbbObj );
					}
				}
				else
				{
					SArbBinMoverAPadre ( p_arbbObj );
				}
			}
			else
			{
				SArbBinMoverAPadre ( p_arbbObj );
			}
		}
	}
}

void SArbBinMoverAAntPreorden ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
		{
			if ( SNodBinTieneHijoDer ( p_arbbObj->p_nodbActual ) == 1 )
			{
				SArbBinMoverAHijoDer ( p_arbbObj );
			}
			else if ( SNodBinTieneHijoIzq ( p_arbbObj->p_nodbActual ) == 1 )
			{
				SArbBinMoverAHijoIzq ( p_arbbObj );
			}
			else
			{
				if ( SNodBinEsHijoDerDelPadre ( p_arbbObj->p_nodbActual ) == 1 )
				{
					SArbBinMoverAHermano ( p_arbbObj );
				}
				else
				{
					SArbBinDesposicionar ( p_arbbObj );
				}
			}
		}
	}
}

void SArbBinMoverAUltPreorden ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		SArbBinMoverARaiz ( p_arbbObj );
	}
}

void SArbBinDesposicionar ( SArbolBin * p_arbbObj )
{
	if ( ES_VALIDO ( p_arbbObj ) )
	{
		p_arbbObj->p_nodbActual = NULL;
	}
}

int	SArbBinEstaPosicionado ( SArbolBin * p_arbbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) )
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

int SArbBinEnraizar ( SArbolBin * p_arbbObj, SNodoBin * p_nodbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbActual ) && ES_VALIDO ( p_nodbObj ) )
		{
			if ( SNodBinTieneHijoDer ( p_arbbObj->p_nodbActual ) == 1 )
			{
				iRes = 0;
			}
			else
			{
				SNodBinEmpadronar ( p_nodbObj, p_arbbObj->p_nodbActual );
				if ( SNodBinTieneHijoIzq ( p_arbbObj->p_nodbActual ) == 0 )
				{
					if ( SNodBinEstHijoIzq ( p_arbbObj->p_nodbActual, p_nodbObj, 1 ) == 1 )
					{
						iRes = 1;
						SArbBinMoverAHijoIzq ( p_arbbObj );
					}
					else
					{
						iRes = 0;
					}
				}
				else
				{
					if ( SNodBinEstHijoDer ( p_arbbObj->p_nodbActual, p_nodbObj, 1 ) == 1 )
					{
						iRes = 1;
						SArbBinMoverAHijoDer ( p_arbbObj );
					}
					else
					{
						iRes = 0;
					}
				}
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

int SArbBinVerificar ( SArbolBin * p_arbbObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbObj ) )
	{
		if ( ES_VALIDO ( p_arbbObj->p_nodbRaiz ) )
		{
			iRes = SNodBinVerificar ( p_arbbObj->p_nodbRaiz, iCorregir );
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



