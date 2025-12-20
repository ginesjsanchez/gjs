#ifndef _ORG_GJS_C_CC_CPP_SERVIDOR_IETF_H
#define _ORG_GJS_C_CC_CPP_SERVIDOR_IETF_H



#include <ServidorSesion.h>
#include <string>
#include <set>
#include <list>
#include <initializer_list>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ServidorIETF : public ServidorSesion
			{
			private:
				set<string> * 	setComandos = NULL;
			
			public:
				ServidorIETF( int iPuerto, const string & sRutaUsuarios = "", const string & sRutaContexto = "", bool _bPermiteAnonimo = false );
				ServidorIETF( int iPuerto, const list<string> & lisComandos, const string & sRutaUsuarios = "", const string & sRutaContexto = "",
								bool _bPermiteAnonimo = false );
				ServidorIETF( int iPuerto, const initializer_list<string> & lisComandos, const string & sRutaUsuarios = "", const string & sRutaContexto = "",
								bool _bPermiteAnonimo = false );
				virtual ~ServidorIETF();
			
				void addComando( const string & sComando );
				void addComandos( const list<string> & lisComandos );
				void addComandos( const initializer_list<string> & lisComandos );
				bool isComando( const string & sComando );

			protected:
				string MensajeOk();
				
				virtual bool EsComandoValido( Comando & comando );
				
			private:
				string MensajeComandoFin();
				string MensajeComandoInvalido();
				string MensajeErrorSintactico();
				string MensajeSesionAbierta();
				string MensajeSesionCerrada();
				string MensajeFaltaClave();
				string MensajeImposibleAperturaSesion();
				string MensajeUsuarioInvalido();
				string MensajeSesionNoAbierta();

				bool EsComandoFin( Comando & comando, bool & bResponder );
				bool EsComandoInicioSesion( Comando & comando, string & sUsuario, string & sClave );
				bool EsComandoFinSesion( Comando & comando );				
			};

 			}
		}
	}
}


#endif