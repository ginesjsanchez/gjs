#include "Intercambios.h"
#include "Memoria.h"



void IntercambiarCaracteres ( char * p_cValorA, char * p_cValorB )
{
	char cAux;

	if ( ES_VALIDO ( p_cValorA ) && ES_VALIDO ( p_cValorB ) )
	{
		cAux = *p_cValorA;
		*p_cValorA = *p_cValorB;
		*p_cValorB = cAux;
	}
}

void IntercambiarEnteros ( int * p_iValorA, int * p_iValorB )
{
	int iAux;

	if ( ES_VALIDO ( p_iValorA ) && ES_VALIDO ( p_iValorB ) )
	{
		iAux = *p_iValorA;
		*p_iValorA = *p_iValorB;
		*p_iValorB = iAux;
	}
}

void IntercambiarEngterosLargos ( long * p_lValorA, long * p_lValorB )
{
	long lAux;

	if ( ES_VALIDO ( p_lValorA ) && ES_VALIDO ( p_lValorB ) )
	{
		lAux = *p_lValorA;
		*p_lValorA = *p_lValorB;
		*p_lValorB = lAux;
	}
}

void IntercambiarEnterosSinSigno ( unsigned int * p_uiValorA, unsigned int * p_uiValorB )
{
	unsigned int uiAux;

	if ( ES_VALIDO ( p_uiValorA ) && ES_VALIDO ( p_uiValorB ) )
	{
		uiAux = *p_uiValorA;
		*p_uiValorA = *p_uiValorB;
		*p_uiValorB = uiAux;
	}
}

void IntercambiarEnterosLargosSinSigno ( unsigned long * p_ulValorA, unsigned long * p_ulValorB )
{
	unsigned long ulAux;

	if ( ES_VALIDO ( p_ulValorA ) && ES_VALIDO ( p_ulValorB ) )
	{
		ulAux = *p_ulValorA;
		*p_ulValorA = *p_ulValorB;
		*p_ulValorB = ulAux;
	}
}

void IntercambiarReales ( float * p_fValorA, float * p_fValorB )
{
	float fAux;

	if ( ES_VALIDO ( p_fValorA ) && ES_VALIDO ( p_fValorB ) )
	{
		fAux = *p_fValorA;
		*p_fValorA = *p_fValorB;
		*p_fValorB = fAux;
	}
}

void IntercambiarRealesDobles ( double * p_dValorA, double * p_dValorB )
{double dAux;

	if ( ES_VALIDO ( p_dValorA ) && ES_VALIDO ( p_dValorB ) )
	{
		dAux = *p_dValorA;
		*p_dValorA = *p_dValorB;
		*p_dValorB = dAux;
	}
}


