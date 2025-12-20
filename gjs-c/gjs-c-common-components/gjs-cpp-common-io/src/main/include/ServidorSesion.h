#ifndef _ORG_GJS_C_CC_CPP_SERVIDOR_SESION_H
#define _ORG_GJS_C_CC_CPP_SERVIDOR_SESION_H



#include <ServidorComandos.h>
#include <GestorUsuarios.h>
#include <GestorSesiones.h>
#include <SocketAbierto.h>



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ServidorSesion : public ServidorComandos
			{
			private:
				GestorUsuarios 	gestorUsuarios;
				GestorSesiones 	gestorSesiones;
				bool 			bSesionNecesaria = true;
				bool			bPermiteAnonimo = false;
				
			public:
				ServidorSesion( int iPuerto, const string & sRutaUsuarios = "", const string & sRutaContexto = "", bool _bPermiteAnonimo = false );
				virtual ~ServidorSesion();

				virtual bool EsValido();
			
			protected:
				bool RequiereSesion();
				
			private:
				void ProcesarComando( Comando & comando, bool & bResponder, string & sRespuesta, bool & bResultado, SocketAbierto * socket );

				virtual string MensajeSesionAbierta() = 0;
				virtual string MensajeSesionCerrada() = 0;
				virtual string MensajeFaltaClave() = 0;
				virtual string MensajeImposibleAperturaSesion() = 0;
				virtual string MensajeUsuarioInvalido() = 0;
				virtual string MensajeSesionNoAbierta() = 0;
				
				virtual bool EsComandoInicioSesion( Comando & comando, string & sUsuario, string & sClave ) = 0;
				virtual bool EsComandoFinSesion( Comando & comando ) = 0;
				virtual void SesionIniciada( const string & sUsuario ); 
				virtual void SesionFinalizada( const string & sUsuario ); 
				virtual void ProcesarComandoSesion( Comando & comando, bool & bResponder, string & sRespuesta, bool & bResultado, SocketAbierto * socket ) = 0;
				
			};

 			}
		}
	}
}


#endif