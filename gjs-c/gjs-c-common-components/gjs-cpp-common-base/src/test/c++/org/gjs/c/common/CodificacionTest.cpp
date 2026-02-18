#include "CppBase.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;




static bool TestUnicodeAUtf801 ()
{
	cout << "Test UnicodeAUtf8 01:" << endl;
	bool bRes = true;
	wstring wsCadena = wstring( L"" );
	string sRes = UnicodeAUtf8( wsCadena );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	wsCadena = wstring( L"Esto es una cadena" );
	sRes = UnicodeAUtf8( wsCadena );
	if ( sRes.compare( "Esto es una cadena" ) != 0 )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestUnicodeAUtf1601 ()
{
	cout << "Test UnicodeAUtf16 01:" << endl;
	bool bRes = true;
	wstring wsCadena = wstring( L"" );
	string sRes = UnicodeAUtf16( wsCadena );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	wsCadena = wstring( L"Esto es una cadena" );
	sRes = UnicodeAUtf16( wsCadena );
	if ( sRes.size() != 2 * wsCadena.size() )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestUtf8AUnicode01 ()
{
	cout << "Test Utf8AUnicode 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	wstring  wsRes = Utf8AUnicode( sCadena );
	if ( wsRes.size() != 0 )
	{
		wcout << L"Error caso 1: [" << wsRes << L"]" << endl;
		bRes = false;
	}
	sCadena = string( "Esto es una cadena" );
	wsRes = Utf8AUnicode( sCadena );
	if ( wsRes.compare( wstring( L"Esto es una cadena" ) ) != 0 )
	{
		wcout << L"Error caso 2: [" << wsRes << L"]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestUtf16AUnicode01 ()
{
	cout << "Test Utf16AUnicode 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	wstring  wsRes = Utf16AUnicode( sCadena );
	if ( wsRes.size() != 0 )
	{
		wcout << L"Error caso 1: [" << wsRes << L"]" << endl;
		bRes = false;
	}
	sCadena = string( "Esto es una cadena" );
	wsRes = Utf16AUnicode( sCadena );
	if ( wsRes.size() != sCadena.size() )
	{
		wcout << L"Error caso 1: [" << wsRes << L"]" << endl;
	}
	return( bRes );
}


bool TestCodificacion ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Cadenas]" << ANSI::RESETEAR << endl;
	if ( TestUnicodeAUtf801() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestUnicodeAUtf1601() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestUtf8AUnicode01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestUtf16AUnicode01() )
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
