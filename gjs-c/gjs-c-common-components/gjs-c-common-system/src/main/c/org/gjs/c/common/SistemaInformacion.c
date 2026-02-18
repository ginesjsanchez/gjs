/*                           SistemaInformacion.cpp                           */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la algunas      */
/* rutinas generales de información del sistema.                              */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/



#include "SistemaInformacion.h"

#include "SistemaTiempo.h"
#include "SContadorCiclos.h"
#include "TiposSistema.h"

#include "SistemaConfig.h"

#include <TiposSistema.h>


static char * g_p_cSisDirTemporal = NULL;





int SisTipo ()
{
	int iRes;

# if ( defined ( WIN ) )
	iRes = TIP_SIS_WINDOWS;
# elif ( defined ( UNIX ) )
	iRes = TIP_SIS_UNIX;
# elif ( defined ( LINUX ) )
	iRes = TIP_SIS_LINUX;
# elif ( defined ( MACKINTOSH ) )
	iRes = TIP_SIS_MACKINTOSHKINTOSH;
# else // DOS
	iRes = TIP_SIS_DOS;
# endif
	return ( iRes );
}

int SisSistema ()
{
	int iRes;

# if ( defined ( WIN ) )
	OSVERSIONINFO osinfDatos;

	if ( GetVersionEx ( &osinfDatos ) != 0 )
	{
		if ( osinfDatos.dwPlatformId == VER_PLATFORM_WIN32s ) 
		{
			// Win32s on Windows 3.1.  
			iRes = SIS_WINDOWS_32S;
		}
		else if ( osinfDatos.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS ) 
		{
			// Win32 on Windows 95 or Windows 98. For Windows 95, dwMinorVersion is zero.
			//For Windows 98, dwMinorVersion is greater than zero. 
			if ( osinfDatos.dwMajorVersion == 4 )
			{
				if ( osinfDatos.dwMinorVersion == 0 ) 
				{
					iRes = SIS_WINDOWS_95;
				}
				else if ( osinfDatos.dwMinorVersion == 10 ) 
				{
					iRes = SIS_WINDOWS_98;
				}
				else
				{
					iRes = SIS_DESCONOCIDO;
				}
			}
			else
			{
				iRes = SIS_DESCONOCIDO;
			}
		}
		else if ( osinfDatos.dwPlatformId == VER_PLATFORM_WIN32_NT ) 
		{
			// Win32 on Windows NT. 
			if ( osinfDatos.dwMajorVersion == 4 ) // The operating system is Windows NT 4.0, Windows Me, Windows 98, or Windows 95. 
			{
				if ( osinfDatos.dwMinorVersion == 0 ) 
				{
					iRes = SIS_WINDOWS_NT;
				}
				else if ( osinfDatos.dwMinorVersion == 90 ) // Windows Me
				{
					iRes = SIS_WINDOWS_ME;
				}
				else
				{
					iRes = SIS_DESCONOCIDO;
				}
			}
			else if ( osinfDatos.dwMajorVersion == 5 ) // The operating system is Windows Server 2003 R2, Windows Server 2003, Windows XP, or Windows 2000. 
			{
				if ( osinfDatos.dwMinorVersion == 1 ) // Windows XP
				{
					iRes = SIS_WINDOWS_XP;
				}
				else if ( osinfDatos.dwMinorVersion == 2 ) // Windows Server 2003 R2, Windows Server 2003, or Windows XP Professional x64 Edition.
				{
					iRes = SIS_WINDOWS_2003;
				}
				else
				{
					iRes = SIS_DESCONOCIDO;
				}
			}
			else if ( osinfDatos.dwMajorVersion == 6 ) // The operating system is Windows Vista or Windows Server "Longhorn". 
			{
				if ( osinfDatos.dwMinorVersion == 0 ) // Windows Vista, Windows Server "Longhorn"
				{
					iRes = SIS_WINDOWS_VISTA;
				}
				else
				{
					iRes = SIS_DESCONOCIDO;
				}
			}
			else
			{
				iRes = SIS_DESCONOCIDO;
			}
		}
		else
		{
			iRes = SIS_DESCONOCIDO;
		}
 	}
	else
	{
		iRes = SIS_DESCONOCIDO;
	}
# else 
	iRes = SIS_DESCONOCIDO;
# endif
	return ( iRes );
}

