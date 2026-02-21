#ifndef _ORG_GJS_C_CC_CPP_COMMON_SYSTEM_CONFIG
#define _ORG_GJS_C_CC_CPP_COMMON_SYSTEM_CONFIG



#include <CppBase.h>


#include <CppCommonTypes.h>
#include <CppCommonIo.h>


#if ( defined ( CC ) ) // Asociado a UNIX:

#	include <ctype.h>
#	include <stdio.h>
#	include <unistd.h>
#	include <errno.h>
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <sys/param.h>
#	include <sys/dir.h>
#	include <sys/wait.h>
#	include <sys/resource.h>
#	include <sys/utsname.h>
#	if ( !defined ( errno ) )
#		define errno	(*_errno())
#	endif
//#		include <rld_interface.h>

#elif ( defined ( VC ) )  // Asociado a WIN o DOS:

#	if ( defined ( WIN ) )

#		include <winnt.h>
#		include <Tlhelp32.h>

#		if ( WINVER >= 0x500 )
#			include <Psapi.h>
#			include <Shlwapi.h>
#		endif

#		include <lm.h>

#	else

#		include <process.h>
#		define sleep		_sleep
#		undef INC_DIRECT
#		if ( !defined ( _STDC__ ) )
#			define _STDC__		0
#		endif

#	endif

#else // GNU:
#	if ( defined ( UNIX ) )

#		include <stdio.h>
#		include <unistd.h>
#		include <errno.h>
#		include <sys/types.h>
#		include <sys/stat.h>
#		include <sys/param.h>
#		include <sys/dir.h>
#		include <sys/wait.h>
#		include <sys/resource.h>
#		include <sys/utsname.h>
#		include <sys/mman.h>
#		if ( !defined ( errno ) )
#			define errno	(*_errno())
#		endif
#		include <pthread.h>
#		include <semaphore.h>
#		include <pwd.h>
#		include <grp.h>

#	elif ( defined ( LINUX ) )

#		include <stdio.h>
#		include <unistd.h>
#		include <errno.h>
#		include <sys/types.h>
#		include <sys/stat.h>
#		include <sys/param.h>
#		include <sys/dir.h>
#		include <sys/utsname.h>
#		include <linux/sched.h>
#		include <sys/mman.h>
#		if ( !defined ( errno ) )
#			define errno	(*_errno())
#		endif
#		include <pthread.h>
#		include <semaphore.h>
#		include <pwd.h>
#		include <grp.h>

#	elif ( defined ( WIN ) )

#		include <Tlhelp32.h>
#		include <Psapi.h>
#		include <Shlwapi.h>

#	else // Caso por defecto (DOS):

#		include <errno.h>
#		include <unistd.h>
#		include <sys/types.h>
#		include <sys/stat.h>
#		include <sys/param.h>
#		include <sys/dir.h>
#		include <sys/wait.h>
#		include <sys/resource.h>
#		include <sys/utsname.h>
#		include <sys/system.h>
#		include <sys/segments.h>
#		include <pthread.h>
// PENDIENTE: Para este caso hay que revisar lo que se puede y no puede hacer con threads:
#		if ( !defined ( pthread_t ) )
			typedef unsigned long int pthread_t;
#		endif
#		if ( !defined ( _defined_schedparam ) )
			struct _sched_param
			{
			    int _sched_priority;
			};
#		endif
#		if ( !defined ( pthread_attr_t ) )
			typedef struct _pthread_attr_s
			{
			  int _detachstate;
			  int _schedpolicy;
			  struct _sched_param _schedparam;
			  int _inheritsched;
			  int _scope;
			  size_t _guardsize;
			  int _stackaddr_set;
			  void *__stackaddr;
			  size_t _stacksize;
			} pthread_attr_t;
#		endif
#	endif

#endif

// El Kernel32.lib (y otros) junto con los *.h, de VC++ suelen estar obsoletos: algunas funciones hay que obtenerlas
// dinámicamente:
#if ( defined ( VC ) && defined ( WIN ) ) 
#	if ( defined ( OpenThread ) )
#		define OPENTHREAD_INDEFINIDO	
//#	if ( !defined ( OpenThread ) )
//WINBASEAPI HANDLE WINAPI OpenThread ( DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwThreadId );
#	endif
#	if ( !defined ( SwitchToThread ) )
WINBASEAPI BOOL WINAPI SwitchToThread ();
#	endif
#endif



#include <format>
#include <iostream>
#include <cstdlib>      // putenv, free
#include <cstring>      // strdup
#include <csignal>      // SIGSTKSZ, kill
#include <unistd.h>     // gethostname, get_current_dir_name
#include <limits.h>     // PATH_MAX



#include <SistemaTiposErrores.h>
#include <SistemaErrores.h>
#include <TiposSistema.h>
#include <Sistemas.h>
#include <Procesadores.h>




#define SIS_MAX_TAM_VARIABLE			255
#define SIS_MAX_TAM_VALOR				255

#define SIS_MAX_TAM_PATH				(MAXPATHLEN - 1)

#define SIS_ES_MAX_TAM_BUFFER			1024
#define SIS_SO_MAX_TAM_BUFFER			MAXPATHLEN

#define SIS_MAX_TAM_COMANDO				1023
#define SIS_MAX_TAM_PARAMS_COMANDO		8191

#define SIS_MAX_PROCESOS_HIJOS			-1 

#define SIS_TIEMPO_ESPERA_DEF			5000

#if ( defined ( WIN ) )
#	define SIS_MAX_TAM_VALOR_REG		SIS_MAX_TAM_PATH
#endif			

#define UID_CACHE_MAX       10          
#define GID_CACHE_MAX       10          



#endif
