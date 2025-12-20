#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_IETF_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_IETF_H




#include <ClienteSesion.h>



using namespace std;
using namespace org::gjs::cpp::common;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			class ClienteIETF : public ClienteSesion
			{
			private:
				list<ResultadoComando> comandoApertura;
				ResultadoComando comandoCierre;

			public:
				ClienteIETF ( const string & sIP, int iPuerto );
				ClienteIETF ( const string & sIP, int iPuerto, const string & _sUsuario, const string & _sClave = "" );
				virtual ~ClienteIETF ();

			private:
				void ModificadoUsuario();
				list<ResultadoComando> & ComandoInicioSesion();
				ResultadoComando & ComandoFinSesion();

			};

 			}
		}
	}
}


#endif
