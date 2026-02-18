
#include "SNodoConector.h"

#include "TiposDatosConfig.h"






static void SNodCnctIncializar ( SNodoConector * p_nodcObj, int iValor );



SNodoConector * SNodCnctCrearDef ()
{
    return ( SNodCnctCrear ( 0 ) );
}

SNodoConector * SNodCnctCrear ( int iValor ) 
{
	SNodoConector * p_nodcObj;
	
	p_nodcObj = (SNodoConector *) MemReservar ( sizeof ( SNodoConector ) );
	if ( p_nodcObj != NULL )
	{
		SNodCnctIncializar ( p_nodcObj, iValor );
	}
	return ( p_nodcObj );
}

void SNodCnctDestruir ( SNodoConector ** p_p_nodcObj )
{
    SNodoConector *   p_nodcObj;
    
    if ( ES_VALIDO ( p_p_nodcObj ) )
    {
        p_nodcObj = *p_p_nodcObj;
 		if ( ES_VALIDO ( p_nodcObj ) )
		{
			MemLiberar ( (void **) p_p_nodcObj );
		}
    }    
}

int SNodCnctEsValido ( SNodoConector * p_nodcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodcObj ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctValor ( SNodoConector * p_nodcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_nodcObj ) )
	{
		iRes = p_nodcObj->iValor;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctEstablecerValor ( SNodoConector * p_nodcObj, int iValor )
{
	int iRes;

	if ( ES_VALIDO ( p_nodcObj ) )
	{
		p_nodcObj->iValor = iValor;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void * SNodCnctPadre ( SNodoConector * p_nodcObj )
{
     void * p_vRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_vRes = SCnctObjeto ( p_nodcObj->p_cnctPadre );
     }
     else
     {
          p_vRes = NULL;
     }
	return ( p_vRes );
}

void * SNodCnctHijoIzq ( SNodoConector * p_nodcObj )
{
     void * p_vRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_vRes = SCnctObjeto ( p_nodcObj->p_cnctHijoIzq );
     }
     else
     {
          p_vRes = NULL;
     }
	return ( p_vRes );
}

SConector * SNodCnctConectorPadre ( SNodoConector * p_nodcObj )
{
     SConector * p_cnctRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_cnctRes = p_nodcObj->p_cnctPadre;
     }
     else
     {
          p_cnctRes = NULL;
     }
	return (p_cnctRes );
}

SConector * SNodCnctConectorHijoDer ( SNodoConector * p_nodcObj )
{
     SConector * p_cnctRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_cnctRes = p_nodcObj->p_cnctHijoDer;
     }
     else
     {
          p_cnctRes = NULL;
     }
	return (p_cnctRes );
}

SConector * SNodCnctConectorHijoIzq ( SNodoConector * p_nodcObj )
{
     SConector * p_cnctRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_cnctRes = p_nodcObj->p_cnctHijoIzq;
     }
     else
     {
          p_cnctRes = NULL;
     }
	return (p_cnctRes );
}

void * SNodCnctHijoDer ( SNodoConector * p_nodcObj )
{
     void * p_vRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
          p_vRes = SCnctObjeto ( p_nodcObj->p_cnctHijoDer );
     }
     else
     {
          p_vRes = NULL;
     }
	return ( p_vRes );
}

