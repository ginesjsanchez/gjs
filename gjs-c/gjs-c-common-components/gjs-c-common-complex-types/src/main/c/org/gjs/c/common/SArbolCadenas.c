#include "SArbolCadenas.h"

#include "TiposDatosConfig.h"


void _SArbCadActualLimpiarHijos ( SNodoPtr * p_nodObj );


SArbolCadenas * SArbCadCrear () 
{
	SArbolCadenas * p_arbObj;
	
	p_arbObj = (SArbolCadenas *) MemReservar ( sizeof ( SArbolCadenas ) );
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_arbObj->p_arbContenido = SArbPtrCrear ();
	}
	return ( p_arbObj );
}

void SArbCadDestruir ( SArbolCadenas ** p_p_arbObj )
{
	SArbolCadenas * p_arbObj;
	
	if ( ES_VALIDO ( p_p_arbObj ) )
	{
		p_arbObj = *p_p_arbObj;
		if ( ES_VALIDO ( p_arbObj ) )
		{
			SArbCadVaciar ( p_arbObj );
			MemLiberar ( (void **) p_p_arbObj );
		}
	}
}

SCadena * SArbCadRaiz ( SArbolCadenas * p_arbObj )
{
	SCadena * p_cadRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_cadRes = (SCadena *) SArbPtrRaiz ( p_arbObj->p_arbContenido );
	}
	else
	{
		p_cadRes = NULL;
	}
	return ( p_cadRes );
}

int SArbCadEstablecerRaiz ( SArbolCadenas * p_arbObj, SCadena * p_cadValor )
{
	int 		iRes;
	SNodoPtr * 	p_nodpObj;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodpObj = SNodPtrCrear ( (byte *) p_cadValor, 0 );
		if ( SNodPtrEsValido  ( p_nodpObj ) == 1 )
		{
			iRes = SArbPtrEstablecerRaiz ( p_arbObj->p_arbContenido, p_nodpObj );
		}
		else
		{
			SNodPtrDestruir ( &p_nodpObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadEstaVacio ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbPtrEstaVacio ( p_arbObj->p_arbContenido );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadNiveles ( SArbolCadenas * p_arbObj )
{
	int iNiveles;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iNiveles = SArbPtrNiveles ( p_arbObj->p_arbContenido );
	}
	else
	{
		iNiveles = 0;
	}
	return ( iNiveles );
}

int SArbCadNumNodos ( SArbolCadenas * p_arbObj )
{
	int iNodos;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iNodos = SArbPtrNumNodos ( p_arbObj->p_arbContenido );
	}
	else
	{
		iNodos = 0;
	}
	return ( iNodos );
}

int SArbCadVaciar ( SArbolCadenas * p_arbObj )
{
	SCadena * p_cadValor;
	int		iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbCadMoverAPrimPreorden ( p_arbObj );
		while ( ES_VALIDO ( SArbCadActual ( p_arbObj ) ) )
		{
			p_cadValor = SArbCadActual ( p_arbObj );
			SArbCadMoverASigPreorden ( p_arbObj );
			SCadDestruir ( &p_cadValor );
		}
		SArbPtrVaciar ( p_arbObj->p_arbContenido );
		if ( SArbCadNumNodos ( p_arbObj ) == 0 )
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
	return ( iRes );
}

SCadena * SArbCadActual ( SArbolCadenas * p_arbObj )
{
	SCadena * p_cadRes;
	
	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_cadRes = (SCadena *) SNodPtrDatos ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		p_cadRes = NULL;
	}
	return ( p_cadRes );
}

void SArbCadMoverARaiz ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverARaiz ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAPadre ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAPadre ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAHijo ( SArbolCadenas * p_arbObj, int iHijo )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAHijo ( p_arbObj->p_arbContenido, iHijo );
	}
}

void SArbCadMoverAPrimHijo ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAPrimHijo ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAUltHijo ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAUltHijo ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAPrimHermano ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAPrimHermano ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverASigHermano ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverASigHermano ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAAntHermano ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAAntHermano ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAUltHermano ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAUltHermano ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAPrimPreorden ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAPrimPreorden ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverASigPreorden ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverASigPreorden ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAAntPreorden ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAAntPreorden ( p_arbObj->p_arbContenido );
	}
}

void SArbCadMoverAUltPreorden ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverAUltPreorden ( p_arbObj->p_arbContenido );
	}
}

void SArbCadDesposicionar ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		SArbPtrMoverARaiz ( p_arbObj->p_arbContenido );
	}
}

