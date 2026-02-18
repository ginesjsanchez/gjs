
#ifndef _ORG_GJS_C_CC_CPP_FECHA_H
#define _ORG_GJS_C_CC_CPP_FECHA_H


#include <chrono>




using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {



class Fecha 
{
private:
   chrono::year_month_day fecha;
	
public:
	Fecha ();
	Fecha ( int iAAAA, int iMM, int iDD );
	Fecha ( long lValor );
	Fecha ( const string & sValor );

	virtual ~Fecha();

	bool Establecer ( int iAAAA, int iMM, int iDD );
	bool Establecer ( long lValor );
	bool Establecer ( const string & sValor );

	bool EsValida ();

	long Valor () const;
	/*
	 *   "%d-%m-%Y", "%d/%m/%Y"  
	 */
	string Formatear ( const string & sFormato );

	chrono::year_month_day ToYMD () const;
	int AAAA () const;
	int MM () const;
	int DD () const;

	void EstablecerValorDeHoy ();

	bool EsIgual ( const Fecha & fecValor );
	bool EsMenor ( const Fecha & fecValor );
	bool EsMayor ( const Fecha & fecValor );
	bool EsDiferente ( const Fecha & fecValor );
	bool EsIgual ( const string & sValor );
	bool EsMenor ( const string & sValor );
	bool EsMayor ( const string & sValor );
	bool EsDiferente ( const string & sValor );
	bool EsIgual ( long lValor );
	bool EsMenor ( long lValor );
	bool EsMayor ( long lValor );
	bool EsDiferente ( long lValor );

	long Diferencia ( const Fecha & fecValor );
	long Diferencia ( const string & sValor );
	long Diferencia ( long lValor );

public:
	bool operator == ( const Fecha & fecValor );
	bool operator != ( const Fecha & fecValor );
	bool operator > ( const Fecha & fecValor );
	bool operator >= ( const Fecha & fecValor );
	bool operator < ( const Fecha & fecValor );
	bool operator <= ( const Fecha & fecValor );

	long operator - ( const Fecha & fecValor );
};


 			}
		}
	}
}



#endif


