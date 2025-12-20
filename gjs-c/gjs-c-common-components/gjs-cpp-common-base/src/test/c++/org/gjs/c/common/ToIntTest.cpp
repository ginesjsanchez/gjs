#include "CppBase.h"


#include <iostream>
#include <limits.h>


using namespace std;
using namespace org::gjs::cpp::common;




static bool TestToInt01 ()
{
	cout << "Test ToInt01:" << endl;
	bool bRes = true;
	string sValor = string( "1" );
	long lRes = ToInt( sValor );
	if ( lRes != 1 )
	{
		cout << "Error caso 1: [" << lRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "-1" );
	lRes = ToInt( sValor );
	if ( lRes != -1 )
	{
		cout << "Error caso 2: [" << lRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "0" );
	lRes = ToInt( sValor );
	if ( lRes != 0 )
	{
		cout << "Error caso 3: [" << lRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt02 ()
{
	cout << "Test ToInt02:" << endl;
	bool bRes = true;
	long lRes = ToInt( "1" );
	if ( lRes != 1 )
	{
		cout << "Error caso 1: [" << lRes << "]" << endl;
		bRes = false;
	}
	lRes = ToInt( "-1" );
	if ( lRes != -1 )
	{
		cout << "Error caso 2: [" << lRes << "]" << endl;
		bRes = false;
	}
	lRes = ToInt( "0" );
	if ( lRes != 0 )
	{
		cout << "Error caso 3: [" << lRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt03 ()
{
	cout << "Test ToInt03:" << endl;
	bool bRes = true;
	try
	{
		string sValor = string( "abc" );
		long lRes = ToInt( sValor );
		if ( lRes != 0 )
		{
			cout << "Error caso 1: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 1: Ha retornado excepcion" << endl;
		bRes = false;
	}
	try
	{
		string sValor = string( "" );
		long lRes = ToInt( sValor );
		if ( lRes != 0 )
		{
			cout << "Error caso 2: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 2: Ha retornado excepcion" << endl;
		bRes = false;
	}
	try
	{
		string sValor = string( "999999999999999999999999999999999999999999999999999999999999999" );
		long lRes = ToInt( sValor );
		if ( lRes != LONG_MAX )
		{
			cout << "Error caso 3: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 3: Ha retornado excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt04 ()
{
	cout << "Test ToInt04:" << endl;
	bool bRes = true;
	try
	{
		char * p_cValor = NULL;
		long lRes = ToInt( p_cValor );
		if ( lRes != 0 )
		{
			cout << "Error caso 1: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 1: Ha retornado excepcion" << endl;
		bRes = false;
	}
	try
	{
		string sValor = string( "abc" );
		long lRes = ToInt( sValor.c_str() );
		if ( lRes != 0 )
		{
			cout << "Error caso 2: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 2: Ha retornado excepcion" << endl;
		bRes = false;
	}
	try
	{
		string sValor = string( "" );
		long lRes = ToInt( sValor.c_str() );
		if ( lRes != 0 )
		{
			cout << "Error caso 3: [" << lRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 3: Ha retornado excepcion" << endl;
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


static bool TestToInt05 ()
{
	cout << "Test ToInt05:" << endl;
	bool bRes = true;
	PruebaIToString * obj = new PruebaIToString( "12345" );
	long lRes = ToInt( obj->Base() );
	if ( lRes != 12345 )
	{
		cout << "Error caso 1: [" << lRes << "]" << endl;
		bRes = false;
	}
	delete obj;
	return( bRes );
}

bool TestToInt ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ToInt]" << ANSI::RESETEAR << endl;
	if ( TestToInt01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt03() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt04() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt05() )
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
