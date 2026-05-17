#ifndef _ORG_GJS_C_CC_SSECUENCIAREALESDOBLES_H
#define _ORG_GJS_C_CC_SSECUENCIAREALESDOBLES_H








#include <SSecuencia.h>



typedef struct
{
	SSecuencia * p_secDatos;

} SSecuenciaRealesDobles;





SSecuenciaRealesDobles * SSecRealdCrear ();


void SSecRealdDestruir ( SSecuenciaRealesDobles ** p_p_secObj );

int SSecRealdEsValida ( SSecuenciaRealesDobles * p_secObj );

int SSecRealdNumElementos ( SSecuenciaRealesDobles * p_secObj );
double SSecRealdElemento ( SSecuenciaRealesDobles * p_secObj, int iElem );

int SSecRealdInsertar ( SSecuenciaRealesDobles * p_secObj, double dDato );
int SSecRealdModificar ( SSecuenciaRealesDobles * p_secObj, int iElem, double dDato );
int SSecRealdEliminar ( SSecuenciaRealesDobles * p_secObj, int iElem );
int SSecRealdVaciar ( SSecuenciaRealesDobles * p_secObj );

int SSecRealdExiste ( SSecuenciaRealesDobles * p_secObj, double dDato );



#endif
