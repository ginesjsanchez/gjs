#ifndef _ORG_GJS_C_CC_CPP_SOCKET_ATENCION_H
#define _ORG_GJS_C_CC_CPP_SOCKET_ATENCION_H





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

			class SocketAtencion : private Socket
			{
			public:
				SocketAtencion( int iSocket );
				virtual ~SocketAtencion();
				
				int getId();
				int getPuerto();
				string getHost();
				
				bool EsValido();

				int Enviar( const string & sMensaje );
				int Recibir( string & sMensaje, int iMaxTam = 2048 );
				bool Cerrar();
				
				SocketAtencion & operator << ( const string & sMensaje );
				SocketAtencion & operator >> ( string & sMensaje );
				
			};

 			}
		}
	}
}


#endif