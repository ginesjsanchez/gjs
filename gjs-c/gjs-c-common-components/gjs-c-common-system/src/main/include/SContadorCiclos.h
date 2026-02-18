#ifndef _ORG_GJS_C_CC_SCONTADORCICLOS_H
#define _ORG_GJS_C_CC_SCONTADORCICLOS_H




#include <stdint.h>



typedef struct
{
	int					iIniciado;
	uint64_t	ui64CicloIni;
	uint64_t	ui64NumCiclos;

} SContadorCiclos;


SContadorCiclos * SConCicCrear ();

void SConCicDestruir ( SContadorCiclos ** p_p_concicObj );

void SConCicIniciar ( SContadorCiclos * p_concicObj );
uint64_t SConCicValor ( SContadorCiclos * p_concicObj );
uint64_t SConCicParar ( SContadorCiclos * p_concicObj );
int SConCicEstaContando ( SContadorCiclos * p_concicObj );



#endif

