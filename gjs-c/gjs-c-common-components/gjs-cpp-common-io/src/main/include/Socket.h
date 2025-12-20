#ifndef _ORG_GJS_C_CC_CPP_SOCKET_H
#define _ORG_GJS_C_CC_CPP_SOCKET_H



#include <SocketExcepcion.h>

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Socket
			{
			private:
				int 				iSocket;
				struct sockaddr_in 	sockaddrSocket;
				
			public:
				Socket();
				virtual ~Socket();
				
				int getId();
				int getPuerto();
				string getHost();

			protected:
				void setId( int valor );
				
			public:
				bool EsValido();
				bool AceptaConexiones();
				bool EstaConectado();

				bool Crear();
				bool Enlazar( int iPuerto );
				bool Conectar( int iIP, int iPuerto );
				bool Conectar( const string & sIP, int iPuerto );
				bool Escuchar( int iTamCola = SOMAXCONN );
				int Aceptar();
				int Enviar( const string & sMensaje );
				int Recibir( string & sMensaje, int iMaxTam = 2048 );
				bool Cerrar();
			};

 			}
		}
	}
}


#endif