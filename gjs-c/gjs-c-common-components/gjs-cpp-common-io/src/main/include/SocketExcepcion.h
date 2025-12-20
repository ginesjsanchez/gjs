#ifndef _ES_INTERIOR_SOCKETEXCEPCION_H
#define _ES_INTERIOR_SOCKETEXCEPCION_H

#include <string>
#include <SistemaExcepcion.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class SocketExcepcion : public SistemaExcepcion
			{
			
			public:
				SocketExcepcion ( const string & _sModulo, const string & _sRutina, int _iErrno );				
			};

 			}
		}
	}
}

#endif