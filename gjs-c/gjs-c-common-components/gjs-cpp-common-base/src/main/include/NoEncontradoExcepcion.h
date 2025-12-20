#ifndef _ORG_GJS_C_CC_CPP_NOENCONTRADOEXCEPCION_H
#define _ORG_GJS_C_CC_CPP_NOENCONTRADOEXCEPCION_H

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

			class NoEncontradoExcepcion : public Excepcion
			{

			public:
				NoEncontradoExcepcion ( const string & _sModulo, const string & _sRutina, const string & _sTipo, const string & _sObjeto );
			};

            }
		}
	}
}

#endif
