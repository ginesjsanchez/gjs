#include "CppBase.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;


class PruebaObjeto : public Objeto
{
private:
    int valor;

public:
	PruebaObjeto( int iValor) : Objeto()
	{
	    this->valor = iValor;
	}

	int getValor () const
    {
        return( valor );
    }


	int hash () const override
    {
        return( valor );
    }

    void assignar( PruebaObjeto & objeto )
    {
        Objeto::assignar( objeto );
        valor = objeto.getValor ();
    }

    PruebaObjeto * clonar() {
        return ( new PruebaObjeto( valor ) );
    }

};



static bool TestObjeto01 ()
{
	cout << "Test Objeto 01:" << endl;
	bool bRes = true;
	PruebaObjeto * obj1 = new PruebaObjeto( 1 );
	if ( obj1->toString() != "[Objeto={Tipo=PruebaObjeto}]" )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	if ( obj1->hash() != 0 )
	{
		cout << "Error caso 2" << endl;
		bRes = false;
	}
	if ( obj1->getTipo().compare ( "PruebaObjeto" ) != 0 )
	{
		cout << "Error caso 3" << endl;
		bRes = false;
	}
	PruebaObjeto * obj2 = obj1->clonar();
	if ( ! obj1->equals( obj2 ) )
	{
		cout << "Error caso 4" << endl;
		bRes = false;
	}
	PruebaObjeto * obj3 = new PruebaObjeto( 2 );
	if ( obj1->equals( obj3 ) )
	{
		cout << "Error caso 5" << endl;
		bRes = false;
	}
	PruebaObjeto obj4 = *obj1;
	if ( ! obj1->equals( obj4 ) )
	{
		cout << "Error caso 5" << endl;
		bRes = false;
	}
	if ( obj1 != ( obj2 ) )
	{
		cout << "Error caso 6" << endl;
		bRes = false;
	}
	if ( obj1 == obj3 )
	{
		cout << "Error caso 7" << endl;
		bRes = false;
	}
	delete obj1;
	delete obj2;
	delete obj3;
	return( bRes );
}

bool TestObjeto ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Objeto]" << ANSI::RESETEAR << endl;
	if ( TestObjeto01() )
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
