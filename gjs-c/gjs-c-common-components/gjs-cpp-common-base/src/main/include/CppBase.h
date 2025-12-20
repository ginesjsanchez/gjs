#ifndef _ORG_GJS_C_CC_CPP_BASE_H
#define _ORG_GJS_C_CC_CPP_BASE_H


#include <Prototipos.h>
#include <TerminalANSI.h>

#include <Cadenas.h>
#include <IToString.h>
#include <ToString.h>
#include <ToInt.h>
#include <Concatenar.h>

#include <Objeto.h>
#include <IComparable.h>

#include <Colecciones.h>

#include <Excepcion.h>
#include <FinExcepcion.h>
#include <NoEncontradoExcepcion.h>
#include <SistemaExcepcion.h>
#include <HayError.h>
#include <Sistema.h>
#include <Ficheros.h>



#define LIBERAR( ptr ) 				if( ptr != NULL ) { delete ptr; ptr = NULL; }


#endif
