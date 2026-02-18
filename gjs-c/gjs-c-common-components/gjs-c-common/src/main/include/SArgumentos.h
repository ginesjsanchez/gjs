#ifndef _ORG_GJS_C_CC_SARGUMENTOS_H
#define _ORG_GJS_C_CC_SARGUMENTOS_H


#include <SSecuenciaLiterales.h>



typedef struct 
{
	SSecuenciaLiterales *	p_seclitArgumentos;

} SArgumentos;

SArgumentos * SArgCrearDef ();
SArgumentos * SArgCrear ( int iNumArg, char ** p_p_cArg );

void SArgDestruir ( SArgumentos ** p_p_argObj );

int SArgNumArgumentos ( SArgumentos * p_argObj );
char * SArgArgumento ( SArgumentos * p_argObj, int iArg );
int SArgEsArgumentoNumerico ( SArgumentos * p_argObj, int iArg );
int SArgArgumentoEntero ( SArgumentos * p_argObj, int iArg );
long SArgArgumentoEnteroLargo ( SArgumentos * p_argObj, int iArg );
float SArgArgumentoReal ( SArgumentos * p_argObj, int iArg );
double SArgArgumentoRealDoble ( SArgumentos * p_argObj, int iArg );







#endif

