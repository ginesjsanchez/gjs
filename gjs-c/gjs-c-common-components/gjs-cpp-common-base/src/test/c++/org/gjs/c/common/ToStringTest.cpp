#include "Base.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;



static bool TestToString01 ()
{
	cout << "Test ToString01:" << endl;
	bool bRes = true;
	string sRes = ToString( 1 );
	if ( sRes != "1" )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( -1 );
	if ( sRes != "-1" )
	{
		cout << "Error caso -1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( 0.1 );
	if ( sRes != "0.1" )
	{
		cout << "Error caso 0.1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( " aye" );
	if ( sRes != " aye" )
	{
		cout << "Error caso aye: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( 0 );
	if ( sRes != "0" )
	{
		cout << "Error caso NULL/0: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( wstring( L"ejemplo" ) );
	if ( sRes != "ejemplo" )
	{
		cout << "Error caso wstring: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( L"ejemplo" );
	if ( sRes != "ejemplo" )
	{
		cout << "Error caso wchar_t: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToString02 ()
{
	cout << "Test ToString02:" << endl;
	bool bRes = true;
	const unsigned char SECUENCIA_0[] = "";
	const unsigned char SECUENCIA_1[] = "1234567890";

	string sRes = ToString( SECUENCIA_0 );
	if ( sRes != "{}" )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = ToString( SECUENCIA_1 );
	if ( sRes != "{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToString03 ()
{
	cout << "Test ToString03:" << endl;
	bool bRes = true;
	list<string> lisTest;
	string sRes = ToString( lisTest );
	if ( sRes != "" )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	lisTest.push_back( "linea 1" );
	sRes = ToString( lisTest );
	if ( sRes != "linea 1\n" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	lisTest.push_back( "linea 2" );
	sRes = ToString( lisTest );
	if ( sRes != "linea 1\nlinea 2\n" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToString04 ()
{
	cout << "Test ToString04:" << endl;
	bool bRes = true;
	vector<string> vecTest;
	string sRes = ToString( vecTest );
	if ( sRes != "" )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	vecTest.push_back( "linea 1" );
	sRes = ToString( vecTest );
	if ( sRes != "linea 1\n" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	vecTest.push_back( "linea 2" );
	sRes = ToString( vecTest );
	if ( sRes != "linea 1\nlinea 2\n" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

class PruebaIToString : public IToString
{
private:
	string sValor;

public:
	PruebaIToString( const string & _sValor = "" ) : IToString()
	{
		sValor = _sValor;
	}

	void setValor( const string & _sValor )
	{
		sValor = _sValor;
	}

	string toString()
	{
		return( sValor );
	}

};


static bool TestToString05 ()
{
	cout << "Test ToString05:" << endl;
	bool bRes = true;
	PruebaIToString * obj = new PruebaIToString( "Valor de test" );
	string sRes = ToString( /*(IToString *) */obj->Base() );
	if ( sRes != "Valor de test" )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	obj->setValor( "" );
	sRes = ToString( (IToString *) obj );
	if ( sRes != "" )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	delete obj;
	return( bRes );
}

bool TestToString ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ToString]" << ANSI::RESETEAR << endl;
	if ( TestToString01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToString02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToString03() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToString04() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToString05() )
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
