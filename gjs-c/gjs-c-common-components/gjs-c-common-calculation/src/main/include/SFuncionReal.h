#ifndef _ORG_GJS_C_CC_FUNCIONREAL_H
#define _ORG_GJS_C_CC_FUNCIONREAL_H


#include <CalculoDefs.h>

#include <CalculoOperaciones.h>

#include <SDominioReal.h>
#include <SDominioSimpleReal.h>



// TODO: Implementar funciones de dominio, continuidad...

typedef struct
{
	PFUNREAL					p_fCalculo;
	struct SFuncionReal *		p_funInterior;
	// SDominioReal *			p_domRango;

} SFuncionReal;


SFuncionReal * SFunRCrear ( PFUNREAL p_fCalculo );
SFuncionReal * SFunRCrearComposicion ( PFUNREAL p_fCalculo, SFuncionReal * p_funInterna );
// SFuncionReal * SFunREncapsular ( PFUNREAL p_fCalculo, SDominioReal * p_domObj );
void SFunRDestruir ( SFuncionReal ** p_p_funObj );

int SFunREsValida ( SFuncionReal * p_funObj );
int SFunREsCompuesta ( SFuncionReal * p_funObj );

SFuncionReal * SFunRFuncionInterior ( SFuncionReal * p_funObj );
// SDominioReal * SFunRDominio ( SFuncionReal * p_funObj );

// int SFunRNumDominiosSimples ( SFuncionReal * p_funObj );
// SDominioSimpleReal * SFunRNumDominioSimple ( SFuncionReal * p_funObj, int iDomSimp );
// int SFunRInsertarDominioSimple ( SFuncionReal * p_funObj, SDominioSimpleReal * p_domsObj );
// int SFunREliminarDominioSimple ( SFuncionReal * p_funObj, SDominioSimpleReal * p_domsObj );
// int SFunRLimpiarDominio ( SFuncionReal * p_funObj );

// int SFunREstaDefinidaEn ( SFuncionReal * p_funObj, double dValor );
// int SFunREstaDefinidaEnOrigen ( SFuncionReal * p_funObj );
// int SFunREstaDefinidaEnInfinito ( SFuncionReal * p_funObj );
// int SFunREstaDefinidaEnMenosInfinito ( SFuncionReal * p_funObj );
// int SFunRTienePuntosSingulares ( SFuncionReal * p_funObj );
// int SFunREsDominioConexo ( SFuncionReal * p_funObj );

double SFunREvaluar ( SFuncionReal * p_funObj, double dValor );

// int SFunREsContinua ( SFuncionReal * p_funObj );

// double SFunRCalcularMax ( SFuncionReal * p_funObj );
// double SFunRCalcularMin ( SFuncionReal * p_funObj );
// double SFunRCalcularMaxLocal ( SFuncionReal * p_funObj, SDominioSimpleReal * p_domsRango );
// double SFunRCalcularMinLocal ( SFuncionReal * p_funObj, SDominioSimpleReal * p_domsRango );

void SFunRComponer ( SFuncionReal * p_funObj, SFuncionReal * p_funInterna );

SFuncionReal * SFunRDuplicar ( SFuncionReal * p_funObj );
SFuncionReal * SFunRValorAbsoluto ( SFuncionReal * p_funObj );
SFuncionReal * SFunRNegada ( SFuncionReal * p_funObj );
SFuncionReal * SFunRInversa ( SFuncionReal * p_funObj );

#endif

