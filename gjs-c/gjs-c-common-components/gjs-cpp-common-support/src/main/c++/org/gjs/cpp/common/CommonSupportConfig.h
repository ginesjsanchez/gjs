#ifndef _ORG_GJS_C_CC_CPP_COMMON_SUPPORT_CONFIG
#define _ORG_GJS_C_CC_CPP_COMMON_SUPPORT_CONFIG



#include <CppBase.h>
#include <CppCommonTime.h>
#include <CppCommonSystem.h>

#include <cstdio>

#if ( !defined ( WIN ) )
#	include <termios.h>
#endif

#if ( defined ( VC ) )
#	include <conio.h>
#else
#	include <fcntl.h>
#	include <unistd.h>
#   include <stdio.h>
#endif




#define APL_MIN_TAM_COD_USUARIO				4
#define APL_MAX_TAM_COD_USUARIO				30
#define APL_MAX_TAM_CLV_USUARIO				30



#define CON_MAX_TAM_CADENA					255
#define CAJ_MSJ_MAX_TAM_LINEA				1023


#define VER_MAX_TAM_CADENA					11
#define VER_FORM_CADENA						"{}.{}.{}"
#define VER_FORM_CADENA_CORTO				"{}.{}"
#define VER_FORM_MENSAJE					"Version: {}.{}.{}  Fecha: {}"

#define VER_TXT_FECHA_NULA					"(indeterminada)"


#define VERSION_FEC_FORMATO					"%d/%m/%Y"

#endif
