

#ifndef _ORG_GJS_C_CC_SFORMALINEAL_H
#define _ORG_GJS_C_CC_SFORMALINEAL_H






typedef struct
{
	int			iNumVariables;
	double *	p_dCoeficientes;

} SFormaLineal;






SFormaLineal * SFrmLinCrear ( int iNumVariables ); 
SFormaLineal * SFrmLinCrearExt ( int iNumVariables, ... ); 
SFormaLineal * SFrmLinCrear1 ( double dCoef );
SFormaLineal * SFrmLinCrear2 ( double dCoef1, double dCoef2 );
SFormaLineal * SFrmLinCrear3 ( double dCoef1, double dCoef2, double dCoef3 );

void SFrmLinDestruir ( SFormaLineal ** p_p_frmlinObj );

int SFrmLinEsValido ( SFormaLineal * p_frmlinObj ); 

int SFrmLinNumVariables ( SFormaLineal * p_frmlinObj ); 
double SFrmLinCoeficiente ( SFormaLineal * p_frmlinObj, int iCoeficiente );
double SFrmLinCoeficiente1 ( SFormaLineal * p_frmlinObj );
double SFrmLinCoeficiente2 ( SFormaLineal * p_frmlinObj );
double SFrmLinCoeficiente3 ( SFormaLineal * p_frmlinObj );
int SFrmLinEstablecerCoeficiente ( SFormaLineal * p_frmlinObj, int iCoeficiente, double dValor );

double * SFrmLinVectorValores ( SFormaLineal * p_frmlinObj );
double SFrmLinEvaluar ( SFormaLineal * p_frmlinObj, double * p_dValores );
double SFrmLinEvaluarExt ( SFormaLineal * p_frmlinObj, ... );

int SFrmLinMultiplicar ( SFormaLineal * p_frmlinObj, double dValor );

int SFrmLinSumar ( SFormaLineal * p_frmlinObj, SFormaLineal * p_frmlinValor );

SFormaLineal * SFrmLinDuplicar  ( SFormaLineal * p_frmlinObj );




#endif

