
#include "Contador.h"
#include <ToString.h>
#include <Concatenar.h>



using namespace org::gjs::cpp::common;
using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

Contador::Contador ()
{
}

Contador::~Contador ()
{
}

unsigned long Contador::getTotal () const
{
	return( ulTotal );
}

unsigned long Contador::getCorrectos () const
{
	return( ulCorrectos );
}

unsigned long Contador::getErroneos () const
{
	return( ulTotal - ulCorrectos );
}

void Contador::Incrementar ( bool bCorrecto )
{
	ulTotal = ulTotal + 1;
	if ( bCorrecto )
	{
		ulCorrectos = ulCorrectos + 1;
	}
}

string Contador::toString ()
{
	return ( Concatenar( "[Total=", ToString( ulTotal ), "; Correctos=", ToString( ulCorrectos ), "; Erroneos=", ToString( getErroneos () ), "]" ) );
}

 			}
		}
	}
}
