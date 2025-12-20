#include "CppCommonSupport.h"


#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;



static bool TestToString01 ()
{
	cout << "Test ToString:" << endl;
	bool bRes = true;
	TipoDatos tipo = TipoDatos::ENTERO;
	string sEsperado = "Entero";
	string sValor = ToString( tipo );
	if ( sValor.compare( sEsperado ) != 0 )
	{
		cout << "Error caso [" << sEsperado << "] = [" << sValor << "]" << endl;
		bRes = false;
	}
	tipo = TipoDatos::REAL;
	sEsperado = "Real";
	sValor = ToString( tipo );
	if ( sValor.compare( sEsperado ) != 0 )
	{
		cout << "Error caso [" << sEsperado << "] = [" << sValor << "]" << endl;
		bRes = false;
	}
	tipo = TipoDatos::CADENA;
	sEsperado = "Cadena";
	sValor = ToString( tipo );
	if ( sValor.compare( sEsperado ) != 0 )
	{
		cout << "Error caso [" << sEsperado << "] = [" << sValor << "]" << endl;
		bRes = false;
	}
	tipo = TipoDatos::BOOLEANO;
	sEsperado = "Booleano";
	sValor = ToString( tipo );
	if ( sValor.compare( sEsperado ) != 0 )
	{
		cout << "Error caso [" << sEsperado << "] = [" << sValor << "]" << endl;
		bRes = false;
	}
	tipo = TipoDatos::INDEFINIDO;
	sEsperado = "Indefinido";
	sValor = ToString( tipo );
	if ( sValor.compare( sEsperado ) != 0 )
	{
		cout << "Error caso [" << sEsperado << "] = [" << sValor << "]" << endl;
		bRes = false;
	}
	return( bRes );
}




bool TestTipoDatos ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test TipoDatos]" << ANSI::RESETEAR << endl;
	if ( TestToString01() )
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
