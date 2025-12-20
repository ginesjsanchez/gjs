#ifndef _ORG_GJS_C_CC_CPP_URI_H
#define _ORG_GJS_C_CC_CPP_URI_H




#include <string>
#include <MapaVector.h>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class URI
			{
			private:
				string 							sProtocolo;
				string 							sDominio;
				string 							sPuerto;
				string 							sRuta;
				
				MapaVector<string> 				mapParametros;
				
			public:
				URI();
				explicit URI( const string & sURI );
				URI( const string & sURL, const string & sURN );
				virtual ~URI();
				
				string getProtocolo();
				void setProtocolo( const string & valor );
				string getDominio();
				void setDominio( const string & valor );
				string getPuerto();
				void setPuerto( const string & valor );
				string getRuta();
				void setRuta( const string & valor );
				void setParametros( const string & valor );
				const vector<string> & getParametros();
				bool ExisteParametro( const string & sNombre );
				string getValorParametro( const string & sNombre );
				void EliminarParametro( const string & sNombre );
				int NumParametros();
				void LimpiarParametros();
				void addParametro( const string & sNombre, const string & sValor );

				string toString();
				string getURL();
				string getURN();
				
				void setURI( const string & sURI );
				void setURI( const string & sURL, const string & sURN );
				
				bool EsValido();
				
			};

 			}
		}
	}
}


#endif