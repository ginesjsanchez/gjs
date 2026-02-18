#ifndef _ORG_GJS_C_CC_C_NIVELESLOG_H
#define _ORG_GJS_C_CC_C_NIVELESLOG_H


#define LOG_NIVEL_NINGUNO					-1
#define LOG_NIVEL_DEPURACION				0
#define LOG_NIVEL_INFORMACION				1
#define LOG_NIVEL_AVISO						2
#define LOG_NIVEL_ERROR						3
#define LOG_NIVEL_FORZADO					100
#define LOG_NIVEL_DEFECTO					LOG_NIVEL_ERROR
#define LOG_NIVEL_MIN						LOG_NIVEL_INFORMACION
#define LOG_NIVEL_MAX						LOG_NIVEL_FORZADO
	

int NivelLogEsValido ( int iNivel );
int NivelLogEsEstablecible ( int iNivel );



#endif
