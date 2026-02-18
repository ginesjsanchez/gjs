/******************************************************************************/
/*                               CFechaHora.cpp                               */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la clase de     */
/* datos CFechaHora.                                                          */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "CFechaHora.h"





#include "CommonTimeConfig.h"



using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


CFechaHora::CFechaHora ()
{
	EstablecerValorDeAhora ();
}

CFechaHora::CFechaHora ( long long llValor )
{
	Establecer ( llValor );
}

CFechaHora::CFechaHora ( const string & sValor )
{
	Establecer ( sValor );
}

CFechaHora::CFechaHora ( long lFecha, long lHora )
{
	Establecer ( lFecha, lHora );
}

CFechaHora::CFechaHora ( int iA, int iM, int iD, int iHH, int iMI, int iSS )
{
	Establecer ( iA, iM, iD, iHH, iMI, iSS );
}


CFechaHora::CFechaHora ( const chrono::system_clock::time_point & tp )
{
	Establecer ( tp );
}

CFechaHora::CFechaHora ( CFecha & fecFecha, CHora & horHora )
{
	Establecer ( fecFecha, horHora );
}

CFechaHora::CFechaHora ( const chrono::year_month_day & ymd, const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	Establecer ( ymd, hms );
}

CFechaHora::CFechaHora ( const chrono::year & y, const chrono::month & m, const chrono::day & d,
               const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss )
{
	Establecer ( y, m, d, hh, mi, ss );
}

CFechaHora::~CFechaHora()
{
}

void CFechaHora::Establecer ( long long llValor )
{
    long lValorDia = llValor / 1000000;
    long lValorHora = llValor % 1000000;
	Establecer ( lValorDia, lValorHora );
}

void CFechaHora::Establecer ( const string & sValor )
{
    Establecer ( ToLLong ( sValor ) );
}

void CFechaHora::Establecer ( int iA, int iM, int iD, int iHH, int iMI, int iSS )
{
    Establecer ( chrono::year ( iA ), chrono::month ( iM ), chrono::day ( iD ),
                chrono::hours ( iHH ), chrono::minutes ( iMI ), chrono::seconds ( iSS ) );
}

void CFechaHora::Establecer ( long lFecha, long lHora )
{
	int iA = lFecha / 10000;
	long lAux = lFecha % 10000;
	int iM = lAux / 100;
	int iD = lAux % 100;
	int iHH = lHora / 10000;
	lAux = lHora % 10000;
	int iMI = lAux / 100;
	int iSS = lAux % 100;
	Establecer ( iA, iM, iD, iHH, iMI, iSS );
}

void CFechaHora::Establecer ( const chrono::system_clock::time_point & tp )
{
    tpFechaHora = tp;
}

void CFechaHora::Establecer ( CFecha & fecFecha, CHora & horHora )
{
    Establecer ( fecFecha.Valor(), horHora.Valor() );
}

void CFechaHora::Establecer ( const chrono::year_month_day & ymd, const chrono::hh_mm_ss<chrono::seconds> & hms )
{
    Establecer ( chrono::system_clock::time_point ( chrono::sys_days( ymd ) + hms.to_duration() ) );
}

void CFechaHora::Establecer ( const chrono::year & y, const chrono::month & m, const chrono::day & d,
            const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss )
{
    Establecer ( chrono::sys_days ( chrono::year_month_day ( y, m, d ) ) +
                hh + mi + ss );
}

bool CFechaHora::EsValida ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymd = chrono::year_month_day ( dias );
    chrono::hh_mm_ss hms = chrono::hh_mm_ss{ tpFechaHora - dias };
    return ( ymd.ok() &&
        ( hms.hours().count() >= 0 ) && ( hms.hours().count() < 24 ) &&
        ( hms.minutes().count() >= 0 ) && ( hms.minutes().count() < 60 ) &&
        ( hms.seconds().count() >= 0 ) && ( hms.seconds().count() < 60 ) );
}

long long CFechaHora::Valor ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymdFecha = chrono::year_month_day ( dias );
    chrono::hh_mm_ss hmsHora = chrono::hh_mm_ss{ tpFechaHora - dias };
	long long llFecha = int( ymdFecha.year() ) * 10000 +
        (int) static_cast<unsigned>( ymdFecha.month() )  * 100 +
        (int) static_cast<unsigned>( ymdFecha.day() );
	long long llHora = hmsHora.hours().count() * 10000 +
        hmsHora.minutes().count()  * 100 +
        hmsHora.seconds().count();
    return ( llFecha * 1000000 + llHora );
}

