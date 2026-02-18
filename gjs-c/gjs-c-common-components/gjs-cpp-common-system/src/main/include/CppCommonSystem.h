#ifndef _ORG_GJS_C_CC_CPP_COMMON_SYSTEM_H
#define _ORG_GJS_C_CC_CPP_COMMON_SYSTEM_H


#include <SistemaTiempo.h>
#include <SistemaInformacion.h>
#include <SistemaProcesos.h>
#include <SistemaMemoria.h>
#include <SistemaRed.h>
#include <SistemaEstado.h>
#include <SistemaComandos.h>
#include <SistemaSignals.h>


#include <CVariablesEntorno.h>
#include <CTemporizador.h>
#include <CContadorCiclos.h>
#include <CGestorSignals.h>

#include <string>



using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


void SisInicializar ( const string & sNomProceso = "", const string & sDirTemporal = "" );
void SisFinalizar ();


 			}
		}
	}
}


#endif
