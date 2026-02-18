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


#include "CommonSystemConfig.h"

#include <vector>

using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
			namespace common
			{


string SisRedNombreOrdenador ()
{
	string sRes = "";
	vector<char> buffer = vector<char> ( SIS_SO_MAX_TAM_BUFFER );
# if ( defined ( WIN ) )
	DWORD			dwTam;
# else
	int				iTam;
# endif	

# if ( defined ( WIN ) )
	dwTam = (DWORD) buffer.size();
	if ( GetComputerName ( (LPTSTR) buffer.data(), ( LPDWORD ) &dwTam) > 0 )
# else
	// TODO:
	iTam = buffer.size ();
	//if ( gethostname ( (char *) buffer.data (), iTam ) == 0 )
	if ( false )
# endif
	{
		sRes = string ( buffer.data() );
	}
	return ( sRes );
}

string SisRedNombreDNSOrdenador ()
{
	string sRes = "";
	vector<char> buffer = vector<char> ( SIS_SO_MAX_TAM_BUFFER );
# if ( defined ( WIN ) )
	DWORD			dwTam;
# endif	
# if ( defined ( WIN ) )
	// PENDIENTE:
	dwTam = (DWORD) buffer.size ();
	//if ( GetComputerNameEx ( ComputerNameDnsHostname, (LPTSTR) buffer.data(), (LPDWORD) &dwTam ) > 0 )
	if ( false )
# else
	// PENDIENTE:
	if ( false )
#	 endif
	{
		sRes = string ( buffer.data () );
	}
	return ( sRes );
}

// PENDIENTE: La siguiente rutina no parce funcionar.
bool SisRedEnviarMensaje ( const string & sDestino, const string & sOrigen, const string & sMensaje )
{
	bool	bRes = false;
# if ( defined ( WIN ) )
	DWORD		dwTam;
	DWORD		dwRes;
# endif	
	if ( !sDestino.empty() && ! sOrigen.empty () && ! sMensaje.empty () )
	{
#	 if ( defined ( WIN ) )
		wstring wsDestUnicode = Utf8AUnicode ( sDestino );
		wstring wsOrigUnicode = Utf8AUnicode ( sOrigen );
		dwTam = (DWORD) sMensaje.length();
		dwRes = NetMessageBufferSend ( (LPCWSTR) NULL, (LPCWSTR) wsDestUnicode.c_str(), ( LPCWSTR ) wsOrigUnicode.c_str (), ( LPBYTE ) sMensaje.c_str (), dwTam);
		if ( dwRes == 0 ) // NERR_Success )
#	 else
		// PENDIENTE:
		if ( false )
#	 endif
		{
			bRes = true;
		}
	}
	return ( bRes );
}

list<string> * SisRedOrdenadoresAccesibles ()
{
	// TODO
	return ( NULL );
}

bool SisRedServidorEsAccesible ( const string & sServidor )
{
	bool	bRes = false;
# if ( defined ( WIN ) )
	SERVER_INFO_100		srvinfDatos;
	DWORD				dwRes;
# endif	
	if ( ! sServidor.empty () )
	{
#	 if ( defined ( WIN ) )
		wstring wsOrdUnicode = = Utf8AUnicode ( sServidor );
#	  if ( _MSC_VER < 1600 )
		dwRes = NetServerGetInfo ( (char *) wsOrdUnicode.c_str(), ( DWORD ) 100, ( LPBYTE * ) &srvinfDatos);
#	  else
		dwRes = NetServerGetInfo ( (LPWSTR) wsOrdUnicode.c_str (), (DWORD) 100, (LPBYTE *) &srvinfDatos );
#	  endif
		if ( dwRes == 0 ) // NERR_Success )
#	 else
		// PENDIENTE:
		if ( false )
#	 endif
		{
			bRes = true;
		}
	}
	return ( bRes );
}
bool SisRedEstacionEsAccesible ( const string & sEstacion )
{
	bool	bRes = false;
# if ( defined ( WIN ) )
	WKSTA_INFO_100	estinfDatos;
	DWORD			dwRes;
# endif	
	if ( ! sEstacion.empty () )
	{
#	 if ( defined ( WIN ) )
		wstring wsOrdUnicode = = Utf8AUnicode ( sExtacion );
#	  if ( _MSC_VER < 1600 )
		dwRes = NetWkstaGetInfo ( (char *) wsOrdUnicode.c_str(), ( DWORD ) 100, ( LPBYTE * ) &estinfDatos);
#	  else
		dwRes = NetWkstaGetInfo ( (LPWSTR) wsOrdUnicode.c_str (), (DWORD) 100, (LPBYTE *) &estinfDatos );
#	  endif
		if ( dwRes == 0 ) // NERR_Success )
#	 else
		// PENDIENTE:
		if ( false )
#	 endif
		{
			bRes = true;
		}
	}
	return ( bRes );
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

			}
		}
	}
}

