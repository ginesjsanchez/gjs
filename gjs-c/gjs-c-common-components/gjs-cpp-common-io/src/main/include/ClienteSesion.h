#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_SESION_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_SESION_H




#include <ClienteComandos.h>
#include <ResultadoComando.h>
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


			class ClienteSesion : public ClienteComandos
			{
			private:
				string 	sUsuario;
				string 	sClave;
				bool 	bSesionNecesaria = true;
				bool	bSesionAbierta = false;
				
			public:
				ClienteSesion( const string & sIP, int iPuerto, const string & _sUsuario = "", const string & _sClave = "" );
				virtual ~ClienteSesion();
				
				string getUsuario();
				string getClave();
				void setUsuario( const string & _sUsuario, const string & _sClave = "" );
				void setUsuarioAnonimo();
				
				bool EsValido();

				bool SesionAbierta();
				bool AbrirSesion();
				void CerrarSesion();
				
				void EnviarComando( Comando & comando, string & sRespuesta );
				void EnviarComando( string sComando, const initializer_list<string> & lisArgumentos, string & sRespuesta );
				void EnviarMensaje( const string & sMensaje, string & sRespuesta );
				void EnviarMensaje( const string & sMensaje );

			private:
				void EstablecerUsuario( const string & _sUsuario, const string & _sClave, bool bConstructor );
				virtual void ModificadoUsuario() = 0; 
				virtual list<ResultadoComando> & ComandoInicioSesion() = 0;
				virtual ResultadoComando & ComandoFinSesion() = 0;

			};

 			}
		}
	}
}

#endif