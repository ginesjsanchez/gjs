#include "SArbolConectivo.h"

#include "TiposDatosConfig.h"









SArbolConectivo * SArbEntlBinCrear () 
{
	SArbolConectivo * p_arbcObj;
	
	p_arbcObj = (SArbolConectivo *) MemReservar ( sizeof ( SArbolConectivo ) );
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		p_arbcObj->p_nodcRaiz = NULL;
		p_arbcObj->p_nodcActual = NULL;
	}
	return ( p_arbcObj );
}

void SArbCnctDestruir ( SArbolConectivo ** p_p_arbcObj )
{
	SArbolConectivo * p_arbcObj;
	
	if ( ES_VALIDO ( p_p_arbcObj ) )
	{
		p_arbcObj = *p_p_arbcObj;
		if ( ES_VALIDO ( p_arbcObj ) )
		{
			SArbCnctVaciar ( p_arbcObj );
			MemLiberar ( (void **) p_p_arbcObj );
		}
	}
}

SNodoConector * SArbCnctRaiz ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcRes;
	
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		p_nodcRes = p_arbcObj->p_nodcRaiz;
	}
	else
	{
		p_nodcRes = NULL;
	}
	return ( p_nodcRes );
}

int SArbCnctEstablecerRaiz ( SArbolConectivo * p_arbcObj, SNodoConector * p_nodcObj )
{
	int iRes;

	if ( SArbCnctEstaVacio ( p_arbcObj ) == 1 )
	{
		p_arbcObj->p_nodcRaiz = p_nodcObj;
		SNodCnctDesempadronar ( p_arbcObj->p_nodcRaiz );
		iRes = SNodCnctEsValido ( p_arbcObj->p_nodcRaiz );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SArbCnctEstaVacio ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( ES_NULO ( p_arbcObj->p_nodcRaiz ) )
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

int SArbCnctValorActual ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctValor ( p_arbcObj->p_nodcActual );
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

SNodoConector * SArbCnctActual ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcRes;
	
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			p_nodcRes = p_arbcObj->p_nodcActual;
		}
		else
		{
			p_nodcRes = NULL;
		}
	}
	else
	{
		p_nodcRes = NULL;
	}
	return ( p_nodcRes );
}

int SArbCnctActualTieneDatos ( SArbolConectivo * p_arbcObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) == -1 ) && ES_VALIDO ( SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) ) || 
				 ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) == -1 ) && ES_VALIDO ( SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) ) )
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

int SArbCnctTieneDatosIzq ( SArbolConectivo * p_arbcObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) == -1 ) && ( ES_VALIDO ( SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) ) )
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

int SArbCnctTieneDatosDer ( SArbolConectivo * p_arbcObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) == -1 ) && ES_VALIDO ( SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) )
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

void * SArbCnctActualDatosIzq ( SArbolConectivo * p_arbcObj )
{
	void * p_vRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) == -1 ) && ( ES_VALIDO ( SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) ) )
			{
				p_vRes = SNodCnctHijoIzq ( p_arbcObj->p_nodcActual );
			}
			else 
			{
				p_vRes = NULL;
			}
		}
		else 
		{
			p_vRes = NULL;
		}
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

void * SArbCnctActualDatosDer( SArbolConectivo * p_arbcObj )
{
	void * p_vRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) == -1 ) && ( ES_VALIDO ( SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) ) )
			{
				p_vRes = SNodCnctHijoDer ( p_arbcObj->p_nodcActual );
			}
			else 
			{
				p_vRes = NULL;
			}
		}
		else 
		{
			p_vRes = NULL;
		}
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

SNodoConector * SArbCnctHijoDer ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				p_nodcRes = (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual );
			}
			else 
			{
				p_nodcRes = NULL;
			}
		}
		else 
		{
			p_nodcRes = NULL;
		}
	}
	else
	{
		p_nodcRes = NULL;
	}
	return ( p_nodcRes );
}

SNodoConector * SArbCnctHijoIzq ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				p_nodcRes = (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual );
			}
			else 
			{
				p_nodcRes = NULL;
			}
		}
		else 
		{
			p_nodcRes = NULL;
		}
	}
	else
	{
		p_nodcRes = NULL;
	}
	return ( p_nodcRes );
}

SNodoConector * SArbCnctPadre ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * 	p_nodcRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			p_nodcRes = (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual );   
		}
		else
		{
			p_nodcRes = NULL;
		}
	}
	else
	{
		p_nodcRes = NULL;
	}
	return ( p_nodcRes );
}

