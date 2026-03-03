#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $packageNamespace = ${package.replaceAll("\.","::")})

${symbol_pound}include <CppTest.h>

${symbol_pound}include "${capitalizedName}.h"




using namespace ${packageNamespace};
using namespace org::gjs::cpp::common;
using namespace org::gjs::cpp::common::test;
using namespace std;




static bool TestSampleType01 ()
{
	cout << "Test SampleType 01:" << endl;
	bool bRes = true;

	try
	{
		SampleType * ejemplo = new SampleType();
		if ( !ejemplo->IsValid() )
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



bool TestSampleType ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test SampleType]" << ANSI::RESETEAR << endl;
	if ( TestSampleType01() )
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
