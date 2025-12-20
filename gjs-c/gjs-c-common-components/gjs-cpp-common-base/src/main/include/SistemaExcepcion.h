#ifndef _ORG_GJS_C_CC_CPP_SISTEMAEXCEPCION_H
#define _ORG_GJS_C_CC_CPP_SISTEMAEXCEPCION_H

#include <string>
#include <Excepcion.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class SistemaExcepcion : public Excepcion
			{

			public:
				SistemaExcepcion ( const string & _sModulo, const string & _sRutina, int _iErrno );
			};

            }
		}
	}
}

#endif
