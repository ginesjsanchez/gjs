#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_COMANDOS_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_COMANDOS_H




#include <Cliente.h>
#include <Comando.h>
#include <list>



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ClienteComandos : public Cliente
			{
			public:
				ClienteComandos( const string & sIP, int iPuerto );
				virtual ~ClienteComandos();
				
				void EnviarComando( Comando & comando, string & sRespuesta );
				void EnviarComando( string sComando, const initializer_list<string> & lisArgumentos, string & sRespuesta );
				
			};

 			}
		}
	}
}

#endif