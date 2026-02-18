#include "CppCommonTypes.h"

#include <map>


//extern bool TestPtr ();


int main( int argc, char * argv[] )
{
	int iRes = 0;
	InicializarBase();

	map<string, FUNCION_BOOL> mapTests;
//	mapTests[ "Ptr" ] = TestPtr;

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

	//if (! TestPtr () )
	if ( false )
	{
		iRes = -1;
	}
	return ( iRes );
}
