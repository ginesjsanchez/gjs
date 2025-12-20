#ifndef _ORG_GJS_C_CC_CPP_COMANDO_IETF_H
#define _ORG_GJS_C_CC_CPP_COMANDO_IETF_H



#include <Comando.h>
#include <CodigosIETF.h>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			class ComandoIETF : public Comando
			{
			public:
				ComandoIETF();
				ComandoIETF( const string & _sComando, const initializer_list<string> & lisArgumentos );
				ComandoIETF( const string & sExpresion );
				virtual ~ComandoIETF();

				virtual string toString();
			};

 			}
		}
	}
}


#endif