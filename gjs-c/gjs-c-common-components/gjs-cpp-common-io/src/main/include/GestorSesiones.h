#ifndef _ORG_GJS_C_CC_CPP_GESTOR_SESIONES_H
#define _ORG_GJS_C_CC_CPP_GESTOR_SESIONES_H

#include <map>
#include <thread>
#include <ControlConcurrencia.h>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			// TODO: Añadir demonio limpiador de sesiones antiguas
			class GestorSesiones : private ControlConcurrencia
			{
			private:
				map<string, pair<time_t, time_t>>	mapSesiones;
				map<thread::id, string> 			mapHilos;
				
			public:
				GestorSesiones ();
				virtual ~GestorSesiones ();
				
			public:
				int NumSesiones ();
				bool Preparar( const string & sUsuario );
				bool Abrir( const string & sUsuario );
				void Cerrar( const string & sUsuario );				
				void Actividad( const string & sUsuario );	
				void Cerrar();				
				void Actividad();	
				
				bool EstaAbierta( const string & sUsuario );
				bool EstaAbierta();
				time_t TiempoInicio( const string & sUsuario );
				time_t TiempoTranscurrido( const string & sUsuario );
				time_t TiempoActividad( const string & sUsuario );
				time_t TiempoInicio();
				time_t TiempoTranscurrido();
				time_t TiempoActividad();

				string getUsuario( thread::id idHilo );
				string getUsuario();
				void setUsuario( string sValor, thread::id idHilo );
				void setUsuario( string sValor );

				void Limpiar ();
				
			};
		
 			}
		}
	}
}




#endif