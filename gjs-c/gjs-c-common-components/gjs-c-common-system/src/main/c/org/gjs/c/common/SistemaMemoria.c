/******************************************************************************/
/*                             SistemaMemoria.cpp                             */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* de carácter general de reserva y liberación de espacios de memoria.        */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "SistemaMemoria.h"


#include "SistemaConfig.h"



/*
getrlimit y setrlimit devuelve / establece el límite de recursos, respectivamente. resource debería ser uno de los siguientes: 
RLIMIT_CPU // tiempo de CPU en segundos 
RLIMIT_FSIZE // tamaño Máximo de fichero
RLIMIT_DATA // tamaño máximo de los datos 
RLIMIT_STACK // tamaño máximo de la pila
RLIMIT_CORE // tamaño máximo del fichero del núcleo 
RLIMIT_RSS // tamaño máximo de la parte 
                   residente (fija) 
RLIMIT_NPROC // núero máximo de procesos
RLIMIT_NOFILE // número máximo de ficheros abiertos 
RLIMIT_MEMLOCK // máximo espacio de direcciones fijado 
                   en memoria 
RLIMIT_AS // límite del espacio de direcciones 
(memoria virtual) 

struct rusage {
    struct timeval ru_utime; // user time used 
    struct timeval ru_stime; // system time used 
    long   ru_maxrss;        // maximum resident set size 
    long   ru_ixrss;         // integral shared memory size 
    long   ru_idrss;         // integral unshared data size 
    long   ru_isrss;         // integral unshared stack size 
    long   ru_minflt;        // page reclaims 
    long   ru_majflt;        // page faults 
    long   ru_nswap;         // swaps 
    long   ru_inblock;       // block input operations 
    long   ru_oublock;       // block output operations 
    long   ru_msgsnd;        // messages sent 
    long   ru_msgrcv;        // messages received 
    long   ru_nsignals;      // signals received 
    long   ru_nvcsw;         // voluntary context switches 
    long   ru_nivcsw;        // involuntary context switches 
};

*/



unsigned long SisMemoriaTotal ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwTotalVirtual;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rlimit	rlimInfo; 
	//struct rusage 	rusgInfo; 

	if ( getrlimit ( RLIMIT_DATA, &rlimInfo ) == 0 )
	{
		ulRes = rlimInfo.rlim_cur; 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

unsigned long SisMemoriaDisponible ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwAvailVirtual;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rlimit	rlimInfo; 
	struct rusage 	rusgInfo; 

	if ( ( getrusage ( RUSAGE_SELF, &rusgInfo ) == 0 ) &&
		 ( getrlimit ( RLIMIT_DATA, &rlimInfo ) == 0 ) )
	{
		ulRes = rlimInfo.rlim_cur - ( rusgInfo.ru_idrss + rusgInfo.ru_ixrss + rusgInfo.ru_isrss ); 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

unsigned long SisMemoriaOcupada ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) (lpmemstatInfo->dwTotalVirtual - lpmemstatInfo->dwAvailVirtual);
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rusage 	rusgInfo; 

	if ( getrusage ( RUSAGE_SELF, &rusgInfo ) == 0 ) 
	{
		ulRes = rusgInfo.ru_idrss + rusgInfo.ru_ixrss + rusgInfo.ru_isrss; 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

double SisMemoriaDisponiblePorc ()
{
	double			dRes;
	unsigned long   ulMemDisp;
	unsigned long   ulMemTotal;

	ulMemDisp = SisMemoriaDisponible ();
	ulMemTotal = SisMemoriaTotal ();
	dRes = (ulMemDisp * 100.0) / (ulMemTotal * 1.0 );
	return ( dRes );
}	

double SisMemoriaOcupadaPorc ()
{
	double			dRes;
	unsigned long   ulMemOcup;
	unsigned long   ulMemTotal;

	ulMemOcup = SisMemoriaOcupada ();
	ulMemTotal = SisMemoriaTotal ();
	dRes = (ulMemOcup * 100.0) / (ulMemTotal * 1.0 );
	return ( dRes );
}	

unsigned long SisMemoriaFisicaTotal ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwTotalPhys;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rlimit	rlimInfo; 
	//struct rusage 	rusgInfo; 

	if ( getrlimit ( RLIMIT_DATA, &rlimInfo ) == 0 )
	{
		ulRes = rlimInfo.rlim_cur; 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

unsigned long SisMemoriaFisicaDisponible ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwAvailPhys;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rlimit	rlimInfo; 
	struct rusage 	rusgInfo; 

	if ( ( getrusage ( RUSAGE_SELF, &rusgInfo ) == 0 ) &&
		 ( getrlimit ( RLIMIT_DATA, &rlimInfo ) == 0 ) )
	{
		ulRes = rlimInfo.rlim_cur - ( rusgInfo.ru_idrss + rusgInfo.ru_ixrss ); 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

unsigned long SisMemoriaFisicaOcupada ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) (lpmemstatInfo->dwTotalPhys - lpmemstatInfo->dwAvailPhys);
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	struct rusage 	rusgInfo; 

	if ( getrusage ( RUSAGE_SELF, &rusgInfo ) == 0 ) 
	{
		ulRes = rusgInfo.ru_idrss + rusgInfo.ru_ixrss; 
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# endif

	return ( ulRes );
}

unsigned long SisMemoriaFicPaginacionTotal ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwTotalPageFile;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	//PENDIENTE:
	ulRes = 0;
# endif

	return ( ulRes );
}

unsigned long SisMemoriaFicPaginacionDisponible ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) lpmemstatInfo->dwAvailPageFile;
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	//PENDIENTE:
	ulRes = 0;
# endif

	return ( ulRes );
}

unsigned long SisMemoriaFicPaginacionOcupada ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	LPMEMORYSTATUS lpmemstatInfo;

	lpmemstatInfo = (LPMEMORYSTATUS) HeapAlloc ( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof ( MEMORYSTATUS ) );
	if ( ES_VALIDO ( lpmemstatInfo ) )
	{
		GlobalMemoryStatus ( lpmemstatInfo );
		ulRes = (unsigned long) (lpmemstatInfo->dwTotalPageFile - lpmemstatInfo->dwAvailPageFile);
		HeapFree ( GetProcessHeap(), 0, lpmemstatInfo );
	}
	else
	{
		// Error:
		ulRes = 0;
	}
# else
	//PENDIENTE:
	ulRes = 0;
# endif

	return ( ulRes );
}


