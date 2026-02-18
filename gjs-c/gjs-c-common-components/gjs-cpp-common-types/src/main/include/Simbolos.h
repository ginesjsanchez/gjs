#ifndef _ORG_GJS_C_CC_CPP_SIMBOLOS_H
#define _ORG_GJS_C_CC_CPP_SIMBOLOS_H

#include <string>
#include <vector>
#include <list>
#include <initializer_list>
#include <ostream>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			// TODO: Completar
			class Simbolos
			{
			private:
				vector<string> vecContenido;

			public:
				Simbolos ();
				explicit Simbolos ( const initializer_list<string> & args );
				explicit Simbolos ( const list<string> & args );
				explicit Simbolos ( const vector<string> & args );

				int Tam ();
				string Simbolo ( int i );
				void Insertar ( const string & simbolo );

				string& operator[] ( int i );

				friend ostream& operator<< ( ostream & strm, const Simbolos & simbolos );
			};

 			}
		}
	}
}

#endif
