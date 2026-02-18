/*
#ifndef _ORG_GJS_C_CC_TEXTO_H
#define _ORG_GJS_C_CC_TEXTO_H

#include "Linea.h"


typedef struct
	  {
		TLINEA	*psLineas;
		long		lNumLineas;
		long		lLineaAct;
		long		lColumnaAct;
	  } TTEXTO;


void TxtVacio( TTEXTO *ptxtDatos );
void TxtInsertarCaracter( TTEXTO *ptxtDatos, char c );
void TxtInsertarCadena( TTEXTO *ptxtDatos, char *sCadena );
void TxtInsertarLinea( TTEXTO *ptxtDatos, char *sCadena );

void TxtInicio( TTEXTO *pLinDatos );
void TxtFinal( TTEXTO *pLinDatos );
void TxtSig( TTEXTO *pLinDatos );
void TxtAnt( TTEXTO *pLinDatos );

void TxtPrimeraLinea( TTEXTO *pLinDatos );
void TxtUltimaLinea( TTEXTO *pLinDatos );
void TxtSigLinea( TTEXTO *pLinDatos );
void TxtAntLinea( TTEXTO *pLinDatos );

TLINEA TxtLinea( TTEXTO *plinDatos );
char *TxtCadenaLinea( TTEXTO *plinDatos );
char *TxtCadena( TTEXTO *plinDatos );

void TxtEliminarCaracter( TTEXTO *pLinDatos );
void TxtEliminarLinea( TTEXTO *pLinDatos );

long TxtNumLineas( TTEXTOO *ptxtDatos );
long TxtLongitud( TTEXTOO *ptxtDatos );
TBOOL TxtEsFinal( TTEXTO *pLinDatos );
TBOOL TxtEsInicio( TTEXTO *pLinDatos );
TBOOL TxtEsFinalLinea( TTEXTO *pLinDatos );
TBOOL TxtEsInicioLinea( TTEXTO *pLinDatos );
TBOOL TxtEsVacio( TTEXTO *pLinDatos );
TBOOL TxtEsLineaVacia( TTEXTO *pLinDatos );

void TxtImprimir( TTEXTO *ptxtDatos );

void TxtCargarFichero( TTEXTO *ptxtDatos, char *sFichero, long lMode );
void TxtSalvarFichero( TTEXTO *ptxtDatos, char *sFichero );


#endif
*/
