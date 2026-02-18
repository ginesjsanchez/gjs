#include "SSecuenciaCadenas.h"

#include "TiposDatosConfig.h"



SSecuenciaCadenas * SSecCadCrear ()
{
	SSecuenciaCadenas * p_secObj;
	
	p_secObj = (SSecuenciaCadenas *) MemReservar ( sizeof ( SSecuenciaCadenas ) );
	if ( ES_VALIDO ( p_secObj ) )
	{
		p_secObj->p_secDatos = SSecpCrear ();
		SSecpActivarLiberacionMemoria ( p_secObj->p_secDatos );
	}
	return ( p_secObj );
}

void SSecCadDestruir ( SSecuenciaCadenas ** p_p_secObj )
{
	SSecuenciaCadenas * p_secObj;
	
	if ( ES_VALIDO ( p_p_secObj ) )
	{
		p_secObj = *p_p_secObj;

		if ( ES_VALIDO ( p_secObj ) )
		{
			SSecpDestruir ( &(p_secObj->p_secDatos) );
			MemLiberar ( (void **) p_p_secObj );
		}
	}
}

int SSecCadEsValida ( SSecuenciaCadenas * p_secObj )
{
	int iRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		iRes = SSecpEsValida ( p_secObj->p_secDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SSecCadEstaVacia ( SSecuenciaCadenas * p_secObj )
{
	int iRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		iRes = SSecpEstaVacia ( p_secObj->p_secDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SSecCadNumElementos ( SSecuenciaCadenas * p_secObj )
{
	int iRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		iRes = SSecpNumElementos ( p_secObj->p_secDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * SSecCadElemento ( SSecuenciaCadenas * p_secObj, int iElem )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		p_cRes = (SCadena *) SSecpElemento ( p_secObj->p_secDatos, iElem );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SSecCadInsertar ( SSecuenciaCadenas * p_secObj, SCadena * p_cadDatos )
{
	int	iRes;

	if ( ES_VALIDO ( p_secObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		iRes = SSecpInsertar ( p_secObj->p_secDatos, (byte *) p_cadDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SSecCadInsertarDup ( SSecuenciaCadenas * p_secObj, SCadena * p_cadDatos )
{
	int		iRes;
	SCadena *	p_cElem;
	int		iActLib;

	if ( ES_VALIDO ( p_secObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SSecpLiberacionMemoriaActivada ( p_secObj->p_secDatos );
			SSecpActivarLiberacionMemoria ( p_secObj->p_secDatos );
			iRes = SSecpInsertar ( p_secObj->p_secDatos, (byte *) p_cadDatos );
			if ( iRes != 1 )
			{
				MemLiberar ( (void **) &p_cElem );
			}
			if ( iActLib == 0 )
			{
				SSecpDesactivarLiberacionMemoria ( p_secObj->p_secDatos );
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

int SSecCadEliminar ( SSecuenciaCadenas * p_secObj, int iElem )
{
	int iRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		iRes = SSecpEliminar ( p_secObj->p_secDatos, iElem );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SSecCadVaciar ( SSecuenciaCadenas * p_secObj )
{
	int iRes;

	if ( ES_VALIDO ( p_secObj ) )
	{
		iRes = SSecpVaciar ( p_secObj->p_secDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int	SSecCadLiberacionMemoriaActivada ( SSecuenciaCadenas * p_secObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_secObj ) ) 
	{
		iRes = SSecpLiberacionMemoriaActivada ( p_secObj->p_secDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SSecCadActivarLiberacionMemoria ( SSecuenciaCadenas * p_secObj )
{
	if ( ES_VALIDO ( p_secObj ) ) 
	{
		SSecpActivarLiberacionMemoria ( p_secObj->p_secDatos );
	}
}

void SSecCadDesactivarLiberacionMemoria ( SSecuenciaCadenas * p_secObj )
{
	if ( ES_VALIDO ( p_secObj ) ) 
	{
		SSecpDesactivarLiberacionMemoria ( p_secObj->p_secDatos );
	}
}

int SSecCadExiste ( SSecuenciaCadenas * p_secObj, SCadena * p_cadDato )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_secObj ) && ES_VALIDO ( p_cadDato )  ) 
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SSecCadNumElementos ( p_secObj ) ) && ( iRes == 0 ) )
		{
			if ( SCadEsIgual ( SSecCadElemento ( p_secObj, iElem ), p_cadDato ) == 1 )
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