int SNodCnctTipoPadre ( SNodoConector * p_nodcObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodcObj ) )
    {
   		iRes = SCnctTipo ( p_nodcObj->p_cnctPadre );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctTipoHijoIzq ( SNodoConector * p_nodcObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodcObj ) )
    {
   		iRes = SCnctTipo ( p_nodcObj->p_cnctHijoIzq );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctTipoHijoDer ( SNodoConector * p_nodcObj )
{
	int iRes;

    if ( ES_VALIDO ( p_nodcObj ) )
    {
   		iRes = SCnctTipo ( p_nodcObj->p_cnctHijoDer );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctTienePadre ( SNodoConector * p_nodcObj )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( SCnctEsValido ( p_nodcObj->p_cnctPadre ) == 1 )
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

int SNodCnctTieneHijos ( SNodoConector * p_nodcObj )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( ( SCnctEsValido ( p_nodcObj->p_cnctHijoIzq ) == 1 ) || ( SCnctEsValido ( p_nodcObj->p_cnctHijoDer ) == 1 ) )
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

int SNodCnctTieneHijoIzq ( SNodoConector * p_nodcObj )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( SCnctEsValido ( p_nodcObj->p_cnctHijoIzq ) == 1 )
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

int SNodCnctTieneHijoDer ( SNodoConector * p_nodcObj )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( SCnctEsValido ( p_nodcObj->p_cnctHijoDer ) == 1 )
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

int SNodCnctEmpadronar ( SNodoConector * p_nodcObj, void * p_vPadre, int iTipo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
		if ( ES_VALIDO ( p_nodcObj->p_cnctPadre ) )
		{
			SCnctEstablecer ( p_nodcObj->p_cnctPadre, p_vPadre, iTipo );
		}
		else
		{
			p_nodcObj->p_cnctPadre = SCnctCrearExt ( p_vPadre, iTipo );
		}
   		iRes = SCnctEsValido ( p_nodcObj->p_cnctPadre );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SNodCnctDesempadronar ( SNodoConector * p_nodcObj )
{
     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	 SCnctLimpiar ( p_nodcObj->p_cnctPadre );
     }
}

void SNodCnctLimpiarHijoIzq ( SNodoConector * p_nodcObj )
{
     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	 SCnctLimpiar ( p_nodcObj->p_cnctHijoIzq );
     }
}

void SNodCnctEliminarHijoDer ( SNodoConector * p_nodcObj )
{
     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	 SCnctLimpiar ( p_nodcObj->p_cnctHijoDer );
     }
}

int SNodCnctEstHijoIzq ( SNodoConector * p_nodcObj, void * p_vHijo, int iTipo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
		if ( ES_VALIDO ( p_nodcObj->p_cnctHijoIzq ) )
		{
			SCnctEstablecer ( p_nodcObj->p_cnctHijoIzq, p_vHijo, iTipo );
		}
		else
		{
			p_nodcObj->p_cnctHijoIzq = SCnctCrearExt ( p_vHijo, iTipo );
		}
   		iRes = SCnctEsValido ( p_nodcObj->p_cnctHijoIzq );
   	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctEstHijoDer ( SNodoConector * p_nodcObj, void * p_vHijo, int iTipo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
		if ( ES_VALIDO ( p_nodcObj->p_cnctHijoDer ) )
		{
			SCnctEstablecer ( p_nodcObj->p_cnctHijoDer, p_vHijo, iTipo );
		}
		else
		{
			p_nodcObj->p_cnctHijoDer = SCnctCrearExt ( p_vHijo, iTipo );
		}
   		iRes = SCnctEsValido ( p_nodcObj->p_cnctHijoDer );
   	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SNodCnctIntercambiarHijos ( SNodoConector * p_nodcObj )
{
	SConector * p_conctAux;
	int 		iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
		p_conctAux = p_nodcObj->p_cnctHijoDer;
		p_nodcObj->p_cnctHijoDer = p_nodcObj->p_cnctHijoIzq;
		p_nodcObj->p_cnctHijoIzq = p_conctAux;
   		iRes = 1;
   	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void SNodCnctLimpiarHijos ( SNodoConector * p_nodcObj )
{
     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	SCnctLimpiar ( p_nodcObj->p_cnctHijoIzq );
      	SCnctLimpiar ( p_nodcObj->p_cnctHijoDer );
     }
}

int	SNodCnctEsHijo ( SNodoConector * p_nodcObj, void * p_vHijo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( ( SCnctObjeto ( p_nodcObj->p_cnctHijoIzq ) == p_vHijo ) ||
     		 ( SCnctObjeto ( p_nodcObj->p_cnctHijoDer ) == p_vHijo ) )
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

int	SNodCnctEsHijoIzq ( SNodoConector * p_nodcObj, void * p_vHijo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( SCnctObjeto ( p_nodcObj->p_cnctHijoIzq ) == p_vHijo ) 
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

int	SNodCnctEsHijoDer ( SNodoConector * p_nodcObj, void * p_vHijo )
{
	int iRes;

     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	if ( SCnctObjeto ( p_nodcObj->p_cnctHijoDer ) == p_vHijo ) 
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

static void SNodCnctIncializar ( SNodoConector * p_nodcObj, int iValor )
{
     if ( ES_VALIDO ( p_nodcObj ) )
     {
     	p_nodcObj->p_cnctPadre = NULL;
     	p_nodcObj->p_cnctHijoIzq = NULL;
     	p_nodcObj->p_cnctHijoDer = NULL;
		p_nodcObj->iValor = iValor;
    }
}

