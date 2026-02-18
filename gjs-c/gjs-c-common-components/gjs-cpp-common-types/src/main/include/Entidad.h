#ifndef _ORG_GJS_C_CC_CPP_ENTIDAD_H
#define _ORG_GJS_C_CC_CPP_ENTIDAD_H

#include <string>
#include <map>
#include <vector>
#include <Atributo.h>
#include <Valor.h>
#include <IComparable.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Entidad : public IComparable
			{
			private:
				string					sNombre;
				map<string, Atributo *>	mapDefinicion;

			public:
				Entidad ();
				explicit Entidad ( const string & _sNombre );
				Entidad ( Entidad & obj );
				explicit Entidad ( Entidad * obj );
				virtual ~Entidad ();

			public:
				virtual long getHash() const override;

			public:
				string getNombre () const;
				void setNombre ( const string & sValor );

				virtual bool EsValida () const;

				int NumAtributos ();
				bool TieneAtributo ( const string & sAtributo );
				Atributo * getAtributo ( const string & sAtributo );
				Atributo * getAtributo ( int iIndice );
				vector<string> * ListaAtributos ();
				int getIndiceAtributo ( const string & sAtributo );
				void InsertarAtributo ( Atributo * atributo );
				void InsertarAtributo ( TipoDatos tipo, const string & sAtributo, bool bAnulable =  true );
				void InsertarAtributo ( Tipo & tipo, const string & sAtributo, bool bAnulable =  true );
				void EliminarAtributo ( const string & sAtributo );
				void EliminarAtributo ( int iIndice );
				void LimpiarAtributos ();

				bool EsCompatible ( Entidad & obj );
				bool EsCompatible ( Entidad * obj );

				void Asignar ( Entidad & obj );
				void Asignar ( Entidad * obj );

				Entidad * Clonar();

				virtual string toString () override;

				Entidad & operator=( Entidad & obj );
				bool operator== ( Entidad & obj );
				bool operator!= ( Entidad & obj );
			};

 			}
		}
	}
}



#endif
