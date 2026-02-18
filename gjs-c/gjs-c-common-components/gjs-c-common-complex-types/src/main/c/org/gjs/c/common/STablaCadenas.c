#include "STablaCadenas.h"

#include "TiposDatosConfig.h"



STablaCadenas * STabCadCrear ( int iNumFilas, int iNumColumnas )
{
	STablaCadenas * p_tabObj;
	
	if ( ( iNumFilas > 0 ) && ( iNumColumnas > 0 ) )
	{
		p_tabObj = (STablaCadenas *) MemReservar ( sizeof ( STablaCadenas ) );
		if ( ES_VALIDO ( p_tabObj ) )
		{
			p_tabObj->p_tabDatos = STabpCrear ( iNumFilas, iNumColumnas );
			STabpActivarLiberacionMemoria ( p_tabObj->p_tabDatos );
		}
	}
	else
	{
		p_tabObj = NULL;
	}
	return ( p_tabObj );
}

void STabCadDestruir ( STablaCadenas ** p_p_tabObj )
{
	STablaCadenas * p_tabObj;
	
	if ( ES_VALIDO ( p_p_tabObj ) )
	{
		p_tabObj = *p_p_tabObj;

		if ( ES_VALIDO ( p_tabObj ) )
		{
			STabpDestruir ( &(p_tabObj->p_tabDatos) );
			MemLiberar ( (void **) p_p_tabObj );
		}
	}
}

int STabCadEsValida ( STablaCadenas * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpEsValida ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabCadNumFilas ( STablaCadenas * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpNumFilas ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabCadNumColumnas ( STablaCadenas * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpNumColumnas ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabCadNumElementos ( STablaCadenas * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpNumElementos ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * STabCadElemento ( STablaCadenas * p_tabObj, int iFila, int iColumna )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		p_cRes = (SCadena *) STabpElemento ( p_tabObj->p_tabDatos, iFila, iColumna );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int STabCadAsignar ( STablaCadenas * p_tabObj, int iFila, int iColumna, SCadena * p_cadDatos )
{
	int		iRes;

	if ( ES_VALIDO ( p_tabObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		iRes = STabpAsignar ( p_tabObj->p_tabDatos, iFila, iColumna, (byte *) p_cadDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int STabCadAsignarDup ( STablaCadenas * p_tabObj, int iFila, int iColumna, SCadena * p_cadDatos )
{
	int		iRes;
	SCadena *	p_cElem;
	int		iActLib;

	if ( ES_VALIDO ( p_tabObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = STabpLiberacionMemoriaActivada ( p_tabObj->p_tabDatos );
			STabpActivarLiberacionMemoria ( p_tabObj->p_tabDatos );
			iRes = STabpAsignar ( p_tabObj->p_tabDatos, iFila, iColumna, (byte *) p_cadDatos );
			if ( iRes != 1 )
			{
				MemLiberar ( (void **) &p_cElem );
			}
			if ( iActLib == 0 )
			{
				STabpDesactivarLiberacionMemoria ( p_tabObj->p_tabDatos );
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

int STabCadLimpiarElemento ( STablaCadenas * p_tabObj, int iFila, int iColumna )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpLimpiarElemento ( p_tabObj->p_tabDatos, iFila, iColumna );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int STabCadLimpiar ( STablaCadenas * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabpLimpiar ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int	STabCadLiberacionMemoriaActivada ( STablaCadenas * p_tabObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_tabObj ) ) 
	{
		iRes = STabpLiberacionMemoriaActivada ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void STabCadActivarLiberacionMemoria ( STablaCadenas * p_tabObj )
{
	if ( ES_VALIDO ( p_tabObj ) ) 
	{
		STabpActivarLiberacionMemoria ( p_tabObj->p_tabDatos );
	}
}

void STabCadDesactivarLiberacionMemoria ( STablaCadenas * p_tabObj )
{
	if ( ES_VALIDO ( p_tabObj ) ) 
	{
		STabpDesactivarLiberacionMemoria ( p_tabObj->p_tabDatos );
	}
}

int STabCadExiste ( STablaCadenas * p_tabObj, SCadena * p_cadDato )
{
	int iRes;
	int iFila;
	int iColumna;

	if ( ES_VALIDO ( p_tabObj ) && ES_VALIDO ( p_cadDato )  ) 
	{
		iRes = 0;
		iRes = 0;
		iFila = 0;
		while ( ( iFila < STabCadNumFilas ( p_tabObj ) ) && ( iRes == 0 ) )
		{
			iColumna = 0;
			while ( ( iColumna < STabCadNumColumnas ( p_tabObj ) ) && ( iRes == 0 ) )
			{
				if ( SCadEsIgual ( STabCadElemento ( p_tabObj, iFila, iColumna ), p_cadDato ) == 1 )
				{
					iRes = 1;
				}
				iColumna = iColumna + 1;
			}
			iFila = iFila + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

