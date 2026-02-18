#include "CppCommonTypes.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;



static bool TestFecha01 ()
{
	cout << "Test Fecha 01:" << endl;
	bool bRes = true;
	string sDia = string ( FECHA_DIA );
	string sMes = string ( FECHA_MES );
	string sAño = string ( FECHA_AÑO );
	string sFecha = string ( FECHA );
	cout << "Dia  : [" << sDia << "]" << endl;
	cout << "Mes  : [" << sMes << "]" << endl;
	cout << "Ano  : [" << sAño << "]" << endl;
	cout << "Fecha: [" << sFecha << "]" << endl;
	if ( sFecha != sAño + sMes + sDia )
	{
		cout << "Error: fecha mal calculada" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestConstantes () 
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Constantes]" << ANSI::RESETEAR << endl;
	if ( TestFecha01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	cout << ANSI::AMARILLO << "[Fin]" << ANSI::RESETEAR << endl;	
	return ( bRes );
}
