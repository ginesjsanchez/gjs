#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestAtributo01 ()
{
	cout << "Test Atributo 01:" << endl;
	bool bRes = true;

	try
	{
		Atributo * atributo = new Atributo();
		if ( atributo->EsValido() || 
			 ( atributo->getTipo() != TipoDatos::INDEFINIDO ) ||
			 ( atributo->getNombre().size() != 0 ) ||
			 ! atributo->isAnulable() || 
			 atributo->isEntero() || 
			 atributo->isReal() || 
			 atributo->isCadena() || 
			 atributo->isBooleano() )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		atributo->setTipo( TipoDatos::ENTERO ); 
		atributo->setNombre( "DATO" ); 
		atributo->setAnulable( false ); 
		if ( !atributo->EsValido() || 
			 ( atributo->getTipo() != TipoDatos::ENTERO ) ||
			 ( atributo->getNombre().compare( "DATO" ) != 0 )  ||
			 atributo->isAnulable() || 
			 !atributo->isEntero() || 
			 atributo->isReal() || 
			 atributo->isCadena() || 
			 atributo->isBooleano() )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		atributo->setTipo( TipoDatos::REAL ); 
		atributo->setNombre( "DATO X" ); 
		atributo->setAnulable( true ); 
		if ( atributo->EsValido() || 
			 ( atributo->getTipo() != TipoDatos::REAL ) ||
			 ( atributo->getNombre().compare( "DATO X" ) != 0 )  ||
			 !atributo->isAnulable() || 
			 atributo->isEntero() || 
			 !atributo->isReal() || 
			 atributo->isCadena() || 
			 atributo->isBooleano() )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		atributo->setTipo( TipoDatos::CADENA ); 
		atributo->setNombre( "Dato3" ); 
		if ( !atributo->EsValido() || 
			 ( atributo->getTipo() != TipoDatos::CADENA ) ||
			 ( atributo->getNombre().compare( "Dato3" ) != 0 )  ||
			 !atributo->isAnulable() || 
			 atributo->isEntero() || 
			 atributo->isReal() || 
			 !atributo->isCadena() || 
			 atributo->isBooleano() )
		{
			cout << "Error caso 4" << endl;
			bRes = false;
		}
		atributo->setTipo( TipoDatos::BOOLEANO ); 
		if ( !atributo->EsValido() || 
			 ( atributo->getTipo() != TipoDatos::BOOLEANO ) ||
			 ( atributo->getNombre().compare( "Dato3" ) != 0 )  ||
			 !atributo->isAnulable() || 
			 atributo->isEntero() || 
			 atributo->isReal() || 
			 atributo->isCadena() || 
			 !atributo->isBooleano() )
		{
			cout << "Error caso 5" << endl;
			bRes = false;
		}
		delete atributo;
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

static bool TestAtributo02 ()
{
	cout << "Test Atributo 02:" << endl;
	bool bRes = true;

	try
	{
		Atributo atributo( TipoDatos::REAL, "DATO", false );
		if ( !atributo.EsValido() || 
			 ( atributo.getTipo() != TipoDatos::REAL ) ||
			 !( atributo.getNombre().compare( "DATO" ) == 0 )  ||
			 atributo.isAnulable() || 
			 atributo.isEntero() || 
			 !atributo.isReal() || 
			 atributo.isCadena() || 
			 atributo.isBooleano() )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		
		Atributo atribCopia = atributo;
		if ( !atribCopia.EsValido() || 
			 ( atribCopia.getTipo() != TipoDatos::REAL ) ||
			!( atribCopia.getNombre().compare( "DATO" ) == 0 )  ||
			 atribCopia.isAnulable() || 
			 atribCopia.isEntero() || 
			 !atribCopia.isReal() || 
			 atribCopia.isCadena() || 
			 atribCopia.isBooleano() )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		
		Atributo atribDif( TipoDatos::ENTERO, "DATO", false );
		if ( atribCopia != atributo )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		if ( atribDif == atributo )
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


bool TestAtributo ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Atributo]" << ANSI::RESETEAR << endl;
	if ( TestAtributo01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestAtributo02() )
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
