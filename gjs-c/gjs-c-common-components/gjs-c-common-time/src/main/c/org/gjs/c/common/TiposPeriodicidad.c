
#include "TiposPeriodicidad.h"
#include "TiempoConfig.h"







int TipPeriodEsValido ( int iId )
{
	int iRes; 

	if ( ( iId == TIP_PERIOD_DIARIO ) ||
 		 ( iId == TIP_PERIOD_SEMANAL ) || 
		 ( iId == TIP_PERIOD_MENSUAL ) ||
		 ( iId == TIP_PERIOD_ANUAL ) ||
		 ( iId == TIP_PERIOD_TRIMESTRAL ) )	
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipPeriodEsDiario ( int iId )
{
	int iRes;

	if ( iId == TIP_PERIOD_DIARIO )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipPeriodEsSemanal ( int iId )
{
	int iRes;

	if ( iId == TIP_PERIOD_SEMANAL )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipPeriodEsMensual ( int iId )
{
	int iRes;

	if ( iId == TIP_PERIOD_MENSUAL )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipPeriodEsAnual ( int iId )
{
	int iRes;

	if ( iId == TIP_PERIOD_ANUAL )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipPeriodEsTrimestral ( int iId )
{
	int iRes;

	if ( iId == TIP_PERIOD_TRIMESTRAL )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

