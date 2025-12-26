#include "LogConfig.h"
#include "MDC.h"



void MDCGuardar ( Clave, Valor )
{
	log4cxx::MDC::put ( sClave, sValor );
}

string MDCRecuperar ( Clave )
{
	return ( log4cxx::MDC::get ( sClave ) );
}

void MDCEliminar ( Clave )
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