long CFechaHora::ValorFecha ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymdFecha = chrono::year_month_day ( dias );
	return ( int( ymdFecha.year() ) * 10000 +
        (int) static_cast<unsigned>( ymdFecha.month() )  * 100 +
        (int) static_cast<unsigned>( ymdFecha.day() ) );
}

long CFechaHora::ValorHora ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::hh_mm_ss hmsHora = chrono::hh_mm_ss{ tpFechaHora - dias };
	return ( hmsHora.hours().count() * 10000 +
        hmsHora.minutes().count()  * 100 +
        hmsHora.seconds().count() );
}

string * CFechaHora::ValorCadena ()
{
    return ( new string ( to_string ( Valor() ) ) );
}

string * CFechaHora::Cadena ( const string & formato )
{
    return ( new string ( vformat ( formato, make_format_args( tpFechaHora ) ) ) );
}

CFecha * CFechaHora::Fecha ()
{
	return ( new CFecha ( ValorFecha()) );
}

CHora * CFechaHora::Hora ()
{
	return ( new CHora ( ValorHora()) );
}


int CFechaHora::AAAA ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymd = chrono::year_month_day ( dias );
	return ( int( ymd.year() ) );
}

int CFechaHora::MM ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymd = chrono::year_month_day ( dias );
	return ( (int) static_cast<unsigned>( ymd.month() ) );
}

int CFechaHora::DD ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::year_month_day ymd = chrono::year_month_day ( dias );
	return ( (int) static_cast<unsigned>(  ymd.day() ) );
}

int CFechaHora::HH ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::hh_mm_ss hms= chrono::hh_mm_ss{ tpFechaHora - dias };
	return ( hms.hours().count() );
}

int CFechaHora::MI ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::hh_mm_ss hms= chrono::hh_mm_ss{ tpFechaHora - dias };
	return ( hms.minutes().count() );
}

int CFechaHora::SS ()
{
    chrono::sys_days dias = chrono::floor<chrono::days>( tpFechaHora );
    chrono::hh_mm_ss hms= chrono::hh_mm_ss{ tpFechaHora - dias };
	return ( hms.seconds().count() );
}

void CFechaHora::EstablecerValorDeAhora ()
{
    tpFechaHora = chrono::system_clock::now();
}

bool CFechaHora::EsIgual ( CFechaHora & fecValor )
{
	return ( EsIgual ( fecValor.Valor () ) );
}

bool CFechaHora::EsMenor( CFechaHora & fecValor )
{
	return ( EsMenor ( fecValor.Valor () ) );
}

bool CFechaHora::EsMayor ( CFechaHora & fecValor )
{
	return ( EsMayor ( fecValor.Valor () ) );
}

bool CFechaHora::EsDiferente ( CFechaHora & fecValor )
{
	return ( EsDiferente ( fecValor.Valor () ) );
}

