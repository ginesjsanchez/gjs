#include "CppCommonSupport.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestArbolBin01 ()
{
	cout << "Test ArbolBin01:" << endl;
	bool bRes = true;

	try
	{
		ArbolBin * arbol = new ArbolBin();
		if ( arbol->TieneRaiz() || 
			 ( arbol->Tam() != 0 ) ||
			 ( arbol->Profundidad() != 0 ) ||
			 ( arbol->getRaiz() != NULL ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		arbol->setRaiz( new string( "RAIZ" ) ); 
		if ( !arbol->TieneRaiz() || 
			 ( arbol->Tam() != 1 ) ||
			 ( arbol->Profundidad() != 0 ) ||
			 ( arbol->getRaiz() == NULL ) )
		{
			cout << "Error caso 2: Tam=" << arbol->Tam() << "; Profundidad=" << arbol->Profundidad() << endl;
			cout << arbol->TieneRaiz() << endl;
			bRes = false;
		}
		Ptr<string> contenido( arbol->getRaiz()->getDatos(), false );
		if ( contenido.getDatos()->compare( "RAIZ" ) != 0 )
		{
			cout << "Error caso 2: [" << contenido.getDatos() << "]" << endl;
			bRes = false;
		}
		
		arbol->EmpadrarPorIzq( new NodoBin( new string( "NUEVA RAIZ" ) ) ); 
		if ( !arbol->TieneRaiz() || 
			 ( arbol->Tam() != 2 ) ||
			 ( arbol->Profundidad() != 1 ) ||
			 ( arbol->getRaiz() == NULL ) )
		{
			cout << "Error caso 3: Tam=" << arbol->Tam() << "; Profundidad=" << arbol->Profundidad() << endl;
			bRes = false;
		}
		Ptr<string> contenido2( arbol->getRaiz()->getDatos(), false );
		if ( contenido2.getDatos()->compare( "NUEVA RAIZ" ) != 0 )
		{
			cout << "Error caso 3: [" << contenido2.getDatos() << "]" << endl;
			bRes = false;
		}

		NodoBin * nodo = new NodoBin( new string( "RE-NUEVA RAIZ" ) );
		nodo->setHijoIzq( new ArbolBin( new string( "HIJO 1" ) ) );
		arbol->EmpadrarPorDer( nodo ); 
		if ( !arbol->TieneRaiz() || 
			 ( arbol->Tam() != 4 ) ||
			 ( arbol->Profundidad() != 2 ) ||
			 ( arbol->getRaiz() == NULL ) )
		{
			cout << "Error caso 4: Tam=" << arbol->Tam() << "; Profundidad=" << arbol->Profundidad() << endl;
			cout << arbol->TieneRaiz() << endl;
			bRes = false;
		}
		Ptr<string> contenido3( arbol->getRaiz()->getDatos(), false );
		if ( contenido3.getDatos()->compare( "RE-NUEVA RAIZ" ) != 0 )
		{
			cout << "Error caso 3: [" << contenido3.getDatos() << "]" << endl;
			bRes = false;
		}
		delete arbol;
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

bool TestArbolBin ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ArbolBin]" << ANSI::RESETEAR << endl;
	if ( TestArbolBin01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	/*
	if ( TestArbolBin02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	*/
	cout << ANSI::AMARILLO << "[Fin]" << ANSI::RESETEAR << endl;	
	return ( bRes );
}
