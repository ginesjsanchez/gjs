
#ifndef _ORG_GJS_C_CC_ARBOL_B_H
#define _ORG_GJS_C_CC_ARBOL_B_H





#include <SNodoArbolB.h>



/*

typedef struct SArbBRaiz
     {
        const char *  sclvDiscriminantes;
        TArbBNodo * spabnHijos; 
        long      lNumClaves; 
     } TArbBRaiz;


typedef struct SArbBNodo
     {
        const char *  *pclvDiscriminantes;
        TArbBNodo * * p_pabnHijos;
        TArbBNodo * pabnSigHermano;   
        long      lNumClaves; 
     } TArbBNodo;



typedef struct
{
	  int       iTipo;
	  int       iOrden;
	  int       iOrdenacionElems;
	  int       iCtlElemsLibres;
	  int       iTipoApuntadores;
	  int       iTamClave;
	  TArbBRaiz    abrRaiz;
	  TArbBNodo    *pabnTronco;
	  long      lNumNodos;
	  long      lNumHojas;
	  long      lNumClaves;
	  TArbBNodo * pabnSigLibre;  
	  
} SArbolB;




SArbolB * SArbBCrear ( int iTipo, int iOrden, int iOrdenacionElems, int iNumClavesRaiz,
              int iCtlElemsLibres, int iTipoApuntadores, 
              int iTamClave );



int ArbBVacio ( SArbolB *parbObj );
int ArbBInsertar ( SArbolB *parbObj, const char * clvElem, 
                 int iElem );



int ArbBConsultar ( SArbolB *parbObj, const char * clvElem, 
                 long *pvalElem );
int ArbBModificar ( SArbolB *parbObj, const char * clvElem, 
                 int iElem );
int ArbBEliminar ( SArbolB *parbObj, const char * clvElem );



int ArbBSeleccionarTodos ( SArbolB *parbObj );
int ArbBSeleccionarRango ( SArbolB *parbObj, const char * clvElem1,
                     const char * clvElem2 );
int ArbBSeleccionarFiltro ( SArbolB *parbObj, const char * clvFiltro );

int ArbBAnularSeleccion ( SArbolB *parbObj );

int ArbBBuscarPrimero ( SArbolB *parbObj, long *pvalElem );
int ArbBBuscarSiguiente ( SArbolB *parbObj, long *pvalElem );
int ArbBBuscarAnterior ( SArbolB *parbObj, long *pvalElem );
int ArbBBuscarUltimo ( SArbolB *parbObj, long *pvalElem );




const char * ArbBValorMaximo ( SArbolB *parbObj );
const char * ArbBValorMinimo ( SArbolB *parbObj );
int ArbBExiste ( SArbolB *parbObj, const char * clvElem );



int ArbBEsValido ( SArbolB *parbObj );
int ArbBEstaVacio ( SArbolB *parbObj );
long ArbBNumNodos ( SArbolB *parbObj );
long ArbBNumNiveles ( SArbolB *parbObj );
long ArbBNumClaves ( SArbolB *parbObj );
long ArbBNumHojas ( SArbolB *parbObj );



int ArbBDestruir ( SArbolB **parbObj );


void ArbBImprimir ( SArbolB *parbObj );

*/


#endif 

