#ifndef _ORG_GJS_C_CC_CPP_SERVIDOR_COMANDOS_H
#define _ORG_GJS_C_CC_CPP_SERVIDOR_COMANDOS_H



#include <Servidor.h>
#include <Comando.h>
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

			class ServidorComandos : public Servidor
			{
			public:
				ServidorComandos( int iPuerto, const string & sRutaContexto = "" );
				virtual ~ServidorComandos();

			private:
				void ProcesarMensaje( const string & sMensaje, bool & bResponder, string & sRespuesta, bool & bResultado, bool & bFin, SocketAtencion * socket );
				void PeticionRecibida(); 
				void PeticionFinalizada( bool bResultado ); 

				virtual string MensajeComandoFin() = 0;
				virtual string MensajeComandoInvalido() = 0;
				virtual string MensajeErrorSintactico() = 0;
				
				virtual void ComandoRecibido( Comando & comando );
				virtual void ComandoProcesado( Comando & comando, bool & bResultado );
				virtual bool EsComandoValido( Comando & comando ) = 0;
				virtual bool EsComandoFin( Comando & comando, bool & bResponder ) = 0;
				virtual void ProcesarComando( Comando & comando, bool & bResponder, string & sRespuesta, bool & bResultado, SocketAbierto * socket ) = 0;
				
			};

 			}
		}
	}
}


#endif