/******************************************************************************/
/*                            SistemaLibrerias.cpp                            */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* de carácter general de información acerca de los procesos en ejecución,    */
/* así como algunas rutinas de gestión de los mismos.                         */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "SistemaLibrerias.h"


#include "SistemaConfig.h"





/*
typedef struct _DllVersionInfo
{
	DWORD cbSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformID;
} DLLVERSIONINFO;
#endif

#ifndef DLLGETVERSIONPROC
	typedef int (FAR WINAPI *DLLGETVERSIONPROC) (DLLVERSIONINFO *);
#endif

*/





int SisLibCargar ( const char * p_cLibreria )
{
	int			iRes;

# if ( defined ( WIN ) )
	HMODULE		hmodLib;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
		if ( SisLibEstaCargada ( p_cLibreria ) == 0 )
		{
#		  if ( defined ( WIN ) )
			hmodLib = LoadLibrary ( p_cLibreria );
			if ( hmodLib != NULL )
			{
				iRes = 1;
			}
			else
			{
				iRes = 0;
			}
#		  else
			// PENDIENTE:
			iRes = 0;
#	      endif
		}
		else
		{
			iRes = 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisLibEstaCargada ( const char * p_cLibreria )
{
	int		iRes;

# if ( defined ( WIN ) )
	HMODULE	hmodLib;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
#	  if ( defined ( WIN ) )
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			FreeLibrary ( hmodLib );
			iRes = 1;
		}
		else
		{
			iRes = 0;
		}
#	  else
			// PENDIENTE:
		iRes = 0;
#     endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

void * SisLibPrimitiva ( const char * p_cLibreria, const char * p_cPrimitiva )
{
	void *		p_vRes;

# if ( defined ( WIN ) )
	HMODULE		hmodLib;
# endif

	if ( ES_VALIDO ( p_cLibreria ) && ES_VALIDO ( p_cPrimitiva ) )
	{
#	  if ( defined ( WIN ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			p_vRes = (void *) GetProcAddress ( hmodLib, p_cPrimitiva );
			FreeLibrary ( hmodLib );
		}
		else
		{
			p_vRes = NULL;
		}
#	  else
		// PENDIENTE:
		p_vRes = NULL;
#	  endif
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

#if ( defined ( CPP ) )
CListaCadenas * SisLibCargadas ()
{
	CListaCadenas *	p_liscadLibrerias;
 	SBuffer	*		p_bufLibrerias;
 	SBuffer	*		p_bufNombre;

# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
	int				iError;
	int				iNumLibs;
	int				iLib;
	char *		p_cNombre;
	HANDLE			hProceso;
	HMODULE *		p_hmodLib;
	DWORD			dwTamOcupado;
#endif

 	p_bufLibrerias = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
 	p_bufNombre = SBufCrear ( MAXPATHLEN );
	if ( ES_VALIDO ( p_bufLibrerias ) && ES_VALIDO ( p_bufNombre ) )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		hProceso = OpenProcess ( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId () );
		if ( hProceso != NULL )
		{
			p_hmodLib = (HMODULE *) p_bufLibrerias->Direccion ();
			// PENDIENTE: Puede ser que sea necesario más tamaño (comprobar caso SBufTam ( p_bufDatos )== dwTamOcupado):
			if ( EnumProcessModules ( hProceso, p_hmodLib, (DWORD) p_bufLibrerias->Tam (), &dwTamOcupado ) != 0 )
			{
				iNumLibs = dwTamOcupado / sizeof ( DWORD );
				iLib = 0;
				iError = 0;
				p_liscadLibrerias = new CListaCadenas ();
				if ( ES_VALIDO ( p_liscadLibrerias ) )
				{
					while ( ( iLib < iNumLibs ) && ( iError == 0 ) )
					{
						if ( p_hmodLib [ iLib ] != 0 )
						{
							p_bufNombre->Limpiar ();
							if ( GetModuleBaseName ( hProceso, p_hmodLib [ iLib ], (LPTSTR)p_bufNombre->Direccion (), (DWORD) (p_bufNombre->Tam ()) / sizeof ( char ) ) > 0 )
							{
								p_cNombre = p_bufNombre->DuplicarCadena ();
								if ( ES_VALIDO  ( p_cNombre ) )
								{
									if ( p_liscadLibrerias->Insertar ( p_cNombre ) == 0 )
									{
										iError = 1;
									}
								}
								else
								{
									iError = 1;
								}
							}
							else
							{
								iError = 1;
							}
						}
						iLib = iLib + 1;
					}
					if ( iError == 1 )
					{
						DESTRUIR ( CListaCadenas, p_liscadLibrerias );
					}
				}
			}
			else
			{
				p_liscadLibrerias = NULL;
			}
			CloseHandle ( hProceso );
		}
		else
		{
			p_liscadLibrerias = NULL;
		}
# else
		// PENDIENTE:
		p_liscadLibrerias = NULL;
# endif
	}
	else
	{
		p_liscadLibrerias = NULL;
	}
	SBufDestruir ( &p_bufLibrerias );
	SBufDestruir ( &p_bufNombre );
	return ( p_liscadLibrerias );
}
#endif

char * SisLibRutaFichero ( const char * p_cLibreria )
{
	char *		p_cRes;
 	SBuffer	*	p_bufDatos;
	int			iLibOk;

# if ( defined ( WIN ) )
	int			iTam;
	HMODULE		hmodLib;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
#	  if ( defined ( WIN ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			iLibOk = 1;
		}
		else
		{
			iLibOk = 0;
		}
#	  else
		// PENDIENTE:
		iLibOk = 0;
#	  endif
	}
	else
	{
		iLibOk = 0;
	}

	if ( iLibOk == 1 )
	{
 		p_bufDatos = SBufCrear ( MAXPATHLEN );
		if ( ES_VALIDO ( p_bufDatos ) )
		{

	# if ( defined ( WIN ) )
			iTam = (int) GetModuleFileName ( hmodLib, (LPTSTR) SBufDireccion ( p_bufDatos ), ((DWORD) SBufTam ( p_bufDatos )) / sizeof ( char ) );
			if ( iTam > 0 )
			{
				p_cRes = SBufDuplicarCadena ( p_bufDatos );
			}
			else
			{
				p_cRes = NULL;
			}
			FreeLibrary ( hmodLib );
	# else
		// PENDIENTE:
			p_cRes = NULL;
	# endif
			SBufDestruir ( &p_bufDatos );
		}
		else
		{
			p_cRes = NULL;
		}
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

char * SisLibDirectorioFichero ( const char * p_cLibreria )
{
	const char * p_cRuta;
	char * p_cRes;

	p_cRuta = SisLibRutaFichero ( p_cLibreria );
	if ( ES_VALIDO ( p_cRuta ) )
	{
		p_cRes = SisRutaDirectorio ( p_cRuta );
		MemLiberar ( (void **) &p_cRuta );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

char * SisLibFichero ( const char * p_cLibreria )
{
	char * p_cRuta;
	char * p_cRes;

	p_cRuta = SisLibRutaFichero ( p_cLibreria );
	if ( ES_VALIDO ( p_cRuta ) )
	{
		p_cRes = SisRutaFichero ( p_cRuta );
		MemLiberar ( (void **) &p_cRuta );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

void * SisLibRutinaPuntoDeEntrada ( const char * p_cLibreria )
{
	void *		p_vRes;
	int			iLibOk;

# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
	HMODULE		hmodLib;
	_MODULEINFO modinfLib;
	HANDLE		hProceso;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			iLibOk = 1;
		}
		else
		{
			iLibOk = 0;
		}
#	  else
		// PENDIENTE:
		iLibOk = 0;
#	  endif
	}
	else
	{
		iLibOk = 0;
	}

	if ( iLibOk == 1 )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		hProceso = OpenProcess ( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId () );
		if ( hProceso != NULL )
		{
			if ( GetModuleInformation ( hProceso, hmodLib, &modinfLib, sizeof ( _MODULEINFO ) ) != 0 )
			{
				p_vRes = modinfLib.EntryPoint;
			}
			else
			{
				p_vRes = NULL;
			}
			CloseHandle ( hProceso );
		}
		else
		{
			p_vRes = NULL;
		}
		FreeLibrary ( hmodLib );
	# else
		// PENDIENTE:
			p_vRes = NULL;
	# endif
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

void * SisLibDireccionMemoria ( const char * p_cLibreria )
{
	void *		p_vRes;
	int			iLibOk;

# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
	HMODULE		hmodLib;
	_MODULEINFO modinfLib;
	HANDLE		hProceso;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			iLibOk = 1;
		}
		else
		{
			iLibOk = 0;
		}
#	  else
		// PENDIENTE:
		iLibOk = 0;
#	  endif
	}
	else
	{
		iLibOk = 0;
	}

	if ( iLibOk == 1 )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		hProceso = OpenProcess ( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId () );
		if ( hProceso != NULL )
		{
			if ( GetModuleInformation ( hProceso, hmodLib, &modinfLib, sizeof ( _MODULEINFO ) ) != 0 )
			{
				p_vRes = modinfLib.lpBaseOfDll;
			}
			else
			{
				p_vRes = NULL;
			}
			CloseHandle ( hProceso );
		}
		else
		{
			p_vRes = NULL;
		}
		FreeLibrary ( hmodLib );
#	  else
		// PENDIENTE:
			p_vRes = NULL;
#	  endif
	}
	else
	{
		p_vRes = NULL;
	}
	return ( p_vRes );
}

unsigned long SisLibTamMemoria ( const char * p_cLibreria )
{
	unsigned long	ulRes;
	int				iLibOk;

# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
	HMODULE		hmodLib;
	_MODULEINFO modinfLib;
	HANDLE		hProceso;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			iLibOk = 1;
		}
		else
		{
			iLibOk = 0;
		}
#	  else
		// PENDIENTE:
		iLibOk = 0;
#	  endif
	}
	else
	{
		iLibOk = 0;
	}

	if ( iLibOk == 1 )
	{
# if ( ( defined ( WIN ) ) && ( defined ( _PSAPI_H_ ) ) )
		hProceso = OpenProcess ( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId () );
		if ( hProceso != NULL )
		{
			if ( GetModuleInformation ( hProceso, hmodLib, &modinfLib, sizeof ( _MODULEINFO ) ) != 0 )
			{
				ulRes = (unsigned long) modinfLib.SizeOfImage;
			}
			else
			{
				ulRes = 0;
			}
			CloseHandle ( hProceso );
		}
		else
		{
			ulRes = 0;
		}
		FreeLibrary ( hmodLib );
	# else
		// PENDIENTE:
			ulRes = 0;
	# endif
	}
	else
	{
		ulRes = 0;
	}
	return ( ulRes );
}