int SArbCnctValorPadrel ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctValor( (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual ) );
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

int SArbCnctValorHijoDer ( SArbolConectivo * p_arbcObj )
{
	int 				iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) );   
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

int SArbCnctValorHijoIzq ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) );   
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

int SArbCnctHijoDerEsConector ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) >= 0 )
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

int SArbCnctHijoIzqEsConector ( SArbolConectivo * p_arbcObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 )
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

void SArbCnctVaciar ( SArbolConectivo * p_arbcObj )
{
	return ( SArbCnctVaciarExt ( p_arbcObj, NULL ) );
}

void SArbCnctVaciarExt ( SArbolConectivo * p_arbcObj, PPRCPPV fDestruccion )
{
	void *			p_vDatos;
	SNodoConector * p_nodcObj;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( ES_VALIDO ( p_arbcObj->p_nodcRaiz ) )
		{
			SArbCnctMoverAPrimPreorden ( p_arbcObj );
			while ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
			{
				if ( ES_VALIDO ( fDestruccion ) )
				{
					if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) == -1 )
					{
						p_vDatos = SNodCnctHijoIzq ( p_arbcObj->p_nodcActual );
						fDestruccion ( &p_vDatos );
					}
					if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) == -1 )
					{
						p_vDatos = SNodCnctHijoDer ( p_arbcObj->p_nodcActual );
						fDestruccion ( &p_vDatos );
					}
				}
				p_nodcObj = p_arbcObj->p_nodcActual;
				SArbCnctMoverASigPreorden ( p_arbcObj );
				SNodCnctDestruir ( &p_nodcObj );
			}
			SNodCnctDestruir ( &(p_arbcObj->p_nodcRaiz) );
		}
	}
}

int SArbCnctTienePadre ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctTienePadre ( p_arbcObj->p_nodcActual );
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

int SArbCnctTieneHijos ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctTieneHijos ( p_arbcObj->p_nodcActual );
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

int SArbCnctTieneHijoIzq ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctTieneHijoIzq ( p_arbcObj->p_nodcActual );
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

int SArbCnctTieneHijoDer ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			iRes = SNodCnctTieneHijoDer ( p_arbcObj->p_nodcActual );
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

int SArbCnctEstaEnRaiz ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( p_arbcObj->p_nodcActual == p_arbcObj->p_nodcRaiz )
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

void SArbCnctMoverARaiz ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( ES_VALIDO ( p_arbcObj->p_nodcRaiz ) )
		{
			p_arbcObj->p_nodcActual = p_arbcObj->p_nodcRaiz;
		}
	}
}

void SArbCnctMoverAPadre ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SArbCnctEstaEnRaiz ( p_arbcObj ) != 1 )
			{
				p_arbcObj->p_nodcActual = (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual );
			}
			else
			{
				SArbCnctDesposicionar ( p_arbcObj );
			}
		}
	}
}

void SArbCnctMoverAHijoIzq ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				p_arbcObj->p_nodcActual = (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual );
			}
			else
			{
				SArbCnctDesposicionar ( p_arbcObj );
			}
		}
	}
}

void SArbCnctMoverAHijoDer ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				p_arbcObj->p_nodcActual = (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual );
			}
			else
			{
				SArbCnctDesposicionar ( p_arbcObj );
			}
		}
	}
}

void SArbCnctMoverAHermano ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcPadre;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SArbCnctEstaEnRaiz ( p_arbcObj ) != 1 )
			{
				p_nodcPadre = (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual );
				if ( ES_VALIDO ( p_nodcPadre ) )
				{
					if ( SNodCnctEsHijoIzq ( p_nodcPadre, (void *) p_arbcObj->p_nodcActual ) == 1 )
					{
						SArbCnctMoverAHijoDer ( p_arbcObj );
					}
					else
					{
						SArbCnctMoverAHijoIzq ( p_arbcObj );
					}
				}
				else
				{
					SArbCnctDesposicionar ( p_arbcObj );
				}
			}
			else
			{
				SArbCnctDesposicionar ( p_arbcObj );
			}
		}
	}
}

void SArbCnctMoverAPrimPreorden ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		SArbCnctMoverARaiz ( p_arbcObj );
		while ( ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 ) && ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 ) )
		{
			SArbCnctMoverAHijoIzq ( p_arbcObj );
		}
	}
}

