#include "SArbolPtr.h"



#include "TiposBasicosConfig.h"




SArbolPtr * SArbPtrCrear () 
{
	SArbolPtr * p_arbpObj;
	
	p_arbpObj = (SArbolPtr *) MemReservar ( sizeof ( SArbolPtr ) );
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_arbpObj->p_nodRaiz = NULL;
		p_arbpObj->p_nodActual = NULL;
	}
	return ( p_arbpObj );
}

void SArbPtrDestruir ( SArbolPtr ** p_p_arbpObj )
{
	SArbolPtr * p_arbpObj;
	
	if ( ES_VALIDO ( p_p_arbpObj ) )
	{
		p_arbpObj = *p_p_arbpObj;
		if ( ES_VALIDO ( p_arbpObj ) )
		{
			SArbPtrVaciar ( p_arbpObj );
			MemLiberar ( (void **) p_p_arbpObj );
		}
	}
}

SNodoPtr * SArbPtrRaiz ( SArbolPtr * p_arbpObj )
{
	SNodoPtr * p_nodRes;
	
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_nodRes = p_arbpObj->p_nodRaiz;
	}
	else
	{
		p_nodRes = NULL;
	}
	return ( p_nodRes );
}

int SArbPtrEstablecerRaiz ( SArbolPtr * p_arbpObj, SNodoPtr * p_nodpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_arbpObj->p_nodRaiz = p_nodpObj;
		if ( ES_VALIDO ( p_arbpObj->p_nodRaiz ) )
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

int SArbPtrEstaVacio ( SArbolPtr * p_arbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_NULO ( p_arbpObj->p_nodRaiz ) )
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

int SArbPtrNiveles ( SArbolPtr * p_arbpObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodRaiz ) )
		{
			iNiveles = SNodPtrNivelesInferiores ( p_arbpObj->p_nodRaiz ) + 1;
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

int SArbPtrNumNodos ( SArbolPtr * p_arbpObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodRaiz ) )
		{
			iNodos = SNodPtrNodosInferiores ( p_arbpObj->p_nodRaiz ) + 1;
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

int SArbPtrVaciar ( SArbolPtr * p_arbpObj )
{
	SNodoPtr * p_nodpObj;
	int		iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodRaiz ) )
		{
			SArbPtrMoverAPrimPreorden ( p_arbpObj );
			while ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
			{
				p_nodpObj = p_arbpObj->p_nodActual;
				SArbPtrMoverASigPreorden ( p_arbpObj );
				SNodPtrDestruir ( &p_nodpObj, 0 );
			}
			if ( SArbPtrNumNodos ( p_arbpObj ) == 0 )
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
		iRes = 1;
	}
	return ( iRes );
}

SNodoPtr * SArbPtrActual ( SArbolPtr * p_arbpObj )
{
	SNodoPtr * p_nodRes;
	
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_nodRes = p_arbpObj->p_nodActual;
	}
	else
	{
		p_nodRes = NULL;
	}
	return ( p_nodRes );
}

void SArbPtrMoverARaiz ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_arbpObj->p_nodActual = p_arbpObj->p_nodRaiz;
	}
}

void SArbPtrMoverAPadre ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			p_arbpObj->p_nodActual = SNodPtrPadre ( p_arbpObj->p_nodActual );
		}
	}
}

void SArbPtrMoverAHijo ( SArbolPtr * p_arbpObj, int iHijo )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			p_arbpObj->p_nodActual = SNodPtrHijo ( p_arbpObj->p_nodActual, iHijo );
		}
	}
}

void SArbPtrMoverAPrimHijo ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		SArbPtrMoverAHijo ( p_arbpObj, 0 );
	}
}

void SArbPtrMoverAUltHijo ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			SArbPtrMoverAHijo ( p_arbpObj, SNodPtrNumHijos ( p_arbpObj->p_nodActual ) - 1 );
		}
	}
}

void SArbPtrMoverAPrimHermano ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		SArbPtrMoverAPadre ( p_arbpObj );
		SArbPtrMoverAHijo ( p_arbpObj, 0 );
	}
}

void SArbPtrMoverASigHermano ( SArbolPtr * p_arbpObj )
{
	int		iHijo;
	SNodoPtr * p_nodPadre;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			if ( SNodPtrTienePadre ( p_arbpObj->p_nodActual ) == 1 )
			{
				p_nodPadre = SNodPtrPadre ( p_arbpObj->p_nodActual );
				iHijo = SNodPtrOrdenDelHijo ( p_nodPadre, p_arbpObj->p_nodActual );
				if ( iHijo >= 0 )
				{
					p_arbpObj->p_nodActual = SNodPtrHijo ( p_nodPadre, iHijo + 1 );
				}
				else
				{
					p_arbpObj->p_nodActual = NULL;
				}
			}
			else
			{
				p_arbpObj->p_nodActual = NULL;
			}
		}
	}
}

