#include "SArbolBinPtr.h"



#include "TiposBasicosConfig.h"








SArbolBinPtr * SArblBinPtrCrear ()
{
	SArbolBinPtr * p_arbbpObj;

	p_arbbpObj = (SArbolBinPtr *) MemReservar ( sizeof ( SArbolBinPtr ) );
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_arbbpObj->p_nodbpRaiz = NULL;
		p_arbbpObj->p_nodbpActual = NULL;
	}
	return ( p_arbbpObj );
}

void SArbBinPtrDestruir ( SArbolBinPtr ** p_p_arbbpObj )
{
	SArbolBinPtr * p_arbbpObj;

	if ( ES_VALIDO ( p_p_arbbpObj ) )
	{
		p_arbbpObj = *p_p_arbbpObj;
		if ( ES_VALIDO ( p_arbbpObj ) )
		{
			SArbBinPtrVaciar ( p_arbbpObj );
			MemLiberar ( (void **) p_p_arbbpObj );
		}
	}
}

SNodoBinPtr * SArbBinPtrRaiz ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_nodbpRes = p_arbbpObj->p_nodbpRaiz;
	}
	else
	{
		p_nodbpRes = NULL;
	}
	return ( p_nodbpRes );
}

int SArbBinPtrEstablecerRaiz ( SArbolBinPtr * p_arbbpObj, SNodoBinPtr * p_nodbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_arbbpObj->p_nodbpRaiz = p_nodbpObj;
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpRaiz ) )
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

int SArbBinPtrEstaVacio ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_NULO ( p_arbbpObj->p_nodbpRaiz ) )
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

int SArbBinPtrNiveles ( SArbolBinPtr * p_arbbpObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpRaiz ) )
		{
			iNiveles = SNodBinPtrNivelesInferiores ( p_arbbpObj->p_nodbpRaiz ) + 1;
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

int SArbBinPtrNumNodos ( SArbolBinPtr * p_arbbpObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpRaiz ) )
		{
			iNodos = SNodBinPtrNodosInferiores ( p_arbbpObj->p_nodbpRaiz ) + 1;
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

void SArbBinPtrVaciar ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpObj;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpRaiz ) )
		{
			SArbBinPtrMoverAPrimPreorden ( p_arbbpObj );
			while ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
			{
				p_nodbpObj = p_arbbpObj->p_nodbpActual;
				SArbBinPtrMoverASigPreorden ( p_arbbpObj );
				SNodBinPtrDestruir ( &p_nodbpObj, 0 );
			}
		}
	}
}

SNodoBinPtr * SArbBinPtrActual ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_nodbpRes = p_arbbpObj->p_nodbpActual;
	}
	else
	{
		p_nodbpRes = NULL;
	}
	return ( p_nodbpRes );
}

SNodoBinPtr * SArbBinPtrPadre ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_nodbpRes = SNodBinPtrPadre ( p_arbbpObj->p_nodbpActual );
		}
		else
		{
			p_nodbpRes = NULL;
		}
	}
	else
	{
		p_nodbpRes = NULL;
	}
	return ( p_nodbpRes );
}

SNodoBinPtr * SArbBinPtrHijoDer ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_nodbpRes = SNodBinPtrHijoDer ( p_arbbpObj->p_nodbpActual );
		}
		else
		{
			p_nodbpRes = NULL;
		}
	}
	else
	{
		p_nodbpRes = NULL;
	}
	return ( p_nodbpRes );
}

SNodoBinPtr * SArbBinPtrHijoIzq ( SArbolBinPtr * p_arbbpObj )
{
	SNodoBinPtr * p_nodbpRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_nodbpRes = SNodBinPtrHijoIzq ( p_arbbpObj->p_nodbpActual );
		}
		else
		{
			p_nodbpRes = NULL;
		}
	}
	else
	{
		p_nodbpRes = NULL;
	}
	return ( p_nodbpRes );
}

int SArbBinPtrTienePadre ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTienePadre ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHijos ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHijos( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHermano ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHermano ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrEsHijoIzqDelPadre ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrEsHijoIzqDelPadre ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrEsHijoDerDelPadre ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrEsHijoDerDelPadre ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHijoIzq ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHijoIzq ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHijoDer ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHijoDer ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHermanoIzq ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHermanoIzq ( p_arbbpObj->p_nodbpActual );
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

int SArbBinPtrTieneHermanoDer ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			iRes = SNodBinPtrTieneHermanoDer ( p_arbbpObj->p_nodbpActual );
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

void SArbBinPtrMoverARaiz ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_arbbpObj->p_nodbpActual = p_arbbpObj->p_nodbpRaiz;
	}
}

void SArbBinPtrMoverAPadre ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_arbbpObj->p_nodbpActual = SNodBinPtrPadre ( p_arbbpObj->p_nodbpActual );
		}
	}
}

