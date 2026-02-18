/******************************************************************************/
/*                                  CFecha.h                                  */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene la definición de la clase de datos        */
/* CFecha, destinada a almacenar un valor de fecha.                           */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_CFECHA_H
#define _ORG_GJS_C_CC_CPP_CFECHA_H

using namespace std;

#include <chrono>


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

class CFecha
{
private:
     chrono::year_month_day ymdFecha;

public:
	CFecha ();
	CFecha ( long lValor );
	CFecha ( const string & sValor );
	CFecha ( int iA, int iM, int iD );
	CFecha ( const chrono::year_month_day & ymd );
	CFecha ( const chrono::year & y, const chrono::month & m, const chrono::day & d );
	~CFecha();

	void Establecer ( long lValor );
	void Establecer ( const string & sValor );
	void Establecer ( int iA, int iM, int iD );
	void Establecer ( const chrono::year_month_day & ymd );
	void Establecer ( const chrono::year & y, const chrono::month & m, const chrono::day & d );

	bool EsValida ();

	long Valor ();
	time_t ValorTiempo ();
	string * ValorCadena ();
	string * Cadena ( const string & formato );

	int AAAA ();
	int MM ();
	int DD ();

	void EstablecerValorDeHoy ();

	bool EsIgual ( CFecha & fecValor );
	bool EsMenor ( CFecha & fecValor );
	bool EsMayor ( CFecha & fecValor );
	bool EsDiferente ( CFecha & fecValor );
	bool EsIgual ( CFecha * p_fecValor );
	bool EsMenor ( CFecha * p_fecValor );
	bool EsMayor ( CFecha * p_fecValor );
	bool EsDiferente ( CFecha * p_fecValor );
	bool EsIgual ( const string & sValor );
	bool EsMenor ( const string & sValor );
	bool EsMayor ( const string & sValor );
	bool EsDiferente ( const string & sValor );
	bool EsIgual ( long lValor );
	bool EsMenor ( long lValor );
	bool EsMayor ( long lValor );
	bool EsDiferente ( long lValor );
	bool EsIgual ( const chrono::year_month_day & ymd  );
	bool EsMenor ( const chrono::year_month_day & ymd  );
	bool EsMayor ( const chrono::year_month_day & ymd  );
	bool EsDiferente ( const chrono::year_month_day & ymd  );

	long Diferencia ( CFecha & fecValor );
	long Diferencia ( CFecha * p_fecValor );
	long Diferencia ( const string & sValor );
	long Diferencia ( long lValor );
	long Diferencia ( const chrono::year_month_day & ymd );

public:
	bool operator == ( CFecha & fecValor );
	bool operator != ( CFecha & fecValor );
	bool operator > ( CFecha & fecValor );
	bool operator >= ( CFecha & fecValor );
	bool operator < ( CFecha & fecValor );
	bool operator <= ( CFecha & fecValor );
	bool operator == ( CFecha * p_fecValor );
	bool operator != ( CFecha * p_fecValor );
	bool operator > ( CFecha * p_fecValor );
	bool operator >= ( CFecha * p_fecValor );
	bool operator < ( CFecha * p_fecValor );
	bool operator <= ( CFecha * p_fecValor );
	bool operator == ( const string & sValor );
	bool operator != ( const string & sValor );
	bool operator > ( const string & sValor );
	bool operator >= ( const string & sValor );
	bool operator < ( const string & sValor );
	bool operator <= ( const string & sValor );
	bool operator == ( long lValor );
	bool operator != ( long lValor );
	bool operator > ( long lValor );
	bool operator >= ( long lValor );
	bool operator < ( long lValor );
	bool operator <= ( long lValor );
	bool operator == ( const chrono::year_month_day & ymd );
	bool operator != ( const chrono::year_month_day & ymd );
	bool operator > ( const chrono::year_month_day & ymd );
	bool operator >= ( const chrono::year_month_day & ymd );
	bool operator < ( const chrono::year_month_day & ymd );
	bool operator <= ( const chrono::year_month_day & ymd );

	long operator - ( CFecha & fecValor );
	long operator - ( CFecha * p_fecValor );
	long operator - ( const string & sValor );
	long operator - ( long lValor );
	long operator - ( const chrono::year_month_day & ymd );

};


 			}
		}
	}
}




#endif


