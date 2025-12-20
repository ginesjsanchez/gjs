#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_HTTP_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_HTTP_H



#include <ClienteIETF.h>
#include <HTTPConstantes.h>
#include <PuertosIETF.h>


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

			class ClienteHTTP : private ClienteIETF
			{
			private:
				string sURL;
				string sVersion;

			public:
				ClienteHTTP ( const string & sIP, int iPuerto = IETF_PUERTO_HTTP, const string & _sVersion = HTTP_VERSION_1_1 );
				virtual ~ClienteHTTP ();

				bool EsValido();

				bool Head( const string & sURN, const string & sRutaLocal );
				bool Get( const string & sURN, const string & sRutaLocal );
				bool Post( const string & sURN, const string & sRutaLocal );

			private:
				void ExcepcionProducida( const exception & ex );
			};

 			}
		}
	}
}

#endif
