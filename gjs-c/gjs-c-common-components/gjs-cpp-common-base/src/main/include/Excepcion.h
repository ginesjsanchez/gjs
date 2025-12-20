#ifndef _ORG_GJS_C_CC_CPP_EXCEPCION_H
#define _ORG_GJS_C_CC_CPP_EXCEPCION_H

#include <string>
#include <stdexcept>


using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			class Excepcion : public runtime_error
			{
			private:
				string sModulo;
				string sRutina;
				string sMensaje;

			public:
				Excepcion ( const string & _sModulo, const string & _sRutina, const string & _sMensaje );
				Excepcion ( const string & _sModulo, const string & _sRutina, const string & _sMensaje, const exception & ex );
				Excepcion ( const string & _sModulo, const string & _sRutina, const exception & ex );

				string getModulo () const;
				string getRutina () const;
				string getMensaje () const;

				const char * what () const noexcept;
				string whatExt () const;

				exception & toException();

			};

            }
		}
	}
}

#endif
