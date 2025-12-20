#include "CommonDatabaseConfig.h"

#include "Tabla.h"



using namespace org::gjs::cpp::common;
using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

Tabla::Tabla ( Entidad * entidad ) : Entidad( entidad )
{
}

Tabla::Tabla ( Entidad & entidad ) : Entidad( entidad )
{
}

Tabla::~Tabla ()
{
	Vaciar();
}

int Tabla::NumOcurrencias () const
{
	return ( vecContenido.size() );
}

Ocurrencia * Tabla::getOcurrencia ( int iIndice )
{
	Ocurrencia * ocurrencia = NULL;
	if ( Entidad::EsValida() && ( iIndice >= 0 ) && ( iIndice < vecContenido.size() ) )
	{
		ocurrencia = vecContenido[ iIndice ];
	}
	return ( ocurrencia );
}

Ocurrencia * Tabla::Nueva ()
{
	Ocurrencia * ocurrencia = NULL;
	if ( Entidad::EsValida() )
	{
		ocurrencia = new Ocurrencia( (Entidad *) this );
	}
	return ( ocurrencia );
}

void Tabla::Insertar ( Ocurrencia * ocurrencia )
{
	if ( Entidad::EsValida() && ( ocurrencia != NULL ) )
	{
		if ( Entidad::EsCompatible( ocurrencia->getEntidad() ) )
		{
			bool bExiste = false;
			int iIndice = 0;
			while ( !bExiste && ( iIndice < vecContenido.size() ) )
			{
				bExiste = ( (void *) vecContenido[ iIndice ] == (void *) ocurrencia );
				iIndice = iIndice + 1;
			}
			if ( !bExiste )
			{
				vecContenido.push_back( ocurrencia );
			}
		}
	}
}

void Tabla::Eliminar ( int iIndice )
{
	if ( Entidad::EsValida() && ( iIndice >= 0 ) && ( iIndice < vecContenido.size() ) )
	{
		delete vecContenido[ iIndice ];
		vecContenido.erase( vecContenido.begin() + iIndice );
	}
}

void Tabla::Vaciar ()
{
	for ( Ocurrencia * ocurrencia : vecContenido )
	{
		delete ocurrencia;
	}
	vecContenido.clear();
}

string Tabla::toString ()
{
	return ( Concatenar( "[Tabla={Entidad=[", Entidad::toString(), "]; NumOcurrencias=", ToString( NumOcurrencias() ), "}]" ) );
}

 			}
		}
	}
}
