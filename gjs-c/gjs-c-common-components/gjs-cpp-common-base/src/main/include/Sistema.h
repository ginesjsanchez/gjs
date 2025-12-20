#ifndef _ORG_GJS_C_CC_CPP_SISTEMA_H
#define _ORG_GJS_C_CC_CPP_SISTEMA_H

#include <string>
#include <ctime>
#include <thread>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			typedef void (*SIGNAL_HANDLER)( int );

			string NombreSistema ();
			bool EsWindows ();
			bool EsCygwin ();
			bool EsMinGW ();
			bool EsLinux ();
			bool EsUnix ();
			bool EsMac ();

			string DirectorioActual ();
			string ResolverDirectorioRelativo ( string sRutaBase, string sRutaRelativa );
			void EstablecerDirectorio( const string & sRuta );

			bool ExisteFichero ( const string & sRuta );
			bool ExisteDirectorio ( const string & sRuta );

			string VariableEntorno ( const string & sNombre );
			void EstablecerVariableEntorno ( const string & sNombre, const string & sValor );
			void EliminarVariableEntorno ( const string & sNombre );

			void Esperar ( long lMiliseg );

			void EstablecerManejadorInterrupciones ( SIGNAL_HANDLER fManejador );
			void EstablecerManejadorInterrupcionesDefecto ();
			void LimpiarManejadorInterrupciones ();
			//void GrabarRetornoAPrograma();
			//void RetornarAPrograma ();

			time_t Ahora ();

			void InicializarBase();
			bool PuedeLiberarse ( void * ptr );

			int ResolverIP( const string & sIP );

			string EjecutarComando ( const string & sComando );

            }
		}
	}
}

#endif
