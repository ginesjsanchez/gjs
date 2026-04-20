#include "SListaCadenas.h"

#include "TextoConfig.h"




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
			SLisCadVaciar ( p_lisObj );
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
	SCadena *	p_cadAnt;
	SCadena *	p_cadElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadAnt = SLisCadElemento ( p_lisObj, iElem );
		if ( ES_VALIDO ( p_cadAnt ) )
		{
			p_cadElem = SCadDuplicar ( p_cadDatos );
			if ( ES_VALIDO ( p_cadElem ) )
			{
				iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
				if ( iActLib == 1 ) 
				{
					SCadDestruir ( &p_cadAnt );
				}
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
				iRes = SLispEstablecerElem ( p_lisObj->p_lisDatos, iElem, (byte *) p_cadElem );
				if ( iActLib == 1 )
				{
					SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
				}

				if ( iRes != 1 )
				{
					SCadDestruir ( &p_cadElem );
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
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadInsertarElemDup ( SListaCadenas * p_lisObj, int iPosAnt, SCadena * p_cadDatos )
{
	SCadena *	p_cadElem;
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cadElem ) )
		{
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_cadElem );

			if ( iRes != 1 )
			{
				SCadDestruir ( &p_cadElem );
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
	SCadena *	p_cadElem;
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cadElem ) )
		{
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, -1, (byte *) p_cadElem );
			if ( iRes != 1 )
			{
				SCadDestruir ( &p_cadElem );
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
	SCadena *	p_cadElem;
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cadElem ) )
		{
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, 
									   SLisCadNumElementos ( p_lisObj ), 
									   (byte *) p_cadElem );
			if ( iRes != 1 )
			{
				SCadDestruir ( &p_cadElem );
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
	int 		iRes;
	SCadena * 	p_cadObj;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iActLib = SLisCadLiberacionMemoriaActivada ( p_lisObj );
		if ( iActLib == 1 ) 
		{
			p_cadObj = SLisCadElemento ( p_lisObj, iElem );
			if ( ES_VALIDO ( p_cadObj ) ) 
			{
				SCadDestruir ( &p_cadObj );	
			}
		}
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );	
		iRes = SLispEliminarElem ( p_lisObj->p_lisDatos, iElem );
		if ( iActLib == 1 )
		{
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadVaciar ( SListaCadenas * p_lisObj )
{
	int 		iRes;
	SCadena * 	p_cadObj;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iActLib = SLisCadLiberacionMemoriaActivada ( p_lisObj );
		if ( iActLib == 1 ) 
		{
			for ( int iElem = 0; iElem < SLisCadNumElementos ( p_lisObj ); iElem = iElem + 1 )
			{
				p_cadObj = SLisCadElemento ( p_lisObj, iElem );
				SCadDestruir ( &p_cadObj );
			}
		}
		SLispDesactivarLiberacionMemoria( p_lisObj->p_lisDatos );
		iRes = SLispVaciar ( p_lisObj->p_lisDatos );
		if ( iActLib == 1 )
		{
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
		}
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
	SCadena *	p_cadAnt;
	SCadena *	p_cadElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadAnt = SLisCadActual ( p_lisObj );
		if ( ES_VALIDO ( p_cadAnt ) )
		{
			p_cadElem = SCadDuplicar ( p_cadDatos );
			if ( ES_VALIDO ( p_cadElem ) )
			{
				iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
				if ( iActLib == 1 ) 
				{
					SCadDestruir ( &p_cadAnt );
				}
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
				iRes = SLispEstablecer ( p_lisObj->p_lisDatos, (byte *) p_cadElem );
				if ( iActLib == 1 )
				{
					SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
				}

				if ( iRes != 1 )
				{
					SCadDestruir ( &p_cadElem );
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

int SLisCadInsertarDup ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	return ( SLisCadInsertarDupDetras ( p_lisObj, p_cadDatos ) );
}

int SLisCadInsertarDupDelante ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	SCadena *	p_cadElem;
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cadElem ) )
		{
			iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_cadElem );

			if ( iRes != 1 )
			{
				SCadDestruir ( &p_cadElem );
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
	SCadena *	p_cadElem;
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		p_cadElem = SCadDuplicar ( p_cadDatos );
		if ( ES_VALIDO ( p_cadElem ) )
		{
			iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_cadElem );

			if ( iRes != 1 )
			{
				SCadDestruir ( &p_cadElem );
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
	int 		iRes;
	SCadena * 	p_cadAnt;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		p_cadAnt = SLisCadActual ( p_lisObj );
		if ( ES_VALIDO ( p_cadAnt ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			if ( iActLib == 1 ) 
			{
				SCadDestruir ( &p_cadAnt );
			}
			SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispEliminar ( p_lisObj->p_lisDatos );
			if ( iActLib == 1 )
			{
				SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
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

int SLisCadBuscar ( SListaCadenas * p_lisObj, SCadena * p_cadDatos )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cadDatos ) )
	{
		iRes = -1;
		iElem = 0;
		while ( ( iElem < SLisCadNumElementos ( p_lisObj ) ) && ( iRes == -1 ) )
		{
			if ( SCadEsIgual ( SLisCadElemento ( p_lisObj, iElem ), p_cadDatos ) == 1 )
			{
				iRes = iElem;
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisCadBuscarExt ( SListaCadenas * p_lisObj, const char * p_cDatos )
{
	int iRes;
	int iElem;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_cDatos ) )
	{
		iRes = -1;
		iElem = 0;
		while ( ( iElem < SLisCadNumElementos ( p_lisObj ) ) && ( iRes == -1 ) )
		{
			if ( SCadEsIgualLiteral ( SLisCadElemento ( p_lisObj, iElem ), p_cDatos ) == 1 )
			{
				iRes = iElem;
			}
			iElem = iElem + 1;
		}
	}
	else
	{
		iRes = -1;
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



