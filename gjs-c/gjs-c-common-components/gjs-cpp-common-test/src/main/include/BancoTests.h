#ifndef _ORG_GJS_C_CC_CPP_TEST_BANCOTEST_H
#define _ORG_GJS_C_CC_CPP_TEST_BANCOTEST_H



#include <Prototipos.h>
#include <MapaVector.h>
#include <string>





using namespace std;
using namespace org::gjs::cpp::common;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {
				namespace test
				{

			class BancoTests
			{
				private:
					MapaVector<FUNCION_BOOL> mapTests;

				public:
					BancoTests ();
					~BancoTests ();

				public:

					void NuevoTest ( const string & sNombre, FUNCION_BOOL funcion );
					int NumTests ();

					int Ejecutar ( const string & sTest = "" );
					int Ejecutar ( int argc, char * argv[] );

			};

				}
 			}
		}
	}
}

#endif
