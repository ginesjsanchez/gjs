#include "CppCommonSupport.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestValor01 ()
{
	cout << "Test Valor 01:" << endl;
	bool bRes = true;

	try
	{
		Valor * valor = new Valor();
		if ( !valor->EsNulo() || 
			 ( valor->getValor().size() != 0 ) )
		{
			cout << "Error caso 1: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "" ) != 0 )  ||
			 ( valor->getValorEntero() != 0L ) ||
			 ( valor->getValorEnteroLargo() != 0LL ) ||
			 ( valor->getValorReal() != 0.0 ) ||
			 ( valor->getValorRealLargo() != 0.0L ) ||
			 valor->getValorBool() )
		{
			cout << "Error caso 2: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "abc" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "abc" ) != 0 )  ||
			 ( valor->getValorEntero() != 0L ) ||
			 ( valor->getValorEnteroLargo() != 0LL  ) ||
			 ( valor->getValorReal() != 0.0 ) ||
			 ( valor->getValorRealLargo() != 0.0L ) ||
			 valor->getValorBool() )
		{
			cout << "Error caso 3: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "0" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "0" ) != 0 )  ||
			 ( valor->getValorEntero() != 0L ) ||
			 ( valor->getValorEnteroLargo() != 0LL  ) ||
			 ( valor->getValorReal() != 0.0 ) ||
			 ( valor->getValorRealLargo() != 0.0L ) ||
			 valor->getValorBool() )
		{
			cout << "Error caso 4: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "1" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "1" ) != 0 )  ||
			 ( valor->getValorEntero() != 1L ) ||
			 ( valor->getValorEnteroLargo() != 1LL  ) ||
			 ( valor->getValorReal() != 1.0 ) ||
			 ( valor->getValorRealLargo() != 1.0L ) ||
			 ! valor->getValorBool() )
		{
			cout << "Error caso 5: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "-157" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "-157" ) != 0 )  ||
			 ( valor->getValorEntero() != -157L ) ||
			 ( valor->getValorEnteroLargo() != -157LL  ) ||
			 ( valor->getValorReal() != -157.0 ) ||
			 ( valor->getValorRealLargo() != -157.0L ) ||
			 valor->getValorBool() )
		{
			cout << "Error caso 6: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		valor->setValor( "4.1" ); 
		if ( valor->EsNulo() || 
			 ( valor->getValor().compare( "4.1" ) != 0 )  ||
			 ( valor->getValorEntero() != 4L ) ||
			 ( valor->getValorEnteroLargo() != 4LL  ) ||
			 ( valor->getValorReal() != 4.1 ) ||
			 ( valor->getValorRealLargo() != 4.1L ) ||
			 valor->getValorBool() )
		{
			cout << "Error caso 7: [" << valor->getValor() << "]" << endl;
			bRes = false;
		}
		delete valor;
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

static bool TestValor02 ()
{
	cout << "Test Valor 02:" << endl;
	bool bRes = true;

	try
	{
		Valor valor( "DATO" );
		if ( valor.EsNulo() || 
			 ( valor.getValor().compare( "DATO" ) != 0 ) )
		{
			cout << "Error caso 1: [" << valor.getValor() << "]" << endl;
			bRes = false;
		}
		
		Valor valCopia = valor;
		if ( valCopia.EsNulo() || 
			( valCopia.getValor().compare( "DATO" ) != 0 ) )
		{
			cout << "Error caso 2: [" << valCopia.getValor() << "]" << endl;
			bRes = false;
		}
		
		Valor valDif( "DAT0" );
		if ( valCopia != valor )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		if ( valDif == valor )
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


bool TestValor ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Valor]" << ANSI::RESETEAR << endl;
	if ( TestValor01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestValor02() )
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
