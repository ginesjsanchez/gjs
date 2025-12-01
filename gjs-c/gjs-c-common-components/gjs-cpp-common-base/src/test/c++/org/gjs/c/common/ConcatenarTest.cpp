#include "Base.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;




static bool TestConcatenar01 ()
{
	cout << "Test Concatenar01:" << endl;
	bool bRes = true;
	string sRes = Concatenar( "" );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = Concatenar( "cadena1 ", " cadena2" );
	if ( sRes != "cadena1  cadena2" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = Concatenar( "", "cadena1 ", "", " cadena2", "" );
	if ( sRes != "cadena1  cadena2" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestConcatenar02 ()
{
	cout << "Test Concatenar02:" << endl;
	bool bRes = true;
	string sCadena0 ( "" );
	string sCadena1 ( "cadena1 " );
	string sCadena2 ( " cadena2" );

	string sRes = Concatenar( sCadena0 );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = Concatenar( sCadena1, sCadena2 );
	if ( sRes != "cadena1  cadena2" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = Concatenar( sCadena1, "-",  sCadena2 );
	if ( sRes != "cadena1 - cadena2" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = Concatenar( sCadena0, sCadena1, sCadena0, sCadena2, sCadena0 );
	if ( sRes != "cadena1  cadena2" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestConcatenar ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Concatenar]" << ANSI::RESETEAR << endl;
	if ( TestConcatenar01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestConcatenar02() )
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
