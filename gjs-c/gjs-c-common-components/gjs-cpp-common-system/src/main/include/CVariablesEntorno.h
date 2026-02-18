/******************************************************************************/
/*                            CVariablesEntorno.h                             */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene la definición de la clase de datos        */
/* CVariablesEntorno, que facilita el trabajo con las variables de entorno    */
/* del sistema operativo.                                                     */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_CVARIABLESENTORNO_H
#define _ORG_GJS_C_CC_CPP_CVARIABLESENTORNO_H




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





class CVariablesEntorno
{
public:
	CVariablesEntorno ();

	~CVariablesEntorno ();

	string * ObtValor ( const string & sVariable ) const;
	bool LimpiarValor ( const string & sVariable );
	bool EstValor ( const string & sVariable, const string & sValor );
	bool ExisteVariable ( const string & sVariable );
};




 			}
		}
	}
}




#endif

