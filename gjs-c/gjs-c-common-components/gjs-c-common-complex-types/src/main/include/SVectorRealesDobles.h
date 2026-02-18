#ifndef _ORG_GJS_C_CC_SVECTORREALESDOBLES_H
#define _ORG_GJS_C_CC_SVECTORREALESDOBLES_H








#include <SVector.h>



typedef struct
{
	SVector * p_vecDatos;

} SVectorRealesDobles;





SVectorRealesDobles * SVecRealdCrear ( int iNumElementos );


void SVecRealdDestruir ( SVectorRealesDobles ** p_p_vecObj );

int SVecRealdEsValido ( SVectorRealesDobles * p_vecObj );

int SVecRealdNumElementos ( SVectorRealesDobles * p_vecObj );
double SVecRealdElemento ( SVectorRealesDobles * p_vecObj, int iElem );
int SVecRealdAsignar ( SVectorRealesDobles * p_vecObj, int iElem, double dDato );

int SVecRealdInicializar ( SVectorRealesDobles * p_vecObj );

int SVecRealdExiste ( SVectorRealesDobles * p_vecObj, double dDato );


#endif