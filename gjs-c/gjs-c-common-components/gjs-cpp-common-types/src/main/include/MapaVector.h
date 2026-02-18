#ifndef _ORG_GJS_C_CC_CPP_MAPAVECTOR_H
#define _ORG_GJS_C_CC_CPP_MAPAVECTOR_H




#include <string>
#include <unordered_map>
#include <vector>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			template <class T> class MapaVector
			{
			private:

				vector<string> 				vecOrden;
				unordered_map<string, T> 	mapObjetos;

			public:
				MapaVector();
				virtual ~MapaVector();

				size_t size() const noexcept;
				bool empty() const noexcept;
				bool isValid() const noexcept;

				bool exists( const string & sClave );
				T& at( size_t pos );
				T& find( const string & sClave );
				const vector<string> & getKeys();

				void push_back( const string & sClave, const T & obj );
				void push_back( const string & sClave, T & obj );
				void pop_back();
				void erase( size_t pos );
				void erase( const string & sClave );

				void clear() noexcept;

				T& operator[]( size_t pos );
				T& operator[]( const string & sClave );
			};

 			}
		}
	}
}

#endif
