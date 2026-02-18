#ifndef _ORG_GJS_C_CC_CPP_LOG_LOG_H
#define _ORG_GJS_C_CC_CPP_LOG_LOG_H

#include <MDC.h>


#include <string>
#include <map>



#define LOG_PROP_FICHERO				"logFilename"
#define LOG_PROP_DIRECTORIO				"logDirectory"

#define LOG_VAR_DIRECTORIO				"LOG_DIR"




using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {
                namespace log
                {
					
            enum Nivel
            {
                TODOS = 0,
                TRAZA = 1,
                DEPUR = 2,
                INFO = 3,
                AVISO = 4,
                ERROR = 5,
                FATAL = 6,
                NINGUNO = 7
            };


            map<string, string> LogPropiedadesDefecto ( string sNombreFichero = "", string sDirectorio = "" );

            bool LogIni ();
            bool LogIni ( const string & sRutaFicheroCfg );

            // TODO: Por un bug en log4cxx no funciona la substitucion de propiedades y no se pueden usar xml de configuración customizados
            bool LogIni ( map<string, string> & mapPropiedades );
            bool LogIni ( const string & sRutaFicheroCfg, map<string, string> & mapPropiedades );

			bool LogActivado ();
			void LogActivar ();
            void LogDesactivar ();


            bool LogIniConsola ( bool bSoloMensaje = false );
			bool LogHaySalidaPorConsola ();
			bool LogSalidaPorConsolaActivada ();
			void LogActivarConsola ();
            void LogDesactivarConsola ();
			
            bool LogIniFichero ( const string & sFicLog, bool consola = false );

            void LogFin ();

            void LogInfo ( const string & sMensaje );
            void LogDepuracion ( const string & sMensaje );
            void LogTraza ( const string & sMensaje );
            void LogAviso ( const string & sMensaje );
            void LogError ( const string & sMensaje );
            void LogFatal ( const string & sMensaje );
            void LogErrorEx ( const string & sMensaje, const exception & exInfo );
            void LogFatalEx ( const string & sMensaje, const exception & exInfo );
            void LogError ( const exception & exInfo );
            void LogFatal ( const exception & exInfo );

            template<typename... Args> void LogInfo ( const string & sFormato, Args&&... argumentos );
            template<typename... Args> void LogDepuracion ( const string & sFormato, Args&&... argumentos );
            template<typename... Args> void LogTraza ( const string & sFormato, Args&&... argumentos );
            template<typename... Args> void LogAviso ( const string & sFormato, Args&&... argumentos );
            template<typename... Args> void LogError ( const string & sFormato, Args&&... argumentos );
            template<typename... Args> void LogFatal ( const string & sFormato, Args&&... argumentos );

            Nivel LogGetNivel ();
            void LogSetNivel ( Nivel nivel );
            void LogSetNivel ( int iNivel );

			Nivel ToNivel ( int iNivel );
			int ToInt ( Nivel nivel );
            /*
                TODO:
                    Colores en caso consola
                    Reconfiguracion forzada
                    Test reconfiguración periodica y forzada
             */
                }
            }
        }
    }
}

#endif
