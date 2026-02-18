#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestNodoBin01 ()
{
	cout << "Test NodoBin01:" << endl;
	bool bRes = true;

	try
	{
		NodoBin * nodo = new NodoBin();
		if ( ( nodo->getDatos() != NULL ) ||
			 nodo->TieneHijos() || 
			 nodo->TieneHijoDer() || 
			 nodo->TieneHijoIzq() || 
			 nodo->TienePadre() ||
			 ( nodo->getHijoDer() != NULL ) ||
			 ( nodo->getHijoIzq() != NULL ) ||
			 ( nodo->getPadre() != NULL ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		nodo->setDatos( new string( "NODO 1") ); 
		if ( ( nodo->getDatos() == NULL ) ||
			 nodo->TieneHijos() || 
			 nodo->TieneHijoDer() || 
			 nodo->TieneHijoIzq() || 
			 nodo->TienePadre() ||
			 ( nodo->getHijoDer() != NULL ) ||
			 ( nodo->getHijoIzq() != NULL ) ||
			 ( nodo->getPadre() != NULL ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		Ptr<string> * contenido = new Ptr<string>( nodo->getDatos(), false );
		if ( contenido->getDatos()->compare( "NODO 1") != 0 ) 
		{
			cout << "Error caso 2:  [" << contenido->getDatos() << "]" << endl;
			bRes = false;
		}
		delete contenido;
		delete nodo;
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

static bool TestNodoBin02 ()
{
	cout << "Test NodoBin02:" << endl;
	bool bRes = true;

	try
	{
		NodoBin * nodo = new NodoBin( new string( "NODO 1") );
		if ( ( nodo->getDatos() == NULL ) ||
			 nodo->TieneHijos() || 
			 nodo->TieneHijoDer() || 
			 nodo->TieneHijoIzq() || 
			 nodo->TienePadre() ||
			 ( nodo->getHijoDer() != NULL ) ||
			 ( nodo->getHijoIzq() != NULL ) ||
			 ( nodo->getPadre() != NULL ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		Ptr<string> * contenido = new Ptr<string>( nodo->getDatos(), false );
		if ( contenido->getDatos()->compare( "NODO 1") != 0 ) 
		{
			cout << "Error caso 2:  [" << contenido->getDatos() << "]" << endl;
			bRes = false;
		}

		nodo->setPadre( new NodoBin( new string( "NODO 2") ) ); 		
		if ( ( nodo->getDatos() == NULL ) ||
			 nodo->TieneHijos() || 
			 nodo->TieneHijoDer() || 
			 nodo->TieneHijoIzq() || 
			 ! nodo->TienePadre() ||
			 ( nodo->getHijoDer() != NULL ) ||
			 ( nodo->getHijoIzq() != NULL ) ||
			 ( nodo->getPadre() == NULL ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		Ptr<string> * contenido2 = new Ptr<string>( nodo->getPadre()->getDatos(), false );
		if ( contenido2->getDatos()->compare( "NODO 2") != 0 ) 
		{
			cout << "Error caso 2:  [" << contenido2->getDatos() << "]" << endl;
			bRes = false;
		}

		nodo->setHijoIzq( new ArbolBin() ); 		
		if ( ( nodo->getDatos() == NULL ) ||
			 ! nodo->TieneHijos() || 
			 nodo->TieneHijoDer() || 
			 !nodo->TieneHijoIzq() || 
			 ! nodo->TienePadre() ||
			 ( nodo->getHijoDer() != NULL ) ||
			 ( nodo->getHijoIzq() == NULL ) ||
			 ( nodo->getPadre() == NULL ) )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}
		nodo->setHijoDer( new ArbolBin() ); 		
		if ( ( nodo->getDatos() == NULL ) ||
			 ! nodo->TieneHijos() || 
			 ! nodo->TieneHijoDer() || 
			 ! nodo->TieneHijoIzq() || 
			 ! nodo->TienePadre() ||
			 ( nodo->getHijoDer() == NULL ) ||
			 ( nodo->getHijoIzq() == NULL ) ||
			 ( nodo->getPadre() == NULL ) )
		{
			cout << "Error caso 4" << endl;
			bRes = false;
		}
		delete contenido;
		delete contenido2;
		delete nodo->getPadre();
		delete nodo->getHijoIzq();
		delete nodo->getHijoDer();
		delete nodo;
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


bool TestNodoBin ()
{
	bool bRes = true;

	cout << endl << ANSI::AMARILLO << "[Test NodoBin]" << ANSI::RESETEAR << endl;
	if ( TestNodoBin01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestNodoBin02() )
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
