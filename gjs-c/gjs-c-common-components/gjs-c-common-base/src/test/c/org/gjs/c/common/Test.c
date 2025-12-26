#include "Base.h"


extern int TestPunteros ();
extern int TestSConversor ();



int main( int argc, char * argv[] )
{
	int iRes = 0;
	//InicializarBase();

	char * p_cTest = 0x0;
	if ( argc > 1 )
	{
		p_cTest = argv[1];
	}
//	if ( ( sTest.size() > 0 ) && ( sTest.compare( "null" ) != 0 ) )
//	{
//		if ( mapTests.find( sTest ) != mapTests.end() )
//		{
//			FUNCION_BOOL fTest = mapTests[ sTest ];
//			if( !fTest() )
//			{
//				iRes = -1;
//			}
//		}
//		else
//		{
//			cerr << "Test [" << sTest << "] no encontrado." << endl;
//			iRes = -1;
//		}
//		return( iRes );
//	}
//
	if ( BOOL_ES_FALSO ( TestPunteros () ||
                        TestSConversor () ) )
	{
		iRes = -1;
	}
	return ( iRes );
}
