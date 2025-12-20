#include "FinExcepcion.h"
#include "ToString.h"
#include "Concatenar.h"


#define MENSAJE_EXCEPCION		"Se ha llamado exit() con codigo: "



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


FinExcepcion::FinExcepcion( const char * p_cModulo, const char * p_cRutina, int iCodigo ) : Excepcion( p_cModulo, p_cRutina, Concatenar( MENSAJE_EXCEPCION, ToString( iCodigo ) ) )
{
}


            }
		}
	}
}
