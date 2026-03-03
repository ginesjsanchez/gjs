#include "SCasoTestAislado.h"
#include "CTestConfig.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
// #include <fcntl.h>
                                                            

SCasoTestAislado * SCasTstaCrear ( const char * p_cId, PFUNINTV p_fTest, int iCodigoEsperado )
{
	SCasoTestAislado * p_caststObj;

	if ( CadEsToken ( p_cId ) && ES_VALIDO ( p_fTest ) )
	{
		p_caststObj = ( SCasoTestAislado * ) MemReservar ( sizeof ( SCasoTestAislado ) );
		if ( ES_VALIDO ( p_caststObj ) )
		{
			p_caststObj->p_caststObj = SCasTstCrear ( p_cId, p_fTest );
			p_caststObj->iCodigo = iCodigoEsperado;
		}
	}
	else
	{
		p_caststObj = NULL;
	}
	return ( p_caststObj );
}


void SCasTstaDestruir ( SCasoTestAislado ** p_p_caststObj )
{
	SCasoTestAislado * p_caststObj;

	if ( ES_VALIDO ( p_p_caststObj ) )
	{
		p_caststObj = *p_p_caststObj;
		if ( ES_VALIDO ( p_caststObj ) )
		{
			SCasTstDestruir ( &(p_caststObj->p_caststObj) );
		}
		*p_p_caststObj = NULL;
	}
}


int SCasTstaEjecutar ( SCasoTestAislado * p_caststObj )
{
	int iRes;

	if ( ES_VALIDO ( p_caststObj ) )
	{
		pid_t pid = fork ();
		if ( pid == -1 )
		{
			AplicLogAnotarError ( "No se ha podido lanzar el test. Error=%d", errno );
			iRes = RESULTADO_CASO_TEST_FAIL;
		}
		else if ( pid == 0 )
		{
			// sigset_t   set; 
			// sigemptyset( &set );                                                             
			// sigaddset( &set, SIGUSR1 );                                               
			// sigwait( &set );

			iRes = SCasTstEjecutar ( p_caststObj->p_caststObj );
			AplicLogAnotarAviso ( "El codigo del test ha terminado normalmente: puede que haya que implementarlo como CasoTest normal" );
			if ( iRes == RESULTADO_CASO_TEST_OK )
			{
				exit ( EXIT_SUCCESS );
			}
			else
			{
				exit ( EXIT_FAILURE );
			}
		}
		else
		{
			int iCodigoRecibido = 0;
			// kill( pid, SIGUSR1 );
			waitpid ( pid, &iCodigoRecibido, 0 );
			AplicLogAnotar ( "Proceso terminado con %s", WEXITSTATUS ( iCodigoRecibido ) );
			if ( WEXITSTATUS ( iCodigoRecibido ) == p_caststObj->iCodigo )
			{
				AplicLogAnotar ( "Caso terminado correctamente" );
			}
			else
			{
				iRes = RESULTADO_CASO_TEST_KO;
				AplicLogAnotarError ( "Caso terminado con error: se esperaba %d", p_caststObj->iCodigo );
			}
		}
	}
	else
	{
		iRes = RESULTADO_CASO_TEST_FAIL;
	}
	return ( iRes );
}

