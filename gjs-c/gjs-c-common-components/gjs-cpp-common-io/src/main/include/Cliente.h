#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_H




#include <SocketCliente.h>




using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Cliente : private SocketCliente
			{
			public:
				Cliente( const string & sIP, int iPuerto );
				virtual ~Cliente();
				
				int getPuerto();
				string getHost();
				
				virtual bool EsValido();

				virtual void EnviarMensaje( const string & sMensaje, string & sRespuesta );
				virtual void EnviarMensaje( const string & sMensaje );

			protected:
				int Recibir( string & sMensaje, int iMaxTam = 2048 );
				
			private:
				virtual void ExcepcionProducida( const exception & ex ) = 0;

			};

 			}
		}
	}
}


#endif