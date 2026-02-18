/******************************************************************************/
/*                              TiposSistema.cpp                              */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* de relativos a los tipos de sistema operativo reconocidos.                 */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "TiposSistema.h"


#include "SistemaConfig.h"


#include <Texto.h>




const char * TipSisNombre ( int iId )
{
	if ( iId == TIP_SIS_UNIX )
	{
		return ( TIP_SIS_TXT_UNIX );
	}
	else if ( iId == TIP_SIS_LINUX )	
	{
		return ( TIP_SIS_TXT_LINUX );
	}
	else if ( iId == TIP_SIS_DOS )	
	{
		return ( TIP_SIS_TXT_DOS );
	}
	else if ( iId == TIP_SIS_WINDOWS )	
	{
		return ( TIP_SIS_TXT_WINDOWS );
	}
	else if ( iId == TIP_SIS_MACKINTOSH )
	{
		return ( TIP_SIS_TXT_MACKINTOSH );
	}
	else 
	{
		return ( NULL );
	}
}

int TipSisId ( const char * p_cNombre )
{
	int iTipo;

	if ( ES_VALIDO ( p_cNombre ) )
	{
		if ( CadCompararSinDistinguirTipoLetra ( p_cNombre, TIP_SIS_TXT_UNIX ) == 1 )
		{
			iTipo = TIP_SIS_UNIX;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cNombre, TIP_SIS_TXT_LINUX ) == 1 )	
		{
			iTipo = TIP_SIS_LINUX;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cNombre, TIP_SIS_TXT_DOS ) == 1 )	
		{
			iTipo = TIP_SIS_DOS;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cNombre, TIP_SIS_TXT_WINDOWS ) == 1 )
		{
			iTipo = TIP_SIS_WINDOWS;
		}
		else if ( CadCompararSinDistinguirTipoLetra ( p_cNombre, TIP_SIS_TXT_MACKINTOSH ) == 1 )
		{
			iTipo = TIP_SIS_MACKINTOSH;
		}
		else 
		{
			iTipo = TIP_SIS_DESCONOCIDO;
		}
	}
	else 
	{
		iTipo = TIP_SIS_DESCONOCIDO;
	}
	return ( iTipo );
}


int TipSisEsValido ( int iId )
{
	int iRes; 

	if ( ( iId == TIP_SIS_UNIX ) ||
 		 ( iId == TIP_SIS_LINUX ) || 
		 ( iId == TIP_SIS_DOS ) ||
		 ( iId == TIP_SIS_WINDOWS ) ||
		 ( iId == TIP_SIS_MACKINTOSH ) )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsDesconocido ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_DESCONOCIDO )
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsUnix ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_UNIX ) 
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsLinux ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_LINUX ) 
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsDOS ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_DOS ) 
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsWindows ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_WINDOWS ) 
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int TipSisEsMacKintosh ( int iId )
{
	int iRes;

	if ( iId == TIP_SIS_MACKINTOSH ) 
	{
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}





