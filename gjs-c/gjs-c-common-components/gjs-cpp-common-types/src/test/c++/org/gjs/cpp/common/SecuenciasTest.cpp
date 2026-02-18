#include "CppCommonTypes.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;

const unsigned char SECUENCIA_0[] = "";
const unsigned char SECUENCIA_1[] = "$%·7daklerjw?546";
const unsigned char SECUENCIA_2[] = "1234567890abcdef";
const unsigned char SECUENCIA_3[] = "$%·7daklerj";


static bool TestSonIguales01 ()
{
	cout << "Test SonIguales 01:" << endl;
	bool bRes = true;
	bool bRet = SonIguales( SECUENCIA_1, SECUENCIA_0 );	
	if ( bRet )
	{
		cout << "Error caso 1: [" << bRet << "]" << endl;
		bRes = false;
	}
	bRet = SonIguales( SECUENCIA_1, SECUENCIA_1 );	
	if ( !bRet )
	{
		cout << "Error caso 2: [" << bRet << "]" << endl;
		bRes = false;
	}
	bRet = SonIguales( SECUENCIA_1, SECUENCIA_2 );	
	if ( bRet )
	{
		cout << "Error caso 3: [" << bRet << "]" << endl;
		bRes = false;
	}
	bRet = SonIguales( SECUENCIA_1, SECUENCIA_3 );	
	if ( bRet )
	{
		cout << "Error caso 4: [" << bRet << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

bool TestSecuencias () 
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Secuencias]" << ANSI::RESETEAR << endl;
	if ( TestSonIguales01() )
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
