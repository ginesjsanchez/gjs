#include "CppBase.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;


static bool TestToVector01 ()
{
	cout << "Test ToVector01:" << endl;
	bool bRes = true;
	vector<string> vecObj1 = ToVector( {} );
	if ( vecObj1.size() != 0 )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	vector<string> vecObj2 = ToVector( { "" } );
	if ( vecObj2.size() != 1 )
	{
		cout << "Error caso 2: tamaño incorrecto" << endl;
		bRes = false;
	}
	else if ( vecObj2[0].compare( "" ) != 0 )
	{
		cout << "Error caso 2: valor incorrecto" << endl;
		bRes = false;
	}
	vector<string> vecObj3 = ToVector( { "1", "2", "3" } );
	if ( vecObj3.size() != 3 )
	{
		cout << "Error caso 3: tamaño incorrecto" << endl;
		bRes = false;
	}
	else if ( ( vecObj3[0].compare( "1" ) != 0 ) ||
				( vecObj3[1].compare( "2" ) != 0 ) ||
				( vecObj3[2].compare( "3" ) != 0 ) )
	{
		cout << "Error caso 3: valor incorrecto" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToList01 ()
{
	cout << "Test ToList01:" << endl;
	bool bRes = true;
	list<string> lisObj1 = ToList( {} );
	if ( lisObj1.size() != 0 )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	list<string> lisObj2 = ToList( { "" } );
	if ( lisObj2.size() != 1 )
	{
		cout << "Error caso 2: tamaño incorrecto" << endl;
		bRes = false;
	}
	else
	{
		list<string>::iterator it2 = lisObj2.begin();
		if ( it2->compare( "" ) != 0 )
		{
			cout << "Error caso 2: valor incorrecto" << endl;
			bRes = false;
		}
	}
	list<string> lisObj3 = ToList( { "1", "2", "3" } );
	if ( lisObj3.size() != 3 )
	{
		cout << "Error caso 3: tamaño incorrecto" << endl;
		bRes = false;
	}
	else
	{
		list<string>::iterator it3 = lisObj3.begin();
		if ( it3->compare( "1" ) != 0 )
		{
			cout << "Error caso 3: valor incorrecto 1" << endl;
			bRes = false;
		}
		++it3;
		if ( it3->compare( "2" ) != 0 )
		{
			cout << "Error caso 3: valor incorrecto 2" << endl;
			bRes = false;
		}
		++it3;
		if ( it3->compare( "3" ) != 0 )
		{
			cout << "Error caso 3: valor incorrecto 3" << endl;
			bRes = false;
		}
	}
	return( bRes );
}


static bool TestSonIguales01 ()
{
	cout << "Test SonIguales01:" << endl;
	bool bRes = true;
	list<string> lisObj1;
	list<string> lisObj2;
	if ( ! SonIguales ( lisObj1, lisObj2 ) )
	{
		cout << "Error caso 1: dos listas vacias deberian ser iguales" << endl;
		bRes = false;
	}
	lisObj1.push_back ( "Elem1" );
	if ( SonIguales ( lisObj1, lisObj2 ) )
	{
		cout << "Error caso 2: las listas con diferente numero de elementos deberian ser diferentes" << endl;
		bRes = false;
	}
	lisObj2.push_back ( "Elem1" );
	if ( !SonIguales ( lisObj1, lisObj2 ) )
	{
		cout << "Error caso 3: las listas deberian ser iguales" << endl;
		bRes = false;
	}
	lisObj1.push_back ( "Elem2 A" );
	lisObj2.push_back ( "Elem2 B" );
	if ( SonIguales ( lisObj1, lisObj2 ) )
	{
		cout << "Error caso 4: las listas deberian ser diferentes" << endl;
		bRes = false;
	}
	return( bRes );
}


static bool TestSonIguales02 ()
{
	cout << "Test SonIguales02:" << endl;
	bool bRes = true;
	vector<string> vecObj1;
	vector<string> vecObj2;
	if ( ! SonIguales ( vecObj1, vecObj2 ) )
	{
		cout << "Error caso 1: dos listas vacias deberian ser iguales" << endl;
		bRes = false;
	}
	vecObj1.push_back ( "Elem1" );
	if ( SonIguales ( vecObj1, vecObj2 ) )
	{
		cout << "Error caso 2: las listas con diferente numero de elementos deberian ser diferentes" << endl;
		bRes = false;
	}
	vecObj2.push_back ( "Elem1" );
	if ( !SonIguales ( vecObj1, vecObj2 ) )
	{
		cout << "Error caso 3: las listas deberian ser iguales" << endl;
		bRes = false;
	}
	vecObj1.push_back ( "Elem2 A" );
	vecObj2.push_back ( "Elem2 B" );
	if ( SonIguales ( vecObj1, vecObj2 ) )
	{
		cout << "Error caso 4: las listas deberian ser diferentes" << endl;
		bRes = false;
	}
	return( bRes );
}


bool TestColecciones ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Colecciones]" << ANSI::RESETEAR << endl;
	if ( TestSonIguales01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSonIguales02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToVector01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToList01() )
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
