#include "SArbol.h"




#include "TiposBasicosConfig.h"



SArbol * SArbCrear () 
{
	SArbol * p_arbObj;
	
	p_arbObj = (SArbol *) MemReservar ( sizeof ( SArbol ) );
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_nodRaiz = NULL;
		p_arbObj->p_nodActual = NULL;
	}
	return ( p_arbObj );
}

void SArbDestruir ( SArbol ** p_p_arbObj )
{
	SArbol * p_arbObj;
	
	if ( ES_VALIDO ( p_p_arbObj ) )
	{
		p_arbObj = *p_p_arbObj;
		if ( ES_VALIDO ( p_arbObj ) )
		{
			SArbVaciar ( p_arbObj );
			MemLiberar ( (void **) p_p_arbObj );
		}
	}
}

SNodo * SArbRaiz ( SArbol * p_arbObj )
{
	SNodo * p_nodRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodRes = p_arbObj->p_nodRaiz;
	}
	else
	{
		p_nodRes = NULL;
	}
	return ( p_nodRes );
}

int SArbEstablecerRaiz ( SArbol * p_arbObj, SNodo * p_nodObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_nodRaiz = p_nodObj;
		if ( ES_VALIDO ( p_arbObj->p_nodRaiz ) )
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

int SArbEstaVacio ( SArbol * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_NULO ( p_arbObj->p_nodRaiz ) )
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

int SArbNiveles ( SArbol * p_arbObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodRaiz ) )
		{
			iNiveles = SNodNivelesInferiores ( p_arbObj->p_nodRaiz ) + 1;
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

int SArbNumNodos ( SArbol * p_arbObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodRaiz ) )
		{
			iNodos = SNodNodosInferiores ( p_arbObj->p_nodRaiz ) + 1;
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

int SArbVaciar ( SArbol * p_arbObj )
{
	SNodo * p_nodObj;
	int		iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodRaiz ) )
		{
			SArbMoverAPrimPreorden ( p_arbObj );
			while ( ES_VALIDO ( p_arbObj->p_nodActual ) )
			{
				p_nodObj = p_arbObj->p_nodActual;
				SArbMoverASigPreorden ( p_arbObj );
				SNodDestruir ( &p_nodObj, 0 );
			}
			if ( SArbNumNodos ( p_arbObj ) == 0 )
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

SNodo * SArbActual ( SArbol * p_arbObj )
{
	SNodo * p_nodRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodRes = p_arbObj->p_nodActual;
	}
	else
	{
		p_nodRes = NULL;
	}
	return ( p_nodRes );
}

void SArbMoverARaiz ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_nodActual = p_arbObj->p_nodRaiz;
	}
}

void SArbMoverAPadre ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			p_arbObj->p_nodActual = SNodPadre ( p_arbObj->p_nodActual );
		}
	}
}

void SArbMoverAHijo ( SArbol * p_arbObj, int iHijo )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			p_arbObj->p_nodActual = SNodHijo ( p_arbObj->p_nodActual, iHijo );
		}
	}
}

void SArbMoverAPrimHijo ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAHijo ( p_arbObj, 0 );
	}
}

void SArbMoverAUltHijo ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			SArbMoverAHijo ( p_arbObj, SNodNumHijos ( p_arbObj->p_nodActual ) - 1 );
		}
	}
}

void SArbMoverAPrimHermano ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPadre ( p_arbObj );
		SArbMoverAHijo ( p_arbObj, 0 );
	}
}

void SArbMoverASigHermano ( SArbol * p_arbObj )
{
	int		iHijo;
	SNodo * p_nodPadre;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			if ( SNodTienePadre ( p_arbObj->p_nodActual ) == 1 )
			{
				p_nodPadre = SNodPadre ( p_arbObj->p_nodActual );
				iHijo = SNodOrdenDelHijo ( p_nodPadre, p_arbObj->p_nodActual );
				if ( iHijo >= 0 )
				{
					p_arbObj->p_nodActual = SNodHijo ( p_nodPadre, iHijo + 1 );
				}
				else
				{
					p_arbObj->p_nodActual = NULL;
				}
			}
			else
			{
				p_arbObj->p_nodActual = NULL;
			}
		}
	}
}

