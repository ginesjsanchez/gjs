

#ifndef _ORG_GJS_C_CC_CONSOLADEPURACION_H
#define _ORG_GJS_C_CC_CONSOLADEPURACION_H





#define						DEP_INIFUN			ConDepEscribirLinea ("<Mod: %s; Fun: %s> - INICIO", __FILE__, __FUNCTION__ )
#define						DEP_FINFUN			ConDepEscribirLinea ("<Mod: %s; Fun: %s> - FIN", __FILE__, __FUNCTION__ )




int ConDepAbrir ();
void ConDepCerrar ();
int ConDepEstaAbierta ();

int ConDepEscribir ( const char * p_cTexto, ... );
int ConDepEscribirLinea ( const char * p_cTexto, ... );


#endif

