/******************************************************************************/
/*                                 Punteros.h                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  GBase                                                           */
/* Versión:   1.0.0                                                           */
/* Fecha:     28/06/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/
#ifndef _ORG_GJS_C_CC_PUNTEROS_H
#define _ORG_GJS_C_CC_PUNTEROS_H

#if  ( !defined (VC) )
#   include <stdlib.h>
#endif

// PENDIENTE: Determinar la dirección mínima de memoria:
#if  ( !defined (VC) )
#	define PTR_LIBERAR( p_Obj )		if ( p_Obj != NULL ) { if ( (unsigned long) p_Obj > 1000 ) free ( p_Obj ); else printf ( "DIR BAJA %lx\n", (long) p_Obj ); p_Obj = NULL; }
#else
#	define PTR_LIBERAR( p_Obj )		if ( p_Obj != NULL ) { if ( (unsigned long) p_Obj > 1000 ) delete ( (void *) p_Obj ); else printf ( "DIR BAJA %lx\n", (long) p_Obj ); p_Obj = NULL; }
#endif


// No funcionaba bien puesto que no se eliminaban los objetos desde el nivel de descendencia correcto:
//#define PTR_LIBERAR_ARRAY( p_p_Obj, iElems )	if ( p_p_Obj != NULL ) { printf ( "LIBERANDO ARRAY EN DIRECCION %ld DE %d ELEMENTOS\n", (long) p_p_Obj, (int) iElems ); PTR_LIBERAR ( p_p_Obj ); p_p_Obj = NULL; }
//#define PTR_LIBERAR_ARRAY( p_p_Obj, iElems )	if ( p_p_Obj != NULL ) { printf ( "LIBERANDO ARRAY EN DIRECCION %ld DE %d ELEMENTOS\n", (long) p_p_Obj, (int) iElems ); { int i; for ( i = 0; i < iElems; i = i + 1 ) { printf ( "ELEM %d (%ld)", i, (long) p_p_Obj [ i ] ); PTR_LIBERAR ( p_p_Obj [ i ] ); } } PTR_LIBERAR ( p_p_Obj ); p_p_Obj = NULL; }

/*
#define PTR_LIBERAR( p_Obj )					if ( p_Obj != NULL ) { printf ( "LIBERANDO DIRECCION %ld -> %d\n", (long) p_Obj, (int) *((int*)p_Obj)); char * p_cObj; p_cObj = (char *) p_Obj; if ( p_cObj [0] != 0 ) { delete ( p_Obj ); } p_Obj = NULL; }
#define PTR_LIBERAR_ARRAY( p_p_Obj, iElems )	if ( p_p_Obj != NULL ) { printf ( "LIBERANDO ARRAY EN DIRECCION %ld DE %d ELEMENTOS\n", (long) p_p_Obj, (int) iElems ); char * p_cObj; p_cObj = (char *) p_p_Obj; if ( p_cObj [0] != 0 ) { int i; for ( i = 0; i < iElems; i = i + 1 ) { printf ( "ELEM %d (%ld)", i, (long) p_p_Obj [ i ] ); PTR_LIBERAR ( p_p_Obj [ i ] ); } } p_p_Obj = NULL; }
*/
/*
#ifndef WIN
#	define PTR_LIBERAR_ARRAY( p_Obj )	if ( p_Obj != NULL ) { delete[] ( p_Obj ); p_Obj = NULL; }
#else
#	define PTR_LIBERAR_ARRAY( p_Obj )	if ( p_Obj != NULL ) { p_Obj = NULL; }
#endif
*/


// NOTA: Utilizo new char para olvidarme de momento de compatibilidades:
#if  ( !defined (VC) )
#   define PTR_RESERVAR_MEMORIA( p_Mem, iTam )			p_Mem = malloc ( iTam )
#else
#   define PTR_RESERVAR_MEMORIA( p_Mem, iTam )			p_Mem = new char [ iTam ]
#endif
#define PTR_LIBERAR_MEMORIA( p_Obj )				PTR_LIBERAR ( p_Obj );
#define PTR_RELLENAR_MEMORIA( p_Mem, iTam, cVal )	if ( ( p_Mem != NULL ) && ( iTam > 0 ) ) { for ( int iPos = 0; iPos < iTam; iPos = iPos + 1 ) {	*(p_Mem + iPos) = (char) cVal; } }
#define PTR_INICIALIZAR_MEMORIA( p_Mem, iTam )		if ( ( p_Mem != NULL ) && ( iTam > 0 ) ) { for ( int iPos = 0; iPos < iTam; iPos = iPos + 1 ) {	*(p_Mem + iPos) = (char) 0; } }
#define PTR_COPIAR_MEMORIA( p_MemD, p_MemO, iTam )  if ( ( p_MemD != NULL ) && ( p_MemO != NULL ) && ( iTam > 0 ) ) { for ( int iPos = 0; iPos < iTam; iPos = iPos + 1 ) {	*(p_MemD + iPos) = *(p_MemO + iPos); } }



#endif






