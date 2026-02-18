
#include "Fecha.h"

#include "CommonTimeConfig.h"

#include "TiempoNumerico.h"
#include "TiempoSistema.h"
#include "Fechas.h"




using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {







Fecha::Fecha () 
{
	EstablecerValorDeHoy ();
}

Fecha::Fecha ( int iAAAA, int iMM, int iDD  )
{
	Establecer ( iAAAA, iMM, iDD );
}

Fecha::Fecha ( long lValor ) 
{
	Establecer ( lValor );
}
	
Fecha::Fecha ( const string & sValor ) 
{
	Establecer ( sValor );
}
	
Fecha::~Fecha()
{
}

bool Fecha::Establecer ( int iAAAA, int iMM, int iDD )
{
	fecha = chrono::year_month_day ( chrono::year{ iAAAA },
									chrono::month{ static_cast<unsigned>( iMM ) },
									chrono::day{ static_cast<unsigned>( iDD ) } );
	return ( EsValida() );											
}

bool Fecha::Establecer ( long lValor )
{
	int iAAAA = 0;
	int iMM = 0;
	int iDD = 0;
	FecFormDescomponer ( lValor, &iAAAA, &iMM, &iDD );
	return ( Establecer ( iAAAA, iMM, iDD ) );
}bool Fecha::Establecer ( const string & sValor )
{
	return ( Establecer ( ToInt ( sValor ) ) );
}

bool Fecha::EsValida ()
{
	return ( fecha.ok() );
}

long Fecha::Valor () const
{
	return ( FecFormConstruir ( AAAA (), MM (), DD () ) );
}

string Fecha::Formatear ( const string & sFormato  )
{
	return ( vformat( sFormato.c_str(), make_format_args( fecha ) ) );
}

chrono::year_month_day Fecha::ToYMD () const
{
	return ( fecha );	
}

int Fecha::AAAA () const
{
	return ( int( fecha.year() ) );
}

int Fecha::MM () const
{
	return ( int( unsigned( fecha.month() ) ) );
}

int Fecha::DD () const
{
	return ( int( unsigned( fecha.day() ) ) );
}

void Fecha::EstablecerValorDeHoy ()
{
	Establecer ( TiempoHoy () );
}

bool Fecha::EsIgual ( const Fecha & fecValor )
{
	return ( EsIgual ( fecValor.Valor () ) );
}

bool Fecha::EsMenor( const Fecha & fecValor )
{
	return ( EsMenor ( fecValor.Valor () ) );
}

bool Fecha::EsMayor ( const Fecha & fecValor )
{
	return ( EsMayor ( fecValor.Valor () ) );
}

bool Fecha::EsDiferente ( const Fecha & fecValor )
{
	return ( EsDiferente ( fecValor.Valor () ) );
}

bool Fecha::EsIgual ( const string & sValor )
{
	return ( EsIgual ( ToInt( sValor ) ) );
}

bool Fecha::EsMenor( const string & sValor )
{
	return ( EsMenor ( ToInt( sValor ) ) );
}

bool Fecha::EsMayor ( const string & sValor )
{
	return ( EsMayor ( ToInt( sValor ) ) );
}

bool Fecha::EsDiferente ( const string & sValor )
{
	return ( EsDiferente ( ToInt( sValor ) ) );
}

bool Fecha::EsIgual ( long lValor )
{
	return ( Valor () == lValor );
}

bool Fecha::EsMenor( long lValor )
{
	return ( Valor () < lValor );
}

bool Fecha::EsMayor ( long lValor )
{
	return ( Valor () > lValor );
}

bool Fecha::EsDiferente ( long lValor )
{
	return ( Valor () != lValor );
}

long Fecha::Diferencia ( const Fecha & fecValor )
{
    chrono::sys_days dias1{ fecha };
    chrono::sys_days dias2{ fecValor.ToYMD() };

    auto diferencia = dias2 - dias1;	
	return ( diferencia.count()  );
}

long Fecha::Diferencia ( const string & sValor )
{
	return ( Diferencia ( Fecha ( sValor ) ) );
}

long Fecha::Diferencia ( long lValor )
{
	return ( Diferencia ( Fecha ( lValor ) ) );
}


bool Fecha::operator == ( const Fecha & fecValor )
{
	return ( EsIgual ( fecValor ) );
}

bool Fecha::operator != ( const Fecha & fecValor )
{
	return ( EsDiferente ( fecValor ) );
}

bool Fecha::operator < ( const Fecha & fecValor )
{
	return ( EsMenor ( fecValor )  );
}

bool Fecha::operator <= ( const Fecha & fecValor )
{
	return ( EsIgual ( fecValor ) || 
		 EsMenor ( fecValor ) );
}

bool Fecha::operator > ( const Fecha & fecValor )
{
	return ( EsMayor ( fecValor )  );
}

  bool Fecha::operator >= ( const Fecha & fecValor )
{
	return ( EsIgual ( fecValor ) || 
		 EsMayor( fecValor ) );
}

long Fecha::operator - ( const Fecha & fecValor )
{
	return ( Diferencia ( fecValor ) );
}




 			}
		}
	}
}