char * SisLibCadenaVersion ( const char * p_cLibreria )
{
	char *	p_cRes;
	int		iVersion;
	int		iSubversion;
	int		iRevision;
	int		iCorreccion;

	if ( SisLibVersion ( p_cLibreria, &iVersion, &iSubversion, &iRevision, &iCorreccion ) == 1 )
	{
		p_cRes = VersCadena ( iVersion, iSubversion, iRevision, iCorreccion );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SisLibVersion ( const char * p_cLibreria, int * p_iVersion, int * p_iSubversion, int * p_iRevision, int * p_iBug )
{
	int					iRes;
	int					iLibOk;

# if ( defined ( WIN ) )
	HMODULE				hmodLib;
    DLLGETVERSIONPROC	p_fDllGetVersion;
    DLLVERSIONINFO		dllverinfDatos;
	HRESULT				hresEjec;
# endif

	if ( ES_VALIDO ( p_cLibreria ) )
	{
#	  if ( defined ( WIN ) )
		//hmodLib = LoadLibrary ( p_cLibreria );
		hmodLib = GetModuleHandle ( p_cLibreria );
		if ( hmodLib != NULL )
		{
			iLibOk = 1;
		}
		else
		{
			iLibOk = 0;
		}
#	  else
		// PENDIENTE:
		iLibOk = 0;
#	  endif
	}
	else
	{
		iLibOk = 0;
	}

	if ( iLibOk == 1 )
	{
	# if ( defined ( WIN ) )

        p_fDllGetVersion = (DLLGETVERSIONPROC) GetProcAddress ( hmodLib, "DllGetVersion" );
        if ( ES_VALIDO ( p_fDllGetVersion ) )  
        {
            ZeroMemory ( &dllverinfDatos, sizeof ( dllverinfDatos ) );
            dllverinfDatos.cbSize = sizeof ( dllverinfDatos );
            hresEjec = (*p_fDllGetVersion)( &dllverinfDatos );

            if( SUCCEEDED ( hresEjec ) )  
            {
				if ( ES_VALIDO ( p_iVersion ) )
				{
					*p_iVersion = (int) dllverinfDatos.dwMajorVersion;
				}
				if ( ES_VALIDO ( p_iSubversion ) )
				{
	                *p_iSubversion = (int) dllverinfDatos.dwMinorVersion;
				}
				if ( ES_VALIDO ( p_iRevision ) )
				{
		            *p_iRevision = (int) dllverinfDatos.dwBuildNumber;
				}
				//iCorreccion = (int) dllverinfDatos.dw
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
		FreeLibrary ( hmodLib );
	# else
		// PENDIENTE:
		iRes = 0;
	# endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

