#ifndef _ORG_GJS_CC_CPP_BASE_TOREAL_H
#define _ORG_GJS_CC_CPP_BASE_TOREAL_H



#include <string>

#include <IToString.h>



using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			double ToDouble ( const string & t );
			double ToDouble ( char * t );
			double ToDouble ( const char * t );
			double ToDouble ( const wstring & t );
			double ToDouble ( wchar_t * t );
			double ToDouble ( const wchar_t * t );

			double ToDouble ( IToString & t );
			double ToDouble ( IToString * t );

 			}
		}
	}
}


#endif
