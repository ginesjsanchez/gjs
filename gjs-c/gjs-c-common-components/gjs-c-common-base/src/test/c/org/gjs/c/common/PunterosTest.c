#include "Base.h"

#include "Punteros.h"



static int TestPunteros01 ()
{
	printf( "Test Punteros 01:\n" );
	int iRes = BOOL_VAL_CIERTO;
	void * p_vInt = NULL;
	PTR_RESERVAR_MEMORIA( p_vInt, sizeof( int ) );
	if ( p_vInt == NULL )
	{
		printf( "Error caso 1\n" );
		iRes = BOOL_VAL_FALSO;
	}
	int * p_iInt = (int  *)p_vInt;
	*p_iInt = 0;
	PTR_LIBERAR ( p_iInt );
	return ( iRes );
}

int TestPunteros ()
{
	int iRes = BOOL_VAL_CIERTO;
	printf ( "%s[Test Punteros]%s\n", ANSI_AMARILLO,  ANSI_RESETEAR );
	if ( TestPunteros01() )
	{
		printf ( "%sResultado: OK%s\n", ANSI_VERDE, ANSI_RESETEAR );
	}
	else
	{
		printf ( "%sResultado: KO%s\n", ANSI_ROJO, ANSI_RESETEAR );
		iRes = BOOL_VAL_FALSO;
	}
	printf ( "%s[Fin]%s", ANSI_AMARILLO, ANSI_RESETEAR );
	return ( iRes );
}
