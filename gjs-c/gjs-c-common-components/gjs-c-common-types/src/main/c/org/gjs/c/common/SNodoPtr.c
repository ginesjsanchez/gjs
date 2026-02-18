
#include "SNodoPtr.h"


#include "TiposBasicosConfig.h"





static void SNodPtrIncializar ( SNodoPtr * p_nodpObj, byte * p_byDirDatos, int iLiberar );



SNodoPtr * SNodPtrCrearMem ( int iTamDatos )
{
	SNodoPtr * p_nodObj;

	if ( iTamDatos > 0 )
	{
		p_nodObj = SNodPtrCrear( (byte *) MemReservar ( iTamDatos ), 1 );
	}
	else
	{
		p_nodObj = NULL;
	}
	return ( p_nodObj );
}

SNodoPtr * SNodPtrCrear ( byte * p_byDatos, int iLiberar )
{
	SNodoPtr * p_nodpObj;

	if ( ES_VALIDO ( p_byDatos ) )
	{
		p_nodpObj= (SNodoPtr *) MemReservar ( sizeof ( SNodoPtr ) );
		if ( ES_VALIDO ( p_nodpObj ) )
		{
		    SNodPtrIncializar ( p_nodpObj, p_byDatos, iLiberar );
		}
	}
	else
	{
		p_nodpObj = NULL;
	}
	return ( p_nodpObj );
}

void SNodPtrDestruir ( SNodoPtr ** p_p_nodpObj, int iDestruirHijos )
{
    SNodoPtr *      p_nodpObj;

    if ( ES_VALIDO ( p_p_nodpObj ) )
    {
        p_nodpObj = *p_p_nodpObj;
		if ( ES_VALIDO ( p_nodpObj ) )
		{
			SNodPtrLimpiarHijos ( p_nodpObj, iDestruirHijos );
			if ( p_nodpObj->iLiberar == 1 )
			{
				MemLiberar ( (void **) &(p_nodpObj->p_byDatos) );
			}
			MemLiberar ( (void **) p_p_nodpObj );
		}
    }
}

