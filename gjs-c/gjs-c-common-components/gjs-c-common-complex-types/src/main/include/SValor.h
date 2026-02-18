/***************************************************************************/
#ifndef _ORG_GJS_C_CC_SVALOR_H
#define _ORG_GJS_C_CC_SVALOR_H














#include <SCadena.h>
#include <SCadenaConv.h>
#include <SCadenaNumerica.h>




typedef struct
{
	int				iTipo;
	SCadenaConv *	p_cadValor;
} SValor;


SValor * SValCrearDef ();
SValor * SValCrear ( int iTipo );
SValor * SValCrearExt ( int iTipo, int iMaxTam );
SValor * SValCrearByte ( byte byValor );
SValor * SValCrearEntero ( int iValor );
SValor * SValCrearEnteroLargo ( long lValor );
SValor * SValCrearEnteroSinSigno ( unsigned int uiValor );
SValor * SValCrearEnteroLargoSinSigno ( unsigned long ulValor );
SValor * SValCrearReal ( float fValor );
SValor * SValCrearRealDoble ( double dValor );
SValor * SValCrearCadena ( const char * p_cValor );
SValor * SValCrearBinario ( byte * p_byValor );


void SValDestruir ( SValor ** p_p_valObj );

int SValTipo ( SValor * p_valObj );
int SValEsValido ( SValor * p_valObj );

SCadenaConv * SValValor ( SValor * p_valObj );
byte SValValorByte ( SValor * p_valObj );
int SValValorBooleano ( SValor * p_valObj );
unsigned long SValValorNatural ( SValor * p_valObj );
long SValValorEntero ( SValor * p_valObj );
double SValValorReal ( SValor * p_valObj );
const char * SValValorCadena ( SValor * p_valObj );
byte * SValValorBinario ( SValor * p_valObj );

int SValMaxTam ( SValor * p_valObj );

void SValEstablecerValorByte ( SValor * p_valObj, byte byValor );
void SValEstablecerValorEntero ( SValor * p_valObj, int iValor );
void SValEstablecerValorEnteroLargo ( SValor * p_valObj, long lValor );
void SValEstablecerValorEnteroSinSigno ( SValor * p_valObj, unsigned int uiValor );
void SValEstablecerValorEnteroLargoSinSigno ( SValor * p_valObj, unsigned long ulValor );
void SValEstablecerValorReal ( SValor * p_valObj, float fValor );
void SValEstablecerValorRealDoble ( SValor * p_valObj, double dValor );
void SValEstablecerValorLiteral ( SValor * p_valObj, const char * p_cValor );
void SValEstablecerValorBinario ( SValor * p_valObj, byte * p_byValor );
void SValEstablecerValorCadena ( SValor * p_valObj, SCadena * p_cadValor );
void SValEstablecerValor ( SValor * p_valObj, SCadenaConv * p_cadValor );
void SValEstablecerValorNumerico ( SValor * p_valObj, SCadenaNumerica * p_cadValor );

void SValAsignar ( SValor * p_valObj, SValor * p_valValor );

void SValLimpiar ( SValor * p_valObj );
int SValTieneValor ( SValor * p_valObj );

SValor * SValDuplicar ( SValor * p_valObj );



#endif

