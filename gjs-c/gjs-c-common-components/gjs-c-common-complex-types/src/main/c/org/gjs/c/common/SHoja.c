#include "SHoja.h"

#include "TiposDatosConfig.h"


/*
static int SHojInicializar ( SHoja * p_hojObj );
static int SHojBuscarElem ( SHoja * p_hojObj, const char * p_cClave );

SHoja * SHojCrearDef ()
{
	return ( SHojCrear ( 0 ) );
}


SHoja * SHojCrear ( int iMaxElems )
{
	SHoja * p_hojObj;
 	
	if ( ( iMaxElems > 0 ) && ( iMaxElems < ARB_B_MAX_ELEMS_HOJA ) )
	{
		p_hojObj = (SHoja *) malloc ( sizeof ( SHoja ) );
		if ( ES_VALIDO ( p_hojObj ) )
		{	 	
			p_hojObj->iMaxElems = iMaxElems;
			SHojInicializar ( p_hojObj );
		}
	}
	else
	{
		p_hojObj = NULL;
	}
	return ( p_hojObj );
}

void SHojDestruir ( SHoja ** p_p_hojObj );
{
	SHoja * p_hojObj;
 	
	if ( p_ES_VALIDO ( p_p_hojObj ) )
	{
		p_hojObj = *p_p_hojObj;
		if ( ES_VALIDO ( p_hojObj ) )
		{
			MemLiberar ( (void **) &(p_hojObj->p_lczContenido) );
			MemLiberar ( (void **) p_p_hojObj );
		}
 	}
}

int SHojEstaVacia ( SHoja * p_hojObj )
{
	int iRes;

	if ( ES_VALIDO ( p_hojObj ) )
	{
		 if ( p_hojObj->iNumElems == 0 )
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

int SHojCompleta ( SHoja * p_hojObj )
{
	int iRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	if ( p_hojObj->iNumElems >= p_hojObj->iMaxElems )
 	 	{
 	 	 	iRes = 0;
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

int SHojInsertar ( SHoja * p_hojObj, const char * p_cClave, int p_cClave )
{
 	int iRes;
	int iFin;

 	iRes = -1;
 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	if ( ( p_hojObj->iPrimLibre >= 0 ) && ( p_hojObj->iPrimLibre < p_hojObj->iMaxElems ) )
 	 	{
 	 	 	iRes = p_hojObj->iPrimLibre;
			p_hojObj->p_lczContenido[ iRes ] = SLczCrear ( p_cClave, p_cClave );
 	 	 	p_hojObj->iNumElems = p_hojObj->iNumElems + 1;
			if ( p_hojObj->iNumElems == 1 )
			{
				p_hojObj->p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ iRes ] );
				p_hojObj->p_cMaxClave = p_hojObj->p_cMinClave;
			}
			else if ( CadComparar ( p_hojObj->p_cMinClave, p_cClave ) > 0 )
			{
				p_hojObj->p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ iRes ] );
			}
			else if ( CadComparar ( p_hojObj->p_cMaxClave, p_cClave ) < 0 )
			{
				p_hojObj->p_cMaxClave = SLczClave ( p_hojObj->p_lczContenido[ iRes ] );
			}
 	 	 	if ( p_hojObj->iNumElems >= p_hojObj->iMaxElems )
 	 	 	{
				p_hojObj->iPrimLibre = -1;
 	 	 	}
			else
			{
				iFin = 0;
				while ( ( SLczEsValido ( p_hojObj->p_lczContenido[ p_hojObj->iPrimLibre ] ) == 1 ) && ( iFin == 0 ) ) 
				{
					p_hojObj->iPrimLibre = ( p_hojObj->iPrimLibre + 1 ) % p_hojObj->iMaxElems;
					if ( p_hojObj->iPrimLibre == iRes )
					{
						iFin = 1;
					}
				}
				if ( SLczEsValido ( p_hojObj->p_lczContenido[ p_hojObj->iPrimLibre ] ) == 1 )
				{
					p_hojObj->iPrimLibre = -1;
				}
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

int SHojBuscar ( SHoja * p_hojObj, const char * p_cClave )
{
 	int iRes;
 	int iElem;

 	if ( ES_VALIDO ( p_hojObj ) )
	{
		iElem = SHojBuscarElem ( p_hojObj, p_cClave );
		if ( ( iElem >= 0 ) && ( iElem < p_hojObj->iMaxElems ) )
		{
			iRes = SLczPosicion ( p_hojObj->p_lczContenido [ iElem ] );
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
		
int SHojEliminar ( SHoja * p_hojObj, const char * p_cClave )
{
 	int iRes;
 	int iElem;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	if ( p_hojObj->iNumElems > 0 )
 	 	{
			iElem = SHojBuscarElem ( p_hojObj, p_cClave );
			if ( ( iElem >= 0 ) && ( iElem < p_hojObj->iMaxElems ) )
			{
				iRes = SLczEstablecerClave ( p_hojObj->p_lczContenido [ iElem ], NULL );
			}
			else
			{
				iRes = 0;
			}	 
 	 	 	if ( iRes == 1 )
 	 	 	{
				p_hojObj->iNumElems = p_hojObj->iNumElems - 1;
				if ( p_hojObj->iNumElems > 0 )
				{
					if ( ES_NULO ( p_hojObj->p_cMinClave ) || ES_NULO ( p_hojObj->p_cMaxClave ) )
					{
						iElem = 0
						while ( iElem < p_hojObj->iMaxElems )
						{
							if ( ES_NULO ( p_hojObj->p_cMinClave ) )
							{
								p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ iElem ] );
							}
							else if ( CadComparar ( p_hojObj->p_cMinClave, SLczClave ( p_hojObj->p_lczContenido[ Elem ] ) ) > 0 )
							{
								p_hojObj->p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ Elem ] );
							}
							if ( ES_NULO ( p_hojObj->p_cMinClave ) )
							{
								p_cMaxClave = SLczClave ( p_hojObj->p_lczContenido[ iElem ] );
							}
							else if ( CadComparar ( p_hojObj->p_cMaxClave, SLczClave ( p_hojObj->p_lczContenido[ Elem ] ) ) < 0 )
							{
								p_hojObj->p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ Elem ] );
							}
							iElem = iElem + 1;
						}
					}
					if ( ES_NULO ( p_hojObj->p_cMaxClave ) )
					{
						iElem = 0
						while ( iElem < p_hojObj->iMaxElems )
						{
							if ( ES_NULO ( p_hojObj->p_cMinClave ) )
							{
								p_cMaxClave = SLczClave ( p_hojObj->p_lczContenido[ iElem ] );
							}
							else if ( CadComparar ( p_hojObj->p_cMaxClave, SLczClave ( p_hojObj->p_lczContenido[ Elem ] ) ) > 0 )
							{
								p_hojObj->p_cMinClave = SLczClave ( p_hojObj->p_lczContenido[ Elem ] );
							}
							iElem = iElem + 1;
						}
					}
				}
				else
				{
					p_hojObj->p_cMaxClave = NULL;
					p_hojObj->p_cMinClave = NULL;
				}
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

int SHojModificar ( SHoja * p_hojObj, const char * p_cClave, int iPosicion )
{
 	int  iRes;
 	int iElem;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	if ( p_hojObj->iNumElems > 0 )
 	 	{
			iElem = SHojBuscarElem ( p_hojObj, p_cClave );
			if ( ( iElem >= 0 ) && ( iElem < p_hojObj->iMaxElems ) )
			{
				iRes = SLczEstablecerPosicion ( p_hojObj->p_lczContenido [ iElem ], iPosicion );
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

int SHojExiste ( SHoja * p_hojObj, const char * p_cClave )
{
 	int  iRes;

 	if ( SHojBuscarElem ( p_hojObj, p_cClave ) >= 0 )
 	{
  	 	iRes = 1;
 	}
 	else
 	{
 	 	iRes = 0;
 	}
 	return ( iRes );
}

int SHojEsValida ( SHoja * p_hojObj )
{
 	int iRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
		if ( ( p_hojObj->iMaxElems > 0 ) && ES_VALIDO ( p_hojObj->p_lczLocalizador ) && ( p_hojObj->iNumElems >= 0 ) && ( p_hojObj->iNumElems <= p_hojObj->iMaxElems ) )
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

int SHojEstaVacia ( SHoja * p_hojObj )

 	int iRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
		if ( p_hojObj->iNumElems == 0 )
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

int SHojNumElementos ( SHoja * p_hojObj )
{ 
 	int iRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	iRes = p_hojObj->iNumElems;
 	}
 	else
 	{
 	 	iRes = 0;
 	}
 	return ( iRes );
}

const char * SHojMinClave ( SHoja * p_hojObj )
{
 	const char * p_cRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	p_cRes = p_hojObj->p_cMinClave;
 	}
 	else
 	{
 	 	p_cRes = ;
 	}
 	return ( p_cRes );
}

const char * SHojMaxClave ( SHoja * p_hojObj )
{
 	const char * p_cRes;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	p_cRes = p_hojObj->p_cMaxClave;
 	}
 	else
 	{
 	 	p_cRes = ;
 	}
 	return ( p_cRes );
}

static void SHojInicializar ( SHoja * p_hojObj )
{
	int iElem;

	if ( ES_VALIDO ( p_hojObj ) )
	{
		MemLiberar ( (void **) &(p_hojObj->p_lczContenido) );
		p_hojObj->p_lczContenido = (SLocalizador *) MemReservar ( p_hojObj->iMaxElems * sizeof ( SLocalizador ) );
		p_hojObj->iNumElems = 0;
		p_hojObj->iPrimLibre = 0;
		p_hojObj->p_cMinClave = NULL;
		p_hojObj->p_cMaxClave = NULL;
	}
}

static int SHojBuscarElem ( SHoja * p_hojObj, const char * p_cClave )
{
 	int iRes;
 	int iElem;
	int iEnc;

 	if ( ES_VALIDO ( p_hojObj ) )
 	{
 	 	if ( p_hojObj->iNumElems > 0 )
 	 	{
 	 	 	iEnc = 0;
 	 	 	iElem = 0;
 	 	 	while ( ( iElem < p_hojObj->iMaxElems ) && ( iEnc == 0 ) )
 	 	 	{
				if ( SLczEsIgual ( p_hojObj->p_lczContenido [ iElem ], p_cClave ) == 1 )
				{
					iEnc = 1;
				}
				else
				{
					iElem = iElem + 1;
				}
 	 	 	}
			if ( iEnc == 1 )
			{
				iRes = iElem;
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

*/