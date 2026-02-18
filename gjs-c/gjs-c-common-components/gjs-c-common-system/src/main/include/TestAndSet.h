/******************************************************************************/
/*                                TestAndSet.h                                */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene los prototipos de las rutinas tas y       */
/* tar, para los casos en que no vengan en las librerías del compilador.      */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_TESTANDSET_H
#define _ORG_GJS_C_CC_TESTANDSET_H



#include <Precompilacion.h>


#if ( defined ( LINUX ) )

#if ( !defined ( tas ) )


#if ( defined ( xchg ) )

#define tas(ptr) (xchg((ptr),1))
#define tas(ptr) (xchg((ptr),1))

#else

// PENDIENTE:
#endif




#endif

#endif

#endif





