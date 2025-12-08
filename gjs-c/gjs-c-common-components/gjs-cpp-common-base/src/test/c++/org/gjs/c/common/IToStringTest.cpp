#include "Base.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;


class PruebaIToString : public IToString
{
private:
	string sValor;

public:
	PruebaIToString( const string & _sValor = "" ) : IToString()
	{
		sValor = _sValor;
	}

	string toString()
	{
		return( sValor );
	}
};



static bool TestIToString01 ()
{
	cout << "Test IToString 01:" << endl;
	bool bRes = true;
	PruebaIToString * obj1 = new PruebaIToString( "abc" );
	PruebaIToString * obj2 = new PruebaIToString( "" );
	if ( obj1->toString() != "abc" )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	if ( obj2->toString() != "" )
	{
		cout << "Error caso 2" << endl;
		bRes = false;
	}
	delete obj1;
	delete obj2;
	return( bRes );
}

bool TestIToString ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ITtoString]" << ANSI::RESETEAR << endl;
	if ( TestIToString01() )
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
