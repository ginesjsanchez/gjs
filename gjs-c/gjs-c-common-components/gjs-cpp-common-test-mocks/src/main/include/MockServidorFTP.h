#ifndef _ORG_GJS_C_CC_CPP_TEST_MOCK_SERVIDOR_FTP_H
#define _ORG_GJS_C_CC_CPP_TEST_MOCK_SERVIDOR_FTP_H


#include <string>
#include <thread>


#include <Comando.h>
#include <ServidorFTP.h>


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
				namespace test
				{
                    namespace mock
                    {

class MockServidorFTP : public ServidorFTP
{
public:
	MockServidorFTP( int iPuerto, int iPuertoDatos, const string & sSubdirectorioRaiz, const string & sFicheroUsuarios = "usuarios.info" );

	virtual ~MockServidorFTP();

private:
	void ComandoRecibido( Comando & comando );
	void ComandoProcesado( Comando & comando, bool & bResultado );
	void SesionIniciada( const string & sUsuario );
	void SesionFinalizada( const string & sUsuario );
	bool ExcepcionProducida( exception & ex );
	void ExcepcionProducidaEnPeticion( exception & ex );

};

                    }
				}
 			}
		}
	}
}

#endif
