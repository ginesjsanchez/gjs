#include "CppBase.h"


#include <iostream>
#include <limits>


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
	long lRes = ToInt( "79303" );
	if ( lRes != 79303 )
	{
		cout << "Error caso 1: [" << lRes << "]" << endl;
		bRes = false;
	}
	lRes = ToInt( "-307" );
	if ( lRes != -307 )
	{
		cout << "Error caso 2: [" << lRes << "]" << endl;
		bRes = false;
	}
	lRes = ToInt( ToString( LONG_MAX ) );
	if ( lRes != LONG_MAX )
	{
		cout << "Error caso 3: [" << lRes << "]" << endl;
		bRes = false;
	}
	lRes = ToInt( ToString( LONG_MIN ) );
	if ( lRes != LONG_MIN )
	{
		cout << "Error caso 4: [" << lRes << "]" << endl;
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

static bool TestToInt06 ()
{
	cout << "Test ToInt06:" << endl;
	bool bRes = true;
	string sValor = string( "1" );
	long long llRes = ToLLong( sValor );
	if ( llRes != 1 )
	{
		cout << "Error caso 1: [" << llRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "-1" );
	llRes = ToLLong( sValor );
	if ( llRes != -1 )
	{
		cout << "Error caso 2: [" << llRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "0" );
	llRes = ToLLong( sValor );
	if ( llRes != 0 )
	{
		cout << "Error caso 3: [" << llRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt07 ()
{
	cout << "Test ToInt07:" << endl;
	bool bRes = true;
	long long llRes = ToLLong( "79303" );
	if ( llRes != 79303 )
	{
		cout << "Error caso 1: [" << llRes << "]" << endl;
		bRes = false;
	}
	llRes = ToLLong( "-307" );
	if ( llRes != -307 )
	{
		cout << "Error caso 2: [" << llRes << "]" << endl;
		bRes = false;
	}
	llRes = ToLLong( ToString( LLONG_MAX ) );
	if ( llRes != LLONG_MAX )
	{
		cout << "Error caso 3: [" << llRes << "]" << endl;
		bRes = false;
	}
	llRes = ToLLong( ToString( LLONG_MIN ) );
	if ( llRes != LLONG_MIN )
	{
		cout << "Error caso 4: [" << llRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt08 ()
{
	cout << "Test ToInt08:" << endl;
	bool bRes = true;
	try
	{
		string sValor = string( "abc" );
		long long llRes = ToLLong( sValor );
		if ( llRes != 0 )
		{
			cout << "Error caso 1: [" << llRes << "]" << endl;
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
		long long llRes = ToLLong( sValor );
		if ( llRes != 0 )
		{
			cout << "Error caso 2: [" << llRes << "]" << endl;
			bRes = false;
		}
	}
	catch(...)
	{
		cout << "Error caso 2: Ha retornado excepcion" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToInt09 ()
{
	cout << "Test ToInt09:" << endl;
	bool bRes = true;
	try
	{
		char * p_cValor = NULL;
		long long llRes = ToLLong( p_cValor );
		if ( llRes != 0 )
		{
			cout << "Error caso 1: [" << llRes << "]" << endl;
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
		long long llRes = ToLLong( sValor.c_str() );
		if ( llRes != 0 )
		{
			cout << "Error caso 2: [" << llRes << "]" << endl;
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
		long long llRes = ToLLong( sValor.c_str() );
		if ( llRes != 0 )
		{
			cout << "Error caso 3: [" << llRes << "]" << endl;
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


static bool TestToInt10 ()
{
	cout << "Test ToInt10:" << endl;
	bool bRes = true;
	PruebaIToString * obj = new PruebaIToString( "12345" );
	long long llRes = ToLLong( obj->Base() );
	if ( llRes != 12345 )
	{
		cout << "Error caso 1: [" << llRes << "]" << endl;
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
	if ( TestToInt06() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt07() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt08() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt09() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToInt10() )
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
