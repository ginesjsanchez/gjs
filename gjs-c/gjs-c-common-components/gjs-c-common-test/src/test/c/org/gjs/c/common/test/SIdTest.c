#include "Base.h"

#include "SId.h"



static int TestSId01 ()
{
	printf( "Test SId 01:\n" );
	int iRes = BOOL_VAL_CIERTO;
	// TODO
	return ( iRes );
}

int TestSId ()
{
	int iRes = BOOL_VAL_CIERTO;
	printf ( "%s[Test SId]%s\n", ANSI_AMARILLO,  ANSI_RESETEAR );
	if ( TestSId01() )
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
