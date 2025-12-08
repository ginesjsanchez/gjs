#ifndef _ORG_GJS_C_CC_CPP_ITOSTRING_H
#define _ORG_GJS_C_CC_CPP_ITOSTRING_H



#include <string>
#include <ostream>
#include <list>
#include <vector>
#include <map>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace c
		{
            namespace common
            {

            class IToString
			{

			public:
				IToString();
				virtual ~IToString();

				virtual string toString() = 0;
				IToString& Base() const;

				friend ostream& operator<< ( ostream & strm, IToString & obj );

			};

			string ToString ( list<IToString *> & lista );
			string ToString ( list<IToString *> * lista );
			string ToString ( vector<IToString *> & vector );
			string ToString ( vector<IToString *> * vector );
			string ToString ( map<string, IToString *> & mapa );
			string ToString ( map<string, IToString *> * mapa );

			}
		}
	}
}


#endif
