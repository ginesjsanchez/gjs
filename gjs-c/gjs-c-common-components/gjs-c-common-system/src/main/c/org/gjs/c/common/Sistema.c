/******************************************************************************/
/*                                Sistema.cpp                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/
#include "Sistema.h"

#include "SistemaConfig.h"


extern void _SisLiberarVariable_g_p_cSisDirTemporal ();

# if ( ! defined ( WIN ) )
extern void SisProcInicializar ( const char * p_cNomProceso );
extern void SisProcFinalizar ();
#  endif


void SisInicializar ()
{
	SisInicializarExt ( NULL, NULL );
}

void SisInicializarExt ( const char * p_cNomProceso, const char * p_cDirTemporal )
{
	if ( ES_VALIDO ( p_cDirTemporal ) )
	{
		SisInicializarDirectorios ( p_cDirTemporal );
	}

	if ( ES_VALIDO ( p_cNomProceso ) )
	{
#	 if ( ! defined ( WIN ) )
		SisProcInicializar ( p_cNomProceso );
#	  endif
	}
}


void SisFinalizar ()
{
	SisErrLimpiar ();
	_SisLiberarVariable_g_p_cSisDirTemporal ();
# if ( ! defined ( WIN ) )
	SisProcFinalizar ();
#  endif
}


void SignalHandlerPorDefecto ( int signal )
{
	printf ( "INTERRUPCION RECIBIDA=%d\n", signal );
	//if ( signal == SIGABRT )
	//{
	//	RetornarAPrograma ();
	//}
}

//void GrabarRetornoAPrograma()
//{
//	_bRetornar = true;
//	setjmp( _entornoRetorno );
//}

//void RetornarAPrograma ()
//{
//	if ( _bRetornar )
//	{
//		_bRetornar = false;
//		cout << "retornando" << endl;
//		longjmp( _entornoRetorno, 1 );
//	}
//}

void SisEstablecerManejadorInterrupciones ( SIGNAL_HANDLER fManejador )
{
	signal( SIGTERM, fManejador );
	signal( SIGSEGV, fManejador );
	signal( SIGINT, fManejador );
	signal( SIGILL, fManejador );
	signal( SIGABRT, fManejador );
	signal( SIGFPE, fManejador );
}

void SisEstablecerManejadorInterrupcionesDefecto ()
{
	SisEstablecerManejadorInterrupciones( SignalHandlerPorDefecto );
}

void SisLimpiarManejadorInterrupciones ()
{
	SisEstablecerManejadorInterrupciones( NULL );
}




