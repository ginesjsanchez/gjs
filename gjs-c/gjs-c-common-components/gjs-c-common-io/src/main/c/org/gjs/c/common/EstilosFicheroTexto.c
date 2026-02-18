
#include "EstilosFicheroTexto.h"

#include "FicherosConfig.h"




int EstFicTxtEsValido ( int iEstilo )
{
	int iRes;

	if ( ( iEstilo == EST_FTXT_DOS ) || 
		 ( iEstilo == EST_FTXT_UNIX ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

