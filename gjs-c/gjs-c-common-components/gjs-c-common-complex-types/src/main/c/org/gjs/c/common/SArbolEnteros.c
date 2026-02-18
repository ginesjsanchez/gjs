#include "SArbolEnteros.h"

#include "TiposDatosConfig.h"





SArbolEnteros * SArbEntCrear () 
{
	SArbolEnteros * p_arbObj;
	
	p_arbObj = (SArbolEnteros *) MemReservar ( sizeof ( SArbolEnteros ) );
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_arbObj = SArbCrear ();
	}
	return ( p_arbObj );
}

void SArbEntDestruir ( SArbolEnteros ** p_p_arbObj )
{
	SArbolEnteros * p_arbObj;
	
	if ( ES_VALIDO ( p_p_arbObj ) )
	{
		p_arbObj = *p_p_arbObj;
		if ( ES_VALIDO ( p_arbObj ) )
		{
			SArbDestruir ( &(p_arbObj->p_arbObj) );
			MemLiberar ( (void **) p_p_arbObj );
		}
	}
}

int SArbEntRaiz ( SArbolEnteros * p_arbObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodEntero ( SArbActual ( p_arbObj->p_arbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntEstablecerRaiz ( SArbolEnteros * p_arbObj, int iValor )
{
	int 		iRes;
	SNodo *		p_nodObj;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodObj = SNodCrearEntero ( iValor );	
		if ( SArbEstablecerRaiz ( p_arbObj->p_arbObj, p_nodObj ) == 1 )
		{
			iRes = 1;
		}
		else
		{
			SNodDestruir ( &p_nodObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntEstaVacio ( SArbolEnteros * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbEstaVacio ( p_arbObj->p_arbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntNiveles ( SArbolEnteros * p_arbObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iNiveles = SArbNiveles ( p_arbObj->p_arbObj );
	}
	else
	{
		iNiveles = 0;
	}
	return ( iNiveles );
}

int SArbEntNumNodos ( SArbolEnteros * p_arbObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iNodos = SArbNumNodos ( p_arbObj->p_arbObj );
	}
	else
	{
		iNodos = 0;
	}
	return ( iNodos );
}

int SArbEntVaciar ( SArbolEnteros * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbVaciar ( p_arbObj->p_arbObj );
	}
	else
	{
		iRes = 1;
	}
	return ( iRes );
}

int SArbEntActual ( SArbolEnteros * p_arbObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodEntero ( SArbActual ( p_arbObj->p_arbObj ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntEstActual ( SArbolEnteros * p_arbObj, int iValor )
{
	int 		iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodEstablecerEntero ( SArbActual ( p_arbObj->p_arbObj ), iValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SArbEntMoverARaiz ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverARaiz ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAPadre ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPadre ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAHijo ( SArbolEnteros * p_arbObj, int iHijo )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAHijo ( p_arbObj->p_arbObj, iHijo );
	}
}

void SArbEntMoverAPrimHijo ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPrimHijo ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAUltHijo ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAUltHijo ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAPrimHermano ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPrimHermano ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverASigHermano ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverASigHermano ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAAntHermano ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAAntHermano ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAUltHermano ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAUltHermano ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAPrimPreorden ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAPrimPreorden ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverASigPreorden ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverASigPreorden ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAAntPreorden ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAAntPreorden ( p_arbObj->p_arbObj );
	}
}

void SArbEntMoverAUltPreorden ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbMoverAUltPreorden ( p_arbObj->p_arbObj );
	}
}

void SArbEntDesposicionar ( SArbolEnteros * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbDesposicionar ( p_arbObj->p_arbObj );
	}
}

int	SArbEntEstaPosicionado ( SArbolEnteros * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbEstaPosicionado ( p_arbObj->p_arbObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntEnraizar ( SArbolEnteros * p_arbObj, int iValor )
{
	SNodo * 	p_nodObj;
	int 		iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodObj = SNodCrearEntero ( iValor );	
		if ( SArbEnraizar ( p_arbObj->p_arbObj, p_nodObj ) == 1 )
		{
			iRes = 1;
		}
		else
		{
			SNodDestruir ( &p_nodObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbEntVerificar ( SArbolEnteros * p_arbObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbVerificar ( p_arbObj->p_arbObj, iCorregir );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}




