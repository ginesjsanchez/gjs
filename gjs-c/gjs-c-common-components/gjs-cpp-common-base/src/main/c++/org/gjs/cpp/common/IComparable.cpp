#include "IComparable.h"

#include "Concatenar.h"
#include "ToString.h"
#include <cstddef>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


IComparable::IComparable() : IToString ()
{
}

IComparable::~IComparable()
{
}

string IComparable::toString()
{
	return ( Concatenar( "[Object=", ToString( getHash() ), "]" ) );
}

bool IComparable::esIgual( IComparable & obj )
{
	return ( getHash() == obj.getHash() );
}

bool IComparable::esIgual( IComparable * obj )
{
	if( obj != NULL )
	{
		return( esIgual( *obj ) );
	}
	return( false );
}

bool IComparable::operator== ( IComparable & obj )
{
	return ( getHash() == obj.getHash() );
}

bool IComparable::operator!= ( IComparable & obj )
{
	return ( getHash() != obj.getHash() );
}

bool IComparable::operator< ( IComparable & obj )
{
	return ( getHash() < obj.getHash() );
}

bool IComparable::operator> ( IComparable & obj )
{
	return ( getHash() > obj.getHash() );
}



bool IComparable::operator<= ( IComparable & obj )
{
	return ( getHash() <= obj.getHash() );
}

bool IComparable::operator>= ( IComparable & obj )
{
	return ( getHash() >= obj.getHash() );
}

            }
		}
	}
}


