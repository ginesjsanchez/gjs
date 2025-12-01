#ifndef _ORG_GJS_C_CC_CPP_CADENAS_H
#define _ORG_GJS_C_CC_CPP_CADENAS_H

#include <string>
#include <initializer_list>
#include <list>
#include <vector>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace c
		{
            namespace common
            {

            string ReemplazarTodos ( const string & sCadena, char cBuscar, char cReemplazo );
			string ReemplazarTodos ( const string & sCadena, const string & sBuscar, const string & sReemplazo );
			string EliminarTodos ( const string & sCadena, char cBuscar );
			string EliminarTodos ( const string & sCadena, const string & sBuscar );

			string Limpiar( const string & sCadena );

			string SubcadenaHasta ( const string & sCadena, char cBuscar );
			string SubcadenaDesde ( const string & sCadena, char cBuscar );

			string LTrim( const string & sCadena );
			string RTrim( const string & sCadena );
			string Trim( const string & sCadena );

			bool TieneEspacios ( const string & sCadena );
			bool EmpiezaPor ( const string & sCadena, const string & sPrefijo );
			bool TerminaPor ( const string & sCadena, const string & sSufijo );
			bool TerminaEnSaltoLinea ( const string & sCadena );

			string EliminarUltimoSaltoLinea( const string & sCadena );

			bool SonIgualesIn ( const string & sCadena1, const string & sCadena2 );

			bool EsPalabra ( const string & sCadena );
			bool EsToken ( const string & sCadena );
			bool EsNombreFichero ( const string & sCadena );
			bool EsNatural ( const string & sCadena );
			bool EsEntero ( const string & sCadena );
			bool EsReal ( const string & sCadena );
			bool EsBooleano ( const string & sCadena );
			bool EsURL ( const string & sCadena );
			bool EsURN ( const string & sCadena );
			bool EsURI ( const string & sCadena );

			size_t BuscarPrimero( const string & sCadena, const initializer_list<string> & delimitadores, size_t * tamDelim = NULL, size_t posIni = 0 );
			size_t BuscarPrimero( const string & sCadena, const list<string> & delimitadores, size_t * tamDelim = NULL, size_t posIni = 0 );
			vector<string> Separar ( string sCadena, const initializer_list<string> & delimitadores = { " " } );
			vector<string> Separar ( string sCadena, const list<string> & delimitadores ) ;

 			}
		}
	}
}

#endif
