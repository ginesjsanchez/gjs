#ifndef _ORG_GJS_C_CC_CPP_GESTOR_USUARIOS_H
#define _ORG_GJS_C_CC_CPP_GESTOR_USUARIOS_H

#include <map>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			class GestorUsuarios 
			{
			private:
				map<string, pair<string, string>>	mapUsuarios;
				
			public:
				GestorUsuarios ();
				GestorUsuarios ( const string & sRuta );
				virtual ~GestorUsuarios ();
				
			public:
				int NumUsuarios () const;
				bool Alta( const string & sUsuario, const string & sClave = "", const string & sSubdirectorio = "" );
				void Baja( const string & sUsuario );				
				bool Existe( const string & sUsuario );
				bool Validar( const string & sUsuario, const string & sClave = "" );
				string Subdirectorio( const string & sUsuario );	
				void Limpiar ();
				
				bool Cargar( const string & sRuta );
				
			};
		
 			}
		}
	}
}




#endif