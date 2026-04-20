#include "BaseConfig.h"

#include <cxxabi.h>

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
	const type_info & typeinfo( typeid(*this) );
	int status;
	char* demangled = abi::__cxa_demangle( typeinfo.name(), nullptr, nullptr, &status );
	string tipo = string ( status == 0 ? demangled : typeinfo.name() );
	free( demangled );
	return( tipo );
}

size_t Objeto::getTam () const
{
	return( sizeof( *this ) );
}

bool Objeto::esValido () const
{
	return( true );
}

void Objeto::assignar( Objeto & objeto )
{
}


Objeto * Objeto::clonar()
{
	Objeto * p_objeto = new Objeto();
	p_objeto->assignar( *this );
	return ( p_objeto );
}

bool Objeto::equals ( Objeto & objeto ) const
{
    bool bRes = false;
	if ( getTipo ().compare ( objeto.getTipo () ) == 0 )
	{
		bRes = ( hash() == objeto.hash() );
	}
	return ( bRes );
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
	return ( Concatenar( "[Objeto={Tipo=", getTipo (), "}]" ) );
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
