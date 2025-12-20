#ifndef _ORG_GJS_C_CC_CPP_SERVIDOR_HTTP_H
#define _ORG_GJS_C_CC_CPP_SERVIDOR_HTTP_H



#include <ServidorIETF.h>
#include <HTTPConstantes.h>

#include <filesystem>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ServidorHTTP : private ServidorIETF
			{
			private:
				// TODO: conjunto de versiones soportadas
				string 				sVersion;
				string 				sDirectorioRaiz;
				filesystem::path 	pathDirectorioRaiz;
				
			public:
				ServidorHTTP( const string & sDirectorio, const string & _sVersion = HTTP_VERSION_1_1, const string & sRutaContexto = "" );
				ServidorHTTP( int iPuerto, const string & sDirectorio, const string & _sVersion = HTTP_VERSION_1_1, const string & sRutaContexto = "" );
				virtual ~ServidorHTTP();
				
				int getPuerto();
				bool EsValido();

				void Iniciar();
				void Parar();				
				
			private:
				void ComandoRecibido( Comando & comando ) = 0;
				void ComandoProcesado( Comando & comando, bool & bResultado ) = 0;
				void SesionIniciada( const string & sUsuario );
				void SesionFinalizada( const string & sUsuario );

				bool EsComandoValido( Comando & comando );
				void ProcesarComandoSesion( Comando & comando, bool & bResponder, string & sRespuesta, bool & bResultadoProcesarComandoSesion, SocketAbierto * socket );
				
			};

 			}
		}
	}
}


#endif