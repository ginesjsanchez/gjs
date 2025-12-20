#ifndef _ORG_GJS_C_CC_CPP_COLECCIONES_H
#define _ORG_GJS_C_CC_CPP_COLECCIONES_H

#include <string>
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

			vector<string> ToVector ( const initializer_list<string> & args );
			list<string> ToList ( const initializer_list<string> & args );

			bool SonIguales ( list<string> & lisObj1, list<string> & lisObj2 );
			bool SonIguales ( vector<string> & vecObj1, vector<string> & vecObj2 );

            }
		}
	}
}

#endif
