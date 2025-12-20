#include "CppCommonIo.h"




using namespace std;
using namespace org::gjs::cpp::common;





static bool TestComando01 ()
{
	cout << "Test Comando 01:" << endl;
	bool bRes = true;

	try
	{
		Comando * comando = new Comando();
		if ( comando->EsValido() || 
			 ( comando->getComando().size() != 0 ) ||
			 ( comando->NumArgumentos() != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		comando->setComando( "CMD 1" ); 
		if ( comando->EsValido() || 
			 ( comando->getComando().compare( "CMD 1" ) != 0 )  ||
			 ( comando->NumArgumentos() != 0 )  )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		comando->setComando( "CMD1" ); 
		comando->addArgumento( "ARG1" );
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "CMD1" ) != 0 )  ||
			 ( comando->NumArgumentos() != 1 ) ||
			 ( comando->getArgumento( 0 ).compare( "ARG1" ) != 0 ) )
		{
			cout << "Error caso 3: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		comando->Asignar( "CMD2", { "ARG1", "ARG2" } );
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "CMD2" ) != 0 )  ||
			 ( comando->NumArgumentos() != 2 ) ||
			 ( comando->getArgumento( 0 ).compare( "ARG1" ) != 0 ) ||
			 ( comando->getArgumento( 1 ).compare( "ARG2" ) != 0 ) )
		{
			cout << "Error caso 4: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		comando->InicializarArgumentos();
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "CMD2" ) != 0 )  ||
			 ( comando->NumArgumentos() != 0 )  )
		{
			cout << "Error caso 5: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		comando->Procesar( "ABRIR usuario clave" );
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "ABRIR" ) != 0 )  ||
			 ( comando->NumArgumentos() != 2 ) ||
			 ( comando->getArgumento( 0 ).compare( "usuario" ) != 0 ) ||
			 ( comando->getArgumento( 1 ).compare( "clave" ) != 0 ) )
		{
			cout << "Error caso 6: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		comando->Procesar( "CMD3 ARG31 ARG32" );
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "CMD3" ) != 0 )  ||
			 ( comando->NumArgumentos() != 2 ) ||
			 ( comando->getArgumento( 0 ).compare( "ARG31" ) != 0 ) ||
			 ( comando->getArgumento( 1 ).compare( "ARG32" ) != 0 ) )
		{
			cout << "Error caso 7: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		comando->Inicializar();
		if ( comando->EsValido() || 
			 ( comando->getComando().size() != 0 ) ||
			 ( comando->NumArgumentos() != 0 ) )
		{
			cout << "Error caso 8: [" << comando->toString() << "]. Valido=" << ToString( comando->EsValido() ) << endl;
			bRes = false;
		}
		delete comando;
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

static bool TestComando02 ()
{
	cout << "Test Comando 02:" << endl;
	bool bRes = true;

	try
	{
		Comando comando1( "CMD2", { "ARG1", "ARG2" } );
		if ( !comando1.EsValido() || 
			 ( comando1.getComando().compare( "CMD2" ) != 0 )  ||
			 ( comando1.NumArgumentos() != 2 ) ||
			 ( comando1.getArgumento( 0 ).compare( "ARG1" ) != 0 ) ||
			 ( comando1.getArgumento( 1 ).compare( "ARG2" ) != 0 ) )
		{
			cout << "Error caso 1: [" << comando1.toString() << "]. Valido=" << ToString( comando1.EsValido() ) << endl;
			bRes = false;
		}
		
		Comando comando2( "CMD3 ARG31 ARG32" );
		if ( !comando2.EsValido() || 
			 ( comando2.getComando().compare( "CMD3" ) != 0 )  ||
			 ( comando2.NumArgumentos() != 2 ) ||
			 ( comando2.getArgumento( 0 ).compare( "ARG31" ) != 0 ) ||
			 ( comando2.getArgumento( 1 ).compare( "ARG32" ) != 0 ) )
		{
			cout << "Error caso 2: [" << comando2.toString() << "]. Valido=" << ToString( comando2.EsValido() ) << endl;
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


bool TestComando ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Comando]" << ANSI::RESETEAR << endl;
	if ( TestComando01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestComando02() )
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
