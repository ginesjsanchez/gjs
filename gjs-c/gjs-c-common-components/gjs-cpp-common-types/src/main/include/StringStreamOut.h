#ifndef _ORG_GJS_C_CC_CPP_STRINGSTREAMOUT_H
#define _ORG_GJS_C_CC_CPP_STRINGSTREAMOUT_H

#include <sstream>
#include <iostream>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class StringStreamOut : public stringstream
			{

			public:
				StringStreamOut ();
				~StringStreamOut ();

				StringStreamOut& put ( char c );
				StringStreamOut& write ( const char * s, streamsize n );

				template<typename T> StringStreamOut& operator<< ( T val )
				{
					cout << val;
					static_cast<std::ostream&>( *this ) << val;
					return( *this );
				}

				StringStreamOut& operator<< ( const string & val );
				StringStreamOut& operator<< ( streambuf * sb );
				StringStreamOut& operator<< ( ostream& (*pf)(ostream&) );
				StringStreamOut& operator<< ( ios& (*pf)(ios&) );
				StringStreamOut& operator<< ( ios_base& (*pf)(ios_base&) );

			};

 			}
		}
	}
}

#endif
