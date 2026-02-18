#ifndef _ORG_GJS_C_CC_DOMINIOREAL_H
#define _ORG_GJS_C_CC_DOMINIOREAL_H




#include <SDominioSimpleReal.h>
#include <SListaPtr.h>

// TODO: Sin implementar

typedef struct
{
	SListaPtr * p_lisDominios;

} SDominioReal;



SDominioReal * SDomRCrear ();
int SDomRDestruir ( SDominioReal ** p_p_domObj );

int SDomREsValido ( SDominioReal * p_domObj );

int SDomRNumDominiosSimples ( SDominioReal * p_domObj );
SDominioSimpleReal * SDomRNumDominioSimple ( SDominioReal * p_domObj, int iDomSimp );
int SDomRInsertarDominioSimple ( SDominioReal * p_domObj, SDominioSimpleReal * p_domsObj );
int SDomREliminarDominioSimple ( SDominioReal * p_domObj, SDominioSimpleReal * p_domsObj );
int SDomRLimpiar ( SDominioReal * p_domObj );

int SDomREstaIncluido ( SDominioReal * p_domObj, double dValor );
int SDomREstaIncluidoOrigen ( SDominioReal * p_domObj );
int SDomREstaIncluidoInfinito ( SDominioReal * p_domObj );
int SDomREstaIncluidoMenosInfinito ( SDominioReal * p_domObj );

int SDomREsConexo ( SDominioReal * p_domObj );

SDominioReal * SDomRDuplicar ( SDominioReal * p_domObj );

#endif

