#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))

${symbol_pound}include <CTest.h>



${symbol_pound}include <CEntorno.h>






int main( int argc, char * argv[] )
{
	int iRes = 0;
	EntInicializar ( 1, "Test${capitalizedName}", 1, 0 );
	// TODO
	EntFinalizar ();
	return ( iRes );
}
