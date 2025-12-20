#ifndef _ORG_GJS_C_CC_CPP_SOCKET_CLIENTE_H
#define _ORG_GJS_C_CC_CPP_SOCKET_CLIENTE_H




#include <Socket.h>




using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class SocketCliente : private Socket
			{
			private:
				bool bConectado = false;
			
			public:
				SocketCliente( int iIP, int iPuerto );
				SocketCliente( const string & sIP, int iPuerto );
				virtual ~SocketCliente();
				
				int getId();
				int getPuerto();
				string getHost();
				
				bool EsValido();
				bool EstaConectado();

				int Enviar( const string & sMensaje );
				int Recibir( string & sMensaje, int iMaxTam = 2048 );
				bool Cerrar();
				
				SocketCliente & operator << ( const string & sMensaje );
				SocketCliente & operator >> ( string & sMensaje );

			};

 			}
		}
	}
}


#endif