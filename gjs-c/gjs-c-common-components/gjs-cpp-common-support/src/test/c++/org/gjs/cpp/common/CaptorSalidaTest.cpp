#include "CppCommonSupport.h"

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
using namespace org::gjs::cpp::common;



static bool TestCaptorSalida01 ()
{
	cout << "Test CaptorSalida01:" << endl;
	bool bRes = true;

	CaptorSalida espia;
	if ( espia.EstaActivado () || ( espia.getLineas ().size() > 0 ) )
	{
		cout << "Objeto mal inicializado" << endl;
		bRes = false;
	}
	espia.Fin ();
	if ( espia.EstaActivado () || ( espia.getLineas ().size() > 0 ) )
	{
		cout << "Fin no deberia haber hecho nada" << endl;
		bRes = false;
	}
	espia.Ini ();
	if ( ! espia.EstaActivado () || ( espia.getLineas ().size () > 0 ) )
	{
		espia.Fin ();
		cout << "Captura de consola mal iniciada" << endl;
		bRes = false;
	}
	if ( bRes )
	{
		cout << endl;
		cout << "Linea 1" << endl;
		cout << "Linea 2" << endl << endl;
		cout << "Linea 3" << endl;
		cout << "Linea 4" << endl;
		//cout.flush ();
		//Esperar( 10000 );
		espia.Fin ();
		if ( espia.EstaActivado () || ( espia.getLineas ().size () == 0 ) )
		{
			cout << "Captura de consola mal finalizada" << endl;
			bRes = false;
		}	

		cout << endl << ANSI::SUBRAYADO_INI << "Contenido capturado:" << ANSI::SUBRAYADO_FIN << endl;	
		for ( auto sLinea : espia.getLineas () )
		{
			cout << "[" << sLinea << "]" << endl;
		}
		
		if ( espia.getLineas ().size () == 6 )
		{
			if ( ( espia.getLineas () [ 0 ] != "" ) ||
				( espia.getLineas () [ 1 ] != "Linea 1" ) ||
				( espia.getLineas () [ 2 ] != "Linea 2" ) ||
				( espia.getLineas () [ 3 ] != "" ) ||
				( espia.getLineas () [ 4 ] != "Linea 3" ) ||
				( espia.getLineas () [ 5 ] != "Linea 4" ) )
			{
				cout << "Contenido capturado incorrecto" << endl;
				bRes = false;
			}		
		}
		else
		{
			cout << "Numeros de lineas capturadas incorrecto: " << espia.getLineas ().size () << endl;
			bRes = false;
		}
	}
	return( bRes );
}


bool TestCaptorSalida ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test CaptorSalida]" << ANSI::RESETEAR << endl;
	if ( TestCaptorSalida01() )
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
