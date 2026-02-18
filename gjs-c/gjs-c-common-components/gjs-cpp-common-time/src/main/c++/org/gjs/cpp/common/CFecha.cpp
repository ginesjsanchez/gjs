/******************************************************************************/
/*                                 CFecha.cpp                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la clase de     */
/* datos CFecha.                                                              */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "CFecha.h"



#include "CommonTimeConfig.h"



// TODO: Revisar si al pasar a sys_days hace falta usar .time_since_epoch() antes de operar como duration

using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

CFecha::CFecha ()
{
	EstablecerValorDeHoy ();
}

CFecha::CFecha ( long lValor )
{
	Establecer ( lValor );
}

CFecha::CFecha ( const string & sValor )
{
	Establecer ( sValor );
}

CFecha::CFecha ( int iA, int iM, int iD )
{
	Establecer ( iA, iM, iD );
}


CFecha::CFecha ( const chrono::year_month_day & ymd )
{
	Establecer ( ymd );
}


CFecha::CFecha ( const chrono::year & y, const chrono::month & m, const std::chrono::day & d )
{
	Establecer ( y, m, d );
}

CFecha::~CFecha()
{
}

void CFecha::Establecer ( long lValor )
{
	int iA = lValor / 10000;
	long lAux = lValor % 10000;
	int iM = lAux / 100;
	int iD = lAux % 100;
	Establecer ( iA, iM, iD );
}

void CFecha::Establecer ( const string & sValor )
{
    Establecer ( ToInt ( sValor ) );
}

void CFecha::Establecer ( int iA, int iM, int iD )
{
    Establecer ( chrono::year ( iA ), chrono::month ( iM ), chrono::day ( iD ) );
}

void CFecha::Establecer ( const chrono::year_month_day & ymd )
{
    ymdFecha = ymd;
}

void CFecha::Establecer ( const chrono::year & y, const chrono::month & m, const chrono::day & d )
{
    Establecer ( chrono::year_month_day ( y, m, d ) );
}

bool CFecha::EsValida ()
{
	return ( ymdFecha.ok() );
}

long CFecha::Valor ()
{
	return ( int( ymdFecha.year() ) * 10000 + ( (int) static_cast<unsigned>(ymdFecha.month()) )  * 100 + (int) static_cast<unsigned>(ymdFecha.day()) );
}

time_t CFecha::ValorTiempo ()
{
    chrono::system_clock::time_point tp = chrono::sys_days ( ymdFecha );
	return ( chrono::system_clock::to_time_t ( tp ) );
}

string * CFecha::ValorCadena ()
{
    return ( new string ( to_string ( Valor() ) ) );
}

string * CFecha::Cadena ( const string & formato )
{
    return ( new string ( vformat ( formato, make_format_args( ymdFecha ) ) ) );
}


int CFecha::AAAA ()
{
	return ( int( ymdFecha.year() ) );
}

int CFecha::MM ()
{
	return ( (int) static_cast<unsigned>( ymdFecha.month() ) );
}

int CFecha::DD ()
{
	return ( (int) static_cast<unsigned>( ymdFecha.day() ) );
}

void CFecha::EstablecerValorDeHoy ()
{
    chrono::system_clock::time_point ahora = chrono::system_clock::now();
    chrono::sys_days dp = chrono::floor<chrono::days>( ahora );
    ymdFecha = chrono::year_month_day ( dp );
}

bool CFecha::EsIgual ( CFecha & fecValor )
{
	return ( EsIgual ( fecValor.Valor () ) );
}

bool CFecha::EsMenor( CFecha & fecValor )
{
	return ( EsMenor ( fecValor.Valor () ) );
}

bool CFecha::EsMayor ( CFecha & fecValor )
{
	return ( EsMayor ( fecValor.Valor () ) );
}

bool CFecha::EsDiferente ( CFecha & fecValor )
{
	return ( EsDiferente ( fecValor.Valor () ) );
}

