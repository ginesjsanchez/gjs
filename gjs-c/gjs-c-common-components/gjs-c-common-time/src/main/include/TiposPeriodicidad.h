
#ifndef _ORG_GJS_C_CC_TIPOSPERIODICIDAD_H
#define _ORG_GJS_C_CC_TIPOSPERIODICIDAD_H




#define TIP_PERIOD_NINGUNO			-1


#define TIP_PERIOD_DIARIO			0	
#define TIP_PERIOD_SEMANAL			1	
#define TIP_PERIOD_MENSUAL			2	
#define TIP_PERIOD_TRIMESTRAL		4	
#define TIP_PERIOD_ANUAL			3	





int TipPeriodEsValido ( int iId );

int TipPeriodEsDiario ( int iId );
int TipPeriodEsSemanal ( int iId );
int TipPeriodEsMensual ( int iId );
int TipPeriodEsAnual ( int iId );
int TipPeriodEsTrimestral ( int iId );


#endif
