#ifndef _ORG_GJS_C_CC_CPP_TERMINALANSI_H
#define _ORG_GJS_C_CC_CPP_TERMINALANSI_H


#include <string>
#include <iostream>


using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {
                namespace ANSI
                {

				const string RESETEAR( "\033[0m" );
				const string NEGRITA_INI ( "\033[0;1m" );
				const string SUBRAYADO_INI ( "\033[0;4m" );
				const string INVERSO_INI ( "\033[0;7m" );
				const string NEGRITA_FIN ( "\033[0;21m" );
				const string SUBRAYADO_FIN ( "\033[0;24m" );
				const string INVERSO_FIN ( "\033[0;27m" );

				const string NEGRO ( "\033[0;30m" );
				const string ROJO ( "\033[0;31m" );
				const string VERDE ( "\033[0;32m" );
				const string AMARILLO ( "\033[0;33m" );
				const string AZUL ( "\033[0;34m" );
				const string MAGENTA ( "\033[0;35m" );
				const string CIAN ( "\033[0;36m" );
				const string BLANCO ( "\033[0;37m" );

				const string FONDO_NEGRO ( "\033[0;40m" );
				const string FONDO_ROJO ( "\033[0;41m" );
				const string FONDO_VERDE ( "\033[0;42m" );
				const string FONDO_AMARILLO ( "\033[0;43m" );
				const string FONDO_AZUL ( "\033[0;44m" );
				const string FONDO_MAGENTA ( "\033[0;45m" );
				const string FONDO_CIAN ( "\033[0;46m" );
				const string FONDO_BLANCO ( "\033[0;47m" );

                }
            }
		}
	}
}

#endif
