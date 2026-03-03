#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))

${symbol_pound}include <CppTest.h>

${symbol_pound}include "${capitalizedName}.h"

${symbol_pound}include <map>


using namespace org::gjs::cpp::common;
using namespace std;



extern bool TestSample ();
extern bool TestSampleType ();


int main( int argc, char * argv[] )
{
	int iRes = 0;
	InicializarBase();

	map<string, FUNCION_BOOL> mapTests;
	mapTests[ "Sample" ] = TestSample;
	mapTests[ "SampleType" ] = TestSampleType;


	string sTest( "null" );
	if ( argc > 1 )
	{
		sTest = argv[1];
	}
	if ( ( sTest.size() > 0 ) && ( sTest.compare( "null" ) != 0 ) )
	{
		if ( mapTests.find( sTest ) != mapTests.end() )
		{
			FUNCION_BOOL fTest = mapTests[ sTest ];
			if( !fTest() )
			{
				iRes = -1;
			}
		}
		else
		{
			cerr << "Test [" << sTest << "] no encontrado." << endl;
			iRes = -1;
		}
		return( iRes );
	}

	if ( ! TestSample () ||
        ! TestSampleType ())
	{
		iRes = -1;
	}
	return ( iRes );
}
