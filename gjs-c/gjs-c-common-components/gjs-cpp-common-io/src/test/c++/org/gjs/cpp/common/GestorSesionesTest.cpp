#include "CppCommonIo.h"
#include <CppBase.h>



using namespace std;
using namespace org::gjs::cpp::common;




static bool TestGestorSesiones01 ()
{
	cout << "Test GestorSesiones 01:" << endl;
	bool bRes = true;

	try
	{
		GestorSesiones * gestor = new GestorSesiones();
		if ( gestor->NumSesiones() != 0 )
		{
			cout << "Error caso 1: NumSesiones=" << gestor->NumSesiones() << endl;
			bRes = false;
		}
		if ( gestor->Abrir( "Nombre Invalido" ) )
		{
			cout << "Error caso 1: Usuario invalido" << endl;
			bRes = false;
		}
		if ( !gestor->Abrir( "Vladimiro" ) || !gestor->Abrir( "Volodimiro" ) )
		{
			cout << "Error caso 2: apertura erronea" << endl;
			bRes = false;
		}
		if ( !gestor->EstaAbierta( "Vladimiro" ) ||
			 !gestor->EstaAbierta( "Volodimiro" ) ||
				gestor->NumSesiones() != 2 )
		{
			cout << "Error caso 2: NumSesiones=" << gestor->NumSesiones() << endl;
			bRes = false;
		}
		if ( bRes )
		{
			Esperar( 1100 );
			time_t ahora = time( 0 );
			if ( ( ahora <= gestor->TiempoInicio( "Vladimiro" ) ) ||
				 ( gestor->TiempoInicio( "Vladimiro" ) !=  gestor->TiempoActividad( "Vladimiro" ) ) ||
				 ( gestor->TiempoTranscurrido( "Vladimiro" ) <= 0 ) ) 
			{
				cout << "Error caso 2: Datos temporales incorrectos" << endl;
				cout << "Inicio : " << gestor->TiempoInicio( "Vladimiro" ) << endl;
				cout << "Activ. : " << gestor->TiempoActividad( "Vladimiro" ) << endl;
				cout << "Transc.: " << gestor->TiempoTranscurrido( "Vladimiro" ) << endl;
				bRes = false;
			}
			Esperar( 1000 );
			gestor->Actividad( "Vladimiro" );
			if ( gestor->TiempoInicio( "Vladimiro" ) ==  gestor->TiempoActividad( "Vladimiro" ) ) 
			{
				cout << "Error caso 3: Datos temporales incorrectos" << endl;
				bRes = false;
			}
			
			gestor->Cerrar( "Vladimiro" ); 
			if ( gestor->EstaAbierta( "Vladimiro" ) || 
				!gestor->EstaAbierta( "Volodimiro" ) ||
				( gestor->NumSesiones() != 1 ) )
			{
				cout << "Error caso 4: NumSesiones=" << gestor->NumSesiones() << endl;
				bRes = false;
			}
			
			gestor->Limpiar();
			if ( gestor->EstaAbierta( "Vladimiro" ) || 
				gestor->EstaAbierta( "Volodimiro" ) ||
				( gestor->NumSesiones() != 0 ) )
			{
				cout << "Error caso 5: NumSesiones=" << gestor->NumSesiones() << endl;
				bRes = false;
			}
		}
		delete gestor;
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

bool TestGestorSesiones ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test GestorSesiones]" << ANSI::RESETEAR << endl;
	if ( TestGestorSesiones01() )
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
