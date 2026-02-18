/******************************************************************************/
/*                              Precompilacion.h                              */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Es el fichero de cabecera de configuración de la librería que normaliza    */
/* las constantes de pre-compilación básicas para determinar el tipo de       */
/* compilación a realizar.                                                    */
/* El sistema de constantes de pre-compilación es el siguiente:               */
/*                                                                            */
/*  Nivel Máquina:          A64 | A32 | A16 | A8                              */
/*  Nivel Sistema/Entorno:  UNIX |LINUX | WIN | DOS	                          */
/*  Nivel Compilador:       GNU | CC | VC				                                 */
/*                                                                            */
/*  Depuración:             MODO_DEPURACION ( & MODO_DEPURACION_2 )           */
/*                          MODO_DEPURACION, MODO_DEPURACION_2                */
/*                                                                            */
/*  Errores:                ALM_ERRORES                                       */
/*                                                                            */
/*  Unicode:                MODO_UNICODE                                      */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _PRECOMPILACION_H
#define _PRECOMPILACION_H


 //PENDIENTE: distinguir consola| no consola en caso WIN

#if ( !defined ( CYGWIN ) && defined ( __CYGWIN__ ) )
#	define	UNIX
#	define	CYGWIN
#endif

/* Por defecto se compila como DOS: */ 
#if ( !defined ( DOS ) && !defined ( WIN ) && !defined ( UNIX )  && !defined ( LINUX ) )
#	define DOS
#endif

/* Por defecto se considera una arquitectura de 32 bits: */
#if ( !defined ( A8 ) && !defined ( A16 ) && !defined ( A32 ) && !defined ( A64 ) )
#	if ( defined ( WIN64 ) || defined ( _WIN64 ) )
#		define	A64
#	elif ( defined ( WIN32 ) || defined ( _WIN32 ) )
#		define	A32
#	elif ( defined ( WIN ) )
#		define	A16
#	elif ( defined ( _INTEGRAL_MAX_BITS ) )
#		if ( _INTEGRAL_MAX_BITS >= 64 )
#			define	A64
#		elif ( _INTEGRAL_MAX_BITS == 32 )
#			define	A32
#		elif ( _INTEGRAL_MAX_BITS == 16 )
#			define	A16
#		elif 
#			define	A8
#		endif
#	else
#		define A32
#	endif
#endif

/* Por defecto se considera que se compila con GNU: */
#if ( !defined ( GNU ) && !defined ( CC ) && !defined ( VC ) )
#	define	GNU
#else // Para CC sólo se permite UNIX y para VC sólo se permite DOS o WIN:
#	if ( defined ( CC ) )
#		undef DOS
#		undef WIN
#		define UNIX
#	elif ( defined ( VC ) )
#		if ( defined ( UNIX ) )
#			undef UNIX
#			define DOS
#		elif ( defined ( LINUX ) )
#			undef LINUX
#			define DOS
#		endif
#	endif
#endif

/* Versión de Windows a utilizar: */
#if ( defined ( WIN ) )
#	if ( defined ( WINVER ) )
#		undef WINVER
#	endif
#	define WINVER			0x0500   // version 5.0
#	if ( defined ( _WIN32_WINNT ) )
#		undef _WIN32_WINNT
#	endif
#	define _WIN32_WINNT		0x0500   // version 5.0
#endif 


/* Modos de depuración: */
#if ( defined ( MODO_DEPURACION_2 ) )
#	if ( !defined ( MODO_DEPURACION ) )
#		define MODO_DEPURACION
#	endif
#endif



#endif







