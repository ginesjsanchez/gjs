#include "CppCommonIo.h"
#include <CppBase.h>




using namespace std;
using namespace org::gjs::cpp::common;





static bool TestEsCodigoIETF01 ()
{
	cout << "Test EsCodigoIETF 01:" << endl;
	bool bRes = true;

	try
	{
		if ( EsCodigoIETF( "" ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		if ( EsCodigoIETF( "abc" ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		if ( EsCodigoIETF( "-12" ) )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		if ( !EsCodigoIETF( "200" ) )
		{
			cout << "Error caso 4" << endl;
			bRes = false;
		}
		if ( EsCodigoIETF( "2001" ) )
		{
			cout << "Error caso 5" << endl;
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

static bool TestConstruirRespuestaIETF01 ()
{
	cout << "Test ConstruirRespuestaIETF 01:" << endl;
	bool bRes = true;

	try
	{
		string sRespuesta = ConstruirRespuestaIETF( IETF_OK );
		if ( sRespuesta.compare( "200\r\n" ) != 0 )
		{
			cout << "Error caso 1: [" << sRespuesta << "]" << endl;
			bRes = false;
		}
		sRespuesta = ConstruirRespuestaIETF( "da1" );
		if ( sRespuesta.compare( "999\r\n" ) != 0 )
		{
			cout << "Error caso 2 [" << sRespuesta << "]" << endl;
			bRes = false;
		}
		sRespuesta = ConstruirRespuestaIETF( IETF_OK, "Correcto" );
		if ( sRespuesta.compare( "200 Correcto\r\n" ) != 0 )
		{
			cout << "Error caso 3 [" << sRespuesta << "]" << endl;
			bRes = false;
		}
		sRespuesta = ConstruirRespuestaIETF( IETF_OK, "Correcto dabuti" );
		if ( sRespuesta.compare( "200 Correcto dabuti\r\n" ) != 0 )
		{
			cout << "Error caso 4 [" << sRespuesta << "]" << endl;
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

static bool TestProcesarRespuestaIETF01()
{
	cout << "Test ProcesarRespuestaIETF 01:" << endl;
	bool bRes = true;

	try
	{
		string sCodigo( "" );
		string sMensaje( "" );
		bool bRes = ProcesarRespuestaIETF( "", sCodigo, sMensaje );
		if (  bRes || ( sCodigo.size() > 0 )  || ( sMensaje.size() > 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		sCodigo = "";
		sMensaje = "";
		bRes = ProcesarRespuestaIETF( "abc rockets will win", sCodigo, sMensaje );
		if ( bRes || ( sCodigo.compare( "abc" ) != 0 )  || ( sMensaje.compare ( "rockets will win" ) != 0 ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		sCodigo = "";
		sMensaje = "";
		bRes = ProcesarRespuestaIETF( "200 rockets will win\r\n", sCodigo, sMensaje );
		if ( !bRes || ( sCodigo.compare( "200" ) != 0 )  || ( sMensaje.compare ( "rockets will win" ) != 0 ) )
		{
			cout << "Error caso 3" << endl;
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

static bool TestConstruirMensajeIETF01 ()
{
	cout << "Test ConstruirMensajeIETF 01:" << endl;
	bool bRes = true;

	try
	{
		string sMensaje = ConstruirMensajeIETF( "" );
		if ( sMensaje.compare( "\r\n" ) != 0 )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		sMensaje = ConstruirMensajeIETF( "Correcto" );
		if ( sMensaje.compare( "Correcto\r\n" ) != 0 )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		sMensaje = ConstruirMensajeIETF( "Correcto dabuti" );
		if ( sMensaje.compare( "Correcto dabuti\r\n" ) != 0 )
		{
			cout << "Error caso 3" << endl;
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

static bool TestProcesarMensajeIETF01()
{
	cout << "Test ProcesarMensajeIETF 01:" << endl;
	bool bRes = true;

	try
	{
		string sMensaje = ProcesarMensajeIETF( "" );
		if ( sMensaje.compare( "" ) != 0 ) 
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		sMensaje = ProcesarMensajeIETF( "\r\n" );
		if ( sMensaje.compare( "" ) != 0 ) 
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		sMensaje = ProcesarMensajeIETF( "Procesar mensaje\r\n" );
		if ( sMensaje.compare( "Procesar mensaje" ) != 0 ) 
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		sMensaje = ProcesarMensajeIETF( "Procesar mensaje" );
		if ( sMensaje.compare( "Procesar mensaje" ) != 0 )
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



bool TestCodigosIETF ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test CodigosIETF]" << ANSI::RESETEAR << endl;
	if ( TestEsCodigoIETF01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestConstruirRespuestaIETF01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestProcesarRespuestaIETF01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestConstruirMensajeIETF01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestProcesarMensajeIETF01() )
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
