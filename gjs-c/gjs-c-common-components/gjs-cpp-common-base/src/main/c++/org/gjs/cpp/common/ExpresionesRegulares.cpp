#include "BaseConfig.h"
#include "ExpresionesRegulares.h"



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

bool CumpleExpresionRegular( const string& cadena, const string& patron ) {
	bool bRes = false;
	try {
		// Convertir patrón estilo DOS/shell a regex estándar
		string patronRegex = patron;
		
		// Reemplazar '?' por '.' (un carácter cualquiera)
		size_t pos = 0;
		while ((pos = patronRegex.find('?', pos)) != string::npos) {
			patronRegex.replace(pos, 1, ".");
			pos++;
		}
		
		// Reemplazar '*' por '.*' (cualquier número de caracteres)
		pos = 0;
		while ((pos = patronRegex.find('*', pos)) != string::npos) {
			if (pos == 0 || patronRegex[pos-1] != '.') {
				patronRegex.replace(pos, 1, ".*");
				pos += 2;
			} else {
				pos++;
			}
		}
		
		regex re( patronRegex );
		bRes = regex_match( cadena, re );
	}
	catch (...) {
	}
	return ( bRes );
}
	


            }
		}
	}
}
