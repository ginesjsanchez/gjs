#include "STest.h"
#include "CTestConfig.h"

#include <signal.h>


extern void _PrepararContexto();
extern void _LiberarContexto();

		
static void SignalHandler( int signal )
{
    printf ( "RECIBIDA INTERRUPCION = %d", signal );
	exit ( -1 );
}		

static int _iEntornoTestInicializado = 0;

static void InicializarEntorno()
{
	if ( _iEntornoTestInicializado == 0 )
	{
		SisEstablecerManejadorInterrupciones( SignalHandler );
		_PrepararContexto();
		_iEntornoTestInicializado = 1;
	}
}
	

STest * STestCrear ( const char * p_cNombre, PPRCV procInicializar, PPRCV procFinalizar, PPRCT procInicializarCaso, PPRCT procFinalizarCaso )
{
	STest * p_testObj;

	p_testObj = ( STest * ) MemReservar ( sizeof ( STest ) );
	if ( ES_VALIDO ( p_testObj ) )
	{
		AplicLogFinalizar ( NULL );
		// TODO: Establecer metodología estándar de definición de Log en test: 1) buscar un xml de definicion en un /config...
		AplicLogActivarSalidaPorConsola ();
		p_testObj->p_cNombreTest = CadDuplicar ( p_cNombre );
		p_testObj->p_lisCasos = SLispCrear ();
		p_testObj->procInicializarTest = procInicializar;
		p_testObj->procFinalizarTest = procFinalizar;
		p_testObj->procInicializarCasoTest = procInicializarCaso;
		p_testObj->procFinalizarCasoTest = procFinalizarCaso;
		p_testObj->p_cDirInicial = NULL;
		InicializarEntorno ();
	}
	return ( p_testObj );
}

void STestDestruir ( STest ** p_p_testObj ) 
{
	STest * p_testObj;

	if ( ES_VALIDO ( p_p_testObj ) )
	{
		p_testObj = *p_p_testObj;
		if ( ES_VALIDO ( p_testObj ) )
		{
			for ( int i = 0; i < SLispNumElementos ( p_testObj->p_lisCasos ); i = i + 1 )
			{
				SCasoTest * p_caststObj = (SCasoTest *) SLispElemento ( p_testObj->p_lisCasos, i );
				SCasTstDestruir ( &p_caststObj );
			}
			SLispDestruir ( &( p_testObj->p_lisCasos ) );
			MemLiberar ( (void *) &( p_testObj->p_cNombreTest) );
		}
		*p_p_testObj = NULL;
	}
	AplicLogFinalizar ( "Test finalizado." );
}

void STestInicializar ( STest * p_testObj )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		AplicLogAnotar ( "" );
		AplicLogAnotar ( "* Iniciando test %s:", p_testObj->p_cNombreTest );
		p_testObj->p_cDirInicial = SisDirectorioActual ();
		if ( ES_VALIDO ( p_testObj->procInicializarTest ) )
		{
			p_testObj->procInicializarTest ();
		}
	}
}

void STestFinalizar ( STest * p_testObj )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		if ( p_testObj->procFinalizarTest != NULL )
		{
			p_testObj->procFinalizarTest ();
		}
		SisEstDirectorioActual ( p_testObj->p_cDirInicial );
		_LiberarContexto ();
		AplicLogAnotar ( "" );
		AplicLogAnotar ( "* Test %s finalizado.", p_testObj->p_cNombreTest );
	}
}

void STestInicializarCaso( STest * p_testObj, const char * p_cId )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		if ( ES_VALIDO ( p_testObj->procInicializarCasoTest ) )
		{
			p_testObj->procInicializarCasoTest ( p_cId );
		}
	}
}

void STestFinalizarCaso( STest * p_testObj, const char * p_cId )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		if ( ES_VALIDO ( p_testObj->procFinalizarCasoTest ) )
		{
			p_testObj->procFinalizarCasoTest ( p_cId );
		}
	}
}

void STestNuevoCaso( STest * p_testObj, const char * p_cNombre, PFUNINTV p_fTest )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		SLispInsertar ( p_testObj->p_lisCasos, (byte *) SCasTstCrear ( p_cNombre, p_fTest ) );
	}
}

void STestNuevoCasoAislado( STest * p_testObj, const char * p_cNombre, PFUNINTV p_fTest, int iCodigoEsperado )
{
	if ( ES_VALIDO ( p_testObj ) )
	{
		SLispInsertar ( p_testObj->p_lisCasos, ( byte * ) SCasTstaCrear ( p_cNombre, p_fTest, iCodigoEsperado ) );
	}
}

int STestNumCasos( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = SLispNumElementos ( p_testObj->p_lisCasos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


int STestEjecutar( STest * p_testObj )
{
	int iRes;
	int iResCaso;

	if ( ES_VALIDO ( p_testObj ) )
	{
		p_testObj->iResultado = 0;
		p_testObj->iEjecutados = 0;
		p_testObj->iCorrectos = 0;
		p_testObj->iErroneos = 0;
		p_testObj->iFallidos = 0;
		iRes = 1;
		STestInicializar( p_testObj );
		for ( int i = 0; i < SLispNumElementos ( p_testObj->p_lisCasos ); i = i + 1 )
		{
			SCasoTest * p_caststObj = (SCasoTest *) SLispElemento ( p_testObj->p_lisCasos, i );
			AplicLogAnotar ( "" );
			STestInicializarCaso ( p_testObj, SCasTstObtenerId ( p_caststObj )  );
			iResCaso = SCasTstEjecutar ( p_caststObj );
			STestFinalizarCaso ( p_testObj, SCasTstObtenerId ( p_caststObj ) );
			p_testObj->iEjecutados = p_testObj->iEjecutados + 1;
			if ( iResCaso == RESULTADO_CASO_TEST_OK )
			{
				p_testObj->iCorrectos = p_testObj->iCorrectos + 1;
			}
			else if ( iResCaso == RESULTADO_CASO_TEST_KO )
			{
				p_testObj->iErroneos = p_testObj->iErroneos + 1;
				iRes = 0;
			}
			else
			{
				p_testObj->iFallidos = p_testObj->iFallidos + 1;
				iRes = 0;
			}
		}
		STestFinalizar ( p_testObj );
	}
	else
	{
		iRes = 0;
	}
	AplicLogAnotar ( "" );
	AplicLogAnotar ( "Ejecutados = %ld/%ls; Correctos = %ld; Erroneos = %ld; Fallidos = &ld", 
		p_testObj->iEjecutados, p_testObj->iCorrectos, p_testObj->iErroneos, p_testObj->iFallidos );
	AplicLogAnotar ( "" );
	if ( iRes == 1 ) 
	{
		AplicLogAnotar( "Test terminado correctamente" );
	}
	else
	{
		AplicLogAnotar( "Test terminado con erorres" );
	}
	AplicLogAnotar ( "" );
	p_testObj->iResultado = iRes;
	return( iRes );
}		

int STestResultado ( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = p_testObj->iResultado;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STestCasosEjecutados ( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = p_testObj->iEjecutados;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STestCasosCorrectos ( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = p_testObj->iCorrectos;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STestCasosErroneos ( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = p_testObj->iErroneos;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int STestCasosFallidos ( STest * p_testObj )
{
	int iRes;

	if ( ES_VALIDO ( p_testObj ) )
	{
		iRes = p_testObj->iFallidos;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

		
