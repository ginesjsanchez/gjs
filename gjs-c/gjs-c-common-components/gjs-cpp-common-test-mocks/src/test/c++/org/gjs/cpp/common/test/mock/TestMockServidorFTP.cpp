#include "MockServidorFTP.h"


#include <CppBase.h>

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;
using namespace org::gjs::cpp::common::test::mock;



MockServidorFTP * mockServidorFTP = NULL;



bool TestMockServidorFTP01 ()
{
	cout << "Test MockServidorFTP01: " << endl;
	bool bRes = true;
	try
	{
		/*
		if ( bInicializado )
		{
			cout << "No se ha finalizado correctamente o no se ha inicializado" << endl;
			bRes = false;
		}
		*/
	}
	catch ( const exception & ex )
	{
		cout << "Error al probar la funcionalidad del test: " << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Terminado con throwable inesperado" << endl;
		bRes = false;
	}
	return( bRes );
}


bool TestMockServidorFTP ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test MockServidorFTP]" << ANSI::RESETEAR << endl;
	if ( TestMockServidorFTP01 () )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	return ( bRes );
}
