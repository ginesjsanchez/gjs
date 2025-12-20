#ifndef _ORG_GJS_C_CC_CPP_SOCKET_SERVIDOR_H
#define _ORG_GJS_C_CC_CPP_SOCKET_SERVIDOR_H





#include <Socket.h>
#include <SocketAtencion.h>



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class SocketServidor : private Socket
			{
			public:
				SocketServidor( int iPuerto );
				virtual ~SocketServidor();
				
				int getId();
				int getPuerto();
				string getHost();
				
				bool EsValido();

				SocketAtencion * Aceptar();
				int Enviar( const string & sMensaje );
				int Recibir( string & sMensaje, int iMaxTam = 2048 );
				bool Cerrar();
				
				SocketServidor & operator << ( const string & sMensaje );
				SocketServidor & operator >> ( string & sMensaje );
				
			};

 			}
		}
	}
}

#endif