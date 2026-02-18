#include "ConsolaDepuracion.h"
#include "AplicacionConsola.h"

#include "CommonSupportConfig.h"





using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {




static bool	g_bConsolaDepuracionDisponible = false;
static bool	g_bConsolaDepuracionAbierta = false;




bool ConDepAbrir ()
{
	bool bRes = false;

	if ( !g_bConsolaDepuracionDisponible )
	{
		if ( !AplicConEstaAbierta () )
		{
			bRes = AplicConAbrir ();
			g_bConsolaDepuracionDisponible = bRes;
			g_bConsolaDepuracionAbierta = bRes;
		}
		else
		{
			g_bConsolaDepuracionDisponible = true;
			bRes = true;
		}
	}
	else
	{
		bRes = true;
	}
	return ( bRes );
}

void ConDepCerrar ()
{
	if ( g_bConsolaDepuracionDisponible )
	{
		if ( g_bConsolaDepuracionAbierta )
		{
			AplicConCerrar ();
		}
		g_bConsolaDepuracionDisponible = false;
		g_bConsolaDepuracionAbierta = false;
	}
}

bool ConDepEstaAbierta ()
{
	return ( g_bConsolaDepuracionDisponible );
}

template<typename... Args> bool ConDepEscribir ( const string & sTexto, Args&&... argumentos )
{
	bool bRes = false;

	if ( g_bConsolaDepuracionDisponible )
	{
		string sValor = ToString ( sTexto, forward<Args>( argumentos )... ).substr( 0, AplicConAncho () ); 
		cout << sValor; 
		bRes = true;
	}
	return ( bRes );
}

template<typename... Args> bool ConDepEscribirLinea ( const string & sTexto, Args&&... argumentos )
{
	bool bRes = ConDepEscribir ( sTexto, forward<Args>( argumentos )... );
	if ( bRes )
	{
		cout << endl;
	}
	return ( bRes );
}



 			}
		}
	}
}
