#ifndef _ORG_GJS_C_CC_CPP_FICHERO_FORMATEADO_H
#define _ORG_GJS_C_CC_CPP_FICHERO_FORMATEADO_H

#include <vector>
#include <list>
#include <Excepcion.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			// TODO: Rutinas de edición y guardado
			class FicheroFormateado
			{
			private:
				list<string> 			lisSeparadores;
				string 					sFichero;
				bool					bCargado = false;
				vector<vector<string>>	vecContenido;

			public:
				explicit FicheroFormateado ( const initializer_list<string> & delimitadores );
				virtual ~FicheroFormateado ();

			public:
				bool Cargar( const string & sRuta );
				//bool Cargar();
				//bool Guardar( const string & sRuta );
				//bool Guardar();

				string getRuta() const;

				int NumLineas() const;
				vector<string> & Linea( int iLinea );
				int NumCamposLinea( int iLinea ) const;
				string Campo( int iLinea, int iCampo );

			private:
				void Vaciar();

			};

			class FicheroTSV : public FicheroFormateado
			{
			public:
				FicheroTSV () : FicheroFormateado ( { "\t" } ) {};
			};

			class FicheroCSV : public FicheroFormateado
			{
			public:
				FicheroCSV () : FicheroFormateado ( { "," } ) {};
			};

			class FicheroDSV : public FicheroFormateado
			{
			public:
				FicheroDSV () : FicheroFormateado ( { ";" } ) {};
			};

 			}
		}
	}
}



#endif
