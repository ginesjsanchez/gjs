
#ifndef _ORG_GJS_C_CC_STEMPORIZADOR_H
#define _ORG_GJS_C_CC_STEMPORIZADOR_H









typedef struct  
{
	int iMiliSegs;
	
} STemporizador;



STemporizador * STmpCrear ( int iMiliSegs );

void STmpDestruir ( STemporizador ** p_p_tmpObj );

int STmpIntervalo ( STemporizador * p_tmpObj );
void STmpEstablecerIntervalo ( STemporizador * p_tmpObj, int iMiliSegs );

void STmpEsperarDef ( STemporizador * p_tmpObj );
void STmpEsperar ( STemporizador * p_tmpObj, int iMiliSegs );



#endif

