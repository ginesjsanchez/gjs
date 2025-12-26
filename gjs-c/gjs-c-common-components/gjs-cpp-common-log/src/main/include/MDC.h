#ifndef _ORG_GJS_C_CC_CPP_LOG_MDC_H
#define _ORG_GJS_C_CC_CPP_LOG_MDC_H


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
                namespace MDC
                {
			void MDCGuardar ( const string & sClave, const string & sValor );
			string MDCRecuperar ( const string & sClave );
			void MDCEliminar ( const string & sClave );

			void MDCLimpiar ();
                }
            }
        }
    }
}

#endif
