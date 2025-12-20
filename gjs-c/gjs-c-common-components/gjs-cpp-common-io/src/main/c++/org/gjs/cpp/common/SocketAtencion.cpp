#include "CommonIoConfig.h"

#include "SocketAtencion.h"




using namespace org::gjs::cpp::common;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

SocketAtencion::SocketAtencion( int iSocket ) : Socket ()
{
	Socket::setId( iSocket );
}

SocketAtencion::~SocketAtencion()
{
}

bool SocketAtencion::EsValido()
{
	return ( Socket::EstaConectado() );
}

int SocketAtencion::getId()
{
	return ( Socket::getId() );
}

int SocketAtencion::getPuerto()
{
	return( Socket::getPuerto() );
}

string SocketAtencion::getHost()
{
	return( Socket::getHost() );
}

int SocketAtencion::Enviar( const string & sMensaje ) 
{
	return( Socket::Enviar( sMensaje ) );
}

int SocketAtencion::Recibir( string & sMensaje, int iMaxTam )
{
	return( Socket::Recibir( sMensaje, iMaxTam ) );
}

bool SocketAtencion::Cerrar()
{
	return( Socket::Cerrar() );
}

SocketAtencion & SocketAtencion::operator << ( const string & sMensaje )
{
	if ( Socket::Enviar( sMensaje ) != sMensaje.length() )
	{
		throw SocketExcepcion( "SocketAtencion", "operator<<", errno );
	}
	return( *this );
}

SocketAtencion & SocketAtencion::operator >> ( string & sMensaje )
{
	if ( Socket::Recibir( sMensaje ) < 0 )
	{
		throw SocketExcepcion( "SocketAtencion", "operator>>", errno );
	}
	return( *this );
}

 			}
		}
	}
}
