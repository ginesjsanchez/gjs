/******************************************************************************/
/*                               SistemaRed.cpp                               */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la algunas      */
/* rutinas generales de información de red.                                   */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/



#include "SistemaRed.h"

#include "SistemaConfig.h"






char * SisRedNombreOrdenador ()
{
	char *		p_cRes;
	SBuffer	*	p_bufDatos;
# if ( defined ( WIN ) )
	DWORD			dwTam;
# else
	int				iTam;
# endif	

	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
#	 if ( defined ( WIN ) )
		dwTam = (DWORD) SBufTam ( p_bufDatos );
		if ( GetComputerName ( (LPTSTR) SBufDireccion ( p_bufDatos ), (LPDWORD) &dwTam ) > 0 )
#	 else
		iTam = SBufTam ( p_bufDatos );
		if ( gethostname ( (char *) SBufDireccion ( p_bufDatos ), iTam ) == 0 )
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

char * SisRedNombreDNSOrdenador ()
{
	char *		p_cRes;
	SBuffer	*	p_bufDatos;
# if ( defined ( WIN ) )
	DWORD			dwTam;
# endif	
	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
#	 if ( defined ( WIN ) )
		// PENDIENTE:
		dwTam = (DWORD) SBufTam ( p_bufDatos );
		//if ( GetComputerNameEx ( ComputerNameDnsHostname, (LPTSTR) SBufDireccion ( p_bufDatos ), (LPDWORD) &dwTam ) > 0 )
		if ( 0 )
#	 else
		// PENDIENTE:
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

// PENDIENTE: La siguiente rutina no parce funcionar.
int SisRedEnviarMensaje ( const char * p_cDestino, const char * p_cOrigen, const char * p_cMensaje )
{
	int		iRes;
# if ( defined ( WIN ) )
	DWORD		dwTam;
	DWORD		dwRes;
	unichar *	p_cDestUnicode;
	unichar *	p_cOrigUnicode;
# endif	
	if ( ES_VALIDO ( p_cDestino ) && ES_VALIDO ( p_cOrigen ) && ES_VALIDO ( p_cMensaje ) )
	{
#	 if ( defined ( WIN ) )
		p_cDestUnicode = CadAsciizAUnicode ( p_cDestino );
		p_cOrigUnicode = CadAsciizAUnicode ( p_cOrigen );
		if ( ES_VALIDO ( p_cDestUnicode ) && ES_VALIDO ( p_cOrigUnicode ) )
		{
			dwTam = (DWORD) CadLongitud ( p_cMensaje );
			dwRes = NetMessageBufferSend ( (LPCWSTR) NULL, (LPCWSTR) p_cDestUnicode, (LPCWSTR) p_cOrigUnicode, (LPBYTE) p_cMensaje, dwTam );
			if ( dwRes == 0 ) // NERR_Success )
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
		//PENDIENTE: Las cadenas UNICODE no se liberan bien:
		//MemLiberarUnicode ( &p_cDestUnicode );
		//MemLiberarUnicode ( &p_cOrigUnicode );
#	 else
		// PENDIENTE:
		iRes = 0;
#	 endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SListaCadenas * SisRedOrdenadoresAccesibles ()
{
	return ( NULL );
}


int SisRedServidorEsAccesible ( const char * p_cServidor )
{
	int					iRes;
# if ( defined ( WIN ) )
	unichar *			p_cOrdUnicode;
	SERVER_INFO_100		srvinfDatos;
	DWORD				dwRes;
# endif	
	if ( ES_VALIDO ( p_cServidor ) )
	{
#	 if ( defined ( WIN ) )
		p_cOrdUnicode = CadAsciizAUnicode ( p_cServidor );
		if ( ES_VALIDO ( p_cOrdUnicode ) )
		{
#		  if ( _MSC_VER < 1600 )
			dwRes = NetServerGetInfo ( (char *) p_cOrdUnicode, (DWORD) 100, (LPBYTE *) &srvinfDatos );
#		  else
			dwRes = NetServerGetInfo ( (LPWSTR) p_cOrdUnicode, (DWORD) 100, (LPBYTE *) &srvinfDatos );
#		  endif
			if ( dwRes == 0 ) // NERR_Success )
			{
				//PENDIENTE: Las cadenas UNICODE no se liberan bien:
				//MemLiberarUnicode ( &p_cOrdUnicode );
			}
		}
		else
		{
			iRes = 0;
		}
#	else
		// PENDIENTE
		iRes = 0;
#	endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisRedEstacionEsAccesible ( const char * p_cEstacion )
{
	int				iRes;
# if ( defined ( WIN ) )
	unichar *			p_cOrdUnicode;
	WKSTA_INFO_100	estinfDatos;
	DWORD			dwRes;
# endif	
	if ( ES_VALIDO ( p_cEstacion ) )
	{
#	 if ( defined ( WIN ) )
		p_cOrdUnicode = CadAsciizAUnicode ( p_cEstacion );
		if ( ES_VALIDO ( p_cOrdUnicode ) )
		{
#		  if ( _MSC_VER < 1600 )
			dwRes = NetWkstaGetInfo ( (char *) p_cOrdUnicode, (DWORD) 100, (LPBYTE *) &estinfDatos );
#		  else

			dwRes = NetWkstaGetInfo ( (LPWSTR) p_cOrdUnicode, (DWORD) 100, (LPBYTE *) &estinfDatos );
#		  endif
			if ( dwRes == 0 ) // NERR_Success )
			{
				iRes = 1;
			}
			else
			{
				iRes = 0;
			}
			//PENDIENTE: Las cadenas UNICODE no se liberan bien:
			//MemLiberarUnicode ( &p_cOrdUnicode );
		}
		else
		{
			iRes = 0;
		}
#	else
	// PENDIENTE:
	iRes = 0;
#	endif
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


/*
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   DWORD dwLevel = 101;
   LPSERVER_INFO_101 pBuf = NULL;
   NET_API_STATUS nStatus;
   LPTSTR pszServerName = NULL;

   if (argc > 2)
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
      exit(1);
   }
   // The server is not the default local computer.
   //
   if (argc == 2)
      pszServerName = argv[1];
   //
   // Call the NetServerGetInfo function, specifying level 101.
   //
   nStatus = NetServerGetInfo(pszServerName,
                              dwLevel,
                              (LPBYTE *)&pBuf);
   //
   // If the call succeeds,
   //
   if (nStatus == NERR_Success)
   {
      //
      // Check for the type of server.
      //
      if ((pBuf->sv101_type & SV_TYPE_DOMAIN_CTRL) ||
         (pBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL) ||
         (pBuf->sv101_type & SV_TYPE_SERVER_NT))
         printf("This is a server\n");
      else
         printf("This is a workstation\n");
   }
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);
   //
   // Free the allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);

   return 0;
}
*/
/*
int main( int argc, char *argv[] )
{
	DWORD rc;
	wchar_t server[MAXLEN], name[MAXLEN], from[MAXLEN], msg[MAXLEN];

	if ( argc != 5 && argc != 2 )
	{
		puts( "\nusage: nmbs \\\\server message-name from-name \"message\"" );
		puts( "       nmbs \\\\server\n" );
		puts( "First form: Sends the message to the <message-name> alias on <server>." );
		puts( "       Use whatever you like as <fromname>." );
		puts( "Second form: Lists <message-name>s on <server>. Note that not all of" );
		puts( "       them may work." );

		return 1;
	}

	mbstowcs( server, argv[1], MAXLEN );
	server[MAXLEN - 1] = L'\0';

	if ( argc == 2 )
	{
		enum_names( server );
	}
	else
	{
		mbstowcs( name, argv[2], MAXLEN );
		name[MAXLEN - 1] = L'\0';
		mbstowcs( from, argv[3], MAXLEN );
		from[MAXLEN - 1] = L'\0';
		mbstowcs( msg, argv[4], MAXLEN );
		msg[MAXLEN - 1] = L'\0';

		printf( "\nTrying ... " );
		rc = NetMessageBufferSend( server, name, from, (byte *) &msg[0], wcslen( msg ) * 2 );

		if ( rc != NERR_Success )
		{
			printf( "NMBS() returned %lu\n", rc );
			return 1;
		}

		puts( "Done." );
	}

	return 0;
}



void enum_names( const wchar_t *server )
{
	MSG_INFO_1 *buf, *cur;
	DWORD read, total, resumeh, rc, i;

	printf( "\nAvailable message-names on server %S:\n", server );
	resumeh = 0;
	do
	{
		buf = NULL;
		rc = NetMessageNameEnum( server, 1, (BYTE **) &buf,
			512, &read, &total, &resumeh );
		if ( rc != ERROR_MORE_DATA && rc != ERROR_SUCCESS )
			break;

		for ( i = 0, cur = buf; i < read; ++ i, ++ cur )
		{
			// Note: the capital S in the format string will expect Unicode
			// strings, as this is a program written/compiled for ANSI.
			printf( "%S\n", cur->msgi1_name );
		}

		if ( buf != NULL )
			NetApiBufferFree( buf );

	} while ( rc == ERROR_MORE_DATA );

	if ( rc != ERROR_SUCCESS )
		printf( "NMNE() returned %lu\n", rc );
}

*/
