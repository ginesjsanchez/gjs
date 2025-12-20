#include "CppCommonSupport.h"




using namespace std;
using namespace org::gjs::cpp::common;




static bool TestMapaVector01 ()
{
	cout << "Test MapaVector 01:" << endl;
	bool bRes = true;

	try
	{
		MapaVector<string> * mapa = new MapaVector<string>();
		if ( !mapa->isValid() || 
			 !mapa->empty() || 
			 ( mapa->size() != 0 ) )
		{
			cout << "Error caso 1: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}
		mapa->push_back( "Vladimiro", "Patin" ); 
		if ( !mapa->isValid() || 
			 mapa->empty() || 
			 ( mapa->size() != 1 ) )
		{
			cout << "Error caso 2: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}
		try
		{
			if ( ( mapa->find( "Vladimiro" ).compare( "Patin" ) != 0 ) || 
				 ( mapa->at( 0 ) != mapa->find( "Vladimiro" ) ) )
			{
				cout << "Error caso 2b: Valor recuperado incorrecto" << endl;
				bRes = false;
			}
		}
		catch( exception & ex )
		{
			cout << "Error caso 2b: " << ex.what() << endl;
			bRes = false;
		}
		try
		{
			string sValor = mapa->find( "Volodimiro" );
			cout << "Error caso 2e: Deberia haber saltado excepcion" << endl;
			bRes = false;
		}
		catch( exception & ex )
		{
		}
		catch( ... )
		{
		}
		try
		{
			string sValor = mapa->at( 2 );
			cout << "Error caso 2f: Deberia haber saltado excepcion" << endl;
			bRes = false;
		}
		catch( exception & ex )
		{
		}
		mapa->push_back( "Volodimiro", "Zelensky" ); 
		if ( !mapa->isValid() || 
			 mapa->empty() || 
			 ( mapa->size() != 2 ) ||
			 ( mapa->find( "Vladimiro" ).compare( "Patin" ) != 0 ) || 
			 ( mapa->find( "Volodimiro" ).compare( "Zelensky" ) != 0 ) || 
			 ( mapa->at( 0 ) !=  mapa->find( "Vladimiro" ) ) || 
			 ( mapa->at( 1 ) !=  mapa->find( "Volodimiro" ) ) )
		{
			cout << "Error caso 3: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}
		mapa->push_back( "clave1", "objeto1" ); 
		mapa->push_back( "clave2", "objeto2" ); 
		mapa->push_back( "clave3", "objeto3" ); 
		if ( !mapa->isValid() || 
			 mapa->empty() || 
			 ( mapa->size() != 5 ) ||
			 ( mapa->find( "Vladimiro" ).compare( "Patin" ) != 0 ) || 
			 ( mapa->find( "Volodimiro" ).compare( "Zelensky" ) != 0 ) || 
			 ( mapa->at( 0 ) != mapa->find( "Vladimiro" ) ) || 
			 ( mapa->at( 1 ) != mapa->find( "Volodimiro" ) ) )
		{
			cout << "Error caso 4: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}
		mapa->pop_back();
		mapa->erase( "Volodimiro" ); 
		if ( !mapa->isValid() || 
			 mapa->empty() || 
			 ( mapa->size() != 3 ) ||
			 ( mapa->find( "Vladimiro" ).compare( "Patin" ) != 0 ) || 
			 ( mapa->at( 0 ) != mapa->find( "Vladimiro" ) ) )
		{
			cout << "Error caso 5: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}
		try
		{
			string sValor = mapa->find( "Volodimiro" );
			cout << "Error caso 5b: Deberia haber saltado excepcion" << endl;
			bRes = false;
		}
		catch( exception & ex )
		{
		}
		mapa->clear();
		if ( !mapa->isValid() || 
			 !mapa->empty() || 
			 ( mapa->size() != 0 ) )
		{
			cout << "Error caso 6: Valida=" << ToString( mapa->isValid() ) << "; size=" << mapa->size() << endl;
			bRes = false;
		}	
		delete mapa;
	}
	catch ( exception & ex )
	{
		cout << "Se ha producido una excepcion : " << ex.what () << endl;
		bRes = false;
	}
	catch ( ... )
	{
		cout << "Excepcion indefinida" << endl;
		bRes = false;
	}
	return( bRes );
}

static bool TestMapaVector02 ()
{
	cout << "Test MapaVector 02:" << endl;
	bool bRes = true;

	try
	{
		MapaVector<string> mapa;
		if ( !mapa.isValid() || 
			 !mapa.empty() || 
			 ( mapa.size() != 0 ) )
		{
			cout << "Error caso 1: Valida=" << ToString( mapa.isValid() ) << "; size=" << mapa.size() << endl;
			bRes = false;
		}
		mapa.push_back( "Vladimiro", "Patin" ); 
		if ( !mapa.isValid() || 
			 mapa.empty() || 
			 ( mapa.size() != 1 ) )
		{
			cout << "Error caso 2: Valida=" << ToString( mapa.isValid() ) << "; size=" << mapa.size() << endl;
			bRes = false;
		}
		try
		{
			if ( ( mapa[ "Vladimiro" ].compare( "Patin" ) != 0 ) || 
				 ( mapa[ 0 ] !=  mapa[ "Vladimiro" ] ) )
			{
				cout << "Error caso 2b: Valor recuperado incorrecto" << endl;
				bRes = false;
			}
		}
		catch( exception & ex )
		{
			cout << "Error caso 2b: " << ex.what() << endl;
			bRes = false;
		}
		try
		{
			string sValor = mapa[ "Volodimiro" ];
			cout << "Error caso 2c: Deberia haber saltado excepcion" << endl;
			bRes = false;
		}
		catch( exception & ex )
		{
		}
		try
		{
			string sValor = mapa[ 2 ];
			cout << "Error caso 2d: Deberia haber saltado excepcion" << endl;
			bRes = false;
		}
		catch( exception & ex )
		{
		}
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

bool TestMapaVector ()
{
	bool bRes = true;
	cout << endl << ANSI::AMARILLO << "[Test MapaVector]" << ANSI::RESETEAR << endl;
	if ( TestMapaVector01() )
	{
		cout << ANSI::VERDE << "Resultado: OK" << ANSI::RESETEAR << endl;
	}
	else
	{
		cout  << ANSI::ROJO << "Resultado: KO" << ANSI::RESETEAR << endl;
		bRes = false;
	}
	if ( TestMapaVector02() )
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
