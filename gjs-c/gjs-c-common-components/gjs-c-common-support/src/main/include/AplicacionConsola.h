/******************************************************************************/
/*                            AplicacionConsola.h                             */
/*----------------------------------------------------------------------------*/
/* Librería:  Aplicacion                                                      */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene los prototipos de unas cuantas rutinas    */
/* para manejo de la consola.                                                 */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/


#ifndef _ORG_GJS_C_CC_APLICACIONCONSOLA_H
#define _ORG_GJS_C_CC_APLICACIONCONSOLA_H






int AplicConAbrir ();
void AplicConCerrar ();
int AplicConEstaAbierta ();

int AplicConAncho ();

void AplicConLimpiar ();

int AplicConLeerNumero ();
int AplicConLeerNumeroEntre ( int iMin, int iMax );
char * AplicConLeerCadena ();
void AplicConEsperarRetorno ();

int AplicConDibujarLinea ( char cCar );
int AplicConDibujarLineaExt ( int iAncho, int iColIni, char cCar );
int AplicConDibujarRectangulo ( int iAlto, int iAncho, int iColIni );

#endif



