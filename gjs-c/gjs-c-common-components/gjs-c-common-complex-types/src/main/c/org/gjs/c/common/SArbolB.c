
#include "SArbolB.h"

#include "TiposDatosConfig.h"


/*
TArbBNodo ArbBSigLibre( SArbolB *parbObj )
{
   long      lRet;
   TArbBNodo pabnNodoAct;
   
   if ( parbObj != NULL )
   {

     if ( parbObj->lNumNodos < ARB_B_MAX_NODOS )
     {
        lRet = TRUE;
        if ( ! ARB_B_NODO_CORRECTO ( parbObj->pabnSigLibre ) )
        {
          parbObj->pabnSigLibre = 0;
        }
        else
        {
          parbObj->pabnSigLibre = 
               ARB_B_NODO_INC_CIR ( parbObj->pabnSigLibre );
        }
        pabnNodoAct = parbObj->pabnSigLibre;

        while ( ( parbObj->sabnJerarquia[ parbObj->pabnSigLibre ].lNumClaves 
             <= 0 ) ) && 
            ( lRet == TRUE ) )   
        {
          parbObj->pabnSigLibre = 
               ARB_B_NODO_INC_CIR ( parbObj->pabnSigLibre );
          if ( parbObj->pabnSigLibre == pabnNodoAct )
          {
             parbObj->ptnSigLibre = ARB_B_NODO_NULO;
             lRet = FALSE;
          }
        }
     }
     else
     {
        parbObj->ptnSigLibre = ARB_B_NODO_NULO;
        lRet = FALSE;
     }
   }
   else
   {
     lRet = FALSE;
   }
   return ( lRet );
}



SArbolB *ArbCrear ( SArbolB *parbObj, int iTipo, int iOrden, int iOrdenacionElems, 
              int iCtlElemsLibres, int iTipoApuntadores, 
              int iTamClave )
{
   SArbolB     *parbObj;
   

   if ( ARB_B_TIPO_VALIDO ( iTipo ) && ARB_B_CTL_LIB_VALIDO ( iCtlElemsLibres ) &&
     ARB_B_ORDENACION_VALIDA ( iOrdenacionElems ) && 
   if ( parbObj != NULL )
   {
     parbAux = parbObj;
   }
   else
   {
     parbAux = (SArbolB *) malloc ( sizeof ( SArbolB ) );
   }

   if ( parbAux != NULL )
   {   
     parbAux->iTipo = iTipo;
     ArbBVacio ( parbAux );
     return ( parbAux );
   }
   else
   {
     return ( NULL );
   }
}

int ArbBVacio ( SArbolB *parbObj )
{
   int   resInfo;
   TArbBNodo pabnNodo;
   TPTR_ARB_B_HOJA pabhHoja;

   if ( parbObj != NULL )
   {
     parbObj->lNumNodos = 0;
     parbObj->lNumHojas = 0;
     parbObj->pabnRaiz = ARB_B_NODO_NULO;
     parbObj->pabnSigLibre = 0;

     for ( pabnNodo = ARB_B_NODO_PRIMERO; pabnNodo <= ARB_B_NODO_ULTIMO; 
        pabnNodo = ARB_B_NODO_INC ( pabnNodo ) )
     {
        ArbBNodoVaciar ( &( parbObj->sabnJerarquia [ ptnNodo ] ) );
     }
     resInfo = ARB_B_RES_OPE_REALIZADA;
   }
   else
   {
     resInfo = ARB_B_RES_ERR_ESTRUCTURA;
   }
   return ( resInfo );
}


int ArbBInsertar ( SArbolB *parbObj, const char * clvElem, 
                 int iElem )
{
   int      resInfo;
   TArbBNodo       *pnabIns;
   TArbBNodo    ptaPadre;
   TArbBNodo    ptnNodo;
   TArbBNodo    ptaDeseq;
   
   if ( parbObj != NULL )
   {
     if ( parbObj->ptnSigLibre != ARB_B_NODO_NULO )
     {
     }
   }
   else
   {
     resInfo = ARB_B_RES_ERR_ESTRUCTURA;
   }
   return ( resInfo );
}


int ArbBConsultar ( SArbolB *parbObj, const char * clvElem, 
                 long *pvalElem )
{
   int resInfo;
   TArbBNodo ptnNodo;
   TArbBNodo ptaPadre;

   if ( ( parbObj != NULL ) && ( pvalElem != NULL ) )
   {
   }
   else
   {
     resInfo = ARB_B_RES_ERR_ESTRUCTURA;
   }
   return ( resInfo );
}


int ArbBModificar ( SArbolB *parbObj, const char * clvElem,
                 int iElem )
{
   int   resInfo;
   TArbBNodo ptnNodo;
   TArbBNodo ptaPadre;

   if ( parbObj != NULL )
   {
   }
   else
   {
     resInfo = ARB_B_RES_ERR_ESTRUCTURA;
   }
   return ( resInfo );
}


int ArbBEliminar ( SArbolB *parbObj, const char * clvElem )
{
   int   resInfo;
   TArbBNodo ptnNodo;
   TArbBNodo ptaSubarbolDer;
   TArbBNodo ptaSubarbolIzq;
   TArbBNodo ptnNodoSust;
   TArbBNodo ptaPadre;
   TArbBNodo ptaDeseq;

   if ( parbObj != NULL )
   {
     if ( parbObj->lNumNodos > 0 )
     {
     }
     else
     {
        resInfo = ARB_B_RES_ERR_NO_EXISTE;        
     }
   }
   else
   {
     resInfo = ARB_B_RES_ERR_ESTRUCTURA;
   }
   return ( resInfo );
}



const char * ArbBValorMaximo ( SArbolB *parbObj )
{
   long  lRes;

   if ( parbObj == NULL )
   {
     lRes = FALSE;
   }
   else
   {
     lRes = TRUE;
   }
   return ( lRes );
}


const char * ArbBValorMinimo ( SArbolB *parbObj )
{
   long  lRes;

   if ( parbObj == NULL ) 
   {
     lRes = FALSE;
   }
   else
   {
     lRes = TRUE;
   }
   return ( lRes );
}


int ArbBExiste ( SArbolB *parbObj, const char * clvElem )
{
   long  lRes;
   TArbBNodo ptaPadre;

   if ( ( parbObj == NULL ) && ( clvElem == NULL ) )
   {
     lRes = FALSE;
   }
   else
   {
     if ( parbObj->lNumNodos <=0 )
     {
        lRes = FALSE;
     }
     else
     {

        if ( ARB_B_NODO_CORRECTO ( ArbBuscarPosicion ( parbObj, pbyClave, 
                              lTamClave, &ptaPadre, 
                              &abdNodo ) ) )
        {
          lRes = TRUE;
        }
        else
        {
          lRes = FALSE;
        }

     }
   }
   return ( lRes );
}



long ArbBEsvalido ( SArbolB *parbObj )
{
   long lRes;

   if ( parbObj == NULL )
   {
     lRes = FALSE;
   }
   else
   {
     if ( ( parbObj->lNumNodos > 0 ) && ( parbObj->lNumNodos <= ARB_B_MAX_NODOS ) )
     {
        lRes = TRUE;
     }
   }
   return ( lRes );
}


int ArbBEstaVacio ( SArbolB *parbObj )
{
   int iRes;

   if ( parbObj == NULL )
   {
     iRes = FALSE;
   }
   else
   {
     if ( parbObj->ptnRaiz == ARB_B_NODO_NULO )
     {   
        iRes = TRUE;
     }
     else
     {
        iRes = FALSE;
     }
   }
   return ( iRes );
}



long ArbBNumNodos ( SArbolB *parbObj )
{
   long  lRes;

   if ( parbObj == NULL )
   {
     lRes = FALSE;
   }
   else
   {
     lRes = TRUE;
   }
   return ( lRes );
}


long ArbBNumNiveles ( SArbolB *parbObj )
{
   long  lRes;

   if ( parbObj == NULL )
   {
     lRes = FALSE;
   }
   else
   {
     lRes = TRUE;
   }
   return ( lRes );
}


long ArbBNumClaves ( SArbolB *parbObj )
{
   long  lRes;

   if ( parbObj == NULL )
   {
     lRes = FALSE;
   }
   else
   {
     lRes = TRUE;
   }
   return ( lRes );
}


void ArbBDestruir ( SArbolB ** p_parbObj )
{
   SArbolB   *parbObj;

   if ( p_parbObj != NULL )
   {
       if ( * p_parbObj != NULL )
       {
        parbObj = * p_parbObj;   
        free ( parbObj );
        * p_parbObj = NULL;
     }
   }
}

*/

