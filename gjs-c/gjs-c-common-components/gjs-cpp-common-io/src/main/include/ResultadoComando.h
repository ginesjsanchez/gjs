#ifndef _ORG_GJS_C_CC_CPP_RESULTADO_COMANDO_H
#define _ORG_GJS_C_CC_CPP_RESULTADO_COMANDO_H



#include <string>
#include <Comando.h>
#include <ComandoIETF.h>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ResultadoComando : public Comando
			{
			private:
				string	sRespuesta;
				
			public:
				ResultadoComando();
				ResultadoComando( ComandoIETF & comando, const string & _sRespuesta );
				ResultadoComando( Comando & comando, const string & _sRespuesta );
				ResultadoComando( const string & _sComando, const initializer_list<string> & lisArgumentos, const string & _sRespuesta );
				ResultadoComando( const string & sExpresion, const string & _sRespuesta );
				virtual ~ResultadoComando();

				string & getRespuestaEsperada();
				void setRespuestaEsperada( const string & sValor );
			};

 			}
		}
	}
}

#endif