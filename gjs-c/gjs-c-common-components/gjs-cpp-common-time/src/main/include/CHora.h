/******************************************************************************/
/*                                  CHora.h                                  */
/*----------------------------------------------------------------------------*/
/* Librería:  Tiempo                                                          */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene la definición de la clase de datos        */
/* CHora, destinada a almacenar un valor de fecha.                           */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_CHORA_H
#define _ORG_GJS_C_CC_CPP_CHORA_H

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
// subsegundos, duration, mili, micro nano

class CHora
{
private:
     chrono::hh_mm_ss<chrono::seconds> hmsHora;

public:
	CHora ();
	CHora ( long lValor );
	CHora ( const string & sValor );
	CHora ( int iHH, int iMI, int iSS );
	CHora ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	CHora ( const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss );
	~CHora();

	void Establecer ( long lValor );
	void Establecer ( const string & sValor );
	void Establecer ( int iHH, int iMI, int iSS );
	void Establecer ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	void Establecer ( const chrono::hours & hh, const chrono::minutes & mi, const chrono::seconds & ss );

	bool EsValida ();

	long Valor ();
	string * ValorCadena ();
	string * Cadena ( const string & formato );

	int HH ();
	int MI ();
	int SS ();

	void EstablecerValorDeAhora ();

	bool EsIgual ( CHora & horValor );
	bool EsMenor ( CHora & horValor );
	bool EsMayor ( CHora & horValor );
	bool EsDiferente ( CHora & horValor );
	bool EsIgual ( CHora * p_horValor );
	bool EsMenor ( CHora * p_horValor );
	bool EsMayor ( CHora * p_horValor );
	bool EsDiferente ( CHora * p_horValor );
	bool EsIgual ( const string & sValor );
	bool EsMenor ( const string & sValor );
	bool EsMayor ( const string & sValor );
	bool EsDiferente ( const string & sValor );
	bool EsIgual ( long lValor );
	bool EsMenor ( long lValor );
	bool EsMayor ( long lValor );
	bool EsDiferente ( long lValor );
	bool EsIgual ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool EsMenor ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool EsMayor ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool EsDiferente ( const chrono::hh_mm_ss<chrono::seconds> & hms );

	long Diferencia ( CHora & horValor );
	long Diferencia ( CHora * p_horValor );
	long Diferencia ( const string & sValor );
	long Diferencia ( long lValor );
	long Diferencia ( const chrono::hh_mm_ss<chrono::seconds> & hms );

public:
	bool operator == ( CHora & horValor );
	bool operator != ( CHora & horValor );
	bool operator > ( CHora & horValor );
	bool operator >= ( CHora & horValor );
	bool operator < ( CHora & horValor );
	bool operator <= ( CHora & horValor );
	bool operator == ( CHora * p_horValor );
	bool operator != ( CHora * p_horValor );
	bool operator > ( CHora * p_horValor );
	bool operator >= ( CHora * p_horValor );
	bool operator < ( CHora * p_horValor );
	bool operator <= ( CHora * p_horValor );
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
	bool operator == ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool operator != ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool operator > ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool operator >= ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool operator < ( const chrono::hh_mm_ss<chrono::seconds> & hms );
	bool operator <= ( const chrono::hh_mm_ss<chrono::seconds> & hms );

	long operator - ( CHora & horValor );
	long operator - ( CHora * p_horValor );
	long operator - ( const string & sValor );
	long operator - ( long lValor );
	long operator - ( const chrono::hh_mm_ss<chrono::seconds> & hms );

};


 			}
		}
	}
}




#endif


