#ifndef _ORG_GJS_C_CC_CPP_MEMORIAGLOBAL_H
#define _ORG_GJS_C_CC_CPP_MEMORIAGLOBAL_H

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

			void MemGlobGuardar ( const string & sClave, const string & sValor );
			string MemGlobRecuperar ( const string & sClave );
			void MemGlobEliminar ( const string & sClave );
			bool MemGlobExiste ( const string & sClave );

			void MemGlobLimpiar ();

 			}
		}
	}
}

#endif
