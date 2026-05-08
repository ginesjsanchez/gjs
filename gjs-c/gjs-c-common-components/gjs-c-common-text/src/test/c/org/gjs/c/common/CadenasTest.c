#include "Base.h"

#include "Cadenas.h"



static int TestCadCopiarConFormato01 ()
{
	int iRes = BOOL_VAL_CIERTO;
	printf( "Test CadCopiarConFormato 01:\n" );
	char * p_cDestino = CadCrear ( 30 );
	if ( p_cDestino != NULL )
	{
		int iResult = CadCopiarConFormato ( p_cDestino, "Entero=%d", 1 );
		if ( iResult == 1 ) 
		{
			if ( CadComparar ( p_cDestino, "Entero=1" ) != COMP_IGUAL ) 
			{
				printf( "Error caso 1: La cadena formateada no es la esperada: [%s]\n", p_cDestino );
				iRes = BOOL_VAL_FALSO;
			}
		}
		else
		{
			printf( "Error: Se esperada resultado 1 pero se ha recibido %d\n", iResult );
			iRes = BOOL_VAL_FALSO;
		} 
		CadLimpiar ( p_cDestino );
		iResult = CadCopiarConFormato ( p_cDestino, "Cadena=%s", "Valor" );
		if ( iResult == 1 ) 
		{
			if ( CadComparar ( p_cDestino, "Cadena=Valor" ) != COMP_IGUAL ) 
			{
			printf( "Error caso 2: La cadena formateada no es la esperada: [%s]\n", p_cDestino );
				iRes = BOOL_VAL_FALSO;
			}
		}
		else
		{
			printf( "Error: Se esperada resultado 1 pero se ha recibido %d\n", iResult );
			iRes = BOOL_VAL_FALSO;
		} 
		CadLimpiar ( p_cDestino );
		iResult = CadCopiarConFormato ( p_cDestino, "Real=%f", 1.01 );
		if ( iResult == 1 ) 
		{
			if ( CadComparar ( p_cDestino, "Real=1.010000" ) != COMP_IGUAL ) 
			{
			printf( "Error caso 3: La cadena formateada no es la esperada: [%s]\n", p_cDestino );
				iRes = BOOL_VAL_FALSO;
			}
		}
		else
		{
			printf( "Error: Se esperada resultado 1 pero se ha recibido %d\n", iResult );
			iRes = BOOL_VAL_FALSO;
		} 
		MemLiberar ( (void **) &p_cDestino );
	}
	else
	{
		printf( "Error: No se ha podido crear el objeto\n" );
		iRes = BOOL_VAL_FALSO;
	} 
	return ( iRes );
}


int TestCadenas ()
{
	int iRes = BOOL_VAL_CIERTO;
	printf ( "%s[Test Cadenas]%s\n", ANSI_AMARILLO,  ANSI_RESETEAR );
	if ( ( TestCadCopiarConFormato01() == BOOL_VAL_CIERTO ) )
	{
		printf ( "%sResultado: OK%s\n", ANSI_VERDE, ANSI_RESETEAR );
	}
	else
	{
		printf ( "%sResultado: KO%s\n", ANSI_ROJO, ANSI_RESETEAR );
		iRes = BOOL_VAL_FALSO;
	}
	printf ( "%s[Fin]%s\n", ANSI_AMARILLO, ANSI_RESETEAR );
	return ( iRes );
}
