#include "STablaRealesDobles.h"

#include "TiposDatosConfig.h"




STablaRealesDobles * STabRealdCrear ( int iNumFilas, int iNumColumnas )
{
	STablaRealesDobles * p_tabObj;
	
	if ( ( iNumFilas > 0 ) && ( iNumColumnas > 0 ) )
	{
		p_tabObj = (STablaRealesDobles *) MemReservar ( sizeof ( STablaRealesDobles ) );
		if ( ES_VALIDO ( p_tabObj ) )
		{
			p_tabObj->p_tabDatos = STabCrear ( iNumFilas, iNumColumnas );
		}
	}
	else
	{
		p_tabObj = NULL;
	}
	return ( p_tabObj );
}

void STabRealdDestruir ( STablaRealesDobles ** p_p_tabObj )
{
	STablaRealesDobles * p_tabObj;
	
	if ( ES_VALIDO ( p_p_tabObj ) )
	{
		p_tabObj = *p_p_tabObj;

		if ( ES_VALIDO ( p_tabObj ) )
		{
			STabDestruir ( &(p_tabObj->p_tabDatos) );
			MemLiberar ( (void **) p_p_tabObj );
		}
	}
}

int STabRealdEsValida ( STablaRealesDobles * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabEsValida ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabRealdNumFilas ( STablaRealesDobles * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabNumFilas ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabRealdNumColumnas ( STablaRealesDobles * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabNumColumnas ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabRealdNumElementos ( STablaRealesDobles * p_tabObj )
{
	int iRes;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = STabNumElementos ( p_tabObj->p_tabDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

double STabRealdElemento ( STablaRealesDobles * p_tabObj, int iFila, int iColumna )
{
	double			dRes;
	SContenido *	p_conObj;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		p_conObj = STabElemento ( p_tabObj->p_tabDatos, iFila, iColumna );
		if ( ES_VALIDO ( p_conObj ) )
		{
			dRes = SConRealDoble ( p_conObj );
		}
		else
		{
			dRes = 0;
		}
	}
	else
	{
		dRes = 0;
	}
	return ( dRes );
}

int STabRealdAsignar ( STablaRealesDobles * p_tabObj, int iFila, int iColumna, double dDato )
{
	int				iRes;
	SContenido *	p_conObj;
	int				iCreado;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		if ( ( iFila >= 0 ) && ( iFila < STabNumFilas ( p_tabObj->p_tabDatos ) ) &&
			 ( iColumna >= 0 ) && ( iFila < STabNumColumnas ( p_tabObj->p_tabDatos ) ) )
		{
			p_conObj = STabElemento ( p_tabObj->p_tabDatos, iFila, iColumna );
			if ( ES_NULO ( p_conObj ) )
			{
				iCreado = 1;
				p_conObj = SConCrearRealDoble ();
			}
			else
			{
				iCreado = 0;
			}
			if ( ES_VALIDO ( p_conObj ) )
			{
				if ( SConEscribirRealDoble ( p_conObj, dDato ) == 1 )
				{
					iRes = STabAsignar ( p_tabObj->p_tabDatos, iFila, iColumna, p_conObj );
				}
				else
				{
					iRes = 0;
				}
				if ( ( iCreado == 1 ) && ( iRes != 1 ) )
				{
					SConDestruir ( &p_conObj );
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STabRealdInicializar ( STablaRealesDobles * p_tabObj )
{
	int iRes;
	int iFila;
	int iColumna;

	if ( ES_VALIDO ( p_tabObj ) )
	{
		iRes = 0;
		iFila = 0;
		while ( ( iFila < STabRealdNumFilas ( p_tabObj ) ) && ( iRes == 0 ) )
		{
			iColumna = 0;
			while ( ( iColumna < STabRealdNumColumnas ( p_tabObj ) ) && ( iRes == 0 ) )
			{
				iRes = STabRealdAsignar ( p_tabObj, iFila, iColumna, 0 );
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

int STabRealdExiste ( STablaRealesDobles * p_tabObj, double dDato )
{
	int iRes;
	int iFila;
	int iColumna;

	if ( ES_VALIDO ( p_tabObj ) ) 
	{
		iRes = 0;
		iFila = 0;
		while ( ( iFila < STabRealdNumFilas ( p_tabObj ) ) && ( iRes == 0 ) )
		{
			iColumna = 0;
			while ( ( iColumna < STabRealdNumColumnas ( p_tabObj ) ) && ( iRes == 0 ) )
			{
				if ( STabRealdElemento ( p_tabObj, iFila, iColumna ) == dDato )
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




