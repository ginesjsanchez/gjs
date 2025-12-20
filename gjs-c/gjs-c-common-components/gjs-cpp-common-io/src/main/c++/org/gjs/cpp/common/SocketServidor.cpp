#include "CommonIoConfig.h"

#include "SocketServidor.h"



using namespace org::gjs::cpp::common;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

SocketServidor::SocketServidor( int iPuerto ) : Socket ()
{
	int iError = 0;
	if ( Socket::Crear () )
	{
		if ( Socket::Enlazar( iPuerto ) )
		{
			if ( ! Socket::Escuchar() )
			{
				iError = errno;
				Socket::Cerrar();			
			}
		}
		else
		{
			iError = errno;
			Socket::Cerrar();
		}
	}
	else
	{
		iError = errno;
	}
	if ( iError != 0 )
	{
		throw SocketExcepcion( "SocketServidor", "Constructor", iError );
	}
}

SocketServidor::~SocketServidor()
{
}

bool SocketServidor::EsValido()
{
	return ( Socket::AceptaConexiones() );
}

int SocketServidor::getId()
{
	return ( Socket::getId() );
}

int SocketServidor::getPuerto()
{
	return( Socket::getPuerto() );
}

string SocketServidor::getHost()
{
	return( Socket::getHost() );
}

SocketAtencion * SocketServidor::Aceptar()
{
	int iSocketHijo = Socket::Aceptar();
	return( new SocketAtencion( iSocketHijo ) );
}

int SocketServidor::Enviar( const string & sMensaje ) 
{
	return( Socket::Enviar( sMensaje ) );
}

int SocketServidor::Recibir( string & sMensaje, int iMaxTam )
{
	return( Socket::Recibir( sMensaje, iMaxTam ) );
}

bool SocketServidor::Cerrar()
{
	return( Socket::Cerrar() );
}

SocketServidor & SocketServidor::operator << ( const string & sMensaje )
{
	if ( Socket::Enviar( sMensaje ) != sMensaje.length() )
	{
		throw SocketExcepcion( "SocketServidor", "operator<<", errno );
	}
	return( *this );
}

SocketServidor & SocketServidor::operator >> ( string & sMensaje )
{
	if ( Socket::Recibir( sMensaje ) < 0 )
	{
		throw SocketExcepcion( "SocketServidor", "operator>>", errno );
	}
	return( *this );
}

 			}
		}
	}
}

