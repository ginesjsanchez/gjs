#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $packageNamespace = ${package.replaceAll("\.","::")})

${symbol_pound}include <CTest.h>

${symbol_pound}include "${capitalizedName}.h"








static int TestSample01 ()
{
	printf ( "Test Sample 01:\n" );
	int iRes = 1;

	if ( SmpDoSomething () == 0 )
	{
		printf ( "Error caso 1\n" );
		iRes = 0;
	}
	return( iRes );
}



int TestSample ()
{
	int iRes = 1;
	printf ( "[Test Sample]\n" );
	if ( TestSample01() == 1 )
	{
		printf ( "Resultado: OK\n" );
	}
	else
	{
		printf ( "Resultado: KO\n" );
		iRes = 0;
	}
	printf ( "[Fin]\n" );
	return ( iRes );
}