void SArbPtrMoverAAntHermano ( SArbolPtr * p_arbpObj )
{
	int		iHijo;
	SNodoPtr * p_nodPadre;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			if ( SNodPtrTienePadre ( p_arbpObj->p_nodActual ) == 1 )
			{
				p_nodPadre = SNodPtrPadre ( p_arbpObj->p_nodActual );
				iHijo = SNodPtrOrdenDelHijo ( p_nodPadre, p_arbpObj->p_nodActual );
				if ( iHijo > 0 )
				{
					p_arbpObj->p_nodActual = SNodPtrHijo ( p_nodPadre, iHijo - 1 );
				}
				else
				{
					p_arbpObj->p_nodActual = NULL;
				}
			}
			else
			{
				p_arbpObj->p_nodActual = NULL;
			}
		}
	}
}

void SArbPtrMoverAUltHermano ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		SArbPtrMoverAPadre ( p_arbpObj );
		SArbPtrMoverAHijo ( p_arbpObj, SNodPtrNumHijos ( p_arbpObj->p_nodActual ) - 1 );
	}
}

void SArbPtrMoverAPrimPreorden ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		SArbPtrMoverARaiz ( p_arbpObj );
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			while ( ES_VALIDO ( p_arbpObj->p_nodActual ) && ( SNodPtrTieneHijos ( p_arbpObj->p_nodActual ) == 1 ) )
			{
				SArbPtrMoverAHijo ( p_arbpObj, 0 );
			}
		}
	}
}

void SArbPtrMoverASigPreorden ( SArbolPtr * p_arbpObj )
{
	SNodoPtr * p_nodpObj;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			p_nodpObj = p_arbpObj->p_nodActual;
			SArbPtrMoverASigHermano ( p_arbpObj );
			if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
			{
				while ( ES_VALIDO ( p_arbpObj->p_nodActual ) && ( SNodPtrTieneHijos ( p_arbpObj->p_nodActual ) == 1 ) )
				{
					SArbPtrMoverAHijo ( p_arbpObj, 0 );
				}
			}
			else
			{
				p_arbpObj->p_nodActual = p_nodpObj;
				SArbPtrMoverAPadre ( p_arbpObj );
			}
		}
	}
}

void SArbPtrMoverAAntPreorden ( SArbolPtr * p_arbpObj )
{
	SNodoPtr * p_nodpObj;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
		{
			if ( SNodPtrTieneHijos ( p_arbpObj->p_nodActual ) == 1 )
			{
				SArbPtrMoverAHijo ( p_arbpObj, SNodPtrNumHijos ( p_arbpObj->p_nodActual ) - 1 );
			}
			else
			{
				p_nodpObj = p_arbpObj->p_nodActual;
				SArbPtrMoverAAntHermano ( p_arbpObj );
				if ( ES_NULO ( p_arbpObj->p_nodActual ) )
				{
					p_arbpObj->p_nodActual = p_nodpObj;
					SArbPtrMoverAPadre ( p_arbpObj );
					if ( ES_NULO ( p_arbpObj->p_nodActual ) )
					{
						SArbPtrMoverAAntHermano ( p_arbpObj );
					}
				}
			}
		}
	}
}

void SArbPtrMoverAUltPreorden ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		SArbPtrMoverARaiz ( p_arbpObj );
	}
}

void SArbPtrDesposicionar ( SArbolPtr * p_arbpObj )
{
	if ( ES_VALIDO ( p_arbpObj ) )
	{
		p_arbpObj->p_nodActual = NULL;
	}
}

int	SArbPtrEstaPosicionado ( SArbolPtr * p_arbpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) )
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

int SArbPtrEnraizar ( SArbolPtr * p_arbpObj, SNodoPtr * p_nodpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodActual ) && ES_VALIDO ( p_nodpObj ) )
		{
			SNodPtrEmpadronar ( p_nodpObj, p_arbpObj->p_nodActual );
			if (  SNodPtrInsertarHijo ( p_arbpObj->p_nodActual, p_nodpObj ) == 1 )
			{
				iRes = 1;
				SArbPtrMoverAUltHijo ( p_arbpObj );
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

int SArbPtrVerificar ( SArbolPtr * p_arbpObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbpObj ) )
	{
		if ( ES_VALIDO ( p_arbpObj->p_nodRaiz ) )
		{
			iRes = SNodPtrVerificar ( p_arbpObj->p_nodRaiz, iCorregir );
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




