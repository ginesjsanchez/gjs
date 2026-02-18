#ifndef _ORG_GJS_C_CC_CPP_PROPIEDADES_H
#define _ORG_GJS_C_CC_CPP_PROPIEDADES_H

#include <NoEncontradoExcepcion.h>

#include <string>
#include <vector>
#include <map>



using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Propiedades
			{
			private:
				vector<string> vecClaves;
				map<string, string> mapPropiedades;

			public:
				Propiedades();
				explicit Propiedades( const string & sRuta );
				virtual ~Propiedades();

				string getPropiedad( const string & sClave ) const;
				string getPropiedad( const string & sClave, const string & sValorDef ) const;
				void setPropiedad( const string & sClave, const string & sValor );

				vector<string> getPropiedades() const;
				bool ExistePropiedad( const string & sClave ) const;
				int NumPropiedades() const;

				void EliminarPropiedad( const string& sClave );

				bool Cargar( const string & sRuta );
				bool Guardar(  const string & sRuta );

			private:
				bool EsPropiedad( const string & sLinea );
				pair<string, string> ParsearPropiedad( const string & sLinea );

			};

 			}
		}
	}
}


#endif
