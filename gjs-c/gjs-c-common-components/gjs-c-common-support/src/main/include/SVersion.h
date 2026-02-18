#ifndef _ORG_GJS_C_CC_SVERSION_H
#define _ORG_GJS_C_CC_SVERSION_H




#include <SFecha.h>




typedef struct
{
	int			iVersion;
	int			iSubversion;
	int			iRevision;
	SFecha *	p_fecVersion;

} SVersion;



SVersion * SVerCrearDef ();
SVersion * SVerCrear ( int iVersion, int iSubversion, int iRevision, long lFecVersion );
SVersion * SVerCrearExt ( int iVersion, int iSubversion, int iRevision, SFecha * p_fecVersion );

void SVerDestruir ( SVersion ** p_p_verObj );

int SVerVersion ( SVersion * p_verObj );
int SVerSubversion ( SVersion * p_verObj );
int SVerRevision ( SVersion * p_verObj );
SFecha * SVerFecha ( SVersion * p_verObj );
char * SVerCadenaVersion ( SVersion * p_verObj, int iCorta );
char * SVerCadenaFecha ( SVersion * p_verObj );
long SVerValorFecha ( SVersion * p_verObj );

int SVerEsValida ( SVersion * p_verObj );

int SVerEstablecerVersion ( SVersion * p_verObj, int iVersion );
int SVerEstablecerSubversion ( SVersion * p_verObj, int iSubversion );
int SVerEstablecerRevision ( SVersion * p_verObj, int iRevision );
int SVerEstablecerFechaEnteroLargo ( SVersion * p_verObj, long lFecVersion );
int SVerEstablecerFecha ( SVersion * p_verObj, SFecha * p_fecVersion );
int SVerEstablecer ( SVersion * p_verObj, int iVersion, int iSubversion, int iRevision, long lFecVersion );
int SVerEstablecerExt ( SVersion * p_verObj, int iVersion, int iSubversion, int iRevision , SFecha * p_fecVersion );

void SVerImprimir ( SVersion * p_verObj );




#endif