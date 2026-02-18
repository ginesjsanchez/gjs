#include "CppBase.h"


#include <iostream>
#include <limits>
#include <cfloat>



using namespace std;
using namespace org::gjs::cpp::common;




static bool TestToReal01 ()
{
	cout << "Test ToReal01:" << endl;
	bool bRes = true;
	string sValor = string( "1.0" );
	double dRes = ToDouble( sValor );
	if ( dRes != 1.0 )
	{
		cout << "Error caso 1: [" << dRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "-1.0" );
	dRes = ToDouble( sValor );
	if ( dRes != -1.0 )
	{
		cout << "Error caso 2: [" << dRes << "]" << endl;
		bRes = false;
	}
	sValor = string( "0.0" );
	dRes = ToDouble( sValor );
	if ( dRes != 0.0 )
	{
		cout << "Error caso 3: [" << dRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToReal02 ()
{
	cout << "Test ToReal02:" << endl;
	bool bRes = true;
	double dRes = ToDouble( "346.03067638" );
	if ( dRes != 346.03067638 )
	{
		cout << "Error caso 1: [" << dRes << "]" << endl;
		bRes = false;
	}
	dRes = ToDouble( "-156.2389003" );
	if ( dRes != -156.2389003 )
	{
		cout << "Error caso 2: [" << dRes << "]" << endl;
		bRes = false;
	}
	dRes = ToDouble( ToString( DBL_MAX ) );
	if ( dRes != DBL_MAX )
	{
		cout << "Error caso 3: [" << dRes << "]" << endl;
		bRes = false;
	}
	dRes = ToDouble( ToString( DBL_MIN ) );
	if ( dRes != DBL_MIN )
	{
		cout << "Error caso 4: [" << dRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToReal03 ()
{
	cout << "Test ToReal03:" << endl;
	bool bRes = true;
	try
	{
		string sValor = string( "abc" );
		double dRes = ToDouble( sValor );
		if ( dRes != 0.0 )
		{
			cout << "Error caso 1: [" << dRes << "]" << endl;
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
		double dRes = ToDouble( sValor );
		if ( dRes != 0.0 )
		{
			cout << "Error caso 2: [" << dRes << "]" << endl;
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

static bool TestToReal04 ()
{
	cout << "Test ToReal04:" << endl;
	bool bRes = true;
	try
	{
		char * p_cValor = NULL;
		double dRes = ToDouble( p_cValor );
		if ( dRes != 0 )
		{
			cout << "Error caso 1: [" << dRes << "]" << endl;
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
		double dRes = ToDouble( sValor.c_str() );
		if ( dRes != 0 )
		{
			cout << "Error caso 2: [" << dRes << "]" << endl;
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
		double dRes = ToDouble( sValor.c_str() );
		if ( dRes != 0 )
		{
			cout << "Error caso 3: [" << dRes << "]" << endl;
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


static bool TestToReal05 ()
{
	cout << "Test ToReal05:" << endl;
	bool bRes = true;
	PruebaIToString * obj = new PruebaIToString( "12345.6789" );
	double dRes = ToDouble( obj->Base() );
	if ( dRes != 12345.6789 )
	{
		cout << "Error caso 1: [" << dRes << "]" << endl;
		bRes = false;
	}
	delete obj;
	return( bRes );
}

bool TestToReal ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ToDouble]" << ANSI::RESETEAR << endl;
	if ( TestToReal01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToReal02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToReal03() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToReal04() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToReal05() )
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
