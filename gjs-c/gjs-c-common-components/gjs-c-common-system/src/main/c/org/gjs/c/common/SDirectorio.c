#include "SDirectorio.h"




#include "SDirectorio.h"
#include "SEntradaDirectorio.h"










/*

SDirectorio::SDirectorio () : SListaPtr (), SPath ()
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
}

SDirectorio::SDirectorio ( const char * _p_cDirectorio ) : SListaPtr (), SPath ( _p_cDirectorio )
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
	CargarEntradas ();
}

SDirectorio::SDirectorio ( SCadena * _p_cadDirectorio ) : SListaPtr (), SPath ( _p_cadDirectorio )
{
	CClase::ActualizarObjeto ( _NOMBRE_SLASE, (void *) this, _TAM_SLASE );
	CargarEntradas ();
}

SDirectorio::~SDirectorio ()
{
	VaciarLista ();
}

SPath * SDirectorio::Ruta ()
{
	SPath * p_pathRuta;

	p_pathRuta = (SPath *) this; 
	return ( p_pathRuta );
}

SCadena * SDirectorio::Valor ()
{
	SCadena * p_cadRuta;

	p_cadRuta = ((SPath *) this)->Directorio (); 
	return ( p_cadRuta );
}

void SDirectorio::Cambiar ( const char * _p_cDirectorio ) 
{
	SPath::EstablecerDirectorio ( _p_cDirectorio );
	CargarEntradas ();
}

void SDirectorio::Cambiar ( SCadena * _p_cadDirectorio )
{
	SPath::EstablecerDirectorio ( _p_cadDirectorio );
	CargarEntradas ();
}

void SDirectorio::Refrescar ()
{
	CargarEntradas ();
}

int SDirectorio::NumEntradas ()
{
	return ( SListaPtr::NumElementos () );
}

SEntradaDirectorio * SDirectorio::Entrada ( int _iEntrada )
{
	SEntradaDirectorio * p_edirInfo;

	if ( ( _iEntrada >= 0 ) && ( _iEntrada < SListaPtr::NumElementos () ) )
	{
		p_edirInfo = ((_SLisEntDirElem *) SListaPtr::Elemento ( _iEntrada ))->Entrada ();
		if ( p_edirInfo->Directorio () != this )
		{
			p_edirInfo->EstablecerDirectorio ( this );
		}
	}
	else
	{
		p_edirInfo = NULL;
	}
	return ( p_edirInfo );
}


// PENDIENTE: Probar int fnmatch(const char *_pattern, const char *_string, int _flags);
// con int  glob(const char *_pattern, int _flags, int (*_errfunc)(const char *_epath, int _eerrno), glob_t *_pglob);
// para GNU de forma que retorne ordenos alfabéticamente los ficheros: 
// PENDIENTE2: FindFirstFile no garantiza que estén en orden alfabético, pues depende del
// sistema operativo concreto.
int SDirectorio::CargarEntradas ()
{
	_SLisEntDirElem *		p_edirelemDatos;
	SEntradaDirectorio *	p_edirDatos;
	SCadena *				p_cadBusqueda;
	int						iRes;
	//int i = 0;
	
# if ( defined ( WIN ) )
	WIN32_FIND_DATA			fndfildatObj;
	HANDLE					hBusqueda;
	int						iResBusq;

	VaciarLista ();
    if ( SPath::Existe () == 1 )
    {
		p_cadBusqueda = SPath::MascaraBusquedaEnDirectorio ();
		if ( ES_VALIDO ( p_cadBusqueda ) )
		{
			hBusqueda = FindFirstFile ( p_cadBusqueda->ValorConstante (), &fndfildatObj );
			if ( hBusqueda != INVALID_HANDLE_VALUE ) 
			{
				iRes = 1;
				iResBusq = 1;
				while ( ( iResBusq != 0 ) && ( iRes == 1 ) )
				{
					if ( fndfildatObj.cFileName [ 0 ] != '.' )
					{
						p_edirDatos = new SEntradaDirectorio ( fndfildatObj.cFileName );
						if ( ES_VALIDO ( p_edirDatos ) )
						{
							p_edirDatos->EstablecerDirectorio ( this );
							p_edirelemDatos = new _SLisEntDirElem ( p_edirDatos );
							if ( ES_VALIDO ( p_edirelemDatos ) )
							{
								SListaPtr::InsertarAlFinal ( p_edirelemDatos );
							}
							else
							{
								SEntDirDestruir ( &p_edirDatos );
								iRes = 0;
							}
						}
						else
						{
							iRes = 0;
						}
					}
					iResBusq = FindNextFile ( hBusqueda, &fndfildatObj );
				}
				if ( ( iResBusq == 0 ) && ( GetLastError () !=  ERROR_NO_MORE_FILES ) )
				{
					// ERROR:
					iRes = 0;
				}
				FindClose ( hBusqueda );
			}
			SCadDestruir ( &p_cadBusqueda );
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

# else
   DIR *					p_dirInfo;
   int						iEntrada;
	SEntradaDirectorio *	p_edirObj;
	_SLisEntDirElem *		p_edirelemObj;
	int						iEnc;
	int						iError;

#  if ( defined ( UNIX ) )
    struct dirent *			p_directInfo;
#  else
    struct direct *			p_directInfo;
#  endif

	//SListaPtr::Vaciar ();
	VaciarLista ();
    if ( SPath::Existe () == 1 )
    {
		p_cadBusqueda = SPath::Directorio ();
		if ( ES_VALIDO ( p_cadBusqueda ) )
		{
			p_dirInfo = opendir ( p_cadBusqueda->ValorConstante () );
			if ( ES_VALIDO ( p_dirInfo ) )
			{
				iRes = 1;
				p_directInfo = readdir ( p_dirInfo );
				while ( ES_VALIDO ( p_directInfo ) && ( iRes == 1 ) )
				{
					if ( *p_directInfo->d_name != '.' )
					{
						p_edirDatos = new SEntradaDirectorio ( p_directInfo->d_name );
						if ( ES_VALIDO ( p_edirDatos ) )
						{
							p_edirDatos->EstablecerDirectorio ( this );
							p_edirelemDatos = new _SLisEntDirElem ( p_edirDatos );
							if ( ES_VALIDO ( p_edirDatos ) )
							{
								//SListaPtr::InsertarAlFinal ( p_edirelemDatos );
								if ( SListaPtr::NumElementos () == 0 )
								{
									iRes = SListaPtr::InsertarAlInicio ( p_edirelemDatos );
								}
								else
								{
									iError = 0;
									iEnc = 0;
									iEntrada = 0;
									while ( ( iEnc == 0 ) && ( iEntrada < SListaPtr::NumElementos () ) && ( iError == 0 ) )
									{
										p_edirelemObj = (_SLisEntDirElem *) SListaPtr::Elemento ( iEntrada );
										if ( ES_VALIDO ( p_edirelemObj ) )
										{
											p_edirObj = p_edirelemObj->Entrada ();
											if ( ES_VALIDO ( p_edirObj ) )
											{
												if ( p_edirDatos->EsMayor ( p_edirObj ) == 1 )
												{
													iEntrada = iEntrada + 1;
												}
												else
												{
													iEnc = 1;
												}
											}
											else
											{
												iError = 1;
											}
										}
										else
										{
											iError = 1;
										}
									}

									if ( iEnc == 0 )
									{
										iRes = SListaPtr::InsertarAlFinal ( p_edirelemDatos );
									}
									else
									{
										if ( iEntrada == 0 )
										{
											iRes = SListaPtr::InsertarAlInicio ( p_edirelemDatos );
										}
										else
										{
											iRes = SListaPtr::Insertar ( iEntrada - 1, p_edirelemDatos );
										}
									}
								}
							}
							else
							{
								// ERROR MEMORIA:
								iRes = 0;
							}
						}
						else
						{
							// ERROR MEMORIA:
							iRes = 0;
						}
					}
					p_directInfo = readdir ( p_dirInfo );
				}
				closedir ( p_dirInfo );
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
    }
	else
	{
		iRes = 0;
	}
# endif

	return ( iRes );
}


int SDirectorio::CrearSubdirectorio ( const char * _p_cSubdirectorio )
{
	_SLisEntDirElem *		p_edirelemDatos;
	SEntradaDirectorio *	p_edirDatos;
	int						iRes;

	if ( ES_VALIDO ( _p_cSubdirectorio ) )
	{
		if ( SisCrearDirectorioExt ( SPath::Directorio ()->ValorConstante (), _p_cSubdirectorio ) == 1 )
		{
			p_edirDatos = new SEntradaDirectorio ( _p_cSubdirectorio );
			if ( ES_VALIDO ( p_edirDatos ) )
			{
				p_edirDatos->EstablecerDirectorio ( this );
				p_edirelemDatos = new _SLisEntDirElem ( p_edirDatos );
				if ( ES_VALIDO ( p_edirDatos ) )
				{
					SListaPtr::InsertarAlFinal ( p_edirelemDatos );
					iRes = SListaPtr::NumElementos () - 1;
				}
				else
				{
					// ERROR MEMORIA:
					iRes = -1;
				}
			}
			else
			{
				// ERROR MEMORIA:
				iRes = -1;
			}
		}
		else
		{
			iRes = -1;
		}
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

void SDirectorio::LiberarEntradas ()
{
	VaciarLista ();
}

int SDirectorio::CrearSubdirectorio ( SCadena * _p_cadSubdirectorio )
{
	return ( CrearSubdirectorio ( _p_cadSubdirectorio->ValorConstante () ) );
}

void SDirectorio::VaciarLista ()
{
	int					iError;
	_SLisEntDirElem *	p_edirelemDatos;

	iError = 0;
	while ( ( SListaPtr::NumElementos () > 0 ) && ( iError == 0 ) )
	{
		p_edirelemDatos = (_SLisEntDirElem *) SListaPtr::Eliminar ( 0 );
		if ( ES_VALIDO ( p_edirelemDatos ) )
		{
			DESTRUIR ( _SLisEntDirElem, p_edirelemDatos );
		}
		else
		{
			iError = 1;
		}
	}
	SListaPtr::Inicio ();
}

*/




