/******************************************************************************/
/*                         AplicacionConfig.h                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  Aplicacion                                                      */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Es el fichero de cabecera de configuración de la librería que contiene     */
/* las constantes de pre-compilación y los ficheros de cabecera externos      */
/* que necsita la librería.                                                   */
/*----------------------------------------------------------------------------*/
/*                    gines_jimenez@safe-mail.net                             */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_APLICACIONCONFIG_H
#define _ORG_GJS_C_CC_APLICACIONCONFIG_H




#include <Base.h>

#include <Tipos.h>
#include <Texto.h>
#include <Tiempo.h>
#include <Sistema.h>

#if ( !defined ( WIN ) )
#	include <termios.h>
#endif

#if ( defined ( VC ) )
#	include <conio.h>
#else
#	include <unistd.h>
#endif




#define APL_MIN_TAM_COD_USUARIO				4
#define APL_MAX_TAM_COD_USUARIO				30
#define APL_MAX_TAM_CLV_USUARIO				30



#define CON_MAX_TAM_CADENA					255
#define CAJ_MSJ_MAX_TAM_LINEA				1023



#define VER_MAX_TAM_CADENA					11
#define VER_FORM_CADENA						"%d.%d.%d"
#define VER_FORM_CADENA_CORTO				"%d.%d"
#define VER_FORM_MENSAJE					"Version: %d.%d.%d  Fecha: %s"

#define VER_TXT_FECHA_NULA					"(indeterminada)"


#endif

