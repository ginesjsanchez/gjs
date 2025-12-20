#include "CppBase.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;


class PruebaIComparable : public IComparable
{
private:
	int iValor = 0;

public:
	PruebaIComparable( int _iValor = 0 )
	{
		iValor = _iValor;
	}

private:
	long getHash() const
	{
		return( iValor );
	}
};



static bool TestIComparable01 ()
{
	cout << "Test IComparable 01:" << endl;
	bool bRes = true;
	PruebaIComparable * obj1 = new PruebaIComparable( 1 );
	PruebaIComparable * obj2 = new PruebaIComparable( 934 );
	PruebaIComparable * obj3 = new PruebaIComparable( 934 );
	if ( !obj1->esIgual( obj1 ) )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	if ( obj1->esIgual( *obj2 ) )
	{
		cout << "Error caso 2" << endl;
		bRes = false;
	}
	if ( obj3->esIgual( *obj1 ) )
	{
		cout << "Error caso 3" << endl;
		bRes = false;
	}
	if ( !obj2->esIgual( obj3 ) )
	{
		cout << "Error caso 4" << endl;
		bRes = false;
	}
	delete obj1;
	delete obj2;
	delete obj3;
	return( bRes );
}

static bool TestIComparable02 ()
{
	cout << "Test IComparable 02:" << endl;
	bool bRes = true;
	PruebaIComparable * obj1 = new PruebaIComparable( -56 );
	PruebaIComparable * obj2 = new PruebaIComparable( 934 );
	PruebaIComparable * obj3 = new PruebaIComparable( 934 );
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtautological-compare"
	if ( *obj1 != *obj1 )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
#pragma GCC diagnostic pop
	if ( *obj1 == *obj2 )
	{
		cout << "Error caso 2" << endl;
		bRes = false;
	}
	if ( *obj3 < *obj1 )
	{
		cout << "Error caso 3" << endl;
		bRes = false;
	}
	if ( *obj1 > *obj3 )
	{
		cout << "Error caso 4" << endl;
		bRes = false;
	}
	if ( *obj2 != *obj3 )
	{
		cout << "Error caso 5" << endl;
		bRes = false;
	}
	if ( !( *obj2 >= *obj3 ) )
	{
		cout << "Error caso 6" << endl;
		bRes = false;
	}
	if ( !( *obj2 <= *obj3 ) )
	{
		cout << "Error caso 7" << endl;
		bRes = false;
	}
	if ( *obj3 <= *obj1 )
	{
		cout << "Error caso 8" << endl;
		bRes = false;
	}
	if ( *obj1 >= *obj3 )
	{
		cout << "Error caso 9" << endl;
		bRes = false;
	}
	if ( !( *obj3 >= *obj1 ) )
	{
		cout << "Error caso 10" << endl;
		bRes = false;
	}
	if ( !( *obj1 <= *obj3 ) )
	{
		cout << "Error caso 11" << endl;
		bRes = false;
	}
	delete obj1;
	delete obj2;
	delete obj3;
	return( bRes );
}

bool TestIComparable ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test IComparable]" << ANSI::RESETEAR << endl;
	if ( TestIComparable01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestIComparable02() )
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
