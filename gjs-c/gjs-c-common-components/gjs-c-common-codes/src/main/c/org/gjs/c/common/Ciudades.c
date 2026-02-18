
#include "Ciudades.h"



long CiudLongitud ( int iPais, int iCiudad )
{
	long lRes;

	if ( iPais == PAIS_ESPANA )
	{
		lRes = CiudEspLongitud ( iCiudad );
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

long CiudLatitud ( int iPais, int iCiudad )
{
	long lRes;

	if ( iPais == PAIS_ESPANA )
	{
		lRes = CiudEspLatitud ( iCiudad );
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

long CiudAltitud ( int iPais, int iCiudad )
{
	long lRes;

	if ( iPais == PAIS_ESPANA )
	{
		lRes = CiudEspAltitud ( iCiudad );
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}




