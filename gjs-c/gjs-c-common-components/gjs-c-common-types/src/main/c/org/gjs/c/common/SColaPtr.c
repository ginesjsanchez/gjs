#include "SColaPtr.h"


#include "TiposBasicosConfig.h"




SColaPtr * SColpCrear ()
{
	SColaPtr * p_colObj;
	
	p_colObj = (SColaPtr *) MemReservar ( sizeof ( SColaPtr ) );
	if ( ES_VALIDO ( p_colObj ) )
	{
		p_colObj->p_lisObjetos = SLispCrear ();
	}
	return ( p_colObj );
}

void SColpDestruir ( SColaPtr ** p_p_colObj )
{
	SColaPtr * p_colObj;
	
	if ( ES_VALIDO ( p_p_colObj ) )
	{
		p_colObj = *p_p_colObj;

		if ( ES_VALIDO ( p_colObj ) )
		{
			SLispDestruir ( &(p_colObj->p_lisObjetos) );
			MemLiberar ( (void **) p_p_colObj );
		}
	}
}

int SColpEsValida ( SColaPtr * p_colObj )
{
	int iRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		iRes = SLispEsValida ( p_colObj->p_lisObjetos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SColpNumElementos ( SColaPtr * p_colObj )
{
	int iRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		iRes = SLispNumElementos ( p_colObj->p_lisObjetos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SColpEstaVacia ( SColaPtr * p_colObj )
{
	int iRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		iRes = SLispEstaVacia ( p_colObj->p_lisObjetos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

byte * SColpPrimero ( SColaPtr * p_colObj )
{
	byte * p_bymRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		p_bymRes = SLispElemento ( p_colObj->p_lisObjetos, 0 );
	}
	else
	{
		p_bymRes = NULL;
	}
	return ( p_bymRes );
}

byte * SColpUltimo ( SColaPtr * p_colObj )
{
	byte * p_bymRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		p_bymRes = SLispElemento ( p_colObj->p_lisObjetos, 
								  SLispNumElementos ( p_colObj->p_lisObjetos ) - 1 );
	}
	else
	{
		p_bymRes = NULL;
	}
	return ( p_bymRes );
}

byte * SColpElemento ( SColaPtr * p_colObj, int iElem )
{
	byte * p_bymRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		p_bymRes = SLispElemento ( p_colObj->p_lisObjetos, iElem );
	}
	else
	{
		p_bymRes = NULL;
	}
	return ( p_bymRes );
}

byte * SColpDesencolar ( SColaPtr * p_colObj )
{
	byte * p_bymRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		p_bymRes = SLispElemento ( p_colObj->p_lisObjetos, 0 );
		if ( ES_VALIDO ( p_bymRes ) )
		{
			if ( SLispEliminarElem ( p_colObj->p_lisObjetos, 0 ) == 0 )
			{
				p_bymRes = NULL;
			}
		}
	}
	else
	{
		p_bymRes = NULL;
	}
	return ( p_bymRes );
}

int SColpEncolar ( SColaPtr * p_colObj, byte * p_bymObj )
{
	int iRes;

	if ( ( SColpEsValida ( p_colObj ) == 1 ) && ES_VALIDO ( p_bymObj ) )
	{
		iRes = SLispInsertarAlFinal ( p_colObj->p_lisObjetos, p_bymObj );
	}
	else
	{
		iRes = 1;
	}
	return ( iRes );
}

int SColpEliminarPrimero ( SColaPtr * p_colObj )
{
	int	iRes;

	if ( SColpEsValida ( p_colObj ) == 1 ) 
	{
		iRes = SLispEliminarElem ( p_colObj->p_lisObjetos, 0 );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SColpEliminarUltimo ( SColaPtr * p_colObj )
{
	int	iRes;

	if ( SColpEsValida ( p_colObj ) == 1 ) 
	{
		iRes = SLispEliminarElem ( p_colObj->p_lisObjetos, 
								  SLispNumElementos ( p_colObj->p_lisObjetos ) - 1 );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SColpEliminar ( SColaPtr * p_colObj, int iElem )
{
	int	iRes;

	if ( SColpEsValida ( p_colObj ) == 1 ) 
	{
		iRes = SLispEliminarElem ( p_colObj->p_lisObjetos, iElem );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SColpVaciar ( SColaPtr * p_colObj )
{
	int	iRes;

	if ( SColpEsValida ( p_colObj ) == 1 ) 
	{
		iRes = SLispVaciar ( p_colObj->p_lisObjetos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SListaPtr * SColpLista ( SColaPtr * p_colObj )
{
	SListaPtr * p_lisRes;

	if ( ES_VALIDO ( p_colObj ) )
	{
		p_lisRes = p_colObj->p_lisObjetos;
	}
	else
	{
		p_lisRes = NULL;
	}
	return ( p_lisRes );
}
