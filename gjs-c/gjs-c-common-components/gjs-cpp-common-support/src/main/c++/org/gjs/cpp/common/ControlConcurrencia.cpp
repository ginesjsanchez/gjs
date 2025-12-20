
#include "ControlConcurrencia.h"
#include <Cadenas.h>
#include <ToString.h>
#include <Concatenar.h>



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

ControlConcurrencia::ControlConcurrencia ()
{
}

ControlConcurrencia::~ControlConcurrencia ()
{
}

void ControlConcurrencia::Bloquear()
{
	if ( ( idBloqueante == NULL ) || ( *idBloqueante != this_thread::get_id() ) )
	{
		mtxAcceso.lock();
		idBloqueante = new thread::id();
		*idBloqueante = this_thread::get_id();
	}
}

void ControlConcurrencia::Desbloquear()
{
	if ( ( idBloqueante != NULL ) && ( *idBloqueante == this_thread::get_id() ) )
	{
		delete idBloqueante;
		idBloqueante = NULL;
		mtxAcceso.unlock();
	}
}

 			}
		}
	}
}