void SArbMoverAAntHermano ( SArbol * p_arbObj )
{
	int		iHijo;
	SNodo * p_nodPadre;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			if ( SNodTienePadre ( p_arbObj->p_nodActual ) == 1 )
			{
				p_nodPadre = SNodPadre ( p_arbObj->p_nodActual );
				iHijo = SNodOrdenDelHijo ( p_nodPadre, p_arbObj->p_nodActual );
				if ( iHijo > 0 )
				{
					p_arbObj->p_nodActual = SNodHijo ( p_nodPadre, iHijo - 1 );
				}
				else
				{
					p_arbObj->p_nodActual = NULL;
				}
			}
			else
			{
				p_arbObj->p_nodActual = NULL;
			}
		}
	}
}

void SArbMoverAUltHermano ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPadre ( p_arbObj );
		SArbMoverAHijo ( p_arbObj, SNodNumHijos ( p_arbObj->p_nodActual ) - 1 );
	}
}

void SArbMoverAPrimPreorden ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverARaiz ( p_arbObj );
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			while ( ES_VALIDO ( p_arbObj->p_nodActual ) && ( SNodTieneHijos ( p_arbObj->p_nodActual ) == 1 ) )
			{
				SArbMoverAHijo ( p_arbObj, 0 );
			}
		}
	}
}

void SArbMoverASigPreorden ( SArbol * p_arbObj )
{
	SNodo * p_nodObj;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			p_nodObj = p_arbObj->p_nodActual;
			SArbMoverASigHermano ( p_arbObj );
			if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
			{
				while ( ES_VALIDO ( p_arbObj->p_nodActual ) && ( SNodTieneHijos ( p_arbObj->p_nodActual ) == 1 ) )
				{
					SArbMoverAHijo ( p_arbObj, 0 );
				}
			}
			else
			{
				p_arbObj->p_nodActual = p_nodObj;
				SArbMoverAPadre ( p_arbObj );
			}
		}
	}
}

void SArbMoverAAntPreorden ( SArbol * p_arbObj )
{
	SNodo * p_nodObj;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
		{
			if ( SNodTieneHijos ( p_arbObj->p_nodActual ) == 1 )
			{
				SArbMoverAHijo ( p_arbObj, SNodNumHijos ( p_arbObj->p_nodActual ) - 1 );
			}
			else
			{
				p_nodObj = p_arbObj->p_nodActual;
				SArbMoverAAntHermano ( p_arbObj );
				if ( ES_NULO ( p_arbObj->p_nodActual ) )
				{
					p_arbObj->p_nodActual = p_nodObj;
					SArbMoverAPadre ( p_arbObj );
					if ( ES_NULO ( p_arbObj->p_nodActual ) )
					{
						SArbMoverAAntHermano ( p_arbObj );
					}
				}
			}
		}
	}
}

void SArbMoverAUltPreorden ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverARaiz ( p_arbObj );
	}
}

void SArbDesposicionar ( SArbol * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_nodActual = NULL;
	}
}

int	SArbEstaPosicionado ( SArbol * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) )
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

int SArbEnraizar ( SArbol * p_arbObj, SNodo * p_nodObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodActual ) && ES_VALIDO ( p_nodObj ) )
		{
			SNodEmpadronar ( p_nodObj, p_arbObj->p_nodActual );
			if (  SNodInsertarHijo ( p_arbObj->p_nodActual, p_nodObj ) == 1 )
			{
				iRes = 1;
				SArbMoverAUltHijo ( p_arbObj );
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

int SArbVerificar ( SArbol * p_arbObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		if ( ES_VALIDO ( p_arbObj->p_nodRaiz ) )
		{
			iRes = SNodVerificar ( p_arbObj->p_nodRaiz, iCorregir );
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




