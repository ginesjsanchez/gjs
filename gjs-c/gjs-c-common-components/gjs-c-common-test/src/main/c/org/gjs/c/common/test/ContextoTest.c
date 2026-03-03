#include "ContextoTest.h"
#include "CTestConfig.h"


#define TEST_FIC_PROPIEDADES	"../internal/test.properties"

		
		
static SPropiedades * p_propContexto = NULL;		



void _PrepararContexto()
{
	if ( ES_NULO ( p_propContexto ) )
	{
		p_propContexto = SPropCrear ( TEST_FIC_PROPIEDADES );	

	}
}	

void _LiberarContexto()
{
	if ( ES_VALIDO ( p_propContexto ) )
	{
		SPropDestruir ( &p_propContexto );	
	}
}	
		
char * DirectorioProyecto()
{
	char * p_cDir;
	if ( ES_VALIDO ( p_propContexto ) )
	{
		if ( SPropExistePropiedad( p_propContexto, "project.basedir" ) == 1 )
		{
			p_cDir = CadDuplicar ( SPropObtPropiedad( p_propContexto, "project.basedir" ) );
		}
		else
		{
			p_cDir = NULL;
		}
	}
	else
	{
		p_cDir = NULL;
	}
	if ( CadLongitud ( p_cDir ) == 0 )
	{
		p_cDir = SisResolverDirectorioRelativo ( SisDirectorioActual(), "../../.." );
	}
	return ( p_cDir );
}

char * DirectorioTrabajo()
{
	char * p_cDir;
	if ( ES_VALIDO ( p_propContexto ) )
	{
		if ( SPropExistePropiedad( p_propContexto, "project.build.directory" ) == 1 )
		{
			p_cDir = CadDuplicar( SPropObtPropiedad( p_propContexto, "project.build.directory" ) );
		}
		else
		{
			p_cDir = NULL;
		}
	}
	else
	{
		p_cDir = NULL;
	}
	if ( CadLongitud ( p_cDir ) == 0 )
	{
		p_cDir = SisResolverDirectorioRelativo( SisDirectorioActual(), "../.." );
	}
	return ( p_cDir );
}
				
char * DirectorioTest()
{
	char * p_cDir = "..";
	if ( ES_VALIDO ( p_propContexto ) )
	{
		if ( SPropExistePropiedad( p_propContexto, "project.build.testDirectory" ) == 1 )
		{
			p_cDir = CadDuplicar( SPropObtPropiedad( p_propContexto, "project.build.testDirectory" ) );
		}
	}
	if ( CadLongitud ( p_cDir ) == 0 )
	{
		p_cDir = SisResolverDirectorioRelativo( SisDirectorioActual(), ".." );
	}
	return ( p_cDir );
}

char * DirectorioTestRecursos()
{
	char * p_cDir = DirectorioTest();
	char * p_cRes = SisResolverDirectorioRelativo( p_cDir, "resources" );
	MemLiberar( (void **) &p_cDir );
	return ( p_cRes );
}

char * DirectorioTestResultados()
{
	char * p_cDir = DirectorioTest();
	char * p_cRes = SisResolverDirectorioRelativo( p_cDir, "results" );
	MemLiberar( (void **) &p_cDir );
	return ( p_cRes );
}