bool CFechaHora::EsIgual ( CFechaHora * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsIgual ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFechaHora::EsMenor( CFechaHora * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsMenor( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFechaHora::EsMayor ( CFechaHora * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsMayor ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFechaHora::EsDiferente ( CFechaHora * p_fecValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        bRes = EsDiferente ( p_fecValor->Valor () );
    }
	return ( bRes );
}

bool CFechaHora::EsIgual ( const string & sValor )
{
	return ( EsIgual ( ToLLong ( sValor ) ) );
}

bool CFechaHora::EsMenor( const string & sValor )
{
	return ( EsMenor ( ToLLong ( sValor ) ) );
}

bool CFechaHora::EsMayor ( const string & sValor )
{
	return ( EsMayor ( ToLLong ( sValor ) ) );
}

bool CFechaHora::EsDiferente ( const string & sValor )
{
	return ( EsDiferente ( ToLLong ( sValor ) ) );
}

bool CFechaHora::EsIgual ( long long llValor )
{
	return ( Valor() == llValor );
}

bool CFechaHora::EsMenor( long long llValor )
{
	return (  Valor() < llValor );
}

bool CFechaHora::EsMayor ( long long llValor )
{
	return (  Valor() > llValor );
}

bool CFechaHora::EsDiferente ( long long llValor )
{
	return (  Valor() != llValor );
}

long CFechaHora::Diferencia ( CFechaHora & fecValor )
{
	return ( Diferencia ( fecValor.Valor () ) );
}

long CFechaHora::Diferencia ( CFechaHora * p_fecValor )
{
    long lRes = LLONG_MAX;
    if ( ES_VALIDO ( p_fecValor ) )
    {
        lRes = Diferencia ( p_fecValor->Valor () );
    }
	return ( lRes );
}

long CFechaHora::Diferencia ( const string & sValor )
{
	return ( Diferencia ( ToLLong ( sValor ) ) );
}

long CFechaHora::Diferencia ( long long llValor )
{
	return ( Valor () - llValor );
}

bool CFechaHora::operator == ( CFechaHora & fecValor )
{
	return ( EsIgual ( fecValor ) );
}

bool CFechaHora::operator != ( CFechaHora & fecValor )
{
	return ( EsDiferente ( fecValor ) );
}

bool CFechaHora::operator < ( CFechaHora & fecValor )
{
	return ( EsMenor ( &fecValor ) );
}

bool CFechaHora::operator <= ( CFechaHora & fecValor )
{
	return ( EsIgual ( fecValor) || EsMenor ( fecValor ) );
}

bool CFechaHora::operator > ( CFechaHora & fecValor )
{
	return ( EsMayor ( fecValor) );
}

bool CFechaHora::operator >= ( CFechaHora & fecValor )
{
	return ( EsIgual ( fecValor) || EsMayor ( fecValor ) );
}

bool CFechaHora::operator == ( CFechaHora * p_fecValor )
{
	return ( EsIgual ( p_fecValor ) );
}

bool CFechaHora::operator != ( CFechaHora * p_fecValor )
{
	return ( EsDiferente ( p_fecValor ) );
}

bool CFechaHora::operator < ( CFechaHora * p_fecValor )
{
	return ( EsMenor ( p_fecValor ) );
}

bool CFechaHora::operator <= ( CFechaHora * p_fecValor )
{
	return ( EsIgual ( p_fecValor) || EsMenor ( p_fecValor ) );
}

bool CFechaHora::operator > ( CFechaHora * p_fecValor )
{
	return ( EsMayor ( p_fecValor ) );
}

bool CFechaHora::operator >= ( CFechaHora * p_fecValor )
{
	return ( EsIgual ( p_fecValor) || EsMayor ( p_fecValor ) );
}

bool CFechaHora::operator == ( const string & sValor )
{
	return ( EsIgual ( sValor ) );
}

bool CFechaHora::operator != ( const string & sValor )
{
	return ( EsDiferente ( sValor ) );
}

bool CFechaHora::operator < ( const string & sValor )
{
	return ( EsMenor ( sValor ) );
}

bool CFechaHora::operator <= ( const string & sValor )
{
	return ( EsIgual ( sValor) || EsMenor ( sValor ) );
}

bool CFechaHora::operator > ( const string &  sValor )
{
	return ( EsMayor ( sValor ) );
}

bool CFechaHora::operator >= ( const string &  sValor )
{
	return ( EsIgual ( sValor) || EsMayor ( sValor ) );
}

bool CFechaHora::operator == ( long long llValor )
{
	return ( EsIgual ( llValor ) );
}

bool CFechaHora::operator != ( long long llValor )
{
	return ( EsDiferente ( llValor ) );
}

bool CFechaHora::operator < ( long long llValor )
{
	return ( EsMenor ( llValor ) );
}

bool CFechaHora::operator <= ( long long llValor )
{
	return ( EsIgual ( llValor ) || EsMenor ( llValor ) );
}

bool CFechaHora::operator > ( long long llValor )
{
	return ( EsMayor ( llValor ) );
}

bool CFechaHora::operator >= ( long long llValor )
{
	return ( EsIgual ( llValor ) || EsMayor ( llValor ) );
}

long CFechaHora::operator - ( CFechaHora & fecValor )
{
	return ( Diferencia ( fecValor ) );
}

long CFechaHora::operator - ( CFechaHora * p_fecValor )
{
	return ( Diferencia ( p_fecValor ) );
}

long CFechaHora::operator - ( const string & sValor )
{
	return ( Diferencia ( sValor ) );
}

long CFechaHora::operator - ( long long llValor )
{
	return ( Diferencia ( llValor ) );
}





 			}
		}
	}
}



