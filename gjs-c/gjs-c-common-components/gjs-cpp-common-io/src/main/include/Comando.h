#ifndef _ORG_GJS_C_CC_CPP_COMANDO_H
#define _ORG_GJS_C_CC_CPP_COMANDO_H



#include <string>
#include <vector>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Comando
			{
			private:
				string 			sComando;
				vector<string>	vecArgumentos;
				
			public:
				Comando();
				Comando( const string & _sComando, const initializer_list<string> & lisArgumentos );
				Comando( const string & sExpresion );
				virtual ~Comando();

				virtual bool EsValido();
				
				const string & getComando();
				void setComando( const string & sValor );
				bool isComando( const string & sValor );
				
				int NumArgumentos() const;
				const string & getArgumento( int iArg );
				void addArgumento( const string & sArgumento );
				
				void Inicializar();
				void InicializarArgumentos();
				void Asignar( const string & _sComando, const initializer_list<string> & lisArgumentos );
				void Procesar( const string & sExpresion );
				
				virtual string toString();

			};

 			}
		}
	}
}


#endif