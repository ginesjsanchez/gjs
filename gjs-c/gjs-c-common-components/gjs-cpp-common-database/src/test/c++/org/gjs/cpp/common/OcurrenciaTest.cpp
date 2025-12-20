#include "CppCommonDatabase.h"
#include <CppBase.h>

#include <iostream>

using namespace std;
using namespace org::gjs::cpp::common;




static bool TestOcurrencia01 ()
{
	cout << "Test Ocurrencia 01:" << endl;
	bool bRes = true;

	try
	{
		Ocurrencia * ocurrencia = new Ocurrencia( (Entidad *) NULL );
		if ( ocurrencia->EsValida() ||
			 ( ocurrencia->getEntidad() != NULL ) ||
			 ( ocurrencia->NumValores() != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		delete ocurrencia;

		Entidad * entidad = new Entidad( "Entidad1" );
		ocurrencia = new Ocurrencia( entidad );
		if ( ocurrencia->EsValida() ||
			 ( ocurrencia->getEntidad() == NULL ) ||
			 ( ocurrencia->NumValores() != 0 ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		delete ocurrencia;
		delete entidad;
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

static bool TestOcurrencia02 ()
{
	cout << "Test Ocurrencia 02:" << endl;
	bool bRes = true;

	try
	{
		Entidad * entidad = new Entidad( "Entidad1" );
		entidad->InsertarAtributo( TipoDatos::ENTERO, "Campo1", false );
		Ocurrencia * ocurrencia = new Ocurrencia( entidad );
		if ( ocurrencia->EsValida() ||
			 ( ocurrencia->getEntidad() == NULL ) ||
			 ( ocurrencia->NumValores() != 1 ) ||
			 ( ocurrencia->getValor( 0 ) == NULL ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		ocurrencia->getValor( 0 )->setValor( "panagiotas" );
		if ( ocurrencia->EsValida() ||
			 ( ocurrencia->getEntidad() == NULL ) ||
			 ( ocurrencia->NumValores() != 1 ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		ocurrencia->getValor( 0 )->setValor( 1 );
		if ( !ocurrencia->EsValida() ||
			 ( ocurrencia->getEntidad() == NULL ) ||
			 ( ocurrencia->NumValores() != 1 ) )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		delete ocurrencia;
		delete entidad;
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


static bool TestOcurrencia03 ()
{
	cout << "Test Ocurrencia 03:" << endl;
	bool bRes = true;

	try
	{
		Entidad * entidad1 = new Entidad( "Entidad1" );
		entidad1->InsertarAtributo( TipoDatos::ENTERO, "Campo1", false );
		Ocurrencia ocurrencia1( entidad1 );
		ocurrencia1.getValor( 0 )->setValor( 1 );

		Entidad * entidad2 = new Entidad( "Entidad2" );
		entidad2->InsertarAtributo( TipoDatos::REAL, "Campo1", false );
		Ocurrencia ocurrencia2( entidad2 );
		ocurrencia2.getValor( 0 )->setValor( -0.62 );

		Ocurrencia ocurrencia3( entidad1 );
		ocurrencia3.getValor( 0 )->setValor( 5 );

		Ocurrencia ocurrencia4( entidad1 );
		ocurrencia4.getValor( 0 )->setValor( 1 );

		if ( !ocurrencia1.EsValida() ||
				!ocurrencia2.EsValida() ||
				!ocurrencia3.EsValida() ||
				!ocurrencia4.EsValida() ||
			 ( ocurrencia1 == ocurrencia2 ) ||
			 ( ocurrencia1 == ocurrencia3 ) ||
			 ( ocurrencia1 != ocurrencia4 ) ||
			 ( ocurrencia2 == ocurrencia3 ) ||
			 ( ocurrencia2 == ocurrencia4 ) ||
			 ( ocurrencia3 == ocurrencia4 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}

		delete entidad1;
		delete entidad2;
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


bool TestOcurrencia ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Ocurrencia]" << ANSI::RESETEAR << endl;
	if ( TestOcurrencia01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestOcurrencia02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestOcurrencia03() )
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
