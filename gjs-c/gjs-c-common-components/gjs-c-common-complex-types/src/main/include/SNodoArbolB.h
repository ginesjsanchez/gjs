
#ifndef _ORG_GJS_C_CC_SNODOARBOLB_H
#define _ORG_GJS_C_CC_SNODOARBOLB_H







// TODO: Implementar


typedef struct SNodoArbolB SNodoArbolB;

struct SNodoArbolB
{
	const char *	p_cDiscriminantes;
	SNodoArbolB *	p_nodHijos;
	SNodoArbolB *	p_nodHermano;

	int 			iOrden;   
	int				iNumClaves;
};


/*
SNodoArbolB * SNodArBCrearDef (); // int iOrden = ARB_B_MIN_ORDEN );
SNodoArbolB * SNodArBCrear ( int iOrden );

void SNodArBDestruir ( SNodoArbolB ** p_p_nodgObj );

int SNodArBOrden ( SNodoArbolB * p_nodgObj );
int SNodArBMinClaves ( SNodoArbolB * p_nodgObj );
int SNodArBMaxClaves ( SNodoArbolB * p_nodgObj );
int SNodArBNumClaves ( SNodoArbolB * p_nodgObj );
int SNodArBNumHijos ( SNodoArbolB * p_nodgObj );
int SNodArBMaxHijos ( SNodoArbolB * p_nodgObj );

SAristaGrafo * SNodArBAristaEntrada ( SNodoArbolB * p_nodgObj, int iArista );
SAristaGrafo * SNodArBAristaSalida ( SNodoArbolB * p_nodgObj, int iArista );

int SNodArBTieneAristasEntrada ( SNodoArbolB * p_nodgObj );
int SNodArBTieneAristasSalida ( SNodoArbolB * p_nodgObj );
int SNodArBTieneAristasEntradaPorRecorrer ( SNodoArbolB * p_nodgObj );
int SNodArBTieneAristasSalidaPorRecorrer ( SNodoArbolB * p_nodgObj );
int SNodArBTieneAristasEntradaRecorridas ( SNodoArbolB * p_nodgObj );
int SNodArBTieneAristasSalidaRecorridas ( SNodoArbolB * p_nodgObj );
int SNodArBPrimeraAristaEntradaPorRecorrer ( SNodoArbolB * p_nodgObj );
int SNodArBPrimeraAristaSalidaPorRecorrer ( SNodoArbolB * p_nodgObj );
int SNodArBUltimaAristaEntradaRecorrida ( SNodoArbolB * p_nodgObj );
int SNodArBUltimaAristaSalidaRecorrida ( SNodoArbolB * p_nodgObj );

int SNodArBConectarAristaEntrada ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj );
int SNodArBConectarAristaSalida ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj );

SAristaGrafo * SNodArBDesconectarAristaEntrada ( SNodoArbolB * p_nodgObj, int iArista );
SAristaGrafo * SNodArBDesconectarAristaSalida ( SNodoArbolB * p_nodgObj, int iArista );
int SNodArBDesconectarAristaEntrada ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj );
int SNodArBDesconectarAristaSalida ( SNodoArbolB * p_nodgObj, SAristaGrafo * p_arigObj );

void SNodArBInicializarAristasSalida ( SNodoArbolB * p_nodgObj );

void SNodArBLimpiarAristasEntrada ( SNodoArbolB * p_nodgObj );
void SNodArBLimpiarAristasSalida ( SNodoArbolB * p_nodgObj, int iLiberar );




*/ 



#endif

