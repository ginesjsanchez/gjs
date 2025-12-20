#include "MockServidorFTP.h"

#include "CppMockConfig.h"
#include "ContextoTest.h"



using namespace std;
using namespace org::gjs::cpp::common;
using namespace org::gjs::cpp::common::test;
using namespace org::gjs::cpp::common::log;


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

MockServidorFTP::MockServidorFTP( int iPuerto, int iPuertoDatos, const string & sSubdirectorioRaiz, const string & sFicheroUsuarios ) :
			ServidorFTP( iPuerto, iPuertoDatos, ResolverDirectorioRelativo( DirectorioTestRecursos(), sSubdirectorioRaiz ),
							ResolverDirectorioRelativo( DirectorioTestRecursos(), Concatenar( "data/", sFicheroUsuarios ) ) )
{
}

MockServidorFTP::~MockServidorFTP()
{
}

void MockServidorFTP::ComandoRecibido( Comando & comando )
{
	LogInfo ( Concatenar( "{SERVIDORFTP} Recibido comando [", comando.toString(), "]" ) );
}

void MockServidorFTP::ComandoProcesado( Comando & comando, bool & bResultado )
{
	LogInfo ( Concatenar( "{SERVIDORFTP} Procesado comando [", comando.toString(), "]" ) );
}

void MockServidorFTP::SesionIniciada( const string & sUsuario )
{
	LogInfo ( Concatenar( "{SERVIDORFTP} Inicio sesion de [", sUsuario, "]" ) );
}

void MockServidorFTP::SesionFinalizada( const string & sUsuario )
{
	LogInfo ( Concatenar( "{SERVIDORFTP} Fin sesion de [", sUsuario, "]" ) );
}

bool MockServidorFTP::ExcepcionProducida( exception & ex )
{
	LogError( "{SERVIDORFTP} Excepcion recibida", ex );
	return( true );
}

void MockServidorFTP::ExcepcionProducidaEnPeticion( exception & ex )
{
	LogError( "{SERVIDORFTP} Excepcion recibida", ex );
}

                    }
				}
 			}
		}
	}
}
