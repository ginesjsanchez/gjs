
#include "SEntradaDirectorio.h"
#include "SDirectorio.h"

#include "SistemaConfig.h"


/*




SEntradaDirectorio::SEntradaDirectorio ( const char * _p_cEntrada ) 
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
	p_dirInfo = NULL;
	p_cadEntrada = new SCadena ( _p_cEntrada );
}

SEntradaDirectorio::SEntradaDirectorio ( SCadena * _p_cadEntrada )
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
	p_dirInfo = NULL;
	p_cadEntrada = _p_cadEntrada->Duplicar ();
}

SEntradaDirectorio::~SEntradaDirectorio ()
{
	SCadDestruir ( &p_cadEntrada );
}

SCadena * SEntradaDirectorio::Entrada ()
{
	return ( p_cadEntrada );
}

const char * SEntradaDirectorio::Valor ()
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_cadEntrada ) )
	{
		p_cRes = p_cadEntrada->DuplicarValorConstante ();
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

SPath * SEntradaDirectorio::Ruta ()
{
	SPath *		p_pathRuta;
	char *		p_cRuta;

	if ( ES_VALIDO ( p_dirInfo ) )
	{
		p_cRuta = SisComponerRuta ( p_dirInfo->Ruta ()->Directorio ()->ValorConstante (), p_cadEntrada->ValorConstante () );
		if ( ES_VALIDO ( p_cRuta ) )
		{
			p_pathRuta = new SPath ();
			if ( ES_VALIDO ( p_pathRuta ) )
			{
				if ( SisExisteDirectorio ( p_cRuta ) == 1 )
				{
					p_pathRuta->EstablecerDirectorio ( p_cRuta );
				}
				else
				{
					p_pathRuta->EstablecerDirectorio ( p_dirInfo->Ruta ()->Directorio () );
					p_pathRuta->EstablecerFichero ( p_cadEntrada );
				}
			}
			MemLiberar ( (void **) &p_cRuta );
		}
		else
		{
			p_pathRuta = NULL;
		}
	}
	else
	{
		p_pathRuta = NULL;
	}
	return ( p_pathRuta );
}

int SEntradaDirectorio::EsSubdirectorio ()
{
	SPath *		p_pathRuta;
	int			iRes;

	p_pathRuta = Ruta ();
	if ( p_pathRuta->EsDirectorio () == 1 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	SPathDestruir ( &p_pathRuta );
	return ( iRes );
}

int SEntradaDirectorio::EsFichero ()
{
	SPath *		p_pathRuta;
	int			iRes;

	p_pathRuta = Ruta ();
	if ( p_pathRuta->EsFichero () == 1 )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	SPathDestruir ( &p_pathRuta );
	return ( iRes );
}


SFichero * SEntradaDirectorio::Fichero ()
{
	SFichero *	p_ficRes;
	SPath *		p_pathRuta;

	p_ficRes = NULL;
	p_pathRuta = Ruta ();
	if ( p_pathRuta->EsFichero () == 1 )
	{
		p_ficRes = new SFichero ( p_pathRuta ); 
	}
	SPathDestruir ( &p_pathRuta );
	return ( p_ficRes );
}

SDirectorio * SEntradaDirectorio::Subdirectorio ()
{
	SDirectorio * p_dirRes;
	SPath *		p_pathRuta;

	p_dirRes = NULL;
	p_pathRuta = Ruta ();
	if ( p_pathRuta->EsDirectorio () == 1 )
	{
		p_dirRes = new SDirectorio ( p_pathRuta->Directorio () );
	}
	SPathDestruir ( &p_pathRuta );
	return ( p_dirRes );
}

SDirectorio * SEntradaDirectorio::Directorio ()
{
	return ( p_dirInfo );
}

void SEntradaDirectorio::EstablecerDirectorio ( SDirectorio * _p_dirInfo )
{
	p_dirInfo = _p_dirInfo;
}

int SEntradaDirectorio::EsIgual ( SEntradaDirectorio * _p_edirObj )
{
	int iRes;

	if ( ES_VALIDO ( _p_edirObj ) )
	{
		if ( ES_VALIDO ( p_cadEntrada ) && ES_VALIDO ( _p_edirObj->Entrada () ) ) 
		{
			iRes = p_cadEntrada->EsIgual ( _p_edirObj->Entrada () );
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEntradaDirectorio::EsMenor ( SEntradaDirectorio * _p_edirObj )
{
	int iRes;

	if ( ES_VALIDO ( _p_edirObj ) )
	{
		if ( ES_VALIDO ( p_cadEntrada ) && ES_VALIDO ( _p_edirObj->Entrada () ) ) 
		{
			iRes = p_cadEntrada->EsMenor ( _p_edirObj->Entrada () );
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SEntradaDirectorio::EsMayor ( SEntradaDirectorio * _p_edirObj )
{
	int iRes;

	if ( ES_VALIDO ( _p_edirObj ) )
	{
		if ( ES_VALIDO ( p_cadEntrada ) && ES_VALIDO ( _p_edirObj->Entrada () ) ) 
		{
			iRes = p_cadEntrada->EsMayor ( _p_edirObj->Entrada () );
		}
		else
		{
			iRes = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

*/




