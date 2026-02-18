#include "BaseConfig.h"
#include "Codificacion.h"




using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

string UnicodeAUtf8 ( const wstring & valor )
{
    wstring_convert<codecvt_utf8<wchar_t>> conversor;
    return ( conversor.to_bytes( valor ) );
}

string UnicodeAUtf16 ( const wstring & valor )
{
    wstring_convert<codecvt_utf16<wchar_t>> conversor;
    return ( conversor.to_bytes( valor ) );
}

wstring Utf8AUnicode ( const string & valor )
{
    wstring_convert<codecvt_utf8<wchar_t>> conversor;
    return ( conversor.from_bytes( valor ) );
}


wstring Utf16AUnicode ( const string & valor )
{
    wstring_convert<codecvt_utf16<wchar_t>> conversor;
    return ( conversor.from_bytes( valor ) );
}

			}
		}
	}
}
