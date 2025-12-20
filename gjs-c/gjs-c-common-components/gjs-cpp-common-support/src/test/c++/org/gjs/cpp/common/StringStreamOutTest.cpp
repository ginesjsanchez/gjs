#include "CppCommonSupport.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace org::gjs::cpp::common;



static bool TestStringStreamOut01 ()
{
	cout << "Test StringStreamOut01:" << endl;
	bool bRes = true;

	try
	{
		StringStreamOut ssObj11;
		ssObj11.put ( 'a' );
		ssObj11.write ( " ejemplo ", 9 );
		ssObj11.put ( 'z' );
		cout << endl;
		
		string sLinea = ssObj11.str ();
		if (  sLinea != "a ejemplo z" )
		{
			cout << "Error caso 1: linea incorrecta [" << sLinea << "]" << endl;
			bRes = false;

		}

		StringStreamOut ssObj12;
		ssObj12.put ( 'a' ).write ( " ejemplo ", 9 ).put ( 'z' );
		cout << endl;

		sLinea = ssObj12.str ();
		if (  sLinea != "a ejemplo z" )
		{
			cout << "Error caso 2: linea incorrecta [" << sLinea << "]" << endl;
			bRes = false;
		}

	}
	catch ( const exception & ex )
	{
		cout << "Error al ejecutar el test: " << ex.what () << endl;
		bRes = false;
	}
	return( bRes );
}

		
static bool TestStringStreamOut02 ()
{
	cout << "Test StringStreamOut02:" << endl;
	bool bRes = true;

	try
	{
		StringStreamOut ssObj1;
	
		ssObj1 << endl;
		ssObj1 << 1 << endl;
		ssObj1 << "Linea 1" << endl;
		ssObj1 << "Linea 2" << endl << endl;
		ssObj1 << ToString ( "Linea 3" ) << endl;
		ssObj1 << "Linea 4";
		cout << endl;
		cout << endl << ANSI::SUBRAYADO_INI << "Contenido capturado:" << ANSI::SUBRAYADO_FIN << endl;	
		cout << ssObj1.str () << endl;
		
		const vector<string> vecEsperadas = { "", "1", "Linea 1", "Linea 2", "", "Linea 3", "Linea 4" };
		string sLinea;
		int iLineas = 0;
		while ( std::getline ( ssObj1, sLinea )  )
		{	
			if (  sLinea != vecEsperadas [ iLineas ] )
			{
				cout << "Error caso 1: linea " << iLineas + 1 << " incorrecta: [" << sLinea << "]" << endl;
				bRes = false;
			}
			iLineas = iLineas + 1;
		}
		if ( iLineas != 7 )
		{
			cout << "Error caso1: numero de lineas inesperado (" << iLineas << ")" << endl;
			bRes = false;
		}
		
		StringStreamOut ssObj2;
	
		ssObj2 << endl << 1 << endl << "Linea 1" << endl << "Linea 2" << endl << endl << ToString ( "Linea 3" ) << endl << "Linea 4" << endl;
		cout << endl << ANSI::SUBRAYADO_INI << "Contenido capturado:" << ANSI::SUBRAYADO_FIN << endl;	
		cout << ssObj2.str () << endl;
		
		iLineas = 0;
		while ( std::getline ( ssObj2, sLinea )  )
		{	
			if (  sLinea != vecEsperadas [ iLineas ] )
			{
				cout << "Error caso 2: linea " << iLineas + 1 << " incorrecta: [" << sLinea << "]" << endl;
				bRes = false;
			}
			iLineas = iLineas + 1;
		}
		if ( iLineas != 7 )
		{
			cout << "Error caso 2: numero de lineas inesperado (" << iLineas << ")" << endl;
			bRes = false;
		}

	}
	catch ( const exception & ex )
	{
		cout << "Error al ejecutar el test: " << ex.what () << endl;
		bRes = false;
	}
	return ( bRes );
}



bool TestStringStreamOut ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test StringStreamOut]" << ANSI::RESETEAR << endl;
	if ( TestStringStreamOut01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestStringStreamOut02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	cout << ANSI::AMARILLO << "[Fin]" << ANSI::RESETEAR << endl;	
	return ( bRes );
}
