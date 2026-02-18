#ifndef _ORG_GJS_C_CC_CPP_WINHERRAMIENTAS_H
#define _ORG_GJS_C_CC_CPP_WINHERRAMIENTAS_H


#if ( defined( _WIN32 ) || defined( _WIN64 ) || defined( _WINRT_DLL ) || defined ( __CYGWIN__ ) )


#include <string>



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			// TODO: Añadir parametros y forma de retorno de resultado
			bool DLLEjecutar ( std::string sRutaDLL, std::string sFuncion );

 			}
		}
	}
}

#endif

#endif
