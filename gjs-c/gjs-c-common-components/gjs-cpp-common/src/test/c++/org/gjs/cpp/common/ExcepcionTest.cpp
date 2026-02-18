#include "CppCommon.h"

#include <iostream>

using namespace std;
using namespace org::gjs::cpp::common;



void RutinaPruebaArgumentoInvalidoExcepcion ()
{
	throw ArgumentoInvalidoExcepcion ( "TestExcepcion", "RutinaPruebaExcepcion", "Argumento" );
}



static bool TestArgumentoInvalidoExcepcion01 ()
{
	cout << "Test ArgumentoInvalidoExcepcion01:" << endl;
	bool bRes = true;

	try
	{
		RutinaPruebaArgumentoInvalidoExcepcion ();
		cout << "No se ha produdido el throw" << endl;
		bRes = false;
	}
	catch ( const ArgumentoInvalidoExcepcion & ex )
	{
	}
	catch ( ... )
	{
		cout << "No se ha capturado la excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestExcepcion ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Excepcion]" << ANSI::RESETEAR << endl;
	if ( TestArgumentoInvalidoExcepcion01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	return ( bRes );
}
