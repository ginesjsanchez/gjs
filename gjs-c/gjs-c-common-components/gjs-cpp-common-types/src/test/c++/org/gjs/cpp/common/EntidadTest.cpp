#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestEntidad01 ()
{
	cout << "Test Entidad 01:" << endl;
	bool bRes = true;

	try
	{
		Entidad * entidad = new Entidad();
		if ( entidad->EsValida() || 
			 ( entidad->getNombre().size() != 0 ) ||
			 ( entidad->NumAtributos() != 0 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		entidad->setNombre( "Entidad1" ); 
		if ( entidad->EsValida() || 
			 ( entidad->getNombre().compare( "Entidad1" ) != 0 ) ||
			 ( entidad->NumAtributos() != 0 ) )
		{
			cout << "Error caso 2" << endl;
			bRes = false;
		}
		entidad->InsertarAtributo( TipoDatos::REAL, "Vladimiro", true ); 
		if ( !entidad->EsValida() || 
			 ( entidad->getNombre().compare( "Entidad1" ) != 0 ) ||
			 ( entidad->NumAtributos() != 1 ) )
		{
			cout << "Error caso 3" << endl;
			bRes = false;
		}

		Atributo * atributo1 = entidad->getAtributo( "Vladimiro" ); 
		Atributo * atributo2 = entidad->getAtributo( "Putin" );
		Atributo * atributo3 = entidad->getAtributo( 0 );
		Atributo * atributo4 = entidad->getAtributo( 1 );
		
		if ( ( atributo1 == NULL ) || 
			 ( atributo2 != NULL ) || 
			 ( atributo3 == NULL ) || 
			 ( atributo4 != NULL ) || 
			 ( atributo1 != atributo3 ) )
		{
			cout << "Error caso 4: [" << atributo1 << "]-[" << atributo2 << "]-[" << atributo3 << "]-[" << atributo4 << "]" << endl;
			bRes = false;
		}
		
		Atributo * atributo5 = new Atributo( TipoDatos::BOOLEANO, "1Capacitancia", false ); 
		entidad->InsertarAtributo( atributo5 ); 
		atributo1 = entidad->getAtributo( "Vladimiro" ); 
		atributo2 = entidad->getAtributo( "1Capacitancia" );
		atributo3 = entidad->getAtributo( 0 ); 
		atributo4 = entidad->getAtributo( 1 );
		if ( entidad->EsValida() || 
			 ( entidad->getNombre().compare( "Entidad1" ) != 0 ) ||
			 ( entidad->NumAtributos() != 2 ) || 
			 ( atributo1 == NULL ) || 
			 ( atributo2 == NULL ) || 
			 ( atributo3 == NULL ) || 
			 ( atributo4 == NULL ) || 
			 ( atributo1 != atributo4 ) || 
			 ( atributo2 != atributo3 ) )
		{
			cout << "Error caso 5: [" << ( (atributo3 != NULL) ? atributo3->getNombre() : "NULL" ) << "]-[" <<
										 ( (atributo4 != NULL) ? atributo4->getNombre() : "NULL" ) << "]" << endl;
			bRes = false;
		}


		entidad->EliminarAtributo( 1 );
		atributo1 = entidad->getAtributo( "Vladimiro" ); 
		atributo2 = entidad->getAtributo( "1Capacitancia" );
		if ( entidad->EsValida() || 
			 ( entidad->getNombre().compare( "Entidad1" ) != 0 ) ||
			 ( entidad->NumAtributos() != 1 ) || 
			 ( atributo1 != NULL ) || 
			 ( atributo2 == NULL ) )
		{
			cout << "Error caso 6: NumAtributos: " << entidad->NumAtributos() << " [" << atributo1 << "]-[" << atributo2 << "]" << endl;
			bRes = false;
		}
		entidad->EliminarAtributo( "1Capacitancia" );
		atributo1 = entidad->getAtributo( "Vladimiro" ); 
		atributo2 = entidad->getAtributo( "1Capacitancia" );
		if ( entidad->EsValida() || 
			 ( entidad->getNombre().compare( "Entidad1" ) != 0 ) ||
			 ( entidad->NumAtributos() != 0 ) || 
			 ( atributo1 != NULL ) || 
			 ( atributo2 != NULL ) )
		{
			cout << "Error caso 7: NumAtributos: " << entidad->NumAtributos() << " [" << atributo1 << "]-[" << atributo2 << "]" << endl;
			bRes = false;
		}
		delete entidad;
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

static bool TestEntidad02 ()
{
	cout << "Test Entidad 02:" << endl;
	bool bRes = true;

	try
	{
		Entidad entidad1( "Entidad1" );
		entidad1.InsertarAtributo( TipoDatos::ENTERO, "Atributo1", true ); 
		entidad1.InsertarAtributo( TipoDatos::CADENA, "Atributo2", true ); 

		Entidad entidad2( "Entidad2" );
		entidad2.InsertarAtributo( TipoDatos::ENTERO, "Atributo1", true ); 

		Entidad entidad3( "Entidad3" );
		entidad3.InsertarAtributo( TipoDatos::ENTERO, "Atributo1", true ); 
		entidad3.InsertarAtributo( TipoDatos::CADENA, "Atributo2", false ); 
		
		Entidad entidad4( "Entidad1" );
		entidad4.InsertarAtributo( TipoDatos::ENTERO, "Atributo1", true ); 
		entidad4.InsertarAtributo( TipoDatos::CADENA, "Atributo2", true ); 
		
		if ( !entidad1.EsValida() || 
				!entidad2.EsValida() || 
				!entidad3.EsValida() || 
				!entidad4.EsValida() || 
			 ( entidad1 == entidad2 ) ||
			 ( entidad1 == entidad3 ) ||
			 ( entidad1 != entidad4 ) ||
			 ( entidad2 == entidad3 ) ||
			 ( entidad2 == entidad4 ) ||
			 ( entidad3 == entidad4 ) )
		{
			cout << "Error caso 1" << endl;
			bRes = false;
		}
		
		entidad1.LimpiarAtributos();
		entidad2.LimpiarAtributos();
		entidad3.LimpiarAtributos();
		entidad4.LimpiarAtributos();
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


bool TestEntidad ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test Entidad]" << ANSI::RESETEAR << endl;
	if ( TestEntidad01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestEntidad02() )
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
