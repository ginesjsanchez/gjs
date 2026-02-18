/******************************************************************************/
/*                                 CHora.cpp                                 */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de la clase de     */
/* datos CHora.                                                              */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "CHora.h"



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

CHora::CHora ()
{
	EstablecerValorDeAhora ();
}

CHora::CHora ( long lValor )
{
	Establecer ( lValor );
}

CHora::CHora ( const string & sValor )
{
	Establecer ( sValor );
}

CHora::CHora ( int iHH, int iMI, int iSS )
{
	Establecer ( iHH, iMI, iSS );
}


CHora::CHora ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	Establecer ( hms );
}


CHora::CHora ( const chrono::hours & hh, const chrono::minutes& mi, const chrono::seconds& ss )
{
	Establecer ( hh, mi, ss );
}

CHora::~CHora()
{
}

void CHora::Establecer ( long lValor )
{
	int iHH = lValor / 10000;
	long lAux = lValor % 10000;
	int iMI = lAux / 100;
	int iSS = lAux % 100;
	Establecer ( iHH, iMI, iSS );
}

void CHora::Establecer ( const string & sValor )
{
    Establecer ( ToInt ( sValor ) );
}

void CHora::Establecer ( int iHH, int iMI, int iSS )
{
    Establecer ( chrono::hours ( iHH ), chrono::minutes ( iMI ), chrono::seconds ( iSS ) );
}

void CHora::Establecer ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
    hmsHora = hms;
}

void CHora::Establecer ( const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss )
{
    Establecer ( chrono::hh_mm_ss<chrono::seconds> ( hh + mi + ss ) );
}

bool CHora::EsValida ()
{
	return ( ( hmsHora.hours().count() >= 0 ) && ( hmsHora.hours().count() < 24 ) &&
        ( hmsHora.minutes().count() >= 0 ) && ( hmsHora.minutes().count() < 60 ) &&
        ( hmsHora.seconds().count() >= 0 ) && ( hmsHora.seconds().count() < 60 ) );
}

long CHora::Valor ()
{
	return ( hmsHora.hours().count() * 10000 + hmsHora.minutes().count() * 100 + hmsHora.seconds().count() );
}

string * CHora::ValorCadena ()
{
    return ( new string ( to_string ( Valor() ) ) );
}

string * CHora::Cadena ( const string & formato )
{
    return ( new string ( vformat ( formato, make_format_args( hmsHora ) ) ) );
}

int CHora::HH ()
{
	return ( hmsHora.hours().count() );
}

int CHora::MI ()
{
	return ( hmsHora.minutes().count() );
}

int CHora::SS ()
{
	return ( hmsHora.seconds().count() );
}

void CHora::EstablecerValorDeAhora ()
{
    chrono::system_clock::time_point ahora = chrono::system_clock::now();
    chrono::sys_days dias = chrono::floor<chrono::days>(ahora);
    hmsHora = chrono::hh_mm_ss{ floor<chrono::seconds>( ahora - dias ) };
}

bool CHora::EsIgual ( CHora & horValor )
{
	return ( EsIgual ( horValor.Valor () ) );
}

bool CHora::EsMenor( CHora & horValor )
{
	return ( EsMenor ( horValor.Valor () ) );
}

bool CHora::EsMayor ( CHora & horValor )
{
	return ( EsMayor ( horValor.Valor () ) );
}

bool CHora::EsDiferente ( CHora & horValor )
{
	return ( EsDiferente ( horValor.Valor () ) );
}

bool CHora::EsIgual ( CHora * p_horValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_horValor ) )
    {
        bRes = EsIgual ( p_horValor->Valor () );
    }
	return ( bRes );
}

bool CHora::EsMenor( CHora * p_horValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_horValor ) )
    {
        bRes = EsMenor( p_horValor->Valor () );
    }
	return ( bRes );
}

bool CHora::EsMayor ( CHora * p_horValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_horValor ) )
    {
        bRes = EsMayor ( p_horValor->Valor () );
    }
	return ( bRes );
}

bool CHora::EsDiferente ( CHora * p_horValor )
{
    bool bRes = false;
    if ( ES_VALIDO ( p_horValor ) )
    {
        bRes = EsDiferente ( p_horValor->Valor () );
    }
	return ( bRes );
}

bool CHora::EsIgual ( const string & sValor )
{
	return ( EsIgual ( ToInt ( sValor ) ) );
}

bool CHora::EsMenor( const string & sValor )
{
	return ( EsMenor ( ToInt ( sValor ) ) );
}

bool CHora::EsMayor ( const string & sValor )
{
	return ( EsMayor ( ToInt ( sValor ) ) );
}

bool CHora::EsDiferente ( const string & sValor )
{
	return ( EsDiferente ( ToInt ( sValor ) ) );
}

bool CHora::EsIgual ( long lValor )
{
	return ( Valor() == lValor );
}

bool CHora::EsMenor( long lValor )
{
	return (  Valor() < lValor );
}

bool CHora::EsMayor ( long lValor )
{
	return (  Valor() > lValor );
}

bool CHora::EsDiferente ( long lValor )
{
	return (  Valor() != lValor );
}

bool CHora::EsIgual ( const chrono::hh_mm_ss<chrono::seconds> & hms  )
{
	return (  hmsHora.to_duration() == hms.to_duration() );
}

