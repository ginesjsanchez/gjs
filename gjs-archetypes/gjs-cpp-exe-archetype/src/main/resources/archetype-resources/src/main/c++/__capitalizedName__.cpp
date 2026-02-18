#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $includeConfig = "${capitalizedName}Config.h")

${symbol_pound}include "${includeConfig}"




using namespace std;
using namespace org::gjs::cpp::common;


int main ( int iNumArgs, char * p_p_cArgs [] )
{
	int					iRes;
	CArgumentos	*		p_argParametros;
    string				sDirectorio;

	EntInicializar ();

	p_argParametros = new CArgumentos ( iNumArgs, p_p_cArgs );
	if ( ES_VALIDO ( p_argParametros ) )
	{
		if ( p_argParametros->NumArgumentos () == 1 )
		{
			sDirectorio = string ( p_argParametros->DuplicarArgumento ( 0 ) );
			if ( !sDirectorio.empty() )
			{
				iRes = 1;
				if ( SisExisteDirectorio ( sDirectorio ) == 0 )
				{
					cout << format( "No existe el directorio pasado como argumento ({})." << sDirectorio << endl; 
					iRes = 0;
				}
			}
			else
			{
				cout << "Error de memoria al procesar los argumentos del programa." << endl;
				iRes = 0;
			}
		}
		else
		{
			cout << "Numero de argumentos erroneo." << endl;
			cout << "Uso: AcumuladorSignos <Dirtectorio> << endl;
			iRes = 0;
		}

		DESTRUIR ( CArgumentos, p_argParametros );
	}
	else
	{
		cout << "Se han producido un error al procesar los parametros." << endl;
		iRes = 0;
	}

	if ( iRes == 1 )
	{
		iRes = ProcesarDirectorio ( p_cDirectorio );
	}
	return ( iRes );
}

static int ProcesarDirectorio ( const string & sDirectorio )


