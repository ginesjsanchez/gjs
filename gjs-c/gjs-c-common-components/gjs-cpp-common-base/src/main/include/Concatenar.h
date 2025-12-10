#ifndef _ES_INTERIOR_BASE_CONCATENAR_H
#define _ES_INTERIOR_BASE_CONCATENAR_H

#include <string>
#include <list>
#include <initializer_list>


using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			string Concatenar ( const initializer_list<string> & args );
			string Concatenar ( const list<string> & args );
			template<typename... Types> string Concatenar ( Types... args );

 			}
		}
	}
}

#endif
