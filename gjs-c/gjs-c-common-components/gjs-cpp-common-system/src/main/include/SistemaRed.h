/******************************************************************************/
/*                                SistemaRed.h                                */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene la definición de algunas rutinas de       */
/* carácter general de información de red.                                    */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_SISTEMARED_H
#define _ORG_GJS_C_CC_CPP_SISTEMARED_H



#include <string>
#include <list>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


string SisRedNombreOrdenador ();
string SisRedNombreDNSOrdenador ();

bool SisRedEnviarMensaje ( const string & sDestino, const string & sOrigen, const string & sMensaje );


list<string> * SisRedOrdenadoresAccesibles ();

bool SisRedServidorEsAccesible ( const string & sServidor );
bool SisRedEstacionEsAccesible ( const string & sEstacion );


 			}
		}
	}
}

#endif