double SisVersion ()
{
	double dRes;

# if ( defined ( WIN ) )
	double			dMult;
	OSVERSIONINFO	osinfDatos;

	if ( GetVersionEx ( &osinfDatos ) != 0 )
	{
		dMult = MatExponencialConExponenteEntero ( 0.1, NumDigitosEnteroLargoSinSigno ( (unsigned long) osinfDatos.dwMinorVersion ) );
		dRes = osinfDatos.dwMajorVersion * 1.0 + osinfDatos.dwMinorVersion * dMult;
	}
	else
	{
		dRes = 0.0;
	}
# else 
	dRes = 0.0;
# endif
	return ( dRes );
}

int SisEsDos ()
{
	return ( TipSisEsDOS ( SisTipo () ) );
}

int SisEsWindows ()
{
	return ( TipSisEsWindows ( SisTipo () ) );
}

int SisEsLinux ()
{
	return ( TipSisEsLinux ( SisTipo () ) );
}

int SisEsUnix ()
{
	return ( TipSisEsUnix ( SisTipo () ) );
}

int SisEsMackintosh ()
{
	return ( TipSisEsMacKintosh ( SisTipo () ) );
}

int SisIntegraGUI ()
{
	int iRes;

	if ( SisEsWindows () == 1 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return (  iRes );
}

int SisPermiteBifurcarProcesos ()
{
	int iRes;

	if ( ( SisEsUnix () == 1 ) || ( SisEsLinux () == 1 ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return (  iRes );
}
/* DETERMINAR TIPO GENE¨RICO:

 


	iEjecComando = 0;

# else
#  if ( ! defined ( UNIX ) )
	struct utsname	utsnInfo;
#  endif
	struct tm *		p_tmFecha;
	time_t			timFecha;
	int				iSisDetec;

	// Por la fecha se pueden reconocer si es DOS o UNIX, y diferentes versiones de LINUX/UNIX:
	iOrdenBytes = -1;
	iAdmiteSubprocesos = 0;
	iSisDetec = 0;
	iSistema = TIP_SIS_DESCONOCIDO;
	iTipo = SIS_TIP_SO_DESCONOCIDO;

	timFecha = 0;
	p_tmFecha = localtime ( &timFecha );
	lFechaInicial = ( 1900 + p_tmFecha->tm_year ) * 10000 + ( p_tmFecha->tm_mon + 1 ) * 100 + p_tmFecha->tm_mday;

	if ( system ( NULL ) != 0 )
	{
		iEjecComando = 1;
	}
	else
	{
		iEjecComando = 0;
	}

	if ( lFechaInicial == _CSISTEMA_FEC_INI_MAC )
	{
		iTipo = SIS_TIP_SO_MAC;
		iSistema = TIP_SIS_MACKINTOSH;
		iSisDetec = 1;
	}
	else if ( lFechaInicial == _CSISTEMA_FEC_INI_WIN32 )
	{
		iTipo = SIS_TIP_SO_IBM_PC;
		iSistema = TIP_SIS_WINDOWS;
		iSisDetec = 1;
	}
	else if ( lFechaInicial == _CSISTEMA_FEC_INI_DOS )
	{
		// Puede ser cualquier DOS o WIN16:
	}
	else if ( lFechaInicial == _CSISTEMA_FEC_INI_IBM )
	{
		// Puede ser cualquier cosa (OS/2...) y también hay una version de MAC:
	}
	else if ( lFechaInicial == _CSISTEMA_FEC_INI_UNIX )
	{
		// También puede ser LINUX, el simulador de DOS de las últminas versiones de WINDOWS
	}

	if ( iSisDetec == 0 )
	{
#	  if ( !defined ( UNIX ) )
		if ( uname ( &utsnInfo ) != -1 )
		{
			if ( lFechaInicial == _CSISTEMA_FEC_INI_UNIX )
			{
				if ( _EstaEnLista ( utsnInfo.sysname, _p_p_cVersionesDos ) == 1 )
				{
					iTipo = SIS_TIP_SO_IBM_PC;
					iSistema = TIP_SIS_DOS;
				}
				else
				{
					iTipo = SIS_TIP_SO_IBM_PC;
					iSistema = TIP_SIS_WINDOWS;
				}
			}
			else if ( lFechaInicial == _CSISTEMA_FEC_INI_UNIX )
			{
				if ( _EstaEnLista ( utsnInfo.sysname, _p_p_cVersionesDos ) == 1 )
				{
					iTipo = SIS_TIP_SO_IBM_PC;
					iSistema = TIP_SIS_DOS;
				}
				else if ( _EstaEnLista ( utsnInfo.sysname, _p_p_cVersionesLinux ) == 1 )
				{
					iTipo = SIS_TIP_SO_IBM_PC;
					iSistema = TIP_SIS_LINUX;
				}
				else
				{
					iTipo = SIS_TIP_SO_UNIX;
					iSistema = TIP_SIS_UNIX;
				}
			}
			else
			{
				if ( _EstaEnLista ( utsnInfo.sysname, _p_p_cVersionesLinux ) == 1 )
				{
					iTipo = SIS_TIP_SO_IBM_PC;
					iSistema = TIP_SIS_LINUX;
				}
				else if ( _EstaEnLista ( utsnInfo.sysname, _p_p_cVersionesUNIX ) == 1 )
				{
					iTipo = SIS_TIP_SO_UNIX;
					iSistema = TIP_SIS_UNIX;
				}
			}
		}
#	  endif
*/
/*
    DWORD dwActiveProcessorMask;
    DWORD dwProcessorType;
Windows NT: 
This member is no longer relevant, but is retained for compatibility with Windows 95 and previous versions of Windows NT. Use the wProcessorArchitecture, wProcessorLevel, and wProcessorRevision members to determine the type of processor. 

  PROCESSOR_INTEL_386 
PROCESSOR_INTEL_486 
PROCESSOR_INTEL_PENTIUM 
Windows NT: PROCESSOR_MIPS_R4000 
Windows NT: PROCESSOR_ALPHA_21064 

    WORD wProcessorLevel;
Windows 95: This member is not used. 
Windows NT: Specifies the system's architecture-dependent processor level. 
If wProcessorArchitecture is PROCESSOR_ARCHITECTURE_MIPS, wProcessorLevel is of the form 00xx, where xx is an 8-bit implementation number (bits 8-15 of the PRId register). The member can be the following value: Value Meaning 
0004 MIPS R4000 



If wProcessorArchitecture is PROCESSOR_ARCHITECTURE_ALPHA, wProcessorLevel is of the form xxxx, where xxxx is a 16-bit processor version number (the low-order 16 bits of a version number from the firmware). The member can be one of the following values: Decimal Value Meaning 
21064  Alpha 21064 
21066 Alpha 21066 
21164 Alpha 21164 



If wProcessorArchitecture is PROCESSOR_ARCHITECTURE_PPC, wProcessorLevel is of the form xxxx, where xxxx is a 16-bit processor version number (the high-order 16 bits of the Processor Version Register). The member can be one of the following values: Decimal Value Meaning 
1  PPC 601 
3 PPC 603 
4 PPC 604 
6 PPC 603+ 
9 PPC 604+ 
20 PPC 620 

    WORD wProcessorRevision;
Windows 95: This member is not used. 
Windows NT: Specifies an architecture-dependent processor revision. The following table shows how the revision value is assembled for each type of processor architecture. Processor Architecture Value 
Intel 80386 or 80486 A value of the form xxyz. 
If xx is equal to 0xFF, y - 0xA is the model number, and z is the stepping identifier. For example, an Intel 80486-D0 system returns 0xFFD0.

If xx is not equal to 0xFF, xx + 'A' is the stepping letter and yz is the minor stepping. 
 
Intel Pentium, 
Cyrix, or 
NextGen 586 A value of the form xxyy, where xx is the model number and yy is the stepping. For example, a value of 0x0201 indicates Model 2, Stepping 1. 
MIPS A value of the form 00xx, where xx is the 8-bit revision number of the processor (the low-order 8 bits of the PRId register). 
ALPHA A value of the form xxyy, where xxyy is the low-order 16 bits of the processor revision number from the firmware. Display this value as follows: 
Model 'A'+xx, Pass yy
 
PPC A value of the form xxyy, where xxyy is the low-order 16 bits of the Processor Version Register. Display this value as a fixed point number:
xx.yy
 

*/
int SisArquitecturaProcesador ()
{
	int iRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL )
	{
		iRes = PROC_ARQ_INTEL;
	}
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_MIPS )
	{
		iRes = PROC_ARQ_MIPS;
	}
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ALPHA )
	{
		iRes = PROC_ARQ_ALPHA;
	}
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_PPC )
	{
		iRes = PROC_ARQ_PPC;
	}
	else
	{
		iRes = PROC_ARQ_DESCONOCIDO;
	}
