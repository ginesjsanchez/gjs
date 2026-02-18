#include "CppCommonTypes.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestListaValores01 ()
{
	cout << "Test ListaValores 01:" << endl;
	bool bRes = true;

	try
	{
		ListaValores * lista = new ListaValores();
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 0 ) )
		{
			cout << "Error caso 1: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}
		lista->InsertarValor( new Valor( "Vladimiro" ) ); 
		Valor * valor1 = lista->getValor( 0 ); 
		Valor * valor2 = lista->getValor( 1 ); 
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 1 ) ||
			 ( valor1 == NULL ) || 
			 ( valor2 != NULL ) )
		{
			cout << "Error caso 2: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}

		lista->InsertarValor( "Putin" ); 
		lista->InsertarValor( 0 ); 
		lista->InsertarValor( -37.02 ); 
		lista->InsertarValor( false ); 
		valor1 = lista->getValor( 0 ); 
		valor2 = lista->getValor( 1 ); 
		Valor * valor3 = lista->getValor( 2 ); 
		Valor * valor4= lista->getValor( 3 ); 
		Valor * valor5= lista->getValor( 4 ); 
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 5 ) ||
			 ( valor1 == NULL ) || 
			 ( valor2 == NULL ) ||
			 ( valor3 == NULL ) || 
			 ( valor4 == NULL )  || 
			 ( valor5 == NULL ) )
		{
			cout << "Error caso 3: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			cout << "\tValor1=" << ( ( valor1 != NULL ) ? valor1->getValor() : "NULO" ) << endl;
			cout << "\tValor2=" << ( ( valor2 != NULL ) ? valor2->getValor() : "NULO" ) << endl;
			cout << "\tValor3=" << ( ( valor3 != NULL ) ? valor3->getValor() : "NULO" ) << endl;
			cout << "\tValor4=" << ( ( valor4 != NULL ) ? valor4->getValor() : "NULO" ) << endl;
			cout << "\tValor5=" << ( ( valor5 != NULL ) ? valor5->getValor() : "NULO" ) << endl;
			bRes = false;
		}
		if ( bRes )
		{
			if ( ( valor1->getValor().compare( "Vladimiro" ) != 0 ) || 
				 ( valor2->getValor().compare( "Putin" ) != 0 ) ||
				 ( valor3->getValor().compare( "0" ) != 0 ) || 
				 ( valor4->getValor().compare( "-37.02" ) != 0 ) || 
				 ( valor5->getValor().compare( "Falso" ) != 0 ) )
			{
				cout << "Error caso 3b: [" << valor1->getValor() << "]-[" << valor2->getValor() << "]-[" << 
							valor3->getValor() << "]-[" << valor4->getValor() << "]-[" << valor5->getValor() << "]" << endl;
				bRes = false;
			}
		}
		lista->EliminarValor( 3 ); 
		valor1 = lista->getValor( 0 ); 
		valor2 = lista->getValor( 1 ); 
		valor3 = lista->getValor( 2 ); 
		valor4= lista->getValor( 3 ); 
		valor5= lista->getValor( 4 ); 
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 4 ) ||
			 ( valor1 == NULL ) || 
			 ( valor2 == NULL ) ||
			 ( valor3 == NULL ) || 
			 ( valor4 == NULL )  || 
			 ( valor5 != NULL ) )
		{
			cout << "Error caso 4: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			cout << "\tValor1=" << ( ( valor1 != NULL ) ? valor1->getValor() : "NULO" ) << endl;
			cout << "\tValor2=" << ( ( valor2 != NULL ) ? valor2->getValor() : "NULO" ) << endl;
			cout << "\tValor3=" << ( ( valor3 != NULL ) ? valor3->getValor() : "NULO" ) << endl;
			cout << "\tValor4=" << ( ( valor4 != NULL ) ? valor4->getValor() : "NULO" ) << endl;
			cout << "\tValor5=" << ( ( valor5 != NULL ) ? valor5->getValor() : "NULO" ) << endl;
			bRes = false;
		}
		if ( bRes )
		{
			if ( ( valor1->getValor().compare( "Vladimiro" ) != 0 ) || 
				 ( valor2->getValor().compare( "Putin" ) != 0 ) ||
				 ( valor3->getValor().compare( "0" ) != 0 ) || 
				 ( valor4->getValor().compare( "Falso" ) != 0 ) )
			{
				cout << "Error caso 4b: [" << valor1->getValor() << "]-[" << valor2->getValor() << "]-[" << 
							valor3->getValor() << "]-[" << valor4->getValor() << "]" << endl;
				bRes = false;
			}
		}
		
		lista->LimpiarValores();
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 0 ) )
		{
			cout << "Error caso 5: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}
		delete lista;
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

static bool TestListaValores02 ()
{
	cout << "Test ListaValores 02:" << endl;
	bool bRes = true;

	try
	{
		ListaValores * lista = new ListaValores( 4, false );
		Valor * valor1 = lista->getValor( 0 ); 
		Valor * valor2 = lista->getValor( 1 ); 
		Valor * valor3 = lista->getValor( 2 ); 
		Valor * valor4 = lista->getValor( 3 ); 
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 4 ) ||
			 ( valor1 == NULL )||
			 ( valor2 == NULL )||
			 ( valor3 == NULL )||
			 ( valor4 == NULL ) )
		{
			cout << "Error caso 1: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}
		if ( bRes )
		{
			if ( !valor1->EsNulo() || 
				 !valor2->EsNulo()||
				  !valor3->EsNulo() || 
				  !valor4->EsNulo() )
			{
				cout << "Error caso 1b: [" << valor1->getValor() << "]-[" << valor2->getValor() << "]-[" << 
							valor3->getValor() << "]-[" << valor4->getValor() << "]" << endl;
				bRes = false;
			}
		}
		lista->getValor(0)->setValor( "Vladimiro" ); 
		lista->getValor(1)->setValor( "Putin" ); 
		lista->getValor(2)->setValor( 0 ); 
		lista->getValor(3)->setValor( -37.02 ); 
		if ( ( valor1->getValor().compare( "Vladimiro" ) != 0 ) || 
			 ( valor2->getValor().compare( "Putin" ) != 0 ) ||
			 ( valor3->getValor().compare( "0" ) != 0 ) || 
			 ( valor4->getValor().compare( "-37.02" ) != 0 ) )
		{
			cout << "Error caso 2: [" << valor1->getValor() << "]-[" << valor2->getValor() << "]-[" << 
						valor3->getValor() << "]-[" << valor4->getValor() << "]" << endl;
			bRes = false;
		}
		lista->EliminarValor( 3 ); 
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 4 ) )
		{
			cout << "Error caso 2: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}
		
		lista->LimpiarValores();
		if ( !lista->EsValida() || 
			 ( lista->NumValores() != 4 ) )
		{
			cout << "Error caso 3: Valida=" << ToString( lista->EsValida() ) << "; NumValores=" << lista->NumValores() << endl;
			bRes = false;
		}
		delete lista;
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

bool TestListaValores ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test ListaValores]" << ANSI::RESETEAR << endl;
	if ( TestListaValores01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestListaValores02() )
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
