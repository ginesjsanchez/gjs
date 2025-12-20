#ifndef _ORG_GJS_C_CC_CPP_TEST_CASOTEST_H
#define _ORG_GJS_C_CC_CPP_TEST_CASOTEST_H

#include <ResultadoCasoTest.h>
#include <CppBase.h>

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

			class CasoTest
			{
				private:
					string sIdCaso = "Caso";
					FUNCION_BOOL funcionCaso = NULL;
					bool bEsperaExcepcion = false;
					
				public:
					CasoTest ( const string & sId, FUNCION_BOOL funcion, bool bEsperaExcep = false );
					virtual ~CasoTest () {};
					
				public:
					string getId();
					virtual ResultadoCasoTest Ejecutar (); 
			};

 				}
			}
		}
	}
}

#endif