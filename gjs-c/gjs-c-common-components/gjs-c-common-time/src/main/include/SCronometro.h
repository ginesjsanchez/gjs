#ifndef _ORG_GJS_C_CC_SSCRONOMETRO_H
#define _ORG_GJS_C_CC_SSCRONOMETRO_H







typedef struct
{
	double dTiempoIni;

} SCronometro;


SCronometro * SCronCrear ();

void SCronDestruir ( SCronometro ** p_p_cronObj );

void SCronIniciar ( SCronometro * p_cronObj );
double SCronParar ( SCronometro * p_cronObj );

double SCronComputo ( SCronometro * p_cronObj );


#endif


