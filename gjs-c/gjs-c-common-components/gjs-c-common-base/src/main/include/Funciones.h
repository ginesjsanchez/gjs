/******************************************************************************/
/*                                Funciones.h                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene los tipos necesarios para manejar los     */
/* punteros a procedimeitnos y funciones.                                     */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _FUNCIONES_H
#define _FUNCIONES_H


#include <UniChar.h>




// NOTA: Ir añadiendio conforme se vayan necesitando:

typedef void (* PPRC0)(void);
typedef void (* PPRC1)(int);
typedef void (* PPRC2)(long);
typedef void (* PPRC3)(char);
typedef void (* PPRC4)(unsigned int);
typedef void (* PPRC5)(unsigned long);
typedef void (* PPRC6)(char *);
typedef void (* PPRC7)(const char *);
typedef void (* PPRC8)(void *);
typedef void (* PPRC9)(void **);


typedef int (* PFUNINT0)(void);
typedef int (* PFUNINT1)(int);
typedef int (* PFUNINT2)(long);
typedef int (* PFUNINT3)(char);
typedef int (* PFUNINT4)(unsigned int);
typedef int (* PFUNINT5)(unsigned long);
typedef int (* PFUNINT6)(char *);
typedef int (* PFUNINT7)(const char *);

typedef int (* PFUNINT11)(int,int);
typedef int (* PFUNINT111)(int,int,int);
typedef int (* PFUNINT1111)(int,int,int,int);
typedef int (* PFUNINT11111)(int,int,int,int,int);
typedef int (* PFUNINT111111)(int,int,int,int,int,int);


typedef long (* PFUNLONG0)(void);
typedef long (* PFUNLONG1)(int);
typedef long (* PFUNLONG2)(long);
typedef long (* PFUNLONG3)(char);
typedef long (* PFUNLONG4)(unsigned int);
typedef long (* PFUNLONG5)(unsigned long);
typedef long (* PFUNLONG6)(char *);
typedef long (* PFUNLONG7)(const char *);

typedef char (* PFUNCHAR0)(void); 
typedef char (* PFUNCHAR1)(int);
typedef char (* PFUNCHAR2)(long);
typedef char (* PFUNCHAR3)(char);
typedef char (* PFUNCHAR4)(unsigned int);
typedef char (* PFUNCHAR5)(unsigned long);
typedef char (* PFUNCHAR6)(char *);
typedef char (* PFUNCHAR7)(const char *);
typedef char (* PFUNCHAR71)(const char *, int );
typedef char (* PFUNCHAR78)(const char *, int * );

typedef char * (* PFUNPCHAR0)(void); 
typedef char * (* PFUNPCHAR1)(int);
typedef char * (* PFUNPCHAR2)(long);
typedef char * (* PFUNPCHAR3)(char);
typedef char * (* PFUNPCHAR4)(unsigned int);
typedef char * (* PFUNPCHAR5)(unsigned long);
typedef char * (* PFUNPCHAR6)(char *);
typedef char * (* PFUNPCHAR7)(const char *);
typedef char * (* PFUNPCHAR71)(const char *, int );
typedef char * (* PFUNPCHAR78)(const char *, int * );

typedef const char * (* PFUNPCCHAR0)(void); 
typedef const char * (* PFUNPCCHAR1)(int);
typedef const char * (* PFUNPCCHAR2)(long);
typedef const char * (* PFUNPCCHAR3)(char);
typedef const char * (* PFUNPCCHAR4)(unsigned int);
typedef const char * (* PFUNPCCHAR5)(unsigned long);
typedef const char * (* PFUNPCCHAR6)(char *);
typedef const char * (* PFUNPCCHAR7)(const char *);
typedef const char * (* PFUNPCCHAR71)(const char *, int );
typedef const char * (* PFUNPCCHAR78)(const char *, int * );

typedef void * (* PFUNVOID0)(void); 
typedef void * (* PFUNVOID515)(unsigned long, int, unsigned long); 


#if ( defined ( WIN ) )

typedef HANDLE (* PFUNHNDDWBDW)(DWORD, BOOL, DWORD);
typedef int (* PFUNINTHWN)(HWND);

#endif


/* Tipo de datos especiales para los casos más sencillos: */ 
typedef int (*PTR_FUNCION)();
typedef void (*PTR_PROCEDIMIENTO)();




#endif







