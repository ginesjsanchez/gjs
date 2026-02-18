#ifndef _ORG_GJS_C_CC_CPP_CODIFICACION_H
#define _ORG_GJS_C_CC_CPP_CODIFICACION_H

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
// TODO UTF32 UCS2
// Utf8 ascii
// Utf 16x -> utf8
// Utf 16x -> ascii

			string UnicodeAUtf8 ( const wstring & valor );
			string UnicodeAUtf16 ( const wstring & valor );

			wstring Utf8AUnicode ( const string & valor );
			wstring Utf16AUnicode ( const string & valor );

			}
		}
	}
}

#endif
