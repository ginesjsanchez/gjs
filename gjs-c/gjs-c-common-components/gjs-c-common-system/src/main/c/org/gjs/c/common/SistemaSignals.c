/******************************************************************************/
/*                             SistemaSignals.cpp                             */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de código fuente que contiene la implementación de las rutinas     */
/* de carácter general para la gestión y el manejo de "signals".              */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#include "SistemaSignals.h"


#include "SistemaConfig.h"
#include "SistemaProcesos.h"






int SisSigEstanPermitidos ()
{
#	if ( defined ( SIGNALS_PERMITIDOS ) )
		return ( 1 );
#	else
		return ( 0 );
#endif
}

int SisSigCodigo ( int iSignal )
{
	int iRes;

	if ( SisSigEstanPermitidos () == 1 )
	{
		if ( iSignal == SIS_SIG_ABORTAR )
		{
			iRes = SIS_COD_SIG_ABORTAR;
		}
		else if ( iSignal == SIS_SIG_ALARMA )
		{
			iRes = SIS_COD_SIG_ALARMA;
		}
		else if ( iSignal == SIS_SIG_ERROR_COMA_FLOTANTE )
		{
			iRes = SIS_COD_SIG_ERROR_COMA_FLOTANTE;
		}
		else if ( iSignal == SIS_SIG_TERMINAL_DESCONECTADO )
		{
			iRes = SIS_COD_SIG_TERMINAL_DESCONECTADO;
		}
		else if ( iSignal == SIS_SIG_INSTRUCCION_ILEGAL )
		{
			iRes = SIS_COD_SIG_INSTRUCCION_ILEGAL;
		}
		else if ( iSignal == SIS_SIG_INTERRUPCION )
		{
			iRes =  SIS_COD_SIG_INTERRUPCION;
		}
		else if ( iSignal == SIS_SIG_FINALIZACION_OBLIGADA )
		{
			iRes = SIS_COD_SIG_FINALIZACION_OBLIGADA;
		}
		else if ( iSignal == SIS_SIG_ERROR_TUBERIA )
		{
			iRes = SIS_COD_SIG_ERROR_TUBERIA;
		}
		else if ( iSignal == SIS_SIG_SALIR )
		{
			iRes = SIS_COD_SIG_SALIR;
		}
		else if ( iSignal == SIS_SIG_REFERENCIA_MEMORIA_INVALIDA )
		{
			iRes = SIS_COD_SIG_REFERENCIA_MEMORIA_INVALIDA;
		}
		else if ( iSignal == SIS_SIG_FINALIZACION )
		{
			iRes = SIS_COD_SIG_FINALIZACION;
		}
		else if ( iSignal == SIS_SIG_USUARIO_1 )
		{
			iRes = SIS_COD_SIG_USUARIO_1;
		}
		else if ( iSignal == SIS_SIG_USUARIO_2 )
		{
			iRes = SIS_COD_SIG_USUARIO_2;
		}
		else if ( iSignal == SIS_SIG_TEMPORIZADOR )
		{
			iRes = SIS_COD_SIG_TEMPORIZADOR;
		}
		else if ( iSignal == SIS_SIG_DEPURACION )
		{
			iRes = SIS_COD_SIG_DEPURACION;
		}
#	  if ( defined ( UNIX ) || defined ( LINUX ) )
		else if ( iSignal == SIS_SIG_ERROR_BUS )
		{
			iRes = SIS_COD_SIG_ERROR_BUS;
		}
		else if ( iSignal == SIS_SIG_ERROR_PILA	 )
		{
			iRes = SIS_COD_SIG_ERROR_PILA;
		}
		else if ( iSignal == SIS_SIG_CAMBIO_ESTADO_HIJO )
		{
			iRes = SIS_COD_SIG_CAMBIO_ESTADO_HIJO;
		}
		else if ( iSignal == SIS_SIG_CONTINUAR )
		{
			iRes = SIS_COD_SIG_CONTINUAR;
		}
		else if ( iSignal == SIS_SIG_PARAR )
		{
			iRes = SIS_COD_SIG_PARAR;
		}
		else if ( iSignal == SIS_SIG_PARAR_TECLADO )
		{
			iRes = SIS_COD_SIG_PARAR_TECLADO;
		}
		else if ( iSignal == SIS_SIG_LECTURA_SEGUNDO_PLANO )
		{
			iRes = SIS_COD_SIG_LECTURA_SEGUNDO_PLANO;
		}
		else if ( iSignal == SIS_SIG_ESCRITURA_SEGUNDO_PLANO )
		{
			iRes = SIS_COD_SIG_ESCRITURA_SEGUNDO_PLANO;
		}
		else if ( iSignal == SIS_SIG_AVISO_SOCKET )
		{
			iRes = SIS_COD_SIG_AVISO_SOCKET;
		}
		else if ( iSignal == SIS_SIG_ERROR_LIMITE_CPU )
		{
			iRes = SIS_COD_SIG_ERROR_LIMITE_CPU;
		}
		else if ( iSignal == SIS_SIG_ERROR_TAM_FICHERO )
		{
			iRes = SIS_COD_SIG_ERROR_TAM_FICHERO;
		}
		else if ( iSignal == SIS_SIG_TEMPORIZADOR_VIRTUAL )
		{
			iRes = SIS_COD_SIG_TEMPORIZADOR_VIRTUAL;
		}
		else if ( iSignal == SIS_SIG_CAMBIO_TAM_VENTANA )
		{
			iRes = SIS_COD_SIG_CAMBIO_TAM_VENTANA;
		}
		else if ( iSignal == SIS_SIG_EVENTO_ENTRADA_SALIDA )
		{
			iRes = SIS_COD_SIG_EVENTO_ENTRADA_SALIDA;
		}
		else if ( iSignal == SIS_SIG_ERROR_REINICIO_SISTEMA )
		{
			iRes = SIS_COD_SIG_ERROR_REINICIO_SISTEMA;
		}
		else if ( iSignal == SIS_SIG_ERROR_LLAMADA_SISTEMA )
		{
			iRes = SIS_COD_SIG_ERROR_LLAMADA_SISTEMA;
		}
#	  endif
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

int SisSigId ( int iCod )
{
	int iRes;

	if ( SisSigEstanPermitidos () == 1 )
	{
		if ( iCod == SIS_COD_SIG_ABORTAR )
		{
			iRes = SIS_COD_SIG_ABORTAR;
		}
		else if ( iCod == SIS_COD_SIG_ALARMA )
		{
			iRes = SIS_SIG_ALARMA;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_COMA_FLOTANTE )
		{
			iRes = SIS_SIG_ERROR_COMA_FLOTANTE;
		}
		else if ( iCod == SIS_COD_SIG_TERMINAL_DESCONECTADO )
		{
			iRes = SIS_SIG_TERMINAL_DESCONECTADO;
		}
		else if ( iCod == SIS_COD_SIG_INSTRUCCION_ILEGAL )
		{
			iRes = SIS_SIG_INSTRUCCION_ILEGAL;
		}
		else if ( iCod == SIS_COD_SIG_INTERRUPCION )
		{
			iRes =  SIS_SIG_INTERRUPCION;
		}
		else if ( iCod == SIS_COD_SIG_FINALIZACION_OBLIGADA )
		{
			iRes = SIS_SIG_FINALIZACION_OBLIGADA;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_TUBERIA )
		{
			iRes = SIS_SIG_ERROR_TUBERIA;
		}
		else if ( iCod == SIS_COD_SIG_SALIR )
		{
			iRes = SIS_SIG_SALIR;
		}
		else if ( iCod == SIS_COD_SIG_REFERENCIA_MEMORIA_INVALIDA )
		{
			iRes = SIS_SIG_REFERENCIA_MEMORIA_INVALIDA;
		}
		else if ( iCod == SIS_COD_SIG_FINALIZACION )
		{
			iRes = SIS_SIG_FINALIZACION;
		}
		else if ( iCod == SIS_COD_SIG_USUARIO_1 )
		{
			iRes = SIS_SIG_USUARIO_1;
		}
		else if ( iCod == SIS_COD_SIG_USUARIO_2 )
		{
			iRes = SIS_SIG_USUARIO_2;
		}
		else if ( iCod == SIS_COD_SIG_TEMPORIZADOR )
		{
			iRes = SIS_SIG_TEMPORIZADOR;
		}
		else if ( iCod == SIS_COD_SIG_DEPURACION )
		{
			iRes = SIS_SIG_DEPURACION;
		}
#	  if ( defined ( UNIX ) || defined ( LINUX ) )
		else if ( iCod == SIS_COD_SIG_ERROR_BUS )
		{
			iRes = SIS_SIG_ERROR_BUS;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_PILA	 )
		{
			iRes = SIS_SIG_ERROR_PILA;
		}
		else if ( iCod == SIS_COD_SIG_CAMBIO_ESTADO_HIJO )
		{
			iRes = SIS_SIG_CAMBIO_ESTADO_HIJO;
		}
		else if ( iCod == SIS_COD_SIG_CONTINUAR )
		{
			iRes = SIS_SIG_CONTINUAR;
		}
		else if ( iCod == SIS_COD_SIG_PARAR )
		{
			iRes = SIS_SIG_PARAR;
		}
		else if ( iCod == SIS_COD_SIG_PARAR_TECLADO )
		{
			iRes = SIS_SIG_PARAR_TECLADO;
		}
		else if ( iCod == SIS_COD_SIG_LECTURA_SEGUNDO_PLANO )
		{
			iRes = SIS_SIG_LECTURA_SEGUNDO_PLANO;
		}
		else if ( iCod == SIS_COD_SIG_ESCRITURA_SEGUNDO_PLANO )
		{
			iRes = SIS_SIG_ESCRITURA_SEGUNDO_PLANO;
		}
		else if ( iCod == SIS_COD_SIG_AVISO_SOCKET )
		{
			iRes = SIS_SIG_AVISO_SOCKET;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_LIMITE_CPU )
		{
			iRes = SIS_SIG_ERROR_LIMITE_CPU;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_TAM_FICHERO )
		{
			iRes = SIS_SIG_ERROR_TAM_FICHERO;
		}
		else if ( iCod == SIS_COD_SIG_TEMPORIZADOR_VIRTUAL )
		{
			iRes = SIS_SIG_TEMPORIZADOR_VIRTUAL;
		}
		else if ( iCod == SIS_COD_SIG_CAMBIO_TAM_VENTANA )
		{
			iRes = SIS_SIG_CAMBIO_TAM_VENTANA;
		}
		else if ( iCod == SIS_COD_SIG_EVENTO_ENTRADA_SALIDA )
		{
			iRes = SIS_SIG_EVENTO_ENTRADA_SALIDA;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_REINICIO_SISTEMA )
		{
			iRes = SIS_SIG_ERROR_REINICIO_SISTEMA;
		}
		else if ( iCod == SIS_COD_SIG_ERROR_LLAMADA_SISTEMA )
		{
			iRes = SIS_SIG_ERROR_LLAMADA_SISTEMA;
		}
#	  endif
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

int SisSigEsProgramable ( int iSignal )
{
	int iRes;

	if ( SisSigEstanPermitidos () == 1 )
	{
#	  if ( defined ( UNIX ) || defined ( LINUX ) )
		if ( ( iSignal == SIS_SIG_FINALIZACION_OBLIGADA ) ||
			 ( iSignal == SIS_SIG_PARAR ) )
#	  else
		if ( iSignal == SIS_SIG_FINALIZACION_OBLIGADA )
#	  endif
		{
			iRes = 0;
		}
		else
		{
			iRes = 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisSigEsValida ( int iSignal )
{
	int iCod;
	int	iRes;

	if ( SisSigEstanPermitidos () == 1 )
	{
		iCod = SisSigCodigo ( iSignal );
		if ( iCod >= 0 )
		{
			iRes = 1;
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

const char * SisSigDescripcion ( int iSignal )
{
	if ( iSignal == SIS_SIG_ABORTAR )
	{
		return ( SIS_SIG_TXT_ABORTAR );
	}
	else if ( iSignal == SIS_SIG_ALARMA )
	{
		return ( SIS_SIG_TXT_ALARMA );
	}
	else if ( iSignal == SIS_SIG_ERROR_COMA_FLOTANTE )
	{
		return ( SIS_SIG_TXT_ERROR_COMA_FLOTANTE );
	}
	else if ( iSignal == SIS_SIG_TERMINAL_DESCONECTADO )
	{
		return ( SIS_SIG_TXT_TERMINAL_DESCONECTADO );
	}
	else if ( iSignal == SIS_SIG_INSTRUCCION_ILEGAL )
	{
		return ( SIS_SIG_TXT_INSTRUCCION_ILEGAL );
	}
	else if ( iSignal == SIS_SIG_INTERRUPCION )
	{
		return ( SIS_SIG_TXT_INTERRUPCION );
	}
	else if ( iSignal == SIS_SIG_FINALIZACION_OBLIGADA )
	{
		return ( SIS_SIG_TXT_FINALIZACION_OBLIGADA );
	}
	else if ( iSignal == SIS_SIG_ERROR_TUBERIA )
	{
		return ( SIS_SIG_TXT_ERROR_TUBERIA );
	}
	else if ( iSignal == SIS_SIG_SALIR )
	{
		return ( SIS_SIG_TXT_SALIR );
	}
	else if ( iSignal == SIS_SIG_REFERENCIA_MEMORIA_INVALIDA )
	{
		return ( SIS_SIG_TXT_REFERENCIA_MEMORIA_INVALIDA );
	}
	else if ( iSignal == SIS_SIG_FINALIZACION )
	{
		return ( SIS_SIG_TXT_FINALIZACION );
	}
	else if ( iSignal == SIS_SIG_USUARIO_1 )
	{
		return ( SIS_SIG_TXT_USUARIO_1 );
	}
	else if ( iSignal == SIS_SIG_USUARIO_2 )
	{
		return ( SIS_SIG_TXT_USUARIO_2 );
	}
	else if ( iSignal == SIS_SIG_TEMPORIZADOR )
	{
		return ( SIS_SIG_TXT_TEMPORIZADOR );
	}
	else if ( iSignal == SIS_SIG_DEPURACION )
	{
		return ( SIS_SIG_TXT_DEPURACION );
	}
#  if ( defined ( UNIX ) || defined ( LINUX ) )
	else if ( iSignal == SIS_SIG_ERROR_BUS )
	{
		return ( SIS_SIG_TXT_ERROR_BUS );
	}
	else if ( iSignal == SIS_SIG_ERROR_PILA	 )
	{
		return ( SIS_SIG_TXT_ERROR_PILA );
	}
	else if ( iSignal == SIS_SIG_CAMBIO_ESTADO_HIJO )
	{
		return ( SIS_SIG_TXT_CAMBIO_ESTADO_HIJO );
	}
	else if ( iSignal == SIS_SIG_CONTINUAR )
	{
		return ( SIS_SIG_TXT_CONTINUAR );
	}
	else if ( iSignal == SIS_SIG_PARAR )
	{
		return ( SIS_SIG_TXT_PARAR );
	}
	else if ( iSignal == SIS_SIG_PARAR_TECLADO )
	{
		return ( SIS_SIG_TXT_PARAR_TECLADO );
	}
	else if ( iSignal == SIS_SIG_LECTURA_SEGUNDO_PLANO )
	{
		return ( SIS_SIG_TXT_LECTURA_SEGUNDO_PLANO );
	}
	else if ( iSignal == SIS_SIG_ESCRITURA_SEGUNDO_PLANO )
	{
		return ( SIS_SIG_TXT_ESCRITURA_SEGUNDO_PLANO );
	}
	else if ( iSignal == SIS_SIG_AVISO_SOCKET )
	{
		return ( SIS_SIG_TXT_AVISO_SOCKET );
	}
	else if ( iSignal == SIS_SIG_ERROR_LIMITE_CPU )
	{
		return ( SIS_SIG_TXT_ERROR_LIMITE_CPU );
	}
	else if ( iSignal == SIS_SIG_ERROR_TAM_FICHERO )
	{
		return ( SIS_SIG_TXT_ERROR_TAM_FICHERO );
	}
	else if ( iSignal == SIS_SIG_TEMPORIZADOR_VIRTUAL )
	{
		return ( SIS_SIG_TXT_TEMPORIZADOR_VIRTUAL );
	}
	else if ( iSignal == SIS_SIG_CAMBIO_TAM_VENTANA )
	{
		return ( SIS_SIG_TXT_CAMBIO_TAM_VENTANA );
	}
	else if ( iSignal == SIS_SIG_EVENTO_ENTRADA_SALIDA )
	{
		return ( SIS_SIG_TXT_EVENTO_ENTRADA_SALIDA );
	}
	else if ( iSignal == SIS_SIG_ERROR_REINICIO_SISTEMA )
	{
		return ( SIS_SIG_TXT_ERROR_REINICIO_SISTEMA );
	}
	else if ( iSignal == SIS_SIG_ERROR_LLAMADA_SISTEMA )
	{
		return ( SIS_SIG_TXT_ERROR_LLAMADA_SISTEMA );
	}
#  endif
	else
	{
		return ( NULL );
	}
}


#if ( defined ( SIGNALS_PERMITIDOS ) )

int SisSigEnviar ( long lPID, int iSignal )
{
	int iCod;
	int iRes;

	if ( SisSigEstanPermitidos () == 1 )
	{
		iCod = SisSigCodigo ( iSignal );
		if ( ( lPID >= 0 ) && ( iCod >= 0 ) )
		{
			kill ( lPID, iCod );
			iRes = 1;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SisSigAutoenviar ( int iSignal )
{
	return ( SisSigEnviar ( SisPID (), iSignal ) );
}

int SisSigAdmiteEspera ()
{
	int			iRes;
	static int	iPrueba = -1;
	time_t		tiAntes;
	time_t		tiDespues;

	if ( SisSigEstanPermitidos () == 1 )
	{
		if ( iPrueba < 0 )
		{
			time ( &tiAntes );
			alarm ( 2 );
			if ( pause () == 0 )
			{
				time ( &tiDespues );
				if ( tiDespues - tiAntes < 1 )
				{
					iRes = 0;
				}
				else
				{
					iRes = 1;
				}
			}
			else 
			{
				iRes = 0;
			}
			iPrueba = iRes;
		}
		else
		{
			iRes = iPrueba;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


int SisDesactivarSignal ( int iSignal, PPRCI * p_p_procRutAnterior )
{
	PPRCI	p_procRutAnt;
	int		iCod;
	int		iRes;

	if ( ( SisSigEstanPermitidos () == 1 ) )
	{
		if ( SisSigEsProgramable ( iSignal ) == 1 )
		{
			iCod = SisSigCodigo ( iSignal );
			if ( iCod >= 0 )
			{
				p_procRutAnt = signal ( iCod, SIG_IGN );
				if ( p_procRutAnt != SIG_ERR )
				{
					iRes = 1;
					if ( ES_VALIDO ( p_p_procRutAnterior ) )
					{
						*p_p_procRutAnterior = p_procRutAnt;
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

int SisAsignarSignal ( int iSignal, PPRCI p_procRutAtencion, PPRCI * p_p_procRutAnterior )
{
	PPRCI	p_procRutAnt;
	int		iCod;
	int		iRes;

	if ( ( SisSigEstanPermitidos () == 1 ) )
	{
		if ( SisSigEsProgramable ( iSignal ) == 1 )
		{
			iCod = SisSigCodigo ( iSignal );
			if ( iCod >= 0 )
			{
				if ( ES_VALIDO ( p_procRutAtencion ) )
				{
					p_procRutAnt = signal ( iCod, p_procRutAtencion );
				}
				else
				{
					p_procRutAnt = signal ( iCod, SIG_DFL );
				}
				if ( p_procRutAnt != SIG_ERR )
				{
					if ( ES_VALIDO ( p_p_procRutAnterior ) )
					{
						*p_p_procRutAnterior = p_procRutAnt;
					}
					iRes = 1;
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


#endif