int SNodPtrEsValido ( SNodoPtr * p_nodpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodpObj ) )
	{
		if ( ES_VALIDO ( p_nodpObj->p_byDatos ) )
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

int SNodPtrTieneDatos ( SNodoPtr * p_nodpObj )
{
	int iRes;

	if ( SNodPtrEsValido ( p_nodpObj ) )
	{
		if ( ES_VALIDO ( p_nodpObj->p_byDatos ) )
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

byte * SNodPtrDatos ( SNodoPtr * p_nodpObj )
{
	byte * p_byRes;

	if ( ES_VALIDO ( p_nodpObj ) )
	{
		p_byRes = p_nodpObj->p_byDatos;
	}
	else
	{
		p_byRes = NULL;
	}
	return ( p_byRes );
}

int SNodPtrModificar ( SNodoPtr * p_nodpObj, byte * p_byDatos, int iLiberar )
{
	int iRes;

	if ( ES_VALIDO ( p_nodpObj ) && ES_VALIDO ( p_byDatos ) && BOOL_VALIDO ( iLiberar ) )
	{
		if ( p_nodpObj->iLiberar == 1 )
		{
			MemLiberar ( (void **) &(p_nodpObj->p_byDatos) );
		}
		p_nodpObj->p_byDatos = p_byDatos;
		if ( ES_VALIDO ( p_nodpObj->p_byDatos ) )
		{
			iRes = 1;
			p_nodpObj->iLiberar = iLiberar;
		}
		else
		{
			iRes = 0;
			p_nodpObj->iLiberar = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodPtrNumHijos ( SNodoPtr * p_nodpObj )
{
    int iRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
        iRes = p_nodpObj->iNumHijos;
    }
    else
    {
        iRes = 0;
    }
	return ( iRes );
}

SNodoPtr * SNodPtrPadre ( SNodoPtr * p_nodpObj )
{
    SNodoPtr * p_nodRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
        p_nodRes = (SNodoPtr *) p_nodpObj->p_nodpPadre;
    }
    else
    {
        p_nodRes = NULL;
    }
	return ( p_nodRes );
}

SNodoPtr * SNodPtrHijo ( SNodoPtr * p_nodpObj, int iHijo )
{
	SNodoPtr *	p_nodpHijo;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
     	if ( ( iHijo >= 0 ) && ( iHijo < p_nodpObj->iNumHijos ) )
     	{
			p_nodpHijo = (SNodoPtr *) p_nodpObj->p_p_nodpHijos [ iHijo ];
     	}
     	else
     	{
     		p_nodpHijo = NULL;
     	}
	}
	else
	{
		p_nodpHijo = NULL;
	}
	return ( p_nodpHijo );
}

int SNodPtrTienePadre ( SNodoPtr * p_nodpObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
     	if ( ES_VALIDO ( p_nodpObj->p_nodpPadre ) )
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

int SNodPtrTieneHijos ( SNodoPtr * p_nodpObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
     	if ( p_nodpObj->iNumHijos > 0 )
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

int SNodPtrTieneHermanos ( SNodoPtr * p_nodpObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
     	if ( ES_VALIDO ( p_nodpObj->p_nodpPadre ) )
     	{
     		if ( SNodPtrNumHijos ( (SNodoPtr *) p_nodpObj->p_nodpPadre ) > 1 )
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

int SNodPtrTieneHermanosIzq ( SNodoPtr * p_nodpObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodpObj ) )
    {
     	if ( ES_VALIDO ( p_nodpObj->p_nodpPadre ) )
     	{
     		if ( SNodPtrOrdenDelHijo ( (SNodoPtr *) p_nodpObj->p_nodpPadre, p_nodpObj ) > 0 )
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

int SNodPtrTieneHermanosDer ( SNodoPtr * p_nodpObj )
{
	int iOrden;
	int iRes;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	if ( ES_VALIDO ( p_nodpObj->p_nodpPadre ) )
     	{
     		iOrden = SNodPtrOrdenDelHijo ( (SNodoPtr *) p_nodpObj->p_nodpPadre, p_nodpObj );
     		if ( ( iOrden >= 0 ) && ( iOrden < SNodPtrNumHijos ( (SNodoPtr *) p_nodpObj->p_nodpPadre ) - 1 ) )
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

int SNodPtrNodosInferiores ( SNodoPtr * p_nodpObj )
{
	SNodoPtr *	p_nodpHijo;
	int		iHijo;
	int		iNodos;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	iNodos = 0;
     	for ( iHijo = 0; iHijo < p_nodpObj->iNumHijos; iHijo = iHijo + 1 )
     	{
     		p_nodpHijo = SNodPtrHijo ( p_nodpObj, iHijo );
     		if ( ES_VALIDO ( p_nodpHijo  ) )
     		{
     			iNodos = iNodos + 1 + SNodPtrNodosInferiores ( p_nodpHijo );
     		}
     	}
     }
     else
     {
          iNodos = 0;
     }
	return ( iNodos );
}

int SNodPtrNivelesInferiores ( SNodoPtr * p_nodpObj )
{
	SNodoPtr *	p_nodpHijo;
	int		iHijo;
	int		iNiveles;
	int		iNivelesMax;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	iNivelesMax = 0;
     	for ( iHijo = 0; iHijo < p_nodpObj->iNumHijos; iHijo = iHijo + 1 )
     	{
     		p_nodpHijo = SNodPtrHijo ( p_nodpObj, iHijo );
     		if ( ES_VALIDO ( p_nodpHijo ) )
     		{
     			iNiveles = SNodPtrNivelesInferiores ( p_nodpHijo );
     			if ( iNiveles > iNivelesMax )
     			{
     				iNivelesMax = iNiveles;
     			}
     		}
     	}
     }
     else
     {
          iNivelesMax = 0;
     }
	return ( iNivelesMax );
}

int SNodPtrProfundidad ( SNodoPtr * p_nodpObj )
{
	int	iProfundidad;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	if ( ES_NULO ( p_nodpObj->p_nodpPadre ) )
     	{
     		iProfundidad = 0;
     	}
     	else
     	{
     		iProfundidad = SNodPtrProfundidad ( (SNodoPtr *) p_nodpObj->p_nodpPadre ) + 1;
     	}
     }
     else
     {
          iProfundidad = 0;
     }
	return ( iProfundidad );
}

int SNodPtrEmpadronar ( SNodoPtr * p_nodpObj, SNodoPtr * p_nodpPadre )
{
	int iRes;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	p_nodpObj->p_nodpPadre = p_nodpPadre;
     	if ( ES_VALIDO ( p_nodpObj->p_nodpPadre ) )
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

int SNodPtrInsertarHijo ( SNodoPtr * p_nodpObj, SNodoPtr * p_nodpHijo )
{
	int	iRes;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	if ( ( p_nodpObj->iNumHijos < ARB_MAX_HIJOS_NODO ) && ES_VALIDO ( p_nodpHijo ) )
     	{
			if ( MemRedimensionar ( (void **) &(p_nodpObj->p_p_nodpHijos), sizeof ( SNodoPtr * ) * ( p_nodpObj->iNumHijos + 1 ) ) == 1 )
			{
  				p_nodpObj->iNumHijos = p_nodpObj->iNumHijos + 1;
  				p_nodpObj->p_p_nodpHijos [ p_nodpObj->iNumHijos - 1 ] = p_nodpHijo;
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

void SNodPtrDesempadronar ( SNodoPtr * p_nodpObj )
{
     if ( ES_VALIDO ( p_nodpObj ) )
     {
          p_nodpObj->p_nodpPadre = NULL;
     }
}

int SNodPtrEliminarHijo ( SNodoPtr * p_nodpObj, int iHijo, int iLiberar )
{
	int	iHijoAux;
	int	iRes;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	if ( ( iHijo >= 0 ) && ( iHijo < p_nodpObj->iNumHijos ) )
     	{
			if ( iLiberar == 1 )
			{
				if ( ES_VALIDO ( p_nodpObj->p_p_nodpHijos [ iHijo ] ) )
				{
					SNodPtrDestruir ( (SNodoPtr **) &(p_nodpObj->p_p_nodpHijos [ iHijo ]), 1 );
				}
			}

			for ( iHijoAux = iHijo + 1; iHijoAux < ARB_TAM_BLOQUE_HIJOS_NODO - 1; iHijoAux = iHijoAux + 1 )
			{
				p_nodpObj->p_p_nodpHijos [ iHijoAux - 1 ] = p_nodpObj->p_p_nodpHijos [ iHijoAux ];
			}
			p_nodpObj->iNumHijos = p_nodpObj->iNumHijos - 1;
			iRes = MemRedimensionar ( (void **) &(p_nodpObj->p_p_nodpHijos), sizeof ( SNodoPtr * ) * ( p_nodpObj->iNumHijos ) );
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

int SNodPtrEstablecerHijo ( SNodoPtr * p_nodpObj, int iHijo, SNodoPtr * p_nodpHijo, int iLiberar  )
{
	int		iRes;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	if ( ( iHijo >= 0 ) && ( iHijo < p_nodpObj->iNumHijos ) && ES_VALIDO ( p_nodpHijo ) )
     	{
			if ( iLiberar == 1 )
			{
				if ( ES_VALIDO ( p_nodpObj->p_p_nodpHijos [ iHijo ] ) )
				{
					SNodPtrDestruir ( (SNodoPtr **) &(p_nodpObj->p_p_nodpHijos [ iHijo ]), 1 );
				}
			}
			p_nodpObj->p_p_nodpHijos [ iHijo ] = p_nodpHijo;
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

void SNodPtrLimpiarHijos ( SNodoPtr * p_nodpObj, int iLiberar )
{
	int	iHijo;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
		for ( iHijo = 0; iHijo < p_nodpObj->iNumHijos;  iHijo = iHijo + 1 )
		{
			if ( iLiberar == 1 )
			{
				if ( ES_VALIDO ( p_nodpObj->p_p_nodpHijos [ iHijo ] ) )
				{
					SNodPtrDestruir ( (SNodoPtr **) &(p_nodpObj->p_p_nodpHijos [ iHijo ]), 1 );
				}
			}
			p_nodpObj->p_p_nodpHijos [ iHijo ] = NULL;
		}
		MemLiberar ( (void **) &(p_nodpObj->p_p_nodpHijos) );
     }
}

int	SNodPtrEsHijo ( SNodoPtr * p_nodpObj )
{
	SNodoPtr *	p_nodpHijo;
	int			iHijo;
	int			iEnc;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	iEnc = 0;
     	iHijo = 0;
     	while ( ( iHijo < p_nodpObj->iNumHijos ) && ( iEnc == 0 ) )
     	{
     		p_nodpHijo = SNodPtrHijo ( p_nodpObj, iHijo );
     		if ( p_nodpHijo == p_nodpObj )
     		{
     			iEnc = 1;
     		}
     		else
     		{
     			iHijo = iHijo + 1;
     		}
     	}
     }
     else
     {
          iEnc = 0;
     }
	return ( iEnc );
}

int SNodPtrOrdenDelHijo ( SNodoPtr * p_nodpObj, SNodoPtr *  p_nodpHijo )
{
	SNodoPtr *  p_nodpAux;
	int			iHijo;
	int			iEnc;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	iEnc = 0;
     	iHijo = 0;
     	while ( ( iHijo < p_nodpObj->iNumHijos ) && ( iEnc == 0 ) )
     	{
     		p_nodpAux = SNodPtrHijo ( p_nodpObj, iHijo );
     		if ( p_nodpHijo == p_nodpAux )
     		{
     			iEnc = 1;
     		}
     		else
     		{
     			iHijo = iHijo + 1;
     		}
     	}

     	if ( iEnc == 0 )
     	{
     		iHijo = -1;
     	}
     }
     else
     {
          iHijo = -1;
     }
	return ( iHijo );
}

int SNodPtrVerificar ( SNodoPtr * p_nodpObj, int iCorregir )
{
	int			iRes;
	SNodoPtr *  p_nodpHijo;
	int			iHijo;

     if ( ES_VALIDO ( p_nodpObj ) )
     {
     	iRes = 1;
     	for ( iHijo = 0; iHijo < p_nodpObj->iNumHijos; iHijo = iHijo + 1 )
     	{
     		p_nodpHijo = SNodPtrHijo ( p_nodpObj, iHijo );
     		if ( SNodPtrPadre ( p_nodpHijo ) != p_nodpObj )
     		{
     			if ( iCorregir == 1 )
     			{
     				SNodPtrEmpadronar ( p_nodpHijo, p_nodpObj );
     			}
     			iRes = 0;
     		}
     		if ( SNodPtrVerificar ( p_nodpHijo, iCorregir ) == 0 )
     		{
     			iRes = 0;
     		}
     	}
     }
     else
     {
          iRes = 0;
     }
	return ( iRes );
}

int	SNodPtrLiberacionMemoriaActivada ( SNodoPtr * p_nodpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodpObj ) )
	{
		iRes = p_nodpObj->iLiberar;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

static void SNodPtrIncializar ( SNodoPtr * p_nodpObj, byte * p_byDirDatos, int iLiberar )
{
    if ( ES_VALIDO ( p_nodpObj ) )
    {
   		p_nodpObj->p_p_nodpHijos = NULL;
     	p_nodpObj->p_nodpPadre = NULL;
     	p_nodpObj->iNumHijos = 0;
 		p_nodpObj->p_byDatos = p_byDirDatos;
		if ( ES_VALIDO ( p_nodpObj->p_byDatos ) )
		{
			p_nodpObj->iLiberar = iLiberar;
		}
		else
		{
			p_nodpObj->iLiberar = 0;
		}
	}
}



