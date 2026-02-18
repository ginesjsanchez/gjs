/******************************************************************************/
/*                         SistemaSincronizacion.cpp                          */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* de carácter general que ofrecen diversas opciones de sincronización de     */
/* procesos e hilos.                                                          */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "SistemaSincronizacion.h"



#include "SistemaConfig.h"
#include "SistemaTiempo.h"



/*
CRITICAL_SECTION GlobalCriticalSection; 

InitializeCriticalSection(&GlobalCriticalSection); 

 
{
      EnterCriticalSection(&GlobalCriticalSection); 
                       // Access the shared resource.
}
finally 
{
                           // Release ownership of the critical section.
      LeaveCriticalSection(&GlobalCriticalSection);
}

*/

/*
LONG InterlockedCompareExchange( LONG volatile *Destination, LONG 
Exchange, LONG Comperand );
*/

int SisActivarVariableSinc ( varsinc * p_vsVariable )
{
	int	iRes;

	if ( ES_VALIDO ( p_vsVariable ) )
	{
#	  if ( defined ( WIN ) )
#	   if ( defined ( InterlockedCompareExchangePointer ) )
		if ( InterlockedCompareExchange ( p_vsVariable, 1, 0 ) == 0 )
#      else
		if ( InterlockedCompareExchange ( (PVOID *) p_vsVariable, (PVOID) 1, (PVOID) 0 ) == 0 )
#      endif
#	  else
		if ( pthread_spin_trylock ( p_vsVariable ) == 0 )
#	  endif
		{
			iRes = 1;
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisEsperarYActivarVariableSinc ( varsinc * p_vsVariable )
{
	int iRes;

	if ( ES_VALIDO ( p_vsVariable ) )
	{
#	  if ( defined ( WIN ) )
		while ( SisActivarVariableSinc ( p_vsVariable ) == 0 )
		{
			SisEsperar ( 1 );
		}
		iRes = 1;
#	  else
		pthread_spin_lock ( p_vsVariable );
#	  endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisDesactivarVariableSinc ( varsinc * p_vsVariable )
{
	int iRes;

	if ( ES_VALIDO ( p_vsVariable ) )
	{
#	  if ( defined ( WIN ) )
		InterlockedExchange ( p_vsVariable, 0 );
#	  else
		pthread_spin_unlock ( p_vsVariable );
#	  endif
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

#if ( !defined ( WIN ) )

void SisInicializarVariableSinc ( varsinc * p_vsVariable )
{
	if ( ES_VALIDO ( p_vsVariable ) )
	{
		pthread_spin_init ( p_vsVariable, PTHREAD_PROCESS_PRIVATE );
	}
}

void SisFinalizarVariableSinc ( varsinc * p_vsVariable )
{
	if ( ES_VALIDO ( p_vsVariable ) )
	{
		pthread_spin_destroy ( p_vsVariable );
	}
}

#endif


/*
> read_lock(&tasklist_lock);
> child = find_task_by_pid(pid);
> if (child)
> get_task_struct(child);
> read_unlock(&tasklist_lock);
*/

