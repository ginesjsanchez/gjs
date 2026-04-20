
#include "STexto.h"

#include "TextoConfig.h"
#include "Cadenas.h"


int _STxtPosMenorOIgual ( int iLinIni, int iColIni, int iLinFin, int iCol);


STexto * STxtCrear ()
{
	STexto * p_txtObj;
	
	p_txtObj = (STexto *) MemReservar ( sizeof ( STexto ) );
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_txtObj->p_lisLineas = SLisCadCrear ();
		p_txtObj->iLineaAct = -1;
		p_txtObj->iColumnaAct = -1;
	}
	else
	{
		p_txtObj = NULL;
	}
	return ( p_txtObj );
}

STexto * STxtGenerarLiteral ( const char * p_cTexto )
{
	STexto *	p_txtObj;
	
	p_txtObj = STxtCrear ();
	if ( ES_VALIDO ( p_txtObj ) )
	{
		STxtInicializar ( p_txtObj, p_cTexto );
	}
	return ( p_txtObj );
}

void STxtDestruir ( STexto ** p_p_txtObj )
{
	STexto * p_txtObj;
	
	if ( ES_VALIDO ( p_p_txtObj ) )
	{
		p_txtObj = *p_p_txtObj;

		if ( ES_VALIDO ( p_txtObj ) )
		{
			SLisCadDestruir ( & (p_txtObj->p_lisLineas) );
			MemLiberar ( (void **) p_p_txtObj );
		}
	}
}

int STxtEsValido ( STexto * p_txtObj )
{
	int iRes;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( SLisCadEsValida ( p_txtObj->p_lisLineas ) == 1 )
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
		iRes = 0;
	}
	return ( iRes );
}

int STxtEstaPosicionado ( STexto * p_txtObj )
{
	int iRes;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( ( p_txtObj->iLineaAct >= 0 ) &&
				 ( p_txtObj->iColumnaAct >= 0 ) )
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
		iRes = 0;
	}
	return ( iRes );
}


