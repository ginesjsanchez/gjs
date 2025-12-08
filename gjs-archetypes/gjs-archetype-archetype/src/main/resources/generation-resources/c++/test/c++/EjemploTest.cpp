#include "${nombre}.h"




using namespace std;
using namespace es::mir::base;
using namespace es::mir::${subespacionombres};



static bool TestEjemplo01 ()
{
	cout << "Test Ejemplo 01:" << endl;
	bool bRes = true;

	try
	{
		Ejemplo * ejemplo = new Ejemplo();
		if ( !ejemplo->EsValido() )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		delete ejemplo;
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



bool TestEjemplo ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Ejemplo]" << ANSI::RESETEAR << endl;
	if ( TestEjemplo01() )
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
