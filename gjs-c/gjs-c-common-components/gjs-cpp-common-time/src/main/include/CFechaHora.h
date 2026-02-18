/******************************************************************************/
/*                                CFechaHora.h                                */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene la definición de la clase de datos        */
/* CFechaHora, destinada a gestionar valores que almacenen un valor           */
/* horario.                                                                   */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_CFECHAHORA_H
#define _ORG_GJS_C_CC_CPP_CFECHAHORA_H


#include <CFecha.h>
#include <CHora.h>





using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


//PENDIENTE: adaptar para distinguir entre valor formateado y valor numerable,
// especialmente en las comparativas. De momento se trabaja con valores formateados

class CFechaHora
{
private:
	chrono::system_clock::time_point tpFechaHora;

public:
	CFechaHora ();
	CFechaHora ( long long llValor );
	CFechaHora ( const string & sValor );
	CFechaHora ( long lFecha, long lHora );
	CFechaHora ( int iA, int iM, int iD, int iHH, int iMI, int iSS );
	CFechaHora ( const chrono::system_clock::time_point & tp );
	CFechaHora ( CFecha & fecFecha, CHora & horHora );
	CFechaHora ( const chrono::year_month_day & ymd, const chrono::hh_mm_ss<chrono::seconds> & hms );
	CFechaHora ( const chrono::year & y, const chrono::month & m, const chrono::day & d,
                const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss );

	~CFechaHora();

	void Establecer ( long long llValor );
	void Establecer ( const string & sValor );
	void Establecer ( long lFecha, long lHora );
	void Establecer ( int iA, int iM, int iD, int iHH, int iMI, int iSS );
	void Establecer ( const chrono::system_clock::time_point & tp );
	void Establecer ( CFecha & fecFecha, CHora & horHora );
	void Establecer ( const chrono::year_month_day & ymd, const chrono::hh_mm_ss<chrono::seconds> & hms );
	void Establecer ( const chrono::year & y, const chrono::month & m, const chrono::day & d,
                const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss );

	bool EsValida ();

	int AAAA ();
	int MM ();
	int DD ();
	int HH ();
	int MI ();
	int SS ();

	long ValorFecha ();
	long ValorHora ();
	long long Valor ();
	string * ValorCadena ();
	string * Cadena ( const string & formato );

	CFecha * Fecha ();
	CHora * Hora ();

	void EstablecerValorDeAhora ();

	bool EsIgual ( CFechaHora & fechValor );
	bool EsMenor ( CFechaHora & fechValor );
	bool EsMayor ( CFechaHora & fechValor );
	bool EsDiferente ( CFechaHora & fechValor );
	bool EsIgual ( CFechaHora * p_horValor );
	bool EsMenor ( CFechaHora * p_horValor );
	bool EsMayor ( CFechaHora * p_horValor );
	bool EsDiferente ( CFechaHora * p_horValor );
	bool EsIgual ( const string & sValor );
	bool EsMenor ( const string & sValor );
	bool EsMayor ( const string & sValor );
	bool EsDiferente ( const string & sValor );
	bool EsIgual ( long long llValor );
	bool EsMenor ( long long llValor );
	bool EsMayor ( long long llValor );
	bool EsDiferente ( long long llValor );

	long Diferencia ( CFechaHora & fechValor );
	long Diferencia ( CFechaHora * p_horValor );
	long Diferencia ( const string & sValor );
	long Diferencia ( long long llValor );

public:
	bool operator == ( CFechaHora & fechValor );
	bool operator != ( CFechaHora & fechValor );
	bool operator > ( CFechaHora & fechValor );
	bool operator >= ( CFechaHora & fechValor );
	bool operator < ( CFechaHora & fechValor );
	bool operator <= ( CFechaHora & fechValor );
	bool operator == ( CFechaHora * p_horValor );
	bool operator != ( CFechaHora * p_horValor );
	bool operator > ( CFechaHora * p_horValor );
	bool operator >= ( CFechaHora * p_horValor );
	bool operator < ( CFechaHora * p_horValor );
	bool operator <= ( CFechaHora * p_horValor );
	bool operator == ( const string & sValor );
	bool operator != ( const string & sValor );
	bool operator > ( const string & sValor );
	bool operator >= ( const string & sValor );
	bool operator < ( const string & sValor );
	bool operator <= ( const string & sValor );
	bool operator == ( long long llValor );
	bool operator != ( long long llValor );
	bool operator > ( long long llValor );
	bool operator >= ( long long llValor );
	bool operator < ( long long llValor );
	bool operator <= ( long long llValor );

	long operator - ( CFechaHora & fechValor );
	long operator - ( CFechaHora * fechValor );
	long operator - ( const string & sValor );
	long operator - ( long long llValor );

};


 			}
		}
	}
}




#endif


