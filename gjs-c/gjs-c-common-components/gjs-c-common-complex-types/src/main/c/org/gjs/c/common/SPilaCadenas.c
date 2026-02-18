#include "SPilaCadenas.h"

#include "TiposDatosConfig.h"



SPilaCadenas * SPilCadCrear ()
{
	SPilaCadenas * p_pilObj;
	
	p_pilObj = (SPilaCadenas *) MemReservar ( sizeof ( SPilaCadenas ) );
	if ( ES_VALIDO ( p_pilObj ) )
	{
		p_pilObj->p_pilDatos = SPilpCrear ();
		SPilpActivarLiberacionMemoria ( p_pilObj->p_pilDatos );
	}
	return ( p_pilObj );
}

void SPilCadDestruir ( SPilaCadenas ** p_p_pilObj )
{
	SPilaCadenas * p_pilObj;
	
	if ( ES_VALIDO ( p_p_pilObj ) )
	{
		p_pilObj = *p_p_pilObj;

		if ( ES_VALIDO ( p_pilObj ) )
		{
			SPilpDestruir ( &(p_pilObj->p_pilDatos) );
			MemLiberar ( (void **) p_p_pilObj );
		}
	}
}

int SPilCadEsValida ( SPilaCadenas * p_pilObj )
{
	int iRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		iRes = SPilpEsValida ( p_pilObj->p_pilDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SPilCadEstaVacia ( SPilaCadenas * p_pilObj )
{
	int iRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		iRes = SPilpEstaVacia ( p_pilObj->p_pilDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SPilCadNumElementos ( SPilaCadenas * p_pilObj )
{
	int iRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		iRes = SPilpNumElementos ( p_pilObj->p_pilDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * SPilCadPrimero ( SPilaCadenas * p_pilObj )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		p_cRes = (SCadena *) SPilpPrimero ( p_pilObj->p_pilDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

SCadena * SPilCadDesapilar ( SPilaCadenas * p_pilObj )
{
	SCadena * p_cRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		p_cRes = (SCadena *) SPilpDesapilar ( p_pilObj->p_pilDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SPilCadApilar ( SPilaCadenas * p_pilObj, SCadena * p_cadDato )
{
	int		iRes;
	SCadena *	p_cElem;

	if ( ES_VALIDO ( p_pilObj ) && ES_VALIDO ( p_cadDato ) )
	{
		p_cElem = SCadDuplicar ( p_cadDato );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iRes = SPilpApilar ( p_pilObj->p_pilDatos, (byte *) p_cElem );
			if ( iRes != 1 )
			{
				MemLiberar ( (void **) &p_cElem );
			}
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SPilCadApilarLit ( SPilaCadenas * p_pilObj, const char * p_cDato )
{
	return ( SPilCadApilar ( p_pilObj, SCadGenerar( p_cDato ) ) );  
}

int SPilCadApilarDup ( SPilaCadenas * p_pilObj, SCadena * p_cadDato )
{
	int			iRes;
	SCadena *	p_cadValor;

	p_cadValor = SCadDuplicar ( p_cadDato );
	iRes = SPilCadApilar ( p_pilObj, p_cadValor );
	if ( iRes < 0 )
	{
		SCadDestruir ( &p_cadValor );
	}
	return ( iRes );
}


int SPilCadEliminarPrimero ( SPilaCadenas * p_pilObj )
{
	int iRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		iRes = SPilpEliminarPrimero ( p_pilObj->p_pilDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SPilCadVaciar ( SPilaCadenas * p_pilObj )
{
	int iRes;

	if ( ES_VALIDO ( p_pilObj ) )
	{
		iRes = SPilpVaciar ( p_pilObj->p_pilDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

