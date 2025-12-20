#include "CommonIoConfig.h"

#include "GestorSesiones.h"


using namespace org::gjs::cpp::common;
using namespace std;



namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

GestorSesiones::GestorSesiones () : ControlConcurrencia()
{
}

GestorSesiones::~GestorSesiones ()
{
	Limpiar();
}

int GestorSesiones::NumSesiones ()
{
	Bloquear();
	int iRes = mapSesiones.size();
	Desbloquear();
	return ( iRes );
}

bool GestorSesiones::Preparar( const string & sUsuario )
{
	bool bRes = false;
	if ( EsToken( sUsuario ) )
	{
		Bloquear();
		mapHilos[ this_thread::get_id() ] = sUsuario; 
		Desbloquear();
		bRes = true;
	}
	return( bRes );
}

bool GestorSesiones::Abrir( const string & sUsuario )
{
	bool bRes = false;
	if ( EsToken( sUsuario ) )
	{
		if ( !EstaAbierta( sUsuario ) )
		{
			Bloquear();
			time_t ahora = time( 0 );
			mapSesiones[ sUsuario ] = pair<time_t, time_t>( ahora, ahora );
			mapHilos[ this_thread::get_id() ] = sUsuario; 
			Desbloquear();
			bRes = true;
		}
	}
	return( bRes );
}

void GestorSesiones::Cerrar( const string & sUsuario )		
{
	Bloquear();
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	if ( it != mapSesiones.end() )
	{
		mapSesiones.erase( it );
	}
	map<thread::id, string>::iterator itHilo = mapHilos.find( this_thread::get_id() );
	if ( itHilo != mapHilos.end() )
	{
		mapHilos.erase( itHilo );
	}
	Desbloquear();
}

void GestorSesiones::Cerrar()		
{
	Cerrar( getUsuario() );
}

void GestorSesiones::Actividad( const string & sUsuario )		
{
	Bloquear();
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	if ( it != mapSesiones.end() )
	{
		time_t ahora = time( 0 );
		it->second.second = ahora;
	}
	Desbloquear();
}

void GestorSesiones::Actividad()		
{
	Cerrar( getUsuario() );
}

bool GestorSesiones::EstaAbierta ( const string & sUsuario )
{
	Bloquear();
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	bool bRes = ( it != mapSesiones.end() );
	Desbloquear();
	return( bRes );
}

bool GestorSesiones::EstaAbierta ()
{
	return( EstaAbierta( getUsuario() ) );
}


time_t GestorSesiones::TiempoInicio( const string & sUsuario )
{
	Bloquear();
	time_t tiempo = 0;
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	if ( it != mapSesiones.end() )
	{
		tiempo = it->second.first;
	}
	Desbloquear();
	return( tiempo );
}

time_t GestorSesiones::TiempoTranscurrido( const string & sUsuario )
{
	Bloquear();
	time_t tiempo = 0;
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	if ( it != mapSesiones.end() )
	{
		time_t ahora = time( 0 );
		tiempo = ahora - it->second.first;
	}
	Desbloquear();
	return( tiempo );
}

time_t GestorSesiones::TiempoActividad( const string & sUsuario )
{
	Bloquear();
	time_t tiempo = 0;
	map<string, pair<time_t, time_t>>::iterator it = mapSesiones.find( sUsuario );
	if ( it != mapSesiones.end() )
	{
		tiempo = it->second.second;
	}
	Desbloquear();
	return( tiempo );
}

time_t GestorSesiones::TiempoInicio()
{
	return( TiempoInicio( getUsuario() ) );
}

time_t GestorSesiones::TiempoTranscurrido()
{
	return( TiempoTranscurrido( getUsuario() ) );
}

time_t GestorSesiones::TiempoActividad()
{
	return( TiempoActividad( getUsuario() ) );
}


string GestorSesiones::getUsuario( thread::id idHilo )
{	
	string sRes( "" );
	Bloquear();
	map<thread::id, string>::iterator itHilo = mapHilos.find( idHilo );
	if ( itHilo != mapHilos.end() )
	{
		sRes = itHilo->second;
	}
	Desbloquear();
	return( sRes );
}

string GestorSesiones::getUsuario()
{
	return( getUsuario( this_thread::get_id() ) );
}

void GestorSesiones::setUsuario( string sValor, thread::id idHilo )
{	
	if ( EsToken( sValor ) )
	{
		if ( !EstaAbierta( sValor ) )
		{
			Bloquear();
			mapHilos[ idHilo ] = sValor; 
			Desbloquear();
		}
	}
}

void GestorSesiones::setUsuario( string sValor )
{
	setUsuario( sValor, this_thread::get_id() );
}

void GestorSesiones::Limpiar ()
{
	Bloquear();
	mapSesiones.clear();
	mapHilos.clear();
	Desbloquear();
}

 			}
		}
	}
}
