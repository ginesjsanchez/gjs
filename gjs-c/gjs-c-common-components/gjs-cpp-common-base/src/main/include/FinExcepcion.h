#ifndef _ORG_GJS_C_CC_CPP_FINEXCEPCION_H
#define _ORG_GJS_C_CC_CPP_FINEXCEPCION_H

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

			class FinExcepcion : public Excepcion
			{
			public:
				FinExcepcion( const string & sModulo, const string & sRutina, int iCodigo );
			};

            }
		}
	}
}

#endif
