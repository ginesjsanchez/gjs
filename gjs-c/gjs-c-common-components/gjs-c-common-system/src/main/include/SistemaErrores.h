#ifndef _ORG_GJS_C_CC_SISTEMAERRORES_H
#define _ORG_GJS_C_CC_SISTEMAERRORES_H












int SisHaHabidoError ();
int SisHaHabidoErrorDeMemoriaAgotada ();
int SisHayError ( int iRefrescar );
int SisHayErrorDeMemoriaAgotada ( int iRefrescar );
int SisErrTipo ();
int SisErrCodigo ();
const char  * SisErrDescripcion (); // int iError );
char * SisErrMensaje ( int iMostrarCodigo ); 
char * SisErrMensajeExt ( const char * p_cModulo, const char * p_cRutina ); 
void SisErrImprimir (); 
void SisErrLimpiar ();

int SisMaxError ();

void SisErrApilar ( const char * p_cModulo, const char * p_cRutina, int iRefrescar );
void SisErrImprimirPila ();
void SisErrLimpiarPila ();


#endif





