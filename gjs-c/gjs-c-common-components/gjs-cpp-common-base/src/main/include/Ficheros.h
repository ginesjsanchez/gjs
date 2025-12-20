#ifndef _ORG_GJS_C_CC_CPP_FICHEROS_H
#define _ORG_GJS_C_CC_CPP_FICHEROS_H

#include <string>
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

			vector<string> LeerFichero ( const string & sRuta );
			void GuardarFichero ( const string & sRuta, const vector<string> & vecLineas );
			void GuardarFichero ( const string & sRuta, const string & sContenido );
			void ImprimirFichero ( const string & sRuta );
			void EliminarFichero ( const string & sRuta );

			bool FicherosIguales ( const string & sRuta1, const string & sRuta2 );

            }
		}
	}
}

#endif
