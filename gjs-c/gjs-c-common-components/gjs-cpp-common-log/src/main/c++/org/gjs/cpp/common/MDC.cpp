#include "LogConfig.h"
#include "MDC.h"


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

void MDCGuardar ( const string & sClave, const string & sValor )
{
	log4cxx::MDC::put ( sClave, sValor );
}

string MDCRecuperar ( const string & sClave )
{
	return ( log4cxx::MDC::get ( sClave ) );
}

void MDCEliminar ( const string & sClave )
{
	log4cxx::MDC::remove ( sClave );
}

void MDCLimpiar ()
{
	log4cxx::MDC::clear ();
}

                }
            }
        }
    }
}
