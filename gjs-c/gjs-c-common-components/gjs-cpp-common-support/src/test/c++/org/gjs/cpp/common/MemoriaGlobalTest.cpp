#include "MemoriaGlobal.h"

#include <CppBase.h>

#include <iostream>
#include <filesystem>



using namespace std;
using namespace org::gjs::cpp::common;




static bool TestMemoriaGlobal01 ()
{
	cout << "Test MemoriaGlobal01: " << endl;
	bool bRes = true;
	try
	{
		string sClave1 ( "Clave1" );
		string sClave2 ( "Clave2" );
		string sValor1 ( "Valor1" );
		string sValor2 ( "Valor2" );

		MemGlobLimpiar ();

		if ( MemGlobExiste ( sClave1 ) )
		{
			cout << "No deberia existir la clave [" << sClave1 << "]" << endl;
			bRes = false;
		}
		if ( MemGlobExiste ( "claveNo" ) )
		{
			cout << "No deberia existir la clave [claveNo]" << endl;
			bRes = false;
		}
		string sValorRet = MemGlobRecuperar( sClave1 );
		if ( sValorRet.size () > 0 )
		{
			cout << "No deberia haberse recuperado ningun valor para [" << sClave1 << "]" << endl;
			bRes = false;
		}

		MemGlobGuardar ( sClave1, sValor1 );
		if ( !MemGlobExiste ( sClave1 ) )
		{
			cout << "Deberia existir la clave [" << sClave1 << "]" << endl;
			bRes = false;
		}
		sValorRet = MemGlobRecuperar( sClave1 );
		if ( sValorRet != sValor1 )
		{
			cout << "Caso 1: Se ha recuperado un valor erroneo para [" << sClave1 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}
		MemGlobGuardar ( sClave1, "" );
		sValorRet = MemGlobRecuperar( sClave1 );
		if ( sValorRet.size () > 0 )
		{
			cout << "Caso 2: Se ha recuperado un valor erroneo para [" << sClave1 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}
		MemGlobGuardar ( sClave1, sValor1 );
		MemGlobGuardar ( sClave2, sValor2 );
		sValorRet = MemGlobRecuperar( sClave2 );
		if ( sValorRet != sValor2 )
		{
			cout << "Caso 3: Se ha recuperado un valor erroneo para [" << sClave2 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}
		MemGlobEliminar ( sClave1 );
		sValorRet = MemGlobRecuperar( sClave1 );
		if ( sValorRet.size () > 0 )
		{
			cout << "Caso 4: Se ha recuperado un valor erroneo para [" << sClave1 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}
		sValorRet = MemGlobRecuperar( sClave2 );
		if ( sValorRet != sValor2 )
		{
			cout << "Caso 5: Se ha recuperado un valor erroneo para [" << sClave2 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}
		MemGlobLimpiar ();
		sValorRet = MemGlobRecuperar( sClave2 );
		if ( sValorRet.size () > 0 )
		{
			cout << "Caso 6: Se ha recuperado un valor erroneo para [" << sClave2 << "]=[" << sValorRet << "]" << endl;
			bRes = false;
		}

	}
	catch ( const exception & ex )
	{
		cout << "Error al probar la funcionalidad del MemoriaGlobal: " << ex.what () << endl;
		bRes = false;
	}
	return( bRes );
}



bool TestMemoriaGlobal ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test MMemoriaGlobal]" << ANSI::RESETEAR << endl;
	if ( TestMemoriaGlobal01 () )
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
