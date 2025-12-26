#include "Base.h"

#include "SConversor.h"



static int TestSConversor01 ()
{
	printf( "Test SConversor 01:\n" );
	int iRes = BOOL_VAL_CIERTO;
	SConversor * p_obj1 = SConvCrearDef ();
	if ( BOOL_ES_CIERTO( SConvConversionValida ( p_obj1 ) ) )
	{
		printf( "Error caso 1\n" );
		iRes = BOOL_VAL_FALSO;
	}
	PTR_LIBERAR ( p_obj1 );
	if ( p_obj1 != NULL )
	{
		printf( "Error PTR_LIBERAR\n" );
		iRes = BOOL_VAL_FALSO;
	}
	return ( iRes );
}

int TestSConversor ()
{
	int iRes = BOOL_VAL_CIERTO;
	printf ( "%s[Test SConversior]%s\n", ANSI_AMARILLO,  ANSI_RESETEAR );
	if ( TestSConversor01() )
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
