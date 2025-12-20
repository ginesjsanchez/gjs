#include "CppCommonDatabase.h"
#include <CppBase.h>

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;




static bool TestTabla01 ()
{
	cout << "Test Tabla 01:" << endl;
	bool bRes = true;

	try
	{
		Tabla * tabla = new Tabla( NULL );
		if ( tabla->EsValida() ||
			 ( tabla->getNombre().size() > 0 ) ||
			 ( tabla->NumOcurrencias() != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		delete tabla;

		Entidad * entidad = new Entidad( "Entidad1" );
		tabla = new Tabla( entidad );
		if ( tabla->EsValida() ||
			 ( tabla->getNombre().size() == 0 ) ||
			 ( tabla->NumOcurrencias() != 0 ) )
		{
			cout << "Error caso 2. Nombre=[" << tabla->getNombre() << "]; Ocurrencias=" << tabla->NumOcurrencias()
				<< "; Valida=" << ToString( tabla->EsValida() ) << endl;
			bRes = false;
		}

		Ocurrencia * ocurrencia1 = tabla->Nueva();
		Ocurrencia * ocurrencia2 = new Ocurrencia( entidad );
		tabla->Insertar( ocurrencia1 );
		tabla->Insertar( ocurrencia2 );
		if ( ( ocurrencia1 != NULL ) ||
			( tabla->NumOcurrencias() != 0 ) )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
			delete ocurrencia1;
		}
		delete ocurrencia2;
		delete tabla;
		delete entidad;
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch (... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestTabla02 ()
{
	cout << "Test Tabla 02:" << endl;
	bool bRes = true;

	try
	{
		Entidad * entidad = new Entidad( "Entidad1" );
		entidad->InsertarAtributo( TipoDatos::ENTERO, "Campo1", false );
		Tabla * tabla = new Tabla( entidad );
		if ( !tabla->EsValida() ||
			 ( tabla->getNombre().size() == 0 ) ||
			 ( tabla->NumOcurrencias() != 0 ) ||
			 ( tabla->getOcurrencia( 0 ) != NULL ) )
		{
			cout << "Error caso 1: Ocurrencias=" << tabla->NumOcurrencias() << "; Valida=" << ToString( tabla->EsValida() ) << endl;
			bRes = false;
		}
		Ocurrencia * ocurrencia = tabla->Nueva();
		ocurrencia->getValor( 0 )->setValor( "1" );
		tabla->Insertar( ocurrencia );
		tabla->Insertar( ocurrencia );
		if ( !tabla->EsValida() ||
			 ( tabla->getNombre().size() == 0 ) ||
			 ( tabla->NumOcurrencias() != 1 ) )
		{
			cout << "Error caso 2: Ocurrencias=" << tabla->NumOcurrencias() << "; Valida=" << ToString( tabla->EsValida() ) << endl;
			cout << tabla->toString() << endl;
			cout << entidad->toString() << endl;
			bRes = false;
		}
		ocurrencia = tabla->Nueva();
		ocurrencia->getValor( 0 )->setValor( "1" );
		tabla->Insertar( ocurrencia );
		ocurrencia = tabla->Nueva();
		ocurrencia->getValor( 0 )->setValor( "2" );
		tabla->Insertar( ocurrencia );
		ocurrencia = tabla->Nueva();
		ocurrencia->getValor( 0 )->setValor( "3" );
		tabla->Insertar( ocurrencia );
		if ( !tabla->EsValida() ||
			 ( tabla->getNombre().size() == 0 ) ||
			 ( tabla->NumOcurrencias() != 4 ) ||
			 ( tabla->getOcurrencia( 0 )->getValor( 0 )->getValor().compare( "1" ) != 0  ) ||
			 ( tabla->getOcurrencia( 1 )->getValor( 0 )->getValor().compare( "1" ) != 0  ) ||
			 ( tabla->getOcurrencia( 2 )->getValor( 0 )->getValor().compare( "2" ) != 0  ) ||
			 ( tabla->getOcurrencia( 3 )->getValor( 0 )->getValor().compare( "3" ) != 0  ) ||
			 ( tabla->getOcurrencia( 5 ) != NULL  ) )
		{
			cout << "Error caso 3: Ocurrencias=" << tabla->NumOcurrencias() << endl;
			bRes = false;
		}
		tabla->Eliminar( 1 );
		if ( !tabla->EsValida() ||
			 ( tabla->getNombre().size() == 0 ) ||
			 ( tabla->NumOcurrencias() != 3 ) ||
			 ( tabla->getOcurrencia( 0 )->getValor( 0 )->getValor().compare( "1" ) != 0  ) ||
			 ( tabla->getOcurrencia( 1 )->getValor( 0 )->getValor().compare( "2" ) != 0  ) ||
			 ( tabla->getOcurrencia( 2 )->getValor( 0 )->getValor().compare( "3" ) != 0  ) ||
			 ( tabla->getOcurrencia( 3 ) != NULL  ) )
		{
			cout << "Error caso 4: Ocurrencias=" << tabla->NumOcurrencias() << endl;
			bRes = false;
		}
		delete tabla;
		delete entidad;
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch (... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}


bool TestTabla ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Tabla]" << ANSI::RESETEAR << endl;
	if ( TestTabla01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestTabla02() )
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
