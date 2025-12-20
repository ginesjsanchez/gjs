#include "CppBase.h"

#include <iostream>

using namespace std;
using namespace org::gjs::cpp::common;



static bool TestExcepcion01 ()
{
	cout << "Test Excepcion01:" << endl;
	bool bRes = true;

	Excepcion ex( "TestExcepcion", "TestExcepcion01", "Error de test" );
	if ( ( ex.getModulo () != "TestExcepcion" ) ||
	     ( ex.getRutina () != "TestExcepcion01" ) ||
	     ( ex.getMensaje () != "Error de test" ) ||
	     ( ex.whatExt () != "[TestExcepcion::TestExcepcion01] Error de test" ) ||
		 ( ex.whatExt () != ex.what () ) )
	{
		cout << "Error caso 1: [" << ex.whatExt () << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestExcepcion02 ()
{
	cout << "Test Excepcion02:" << endl;
	bool bRes = true;

	runtime_error ex1 ( "Excepcion error 1" );
	Excepcion ex( "TestExcepcion", "TestExcepcion02", "Error de test", ex1 );
	if ( ( ex.getModulo () != "TestExcepcion" ) ||
	     ( ex.getRutina () != "TestExcepcion02" ) ||
	     ( ex.getMensaje () != Concatenar ( "Error de test [", ex1.what(), "]" ) ) ||
	     ( string( ex.what() ) != Concatenar ( "[TestExcepcion::TestExcepcion02] Error de test [", ex1.what(), "]" ) ) )
	{
		cout << "Error caso 1: [" << ex.whatExt () << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

void RutinaPruebaExcepcion ()
{
	throw Excepcion ( "TestExcepcion", "RutinaPruebaExcepcion", "Error de test" );
}

void RutinaPruebaFinExcepcion ()
{
	throw FinExcepcion ( "TestExcepcion", "RutinaPruebaFinExcepcion", 0 );
}


void RutinaPruebaNoEncontradoExcepcion ()
{
	throw NoEncontradoExcepcion ( "TestExcepcion", "RutinaPruebaNoEncomntradoExcepcion", "propiedad", "clave" );
}

void RutinaPruebaSistemaExcepcion ()
{
	throw SistemaExcepcion ( "TestExcepcion", "RutinaPruebaNoEncomntradoExcepcion", ENOENT );
}


static bool TestExcepcion03 ()
{
	cout << "Test Excepcion02:" << endl;
	bool bRes = true;

	try
	{
		RutinaPruebaExcepcion ();
		cout << "No se ha produdido el throw" << endl;
		bRes = false;
	}
	catch ( const Excepcion & ex )
	{
	}
	catch ( ... )
	{
		cout << "No se ha capturado la excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestFinExcepcion01 ()
{
	cout << "Test FinExcepcion01:" << endl;
	bool bRes = true;

	FinExcepcion ex( "TestExcepcion", "TestFinExcepcion01", -1 );
	if ( ( ex.getModulo () != "TestExcepcion" ) ||
	     ( ex.getRutina () != "TestFinExcepcion01" ) ||
	     ( ex.getMensaje () != "Se ha llamado exit() con codigo: -1" ) )
	{
		cout << "Error caso 1: [" << ex.whatExt () << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestFinExcepcion02 ()
{
	cout << "Test FinExcepcion02:" << endl;
	bool bRes = true;

	try
	{
		RutinaPruebaFinExcepcion ();
		cout << "No se ha produdido el throw" << endl;
		bRes = false;
	}
	catch ( const FinExcepcion & ex )
	{
	}
	catch ( ... )
	{
		cout << "No se ha capturado la excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestNoEncontradoExcepcion01 ()
{
	cout << "Test NoEncontradoExcepcion01:" << endl;
	bool bRes = true;

	try
	{
		RutinaPruebaNoEncontradoExcepcion ();
		cout << "No se ha produdido el throw" << endl;
		bRes = false;
	}
	catch ( const NoEncontradoExcepcion & ex )
	{
	}
	catch ( ... )
	{
		cout << "No se ha capturado la excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestNoEncontradoExcepcion02 ()
{
	cout << "Test NoEncontradoExcepcion02:" << endl;
	bool bRes = true;

	NoEncontradoExcepcion ex( "TestExcepcion", "TestNoEncontradoExcepcion01", "propiedad", "clave" );
	if ( ( ex.getModulo () != "TestExcepcion" ) ||
	     ( ex.getRutina () != "TestNoEncontradoExcepcion01" ) ||
	     ( ex.getMensaje () != "No se ha encontrado el/la propiedad [clave]" ) )
	{
		cout << "Error caso 1: [" << ex.whatExt () << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSistemaExcepcion01 ()
{
	cout << "Test SistemaExcepcion01:" << endl;
	bool bRes = true;

	try
	{
		RutinaPruebaSistemaExcepcion ();
		cout << "No se ha produdido el throw" << endl;
		bRes = false;
	}
	catch ( const SistemaExcepcion & ex )
	{
	}
	catch ( ... )
	{
		cout << "No se ha capturado la excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSistemaExcepcion02 ()
{
	cout << "Test SistemaExcepcion02:" << endl;
	bool bRes = true;

	SistemaExcepcion ex( "TestExcepcion", "TestSistemaExcepcion01", ENOENT );
	if ( ( ex.getModulo () != "TestExcepcion" ) ||
	     ( ex.getRutina () != "TestSistemaExcepcion01" ) ||
	     ( ex.getMensaje () != "No such file or directory" ) )
	{
		cout << "Error caso 1: [" << ex.whatExt () << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestExcepcion ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Excepcion]" << ANSI::RESETEAR << endl;
	if ( TestExcepcion01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestExcepcion02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestExcepcion03() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestFinExcepcion01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestFinExcepcion02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestNoEncontradoExcepcion01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestNoEncontradoExcepcion02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSistemaExcepcion01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSistemaExcepcion02() )
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
