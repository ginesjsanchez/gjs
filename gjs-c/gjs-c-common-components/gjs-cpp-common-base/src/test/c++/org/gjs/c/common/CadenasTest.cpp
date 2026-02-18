#include "CppBase.h"

#include <iostream>


using namespace std;
using namespace org::gjs::cpp::common;


static bool TestToLowerCase01 ()
{
	cout << "Test ToLowerCase 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = ToLowerCase( sCadena );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12 AbC-DEFgH" );
	string sExpected = string( "12 abc-defgh" );
	sRes = ToLowerCase( sCadena );
	if ( sRes != sExpected )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestToUpperCase01 ()
{
	cout << "Test ToUpperCase 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = ToUpperCase( sCadena );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12 AbC-DEFgH" );
	string sExpected = string( "12 ABC-DEFGH" );
	sRes = ToUpperCase( sCadena );
	if ( sRes != sExpected )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestReemplazarTodos01 ()
{
	cout << "Test ReemplazarTodos 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	char cBuscar = '$';
	char cReemplazo = '#';
	string sRes = ReemplazarTodos( sCadena, cBuscar, cReemplazo );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = ReemplazarTodos( sCadena, cBuscar, cReemplazo );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234$6789" );
	sRes = ReemplazarTodos( sCadena, cBuscar, cReemplazo );
	if ( sRes != "1234#6789" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "$234$678$" );
	sRes = ReemplazarTodos( sCadena, cBuscar, cReemplazo );
	if ( sRes != "#234#678#" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestReemplazarTodos02 ()
{
	cout << "Test ReemplazarTodos 02:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sBuscar = string( "$_$" );
	string sReemplazo = string( "##" );;
	string sRes = ReemplazarTodos( sCadena, sBuscar, sReemplazo );
	if ( sRes.size() != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = ReemplazarTodos( sCadena, sBuscar, sReemplazo );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234$_$6789" );
	sRes = ReemplazarTodos( sCadena, sBuscar, sReemplazo );
	if ( sRes != "1234##6789" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "$_$ 234$_$678 $_$ abc$_ $cde$_$" );
	sRes = ReemplazarTodos( sCadena, sBuscar, sReemplazo );
	if ( sRes != "## 234##678 ## abc$_ $cde##" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarTodos01 ()
{
	cout << "Test EliminarTodos 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	char cBuscar = '$';
	string sRes = EliminarTodos( sCadena, cBuscar );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarTodos( sCadena, cBuscar );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234$6789" );
	sRes = EliminarTodos( sCadena, cBuscar );
	if ( sRes != "12346789" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "$234$678$" );
	sRes = EliminarTodos( sCadena, cBuscar );
	if ( sRes != "234678" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarTodos02 ()
{
	cout << "Test EliminarTodos 02:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sBuscar = string( "$_$" );
	string sRes = EliminarTodos( sCadena, sBuscar );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarTodos( sCadena, sBuscar );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234$_$6789" );
	sRes = EliminarTodos( sCadena, sBuscar );
	if ( sRes != "12346789" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "$_$ 234$_$678 $_$ abc$_ $cde$_$" );
	sRes = EliminarTodos( sCadena, sBuscar );
	if ( sRes != " 234678  abc$_ $cde" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789\n" );
	sBuscar = "\n";
	sRes = EliminarTodos( sCadena, sBuscar );
	if ( sRes != "123456789" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestLimpiar01 ()
{
	cout << "Test Limpiar01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = Limpiar( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = Limpiar( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "\n\t12345\t6789\nabc\n" );
	sRes = Limpiar( sCadena );
	if ( sRes != "123456789abc" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestFormatearBlancos01 ()
{
	cout << "Test FormatearBlancos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = FormatearBlancos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = FormatearBlancos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123  456  789 abc  " );
	sRes = FormatearBlancos( sCadena );
	if ( sRes != "123 456 789 abc" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestContieneBlancos01 ()
{
	cout << "Test ContieneBlancos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = ContieneBlancos( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = ContieneBlancos( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123  456  789 abc  " );
	bRes = ContieneBlancos( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestContieneTabuladores01 ()
{
	cout << "Test ContieneTabuladores01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = ContieneTabuladores( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = ContieneTabuladores( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123\t456  789 abc  " );
	bRes = ContieneTabuladores( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestContieneCaracteresNoImprimibles01 ()
{
	cout << "Test ContieneCaracteresNoImprimibles01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = ContieneCaracteresNoImprimibles( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = ContieneCaracteresNoImprimibles( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123\u0001456  789 abc  " );
	bRes = ContieneCaracteresNoImprimibles( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestContieneCaracteresNoAlfanumericos01 ()
{
	cout << "Test ContieneCaracteresNoAlfanumericos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = ContieneCaracteresNoAlfanumericos( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = ContieneCaracteresNoAlfanumericos( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123.456  789 abc : " );
	bRes = ContieneCaracteresNoAlfanumericos( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestContieneCaracteresNoEstandar01 ()
{
	cout << "Test ContieneCaracteresNoEstandar01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = ContieneCaracteresNoEstandar( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = ContieneCaracteresNoEstandar( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  123ñ456  789 abc  " );
	bRes = ContieneCaracteresNoEstandar( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestCoherenciaParentesis01 ()
{
	cout << "Test CoherenciaParentesis01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = CoherenciaParentesis( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = CoherenciaParentesis( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  (123 (456()789) abc)" );
	bRes = CoherenciaParentesis( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  (123 (456()789 abc)" );
	bRes = CoherenciaParentesis( sCadena );
	if ( bRes )
	{
		cout << "Error caso 4: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestCoherenciaLlaves01 ()
{
	cout << "Test CoherenciaLlaves01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = CoherenciaLlaves( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = CoherenciaLlaves( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  {123 {456{}789} abc}" );
	bRes = CoherenciaLlaves( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  {123 {456{}789 abc}" );
	bRes = CoherenciaLlaves( sCadena );
	if ( bRes )
	{
		cout << "Error caso 4: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestCoherenciaCorchetes01 ()
{
	cout << "Test CoherenciaCorchetes01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = CoherenciaCorchetes( sCadena );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = CoherenciaCorchetes( sCadena );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  [123 [456[]789] abc]" );
	bRes = CoherenciaCorchetes( sCadena );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  [123 [456[]789 abc]" );
	bRes = CoherenciaCorchetes( sCadena );
	if ( bRes )
	{
		cout << "Error caso 4: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestCoherenciaParejaSignos01 ()
{
	cout << "Test CoherenciaParejaSignos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( bRes )
	{
		cout << "Error caso 1: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( bRes )
	{
		cout << "Error caso 2: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  @123 @456@$789$ abc$" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( !bRes )
	{
		cout << "Error caso 3: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  @123 @456@$789 abc$" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( bRes )
	{
		cout << "Error caso 4: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  $123 @456@$789$ abc$" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( !bRes )
	{
		cout << "Error caso 5: [" << bRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "  $123 @456@$789@ abc$" );
	bRes = CoherenciaParejaSignos( sCadena, '@', '$' );
	if ( bRes )
	{
		cout << "Error caso 6: [" << bRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarCaracter01 ()
{
	cout << "Test EliminarCaracter01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarCaracter( sCadena, 0 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarCaracter( sCadena, -1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracter( sCadena, 20 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracter( sCadena, 0 );
	if ( sRes != "23456789" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracter( sCadena, sCadena.size() - 1 );
	if ( sRes != "12345678" )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracter( sCadena, 3 );
	if ( sRes != "1235678" )
	{
		cout << "Error caso 6: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarCaracteres01 ()
{
	cout << "Test EliminarCaracteres01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarCaracteres( sCadena, 0, 1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarCaracteres( sCadena, -1, 1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracteres( sCadena, 0, 0 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracteres( sCadena, 20, 1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracteres( sCadena, 0, 1 );
	if ( sRes != "23456789" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracteres( sCadena, sCadena.size() - 1, 2 );
	if ( sRes != "12345678" )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarCaracteres( sCadena, 3, 4 );
	if ( sRes != "1238" )
	{
		cout << "Error caso 6: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarPrimerosCaracteres01 ()
{
	cout << "Test EliminarPrimerosCaracteres01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarPrimerosCaracteres( sCadena, 1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarPrimerosCaracteres( sCadena, -1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarPrimerosCaracteres( sCadena, 0 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarPrimerosCaracteres( sCadena, 1 );
	if ( sRes != "23456789" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarPrimerosCaracteres( sCadena, sCadena.size() + 1 );
	if ( sRes != "" )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarPrimerosCaracteres( sCadena, 3 );
	if ( sRes != "456789" )
	{
		cout << "Error caso 6: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarUltimosCaracteres01 ()
{
	cout << "Test EliminarUltimosCaracteres01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarUltimosCaracteres( sCadena, 1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarUltimosCaracteres( sCadena, -1 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarUltimosCaracteres( sCadena, 0 );
	if ( sRes != sCadena )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarUltimosCaracteres( sCadena, 1 );
	if ( sRes != "12345678" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarUltimosCaracteres( sCadena, 20 );
	if ( sRes != "" )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	sRes = EliminarUltimosCaracteres( sCadena, 3 );
	if ( sRes != "123456" )
	{
		cout << "Error caso 6: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarApariciones01 ()
{
	cout << "Test EliminarApariciones01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sSubcadena = string( "" );
	string sRes = EliminarApariciones( sCadena, sSubcadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarApariciones( sCadena, sSubcadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sSubcadena = string( "abc" );
	sRes = EliminarApariciones( sCadena, sSubcadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sSubcadena = string( "345" );
	sRes = EliminarApariciones( sCadena, sSubcadena );
	if ( sRes != "12678" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc fgh 123 abc456" );
	sSubcadena = string( "abc" );
	sRes = EliminarApariciones( sCadena, sSubcadena );
	if ( sRes != " fgh 123 456" )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarBlancos01 ()
{
	cout << "Test EliminarBlancos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarBlancos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarBlancos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc fgh" );
	sRes = EliminarBlancos( sCadena );
	if ( sRes != "abcfgh" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " a b c f g h" );
	sRes = EliminarBlancos( sCadena );
	if ( sRes != "abcfgh" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarTabuladores01 ()
{
	cout << "Test EliminarTabuladores01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarTabuladores( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarTabuladores( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc\tfgh" );
	sRes = EliminarTabuladores( sCadena );
	if ( sRes != "abcfgh" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " a\tb\tc\tf\tg\th" );
	sRes = EliminarTabuladores( sCadena );
	if ( sRes != " abcfgh" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarCaracteresNoAlfanumericos01 ()
{
	cout << "Test EliminarCaracteresNoAlfanumericos01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarCaracteresNoAlfanumericos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarCaracteresNoAlfanumericos( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc:fgh" );
	sRes = EliminarCaracteresNoAlfanumericos( sCadena );
	if ( sRes != "abcfgh" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " a.b,c-f\tg(h1" );
	sRes = EliminarCaracteresNoAlfanumericos( sCadena );
	if ( sRes != "abcfgh1" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarCaracteresNoEstandar01 ()
{
	cout << "Test EliminarCaracteresNoEstandar01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarCaracteresNoEstandar( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123456789" );
	sRes = EliminarCaracteresNoEstandar( sCadena );
	if ( sRes != sCadena )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abcñfgh" );
	sRes = EliminarCaracteresNoEstandar( sCadena );
	if ( sRes != "abcfgh" )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " añbçcf\tg\u0200h1" );
	sRes = EliminarCaracteresNoEstandar( sCadena );
	if ( sRes != " abcf\tgh1" )
	{
		cout << "Error caso 4: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSubcadenas01 ()
{
	cout << "Test Subcadenas 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	char cBuscar = '#';
	string sHasta = SubcadenaHasta( sCadena, cBuscar );
	string sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta.size() != 0 ) || ( sDesde.size() != 0 ) )
	{
		cout << "Error caso 1: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234567890" );
	sHasta = SubcadenaHasta( sCadena, cBuscar );
	sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta != sCadena ) || ( sDesde.size() != 0 ) )
	{
		cout << "Error caso 2: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345#67890" );
	sHasta = SubcadenaHasta( sCadena, cBuscar );
	sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta != "12345" ) || ( sDesde != "67890" ) )
	{
		cout << "Error caso 3: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234567890#" );
	sHasta = SubcadenaHasta( sCadena, cBuscar );
	sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta != "1234567890" ) || ( sDesde.size() != 0 ) )
	{
		cout << "Error caso 4: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	sCadena = string( "#1234567890" );
	sHasta = SubcadenaHasta( sCadena, cBuscar );
	sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta.size() != 0 ) || ( sDesde != "1234567890" ) )
	{
		cout << "Error caso 5: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	sCadena = string( "#" );
	sHasta = SubcadenaHasta( sCadena, cBuscar );
	sDesde = SubcadenaDesde( sCadena, cBuscar );
	if ( ( sHasta.size() != 0 ) || ( sDesde.size() != 0 ) )
	{
		cout << "Error caso 6: [" << sHasta << "]-[" << sDesde << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestTrim01 ()
{
	cout << "Test Trim 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sLTrim = LTrim( sCadena );
	string sRTrim = RTrim( sCadena );
	string sTrim = Trim( sCadena );
	if ( ( sRTrim.size() != 0 ) || ( sLTrim.size() != 0 ) || ( sTrim.size() != 0 ) )
	{
		cout << "Error caso 1: [" << sLTrim << "]-[" << sRTrim << "]-[" << sTrim << "]" << endl;
		bRes = false;
	}
	sCadena = string( "       " );
	sLTrim = LTrim( sCadena );
	sRTrim = RTrim( sCadena );
	sTrim = Trim( sCadena );
	if ( ( sRTrim.size() != 0 ) || ( sLTrim.size() != 0 ) || ( sTrim.size() != 0 ) )
	{
		cout << "Error caso 2: [" << sLTrim << "]-[" << sRTrim << "]-[" << sTrim << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1234567890" );
	sLTrim = LTrim( sCadena );
	sRTrim = RTrim( sCadena );
	sTrim = Trim( sCadena );
	if ( ( sLTrim != sCadena ) || ( sRTrim != sCadena )  || ( sTrim != sCadena ))
	{
		cout << "Error caso 3: [" << sLTrim << "]-[" << sRTrim << "]-[" << sTrim << "]" << endl;
		bRes = false;
	}
	sCadena = string( "   12345 67890   " );
	sLTrim = LTrim( sCadena );
	sRTrim = RTrim( sCadena );
	sTrim = Trim( sCadena );
	if ( ( sLTrim != "12345 67890   " ) || ( sRTrim != "   12345 67890" )  || ( sTrim != "12345 67890" ))
	{
		cout << "Error caso 4: [" << sLTrim << "]-[" << sRTrim << "]-[" << sTrim << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEmpiezaTermina01 ()
{
	cout << "Test EmpiezaPor/TerminaPor 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sIni = string( "" );
	string sFin = string( "" );
	if ( !EmpiezaPor( sCadena, sIni ) || !TerminaPor( sCadena, sFin ) )
	{
		cout << "Error caso 1: [" << sCadena << "] deberia empezar por [" << sIni << "] y acabar por [" << sFin << "]" << endl;
		bRes = false;
	}
	sIni = string( "123" );
	sFin = string( "xyz" );
	if ( EmpiezaPor( sCadena, sIni ) || TerminaPor( sCadena, sFin ) )
	{
		cout << "Error caso 2: [" << sCadena << "] no deberia empezar por [" << sIni << "] y acabar por [" << sFin << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abcdefg" );
	if ( EmpiezaPor( sCadena, sIni ) || TerminaPor( sCadena, sFin ) )
	{
		cout << "Error caso 3: [" << sCadena << "] no deberia empezar por [" << sIni << "] y acabar por [" << sFin << "]" << endl;
		bRes = false;
	}
	sCadena = string( "xyzabcdefg123" );
	if ( EmpiezaPor( sCadena, sIni ) || TerminaPor( sCadena, sFin ) )
	{
		cout << "Error caso 4: [" << sCadena << "] no deberia empezar por [" << sIni << "] y acabar por [" << sFin << "]" << endl;
		bRes = false;
	}
	sCadena = string( "123abcdefgxyz" );
	if ( !EmpiezaPor( sCadena, sIni ) || !TerminaPor( sCadena, sFin ) )
	{
		cout << "Error caso 5: [" << sCadena << "] deberia empezar por [" << sIni << "] y acabar por [" << sFin << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestTerminaEnSaltoLinea01 ()
{
	cout << "Test TerminaEnSaltoLinea 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( TerminaEnSaltoLinea( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer" );
	if ( TerminaEnSaltoLinea( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer\n" );
	if ( !TerminaEnSaltoLinea( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer\r" );
	if ( !TerminaEnSaltoLinea( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc\n 12,\rviewer" );
	if ( TerminaEnSaltoLinea( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEliminarUltimoSaltoLinea01 ()
{
	cout << "Test EliminarUltimoSaltoLinea 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	string sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( sCadena ) != 0 )
	{
		cout << "Error caso 1: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " " );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( sCadena ) != 0 )
	{
		cout << "Error caso 2: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( " \r" );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( " " ) != 0 )
	{
		cout << "Error caso 3: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer" );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( sCadena ) != 0 )
	{
		cout << "Error caso 42: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer\n" );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( "abc 12, viewer" ) != 0 )
	{
		cout << "Error caso 5: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc 12, viewer\r\n" );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( "abc 12, viewer" ) != 0 )
	{
		cout << "Error caso 6: [" << sRes << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc\n 12,\rviewer" );
	sRes = EliminarUltimoSaltoLinea( sCadena );
	if ( sRes.compare( sCadena ) != 0 )
	{
		cout << "Error caso 7: [" << sRes << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestTieneEspacios01 ()
{
	cout << "Test TieneEspacios 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( TieneEspacios( sCadena ) )
	{
		cout << "Error caso 1" << endl;
		bRes = false;
	}
	sCadena = string( " " );
	if ( !TieneEspacios( sCadena ) )
	{
		cout << "Error caso 2" << endl;
		bRes = false;
	}	return( bRes );
	sCadena = string( " a" );
	if ( !TieneEspacios( sCadena ) )
	{
		cout << "Error caso 3" << endl;
		bRes = false;
	}	return( bRes );
	sCadena = string( "b " );
	if ( !TieneEspacios( sCadena ) )
	{
		cout << "Error caso 4" << endl;
		bRes = false;
	}	return( bRes );
	sCadena = string( "\tx" );
	if ( !TieneEspacios( sCadena ) )
	{
		cout << "Error caso 5" << endl;
		bRes = false;
	}	return( bRes );
	sCadena = string( "aye\n\raye" );
	if ( !TieneEspacios( sCadena ) )
	{
		cout << "Error caso 6" << endl;
		bRes = false;
	}	return( bRes );
	sCadena = string( "abcdefge" );
	if ( TieneEspacios( sCadena ) )
	{
		cout << "Error caso 7" << endl;
		bRes = false;
	}	return( bRes );
}

static bool TestSonIgualesIn01 ()
{
	cout << "Test SonIgualesIn 01:" << endl;
	bool bRes = true;
	string sCadena1 = string( "" );
	string sCadena2 = string( "" );
	if ( !SonIgualesIn( sCadena1, sCadena2 ) )
	{
		cout << "Error caso 1: [" << sCadena1 << "] vs [" << sCadena2 << "]" << endl;
		bRes = false;
	}
	sCadena1 = string( "abc" );
	sCadena2 = string( "xyz" );
	if ( SonIgualesIn( sCadena1, sCadena2 ) )
	{
		cout << "Error caso 2: [" << sCadena1 << "] vs [" << sCadena2 << "]" << endl;
		bRes = false;
	}
	sCadena1 = string( " abc 123 XyZ #&" );
	sCadena2 = string( " ABC 123 xyz #&" );
	if ( !SonIgualesIn( sCadena1, sCadena2 ) )
	{
		cout << "Error caso 3: [" << sCadena1 << "] vs [" << sCadena2 << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsPalabra01 ()
{
	cout << "Test EsPalabra 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsPalabra( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc" );
	if ( !EsPalabra( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab#c" );
	if ( EsPalabra( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab c" );
	if ( EsPalabra( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( EsPalabra( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsToken01 ()
{
	cout << "Test EsToken 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	if ( !EsToken( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "Aab#c3" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab 3c" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "_Az2" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "2Az_" );
	if ( EsToken( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "Az2_" );
	if ( !EsToken( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ABRIR" );
	if ( !EsToken( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsURL01 ()
{
	cout << "Test EsURL 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "localhost" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://localhost" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://127.0.0.1" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://miralbueno.com" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "gopher://marchamalo.com/" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ftp://granadilla.ar/path1/path2" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://granadilla.ar/?hue=br" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "://granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 10: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 11: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://path?hue=br#" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURL( sCadena ) )
	{
		cout << "Error caso 12: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 13: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://pc2.subnet.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 14: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 15: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 16: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 17: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ms-help://granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 18: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://www.granadilla.ar:8080" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURL( sCadena ) )
	{
		cout << "Error caso 19: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsURN01 ()
{
	cout << "Test EsURN 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "path" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path1/path2" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "path1/path2" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue=br#cool&pit=false" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path1/path2?hue=br&pit=false" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue=" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue=12" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 10: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue=12&" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 11: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/path?hue=12&so=pasivo1" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 12: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/reyno/fuero?usuario=garcia&clave=philipoussis" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 13: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/site1/index.html" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 14: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/site1/index.htm" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 15: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/site1/code.php?param1=10&param2=azerbaiyan" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURN( sCadena ) )
	{
		cout << "Error caso 16: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "/site1/index.ht-ml" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURN( sCadena ) )
	{
		cout << "Error caso 15: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsURI01 ()
{
	cout << "Test EsURI 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "localhost" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://localhost" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://127.0.0.1" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://miralbueno.com" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "gopher://marchamalo.com/" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ftp://granadilla.ar/path1/path2" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://granadilla.ar/path?hue=br#cool&pit=false" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "://granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 10: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar/path?hue" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 11: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar/path?hue=" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 12: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar/path?hue=12" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 13: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar/path?hue=12&" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 14: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar/path?hue=12&so=pasivo1" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 15: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 16: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://path?hue=br#" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 17: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 18: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://pc2.subnet.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 19: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 20: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "www.granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 21: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 22: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ms-help://granadilla.ar" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 23: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "https://www.granadilla.ar:8080" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 24: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ftp://sobrarbe.ara:1021/reyno/fuero?usuario=garcia&clave=philipoussis" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 25: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://localhost:45301/site1/index.html" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( !EsURI( sCadena ) )
	{
		cout << "Error caso 26: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "http://localhost:45301/site1/index.barra-cuda" );
	cout << "\t Caso [" << sCadena << "]" << endl;
	if ( EsURI( sCadena ) )
	{
		cout << "Error caso 27: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsNombreFichero01 ()
{
	cout << "Test EsNombreFichero 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc" );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab#c" );
	if ( EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab c" );
	if ( EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "." );
	if ( EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abc.sh" );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( ".sh.xyy." );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "_abc.123" );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( ".." );
	if ( EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "..." );
	if ( !EsNombreFichero( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}


static bool TestEsNatural01 ()
{
	cout << "Test EsNatural 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsNatural( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	if ( EsNatural( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( " 3" );
	if ( EsNatural( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "-123" );
	if ( EsNatural( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( !EsNatural( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12.7" );
	if ( EsNatural( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsEntero01 ()
{
	cout << "Test EsEntero 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsEntero( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	if ( EsEntero( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( " 3" );
	if ( EsEntero( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "-123" );
	if ( !EsEntero( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( !EsEntero( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12.7" );
	if ( EsEntero( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsReal01 ()
{
	cout << "Test EsReal 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsReal( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	if ( EsReal( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( " 0.0" );
	if ( EsReal( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "-123" );
	if ( !EsReal( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( !EsReal( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "3.14" );
	if ( !EsReal( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "-0.0012" );
	if ( !EsReal( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestEsBooleano01 ()
{
	cout << "Test EsBooleano 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	if ( EsBooleano( sCadena ) )
	{
		cout << "Error caso 1: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ab_c3" );
	if ( EsBooleano( sCadena ) )
	{
		cout << "Error caso 2: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "1" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 3: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "0" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 4: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "12345" );
	if ( EsBooleano( sCadena ) )
	{
		cout << "Error caso 5: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "ciErto" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 6: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "faLSO" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 7: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "TRUE" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 8: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "false" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 9: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "T" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 10: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "C" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 11: [" << sCadena << "]" << endl;
		bRes = false;
	}
	sCadena = string( "f" );
	if ( !EsBooleano( sCadena ) )
	{
		cout << "Error caso 12: [" << sCadena << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestBuscarPrimero01 ()
{
	cout << "Test BuscarPrimero 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	size_t pos = BuscarPrimero( sCadena, {} );
	if ( pos != string::npos )
	{
		cout << "Error caso 1: [" << pos << "]" << endl;
		bRes = false;
	}
	pos = BuscarPrimero( sCadena, { " ", "-" } );
	if ( pos != string::npos )
	{
		cout << "Error caso 2: [" << pos << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abcdefghijklmnopqrstuvwxyz" );
	pos = BuscarPrimero( sCadena, {} );
	if ( pos != string::npos )
	{
		cout << "Error caso 3: [" << pos << "]" << endl;
		bRes = false;
	}
	sCadena = string( " abcde-fghijklmnop qrstuvwxyz-" );
	pos = BuscarPrimero( sCadena, { " ", "-" } );
	if ( pos != 0 )
	{
		cout << "Error caso 4: [" << pos << "]" << endl;
		bRes = false;
	}
	size_t tam = 0;
	pos = BuscarPrimero( sCadena, { " ", "-" }, &tam, 1 );
	if ( ( pos != 6 ) && ( tam != 1 ) )
	{
		cout << "Error caso 5: [" << pos << "]" << endl;
		bRes = false;
	}
	pos = BuscarPrimero( sCadena, { " ", "-" }, &tam, 21 );
	if ( ( pos != 29 ) && ( tam != 1 ) )
	{
		cout << "Error caso 6: [" << pos << "]" << endl;
		bRes = false;
	}
	pos = BuscarPrimero( sCadena, { " ", "-" }, &tam, 41 );
	if ( ( pos != string::npos ) && ( tam != 0 ) )
	{
		cout << "Error caso 6: [" << pos << "]" << endl;
		bRes = false;
	}
	pos = BuscarPrimero( sCadena, { "-fg", " q" }, &tam, 0 );
	if ( ( pos != 6 ) && ( tam != 3 ) )
	{
		cout << "Error caso 7: [" << pos << "]" << endl;
		bRes = false;
	}
	pos = BuscarPrimero( sCadena, { "-fg", " q" }, &tam, 10 );
	if ( ( pos != 18 ) && ( tam != 2 ) )
	{
		cout << "Error caso 8: [" << pos << "]" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestSeparar01 ()
{
	cout << "Test Separar 01:" << endl;
	bool bRes = true;
	string sCadena = string( "" );
	vector<string> vector = Separar( sCadena, {} );
	if ( vector.size() != 0 )
	{
		cout << "Error caso 1: [" << vector.size() << "]" << endl;
		bRes = false;
	}
	vector = Separar( sCadena, { " ", "-" } );
	if ( vector.size() != 0 )
	{
		cout << "Error caso 2: [" << vector.size() << "]" << endl;
		bRes = false;
	}
	sCadena = string( "abcdefghijklmnopqrstuvwxyz" );
	vector = Separar( sCadena, {} );
	if ( vector.size() != 1 )
	{
		cout << "Error caso 3: [" << vector.size() << "]" << endl;
		bRes = false;
	}
	sCadena = string( " abcde-fghijklmnop qrstuvwxyz-" );
	vector = Separar( sCadena, { " ", "-" } );
	if ( vector.size() != 5 )
	{
		cout << "Error caso 4: Tam=" << vector.size() << endl;
		bRes = false;
	}
	else
	{
		if ( ( vector[ 0 ].compare( "" ) != 0 ) ||
				( vector[ 1 ].compare( "abcde" ) != 0 ) ||
				( vector[ 2 ].compare( "fghijklmnop" ) != 0 ) ||
				( vector[ 3 ].compare( "qrstuvwxyz" ) != 0 ) ||
				( vector[ 4 ].compare( "" ) != 0 ) )
		{
			cout << "Error caso 4: valores erroneos" << endl;
			cout << ToString( vector ) << endl;
			bRes = false;
		}
	}
	vector = Separar( sCadena, { "-fg", " q" } );
	if ( vector.size() != 3 )
	{
		cout << "Error caso 5:  Tam=" << vector.size() << endl;
		bRes = false;
	}
	else
	{
		if ( ( vector[ 0 ].compare( " abcde" ) != 0 ) ||
				( vector[ 1 ].compare( "hijklmnop" ) != 0 ) ||
				( vector[ 2 ].compare( "rstuvwxyz-" ) != 0 ) )
		{
			cout << "Error caso 5: valores erroneos" << endl;
			cout << ToString( vector ) << endl;
			bRes = false;
		}
	}
	sCadena = string( "abcde\t\tfghij\tqrstu\tvwxyz" );
	vector = Separar( sCadena, { "\t" } );
	if ( vector.size() != 5 )
	{
		cout << "Error caso 6: Tam=" << vector.size() << endl;
		bRes = false;
	}
	else
	{
		if ( ( vector[ 0 ].compare( "abcde" ) != 0 ) ||
				( vector[ 1 ].compare( "" ) != 0 ) ||
				( vector[ 2 ].compare( "fghij" ) != 0 ) ||
				( vector[ 3 ].compare( "qrstu" ) != 0 ) ||
				( vector[ 4 ].compare( "vwxyz" ) != 0 ) )
		{
			cout << "Error caso 6: valores erroneos" << endl;
			cout << ToString( vector ) << endl;
			bRes = false;
		}
	}
	return( bRes );
}

bool TestCadenas ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Cadenas]" << ANSI::RESETEAR << endl;
	if ( TestToLowerCase01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestToUpperCase01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestReemplazarTodos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestReemplazarTodos02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarTodos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarTodos02() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestLimpiar01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestFormatearBlancos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestContieneBlancos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestContieneTabuladores01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestContieneCaracteresNoImprimibles01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestContieneCaracteresNoAlfanumericos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
    if ( TestContieneCaracteresNoEstandar01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestCoherenciaParentesis01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestCoherenciaLlaves01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestCoherenciaCorchetes01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestCoherenciaParejaSignos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarCaracter01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarCaracteres01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarPrimerosCaracteres01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarUltimosCaracteres01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarApariciones01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarBlancos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarTabuladores01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarCaracteresNoAlfanumericos01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarCaracteresNoEstandar01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}

	if ( TestSubcadenas01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestTrim01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEmpiezaTermina01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestTerminaEnSaltoLinea01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEliminarUltimoSaltoLinea01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSonIgualesIn01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsPalabra01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsToken01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsNombreFichero01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsNatural01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsEntero01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsReal01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsBooleano01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsURL01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsURN01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEsURI01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestTieneEspacios01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestBuscarPrimero01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestSeparar01() )
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
