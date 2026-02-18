/*
#include "Punteros.h"
#include "Texto.h"

#include "TextoConfig.h"



void TxtLiberar( TTEXTOO *ptxtDatos )
{
	char *sLinea;
	long lLinea;

	lLinea = 0;
	while( lLinea < ptxtDatos->lNumLineas )
	{
		Lin
		sLinea = *( ( ptxtDatos->psLineas ) + lNumLineas );
		free( sLinea );
		lLinea = lLinea + 1;
	}
	free( ptxtDatos->psLineas );
	ptxtDatos->psLineas = NULL;	
}


void TxtInicializar( TTEXTO *ptxtDatos )
{
	TxtLiberar( ptxtDatos );
	ptxtDatos->psLineas = Null;
	ptxtDatos->lNumLineas = 0;
	ptxtDatos->lLineaAct =0;
	ptxtDatos->lColumnaAct =0;
}


void TxtInicio( TTEXTO *ptxtDatos )
{
	ptxtDatos->lLineaActual = 0;
	ptxtDatos->lColumnaActual = 0;
}
void TxtFinal( TTEXTO *pLinDatos );
void TxtSig( TTEXTO *pLinDatos );
void TxtAnt( TTEXTO *pLinDatos );


void TxtPrimeraLinea( TTEXTO *pLinDatos );
void TxtUltimaLinea( TTEXTO *pLinDatos );
void TxtSigLinea( TTEXTO *pLinDatos );
void TxtAntLinea( TTEXTO *pLinDatos );


long TxtNumLineas( TTEXTOO *ptxtDatos )
{
	return ptxtDatos->lNumLineas;
}

long TxtNumLineas( TTEXTOO *ptxtDatos );
long TxtLongitud( TTEXTOO *ptxtDatos );
TBOOL TxtEsFinal( TTEXTO *pLinDatos );
TBOOL TxtEsInicio( TTEXTO *pLinDatos );
TBOOL TxtEsFinalLinea( TTEXTO *pLinDatos );
TBOOL TxtEsInicioLinea( TTEXTO *pLinDatos );
TBOOL TxtEsVacio( TTEXTO *pLinDatos );
TBOOL TxtEsLineaVacia( TTEXTO *pLinDatos );



void TxtInsertarCaracter( TTEXTO *ptxtDatos, char c )
{
	char 	*sLineaNueva;

	if( lNumLineas == 0 ) 
	{
		TxtInsertarLinea( ptxtDatos );
		TxtInicio( ptxtDatos );
	}

	if( ptxtDatos->iColumnaActual == strlen( *( ( ptxtDatos->psLineas ) + iLineaActual ) ) )
	{
		// Añadir al final:
		
	}
	else
	{
		// Insertar en medio:
	}
}


void TxtInsertarLinea( TTEXTO *ptxtDatos, char *sCadena );


TLINEA TxtLinea( TTEXTO *plinDatos );
char *TxtCadenaLinea( TTEXTO *plinDatos );
char *TxtCadenaTexto( TTEXTO *plinDatos );

void TxtEliminarCaracter( TTEXTO *pLinDatos );


void TxtImprimir( TTEXTO *ptxtDatos )
{
}
*/
