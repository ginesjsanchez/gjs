/******************************************************************************/
/*                                Memoria.cpp                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* para reservar, liberar y trabajar con espacios de memoria.                 */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "Memoria.h"

#include "BaseErrores.h"
#include "Finalizacion.h"
#include "Errores.h"


//PENDIENTE: Adaptar a 64-bits




// Limites por defecto:
#if ( defined ( WIN ) )

#	define MEM_LIM_INF							0x000100000UL
#	define MEM_LIM_SUP							0x7FFFFFFFFUL

#elif ( defined ( UNIX ) )

#	define MEM_LIM_INF							0x0012D000UL
#	define MEM_LIM_SUP							0x7FFFFFFFUL

#elif ( defined ( LINUX ) )

#	define MEM_LIM_INF							0x0012D000UL
#	define MEM_LIM_SUP							0x7FFFFFFFUL

#else // DOS

#	define MEM_LIM_INF							0x0012D000UL
#	define MEM_LIM_SUP							0x7FFFFFFFUL
//#	define MEM_LIM_INF							0x0006000UL (NO SIMULADO)

#endif




/* Mensajes de error auxiliares par finalizar la ejecución: */
#define ERR_GRAVE_TXT_MEMORIA				"Error grave de memoria: se ha corrompido el 'heap' del proceso."






// OJO: Esto es provisional y para linux/unix no fiunciona!!!

static int		g_iBasMemIniciado = 0;
static void *	p_vBasMemMinDireccionEspProc = NULL;
static void *	p_vBasMemMaxDireccionEspProc = NULL;



static void	MemInicializar ();





#if ( defined ( MODO_DEPURACION ) )

extern void _MemBloqueReservado ( void * p_vDir, unsigned long ulTam );
extern void _MemBloqueLiberado ( void * p_vDir, unsigned long ulTam );

#endif




// Pendientew: Para el caso de WINDOWS una rutina que utilice HeapWalk para liberar todos los bloques de memoria pendientes
// de ser liberados:

//PENDIENTE: Info memoria: The HeapWalk function enumerates the memory blocks in a specified heap.



