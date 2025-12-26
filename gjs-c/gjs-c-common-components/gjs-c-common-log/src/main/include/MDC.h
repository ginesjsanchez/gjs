#ifndef _ORG_GJS_C_CC_C_LOG_MDC_H
#define _ORG_GJS_C_CC_C_LOG_MDC_H

void MDCGuardar ( const char * p_cClave, const char * p_cValor );
const char * MDCRecuperar ( const char * p_cClave );
void MDCEliminar ( const char * p_cClave );

void MDCLimpiar ();

#endif
