#ifndef _ORG_GJS_C_CC_CPP_CONJUNTO_VALORES_H
#define _ORG_GJS_C_CC_CPP_CONJUNTO_VALORES_H

#include <map>
#include <list>
#include <initializer_list>
#include <Valor.h>
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

			class ConjuntoValores : public IToString
			{
			private:
				map<string, Valor *>	mapValores;
				bool 					bPermiteInsercion = true;

			public:
				ConjuntoValores ();
				ConjuntoValores ( const initializer_list<string> & lisAtributos, bool _bPermiteInsercion = false );
				ConjuntoValores ( const list<string> & lisAtributos, bool _bPermiteInsercion = false );
				ConjuntoValores ( const string & sRuta, bool _bPermiteInsercion = false );
				virtual ~ConjuntoValores ();

			protected:
				virtual long getHash() const;

			public:
				int NumValores () const;
				Valor * getValor ( const string & sAtributo );
				bool ExisteValor( const string & sAtributo );
				void InsertarValor ( const string & sAtributo, Valor * valor );
				void InsertarValor ( const string & sAtributo, const string & sValor );
				void InsertarValor ( const string & sAtributo, const char * p_cValor );
				void InsertarValor ( const string & sAtributo, bool _valor );
				void InsertarValor ( const string & sAtributo, short _valor );
				void InsertarValor ( const string & sAtributo, int _valor );
				void InsertarValor ( const string & sAtributo, long _valor );
				void InsertarValor ( const string & sAtributo, long long _valor );
				void InsertarValor ( const string & sAtributo, unsigned short _valor );
				void InsertarValor ( const string & sAtributo, unsigned int _valor );
				void InsertarValor ( const string & sAtributo, unsigned long _valor );
				void InsertarValor ( const string & sAtributo, unsigned long long _valor );
				void InsertarValor ( const string & sAtributo, float _valor );
				void InsertarValor ( const string & sAtributo, double _valor );
				void InsertarValor ( const string & sAtributo, long double _valor );
				void InsertarValor ( const string & sAtributo, char _valor );
				void InsertarValor ( const string & sAtributo, unsigned char _valor );
				void EliminarValor ( const string & sAtributo );
				void LimpiarValores ();

				bool Cargar( const string & sRuta );

				virtual bool EsValido () const;

				virtual string toString () override;

			};

 			}
		}
	}
}



#endif
