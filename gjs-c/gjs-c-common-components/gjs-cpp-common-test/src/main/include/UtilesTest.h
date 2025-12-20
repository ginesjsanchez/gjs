#ifndef _ORG_GJS_C_CC_CPP_TEST_UTILESTEST_H
#define _ORG_GJS_C_CC_CPP_TEST_UTILESTEST_H


#include <string>
#include <vector>

#include <IComparable.h>



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

			void VerificarValor ( const string & sInfoCaso, const string & sResultado, const string & sEsperado, bool & bRes );
			void VerificarValor ( const string & sInfoCaso, const string & sResultado, const char * p_cEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, const char * p_cResultado, const char * p_cEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, long lResultado, long lEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, long lResultado, int iEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, int iResultado, int iEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, bool bResultado, bool bEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, double dResultado, double dEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, float fResultado, float fEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, const wstring & sResultado, const wstring & sEsperado, bool & bRes );
			void VerificarValor ( const string & sInfoCaso, const wstring & sResultado, const wchar_t * p_cEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, const wchar_t * p_cResultado, const wchar_t * p_cEsperado, bool & bRes );		

			void VerificarValor ( const string & sInfoCaso, IComparable & objResultado, IComparable & objEsperado, bool & bRes );			
			void VerificarValor ( const string & sInfoCaso, IComparable * objResultado, IComparable * objEsperado, bool & bRes );			
			
			void VerificarEsCierto ( const string & sInfoCaso, bool bResultado, bool & bRes );
			void VerificarEsFalso ( const string & sInfoCaso, bool bResultado, bool & bRes );
			void VerificarEsNulo ( const string & sInfoCaso, void * p_vResultado, bool & bRes );
			void VerificarNoEsNulo ( const string & sInfoCaso, void * p_vResultado, bool & bRes );

			void VerificarExistenciaFichero ( const string & sRuta, bool & bRes );
			void VerificarFichero ( const string & sRuta, int iLineasEsperadas, bool & bRes );
			void VerificarFichero ( const string & sRuta, vector<string> & vecLineas, bool & bRes );
			void VerificarFichero ( const string & sRuta, const char * p_cEsperado, bool & bRes );
			void VerificarFichero ( const string & sRuta, const string & sRutaEsperado, bool & bRes );

				}
 			}
		}
	}
}

#endif