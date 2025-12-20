#ifndef _ORG_GJS_C_CC_CPP_TIPODATOS_H
#define _ORG_GJS_C_CC_CPP_TIPODATOS_H

#include <string>



using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			enum class TipoDatos : int
			{
				INDEFINIDO = 0,
				ENTERO = 1,
				REAL = 2,
				CADENA = 3,
				BOOLEANO = 4,

			};

			string ToString( TipoDatos tipo );

 			}
		}
	}
}

#endif
