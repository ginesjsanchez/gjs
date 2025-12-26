#include "BaseConfig.h"
#include "ToInt.h"





using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

long ToInt ( char * t )
{
	return ( ToInt( (const char *)t ) );
}

long ToInt ( const char * t )
{
	long lRes = 0;
	if ( t != NULL )
	{
		try
		{
			if ( strlen( t ) > 0 )
			{
				lRes = atol( t );
			}
		}
		catch (...)
		{
		}
	}
	return ( lRes );
}

long ToInt ( const string & t )
{
	long lRes = 0;
	try
	{
		if ( t.size() > 0 )
		{
			lRes = atol( t.c_str() );
		}
	}
	catch (...)
	{
	}
	return ( lRes );
}


long ToInt ( IToString & t )
{
	return ( ToInt ( t.toString() ) );
}

long ToInt ( IToString * t )
{
	long lRes = 0;
	if ( t != NULL )
	{
		lRes = ToInt ( *t );
	}
	return ( lRes );
}

long ToInt ( const wstring & t )
{
	return ( ToInt( string( t.begin(), t.end() ) ) );
}

long ToInt ( wchar_t * t )
{
	return ( ToInt ( wstring( t ) ) );
}

long ToInt ( const wchar_t * t )
{
	return ( ToInt ( wstring( t ) ) );
}

			}
		}
	}
}

