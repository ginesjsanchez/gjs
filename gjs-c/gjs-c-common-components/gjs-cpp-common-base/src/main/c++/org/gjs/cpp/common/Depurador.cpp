#include "Depurador.h"



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {






#if ( defined ( MODO_DEPURACION_2 ) )

#include <map>

	static int _g_iGesClsIniciado = 0;

	static map<string, int> _g_mapInstancias;

	void _GesClsInicializar ();
	int _GesClsBuscar ( const string & sNombre );
	void _GesClsAltaInstancia ( const string & sNombre );
	void _GesClsBajaInstancia ( const string & sNombre );

#endif






#if ( defined ( MODO_DEPURACION ) )

extern void _MemObjetoCreado ( unsigned long ulTam, unsigned int uiObjetos );
extern void _MemObjetoDestruido ( unsigned long ulTam, unsigned int uiObjetos );

#endif





Depurador::Depurador () : Objeto ()
{
#  if ( defined ( MODO_DEPURACION ) )
	int iCar;

	p_vDirObjeto = (void *) this;
	iTamObjeto = _TAM_CLASE;
	iObjetos = 0;
	iEliminando = 0;
	iError = 0;
	_MemObjetoCreado ( (unsigned long) iTamObjeto, iObjetos );
	ActualizarObjeto ( ::Objeto::getTipo (), (void *) this, (int) ::Objeto::getTam (); )
#  endif
}


Depurador::~Depurador ()
{
#if ( defined ( MODO_DEPURACION ) )
	if ( iEliminando == 0 )
	{
		iEliminando = 1;
		_MemObjetoDestruido ( (unsigned long) iTamObjeto, iObjetos );
#	  if ( defined ( MODO_DEPURACION_2 ) )
		if ( iObjetos == 1 )
		{
			cout << "{Eliminando objeto de clase %s (Tamaño: %d)}\n", 
					 p_cNombre, iTamObjeto );
		}
		else
		{
			cout << "{Eliminando objeto de clase %s compuesto por %d objetos simples (Tamaño: %d)}\n", 
						p_cNombre, iObjetos, iTamObjeto );
		}
		cout << "\t[Objetos totales: %lu, Memoria ocupada: %lu]\n", 
				 MemNumObjetosActuales (), MemReservadaObjetos ();

		_GesClsBajaInstancia ( p_cNombre );
#	  endif
	}
#endif
}

#if ( defined ( MODO_DEPURACION ) )

int Depurador::EsTipo ( const string & sNombre )
{
	int iRes;

	if ( Objeto::getTipo().compare ( sNombre ) == 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int Depurador::EsTipo ( const char * p_cNombre )
{
	int iRes;

	if ( strcmp ( Objeto::getTipo().c_str(), p_cNombre ) == 0 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int Depurador::NumObjetos ()
{
	return ( iObjetos );
}

void * Depurador::DireccionObjeto ()
{
	return ( p_vDirObjeto );
}

int Depurador::Error ()
{
	return ( iError );
}

void Depurador::EstablecerError ( int iError )
{
	iError = iError;
}

void Depurador::LimpiarError ()
{
	iError = 0;
}

void Depurador::ActualizarObjeto ( const string & sNombre, void * p_vDirObj, int iTamObj )
{
	int iCar;
	int iTam;
	if ( ES_VALIDO ( p_vDirObj ) && ( iTamObj > 0 ) )
	{
		iObjetos = iObjetos + 1;
		iTamObjeto = iTamObjeto + iTamObj;

		p_vDirObjeto = p_vDirObj;

#	  if ( defined ( MODO_DEPURACION ) )
		_MemObjetoCreado ( (unsigned long) iTamObj, iObjetos );

		cout << "{Creando objeto de clase " << sNombre << " (Tamaño: " << iTamObjeto << ")}" << endl; 
		if ( iObjetos == 1 ) 
		{
#		  if ( defined ( MODO_DEPURACION_2 ) )
			_GesClsAltaInstancia ( sNombre );
#		  endif
		}
		else
		{
#		  if ( defined ( MODO_DEPURACION_2 ) )
			_GesClsBajaInstancia ( sNombre );
			_GesClsAltaInstancia ( sNombre );
#		  endif
		}
#	  if ( defined ( MODO_DEPURACION_2 ) )
		cout << "\t[Objetos totales: "  << MemNumObjetosActuales () << " Memoria ocupada: " 
			<<  MemReservadaObjetos () << "]" << endl; 
#	  endif
	}
#endif
}	


#endif


void GesClsImprimirEstado ()
{
#	if ( defined ( MODO_DEPURACION_2 ) )
		int iClase;
		int iTab;

		if ( _g_iGesClsIniciado == 1 )
		{
			cout << endl << " * Lista de clases utilizadas: " << endl;
			cout << " " << string(70, '-') << endl;
			for ( const pair<const int, string>& par : _g_mapInstancias )
			{
				cout << " Clase: "  <<  left << setw(50) << par.first;
				cout << "Instancias: "  <<  pair.second() << endl;
			}
			cout << endl << "Total clases: "  << endl << _g_mapInstancias.size(); 	
			cout << " " << string(70, '-') << endl << endl;
		}
		else
		{
			cout << "Gestor de clases no inicializado" << endl;
		}

		char c = getchar ();
#	endif
}




 			}
		}
	}
}




