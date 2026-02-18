#include "SVectorCadenas.h"

#include "TiposDatosConfig.h"



SVectorCadenas * SVecCadCrear ( int iNumElementos )
{
	SVectorCadenas * p_vecObj;
	
	if ( iNumElementos > 0 )
	{
		p_vecObj = (SVectorCadenas *) MemReservar ( sizeof ( SVectorCadenas ) );
		if ( ES_VALIDO ( p_vecObj ) )
		{
			p_vecObj->p_vecDatos = SVecpCrear ( iNumElementos );
			SVecpActivarLiberacionMemoria ( p_vecObj->p_vecDatos );
		}
	}
	else
	{
		p_vecObj = NULL;
	}
	return ( p_vecObj );
}

void SVecCadDestruir ( SVectorCadenas ** p_p_vecObj )
{
	SVectorCadenas * p_vecObj;
	
	if ( ES_VALIDO ( p_p_vecObj ) )
	{
		p_vecObj = *p_p_vecObj;

		if ( ES_VALIDO ( p_vecObj ) )
		{
			SVecpDestruir ( &(p_vecObj->p_vecDatos) );
			MemLiberar ( (void **) p_p_vecObj );
		}
	}
}

int SVecCadEsValido ( SVectorCadenas * p_vecObj )
{
	int iRes;

	if ( ES_VALIDO ( p_vecObj ) )
	{
		iRes = SVecpEsValido ( p_vecObj->p_vecDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SVecCadNumElementos ( SVectorCadenas * p_vecObj )
{
	int iRes;

	if ( ES_VALIDO ( p_vecObj ) )
	{
		iRes = SVecpNumElementos ( p_vecObj->p_vecDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * SVecCadElemento ( SVectorCadenas * p_vecObj, int iElem )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_vecObj ) )
	{
		p_cRes = (SCadena *) SVecpElemento ( p_vecObj->p_vecDatos, iElem );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SVecCadAsignar ( SVectorCadenas * p_vecObj, int iElem, SCadena * p_cadDato )
{
	int		iRes;

	if ( ES_VALIDO ( p_vecObj ) && ES_VALIDO ( p_cadDato ) )
	{
		iRes = SVecpAsignar ( p_vecObj->p_vecDatos, iElem, (byte *) p_cadDato );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SVecCadAsignarDup ( SVectorCadenas * p_vecObj, int iElem, SCadena * p_cadDato )
{
	int		iRes;
	SCadena *	p_cElem;
	int		iActLib;

	if ( ES_VALIDO ( p_vecObj ) && ES_VALIDO ( p_cadDato ) )
	{
		p_cElem = SCadDuplicar ( p_cadDato );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SVecpLiberacionMemoriaActivada ( p_vecObj->p_vecDatos );
			SVecpActivarLiberacionMemoria ( p_vecObj->p_vecDatos );
			iRes = SVecpAsignar ( p_vecObj->p_vecDatos, iElem, (byte *) p_cadDato );
			if ( iRes != 1 )
			{
				MemLiberar ( (void **) &p_cElem );
			}
			if ( iActLib == 0 )
			{
				SVecpDesactivarLiberacionMemoria ( p_vecObj->p_vecDatos );
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

int SVecCadLimpiarElemento ( SVectorCadenas * p_vecObj, int iElem )
{
	int iRes;

	if ( ES_VALIDO ( p_vecObj ) )
	{
		iRes = SVecpLimpiarElemento ( p_vecObj->p_vecDatos, iElem );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SVecCadLimpiar ( SVectorCadenas * p_vecObj )
{
	int iRes;

	if ( ES_VALIDO ( p_vecObj ) )
	{
		iRes = SVecpLimpiar ( p_vecObj->p_vecDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int	SVecCadLiberacionMemoriaActivada ( SVectorCadenas * p_vecObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_vecObj ) ) 
	{
		iRes = SVecpLiberacionMemoriaActivada ( p_vecObj->p_vecDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SVecCadActivarLiberacionMemoria ( SVectorCadenas * p_vecObj )
{
	if ( ES_VALIDO ( p_vecObj ) ) 
	{
		SVecpActivarLiberacionMemoria ( p_vecObj->p_vecDatos );
	}
}

void SVecCadDesactivarLiberacionMemoria ( SVectorCadenas * p_vecObj )
{
	if ( ES_VALIDO ( p_vecObj ) ) 
	{
		SVecpDesactivarLiberacionMemoria ( p_vecObj->p_vecDatos );
	}
}

int SVecCadExiste ( SVectorCadenas * p_vecObj, SCadena * p_cadDato )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_vecObj ) && ES_VALIDO ( p_cadDato )  ) 
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SVecCadNumElementos ( p_vecObj ) ) && ( iRes == 0 ) )
		{
			if ( SCadEsIgual ( SVecCadElemento ( p_vecObj, iElem ), p_cadDato ) == 1 )
			{
				iRes = 1;
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}