bool CFecha::EsIgual ( CFecha * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsIgual ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFecha::EsMenor( CFecha * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsMenor( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFecha::EsMayor ( CFecha * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsMayor ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFecha::EsDiferente ( CFecha * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsDiferente ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFecha::EsIgual ( const string & sValor )
{
	return ( EsIgual ( ToInt ( sValor ) ) );
}

bool CFecha::EsMenor( const string & sValor )
{
	return ( EsMenor ( ToInt ( sValor ) ) );
}

bool CFecha::EsMayor ( const string & sValor )
{
	return ( EsMayor ( ToInt ( sValor ) ) );
}

bool CFecha::EsDiferente ( const string & sValor )
{
	return ( EsDiferente ( ToInt ( sValor ) ) );
}

bool CFecha::EsIgual ( long lValor )
{
	return ( Valor() == lValor );
}

bool CFecha::EsMenor( long lValor )
{
	return ( Valor() < lValor );
}

bool CFecha::EsMayor ( long lValor )
{
	return ( Valor() > lValor );
}

bool CFecha::EsDiferente ( long lValor )
{
	return ( Valor() != lValor );
}

bool CFecha::EsIgual ( const chrono::year_month_day & ymd  )
{
	return ( ymdFecha == ymd );
}

bool CFecha::EsMenor ( const chrono::year_month_day & ymd  )
{
	return ( ymdFecha < ymd );
}

bool CFecha::EsMayor ( const chrono::year_month_day & ymd  )
{
	return ( ymdFecha > ymd );
}

bool CFecha::EsDiferente ( const chrono::year_month_day & ymd  )
{
	return ( ymdFecha != ymd );
}

long CFecha::Diferencia ( CFecha & fecValor )
{
	return ( Diferencia ( fecValor.Valor () ) );
}

long CFecha::Diferencia ( CFecha * p_fecValor )
{
    long lRes = LLONG_MAX;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        lRes = Diferencia ( p_fecValor->Valor () );
    }
	return ( lRes );
}

long CFecha::Diferencia ( const string & sValor )
{
	return ( Diferencia ( ToInt ( sValor ) ) );
}

long CFecha::Diferencia ( long lValor )
{
	return ( Valor () - lValor );
}

long CFecha::Diferencia ( const chrono::year_month_day & ymd )
{
	long lValor = int( ymd.year() ) * 10000 + (int) static_cast<unsigned>( ymd.month() )  * 100 + (int) static_cast<unsigned>( ymd.day() );
	return ( Diferencia( lValor ) );
}


bool CFecha::operator == ( CFecha & fecValor )
{
	return ( EsIgual ( fecValor ) );
}

bool CFecha::operator != ( CFecha & fecValor )
{
	return ( EsDiferente ( fecValor ) );
}

bool CFecha::operator < ( CFecha & fecValor )
{
	return ( EsMenor ( &fecValor ) );
}

bool CFecha::operator <= ( CFecha & fecValor )
{
	return ( EsIgual ( fecValor) || EsMenor ( fecValor ) );
}

bool CFecha::operator > ( CFecha & fecValor )
{
	return ( EsMayor ( fecValor) );
}

bool CFecha::operator >= ( CFecha & fecValor )
{
	return ( EsIgual ( fecValor) || EsMayor ( fecValor ) );
}

bool CFecha::operator == ( CFecha * p_fecValor )
{
	return ( EsIgual ( p_fecValor ) );
}

bool CFecha::operator != ( CFecha * p_fecValor )
{
	return ( EsDiferente ( p_fecValor ) );
}

bool CFecha::operator < ( CFecha * p_fecValor )
{
	return ( EsMenor ( p_fecValor ) );
}

bool CFecha::operator <= ( CFecha * p_fecValor )
{
	return ( EsIgual ( p_fecValor) || EsMenor ( p_fecValor ) );
}

bool CFecha::operator > ( CFecha * p_fecValor )
{
	return ( EsMayor ( p_fecValor ) );
}

bool CFecha::operator >= ( CFecha * p_fecValor )
{
	return ( EsIgual ( p_fecValor) || EsMayor ( p_fecValor ) );
}

bool CFecha::operator == ( const string & sValor )
{
	return ( EsIgual ( sValor ) );
}

bool CFecha::operator != ( const string & sValor )
{
	return ( EsDiferente ( sValor ) );
}

bool CFecha::operator < ( const string & sValor )
{
	return ( EsMenor ( sValor ) );
}

bool CFecha::operator <= ( const string & sValor )
{
	return ( EsIgual ( sValor) || EsMenor ( sValor ) );
}

bool CFecha::operator > ( const string &  sValor )
{
	return ( EsMayor ( sValor ) );
}

bool CFecha::operator >= ( const string &  sValor )
{
	return ( EsIgual ( sValor) || EsMayor ( sValor ) );
}

bool CFecha::operator == ( long lValor )
{
	return ( EsIgual ( lValor ) );
}

bool CFecha::operator != ( long lValor )
{
	return ( EsDiferente ( lValor ) );
}

bool CFecha::operator < ( long lValor )
{
	return ( EsMenor ( lValor ) );
}

bool CFecha::operator <= ( long lValor )
{
	return ( EsIgual ( lValor ) || EsMenor ( lValor ) );
}

bool CFecha::operator > ( long lValor )
{
	return ( EsMayor ( lValor ) );
}

bool CFecha::operator >= ( long lValor )
{
	return ( EsIgual ( lValor ) || EsMayor ( lValor ) );
}

bool CFecha::operator == ( const chrono::year_month_day & ymd )
{
	return ( EsIgual ( ymd ) );
}

bool CFecha::operator != ( const chrono::year_month_day & ymd )
{
	return ( EsDiferente ( ymd ) );
}

bool CFecha::operator < ( const chrono::year_month_day & ymd )
{
	return ( EsMenor ( ymd ) );
}

bool CFecha::operator <= ( const chrono::year_month_day & ymd )
{
	return ( EsIgual ( ymd ) || EsMenor ( ymd ) );
}

bool CFecha::operator > ( const chrono::year_month_day & ymd )
{
	return ( EsMayor ( ymd ) );
}

bool CFecha::operator >= ( const chrono::year_month_day & ymd )
{
	return ( EsIgual ( ymd ) || EsMayor ( ymd ) );
}

long CFecha::operator - ( CFecha & fecValor )
{
	return ( Diferencia ( fecValor ) );
}

long CFecha::operator - ( CFecha * p_fecValor )
{
	return ( Diferencia ( p_fecValor ) );
}

long CFecha::operator - ( const string & sValor )
{
	return ( Diferencia ( sValor ) );
}

long CFecha::operator - ( long lValor )
{
	return ( Diferencia ( lValor ) );
}

long CFecha::operator - ( const chrono::year_month_day & ymd )
{
	return ( Diferencia ( ymd ) );
}


 			}
		}
	}
}




