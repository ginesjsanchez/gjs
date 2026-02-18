#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestContador01 ()
{
	cout << "Test Contador 01:" << endl;
	bool bRes = true;

	try
	{
		Contador * contador = new Contador();
		if ( ( contador->getTotal() != 0 ) ||
			 ( contador->getCorrectos() != 0 )  ||
			 ( contador->getErroneos() != 0 )  ||
			 ( contador->toString().compare( "[Total=0; Correctos=0; Erroneos=0]" ) != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		contador->Incrementar(); 
		if ( ( contador->getTotal() != 1 ) ||
			 ( contador->getCorrectos() != 1 )  ||
			 ( contador->getErroneos() != 0 )  ||
			 ( contador->toString().compare( "[Total=1; Correctos=1; Erroneos=0]" ) != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		contador->Incrementar( false ); 
		if ( ( contador->getTotal() != 2 ) ||
			 ( contador->getCorrectos() != 1 )  ||
			 ( contador->getErroneos() != 1 )  ||
			 ( contador->toString().compare( "[Total=2; Correctos=1; Erroneos=1]" ) != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		delete contador;
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion :" << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestContador ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Contador]" << ANSI::RESETEAR << endl;
	if ( TestContador01() )
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