void SArbCnctMoverASigPreorden ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcPadre;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			p_nodcPadre = (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual );
			if ( ES_VALIDO ( p_nodcPadre ) )
			{
				if ( SNodCnctEsHijoIzq ( p_nodcPadre, (void *) p_arbcObj->p_nodcActual ) == 1 )
				{
					if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_nodcPadre ) ) >= 0 )
					{
						SArbCnctMoverAHermano ( p_arbcObj );
						while ( ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 ) && ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 ) )
						{
							SArbCnctMoverAHijoIzq ( p_arbcObj );
						}
					}
					else
					{
						p_arbcObj->p_nodcActual = p_nodcPadre;
					}
				}
				else
				{
					p_arbcObj->p_nodcActual = p_nodcPadre;
				}
			}
			else
			{
				SArbCnctDesposicionar ( p_arbcObj );
			}
		}
	}
}

void SArbCnctMoverAAntPreorden ( SArbolConectivo * p_arbcObj )
{
	SNodoConector * p_nodcPadre;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
		{
			if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoDer ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				SArbCnctMoverAHijoDer ( p_arbcObj );
			}
			else if ( SNodCnctValor ( (SNodoConector *) SNodCnctHijoIzq ( p_arbcObj->p_nodcActual ) ) >= 0 )
			{
				SArbCnctMoverAHijoIzq ( p_arbcObj );
			}
			else
			{
				p_nodcPadre = (SNodoConector *) SNodCnctPadre ( p_arbcObj->p_nodcActual );
				if ( ES_VALIDO ( p_nodcPadre ) )
				{
					if ( SNodCnctEsHijoDer ( p_nodcPadre, (void *) p_arbcObj->p_nodcActual ) == 1 )
					{
						SArbCnctMoverAHermano ( p_arbcObj );
					}
					else
					{
						SArbCnctDesposicionar ( p_arbcObj );
					}
				}
				else
				{
					SArbCnctDesposicionar ( p_arbcObj );
				}
			}
		}
	}
}

void SArbCnctMoverAUltPreorden ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		SArbCnctMoverARaiz ( p_arbcObj );
	}
}

void SArbCnctDesposicionar ( SArbolConectivo * p_arbcObj )
{
	if ( ES_VALIDO ( p_arbcObj ) )
	{
		p_arbcObj->p_nodcActual = NULL;
	}
}

int	SArbCnctEstaPosicionado ( SArbolConectivo * p_arbcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 )
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

int SArbCnctEnraizar ( SArbolConectivo * p_arbcObj, SNodoConector * p_nodcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) )
	{
		if ( ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 ) && ( SNodCnctEsValido ( p_nodcObj ) == 1 ) )
		{
			if ( SNodCnctTieneHijoDer ( p_arbcObj->p_nodcActual ) == 1 )
			{
				iRes = 0;
			}
			else
			{
				SNodCnctEmpadronar ( p_nodcObj, (void *) p_arbcObj->p_nodcActual, SNodCnctValor ( p_arbcObj->p_nodcActual ) );
				if ( SNodCnctTieneHijoIzq ( p_arbcObj->p_nodcActual ) == 0 )
				{
					if ( SNodCnctEstHijoIzq ( p_arbcObj->p_nodcActual, p_nodcObj, SNodCnctValor ( p_nodcObj ) ) == 1 )
					{
						iRes = 1;
						SArbCnctMoverAHijoIzq ( p_arbcObj );
					}
					else
					{
						iRes = 0;
					}
				}
				else
				{
					if ( SNodCnctEstHijoDer ( p_arbcObj->p_nodcActual, p_nodcObj, SNodCnctValor ( p_nodcObj ) ) == 1 )
					{
						iRes = 1;
						SArbCnctMoverAHijoDer ( p_arbcObj );
					}
					else
					{
						iRes = 0;
					}
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

int SArbCnctEnraizarDatos ( SArbolConectivo * p_arbcObj, void * p_vDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_arbcObj ) && ES_VALIDO ( p_vDatos ) )
	{
		if ( SNodCnctEsValido ( p_arbcObj->p_nodcActual ) == 1 ) 
		{
			if ( SNodCnctTieneHijoDer ( p_arbcObj->p_nodcActual ) == 1 )
			{
				iRes = 0;
			}
			else
			{
				if ( SNodCnctTieneHijoIzq ( p_arbcObj->p_nodcActual ) == 0 )
				{
					if ( SNodCnctEstHijoIzq ( p_arbcObj->p_nodcActual, p_vDatos, -1 ) == 1 )
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
					if ( SNodCnctEstHijoDer ( p_arbcObj->p_nodcActual, p_vDatos, -1 ) == 1 )
					{
						iRes = 1;
					}
					else
					{
						iRes = 0;
					}
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


