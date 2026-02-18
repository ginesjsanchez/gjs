#ifndef _ORG_GJS_C_CC_STABLAREALESDOBLES_H
#define _ORG_GJS_C_CC_STABLAREALESDOBLES_H



#include <STabla.h>



typedef struct
{
	STabla * p_tabDatos;

} STablaRealesDobles;





STablaRealesDobles * STabRealdCrear ( int iNumFilas, int iNumColumnas );


void STabRealdDestruir ( STablaRealesDobles ** p_p_tabObj );

int STabRealdEsValida ( STablaRealesDobles * p_tabObj );

int STabRealdNumFilas ( STablaRealesDobles * p_tabObj );
int STabRealdNumColumnas ( STablaRealesDobles * p_tabObj );
int STabRealdNumElementos ( STablaRealesDobles * p_tabObj );
double STabRealdElemento ( STablaRealesDobles * p_tabObj, int iFila, int iColumna );

int STabRealdAsignar ( STablaRealesDobles * p_tabObj, int iFila, int iColumna, double dDato );
int STabRealdInicializar ( STablaRealesDobles * p_tabObj );

int STabRealdExiste ( STablaRealesDobles * p_tabObj, double dDato );



#endif



