
#include "Objeto.h"
#include "Cadenas.h"
#include "ToString.h"
#include "Concatenar.h"




using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

Objeto::Objeto ()
{
    const type_info &typeinfo( typeid(*this) );
    tipo = string ( typeinfo.name() );
}

Objeto::~Objeto ()
{
}

int Objeto::hash () const
{
	return( 0 );
}

string Objeto::getTipo () const
{
	return( tipo );
}

bool Objeto::esValido () const
{
	return( true );
}

void Objeto::assignar( Objeto & objeto )
{
    tipo = string ( objeto.getTipo() );
}


Objeto * Objeto::clonar()
{
	Objeto * p_objeto = new Objeto();
	p_objeto->assignar( *this );
	return ( p_objeto );
}

bool Objeto::equals ( Objeto & objeto ) const
{
	return ( hash() == objeto.hash() );
}

bool Objeto::equals ( Objeto * objeto ) const
{
    bool bRes = false;
    if ( objeto != NULL )
    {
        bRes = equals( *objeto );
    }
	return ( bRes );
}


string Objeto::toString ()
{
	return ( Concatenar( "[Objeto={Tipo=", tipo, "}]" ) );
}

Objeto & Objeto::operator= ( Objeto & objeto )
{
	assignar( objeto );
	return ( *this );
}

bool Objeto::operator== ( Objeto & objeto )
{
	return ( equals( objeto ) );
}

bool Objeto::operator!= ( Objeto & objeto )
{
	return ( !equals( objeto ) );
}

			}
		}
	}
}
