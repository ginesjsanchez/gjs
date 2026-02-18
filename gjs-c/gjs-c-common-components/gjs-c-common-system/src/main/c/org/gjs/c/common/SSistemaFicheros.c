
#include "SSistemaFicheros.h"

#include "SistemaConfig.h"

/*

#include <SBuffer.h>
#include <SCadena.h>


static void SSFActualizar ( SSistemaFicheros * p_sfObj );
static void SSFDeterminarSistema ( SSistemaFicheros * p_sfObj );




SSistemaFicheros * SSFCrear ()
{
	SSistemaFicheros * p_sfObj;
	
	p_sfObj = (SSistemaFicheros *) MemReservar ( sizeof ( SSistemaFicheros ) );
	if ( ES_VALIDO ( p_sfObj ) )
	{
		p_sfObj->iIniciado = 0;
		p_sfObj->ui64CicloIni = 0;
		p_sfObj->ui64NumCiclos = 0;
	}
	return ( p_sfObj );
}

void SSFDestruir ( SSistemaFicheros ** p_p_sfObj )
{
	SSistemaFicheros * p_sfObj;
	
	if ( ES_VALIDO ( p_p_sfObj ) )
	{
		p_sfObj = *p_p_sfObj;
		if ( ES_VALIDO ( p_sfObj ) )
		{
			MemLiberar ( (void **) p_p_sfObj );
		}
	}
}


SSFSSistemaFicheros () : SDirectorio ()
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
	Actualizar ();
	DeterminarSistema ();
}

SSF~SSistemaFicheros ()
{
}

SDirectorio * SSFDirectorioActual ()
{
	SDirectorio * p_dirActual;

	p_dirActual = (SDirectorio *) this;
	return ( p_dirActual );
}

void SSFCambiarARuta ( const char * p_cRuta )
{
	if ( ES_VALIDO ( p_cRuta ) ) 
	{
#	  if ( defined ( WIN ) )
		if ( SetCurrentDirectory ( p_cRuta ) != 0 )
#	  else
		if ( chdir ( p_cRuta ) == 0 )
#	  endif
		{
			Actualizar ();
		}
		else
		{
			//printf ( "NO OK\n" );
		}
	}
}

void SSFCambiarASubdirectorio ( const char * p_cSubdir )
{
	::SCadena * p_cadRuta;

	if ( ES_VALIDO ( p_cSubdir ) ) 
	{
		p_cadRuta = new ::SCadena ( "./" );
		if ( ES_VALIDO ( p_cadRuta ) )
		{
			p_cadRuta->Concatenar ( p_cSubdir ); 	
#		  if ( defined ( WIN ) )
			if ( SetCurrentDirectory ( p_cadRuta->Valor () ) != 0 )
#		  else
			if ( chdir ( p_cadRuta->Valor () ) == 0 )
#		 endif
			{
				Actualizar ();
			}
			DESTRUIR ( SCadena, &p_cadRuta );
		}
	}
}

void SSFCambiarASuperdirectorio ()
{
	if ( EsRaiz () == 0 )
	{
#	  if ( defined ( WIN ) )
		if ( SetCurrentDirectory ( ".." ) != 0 )
#	  else
		if ( chdir ( ".." ) == 0 )
#	  endif
		{
			Actualizar ();
		}
	}
}

void SSFCambiarARaiz ()
{
	if ( EsRaiz () == 0 )
	{
#	  if ( defined ( WIN ) )
		if ( SetCurrentDirectory ( "\\" ) != 0 )
#	  else
		if ( chdir ( "/" ) == 0 )
#	  endif
		{
			Actualizar ();
		}
	}
}

int SSFEsRaiz ()
{
	return ( 0 );
}

int SSFEsDOS ()
{
	return ( iDOS );
}

int SSFEsUNIX ()
{
	return ( ( iDOS + 1 ) % 2 );
}

void SSFActualizar ()
{
	const char *	p_cDir;
# if ( !defined ( GNU ) )
	SBuffer	*		p_bufDatos;
# endif
	
# if ( defined ( WIN ) )
	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
		if ( GetCurrentDirectory ( (DWORD) SBufTam ( p_bufDatos ), (LPSTR) SBufDireccion ( p_bufDatos ) ) > 0 )
		{
			p_cDir = SBufDuplicarCadena ( p_bufDatos );
		}
		else
		{
			p_cDir = NULL;
		}
		SBufDestruir ( &p_bufDatos );
	}
# elif ( defined ( GNU ) )
	p_cDir = get_current_dir_name ();
# else
	p_bufDatos = SBufCrear ( SIS_SO_MAX_TAM_BUFFER );
	if ( ES_VALIDO ( p_bufDatos ) )
	{
		if ( getcwd ( (char *) SBufDireccion ( p_bufDatos ), SBufTam ( p_bufDatos ) ) != NULL )
		{
			p_cDir = SBufDuplicarCadena ( p_bufDatos );
		}
		else
		{
			p_cDir = NULL;
		}
		SBufDestruir ( &p_bufDatos );
	}
# endif
	if ( ES_VALIDO ( p_cDir ) )
	{
		SDirectorio::Cambiar ( p_cDir );
		MemLiberar ( (void **) &p_cDir );
	}
}

void SSFDeterminarSistema ()
{
	if ( SDirectorio::Ruta ()->EsEstiloDOS () == 1 )
	{
		iDOS = 1;
	}
	else
	{
		iDOS = 0;
	}
}


*/




