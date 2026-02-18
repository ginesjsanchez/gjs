
#ifndef _ORG_GJS_C_CC_HORAS_H
#define _ORG_GJS_C_CC_HORAS_H









long HorFormConstruir ( int iH, int iM, int iS );

int HorEsValida ( int iH, int iM, int iS );
int HorFormEsValida ( long lHora );

void HorFormDescomponer ( long lHora, int * p_iH, int * p_iM, int * p_iS );
int HorFormHoras ( long lHora );
int HorFormMinutos ( long lHora );
int HorFormSegundos ( long lHora );

int HorNumMinutos ( int iH, int iM, int iS ); 
int HorNumSegundos ( int iH, int iM, int iS ); 
int HorFormNumMinutos ( long lHora ); 
int HorFormNumSegundos ( long lHora ); 

int HorSumar ( int * p_iH, int * p_iM, int * p_iS, int iH, int iM, int iS );
int HorRestar ( int * p_iH, int * p_iM, int * p_iS, int iH, int iM, int iS );
long HorFormSumar ( long lHora1, long lHora2 );
long HorFormRestar ( long lHora1, long lHora2 );

// En horas:
int HorValEsValido ( double dValor );
double HorObtenerValor ( int iH, int iM, int iS );
double HorFormObtenerValor ( long lHora );
int HorEstablecerValor ( double dValor, int * p_iH, int * p_iM, int * p_iS ); 
long HorFormEstablecerValor ( double dValor );




#endif



