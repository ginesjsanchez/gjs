
#ifndef _ORG_GJS_C_CC_SINTERVALO_H
#define _ORG_GJS_C_CC_SINTERVALO_H







typedef struct
{
	double		dMin;
	double		dMax;
	int			iNumDivisiones;
	double *	p_dDivisiones;

} SIntervalo;






SIntervalo * SIntvCrear ( double dMin, double dMax ); 
SIntervalo * SIntvCrearExt ( double dMin, double dMax, int iValores, ... ); 
SIntervalo * SIntvCrearSimetrico ( double dMax );
SIntervalo * SIntvCrearDesdeCero ( double dMax );
SIntervalo * SIntvCrearUnidad ();
SIntervalo * SIntvCrearCentena ();
SIntervalo * SIntvCrearPunto ( double dValor );

void SIntvDestruir ( SIntervalo ** p_p_intvObj );

double SIntvMin ( SIntervalo * p_intvObj );
double SIntvMax ( SIntervalo * p_intvObj );
int SIntvEstablecerMin ( SIntervalo * p_intvObj, double dValor );
int SIntvEstablecerMax ( SIntervalo * p_intvObj, double dValor );

double SIntvLongitud ( SIntervalo * p_intvObj );

int SIntvDividir ( SIntervalo * p_intvObj, int iValores, ... );
int SIntvDividirEquidistantemente ( SIntervalo * p_intvObj, int iNumSubintervalos );
void SIntvLimpiarDivisiones ( SIntervalo * p_intvObj );

int SIntvEsValido ( SIntervalo * p_intvObj ); 

SIntervalo * SIntvObtenerReflejo ( SIntervalo * p_intvObj );
SIntervalo * SIntvObtenerInverso ( SIntervalo * p_intvObj );

int SIntvNumDivisiones ( SIntervalo * p_intvObj ); 
int SIntvNumSubintervalos ( SIntervalo * p_intvObj ); 
SIntervalo * SIntvSubintervalo ( SIntervalo * p_intvObj, int iSubintervalo );
double SIntvLongitudSubintervalo ( SIntervalo * p_intvObj, int iSubintervalo );
double SIntvSubintervaloMin ( SIntervalo * p_intvObj, int iSubintervalo );
double SIntvSubintervaloMax ( SIntervalo * p_intvObj, int iSubintervalo );

int SIntvBuscarInervalo ( SIntervalo * p_intvObj, double dValor );



#endif

