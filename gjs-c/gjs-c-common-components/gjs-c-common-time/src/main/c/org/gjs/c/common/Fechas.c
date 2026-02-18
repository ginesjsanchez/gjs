
#include "Fechas.h"
#include "Calendario.h"
#include "TiempoConfig.h"




long FecFormConstruir ( int iA, int iM, int iD )
{
	long lRes;

	if ( FecEsValida ( iA, iM, iD ) == 1 )
	{
		lRes = iA * 10000 + iM * 100 + iD;
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

int FecEsValida ( int iA, int iM, int iD )
{
	int iRes;

	if ( ( iA != 0 ) && ( iM >= 1 ) && ( iM <= 12 ) &&
		 ( iD >= 1 ) && ( iD <= CalendDiasMes ( iA, iD ) ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int FecFormEsValida ( long lFecha )
{
	int	iRes;
	int iA = 0;
	int iM = 0;
	int iD = 0;

	FecFormDescomponer ( lFecha, &iA, &iM, &iD );
	iRes = FecEsValida ( iA, iM, iD );
	return ( iRes );
}

void FecFormDescomponer ( long lFecha, int * p_iA, int * p_iM, int * p_iD )
{
	long lAux;

	if ( ( lFecha >= 0 ) && ( lFecha < 240000 ) && 
		 ES_VALIDO ( p_iA ) && ES_VALIDO ( p_iM ) && ES_VALIDO ( p_iD ) )
	{
		*p_iA = lFecha / 10000;
		lAux = lFecha % 10000;
		*p_iM = lAux / 100;
		*p_iD = lAux % 100;
	} 
}

int FecFormAnos ( long lFecha )
{
 	return ( lFecha / 10000 );
}

int FecFormMeses ( long lFecha )
{
 	return ( ( lFecha % 10000 ) / 100 );
}

int FecFormDias ( long lFecha )
{
 	return ( lFecha % 100 );
}

int FecNumDiasAnualesHasta ( int iA, int iM, int iD ) 
{
	int iRes;

	if ( FecEsValida ( iA, iM, iD ) == 1 )
	{
		iRes = CalendDiasAnualesHastaElMes ( iA, iM ) + iD;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int FecNumDiasAnualesDesde ( int iA, int iM, int iD ) 
{
	int iRes;

	if ( FecEsValida ( iA, iM, iD ) == 1 )
	{
		iRes = CalendDiasAnualesDesdeElMes ( iA, iM ) +  CalendDiasMes ( iA, iM ) - iD;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int FecFormNumDiasAnualesHasta ( long lFecha )
{
	int iRes;
	int iA = 0;
	int iM = 0;
	int iD = 0;

	FecFormDescomponer ( lFecha, &iA, &iM, &iD );
	iRes = FecNumDiasAnualesHasta ( iA, iM, iD );
	return ( iRes );
}

int FecFormNumDiasAnualesDesde ( long lFecha )
{
	int iRes;
	int iA = 0;
	int iM = 0;
	int iD = 0;

	FecFormDescomponer ( lFecha, &iA, &iM, &iD );
	iRes = FecNumDiasAnualesDesde ( iA, iM, iD );
	return ( iRes );
}

int FecSumar ( int * p_iA, int * p_iM, int * p_iD, int iA, int iM, int iD )
{
	int iRes;

	if ( ES_VALIDO ( p_iA ) && ES_VALIDO ( p_iM ) && ES_VALIDO ( p_iD ) )
	{
		if ( ( FecEsValida ( *p_iA, *p_iM, *p_iD ) == 1 ) && ( FecEsValida ( iA, iM, iD ) == 1 ) )
		{
			*p_iD = *p_iD + iD;
			if ( *p_iD > CalendDiasMes ( *p_iA, *p_iM ) )
			{
				*p_iD = *p_iD - CalendDiasMes ( *p_iA, *p_iM );
				*p_iM = *p_iM + 1;
			}
			*p_iM = *p_iM + iM;
			if ( *p_iM > 12 )
			{
				*p_iM = *p_iM - 12;
				*p_iA = *p_iA + 1;
			}
			*p_iA = *p_iA + iA;
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

int FecRestar ( int * p_iA, int * p_iM, int * p_iD, int iA, int iM, int iD )
{
	int iRes;

	if ( ES_VALIDO ( p_iA ) && ES_VALIDO ( p_iM ) && ES_VALIDO ( p_iD ) )
	{
		if ( ( FecEsValida ( *p_iA, *p_iM, *p_iD ) == 1 ) && ( FecEsValida ( iA, iM, iD ) == 1 ) )
		{
			*p_iD = *p_iD - iD;
			*p_iM = *p_iM - iM;
			*p_iA = *p_iA - iA;

			if ( *p_iM <= 0 )
			{
				*p_iM = 12 - *p_iM;
				*p_iA = *p_iA - 1;
			}
			if ( *p_iD <= 0 )
			{
				*p_iM = *p_iM - 1;
				*p_iD = CalendDiasMes ( *p_iA, *p_iM ) - *p_iD;
			}
			if ( *p_iM <= 0 )
			{
				*p_iM = 12;
				*p_iA = *p_iA - 1;
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
	return ( iRes );
}

long FecFormSumar ( long lFecha1, long lFecha2 )
{
	long	lRes;
	int		iA1 = 0;
	int		iM1 = 0;
	int		iD1 = 0;
	int		iA2 = 0;
	int		iM2 = 0;
	int		iD2 = 0;

	FecFormDescomponer ( lFecha1, &iA1, &iM1, &iD1 );
	FecFormDescomponer ( lFecha2, &iA2, &iM2, &iD2 );
	if ( FecSumar ( &iA1, &iM1, &iD1, iA2, iM2, iD2 ) == 1 )
	{
		lRes = FecFormConstruir ( iA1, iM1, iD1 );
	}
	else
	{
		lRes = -1;
	}
	return ( lRes );
}

long FecFormRestar ( long lFecha1, long lFecha2 )
{
	long	lRes;
	int		iA1 = 0;
	int		iM1 = 0;
	int		iD1 = 0;
	int		iA2 = 0;
	int		iM2 = 0;
	int		iD2 = 0;

	FecFormDescomponer ( lFecha1, &iA1, &iM1, &iD1 );
	FecFormDescomponer ( lFecha2, &iA2, &iM2, &iD2 );
	if ( FecRestar ( &iA1, &iM1, &iD1, iA2, iM2, iD2 ) == 1 )
	{
		lRes = FecFormConstruir ( iA1, iM1, iD1 );
	}
	else
	{
		lRes = -1;
	}
	return ( lRes );
}

int FecValEsValido ( double dValor )
{
	int iRes;

	if ( ( dValor >= 1.0 ) || ( dValor <= -1.0 ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

double FecObtenerValor ( int iA, int iM, int iD )
{
	double dRes;

	if ( FecEsValida ( iA, iM, iD ) == 1 )
	{
		dRes = iA * 1.0 + FecNumDiasAnualesHasta ( iA, iM, iD ) / CalendDiasAno ( iA );
	}
	else
	{
		dRes = -1.0;
	}
	return ( dRes );
}

double FecFormObtenerValor ( long lFecha )
{
	double	dRes;
	int		iA = 0;
	int		iM = 0;
	int		iD = 0;

	FecFormDescomponer ( lFecha, &iA, &iM, &iD );
	dRes = FecObtenerValor ( iA, iM, iD );
	return ( dRes );
}

int FecEstablecerValor ( double dValor, int * p_iA, int * p_iM, int * p_iD )
{
	double	dDias;
	int		iRes;

	if ( ( FecValEsValido ( dValor ) == 1 ) && 
		   ES_VALIDO ( p_iA ) && ES_VALIDO ( p_iM ) && ES_VALIDO ( p_iD ) )
	{
		*p_iA = ConvRealDobleAEntero ( dValor, 1 );
		dDias = ( dValor - *p_iA * 1.0 ) * CalendDiasAno ( *p_iA ); 
		*p_iM = 1;
		while ( ( dDias > CalendDiasMes ( *p_iA, *p_iM ) ) && ( *p_iM <= 12 ) )
		{
			dDias = dDias - CalendDiasMes ( *p_iA, *p_iM ) * 1.0;
			*p_iM = *p_iM + 1;
		}
		if ( *p_iM <= 12 )
		{
			*p_iD = ConvRealDobleAEntero ( dDias, 0 );
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

long FecFormEstablecerValor ( double dValor )
{
	long	lRes;
	int		iA = 0;
	int		iM = 0;
	int		iD = 0;

	if ( FecEstablecerValor ( dValor, &iA, &iM, &iD ) == 1 )
	{
		lRes = FecFormConstruir ( iA, iM, iD );
	}
	else
	{
		lRes = -1;
	}
	return ( lRes );
}







