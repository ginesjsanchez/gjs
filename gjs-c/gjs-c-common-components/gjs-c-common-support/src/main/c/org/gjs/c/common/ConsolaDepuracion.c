#include "ConsolaDepuracion.h"
#include "AplicacionConsola.h"

#include "AplicacionConfig.h"







static int	g_iConsolaDepuracionDisponible = 0;
static int	g_iConsolaDepuracionAbierta = 0;




int ConDepAbrir ()
{
	int		iRes;

	if ( g_iConsolaDepuracionDisponible == 0 )
	{
		if ( AplicConEstaAbierta ()  == 0 )
		{
			iRes = AplicConAbrir ();
			if ( iRes == 1 )
			{
				g_iConsolaDepuracionDisponible = 1;
				g_iConsolaDepuracionAbierta = 1;
			}
		}
		else
		{
			g_iConsolaDepuracionDisponible = 1;
			iRes = 1;
		}
	}
	else
	{
		iRes = 1;
	}
	return ( iRes );
}

void ConDepCerrar ()
{
	if ( g_iConsolaDepuracionDisponible == 1 )
	{
		if ( g_iConsolaDepuracionAbierta == 1 )
		{
			AplicConCerrar ();
		}
		g_iConsolaDepuracionDisponible = 0;
		g_iConsolaDepuracionAbierta = 0;
	}
}

int ConDepEstaAbierta ()
{
	return ( g_iConsolaDepuracionDisponible );
}

int ConDepEscribir ( const char * p_cTexto, ... )
{
	int			iRes;
	char *		p_cValor;
	va_list		valArgumentos;

	if ( ( g_iConsolaDepuracionDisponible == 1 ) && ES_VALIDO ( p_cTexto ) )
	{
		p_cValor = CadCrear ( AplicConAncho () );
		if ( ES_VALIDO ( p_cValor ) )
		{
			va_start ( valArgumentos, p_cTexto );
			if ( FrmCadena ( p_cValor, p_cTexto, valArgumentos, AplicConAncho () ) == 1 )
			{
				iRes = 1;			
				printf ( p_cValor ); 
			}
			else
			{
				iRes = 0;
			}
			MemLiberar ( (void **) &p_cValor );
			va_end ( valArgumentos );
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

int ConDepEscribirLinea ( const char * p_cTexto, ... )
{
	int			iRes;
	char *		p_cValor;
	va_list		valArgumentos;

	if ( g_iConsolaDepuracionDisponible == 1 )
	{
		p_cValor = CadCrear ( AplicConAncho () );
		if ( ES_VALIDO ( p_cValor ) )
		{
			va_start ( valArgumentos, p_cTexto );
			if ( FrmCadena ( p_cValor, p_cTexto, valArgumentos, AplicConAncho () ) == 1 )
			{
				iRes = 1;			
				printf ( p_cValor ); 
				printf ( "\n" );
			}
			else
			{
				iRes = 0;
			}
			MemLiberar ( (void **) &p_cValor );
			va_end ( valArgumentos );
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
