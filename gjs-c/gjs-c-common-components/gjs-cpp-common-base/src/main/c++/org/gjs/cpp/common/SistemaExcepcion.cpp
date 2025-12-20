#include "BaseConfig.h"

#include "SistemaExcepcion.h"
#include <string.h>



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

SistemaExcepcion::SistemaExcepcion( const string & _sModulo, const string & _sRutina, int _iErrno ) :
										Excepcion( _sModulo, _sRutina, strerror( _iErrno ) )
{
}


            }
		}
	}
}