# else
	// PENDIENTE:
	iRes = PROC_ARQ_DESCONOCIDO;
# endif
	return ( iRes );
}

int SisArquitecturaProcesadorEsIntel ()
{
	int iRes;

	if ( SisArquitecturaProcesador () == PROC_ARQ_INTEL )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisArquitecturaProcesadorEsMIPS ()
{
	int iRes;

	if ( SisArquitecturaProcesador () == PROC_ARQ_MIPS )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisArquitecturaProcesadorEsAlpha ()
{
	int iRes;

	if ( SisArquitecturaProcesador () == PROC_ARQ_ALPHA )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisArquitecturaProcesadorEsPPC ()
{
	int iRes;

	if ( SisArquitecturaProcesador () == PROC_ARQ_PPC )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisProcesador ()
{
	int iRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL )
	{
		if ( sysinfDatos.wProcessorLevel == 3 )
		{
			iRes = PROC_INTEL_80386;
		}
		else if ( sysinfDatos.wProcessorLevel == 4 )
		{
			iRes = PROC_INTEL_80486;
		}
		else if ( sysinfDatos.wProcessorLevel == 5 )
		{
			iRes = PROC_INTEL_PENTIUM;
		}
		else
		{
			iRes = PROC_DESCONOCIDO;
		}
	}	
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_MIPS )
	{
		if ( sysinfDatos.wProcessorLevel == 4 )
		{
			iRes = PROC_MIPS_R4000;
		}
		else
		{
			iRes = PROC_DESCONOCIDO;
		}
	}
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ALPHA )
	{
		if ( sysinfDatos.wProcessorLevel == 21064 )
		{
			iRes = PROC_ALPHA_21064;
		}
		else if ( sysinfDatos.wProcessorLevel == 21064 )
		{
			iRes = PROC_ALPHA_21066;
		}
		else if ( sysinfDatos.wProcessorLevel == 21164 )
		{
			iRes = PROC_ALPHA_21164;
		}
		else
		{
			iRes = PROC_DESCONOCIDO;
		}
	}
	else if ( sysinfDatos.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_PPC )
	{
		if ( sysinfDatos.wProcessorLevel == 1 )
		{
			iRes = PROC_PPC_601;
		}
		else if ( sysinfDatos.wProcessorLevel == 3 )
		{
			iRes = PROC_PPC_603;
		}
		else if ( sysinfDatos.wProcessorLevel == 4 )
		{
			iRes = PROC_PPC_604;
		}
		else if ( sysinfDatos.wProcessorLevel == 6 )
		{
			iRes = PROC_PPC_603_PLUS;
		}
		else if ( sysinfDatos.wProcessorLevel == 9 )
		{
			iRes = PROC_PPC_604_PLUS;
		}
		else if ( sysinfDatos.wProcessorLevel == 20 )
		{
			iRes = PROC_PPC_620;
		}
		else
		{
			iRes = PROC_DESCONOCIDO;
		}
	}
	else
	{
		iRes = PROC_DESCONOCIDO;
	}
# else
	// PENDIENTE:
	iRes = PROC_DESCONOCIDO;
# endif
	return ( iRes );
}

int SisNumProcesadores ()
{
	int iRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	iRes = (int) sysinfDatos.dwNumberOfProcessors;
# else
	// PENDIENTE:
	iRes = -1;
# endif
	return ( iRes );
}

int SisProcesadorPuedeFallarPuntoFlotante ()
{
	int iRes;

# if ( defined ( WIN ) )
	if ( IsProcessorFeaturePresent ( PF_FLOATING_POINT_PRECISION_ERRATA ) != 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
# else
	// PENDIENTE:
	iRes = 0;
# endif
	return ( iRes );
}

int SisProcesadorEmulaPuntoFlotante ()
{
	int iRes;

# if ( defined ( WIN ) )
	if ( IsProcessorFeaturePresent ( PF_FLOATING_POINT_EMULATED ) != 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
# else
	// PENDIENTE:
	iRes = 0;
# endif
	return ( iRes );
}

int SisProcesadorAdmiteMMX ()
{
	int iRes;

# if ( defined ( WIN ) )
	if ( IsProcessorFeaturePresent ( PF_MMX_INSTRUCTIONS_AVAILABLE ) != 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
# else
	// PENDIENTE:
	iRes = 0;
# endif
	return ( iRes );
}

int SisProcesadorAdmiteInstruccionesDeBytesAlpha ()
{
	int iRes;

# if ( defined ( WIN ) )
	if ( IsProcessorFeaturePresent ( PF_ALPHA_BYTE_INSTRUCTIONS ) != 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
# else
	// PENDIENTE:
	iRes = 0;
# endif
	return ( iRes );
}

unsigned long SisTamPagina ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	ulRes = (unsigned long) sysinfDatos.dwPageSize;
# else
	ulRes = (unsigned long) getpagesize ();
# endif
	return ( ulRes );
}

unsigned long SisMemTamBloqueMinimo ()
{
	unsigned long ulRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	ulRes = (unsigned long) sysinfDatos.dwAllocationGranularity;
# else
	ulRes = (unsigned long) getpagesize ();
# endif
	return ( ulRes );
}

void * SisMemAplicDireccionMinima ()
{
	void * p_vRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	p_vRes = (void *) sysinfDatos.lpMinimumApplicationAddress;
# else
	// PENDIENTE:
	p_vRes = NULL;
# endif
	return ( p_vRes );
}

void * SisMemAplicDireccionMaxima ()
{
	void * p_vRes;

# if ( defined ( WIN ) )
	SYSTEM_INFO sysinfDatos;
	
	GetSystemInfo ( &sysinfDatos );
	p_vRes = (void *) sysinfDatos.lpMaximumApplicationAddress;
# else
	// PENDIENTE:
	p_vRes = NULL;
# endif
	return ( p_vRes );
}

/*
const char * SisDirectorioSistema ()
{
	const char * p_cRes;
	SBuffer	*		p_bufDatos;
	
	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
#	 if ( defined ( WIN ) )
		if ( GetSystemDirectory ( (LPTSTR) SBufDireccion ( p_bufDatos ), (UINT) SBufTam ( p_bufDatos ) ) > 0 )
#	 else
		// PENDIENTE:
#	 endif
		{
			p_cRes = SBufDuplicarCadena ( p_bufDatos );
		}
		else
		{
			p_cRes = NULL;
		}
		SBufDestruir ( &p_bufDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}
*/

#if ( defined ( WIN ) || defined ( DOS ) )
const char * SisDirectorioSistema ()
{
	const char * p_cRes;
	SBuffer	*		p_bufDatos;
	
	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
#	 if ( defined ( WIN ) )
		if ( GetWindowsDirectory ( (LPTSTR) SBufDireccion ( p_bufDatos ), (UINT) SBufTam ( p_bufDatos ) ) > 0 )
#	 else
		// PENDIENTE para DOS:
		if ( 0 )
#	 endif
		{
			p_cRes = SBufDuplicarCadena ( p_bufDatos );
		}
		else
		{
			p_cRes = NULL;
		}
		SBufDestruir ( &p_bufDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}
#endif

const char * SisDirectorioTemporal ()
{
	const char * p_cRes;
#if ( defined ( WIN ) || !defined ( DOS ) )
	SBuffer	*		p_bufDatos;
#endif
	
#if ( defined ( WIN ) || !defined ( DOS ) )
	if ( ES_VALIDO ( g_p_cSisDirTemporal ) )
	{
		p_cRes = CadDuplicar ( g_p_cSisDirTemporal );
	}
	else
	{
		p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
		if ( ES_VALIDO ( p_bufDatos ) )
		{
#		 if ( defined ( WIN ) )
			if ( GetTempPath ( (DWORD) SBufTam ( p_bufDatos ), (LPTSTR) SBufDireccion ( p_bufDatos ) ) > 0 )
#		 else
				// PENDIENTE:
			if ( 0 )
#		 endif
			{
				p_cRes = SBufDuplicarCadena ( p_bufDatos );
			}
			else
			{
				p_cRes = NULL;
			}
			SBufDestruir ( &p_bufDatos );
		}
		else
		{
			p_cRes = NULL;
		}
	}
#else
	p_cRes = CadDuplicar ( g_p_cSisDirTemporal );
#endif
	return ( p_cRes );
}

double SisVelocidadCPU ()
{
	double				dRes = 0.0;
	SContadorCiclos *	p_cntcCPU;
	int64_t				i64Valor;
	int64_t				i64Resto;
	
	p_cntcCPU = SConCicCrear ();
	SConCicIniciar ( p_cntcCPU );
# if ( defined ( WIN ) )
	Sleep(1000);
# else
	sleep ( 1 );
# endif
	SConCicParar ( p_cntcCPU );
	i64Valor = SConCicValor ( p_cntcCPU ) / 100000;
	i64Resto = SConCicValor ( p_cntcCPU ) % 100000;
    dRes = ((double) i64Valor) + 0.00001 * ((double) i64Resto);
	return ( dRes );
}

void SisInicializarDirectorios ( const char * p_cDirTemporal )
{
	MemLiberarCadena ( &g_p_cSisDirTemporal );
	g_p_cSisDirTemporal = CadDuplicar ( p_cDirTemporal );
	if ( SisExisteDirectorio ( g_p_cSisDirTemporal ) == 0 )
	{
		SisCrearDirectorio ( g_p_cSisDirTemporal );
	}
}



void _SisLiberarVariable_g_p_cSisDirTemporal ()
{
	MemLiberar ( (void **) &g_p_cSisDirTemporal );
}



/*
static void detect_os()
{
   __dpmi_regs r;
   char buf[16];
   char *p;
   int i;

   al_os_type = OSTYPE_UNKNOWN;

   // check for Windows 3.x or 9x 
   r.x.ax = 0x1600; 
   __dpmi_int(0x2F, &r);

   if ((r.h.al != 0) && (r.h.al != 1) && (r.h.al != 0x80) && (r.h.al != 0xFF)) {
      al_os_version = r.h.al;
      al_os_revision = r.h.ah;
      al_os_is_multitasking = TRUE;

      if (al_os_version == 4) {
         if (al_os_revision == 90)
            al_os_type = OSTYPE_WINME;
         else if (al_os_revision == 10)
            al_os_type = OSTYPE_WIN98;
	 else
            al_os_type = OSTYPE_WIN95;
      }
      else
	 al_os_type = OSTYPE_WIN3;

      al_i_love_bill = TRUE;
      return;
   }

   // check for Windows NT 
   p = getenv("OS");

   if (((p) && (stricmp(p, "Windows_NT") == 0)) || (_get_dos_version(1) == 0x0532)) {
      al_os_type = OSTYPE_WINNT;
      al_os_is_multitasking = TRUE;
      al_i_love_bill = TRUE;
      return;
   }

   // check for OS/2 
   r.x.ax = 0x4010;
   __dpmi_int(0x2F, &r);

   if (r.x.ax != 0x4010) {
      if (r.x.ax == 0)
	 al_os_type = OSTYPE_WARP;
      else
	 al_os_type = OSTYPE_OS2;

      al_os_is_multitasking = TRUE;
      al_i_love_bill = TRUE;
      return;
   }

   // check for Linux DOSEMU 
   _farsetsel(_dos_ds);

   for (i=0; i<8; i++) 
      buf[i] = _farnspeekb(0xFFFF5+i);

   buf[8] = 0;

   if (!strcmp(buf, "02/25/93")) {
      r.x.ax = 0;
      __dpmi_int(0xE6, &r);

      if (r.x.ax == 0xAA55) {
	 al_os_type = OSTYPE_DOSEMU;
	 al_os_is_multitasking = TRUE;
	 al_i_love_bill = TRUE;     // (evil chortle) 
	 return;
      }
   }

   // check if running under OpenDOS 
   r.x.ax = 0x4452;
   __dpmi_int(0x21, &r);

   if ((r.x.ax >= 0x1072) && !(r.x.flags & 1)) {
      al_os_type = OSTYPE_OPENDOS;

      // now check for OpenDOS EMM386.EXE 
      r.x.ax = 0x12FF;
      r.x.bx = 0x0106;
      __dpmi_int(0x2F, &r);

      if ((r.x.ax == 0) && (r.x.bx == 0xEDC0)) {
	 al_i_love_bill = TRUE;
      }

      return;
   }

   // check for that stupid win95 "stealth mode" setting 
   r.x.ax = 0x8102;
   r.x.bx = 0;
   r.x.dx = 0;
   __dpmi_int(0x4B, &r);

   if ((r.x.bx == 3) && !(r.x.flags & 1)) {
      al_os_type = OSTYPE_WIN95;
      al_os_is_multitasking = TRUE;
      al_i_love_bill = TRUE;
      return;
   }

   // fetch DOS version if pure DOS is likely to be the running OS 
   if (al_os_type == OSTYPE_UNKNOWN) {
      r.x.ax = 0x3000;
      __dpmi_int(0x21, &r);
      al_os_version = r.h.al;
      al_os_revision = r.h.ah;
   }
}

BOOL SystemParametersInfo(
  UINT uiAction, // system parameter to query or set
  UINT uiParam,  // depends on action to be taken
  PVOID pvParam, // depends on action to be taken
  UINT fWinIni   // user profile update flag
);


*/

