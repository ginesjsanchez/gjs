#include "CppBase.h"

#include <iostream>
#include <map>

using namespace std;
using namespace org::gjs::cpp::common;

extern bool TestToInt ();
extern bool TestToString ();
extern bool TestConcatenar ();
extern bool TestCadenas ();
extern bool TestIToString ();
extern bool TestObjeto ();
extern bool TestExcepcion ();
extern bool TestSistema ();
extern bool TestIComparable ();
extern bool TestColecciones ();
extern bool TestFicheros ();


int main( int argc, char * argv[] )
{
	int iRes = 0;

	map<string, FUNCION_BOOL> mapTests;
	mapTests[ "ToInt" ] = TestToString;
	mapTests[ "ToString" ] = TestToString;
	mapTests[ "Concatenar" ] = TestConcatenar;
	mapTests[ "Cadenas" ] = TestCadenas;
	mapTests[ "IToString" ] = TestIToString;
	mapTests[ "Objeto" ] = TestObjeto;
	mapTests[ "Excepcion" ] = TestExcepcion;
	mapTests[ "Sistema" ] = TestSistema;
	mapTests[ "IComparable" ] = TestIComparable;
	mapTests[ "Colecciones" ] = TestColecciones;
	mapTests[ "Ficheros" ] = TestFicheros;


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

	if ( ! TestToInt () ||
		! TestToString () ||
		! TestConcatenar () ||
		! TestCadenas () ||
		! TestIToString () ||
		! TestObjeto () ||
		! TestExcepcion () ||
		! TestSistema () ||
        ! TestIComparable() ||
        ! TestColecciones() ||
        ! TestFicheros() )
	{
		iRes = -1;
	}
	return ( iRes );
}
