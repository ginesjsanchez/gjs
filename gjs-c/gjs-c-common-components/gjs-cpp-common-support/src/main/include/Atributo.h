#ifndef _ORG_GJS_C_CC_CPP_ATRIBUTO_H
#define _ORG_GJS_C_CC_CPP_ATRIBUTO_H

#include <string>
#include <Tipo.h>
#include <Valor.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			class Atributo : public Tipo
			{
			private:
				TipoDatos		tipo;
				string 			sNombre;
				bool			bAnulable;

			public:
				Atributo ();
				Atributo ( TipoDatos _tipo, const string & _sNombre, bool _bAnulable =  true );
				Atributo ( Tipo & _tipo, const string & _sNombre, bool _bAnulable =  true );
				Atributo ( Atributo & atributo );
				explicit Atributo ( Atributo * atributo );
				virtual ~Atributo ();

			public:
				virtual long getHash() const override;

			public:
				string getNombre () const;
				void setNombre ( const string & sValor );

				bool isAnulable () const;
				void setAnulable ( bool bValor );

				void Asignar ( Atributo & atributo );
				void Asignar ( Atributo * atributo );

				Atributo * Clonar();

				virtual bool EsValido () const override;

				bool EsCompatible ( Atributo & atributo ) const;
				bool EsCompatible ( Atributo * atributo ) const;
				bool EsCompatible ( Valor & valor ) const;
				bool EsCompatible ( Valor * valor ) const;

				virtual string toString () override;

				Atributo & operator=( Atributo & atributo );
				bool operator== ( Atributo & obj );
				bool operator!= ( Atributo & obj );
			};

 			}
		}
	}
}



#endif
