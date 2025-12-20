#ifndef _ORG_GJS_C_CC_CPP_SERVIDOR_H
#define _ORG_GJS_C_CC_CPP_SERVIDOR_H



#include <SocketServidor.h>
#include <SocketAtencion.h>
#include <Propiedades.h>
#include <Contador.h>
 





using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Servidor : private SocketServidor, public Contador 
			{				
			private:
				Propiedades 						contexto;
				bool								bEjecucion = false;
				bool								bParar = false;
				thread *							thServidor = NULL;
				
			public:
				Servidor( int iPuerto, const string & sRutaContexto = "" );
				virtual ~Servidor();
				
				int getPuerto();
				string getHost();
				virtual bool EsValido();

				void Iniciar();
				void Parar();				
				
			protected:
				Propiedades Contexto();
				int Enviar( const string & sMensaje );
				
			private:
				void RutinaAtencion();
				void RutinaPeticion( SocketAtencion * socket );
				
				virtual void PeticionRecibida(); 
				virtual void PeticionFinalizada( bool bResultado ); 
				virtual void ProcesarMensaje( const string & sMensaje, bool & bResponder, string & sRespuesta, bool & bResultado, bool & bFin, SocketAtencion * socket ) = 0;

			protected:
				virtual bool ExcepcionProducida( const exception & ex );
				virtual void ExcepcionProducidaEnPeticion( const exception & ex );
				
			};

 			}
		}
	}
}


#endif