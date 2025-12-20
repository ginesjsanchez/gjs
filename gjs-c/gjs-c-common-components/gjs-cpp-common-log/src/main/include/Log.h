#ifndef _ORG_GJS_C_CC_CPP__LOG_LOG_H
#define _ORG_GJS_C_CC_CPP__LOG_LOG_H

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

            bool LogIniConsola ( bool bSoloMensaje = false );
            bool LogIniFichero ( const string & sFicLog, bool consola = false );

            void LogFin ();

            void LogInfo ( const string & sMensaje );
            void LogDepuracion ( const string & sMensaje );
            void LogTraza ( const string & sMensaje );
            void LogAviso ( const string & sMensaje );
            void LogError ( const string & sMensaje );
            void LogFatal ( const string & sMensaje );
            void LogError ( const string & sMensaje, const exception & exInfo );
            void LogFatal ( const string & sMensaje, const exception & exInfo );
            void LogError ( const exception & exInfo );
            void LogFatal ( const exception & exInfo );

            Nivel LogGetNivel ();
            void LogSetNivel ( Nivel nivel );


            /*
                TODO:
                    Colores en caso consola
                    Reconfiguracion forzada
                    Test reconfiguración periodica y forzada
                    Caso formateo de cadenas + multiple argumentos
            */
            /*
            template<typename... Types> void LogInfo ( Types... args );
            template<typename... Types> void LogDepuracion ( Types... args );
            template<typename... Types> void LogTraza ( Types... args );
            template<typename... Types> void LogAviso ( Types... args );
            template<typename... Types> void LogError ( Types... args );
            template<typename... Types> void LogFatal ( Types... args );
            */
                }
            }
        }
    }
}

#endif
