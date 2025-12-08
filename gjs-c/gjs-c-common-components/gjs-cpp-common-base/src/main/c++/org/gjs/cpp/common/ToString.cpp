#include "BaseConfig.h"
#include "ToString.h"

//#include <locale>
//#include <codecvt>

using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

string ToString ( IToString & t )
{
	try
	{
		ostringstream conv;

		conv << t;
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

string ToString ( IToString * t )
{
	if ( t != NULL )
	{
		return ( ToString( *t ) );
	}
	else
	{
		return ( string( "[Object Error]" ) );
	}
}

string ToString ( bool t )
{
	if ( t )
	{
		return ( string( "Cierto" ) );
	}
	else
	{
		return ( string( "Falso" ) );
	}
}

string ToString ( wstring t )
{
	return ( string( t.begin(), t.end() ) );
}

string ToString ( wchar_t * t )
{
	return ( ToString ( wstring( t ) ) );
}

string ToString ( const wchar_t * t )
{
	return ( ToString ( wstring( t ) ) );
}

string ToString ( const unsigned char t[] )
{
	try
	{
		ostringstream conv;
		conv << '{';
		conv << hex << uppercase;
		int iPos = 0;
		while ( t[ iPos ] != 0x00 )
		{
			if ( iPos > 0 )
			{
				conv << ", ";
			}
			conv << t[ iPos ];
			iPos = iPos + 1;
		}
		conv << '}';
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

string ToString ( const tm * t )
{
	char buffer [ 9 ];
	strftime ( buffer, 9, "%H:%M:%S", t );
	return ( ToString ( buffer ) );
}

string ToTimeString ( time_t t )
{
	char buffer [ 9 ];
	strftime ( buffer, 9, "%H:%M:%S", localtime( &t ) );
	return ( ToString ( buffer ) );
}

template <typename T>
string ToString ( T t )
{
	try
	{
		ostringstream conv;

		conv << t;
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

template string ToString ( bool );
template string ToString ( short );
template string ToString ( int );
template string ToString ( long );
template string ToString ( long long );
template string ToString ( unsigned short );
template string ToString ( unsigned int );
template string ToString ( unsigned long );
template string ToString ( unsigned long long );
template string ToString ( float );
template string ToString ( double );
template string ToString ( long double );
template string ToString ( char );
template string ToString ( unsigned char );
template string ToString ( char * );
template string ToString ( const char * );


template <typename T>
string ToString ( list<T> & lista )
{
	try
	{
		ostringstream conv;

		for ( auto & linea : lista )
		{
			conv << linea << endl;
		}
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

template <typename T>
string ToString ( list<T> * lista )
{
	if ( lista != NULL )
	{
		return ( ToString ( *lista ) );
	}
	else
	{
		return ( string( "[Object Error]" ) );
	}
}

template <typename T>
string ToString ( vector<T> & vector )
{
	try
	{
		ostringstream conv;

		for ( auto & linea : vector )
		{
			conv << linea << endl;
		}
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

template <typename T>
string ToString ( vector<T> * vector )
{
	if ( vector != NULL )
	{
		return ( ToString ( *vector ) );
	}
	else
	{
		return ( string( "[Object Error]" ) );
	}
}

template <typename T>
string ToString ( map<string, T> & mapa )
{
	try
	{
		ostringstream conv;

		for ( auto & linea : mapa )
		{
			conv << linea.first << "=" << linea.second << endl;
		}
		return ( conv.str () );
	}
	catch (...)
	{
		return ( string( "[Object Error]" ) );
	}
}

template <typename T>
string ToString ( map<string, T> * mapa )
{
	if ( mapa != NULL )
	{
		return ( ToString ( *mapa ) );
	}
	else
	{
		return ( string( "[Object Error]" ) );
	}
}



template string ToString ( list<string> & );
template string ToString ( list<string> * );
template string ToString ( vector<string> & );
template string ToString ( vector<string> * );
template string ToString ( map<string, string> & );
template string ToString ( map<string, string> * );


			}
		}
	}
}
