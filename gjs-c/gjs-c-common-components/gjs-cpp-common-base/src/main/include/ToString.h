#ifndef _ORG_GJS_C_CC_CPP_TOSTRING_H
#define _ORG_GJS_C_CC_CPP_TOSTRING_H


#include <string>
#include <list>
#include <vector>
#include <map>
#include <ctime>
#include <format>

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

			string ToString ( long t );
			string ToString ( bool t );
			string ToString ( wstring t );
			string ToString ( wchar_t * t );
			string ToString ( const wchar_t * t );
			string ToString ( const unsigned char t[] );
			string ToString ( const tm * t );

			string ToString ( IToString & t );
			string ToString ( IToString * t );

			string ToTimeString ( time_t t );

			template <typename T> string ToString ( list<T> & lista );
			template <typename T> string ToString ( list<T> * lista );
			template <typename T> string ToString ( vector<T> & vector );
			template <typename T> string ToString ( vector<T> * vector );
			template <typename T> string ToString ( map<string, T> & mapa );
			template <typename T> string ToString ( map<string, T> * mapa );

            string ToString ( short );
            string ToString ( int );
            string ToString ( long );
            string ToString ( long long );
            string ToString ( unsigned short );
            string ToString ( unsigned int );
            string ToString ( unsigned long );
            string ToString ( unsigned long long );
            string ToString ( float );
            string ToString ( double );
            string ToString ( long double );
            string ToString ( char );
            string ToString ( unsigned char );
            string ToString ( char * );
            string ToString ( const char * );
	
			// Pendiente de test
			template<typename... Args> string ToString ( const string & sFormato, Args&&... argumentos );

			}
		}
	}
}

#endif
