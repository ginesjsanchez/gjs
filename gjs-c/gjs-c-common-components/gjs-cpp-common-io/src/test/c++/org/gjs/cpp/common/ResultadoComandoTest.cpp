#include "CppCommonIo.h"




using namespace std;
using namespace org::gjs::cpp::common;





static bool TestResultadoComando01 ()
{
	cout << "Test ResultadoComando 01:" << endl;
	bool bRes = true;

	try
	{
		ResultadoComando * comando = new ResultadoComando();
		if ( comando->EsValido() || 
			 ( comando->getComando().size() != 0 ) ||
			 ( comando->getRespuestaEsperada().size() != 0 ) ||
			 ( comando->NumArgumentos() != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		comando->setComando( "CMD1" ); 
		comando->setRespuestaEsperada( "Aye" ); 
		comando->addArgumento( "ARG1" );
		if ( !comando->EsValido() || 
			 ( comando->getComando().compare( "CMD1" ) != 0 )  ||
			 ( comando->getRespuestaEsperada().compare( "Aye" ) != 0 ) ||
			 ( comando->NumArgumentos() != 1 ) ||
			 ( comando->getArgumento( 0 ).compare( "ARG1" ) != 0 ) )
		{
			cout << "Error caso 2" << endl;
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

static bool TestResultadoComando02 ()
{
	cout << "Test ResultadoComando 02:" << endl;
	bool bRes = true;

	try
	{
		Comando comando1( "CMD1", { "ARG1", "ARG2" } );
		ResultadoComando resultado1( comando1, "Esperado1" );
		if ( !resultado1.EsValido() || 
			 ( resultado1.getComando().compare( "CMD1" ) != 0 )  ||
			 ( resultado1.getRespuestaEsperada().compare( "Esperado1" ) != 0 ) ||
			 ( resultado1.NumArgumentos() != 2 ) ||
			 ( resultado1.getArgumento( 0 ).compare( "ARG1" ) != 0 ) ||
			 ( resultado1.getArgumento( 1 ).compare( "ARG2" ) != 0 ) )
		{
			cout << "Error caso 1: " << resultado1.toString() << ". Valido=" << ToString( resultado1.EsValido() ) << endl;
			bRes = false;
		}
		
		ResultadoComando resultado2( "CMD2", { "ARG1", "ARG2" }, "Esperado2" );
		if ( !resultado2.EsValido() || 
			 ( resultado2.getComando().compare( "CMD2" ) != 0 )  ||
			 ( resultado2.getRespuestaEsperada().compare( "Esperado2" ) != 0 ) ||
			 ( resultado2.NumArgumentos() != 2 ) ||
			 ( resultado2.getArgumento( 0 ).compare( "ARG1" ) != 0 ) ||
			 ( resultado2.getArgumento( 1 ).compare( "ARG2" ) != 0 ) )
		{
			cout << "Error caso 2: " << resultado2.toString() << ". Valido=" << ToString( resultado2.EsValido() ) << endl;
			bRes = false;
		}
		
		ResultadoComando resultado3( "CMD3 ARG31 ARG32", "Esperado3" );
		if ( !resultado3.EsValido() || 
			 ( resultado3.getComando().compare( "CMD3" ) != 0 )  ||
			 ( resultado3.getRespuestaEsperada().compare( "Esperado3" ) != 0 ) ||
			 ( resultado3.NumArgumentos() != 2 ) ||
			 ( resultado3.getArgumento( 0 ).compare( "ARG31" ) != 0 ) ||
			 ( resultado3.getArgumento( 1 ).compare( "ARG32" ) != 0 ) )
		{
			cout << "Error caso 3: " << resultado3.toString() << ". Valido=" << ToString( resultado3.EsValido() ) << endl;
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


bool TestResultadoComando ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ResultadoComando]" << ANSI::RESETEAR << endl;
	if ( TestResultadoComando01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestResultadoComando02() )
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
