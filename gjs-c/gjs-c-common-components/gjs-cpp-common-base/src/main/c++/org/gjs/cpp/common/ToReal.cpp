#include "BaseConfig.h"
#include "ToReal.h"





using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

double ToDouble ( char * t )
{
	return ( ToDouble( (const char *)t ) );
}

double ToDouble ( const char * t )
{
	double dRes = 0.0;
	if ( t != NULL )
	{
		try
		{
			if ( strlen( t ) > 0 )
			{
				dRes = atof( t );
			}
		}
		catch (...)
		{
		}
	}
	return ( dRes );
}

double ToDouble ( const string & t )
{
	double dRes = 0.0;
	try
	{
        dRes = stold( t );
	}
	catch (...)
	{
	}
	return ( dRes );
}


double ToDouble ( IToString & t )
{
	return ( ToDouble ( t.toString() ) );
}

double ToDouble ( IToString * t )
{
	double dRes = 0;
	if ( t != NULL )
	{
		dRes = ToDouble ( *t );
	}
	return ( dRes );
}

double ToDouble ( const wstring & t )
{
	return ( ToDouble( string( t.begin(), t.end() ) ) );
}

double ToDouble ( wchar_t * t )
{
	return ( ToDouble ( wstring( t ) ) );
}

double ToDouble ( const wchar_t * t )
{
	return ( ToDouble ( wstring( t ) ) );
}
			}
		}
	}
}

