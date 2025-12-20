#ifndef _ORG_GJS_C_CC_CPP_CLIENTE_FTP_H
#define _ORG_GJS_C_CC_CPP_CLIENTE_FTP_H



#include <ClienteIETF.h>
#include <SocketCliente.h>
#include <PuertosIETF.h>


using namespace std;
using namespace org::gjs::cpp::common;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class ClienteFTP : private ClienteIETF
			{
			private:
				bool 			bModoActivo = false;
				bool 			bModoBinario = false;
				int				iPuertoDatos = 0;

			public:
				ClienteFTP ( const string & sIP, int iPuerto = IETF_PUERTO_FTP );
				ClienteFTP ( const string & sIP, int iPuerto, const string & _sUsuario, const string & _sClave = "" );
				virtual ~ClienteFTP ();

				bool EsValido();

				bool SesionAbierta();
				bool AbrirSesion();
				void CerrarSesion();

				bool isModoActivo();
				bool isModoPasivo();
				void setModoActivo( int iPuerto );
				void setModoPasivo();

				bool isAscii();
				bool isBinario();
				bool setAscii();
				bool setBinario();

				bool EstadoServidor( string & sResultado );
				bool PingServidor();
				string InfoSistemaServidor();

				string DirectorioRemoto();
				bool CambiarDirectorioRemoto( const string & sSubdirectorio );
				bool CrearDirectorioRemoto( const string & sSubdirectorio );

				bool ContenidoDirectorioRemoto( vector<string> & vecContenido );

				bool BajarFichero( const string & sFichero, const string & sRutaLocal );
				bool SubirFichero( const string & sFichero, const string & sRutaLocal );

			private:
				void PrepararSocketDatos();
				common::SocketCliente * AbrirSocketDatos();
				void CerrarSocketDatos( common::SocketCliente ** sockDatos );
				void ExcepcionProducida( const exception & ex );
			};

 			}
		}
	}
}


#endif
