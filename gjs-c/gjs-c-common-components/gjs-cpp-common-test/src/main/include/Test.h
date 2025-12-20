#ifndef _ORG_GJS_C_CC_CPP_TEST_TEST_H
#define _ORG_GJS_C_CC_CPP_TEST_TEST_H

#include <string>
#include <list>
#include <initializer_list>

#include <CasoTest.h>
#include <CasoTestAislado.h>
#include <ContextoTest.h>
#include <UtilesTest.h>
#include <BancoTests.h>


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

			// TODO: Añadir lista de parametros, y gestión automatizada de la llamada al procedimiento a testear
			class Test
			{
				private:
					string 				sNombreTest = "Test";
					PROCEDIMIENTO		procInicializarTest = NULL;
					PROCEDIMIENTO		procFinalizarTest = NULL;
					PROCEDIMIENTO_1CAD	procInicializarCasoTest = NULL;
					PROCEDIMIENTO_1CAD	procFinalizarCasoTest = NULL;

					list<CasoTest *> 	listCasos;

					//Simbolos		parametros;

					string				sDirInicial;
					bool 				bResultado = false;
					int 				iEjecutados = 0;
					int 				iCorrectos = 0;
					int 				iErroneos = 0;
					int 				iFallidos = 0;

				public:
					Test ( const string & sNombre, PROCEDIMIENTO procInicializar = NULL, PROCEDIMIENTO procFinalizar = NULL, PROCEDIMIENTO_1CAD procInicializarCaso = NULL, PROCEDIMIENTO_1CAD procFinalizarCaso = NULL );
					~Test ();

				private:
					void Inicializar ();
					void Finalizar ();
					void InicializarCaso ( const string & sId );
					void FinalizarCaso ( const string & sId );

				public:
					//void EstablecerParametros ( const initializer_list<string> & args );
					//void EstablecerParametros ( const list<string> & args );
					//void EstablecerParametros ( const vector<string> & args );
					//void EstablecerParametro ( string sParametro );

					void NuevoCaso ( const string & sNombre, FUNCION_BOOL funcion );
					void NuevoCasoAislado ( const string & sNombre, FUNCION_BOOL funcion, int iCodigoEsperado = 0 );
					int NumCasos ();

					bool Ejecutar ();

					bool Resultado ();
					int CasosEjecutados ();
					int CasosCorrectos ();
					int CasosErroneos ();
					int CasosFallidos ();

			};

				}
 			}
		}
	}
}

#endif
