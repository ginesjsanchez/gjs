#include "NivelesLog.h"


int NivelLogEsValido ( int iNivel )
{
	int iRes;

	if ( ( iNivel >= LOG_NIVEL_MIN ) &&
		 ( iNivel <= LOG_NIVEL_MAX ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int NivelLogEsEstablecible ( int iNivel )
{
	int iRes;

	if ( ( iNivel == LOG_NIVEL_NINGUNO ) || 
		 ( ( iNivel >= LOG_NIVEL_MIN ) &&
		   ( iNivel <= LOG_NIVEL_MAX ) ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