void SArbBinPtrMoverAHijoIzq ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_arbbpObj->p_nodbpActual = SNodBinPtrHijoIzq ( p_arbbpObj->p_nodbpActual );
		}
	}
}

void SArbBinPtrMoverAHijoDer ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			p_arbbpObj->p_nodbpActual = SNodBinPtrHijoDer ( p_arbbpObj->p_nodbpActual );
		}
	}
}

void SArbBinPtrMoverAHermano ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			if ( SNodBinPtrEsHijoIzqDelPadre ( p_arbbpObj->p_nodbpActual ) == 1 )
			{
				SArbBinPtrMoverAPadre ( p_arbbpObj );
				SArbBinPtrMoverAHijoDer ( p_arbbpObj );
			}
			else
			{
				SArbBinPtrMoverAPadre ( p_arbbpObj );
				SArbBinPtrMoverAHijoIzq ( p_arbbpObj );
			}
		}
	}
}

void SArbBinPtrMoverAPrimPreorden ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		SArbBinPtrMoverARaiz ( p_arbbpObj );
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			while ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) && ( SNodBinPtrTieneHijos ( p_arbbpObj->p_nodbpActual ) == 1 ) )
			{
				SArbBinPtrMoverAHijoIzq ( p_arbbpObj );
			}
		}
	}
}

void SArbBinPtrMoverASigPreorden ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			if ( SNodBinPtrEsHijoIzqDelPadre ( p_arbbpObj->p_nodbpActual ) == 1 )
			{
				if ( SNodBinPtrTieneHermano ( p_arbbpObj->p_nodbpActual ) == 1 )
				{
					SArbBinPtrMoverAHermano ( p_arbbpObj );
					while ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) && ( SNodBinPtrTieneHijos ( p_arbbpObj->p_nodbpActual ) == 1 ) )
					{
						SArbBinPtrMoverAHijoIzq ( p_arbbpObj );
					}
				}
				else
				{
					SArbBinPtrMoverAPadre ( p_arbbpObj );
				}
			}
			else
			{
				SArbBinPtrMoverAPadre ( p_arbbpObj );
			}
		}
	}
}

void SArbBinPtrMoverAAntPreorden ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
		{
			if ( SNodBinPtrTieneHijoDer ( p_arbbpObj->p_nodbpActual ) == 1 )
			{
				SArbBinPtrMoverAHijoDer ( p_arbbpObj );
			}
			else if ( SNodBinPtrTieneHijoIzq ( p_arbbpObj->p_nodbpActual ) == 1 )
			{
				SArbBinPtrMoverAHijoIzq ( p_arbbpObj );
			}
			else
			{
				if ( SNodBinPtrEsHijoDerDelPadre ( p_arbbpObj->p_nodbpActual ) == 1 )
				{
					SArbBinPtrMoverAHermano ( p_arbbpObj );
				}
				else
				{
					SArbBinPtrDesposicionar ( p_arbbpObj );
				}
			}
		}
	}
}

void SArbBinPtrMoverAUltPreorden ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		SArbBinPtrMoverARaiz ( p_arbbpObj );
	}
}

void SArbBinPtrDesposicionar ( SArbolBinPtr * p_arbbpObj )
{
	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		p_arbbpObj->p_nodbpActual = NULL;
	}
}

int	SArbBinPtrEstaPosicionado ( SArbolBinPtr * p_arbbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) )
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

int SArbBinPtrEnraizar ( SArbolBinPtr * p_arbbpObj, SNodoBinPtr * p_nodbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpActual ) && ES_VALIDO ( p_nodbpObj ) )
		{
			if ( SNodBinPtrTieneHijoDer ( p_arbbpObj->p_nodbpActual ) == 1 )
			{
				iRes = 0;
			}
			else
			{
				SNodBinPtrEmpadronar ( p_nodbpObj, p_arbbpObj->p_nodbpActual );
				if ( SNodBinPtrTieneHijoIzq ( p_arbbpObj->p_nodbpActual ) == 0 )
				{
					if ( SNodBinPtrEstHijoIzq ( p_arbbpObj->p_nodbpActual, p_nodbpObj, 1 ) == 1 )
					{
						iRes = 1;
						SArbBinPtrMoverAHijoIzq ( p_arbbpObj );
					}
					else
					{
						iRes = 0;
					}
				}
				else
				{
					if ( SNodBinPtrEstHijoDer ( p_arbbpObj->p_nodbpActual, p_nodbpObj, 1 ) == 1 )
					{
						iRes = 1;
						SArbBinPtrMoverAHijoDer ( p_arbbpObj );
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

int SArbBinPtrVerificar ( SArbolBinPtr * p_arbbpObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbbpObj ) )
	{
		if ( ES_VALIDO ( p_arbbpObj->p_nodbpRaiz ) )
		{
			iRes = SNodBinPtrVerificar ( p_arbbpObj->p_nodbpRaiz, iCorregir );
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



