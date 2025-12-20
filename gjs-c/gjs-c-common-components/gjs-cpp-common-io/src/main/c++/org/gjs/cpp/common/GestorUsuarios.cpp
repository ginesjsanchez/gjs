#include "CommonIoConfig.h"

#include "GestorUsuarios.h"
#include <FicheroFormateado.h>


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

GestorUsuarios::GestorUsuarios () 
{
}

GestorUsuarios::GestorUsuarios ( const string & sRuta ) 
{
	Cargar( sRuta );
}

GestorUsuarios::~GestorUsuarios ()
{
	Limpiar();
}

int GestorUsuarios::NumUsuarios () const
{
	return ( mapUsuarios.size() );
}

bool GestorUsuarios::Alta( const string & sUsuario, const string & sClave, const string & sSubdirectorio )
{
	bool bRes = false;
	if ( EsToken( sUsuario ) && !Existe( sUsuario ) )
	{
		if ( sClave.empty() || EsToken( sClave ) )
		{
			mapUsuarios[ sUsuario ] = pair<string, string>( sClave, sSubdirectorio );
			bRes = true;
		}
	}
	return( bRes );
}

void GestorUsuarios::Baja( const string & sUsuario )		
{
	map<string, pair<string, string>>::iterator it = mapUsuarios.find( sUsuario );
	if ( it != mapUsuarios.end() )
	{
		mapUsuarios.erase( it );
	}
}

bool GestorUsuarios::Existe ( const string & sUsuario )
{
	map<string, pair<string, string>>::iterator it = mapUsuarios.find( sUsuario );
	return ( it != mapUsuarios.end() );
}

bool GestorUsuarios::Validar( const string & sUsuario, const string & sClave )
{
	bool bRes = false;
	map<string, pair<string, string>>::iterator it = mapUsuarios.find( sUsuario );
	if ( it != mapUsuarios.end() )
	{
		bRes = ( it->second.first.compare( sClave ) == 0 );
	}
	return ( bRes );
}

string GestorUsuarios::Subdirectorio( const string & sUsuario )
{
	string sRes = "";
	map<string, pair<string, string>>::iterator it = mapUsuarios.find( sUsuario );
	if ( it != mapUsuarios.end() )
	{
		sRes = it->second.second;
	}
	return ( sRes );
}

void GestorUsuarios::Limpiar ()
{
	mapUsuarios.clear();
}

bool GestorUsuarios::Cargar( const string & sRuta )
{
	bool bRes = false;
	try
	{
		FicheroTSV * fichero = new FicheroTSV();
		if ( fichero->Cargar( sRuta ) )
		{
			bRes = true;
			for ( int iLinea = 0; iLinea < fichero->NumLineas(); iLinea = iLinea + 1 )
			{
				if ( fichero->NumCamposLinea( iLinea ) >= 2 )
				{
					string sUsuario = fichero->Campo( iLinea, 0 );
					string sClave = fichero->Campo( iLinea, 1 );
					string sDirectorio;
					if ( fichero->NumCamposLinea( iLinea ) > 2 )
					{
						sDirectorio = fichero->Campo( iLinea, 2 );
					}
					bRes = bRes && Alta( sUsuario, sClave, sDirectorio );
				}
				else
				{
					bRes = false;
				}
			}
			bRes = bRes && ( NumUsuarios() > 0 );
		}
	}
	catch( exception & ex )
	{
		cerr << "Error cargando el fichero [" << sRuta << "]: " << ex.what() << endl;
		bRes = false;
	}
	return( bRes );
}

 			}
		}
	}
}
