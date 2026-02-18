#ifndef _ORG_GJS_C_CC_CPP_ARGUUMENTOINVALIDOEXCEPCION_H
#define _ORG_GJS_C_CC_CPP_ARGUUMENTOINVALIDOEXCEPCION_H

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

			class ArgumentoInvalidoExcepcion : public Excepcion
			{
			public:
				ArgumentoInvalidoExcepcion( const string & sModulo, const string & sRutina, const string & sArgumento );
			};

            }
		}
	}
}

#endif
