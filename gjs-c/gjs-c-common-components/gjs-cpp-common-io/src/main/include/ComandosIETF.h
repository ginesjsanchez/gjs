#ifndef _ORG_GJS_C_CC_CPP_COMANDOS_IETF_H
#define _ORG_GJS_C_CC_CPP_COMANDOS_IETF_H




#include <string>
#include <list>



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

			const string IETF_CMD_USUARIO 				= "USER";
			const string IETF_CMD_CLAVE					= "PASS";
			const string IETF_CMD_CUENTA				= "ACCT";
			const string IETF_CMD_SALIR 				= "QUIT";

			const string IETF_CMD_NADA					= "NOOP";
			const string IETF_CMD_AYUDA					= "HELP";
			const string IETF_CMD_REINICIALIZAR			= "REIN";
			const string IETF_CMD_REINICIAR				= "REST";
			const string IETF_CMD_ABORTAR 				= "ABOR";
			const string IETF_CMD_CONFIGURACION			= "SITE"; 
			const string IETF_CMD_ESTADO				= "STAT";
			const string IETF_CMD_SISTEMA				= "SYST";
			
			// FTP:
			const string IETF_CMD_RESERVAR				= "ALLO"; 
			const string IETF_CMD_ANEXAR				= "APPE";
			const string IETF_CMD_CAMBIAR_DIR			= "CWD";
			const string IETF_CMD_ELIMINAR				= "DELE";
			const string IETF_CMD_LISTAR				= "LIST";
			const string IETF_CMD_MODO_TRANSFER			= "MODE";
			const string IETF_CMD_LISTAR_NOMBRES		= "NLST"; 			
			const string IETF_CMD_MODO_PASIVO			= "PASV";
			const string IETF_CMD_PUERTO				= "PORT"; 
			const string IETF_CMD_RECUPERAR				= "RETR";
			const string IETF_CMD_RENOMBRAR_ORIG		= "RNFR";
			const string IETF_CMD_RENOMBRAR_DEST		= "RNTO";
			const string IETF_CMD_GUARDAR				= "STOR";
			const string IETF_CMD_ESTRUCTURA_FIC		= "STRU";
			const string IETF_CMD_TIPO					= "TYPE";
			const string IETF_CMD_TAM					= "SIZE";
			const string IETF_CMD_DIR_PADRE				= "CDUP"; 
			const string IETF_CMD_CREAR_DIR				= "MKD";
			const string IETF_CMD_OBTENER_DIR			= "PWD"; 
			const string IETF_CMD_ELIMINAR_DIR			= "RMD";
			const string IETF_CMD_MONTAR_ESTRUCTURA 	= "SMNT";
			const string IETF_CMD_GUARDAR_UNICO			= "STOU"; 			
			
			// SMTP
			const string IETF_CMD_IDENTIFICACION		= "HELO";
			const string IETF_CMD_IDENTIFICACION_EXT	= "EHEL";
			const string IETF_CMD_CORREO				= "MAIL";
			const string IETF_CMD_DESTINATARIO			= "RCPT";
			const string IETF_CMD_DATOS					= "DATA";
			const string IETF_CMD_ANULAR				= "RSET";
			const string IETF_CMD_VERIFICAR				= "VRFY";
			const string IETF_CMD_EXPANDIR				= "EXPN";

			// HTTP
			const string IETF_CMD_OPCIONES				= "OPTIONS";
			const string IETF_CMD_METODO_GET			= "GET";
			const string IETF_CMD_METODO_HEAD			= "HEAD";
			const string IETF_CMD_METODO_POST			= "POST";
			const string IETF_CMD_METODO_PUT			= "PUT";
			const string IETF_CMD_METODO_DEL			= "DELETE";
			const string IETF_CMD_METODO_PATCH			= "PATCH";
	
			
			const list<string> lisComandosFtp( { IETF_CMD_USUARIO, IETF_CMD_CLAVE, IETF_CMD_AYUDA, IETF_CMD_CUENTA, IETF_CMD_RESERVAR, IETF_CMD_ANEXAR, 
													IETF_CMD_CAMBIAR_DIR, IETF_CMD_ELIMINAR, IETF_CMD_LISTAR, IETF_CMD_MODO_TRANSFER, IETF_CMD_LISTAR_NOMBRES, 
													IETF_CMD_MODO_PASIVO, IETF_CMD_PUERTO, IETF_CMD_RECUPERAR, IETF_CMD_RENOMBRAR_ORIG, IETF_CMD_RENOMBRAR_DEST, 
													IETF_CMD_GUARDAR, IETF_CMD_ESTRUCTURA_FIC, IETF_CMD_TIPO, IETF_CMD_TAM, IETF_CMD_DIR_PADRE, IETF_CMD_CREAR_DIR,	
													IETF_CMD_OBTENER_DIR, IETF_CMD_ELIMINAR_DIR, IETF_CMD_MONTAR_ESTRUCTURA, IETF_CMD_GUARDAR_UNICO, 
													IETF_CMD_REINICIALIZAR, IETF_CMD_REINICIAR, IETF_CMD_ABORTAR, IETF_CMD_CONFIGURACION, IETF_CMD_ESTADO, 
													IETF_CMD_SISTEMA, IETF_CMD_NADA, IETF_CMD_SALIR } );
													
			const list<string> lisComandosSmtp( { IETF_CMD_IDENTIFICACION, IETF_CMD_IDENTIFICACION_EXT, IETF_CMD_CORREO, IETF_CMD_DESTINATARIO,
													IETF_CMD_DATOS, IETF_CMD_VERIFICAR, IETF_CMD_EXPANDIR, IETF_CMD_AYUDA, IETF_CMD_NADA, IETF_CMD_SALIR } );
													
			const list<string> lisComandosHttp( { IETF_CMD_OPCIONES, IETF_CMD_METODO_GET, IETF_CMD_METODO_HEAD, IETF_CMD_METODO_POST, IETF_CMD_METODO_POST,
													IETF_CMD_METODO_DEL } );

 			}
		}
	}
}


#endif