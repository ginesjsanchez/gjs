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
		namespace cpp
		{
            namespace common
            {
			string ToLowerCase ( const string & sCadena );
			string ToUpperCase ( const string & sCadena );

            string ReemplazarTodos ( const string & sCadena, char cBuscar, char cReemplazo );
			string ReemplazarTodos ( const string & sCadena, const string & sBuscar, const string & sReemplazo );
			string EliminarTodos ( const string & sCadena, char cBuscar );
			string EliminarTodos ( const string & sCadena, const string & sBuscar );

            string FormatearBlancos ( const string & sCadena );

			// TODO: Falta el test de esta
			bool ContieneCaracter ( const string & sCadena, char c );
			
            bool ContieneBlancos ( const string & sCadena );
            bool ContieneTabuladores ( const string & sCadena );
            bool ContieneCaracteresNoImprimibles ( const string & sCadena );
            bool ContieneCaracteresNoAlfanumericos ( const string & sCadena );
            bool ContieneCaracteresNoImprimibles ( const string & sCadena );
            bool ContieneCaracteresNoEstandar ( const string & sCadena );

            bool CoherenciaParentesis ( const string & sCadena );
            bool CoherenciaLlaves ( const string & sCadena );
            bool CoherenciaCorchetes ( const string & sCadena );
            bool CoherenciaParejaSignos ( const string & sCadena, char cSigAp, char cSigCl );

            string EliminarCaracter ( const string & sCadena, int iCar );
            string EliminarCaracteres ( const string & sCadena, int iPosIni, int iNumCars );
            string EliminarPrimerosCaracteres ( const string & sCadena, int iNumCars );
            string EliminarUltimosCaracteres ( const string & sCadena, int iNumCars );
            string EliminarApariciones ( const string & sCadena1, const string & sCadena2 );
            string EliminarBlancos ( const string & sCadena );
            string EliminarTabuladores ( const string & sCadena );
            string EliminarCaracteresNoAlfanumericos ( const string & sCadena );
            string EliminarCaracteresNoImprimibles ( const string & sCadena );
            string EliminarCaracteresNoEstandar ( const string & sCadena );
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
			// TODO: Falta el test de esta
			size_t BuscarDesdeAtrasCaracter( const string & sCadena, char c, size_t desde = string::npos );

			vector<string> Separar ( string sCadena, const initializer_list<string> & delimitadores = { " " } );
			vector<string> Separar ( string sCadena, const list<string> & delimitadores );

			// TODO: Falta el test de estas
			int NumPalabras( const string & cadena, char delimitador );
			string ExtraerPalabra( const string & sCadena, int iPos, char cDelimitador ); 
		
 			}
		}
	}
}

#endif