int STxtCursorEsValido ( STexto * p_txtObj )
{
	int 		iRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( ( p_txtObj->iLineaAct >= 0 ) && ( p_txtObj->iLineaAct < STxtNumLineas ( p_txtObj ) ) )
		{
			iRes = STxtPosEsValida ( p_txtObj, p_txtObj->iLineaAct, p_txtObj->iColumnaAct );
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

int STxtPosEsValida ( STexto * p_txtObj, int iLinea, int iColumna )
{
	int 		iRes;
	SCadena * 	p_cadLinea;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( ( iLinea >= 0 ) && ( iLinea < STxtNumLineas ( p_txtObj ) ) )
		{
			p_cadLinea = STxtLinea ( p_txtObj, iLinea );
			if ( ES_VALIDO ( p_cadLinea ) )
			{
				if	 ( ( iColumna >= 0 ) && ( iColumna < SCadLongitud ( p_cadLinea ) ) )
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

int STxtInicializar ( STexto * p_txtObj, const char * p_cTexto )
{
	int 		iRes;
	int			iNumLineas;
	SCadena * 	p_cadLinea;
	char *		p_cLinea;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		SLisCadVaciar ( p_txtObj->p_lisLineas );
		iNumLineas = CadNumPalabrasSep ( p_cTexto, '\n' );
		for ( int iLinea = 0; iLinea < iNumLineas; iLinea = iLinea + 1 )
		{
			p_cLinea = CadPalabraSep ( p_cTexto, iLinea, '\n' );
			p_cadLinea = SCadGenerar ( p_cLinea );
			SLisCadInsertar ( p_txtObj->p_lisLineas, p_cadLinea );
			MemLiberar ( (void **) p_cLinea );
		}
		iRes = iNumLineas;
		p_txtObj->iLineaAct = 0;
		p_txtObj->iColumnaAct = 0;
	}
	else
	{
		iRes = 0;
		p_txtObj->iLineaAct = -1;
		p_txtObj->iColumnaAct = -1;
	}
	return ( iRes );
}

void STxtVaciar ( STexto * p_txtObj )
{
	if ( ES_VALIDO ( p_txtObj ) )
	{
		SLisCadVaciar ( p_txtObj->p_lisLineas );
		p_txtObj->iLineaAct = -1;
		p_txtObj->iColumnaAct = -1;
	}
}

int STxtNumLineas ( STexto * p_txtObj )
{
	int iRes;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		iRes = SLisCadNumElementos ( p_txtObj->p_lisLineas );
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}


int STxtCursorLinea ( STexto * p_txtObj )
{
	int iRes;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		iRes = p_txtObj->iLineaAct;
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int STxtCursorColumna ( STexto * p_txtObj )
{
	int iRes;

	if ( ES_VALIDO ( p_txtObj ) )
	{
		iRes = p_txtObj->iColumnaAct;
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

void STxtIrInicio ( STexto * p_txtObj )
{
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( STxtNumLineas ( p_txtObj ) > 0 )
		{
			p_txtObj->iLineaAct = 0;
			p_txtObj->iColumnaAct = 0;
		}
		else
		{
			p_txtObj->iLineaAct = -1;
			p_txtObj->iColumnaAct = -1;
		}
	}
}

void STxtIrFinal ( STexto * p_txtObj )
{
	SCadena * p_cadLinea;
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( STxtNumLineas ( p_txtObj ) > 0 )
		{
			p_txtObj->iLineaAct = STxtNumLineas ( p_txtObj );
			p_cadLinea = STxtLineaActual ( p_txtObj );
			if ( ES_VALIDO ( p_cadLinea ) ) 
			{
				p_txtObj->iColumnaAct = SCadLongitud ( p_cadLinea ) - 1;
			}
		}
		else
		{
			p_txtObj->iLineaAct = -1;
			p_txtObj->iColumnaAct = -1;
		}
	}
}

int STxtSig ( STexto * p_txtObj )
{
	SCadena * 	p_cadLinea;
	int			iRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadLinea = STxtLineaActual ( p_txtObj );
		p_txtObj->iColumnaAct = p_txtObj->iColumnaAct + 1;
		if ( p_txtObj->iColumnaAct >= SCadLongitud ( p_cadLinea ) ) 
		{
			if ( p_txtObj->iLineaAct < STxtNumLineas ( p_txtObj ) - 1 )
			{
				p_txtObj->iLineaAct = p_txtObj->iLineaAct + 1;
				p_cadLinea = STxtLineaActual ( p_txtObj );
				if ( ES_VALIDO ( p_cadLinea ) ) 
				{
					if ( SCadLongitud ( p_cadLinea ) > 0 )
					{			
						p_txtObj->iColumnaAct = 0;
					}
					else
					{
						p_txtObj->iColumnaAct = -1;
					}
					iRes = 1;
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
			iRes = 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STxtAnt ( STexto * p_txtObj )
{
	SCadena * 	p_cadLinea;
	int			iRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_txtObj->iColumnaAct = p_txtObj->iColumnaAct - 1;
		if ( p_txtObj->iColumnaAct < 0 ) 
		{
			if ( p_txtObj->iLineaAct > 0 )
			{
				p_txtObj->iLineaAct = p_txtObj->iLineaAct - 1;
				p_cadLinea = STxtLineaActual ( p_txtObj );
				if ( ES_VALIDO ( p_cadLinea ) ) 
				{
					p_txtObj->iColumnaAct = SCadLongitud ( p_cadLinea ) - 1;
					iRes = 1;
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
			iRes = 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void STxtIrInicioLinea ( STexto * p_txtObj )
{
	SCadena * p_cadLinea;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadLinea = STxtLineaActual ( p_txtObj );
		if ( ES_VALIDO ( p_cadLinea ) ) 
		{
			if ( SCadLongitud ( p_cadLinea ) > 0 )
			{			
				p_txtObj->iColumnaAct = 0;
			}
			else
			{
				p_txtObj->iColumnaAct = -1;
			}
		}
	}
}

void STxtIrFinalLinea ( STexto * p_txtObj )
{
	SCadena * p_cadLinea;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadLinea = STxtLineaActual ( p_txtObj );
		if ( ES_VALIDO ( p_cadLinea ) ) 
		{
			if ( SCadLongitud ( p_cadLinea ) > 0 )
			{			
				p_txtObj->iColumnaAct = 0;
			}
			else
			{
				p_txtObj->iColumnaAct = -1;
			}
		}
	}
}

void STxtIrPrimeraLinea ( STexto * p_txtObj )
{
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( STxtNumLineas ( p_txtObj ) > 0 )
		{
			p_txtObj->iLineaAct = 0;
		}
		else
		{
			p_txtObj->iLineaAct = -1;
		}
	}
}

void STxtIrUltimaLinea ( STexto * p_txtObj )
{
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_txtObj->iLineaAct = STxtNumLineas ( p_txtObj ) - 1;
	}
}

int STxtSigLinea ( STexto * p_txtObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( p_txtObj->iLineaAct < STxtNumLineas ( p_txtObj ) - 1 )
		{
			p_txtObj->iLineaAct = p_txtObj->iLineaAct + 1;
			iRes = 1;
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

int STxtAntLinea ( STexto * p_txtObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		if ( p_txtObj->iLineaAct > 0 )
		{
			p_txtObj->iLineaAct = p_txtObj->iLineaAct - 1;
			iRes = 1;
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

void STxtIrA ( STexto * p_txtObj, int iLinea, int iColumna )
{
	if ( ES_VALIDO ( p_txtObj ) && ( STxtPosEsValida ( p_txtObj, iLinea, iColumna ) == 1 ) )
	{
		p_txtObj->iLineaAct = iLinea;
		p_txtObj->iColumnaAct = iColumna;
	}
}

SCadena * STxtLineaActual ( STexto * p_txtObj )
{
	return ( STxtLinea ( p_txtObj, p_txtObj->iLineaAct ) );
}

SCadena * STxtLinea ( STexto * p_txtObj, int iLinea )
{
	SCadena * p_cadRes;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadRes = SLisCadElemento ( p_txtObj->p_lisLineas, iLinea );
	}
	else
	{
		p_cadRes = NULL;
	}
	return ( p_cadRes );
}

char STxtCaracterActual ( STexto * p_txtObj )
{
	char		cRes;
	SCadena * 	p_cadLinea;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadLinea = STxtLineaActual ( p_txtObj );
		if ( ES_VALIDO ( p_cadLinea ) )
		{
			cRes = SCadCaracter ( p_cadLinea, p_txtObj->iColumnaAct );
		}
		else
		{
			cRes = (char) 0;
		}
	}
	else
	{
		cRes = (char) 0;
	}
	return ( cRes );
}

char STxtCaracterSig ( STexto * p_txtObj )
{
	char		cRes;
	SCadena * 	p_cadLinea;
	int			iPos;
	
	if ( ES_VALIDO ( p_txtObj ) )
	{
		p_cadLinea = STxtLineaActual ( p_txtObj );
		if ( ES_VALIDO ( p_cadLinea ) )
		{
			iPos = p_txtObj->iColumnaAct + 1;
			if ( p_txtObj->iColumnaAct == SCadLongitud ( p_cadLinea ) - 1 )
			{
				p_cadLinea = STxtLinea ( p_txtObj,p_txtObj->iLineaAct  + 1 );
				iPos = 0;
			}
			if ( ES_VALIDO ( p_cadLinea ) )
			{
				cRes = SCadCaracter ( p_cadLinea, iPos );
			}
			else
			{
				cRes = (char) 0;
			}
		}
		else
		{
			cRes = (char) 0;
		}
	}
	else
	{
		cRes = (char) 0;
	}
	return ( cRes );
}

SCadena * STxtExtraer ( STexto * p_txtObj, int iLinIni, int iColIni, int iLinFin, int iColFin )
{
	SCadena * 	p_cadRes;
	SCadena * 	p_cadLinea;
	SCadena * 	p_cadSubcad;
	int 		iPosIni;
	int 		iPosFin;
	
	if ( ES_VALIDO ( p_txtObj ) && ( STxtPosEsValida ( p_txtObj, iLinIni, iColIni ) == 1 ) && 
		( STxtPosEsValida ( p_txtObj, iLinFin, iColFin ) == 1 ) && 
			( _STxtPosMenorOIgual ( iLinIni, iColIni, iLinFin, iColFin ) == 1 ) )
	{
		printf ( "** ENTRA\n" );
		p_cadRes = SCadCrearDef ();
		for ( int iLinea = iLinIni; iLinea <= iLinFin;  iLinea = iLinea + 1 )
		{
			p_cadLinea = STxtLinea ( p_txtObj, iLinea );
			SCadImprimirExt(p_cadLinea, "** LIN", '=', 1);
			if ( iLinea > iLinIni ) 
			{
				iPosIni = 0;
			}
			else 
			{
				iPosIni = iColIni;
			}
			if ( iLinea < iLinFin ) 
			{
				iPosFin = SCadLongitud ( p_cadLinea );
			}
			else 
			{
				iPosFin = iColFin - 1;
			}
			p_cadSubcad = SCadExtraer ( p_cadLinea, iPosIni, iPosFin );	
			SCadImprimirExt(p_cadSubcad, "** SUB", '=', 1);
			SCadConcatenar ( p_cadRes, p_cadSubcad );
			SCadImprimirExt(p_cadRes, "** RES", '=', 1);
			SCadDestruir ( &p_cadSubcad );
		}
	}
	else
	{
		p_cadRes = NULL;
		printf ( "Valida 1=%d\n", STxtPosEsValida ( p_txtObj, iLinIni, iColIni ) ); 
		printf ( "Valida 1=%d\n", STxtPosEsValida ( p_txtObj, iLinFin, iColFin ) ); 
		printf ( "Valida 1=%d\n", _STxtPosMenorOIgual ( iLinIni, iColIni, iLinFin, iColFin ));
	}
	return ( p_cadRes );
}


int _STxtPosMenorOIgual ( int iLinIni, int iColIni, int iLinFin, int iColFin )
{
	int iRes;
	if ( ( iLinIni < iLinFin ) || ( ( iLinIni == iLinFin ) && ( iColIni <= iColFin ) ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


/*
void TxtInsertarCaracter ( TTEXTO *p_txtObj, char c )
{
	char 	*sLineaNueva;

	if ( lNumLineas == 0 ) 
	{
		TxtInsertarLinea ( p_txtObj );
		TxtInicio ( p_txtObj );
	}

	if ( p_txtObj->iColumnaAct == strlen ( * ( ( p_txtObj->psLineas ) + iLineaAct ) ) )
	{
		// Añadir al final:
		
	}
	else
	{
		// Insertar en medio:
	}
}


void TxtInsertarLinea ( TTEXTO *p_txtObj, char *sCadena );


TLINEA TxtLinea ( TTEXTO *plinDatos );
char *TxtCadenaLinea ( TTEXTO *plinDatos );
char *TxtCadenaTexto ( TTEXTO *plinDatos );

void TxtEliminarCaracter ( TTEXTO *pLinDatos );


void TxtImprimir ( TTEXTO *p_txtObj )
{
}

*/