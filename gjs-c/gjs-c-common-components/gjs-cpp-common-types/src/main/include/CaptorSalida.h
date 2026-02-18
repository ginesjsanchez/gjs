#ifndef _ORG_GJS_C_CC_CPP_CAPTORSALIDA_H
#define _ORG_GJS_C_CC_CPP_CAPTORSALIDA_H

#include <string>
#include <sstream>
#include <vector>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class CaptorSalida
			{
			private:
				streambuf * p_bufViejo = NULL;
				stringstream ssContenido;

				bool bActivado = false;
				vector<string> vecLineas;

			public:
				CaptorSalida ();
				~CaptorSalida ();

				void Ini ();
				void Fin ();
				bool EstaActivado ();

				vector<string> getLineas ();
			};

 			}
		}
	}
}

#endif
