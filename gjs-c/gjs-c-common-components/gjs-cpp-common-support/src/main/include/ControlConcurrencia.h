#ifndef _ORG_GJS_C_CC_CPP_CONTROL_CONCURRENCIA_H
#define _ORG_GJS_C_CC_CPP_CONTROL_CONCURRENCIA_H

#include <mutex>
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

			class ControlConcurrencia
			{
			private:
				mutex 			mtxAcceso;
				thread::id * 	idBloqueante = NULL;

			public:
				ControlConcurrencia ();
				virtual ~ControlConcurrencia ();

			protected:
				void Bloquear();
				void Desbloquear();
			};

 			}
		}
	}
}



#endif