void * MemReservar ( int iNumBytes )
{
	void *	p_vBloque;
#  if ( defined ( WIN ) )
	HANDLE  hMem;
#  endif

	if ( iNumBytes > 0 )
	{
		MemInicializar ();

#	  if ( defined ( WIN ) )
		hMem = GetProcessHeap ();
		if ( hMem != NULL )
		{
			p_vBloque = (void *) HeapAlloc ( hMem, HEAP_ZERO_MEMORY, iNumBytes );
			if ( ES_VALIDO ( p_vBloque ) )
			{
#			  if ( defined ( MODO_DEPURACION ) )
				_MemBloqueReservado ( p_vBloque, (unsigned long) iNumBytes );
#			  endif
			}
			else
			{
				if ( HeapValidate ( hMem, 0, NULL ) == FALSE )
				{
					// Error grave por heap del proceso corrupto:
					ErrEstablecer ( ERR_MEMORIA_INVALIDA );
					FinalizarEjecucion ( ERR_GRAVE_TXT_MEMORIA );
				}
				else
				{
					ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
				}
			}
		}
		else
		{
			p_vBloque = NULL;
			ErrEstablecer ( ERR_MEMORIA_INVALIDA );
		}
#	  else
		p_vBloque = (void *) malloc ( iNumBytes );
		if ( ES_VALIDO ( p_vBloque ) )
		{
			memset ( p_vBloque, 0, iNumBytes );
#		  if ( defined ( MODO_DEPURACION ) )
			_MemBloqueReservado ( p_vBloque, (unsigned long) iNumBytes );
#		  endif
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
#	  endif
	}
	else
	{
		p_vBloque = NULL;
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( p_vBloque );
}

void * MemReservarVector ( int iNumElems, int iNumBytesElem )
{
	return ( MemReservar ( iNumElems * iNumBytesElem ) );
}

void * MemReservarTabla ( int iNumFilas, int iNumColumnas, int iNumBytesElem )
{
	return ( MemReservar ( iNumFilas * iNumColumnas * iNumBytesElem ) );
}

int MemRedimensionar ( void ** p_p_vBloque, int iNumBytes )
{
	void *	p_vBloque;
	int		iRes;
#  if ( defined ( WIN ) )
	HANDLE  hMem;
#  endif

	iRes = 0;
	if ( iNumBytes > 0 )
	{
		MemInicializar ();

		p_vBloque = *p_p_vBloque;

#	  if ( defined ( WIN ) )
		hMem = GetProcessHeap ();
		if ( hMem != NULL )
		{
			*p_p_vBloque = (void *) HeapReAlloc ( hMem, HEAP_ZERO_MEMORY, p_vBloque, iNumBytes );
			if ( ES_VALIDO ( *p_p_vBloque ) )
			{
				iRes = 1;
#			  if ( defined ( MODO_DEPURACION ) )
				_MemBloqueReservado ( *p_p_vBloque, (unsigned long) iNumBytes );
#			  endif
			}
			else
			{
				if ( HeapValidate ( hMem, 0, NULL ) == FALSE )
				{
					// Error grave por heap del proceso corrupto:
					ErrEstablecer ( ERR_MEMORIA_INVALIDA );
					FinalizarEjecucion ( ERR_GRAVE_TXT_MEMORIA );
				}
				else
				{
					ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
				}
			}
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INVALIDA );
		}
#	  else
		*p_p_vBloque = (void *) realloc ( p_vBloque, iNumBytes );
		if ( ES_VALIDO ( p_vBloque ) )
		{
			iRes = 1;
#		  if ( defined ( MODO_DEPURACION ) )
			_MemBloqueReservado ( p_vBloque, (unsigned long) iNumBytes );
#		  endif
		}
		else
		{
			ErrEstablecer ( ERR_MEMORIA_INSUFICIENTE );
		}
#	  endif
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iRes );
}

int MemLiberar ( void ** p_p_vBloque )
{
	int				iRes;
	void *			p_vBloque;
#  if ( defined ( WIN ) )
	HANDLE			hMem;
#  elif ( defined ( GNU ) )
	//mcheck_status	mchkInfo;
#  endif

	if ( ES_VALIDO ( p_p_vBloque ) && ( g_iBasMemIniciado == 1 ) )
	{
		p_vBloque = *p_p_vBloque;
		if ( MemEsValida ( p_vBloque ) == 1 )
		{
#		  if ( defined ( WIN ) )
			hMem = GetProcessHeap ();
			if ( hMem != NULL )
			{
				HeapFree ( hMem, 0, (LPVOID) p_vBloque );
#			  if ( defined ( MODO_DEPURACION ) )
				_MemBloqueLiberado ( p_vBloque, (unsigned long) iNumBytes );
#			  endif
				iRes = 1;
			}
			else
			{
				iRes = 0;
				//ErrEstablecer ( ERR_MEMORIA_INVALIDA );
			}
			*p_p_vBloque = NULL;

#		  elif ( defined ( GNU ) )

			iRes = 1;
			//iNumBytes = 0; // _msize ( p_vBloque );
			// NOTA: Parece que el las primeras versiones de libc.so.6 hay un Bug con
			// mprobe y mcheck:
			// mchkInfo = mprobe ( p_vBloque );
			// if ( mchkInfo == MCHECK_OK )
			// {
            free ( p_vBloque );
			// }
			//else
			//{
			//	FILE * f;
			//	f = fopen ( "aye.dat", "a" );
			//	fprintf (f, "ERROR DE DIR_MEM mchkInfo=%d\n", mchkInfo );
			//	fclose ( f );
			//}
			*p_p_vBloque = NULL;
#		  if ( defined ( MODO_DEPURACION ) )
 			_MemBloqueLiberado ( p_vBloque, (unsigned long) iNumBytes );
#		  endif

#		  else // DOS o UNIX (no GNU):
			iRes = 1;
			iNumBytes = 0; // _msize ( p_vBloque );
			free ( p_vBloque );
			*p_p_vBloque = NULL;
#		   if ( defined ( MODO_DEPURACION ) )
			_MemBloqueLiberado ( p_vBloque, (unsigned long) iNumBytes );
#		   endif
#		 endif
		}
		else
		{
			// Ya es un puntero nulo o no valido:
			iRes = 1;
			*p_p_vBloque = NULL;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int MemLiberarCadena ( char ** p_p_cCadena )
{
	return ( MemLiberar ( (void **) p_p_cCadena ) );
}

int MemLiberarUnicode ( unichar ** p_p_cCadena )
{
#  if ( defined ( WIN ) )
	int		iByte;
	int		iRes;
	void *	p_vBloque;
	byte *	p_byBloque;
	int		iNumBytes;
	HANDLE  hMem;

	if ( ES_VALIDO ( p_p_cCadena ) && ( g_iBasMemIniciado == 1 ) )
	{
		p_vBloque = (void *) *p_p_cCadena;
		if ( MemEsValida ( p_vBloque ) == 1 )
		{
			p_byBloque = (byte *) p_vBloque;
			if ( *(p_byBloque + 1) == 0x00 )
			{
				// Puede ser unicode:
				iByte = 0;
				while ( *(p_byBloque + iByte) != 0x00 )
				{
					*(p_byBloque + iByte + 1) = 0x20;
					iByte = iByte + 2;
				}
				*(p_byBloque + iByte) = 0x20;

				hMem = GetProcessHeap ();
				if ( hMem != NULL )
				{
					iNumBytes = HeapSize ( hMem, 0, (LPVOID) p_vBloque );
					if ( iNumBytes > 0 )
					{
						HeapFree ( hMem, 0, (LPVOID) p_vBloque );
#					  if ( defined ( MODO_DEPURACION ) )
				 		_MemBloqueLiberado ( p_vBloque, (unsigned long) iNumBytes );
#					  endif
						*p_p_cCadena = NULL;
						iRes = 1;
					}
					else
					{
						iRes = 0;
						//ErrEstablecer ( ERR_MEMORIA_INVALIDA );
					}
				}
				else
				{
					// No es unicode:
					iRes = MemLiberar ( (void **) p_p_cCadena );
				}
			}
			else
			{
				iRes = 0;
			}
		}
		else
		{
			// Ya es un puntero nulo o no valido:
			iRes = 1;
			*p_p_cCadena = NULL;
			//ErrEstablecer ( ERR_MEMORIA_INVALIDA );
		}
	}
	else
	{
		iRes = 0;
		//ErrEstablecer ( ERR_PARAMETROS );
	}
	return ( iRes );
# else
	return ( MemLiberar ( (void **) p_p_cCadena ) );
# endif
}

void MemLimpiar ( void * p_vBloque, int iNumBytes )
{
	if ( ( iNumBytes > 0 ) && ( MemEsValida ( p_vBloque ) == 1 ) )
	{
#	  if ( defined ( WIN ) )
		//if ( IsBadWritePtr ( p_vBloque, 1 ) == 0 )
		//{
		ZeroMemory ( (LPVOID) p_vBloque, iNumBytes  );
		//}
#	  else
		memset ( p_vBloque, 0, iNumBytes );
#	  endif
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
}

void MemLlenar ( void * p_vBloque, byte byValor, int iNumBytes )
{
	if ( ( iNumBytes > 0 ) && ( MemEsValida ( p_vBloque ) == 1 ) )
	{
#	  if ( defined ( WIN ) )
		FillMemory ( (LPVOID) p_vBloque, iNumBytes, byValor );
#	  else
		memset ( p_vBloque, byValor, iNumBytes );
#	  endif
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
}

void MemCopiar ( void * p_vDest, void * p_vOrig, int iNumBytes )
{
	if ( ( iNumBytes > 0 ) && ES_VALIDO ( p_vDest ) && ES_VALIDO ( p_vOrig ) &&
		 ( MemEsValida (  p_vDest ) == 1 ) )
	{
#	  if ( defined ( WIN ) )
		CopyMemory ( (LPVOID) p_vDest, (CONST VOID *) p_vOrig, iNumBytes  );
#	  else
		memcpy ( p_vDest, p_vOrig, iNumBytes );
#	  endif
	}
	else
	{
		ErrEstablecer ( ERR_PARAMETROS );
	}
}

// La idea es que retorna cierto si, y solo si, es una direccion del espacio 'heap' del proceso:
int MemEsValida ( void * p_vDireccion )
{
	int	iRes;

	if ( ES_VALIDO ( p_vDireccion ) )
	{
		if ( ( p_vDireccion >= p_vBasMemMinDireccionEspProc ) && ( p_vDireccion <= p_vBasMemMaxDireccionEspProc ) )
		{
#	  if ( defined ( VC ) )
			//if ( ( *((unsigned int *)p_vDireccion) != MEM_DIN_LIBERADA_2 ) &&
			//		( *((unsigned int *)p_vDireccion) != MEM_DIN_LIBERADA ) &&
			//		( *(((unsigned int *)p_vDireccion)+1) != MEM_DIN_LIBERADA_2 ) &&
			//		( *(((unsigned int *)p_vDireccion)+1) != MEM_DIN_LIBERADA ) &&
			//		( *(((unsigned int *)p_vDireccion)+2) != MEM_DIN_LIBERADA_2 ) &&
			//		( *(((unsigned int *)p_vDireccion)+2) != MEM_DIN_LIBERADA ) )
			//{
			//	iRes = 0;
			//}
			//else
			//{
			if ( IsBadReadPtr ( p_vDireccion, sizeof ( unsigned int ) ) == 0 )
			{
				iRes = 1;
			}
			else
			{
				iRes = 0;
			}
			//}
			//else
			//{
			//	iRes = 0;
			//}
#	  else
			iRes = 1;
#	  endif
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


/*
byte MemValorByte ( unsigned long ulDireccion )
{
	byte	byRes;
	byte *	p_byValor;

	p_byValor = (byte *) ulDireccion;
	if ( MemValida ( p_byValor ) == 1 )
	{
		byRes = * p_byValor;
	}
	else
	{
		byRes = 0x00;
	}
	return ( byRes );
}
*/

static void	MemInicializar ()
{
#  if ( defined ( WIN ) )
	SYSTEM_INFO		sysinfDatos;
#  elif ( ( defined ( UNIX ) || defined ( LINUX ) ) && !defined ( CYGWIN ) )
	struct rlimit	rlimDatos;
#  endif

	if ( g_iBasMemIniciado == 0 )
	{
#	  if ( defined ( WIN ) )

		GetSystemInfo ( &sysinfDatos );
		p_vBasMemMinDireccionEspProc = (void *) sysinfDatos.lpMinimumApplicationAddress;
		p_vBasMemMaxDireccionEspProc = (void *) sysinfDatos.lpMaximumApplicationAddress;

#	  elif (  ( defined ( UNIX ) || defined ( LINUX ) ) && !defined ( CYGWIN ) )

		if ( getrlimit ( RLIMIT_DATA, &rlimDatos ) == 0 )
		{
			p_vBasMemMinDireccionEspProc = (void *) rlim.rlim_min;
			p_vBasMemMaxDireccionEspProc = (void *) rlim.rlim_max;
		}
		else
		{
			p_vBasMemMinDireccionEspProc = (void *) MEM_LIM_INF;
			p_vBasMemMaxDireccionEspProc = (void *) MEM_LIM_SUP;
		}

#	  else

		p_vBasMemMinDireccionEspProc = (void *) MEM_LIM_INF;
		p_vBasMemMaxDireccionEspProc = (void *) MEM_LIM_SUP;

#	  endif

		g_iBasMemIniciado = 1;
	}
}






