#include "SListaValores.h"

#include "TiposDatosConfig.h"




SListaValores * SLisValCrear ()
{
	SListaValores * p_lisObj;
	
	p_lisObj = (SListaValores *) MemReservar ( sizeof ( SListaValores ) );
	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_lisObj->p_lisDatos = SLispCrear ();
	}
	return ( p_lisObj );
}

void SLisValDestruir ( SListaValores ** p_p_lisObj )
{
	SListaValores * p_lisObj;
	
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

int SLisValEsValida ( SListaValores * p_lisObj )
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

int SLisValEstaVacia ( SListaValores * p_lisObj )
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

int SLisValNumElementos ( SListaValores * p_lisObj )
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

SValor * SLisValElemento ( SListaValores * p_lisObj, int iElem )
{
	SValor *	p_valRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_valRes = (SValor *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
	}
	else
	{
		p_valRes = NULL;
	}
	return ( p_valRes );
}

int SLisValEstablecerElem ( SListaValores * p_lisObj, int iElem, SValor * p_valDatos )
{
	int		iRes;
	SValor *	p_valAnt;	

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_valAnt = (SValor *) SLispElemento ( p_lisObj->p_lisDatos, iElem );
		SValDestruir ( &p_valAnt );
		iRes = SLispEstablecerElem ( p_lisObj->p_lisDatos, iElem, (byte *) p_valDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisValInsertarElem ( SListaValores * p_lisObj, int iPosAnt, SValor * p_valDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_valDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisValInsertarAlInicio ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	return ( SLisValInsertarElem ( p_lisObj, -1, p_valDatos ) );
}

int SLisValInsertarAlFinal ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		iRes = SLisValInsertarElem ( p_lisObj, SLisValNumElementos ( p_lisObj ), p_valDatos );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SLisValEstablecerElemDup ( SListaValores * p_lisObj, int iElem, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispEstablecerElem ( p_lisObj->p_lisDatos, iElem, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValInsertarElemDup ( SListaValores * p_lisObj, int iPosAnt, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, iPosAnt, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValInsertarDupAlInicio ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, -1, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValInsertarDupAlFinal ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarElem ( p_lisObj->p_lisDatos, 
									   SLisValNumElementos ( p_lisObj ), 
									   (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValEliminarElem ( SListaValores * p_lisObj, int iElem )
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

int SLisValVaciar ( SListaValores * p_lisObj )
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

int SLisValPosicion ( SListaValores * p_lisObj )
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

SValor * SLisValActual ( SListaValores * p_lisObj )
{
	SValor *	p_valRes;

	if ( ES_VALIDO ( p_lisObj ) )
	{
		p_valRes = (SValor *) SLispActual ( p_lisObj->p_lisDatos );
	}
	else
	{
		p_valRes = NULL;
	}
	return ( p_valRes );
}

void SLisValInicio ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispInicio ( p_lisObj->p_lisDatos );
	}
}

void SLisValFinal ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispFinal ( p_lisObj->p_lisDatos );
	}
}

void SLisValSiguiente ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispSiguiente ( p_lisObj->p_lisDatos );
	}
}

void SLisValAnterior ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispAnterior ( p_lisObj->p_lisDatos );
	}
}

void SLisValMoverA ( SListaValores * p_lisObj, int iElem )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispMoverA ( p_lisObj->p_lisDatos, iElem );
	}
}

void SLisValDeposicionar ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDeposicionar ( p_lisObj->p_lisDatos );
	}
}

int SLisValEsNulo ( SListaValores * p_lisObj )
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

int SLisValEstaEnFinal ( SListaValores * p_lisObj )
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

int SLisValEstaEnIncio ( SListaValores * p_lisObj )
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

int SLisValEstablecer ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valAnt;  
	int			iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		p_valAnt = (SValor *) SLispActual ( p_lisObj->p_lisDatos );
		SValDestruir ( &p_valAnt );
		iRes = SLispEstablecer ( p_lisObj->p_lisDatos, (byte *) p_valDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisValInsertar ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	return ( SLisValInsertarAlFinal ( p_lisObj, p_valDatos ) );
}

int SLisValInsertarDelante ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_valDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisValInsertarDetras ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_valDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SLisValEstablecerDup ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispEstablecer ( p_lisObj->p_lisDatos, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValInsertarDup ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	return ( SLisValInsertarDupDetras ( p_lisObj, p_valDatos ) );
}

int SLisValInsertarDupDelante ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarDelante ( p_lisObj->p_lisDatos, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValInsertarDupDetras ( SListaValores * p_lisObj, SValor * p_valDatos )
{
	SValor *	p_valElem;
	int			iRes;
	int			iActLib;

	if ( ES_VALIDO ( p_lisObj ) && ES_VALIDO ( p_valDatos ) )
	{
		p_valElem = SValDuplicar ( p_valDatos );
		if ( ES_VALIDO ( p_valElem ) )
		{
			iActLib = SLispLiberacionMemoriaActivada ( p_lisObj->p_lisDatos );
			SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			iRes = SLispInsertarDetras ( p_lisObj->p_lisDatos, (byte *) p_valElem );
			if ( iActLib == 0 )
			{
				SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
			}

			if ( iRes != 1 )
			{
				SValDestruir ( &p_valElem );
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

int SLisValEliminar ( SListaValores * p_lisObj )
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

int	SLisValLiberacionMemoriaActivada ( SListaValores * p_lisObj )
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

void SLisValActivarLiberacionMemoria ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispActivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}

void SLisValDesactivarLiberacionMemoria ( SListaValores * p_lisObj )
{
	if ( ES_VALIDO ( p_lisObj ) ) 
	{
		SLispDesactivarLiberacionMemoria ( p_lisObj->p_lisDatos );
	}
}