bool CHora::EsMenor ( const chrono::hh_mm_ss<chrono::seconds> & hms  )
{
	return (  hmsHora.to_duration() < hms.to_duration() );
}

bool CHora::EsMayor ( const chrono::hh_mm_ss<chrono::seconds> & hms  )
{
	return (  hmsHora.to_duration() > hms.to_duration() );
}

bool CHora::EsDiferente ( const chrono::hh_mm_ss<chrono::seconds> & hms  )
{
	return (  hmsHora.to_duration() != hms.to_duration() );
}

long CHora::Diferencia ( CHora & horValor )
{
	return ( Diferencia ( horValor.Valor () ) );
}

long CHora::Diferencia ( CHora * p_horValor )
{
    long lRes = LLONG_MAX;
    if ( ES_VALIDO ( p_horValor ) )
    {
        lRes = Diferencia ( p_horValor->Valor () );
    }
	return ( lRes );
}

long CHora::Diferencia ( const string & sValor )
{
	return ( Diferencia ( ToInt ( sValor ) ) );
}

long CHora::Diferencia ( long lValor )
{
	return ( Valor () - lValor );
}

long CHora::Diferencia ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	long lValor = hms.hours().count() * 10000 + hms.minutes().count() * 100 + hms.seconds().count();
	return ( Diferencia( lValor ) );
}

bool CHora::operator == ( CHora & hmsHora )
{
	return ( EsIgual ( hmsHora ) );
}

bool CHora::operator != ( CHora & hmsHora )
{
	return ( EsDiferente ( hmsHora ) );
}

bool CHora::operator < ( CHora & hmsHora )
{
	return ( EsMenor ( &hmsHora ) );
}

bool CHora::operator <= ( CHora & hmsHora )
{
	return ( EsIgual ( hmsHora) || EsMenor ( hmsHora ) );
}

bool CHora::operator > ( CHora & hmsHora )
{
	return ( EsMayor ( hmsHora) );
}

bool CHora::operator >= ( CHora & hmsHora )
{
	return ( EsIgual ( hmsHora) || EsMayor ( hmsHora ) );
}

bool CHora::operator == ( CHora * p_horValor )
{
	return ( EsIgual ( p_horValor ) );
}

bool CHora::operator != ( CHora * p_horValor )
{
	return ( EsDiferente ( p_horValor ) );
}

bool CHora::operator < ( CHora * p_horValor )
{
	return ( EsMenor ( p_horValor ) );
}

bool CHora::operator <= ( CHora * p_horValor )
{
	return ( EsIgual ( p_horValor) || EsMenor ( p_horValor ) );
}

bool CHora::operator > ( CHora * p_horValor )
{
	return ( EsMayor ( p_horValor ) );
}

bool CHora::operator >= ( CHora * p_horValor )
{
	return ( EsIgual ( p_horValor) || EsMayor ( p_horValor ) );
}

bool CHora::operator == ( const string & sValor )
{
	return ( EsIgual ( sValor ) );
}

bool CHora::operator != ( const string & sValor )
{
	return ( EsDiferente ( sValor ) );
}

bool CHora::operator < ( const string & sValor )
{
	return ( EsMenor ( sValor ) );
}

bool CHora::operator <= ( const string & sValor )
{
	return ( EsIgual ( sValor) || EsMenor ( sValor ) );
}

bool CHora::operator > ( const string &  sValor )
{
	return ( EsMayor ( sValor ) );
}

bool CHora::operator >= ( const string &  sValor )
{
	return ( EsIgual ( sValor) || EsMayor ( sValor ) );
}

bool CHora::operator == ( long lValor )
{
	return ( EsIgual ( lValor ) );
}

bool CHora::operator != ( long lValor )
{
	return ( EsDiferente ( lValor ) );
}

bool CHora::operator < ( long lValor )
{
	return ( EsMenor ( lValor ) );
}

bool CHora::operator <= ( long lValor )
{
	return ( EsIgual ( lValor ) || EsMenor ( lValor ) );
}

bool CHora::operator > ( long lValor )
{
	return ( EsMayor ( lValor ) );
}

bool CHora::operator >= ( long lValor )
{
	return ( EsIgual ( lValor ) || EsMayor ( lValor ) );
}

bool CHora::operator == ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsIgual ( hms ) );
}

bool CHora::operator != ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsDiferente ( hms ) );
}

bool CHora::operator < ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsMenor ( hms ) );
}

bool CHora::operator <= ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsIgual ( hms ) || EsMenor ( hms ) );
}

bool CHora::operator > ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsMayor ( hms ) );
}

bool CHora::operator >= ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( EsIgual ( hms ) || EsMayor ( hms ) );
}

long CHora::operator - ( CHora & hmsHora )
{
	return ( Diferencia ( hmsHora ) );
}

long CHora::operator - ( CHora * p_horValor )
{
	return ( Diferencia ( p_horValor ) );
}

long CHora::operator - ( const string & sValor )
{
	return ( Diferencia ( sValor ) );
}

long CHora::operator - ( long lValor )
{
	return ( Diferencia ( lValor ) );
}

long CHora::operator - ( const chrono::hh_mm_ss<chrono::seconds> & hms )
{
	return ( Diferencia ( hms ) );
}


 			}
		}
	}
}





