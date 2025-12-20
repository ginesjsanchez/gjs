#include "Booleano.h"


/* Rutinas: */
booleano BoolCierto ()
{
	return ( BOOL_VAL_CIERTO );
}


booleano BoolFalso ()
{
	return ( BOOL_VAL_FALSO );
}


booleano BoolNormalizar ( booleano bValor )
{
	booleano bRes;

	if ( bValor == 0 )
	{
		bRes = BOOL_VAL_FALSO;
	}
	else
	{
		bRes = BOOL_VAL_CIERTO;
	}
	return ( bRes );
}


booleano BoolNo ( booleano bValor ) 
{
	booleano bRes;

	if ( bValor == BOOL_VAL_FALSO )
	{
		bRes = BOOL_VAL_CIERTO;
	}
	else
	{
		bRes = BOOL_VAL_FALSO;
	}
	return ( bRes );
}


booleano BoolY ( booleano bValor1, booleano bValor2 ) 
{
	booleano bRes;

	if ( ( bValor1 == BOOL_VAL_CIERTO ) && ( bValor2 == BOOL_VAL_CIERTO ) )
	{
		bRes = BOOL_VAL_CIERTO;
	}
	else
	{
		bRes = BOOL_VAL_FALSO;
	}
	return ( bRes );
}


booleano BoolO ( booleano bValor1, booleano bValor2 ) 
{
	booleano bRes;

	if ( ( bValor1 == BOOL_VAL_CIERTO ) || ( bValor2 == BOOL_VAL_CIERTO ) )
	{
		bRes = BOOL_VAL_CIERTO;
	}
	else
	{
		bRes = BOOL_VAL_FALSO;
	}
	return ( bRes );
}