int	SArbCadEstaPosicionado ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbPtrEstaPosicionado ( p_arbObj->p_arbContenido );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadEnraizar ( SArbolCadenas * p_arbObj, SCadena * p_cadValor )
{
	int 		iRes;
	SNodoPtr * 	p_nodpObj;

	if ( ES_VALIDO ( p_arbObj ) && ES_VALIDO ( p_cadValor ) )
	{
		p_nodpObj = SNodPtrCrear ( (byte *) p_cadValor, 0 );
		if ( SNodPtrEsValido  ( p_nodpObj ) == 1 )
		{
			iRes = SArbPtrEnraizar ( p_arbObj->p_arbContenido, p_nodpObj );
		}
		else
		{
			SNodPtrDestruir ( &p_nodpObj, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualEsValido ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrEsValido ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualTieneDatos ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrEsValido ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualModificar ( SArbolCadenas * p_arbObj, SCadena * p_cadValor )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) && ES_VALIDO ( p_cadValor ) )
	{
		iRes = SNodPtrModificar ( SArbPtrActual ( p_arbObj->p_arbContenido  ), (byte *) p_cadValor, 1 );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


int SArbCadActualNumHijos ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrNumHijos ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * SArbCadActualPadre ( SArbolCadenas * p_arbObj )
{
	SCadena * p_cRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_cRes = (SCadena *) SNodPtrPadre ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		p_cRes = 0;
	}
	return ( p_cRes );
}

SCadena * SArbCadActualHijo ( SArbolCadenas * p_arbObj, int iHijo )
{
	SCadena * p_cRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_cRes = (SCadena *) SNodPtrHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ), iHijo );
	}
	else
	{
		p_cRes = 0;
	}
	return ( p_cRes );
}


int SArbCadActualTienePadre ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrTienePadre ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualTieneHijos ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrTieneHijos ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualTieneHermanos ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrTieneHermanos ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualTieneHermanosIzq ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrTieneHermanosIzq ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualTieneHermanosDer ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrTieneHermanosDer ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualNodosInferiores ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrNodosInferiores ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualProfundidad ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrProfundidad ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualNivelesInferiores ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrNivelesInferiores ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualInsertarHijo ( SArbolCadenas * p_arbObj, SCadena * p_cadValor )
{
	int 		iRes;
	SNodoPtr * 	p_nodHijo;

	if ( ES_VALIDO ( p_arbObj ) && ES_VALIDO ( p_cadValor ) )
	{
		p_nodHijo = SNodPtrCrear ( (byte *) p_cadValor, 0 );
		if ( SNodPtrEsValido ( p_nodHijo ) == 1 )
		{
			iRes = SNodPtrInsertarHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ), p_nodHijo );
		}
		else
		{
			SNodPtrDestruir ( &p_nodHijo, 0 );
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualEliminarHijo ( SArbolCadenas * p_arbObj, int iHijo )
{
	SNodoPtr * 	p_nodHijo;
	int 		iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		p_nodHijo = SNodPtrHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ), iHijo );
		if ( ES_VALIDO ( p_nodHijo ) )
		{
			SCadDestruir ( (SCadena **) &p_nodHijo->p_byDatos );
			_SArbCadActualLimpiarHijos ( p_nodHijo );
		}
		iRes = SNodPtrEliminarHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ),  iHijo,  1 );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadActualEstablecerHijo ( SArbolCadenas * p_arbObj, int iHijo, SCadena * p_cadValor )
{
	int 		iRes;
	SNodoPtr * 	p_nodHijo;

	if ( ES_VALIDO ( p_arbObj ) && ES_VALIDO ( p_cadValor ) )
	{
		p_nodHijo = SNodPtrHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ), iHijo );
		if ( ES_VALIDO ( p_nodHijo ) )
		{
			SCadDestruir ( (SCadena **) &p_nodHijo->p_byDatos );
			iRes = SNodPtrModificar ( SArbPtrActual ( p_arbObj->p_arbContenido ), 
				(byte *) p_cadValor, 0 );
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

void SArbCadActualLimpiarHijos ( SArbolCadenas * p_arbObj )
{
	if ( ES_VALIDO ( p_arbObj ) )
	{
		_SArbCadActualLimpiarHijos ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
}

int	SArbCadActualEsHijo ( SArbolCadenas * p_arbObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SNodPtrEsHijo ( SArbPtrActual ( p_arbObj->p_arbContenido ) );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCadVerificar ( SArbolCadenas * p_arbObj, int iCorregir )
{
	int iRes;

	if ( ES_VALIDO ( p_arbObj ) )
	{
		iRes = SArbPtrVerificar ( p_arbObj->p_arbContenido, iCorregir );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void _SArbCadActualLimpiarHijos ( SNodoPtr * p_nodObj )
{
	SNodoPtr * p_nodHijo;
	
	if ( ES_VALIDO ( p_nodObj ) )
	{
		for ( int iHijo = 0; iHijo < SNodPtrNumHijos ( p_nodObj ); iHijo = iHijo + 1 )
		{
			p_nodHijo = SNodPtrHijo ( p_nodObj, iHijo );
			if ( ES_VALIDO ( p_nodHijo ) )
			{
				SCadDestruir ( (SCadena **) &p_nodHijo->p_byDatos );
				_SArbCadActualLimpiarHijos ( p_nodHijo );
			}
		}
	}
}



