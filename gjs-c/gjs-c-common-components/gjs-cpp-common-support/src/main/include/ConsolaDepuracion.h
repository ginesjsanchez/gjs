

#ifndef _CONSOLADEPURACION_H
#define _CONSOLADEPURACION_H






#define	DEP_INIFUN			ConDepEscribirLinea ("<Mod: {}; Fun: {}> - INICIO", __FILE__, __FUNCTION__ )
#define	DEP_FINFUN			ConDepEscribirLinea ("<Mod: {}; Fun: {}> - FIN", __FILE__, __FUNCTION__ )



#include <string>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {



bool ConDepAbrir ();
void ConDepCerrar ();
bool ConDepEstaAbierta ();

template<typename... Args> bool ConDepEscribir ( const string & sTexto, Args&&... argumentos );
template<typename... Args> bool ConDepEscribirLinea ( const string & sTexto, Args&&... argumentos );


 			}
		}
	}
}

#endif

