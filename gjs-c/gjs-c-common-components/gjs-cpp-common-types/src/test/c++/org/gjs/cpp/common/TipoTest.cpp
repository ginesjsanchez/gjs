#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestTipo01 ()
{
	cout << "Test Tipo 01:" << endl;
	bool bRes = true;

	try
	{
		Tipo * tipo = new Tipo();
		if ( tipo->EsValido() || 
			 ( tipo->getTipo() != TipoDatos::INDEFINIDO ) ||
			 tipo->isEntero() || 
			 tipo->isReal() || 
			 tipo->isCadena() || 
			 tipo->isBooleano() )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		tipo->setTipo( TipoDatos::ENTERO ); 
		if ( !tipo->EsValido() || 
			 ( tipo->getTipo() != TipoDatos::ENTERO ) ||
			 !tipo->isEntero() || 
			 tipo->isReal() || 
			 tipo->isCadena() || 
			 tipo->isBooleano() )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		tipo->setTipo( TipoDatos::REAL ); 
		if ( !tipo->EsValido() || 
			 ( tipo->getTipo() != TipoDatos::REAL ) ||
			 tipo->isEntero() || 
			 !tipo->isReal() || 
			 tipo->isCadena() || 
			 tipo->isBooleano() )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		tipo->setTipo( TipoDatos::CADENA ); 
		if ( !tipo->EsValido() || 
			 ( tipo->getTipo() != TipoDatos::CADENA ) ||
			 tipo->isEntero() || 
			 tipo->isReal() || 
			 !tipo->isCadena() || 
			 tipo->isBooleano() )
		{
			cout << "Error caso 4" << endl;
			bRes = false;
		}
		tipo->setTipo( TipoDatos::BOOLEANO ); 
		if ( !tipo->EsValido() || 
			 ( tipo->getTipo() != TipoDatos::BOOLEANO ) ||
			 tipo->isEntero() || 
			 tipo->isReal() || 
			 tipo->isCadena() || 
			 !tipo->isBooleano() )
		{
			cout << "Error caso 5" << endl;
			bRes = false;
		}
		delete tipo;
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

static bool TestTipo02 ()
{
	cout << "Test Tipo 02:" << endl;
	bool bRes = true;

	try
	{
		Tipo tipo( TipoDatos::REAL );
		if ( !tipo.EsValido() || 
			 ( tipo.getTipo() != TipoDatos::REAL ) ||
			 tipo.isEntero() || 
			 !tipo.isReal() || 
			 tipo.isCadena() || 
			 tipo.isBooleano() )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		
		Tipo tipoCopia = tipo;
		if ( !tipoCopia.EsValido() || 
			 ( tipoCopia.getTipo() != TipoDatos::REAL ) ||
			 tipoCopia.isEntero() || 
			 !tipoCopia.isReal() || 
			 tipoCopia.isCadena() || 
			 tipoCopia.isBooleano() )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		
		Tipo tipoDif( TipoDatos::ENTERO );
		if ( tipoCopia != tipo )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		if ( tipoDif == tipo )
		{
			cout << "Error caso 4" << endl;
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


bool TestTipo ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Tipo]" << ANSI::RESETEAR << endl;
	if ( TestTipo01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestTipo02() )
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
