/***************************************************************************/
/*                          CajaMensajes.cpp                               */
/*-------------------------------------------------------------------------*/
/* Librería: GAplicacion                                                  */
/* Versión:  2.0.0                                                         */
/* Fecha:    01/09/2007                                                    */
/* Autor:    Ginés Jiménez Sánchez                                         */
/*-------------------------------------------------------------------------*/
/* Autor:    Ginés Jiménez Sánchez                                         */
/*-------------------------------------------------------------------------*/
/* Descripción:                                                            */
/* Fichero de código fuente que contiene la implementación de la rutina    */
/* para controlar el diálogo de mensajes del sistema.                      */
/*-------------------------------------------------------------------------*/
/*                    gines_jimenez@safe-mail.net                          */
/***************************************************************************/

#include "CajaMensajes.h"

#include "CommonSupportConfig.h"



using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {





#if ( defined ( WIN ) )


//extern HWND ExeVentanaPrincipal ();




int CajMsjMostrar ( int iTipo,const string & sTitulo, const string & sMensaje )
{
	int		iRes;
	UINT	uiFlags;
	HWND    hVentana;

	
	if ( ES_VALIDO ( p_cMensaje ) && ( TipCajMsjEsValido ( iTipo ) == 1 ) )
	{
		if ( iTipo == TIP_CAJ_MSJ_INFORMACION )
		{
			uiFlags = MB_ICONINFORMATION | MB_OK;
		}
		else if ( iTipo == TIP_CAJ_MSJ_PREGUNTA )
		{
			uiFlags = MB_ICONQUESTION | MB_YESNO;
		}
		else if ( iTipo == TIP_CAJ_MSJ_PREGUNTA_OKCAN )
		{
			uiFlags = MB_ICONQUESTION | MB_OKCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_PREGUNTA_REINCAN )
		{
			uiFlags = MB_ICONQUESTION | MB_RETRYCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_PREGUNTA_SINOCAN )
		{
			uiFlags = MB_ICONQUESTION | MB_YESNOCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_AVISO )
		{
			uiFlags = MB_ICONEXCLAMATION | MB_OK;
		}
		else if ( iTipo == TIP_CAJ_MSJ_AVISO_OKCAN )
		{
			uiFlags = MB_ICONEXCLAMATION | MB_OKCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_AVISO_REINCAN )
		{
			uiFlags = MB_ICONEXCLAMATION | MB_RETRYCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_AVISO_ABRREINIGN )
		{
			uiFlags = MB_ICONEXCLAMATION | MB_ABORTRETRYIGNORE;
		}
		else if ( iTipo == TIP_CAJ_MSJ_ERROR )
		{
			uiFlags = MB_ICONERROR | MB_OK;
		}
		else if ( iTipo == TIP_CAJ_MSJ_ERROR_OKCAN )
		{
			uiFlags = MB_ICONERROR | MB_OKCANCEL;
		}
		else if ( iTipo == TIP_CAJ_MSJ_ERROR_REINCAN )
		{
			uiFlags = MB_ICONERROR | MB_RETRYCANCEL;
		}
		else //if ( iTipo == TIP_CAJ_MSJ_ERROR_ABRREINIGN )
		{
			uiFlags = MB_ICONERROR | MB_ABORTRETRYIGNORE;
		}
		uiFlags = uiFlags | MB_APPLMODAL;
		//hVentana = ExeVentanaPrincipal ();
		//if ( ES_NULO ( hVentana ) )
		//{
		hVentana = GetActiveWindow ();
		//}
		iRes = MessageBox ( hVentana, p_cMensaje, p_cTitulo, uiFlags );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

template<typename... Args> int CajMsjMostrarConFormato ( int iTipo, const string & sTitulo, const string & sFormato, Args&&... argumentos );
{
	sMensaje = ToString ( sFormato, forward<Args>( argumentos )... ).substr( 0, CAJ_MSJ_MAX_TAM_LINEA );
	return ( CajMsjMostrar ( iTipo, sTitulo, sMensaje ) );
}

#else

int CajMsjMostrar ( int iTipo,const string & sTitulo, const string & sMensaje )
{
	int		iRes;
	if ( TipCajMsjEsValido ( iTipo ) ) 
	{
		cout << endl;
		cout << "********************************************************************************************" << endl;
		cout << "*  " << setw ( 86 ) << sTitulo << "  *" << endl;
		cout << "*------------------------------------------------------------------------------------------*" << endl;
		cout << "*                                                                                          *" << endl;
		cout << "*  " << setw ( 86 ) << sMensaje << "  *" << endl;
		cout << "*                                                                                          *" << endl;
		cout << "*                        Pulsa <retorno> para continuar...                                 *" << endl;
		cout << "********************************************************************************************" << endl;
		cout << endl;
		char cVal = getchar ();
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

template<typename... Args> int CajMsjMostrarConFormato ( int iTipo, const string & sTitulo, const string & sFormato, Args&&... argumentos )
{
	string sMensaje = ToString ( sFormato, forward<Args>( argumentos )... ).substr( 0, CAJ_MSJ_MAX_TAM_LINEA );
	return ( CajMsjMostrar ( iTipo, sTitulo, sMensaje ) );
}



#endif


 			}
		}
	}
}
