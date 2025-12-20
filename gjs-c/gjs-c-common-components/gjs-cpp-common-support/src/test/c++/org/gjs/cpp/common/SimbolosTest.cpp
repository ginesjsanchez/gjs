#include "CppCommonSupport.h"

#include <iostream>
#include <sstream>
#include <list>
#include <vector>


using namespace std;
using namespace org::gjs::cpp::common;


static bool TestComun ( Simbolos simbolos )
{
	bool bRes = true;
	try
	{
		if ( simbolos.Tam () == 3 )
		{
			if ( simbolos.Simbolo ( 0 ) != "A" )
			{
				cout << "Valor 0 erroneo (1): [" << simbolos.Simbolo ( 0 ) << "]" << endl;
				bRes = false;
			}
			if ( simbolos.Simbolo ( 1 ) != "B" )
			{
				cout << "Valor 1 erroneo (1): [" << simbolos.Simbolo ( 1 ) << "]" << endl;
				bRes = false;
			}
			if ( simbolos.Simbolo ( 2 ) != "C" )
			{
				cout << "Valor 2 erroneo (1): [" << simbolos.Simbolo ( 2 ) << "]" << endl;
				bRes = false;
			}
			if ( simbolos[ 0 ] != "A" )
			{
				cout << "Valor 0 erroneo (2): [" << simbolos.Simbolo ( 0 ) << "]" << endl;
				bRes = false;
			}
			if ( simbolos[ 1 ] != "B" )
			{
				cout << "Valor 1 erroneo (2): [" << simbolos.Simbolo ( 1 ) << "]" << endl;
				bRes = false;
			}
			if ( simbolos[ 2 ] != "C" )
			{
				cout << "Valor 2 erroneo (2): [" << simbolos.Simbolo ( 2 ) << "]" << endl;
				bRes = false;
			}
			stringstream ss;
			ss << simbolos;
			if ( ss.str() != "A, B, C" )
			{
				cout << "Valor cadena erroneo: [" << ss.str() << "]" << endl;
				bRes = false;
			}
		}
		else
		{
			cout << "Longitud erronea: [" << simbolos.Tam () << "]" << endl;
			bRes = false;
		}
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSimbolos01 ()
{
	cout << "Test Simbolos01:" << endl;
	bool bRes = true;

	try
	{
		Simbolos simbolos( { "A", "B", "C" } );
		bRes = TestComun ( simbolos );
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSimbolos02 ()
{
	cout << "Test Simbolos02:" << endl;
	bool bRes = true;

	try
	{
		list<string> lista;
		lista.push_back ( "A" );
		lista.push_back ( "B" );
		lista.push_back ( "C" );
		Simbolos simbolos( lista );
		bRes = TestComun ( simbolos );
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSimbolos03 ()
{
	cout << "Test Simbolos03:" << endl;
	bool bRes = true;

	try
	{
		vector<string> vector;
		vector.push_back ( "A" );
		vector.push_back ( "B" );
		vector.push_back ( "C" );
		Simbolos simbolos( vector );
		bRes = TestComun ( simbolos );
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSimbolos04 ()
{
	cout << "Test Simbolos04:" << endl;
	bool bRes = true;

	try
	{
		Simbolos * simbolos = new Simbolos();
		if ( simbolos->Tam () == 0 )
		{
			simbolos->Insertar ( "A" );
			simbolos->Insertar ( "B" );
			simbolos->Insertar ( "C" );

			bRes = TestComun ( *simbolos );
		}
		else
		{
			cout << "Longitud erronea: [" << simbolos->Tam () << "]" << endl;
			bRes = false;
		}
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}


bool TestSimbolos ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Simbolos]" << ANSI::RESETEAR << endl;
	if ( TestSimbolos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSimbolos02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSimbolos03() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSimbolos04() )
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
