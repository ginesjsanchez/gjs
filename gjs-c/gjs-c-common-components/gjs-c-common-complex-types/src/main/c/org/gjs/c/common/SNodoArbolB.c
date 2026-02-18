

#include "SNodoArbolB.h"

#include "TiposDatosConfig.h"


/*
static void SNodArbBInicializar ( SNodoArbolB * p_nodgObj );

SNodoArbolB * SNodArBCrear ()
{
	return ( SNodArBCrear ( ARB_B_MIN_ORDEN ) );
}

SNodoArbolB * SNodArBCrear ( int iMaxAristas ) 
{
	SNodoArbolB * p_nodgObj;
   
	if ( ( iMaxAristas > 0 ) && ( iMaxAristas <= GRAF_MAX_ARISTAS_NODO ) )
	{
		p_nodgObj = (SNodoArbolB *) malloc ( sizeof ( SNodoArbolB ) );
		if ( ES_VALIDO ( p_nodgObj ) )
		{   
			p_nodgObj->iMaxAristas = iMaxAristas;
			SNodArBInicializar ( p_nodgObj );
		}
	}
	else
	{
		p_nodgObj = NULL;
	}
	return ( p_nodgObj );
}

SNodArBvoid SNodArBDestruir ( SNodoArbolB ** p_p_nodgObj )
{
	SNodoArbolB * p_nodgObj;

	if ( ES_VALIDO ( p_p_nodgObj ) )
	{
		p_nodgObj = *p_p_nodgObj
		if ( ES_VALIDO ( p_nodgObj ) )
		{
			SNodArBLimpiarAristasEntrada ( p_nodgObj );
			SNodArBLimpiarAristasSalida ( p_nodgObj );
			MemLiberar ( (void **) &(p_nodgObj->p_cDiscriminantes) );
			MemLiberar ( (void **) &(p_nodgObj->p_nodHijos) );
			MemLiberar ( ( void *) p_p_nodgObj );
		}
	}
}

int SNodArBId ( SNodoArbolB * p_nodgObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = iId;
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

void SNodArBEstablecerId ( int iId )
{
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		p_nodgObj->iId = iId;
	}
}

int SNodArBDato ( SNodoArbolB * p_nodgObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = p_nodgObj->iDato;
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

void SNodArBEstablecerDato ( SNodoArbolB * p_nodgObj, int iValor )
{
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		p_nodgObj->iDato = iValor;
	}
}

int SNodArBMaxAristas ( SNodoArbolB * p_nodgObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = p_nodgObj->iMaxAristas;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBNumAristasEntrada ( SNodoArbolB * p_nodgObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = p_nodgObj->iNumClaves;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBNumAristasSalida ( SNodoArbolB * p_nodgObj )
{
	int iRes;
	
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = p_nodgObj->iNumAristasSal;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBAristaEntradaEsValida ( SNodoArbolB * p_nodgObj, int iArista )
{
	int iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumClaves ) )
		{
			if ( ES_VALIDO ( p_nodgObj->p_cDiscriminantes [ iArista ] ) )
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
	return ( iRes );
}

int SNodArBAristaSalidaEsValida ( SNodoArbolB * p_nodgObj, int iArista )
{
	int iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumAristasSal ) )
		{
			if ( ES_VALIDO ( p_nodgObj->p_nodHijos [ iArista ] ) )
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
	return ( iRes );
}

SAristaGrafo * SNodArBAristaEntrada ( SNodoArbolB * p_nodgObj, int iArista )
{
	SAristaGrafo *	p_arigArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumClaves ) )
		{
			p_arigArista = p_nodgObj->p_cDiscriminantes [ iArista ];
		}
		else
		{
			p_arigArista = NULL;
		}
	}
	else
	{
		p_arigArista = NULL;
	}
	return ( p_arigArista );
}

SAristaGrafo * SNodArBAristaSalida ( SNodoArbolB * p_nodgObj, int iArista )
{
	SAristaGrafo *	p_arigArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumAristasSal ) )
		{
			p_arigArista = p_nodgObj->p_nodHijos [ iArista ];
		}
		else
		{
			p_arigArista = NULL;
		}
	}
	else
	{
		p_arigArista = NULL;
	}
	return ( p_arigArista );
}

int SNodArBTieneAristasEntrada ( SNodoArbolB * p_nodgObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( p_nodgObj->iNumClaves > 0 )
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

int SNodArBTieneAristasSalida ( SNodoArbolB * p_nodgObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( p_nodgObj->iNumAristasSal > 0 )
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

int SNodArBTieneAristasEntradaPorRecorrer ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = 0;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumClaves ) && ( iRes == 0 ) )
		{
			p_arigRes = p_nodgObj->p_cDiscriminantes [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 0 ) 
			{
				iRes = 1;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBTieneAristasSalidaPorRecorrer ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = 0;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumAristasSal ) && ( iRes == 0 ) )
		{
			p_arigRes = p_nodgObj->p_nodHijos [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 0 ) 
			{
				iRes = 1;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBTieneAristasEntradaRecorridas ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = 0;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumClaves ) && ( iRes == 0 ) )
		{
			p_arigRes = p_nodgObj->p_cDiscriminantes [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 1 ) 
			{
				iRes = 1;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBTieneAristasSalidaRecorridas ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = 0;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumAristasSal ) && ( iRes == 0 ) )
		{
			p_arigRes = p_nodgObj->p_nodHijos [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 1 ) 
			{
				iRes = 1;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodArBPrimeraAristaEntradaPorRecorrer ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = -1;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumClaves ) && ( iRes < 0 ) )
		{
			p_arigRes = p_nodgObj->p_cDiscriminantes [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 0 ) 
			{
				iRes = iArista;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SNodArBPrimeraAristaSalidaPorRecorrer ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = -1;
		iArista = 0;
		while ( ( iArista < p_nodgObj->iNumAristasSal ) && ( iRes < 0 ) )
		{
			p_arigRes = p_nodgObj->p_nodHijos [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 0 ) 
			{
				iRes = iArista;
			}
			iArista = iArista + 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SNodArBUltimaAristaEntradaRecorrida ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = -1;
		iArista = p_nodgObj->iNumClaves;
		while ( ( iArista >= 0 ) && ( iRes < 0 ) )
		{
			p_arigRes = p_nodgObj->p_cDiscriminantes [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 1 ) 
			{
				iRes = iArista;
			}
			iArista = iArista - 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SNodArBUltimaAristaSalidaRecorrida ( SNodoArbolB * p_nodgObj )
{
	int				iRes;
	int				iArista;
	SAristaGrafo * p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		iRes = -1;
		iArista = p_nodgObj->iNumAristasSal;
		while ( ( iArista >= 0 ) && ( iRes < 0 ) )
		{
			p_arigRes = p_nodgObj->p_nodHijos [ iArista ];
			if ( SAriGrfEstaRecorrida ( p_arigRes ) == 1 ) 
			{
				iRes = iArista;
			}
			iArista = iArista - 1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

int SNodArBConectarAristaEntrada ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( p_nodgObj->iNumClaves < p_nodgObj->iMaxAristas ) && ES_VALIDO ( p_arigObj ) )
		{
			p_nodgObj->iNumClaves = p_nodgObj->iNumClaves + 1;
			p_nodgObj->p_cDiscriminantes [ p_nodgObj->iNumClaves - 1 ] = p_arigObj;
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

int SNodArBConectarAristaSalida ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( p_nodgObj->iNumAristasSal < p_nodgObj->iMaxAristas ) && ES_VALIDO ( p_arigObj ) )
		{
			p_nodgObj->iNumAristasSal = p_nodgObj->iNumAristasSal + 1;
			p_nodgObj->p_nodHijos [ p_nodgObj->iNumAristasSal - 1 ] = p_arigObj;
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

SAristaGrafo * SNodArBDesconectarAristaEntrada ( SNodoArbolB * p_nodgObj, int iArista )
{
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumClaves ) )
		{
			p_arigRes = p_nodgObj->p_cDiscriminantes [ iArista ];
			p_nodgObj->p_cDiscriminantes [ iArista ] = NULL;

			for ( iArista = iArista + 1; iArista < p_nodgObj->iNumClaves; iArista = iArista + 1 )
			{
				p_nodgObj->p_cDiscriminantes [ iArista - 1 ] = p_nodgObj->p_cDiscriminantes [ iArista ];
			}
			p_nodgObj->p_cDiscriminantes [ p_nodgObj->iNumClaves - 1 ] = NULL;
			p_nodgObj->iNumClaves = p_nodgObj->iNumClaves - 1;
		}
		else
		{
			p_arigRes = NULL;
		}
	}
	else
	{
		p_arigRes = NULL;
	}
	return ( p_arigRes );
}

SAristaGrafo * SNodArBDesconectarAristaSalida ( SNodoArbolB * p_nodgObj, int iArista )
{
	int				iArista;
	SAristaGrafo * 	p_arigRes;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( iArista >= 0 ) && ( iArista < p_nodgObj->iNumAristasSal ) )
		{
			p_arigRes = p_nodgObj->p_nodHijos [ iArista ];
			p_nodgObj->p_nodHijos [ iArista ] = NULL;

			for ( iArista = iArista + 1; iArista < p_nodgObj->iNumAristasSal; iArista = iArista + 1 )
			{
				p_nodgObj->p_nodHijos [ iArista - 1 ] = p_nodgObj->p_nodHijos [ iArista ];
			}
			p_nodgObj->p_nodHijos [ p_nodgObj->iNumAristasSal - 1 ] = NULL;
			p_nodgObj->iNumAristasSal = p_nodgObj->iNumAristasSal - 1;
		}
		else
		{
			p_arigRes = NULL;
		}
	}
	else
	{
		p_arigRes = NULL;
	}
	return ( p_arigRes );
}

void ArbBNodoInicializar ( TArbBNodo *pabnObj )
{
   long lClave;

   if ( pabnObj != NULL )
   {
     for ( lClave = 0; lClave < ARB_B_MAX_HIJOS_POR_NODO;
        lCalve = lClave + 1 ) 
     {
        pabnObj->sclvDiscriminante [ lClave ] = ARB_B_CLAVE_NULA;
        pabnObj->spabnHijos    [ lClave ] = ARB_B_NODO_NULO;
     }
     p_hojObj->pabnSigHermano = ARB_B_NODO_NULO;
     p_hojObj->lNumClaves = 0;
   }
}


int ArbBNodoVacio ( TArbBNodo *pabnObj )
{
   int iRet;

   if ( pabnObj != NULL )
   {
     if ( pabnObj->lNumClaves == 0 )
     {
        iRet = TRUE;
     }
     else
     {
        iRet = FALSE;
     }
   }
   else
   {
     iRet = FALSE;
   }
   return ( iRet );
}


int ArbBNodoCompleto ( TArbBNodo *pabnObj )
{
   int iRet;

   if ( pabnObj != NULL )
   {
     if ( pabnObj->lNumClaves >= ARB_B_MAX_HIJOS_POR_NODO )
     {
        iRet = TRUE;
     }
     else
     {
        iRet = FALSE;
     }
   }
   else
   {
     iRet = FALSE;
   }
   return ( iRet );
}


TArbBNodo ArbBNodoBuscar ( TArbBNodo *pabnObj, const char * clvBus )
{
   int       iEnc;
   long      lClave;
   TArbBNodo pabnSig;

   if ( pabnObj != NULL )
   {
     if ( pabnObj->lNumClaves > 0 )
     {
        if ( clvBus < pabnObj->sclvDiscriminantes [ 0 ] )
        {
          pabnSig = pabnObj->spabnHijos [ 0 ]; 
        }
        else
        {
          lClave = 1; 
          iEnc = FALSE; 
          while ( ( lClave < pabnObj->lNumClaves ) && ( iEnc == FALSE ) )
          {
             if ( clvBus <= pabnObj->sclvDiscriminantes [ lClave ] )
             {
               pabnSig = pabnObj->spabnHijos [ lClave ];
               iEnc = TRUE;
             }
             lClave = lClave + 1;
          }

          if ( iEnc == FALSE )
          {
             pabnSig = pabnObj->pabnSigHermano;
          }
        }
     }
     else
     {
        iElem = ARB_B_ELEM_NULO;
     }
   }
   else
   {
     iElem = ARB_B_ELEM_NULO;
   }
   return ( iElem );
}


int SNodArBDesconectarAristaEntrada ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj )
{
	int	iRes;			
	int	iAristaDesc;
	int	iArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( p_nodgObj->iNumClaves > 0 ) && ES_VALIDO ( p_arigObj ) )
		{
			iArista = 0;
			iAristaDesc = -1;
			while ( ( iArista < p_nodgObj->iNumClaves ) && ( iAristaDesc < 0 ) )
			{
				if ( p_nodgObj->p_cDiscriminantes [ iArista ] == p_arigObj )
				{
					iAristaDesc = iArista;
				}
				iArista = iArista + 1;
			}

			if ( iAristaDesc >= 0 )
			{
				p_nodgObj->p_cDiscriminantes [ iAristaDesc ] = NULL;

				for ( iArista = iAristaDesc + 1; iArista < p_nodgObj->iNumClaves; iArista = iArista + 1 )
				{
					p_nodgObj->p_cDiscriminantes [ iArista - 1 ] = p_nodgObj->p_cDiscriminantes [ iArista ];
				}
				p_nodgObj->p_cDiscriminantes [ p_nodgObj->iNumClaves - 1 ] = NULL;
				p_nodgObj->iNumClaves = p_nodgObj->iNumClaves - 1;
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
	return ( iRes );
}

int SNodArBDesconectarAristaSalida ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj )
{
	int	iRes;			
	int	iAristaDesc;
	int	iArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		if ( ( p_nodgObj->iNumAristasSal > 0 ) && ES_VALIDO ( p_arigObj ) )
		{
			iArista = 0;
			iAristaDesc = -1;
			while ( ( iArista < p_nodgObj->iNumAristasSal ) && ( iAristaDesc < 0 ) )
			{
				if ( p_nodgObj->p_nodHijos [ iArista ] == p_arigObj )
				{
					iAristaDesc = iArista;
				}
				iArista = iArista + 1;
			}

			if ( iAristaDesc >= 0 )
			{
				p_nodgObj->p_cDiscriminantes [ iAristaDesc ] = NULL;

				for ( iArista = iAristaDesc + 1; iArista < p_nodgObj->iNumAristasSal; iArista = iArista + 1 )
				{
					p_nodgObj->p_nodHijos [ iArista - 1 ] = p_nodgObj->p_nodHijos [ iArista ];
				}
				p_nodgObj->p_nodHijos [ iNumAristasSal - 1 ] = NULL;
				p_nodgObj->iNumAristasSal = p_nodgObj->iNumAristasSal - 1;
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
	return ( iRes );
}

void SNodArBInicializarAristasSalida ( SNodoArbolB * p_nodgObj, SNodoArbolB * p_nodgObj )
{
	SAristaGrafo *	p_arigObj;
	SNodoArbolB *	p_nodgObj;
	int				iArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		for ( iArista = 0; iArista < p_nodgObj->iNumAristasSal; iArista = iArista + 1 )
		{
			p_arigObj = p_nodgObj->p_nodHijos [ iArista ];
			if ( ES_VALIDO ( p_arigObj ) )
			{
				if ( SAriGrfEstaRecorrida ( p_arigRes ) == 1 )
				{
					p_arigObj->DesmarcarComoRecorrida ();
					p_nodgObj = p_arigObj->NodoFinal ();
					if ( ES_VALIDO ( p_nodgObj ) )
					{
						SNodArBLimpiarAristasSalida ( p_nodgObj );
					}
				}
			}
		}
}

void SNodArBLimpiarAristasEntrada ( SNodoArbolB * p_nodgObj, SNodoArbolB * p_nodgObj )
{
	int	iArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		for ( iArista = 0; iArista < p_nodgObj->iNumClaves; iArista = iArista + 1 )
		{
			if ( ES_VALIDO ( p_cDiscriminantes [ iArista ] ) )
			{
				SAriGrfLimpiarNodoFinal ( p_nodgObj->p_cDiscriminantes [ iArista ] );
			}
			p_nodgObj->p_cDiscriminantes [ iArista ] = NULL;
		}
	}
}

void SNodArBLimpiarAristasSalida ( SNodoArbolB * p_nodgObj, int iLiberar )
{
	int	iArista;

	if ( ES_VALIDO ( p_nodgObj ) )
	{
		for ( iArista = 0; iArista < ip_nodgObj->NumAristasSal; iArista = iArista + 1 )
		{
			if ( iLiberar == 1 )
			{
				if ( ES_VALIDO ( p_nodHijos [ iArista ] ) )
				{
					SAriGrfLimpiarNodoInicial ( p_nodgObj->p_nodHijos [ iArista ] );
					SAriGrfLimpiarNodoFinal ( p_nodgObj->p_nodHijos [ iArista ], iLiberar );
					SAriGrfDestruir ( &(p_nodHijos [ iArista ]) );
				}
			}
			p_nodgObj->p_nodHijos [ iArista ] = NULL;
		}
	}
}

static SNodGfrInicializar ( SNodoArbolB * p_nodgObj )
{
	if ( ES_VALIDO ( p_nodgObj ) )
	{
		MemLiberar ( (void **) &(p_nodgObj->p_cDiscriminantes) );
		MemLiberar ( (void **) &(p_nodgObj->p_nodHijos) );
		p_nodgObj->p_cDiscriminantes = (SAristaGrafo *) MemReservarVector ( p_nodgObj->iMaxAristas, sizeof ( SAristaGrafo ) );
		p_nodgObj->p_nodHijos = (SAristaGrafo *) MemReservarVector ( p_nodgObj->iMaxAristas, sizeof ( SAristaGrafo ) );
		p_nodgObj->iNumClaves = 0;
		p_nodgObj->iNumAristasSal = 0;
		p_nodgObj->iId = -1;
		p_nodgObj->iDato = 0;
	}
}

*/