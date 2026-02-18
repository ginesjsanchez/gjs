
#include "Atributo.h"
#include <Cadenas.h>
#include <ToString.h>
#include <Concatenar.h>



using namespace org::gjs::cpp::common;
using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


Atributo::Atributo () : Tipo ( TipoDatos::INDEFINIDO )
{
	sNombre = string( "" );
	bAnulable = true;
}

Atributo::Atributo ( TipoDatos _tipo, const string & _sNombre, bool _bAnulable ) : Tipo ( _tipo )
{
	sNombre = _sNombre;
	bAnulable = _bAnulable;
}

Atributo::Atributo ( Tipo & _tipo, const string & _sNombre, bool _bAnulable ) : Tipo ( _tipo.getTipo() )
{
	sNombre = _sNombre;
	bAnulable = _bAnulable;
}

Atributo::Atributo( Atributo & atributo )
{
	Asignar( atributo );
}

Atributo::Atributo ( Atributo * atributo )
{
	Asignar( atributo );
}

Atributo::~Atributo ()
{
}

long Atributo::getHash () const
{
	return( 10 * hash<string>{}( sNombre ) + Tipo::getHash() );
}

string Atributo::getNombre () const
{
	return( sNombre );
}

bool Atributo::isAnulable () const
{
	return( bAnulable );
}

void Atributo::setNombre( const string & sValor )
{
	sNombre = sValor;
}

void Atributo::setAnulable( bool bValor )
{
	bAnulable = bValor;
}

void Atributo::Asignar( Atributo & atributo )
{
	sNombre = atributo.getNombre();
	setTipo( atributo.getTipo() );
	bAnulable = atributo.isAnulable();
}

void Atributo::Asignar( Atributo * atributo )
{
	if ( atributo != NULL )
	{
		sNombre = atributo->getNombre();
		setTipo( atributo->getTipo() );
		bAnulable = atributo->isAnulable();
	}
}

Atributo * Atributo::Clonar()
{
	return ( new Atributo( getTipo(), sNombre, bAnulable ) );
}

bool Atributo::EsValido () const
{
	return( Tipo::EsValido() && EsToken( sNombre ) );
}

bool Atributo::EsCompatible ( Atributo & atributo ) const
{
	bool bRes = false;
	if ( Tipo::EsCompatible( (Tipo &)atributo ) )
	{
		bRes = isAnulable() || !atributo.isAnulable();
	}
	return ( bRes );
}

bool Atributo::EsCompatible ( Atributo * atributo ) const
{
	bool bRes = false;
	if ( atributo != NULL )
	{
		bRes = EsCompatible ( *atributo );
	}
	return ( bRes );
}

bool Atributo::EsCompatible ( Valor & valor ) const
{
	bool bRes = false;
	if ( isAnulable() && valor.EsNulo() )
	{
		bRes = true;
	}
	else
	{
		bRes = Tipo::EsCompatible( valor.getValor() );
	}
	return ( bRes );
}

bool Atributo::EsCompatible ( Valor * valor ) const
{
	bool bRes = false;
	if ( valor != NULL )
	{
		bRes = EsCompatible ( *valor );
	}
	return ( bRes );
}

string Atributo::toString ()
{
	return ( Concatenar( "[Atributo={Tipo=", Tipo::toString(), "; Nombre=[", getNombre(), "]; Anulable=", ToString( isAnulable() ), "}]" ) );
}

Atributo & Atributo::operator= ( Atributo & atributo )
{
	Asignar( atributo );
	return ( *this );
}

bool Atributo::operator== ( Atributo & obj )
{
	return ( IComparable::operator==( obj ) );
}

bool Atributo::operator!= ( Atributo & obj )
{
	return ( IComparable::operator!=( obj ) );
}

 			}
		}
	}
}
