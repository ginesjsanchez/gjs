#include "SListaCadenas.h"

#include "TiposDatosConfig.h"




SListaCadenas * SLisCadCrear ()
{
	SListaCadenas * p_lisObj;
	
	p_lisObj = (SListaCadenas *) MemReservar ( sizeof ( SListaCadenas ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLispCrear ();
	}
	return ( p_lisObj );
}

void SLisCadDestruir ( SListaCadenas ** p_p_lisObj )
{
	SListaCadenas * p_lisObj;
	
	if ( ES_VALIDO ( p_p_lisObj ) )
	{
		p_lisObj = *p_p_lisObj;

		if ( ES_VALIDO ( p_lisObj ) )
		{
			SLispDestruir ( &(p_lisObj->p_lisDatos) );
			MemLiberar ( (void **) p_p_lisObj );
		}
	}
}

int SLisCadEsValida ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEsValida ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadEstaVacia ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEstaVacia ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadNumElementos ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispNumElementos ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SCadena * SLisCadElemento ( SListaCadenas * p_lisObj, int iElem )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_cRes = (SCadena *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SLisCadEstablecerElem ( SListaCadenas * p_lisObj, int iElem, SCadena * p_cadDatos )
{
	int		iRes;
	SCadena *	p_cAnt;	

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_cAnt = (SCadena *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
		MemLiberar ( (void **) &p_cAnt );
		iRes = SLispEstablecerElem ( p_lisObj->p_lisDatos, iElem, (byte *) p_cadDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadInsertarElem ( SListaCadenas * p_lisObj, int iPosAnt, SCadena * p_cadDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_cadDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadInsertarAlInicio ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	return ( SLisCadInsertarElem ( p_lisObj, -1, p_cadDatos ) );
}

int SLisCadInsertarAlFinal ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisCadInsertarElem ( p_lisObj, SLisCadNumElementos ( p_lisObj ), p_cadDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadEstablecerElemDup ( SListaCadenas * p_lisObj, int iElem, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispEstablecerElem ( p_lisObj->p_lisDatos, iElem, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadInsertarElemDup ( SListaCadenas * p_lisObj, int iPosAnt, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadInsertarDupAlInicio ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, -1, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadInsertarDupAlFinal ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, 
									   SLisCadNumElementos ( p_lisObj ), 
									   (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadEliminarElem ( SListaCadenas * p_lisObj, int iElem )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispEliminarElem ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadVaciar ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispVaciar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadPosicion ( SListaCadenas * p_lisObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispPosicion ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

SCadena * SLisCadActual ( SListaCadenas * p_lisObj )
{
	SCadena *	p_cRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_cRes = (SCadena *) SLispActual ( p_lisObj->p_lisDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

void SLisCadInicio ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispInicio ( p_lisObj->p_lisDatos );
	}
}

void SLisCadFinal ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispFinal ( p_lisObj->p_lisDatos );
	}
}

void SLisCadSiguiente ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispSiguiente ( p_lisObj->p_lisDatos );
	}
}

void SLisCadAnterior ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispAnterior ( p_lisObj->p_lisDatos );
	}
}

void SLisCadMoverA ( SListaCadenas * p_lisObj, int iElem )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispMoverA ( p_lisObj->p_lisDatos, iElem );
	}
}

void SLisCadDeposicionar ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDeposicionar ( p_lisObj->p_lisDatos );
	}
}

int SLisCadEsNulo ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEsNulo ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadEstaEnFinal ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEstaEnFinal ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadEstaEnIncio ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEstaEnIncio ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadEstablecer ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cAnt;  
	int		iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		p_cAnt = (SCadena *) SLispActual ( p_lisObj->p_lisDatos );
		MemLiberar ( (void **) &p_cAnt );
		iRes = SLispEstablecer ( p_lisObj->p_lisDatos, (byte *) p_cadDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


int SLisCadInsertar ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	return ( SLisCadInsertarDetras ( p_lisObj, p_cadDatos ) );
}

int SLisCadInsertarDelante ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_cadDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadInsertarDetras ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_cadDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadEstablecerDup ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispEstablecer ( p_lisObj->p_lisDatos, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				MemLiberar ( (void **) &p_cElem );
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

int SLisCadInsertarDup ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	return ( SLisCadInsertarDupDetras ( p_lisObj, p_cadDatos ) );
}

int SLisCadInsertarDupDelante ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadInsertarDupDetras ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cElem;
	int		iRes;
	int		iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_cElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

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

int SLisCadEliminar ( SListaCadenas * p_lisObj )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispEliminar ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisCadExiste ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos )  ) 
	{
		iRes = 0;
		iElem = 0;
		while ( ( iElem < SLisCadNumElementos ( p_lisObj ) ) && ( iRes == 0 ) )
		{
			if ( SCadEsIgual ( SLisCadElemento ( p_lisObj, iElem ), p_cadDatos ) == 1 )
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

int	SLisCadLiberacionMemoriaActivada ( SListaCadenas * p_lisObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SLisCadActivarLiberacionMemoria ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}

void SLisCadDesactivarLiberacionMemoria ( SListaCadenas * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}



