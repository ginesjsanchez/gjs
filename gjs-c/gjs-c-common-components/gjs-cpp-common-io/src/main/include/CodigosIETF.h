#ifndef _ORG_GJS_C_CC_CPP_CODIGOS_IETF_H
#define _ORG_GJS_C_CC_CPP_CODIGOS_IETF_H






using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {


			const string IETF_CONTINUAR = "100";
			const string IETF_CAMBIANDO_PROTOCOLO = "101";
			const string IETF_PROCESANDO = "102";
			const string IETF_CONSEJOS = "103";
			const string IETF_REINICIAR_MARCADOR = "110";  
			const string IETF_SERVICIO_LISTO_PROXIMAMEMTE = "120";  
 			const string IETF_TRANSFERENCIA_INICIADA = "125"; 
			const string IETF_FICHERO_PREPARADO = "150"; 
 
			const string IETF_OK = "200";
			const string IETF_CREADO = "201";
			const string IETF_ACEPTADO = "202";
			const string IETF_INFORMACION_NO_AUTORIZADA = "203";
			const string IETF_SIN_CONTENIDO = "204";
			const string IETF_CONTENIDO_INICIALIZADO = "205";
			const string IETF_CONTENIDO_PARCIAL = "206";

			const string IETF_MULTIPLES_OPCIONES = "300";
			const string IETF_MOVIDO_PERMANENTEMENTE = "301";
			const string IETF_ENCONTRADO = "302";
			const string IETF_PRUEBA_OTRO = "303";
			const string IETF_NO_MODIFICADO = "304";
			const string IETF_USAR_PROXY = "305";
			const string IETF_TEMPORALMENTE_REDIRIGIDO = "307";
			
			const string IETF_PETICION_ERROENA = "400";
			const string IETF_NO_AUTORIZADO = "401";
			const string IETF_PAGO_REQUERIDO = "402";
			const string IETF_PROHIBIDO = "403";
			const string IETF_NO_ENCONTRADO = "404";
			const string IETF_METODO_NO_PERMITIDO = "405";
			const string IETF_NO_ACEPTABLE = "406";
			const string IETF_AUTENTICACION_PROXY_REQUERIDA = "407";
			const string IETF_TIEMPO_EXCEDIDO = "408";			
			const string IETF_CONFLICTO = "409";			
			const string IETF_DESAPARECIDO = "410";			
			const string IETF_LONGITUD_REQUERIDA = "411";			
			const string IETF_FALLO_PRECONDICION = "412";			
			const string IETF_ENTIDAD_DEMASIADO_GRANDE = "413";			
			const string IETF_URI_DEMASIADO_GRANDE = "414";			
			const string IETF_TIPO_NO_SOPORTADO = "415";			
			const string IETF_RANGO_NO_SATISFACIBLE = "416";			
			const string IETF_EXPECTACION_FALLIDA = "417";			
			
			const string IETF_ERROR_INTERNO = "500";
			const string IETF_NO_IMPLEMENTADO = "501";
			const string IETF_ERROR_SINTACTICO = "501";
			const string IETF_PUERTA_ENLACE_ERRONEA = "502";
			const string IETF_COMANDO_NO_IMPLEMENTADO = "502";
			const string IETF_SERVICIO_NO_DISPONIBLE = "503";  
			const string IETF_SECUENCIA_ERRONEA = "503";  
			const string IETF_TIEMPO_PUERTA_ENLACE_EXCEDIDO = "504";
			const string IETF_CASO_NO_IMPLEMENTADO = "504";  
			const string IETF_VERSION_PROTOCOLO_NO_SOPORTADA = "505";
 
			const string IETF_ESTADO_SISTEMA = "211";  
			const string IETF_ESTADO_DIRECTORIO = "212";  
			const string IETF_ESTADO_FICHERO = "213";  
			const string IETF_AYUDA = "214";  
			const string IETF_INFO_SISTEMA = "215";  
                                                                         
			const string IETF_SERVICIO_PREPARADO = "220"; 
			const string IETF_SALIR = "221";  
 			const string IETF_SOLICITUD_MAL_DIRIGIDA = "421";  
    
 			const string IETF_CONEXION_ABIERTA = "225";
  			const string IETF_ERROR_CONEXION = "425";  
			const string IETF_CERRANDO_CONEXION = "226";  
 			const string IETF_CONEXION_CERRADA = "426";
			const string IETF_MODO_PASIVO = "227"; 
                                                                       
			const string IETF_SESION_INICIADA = "230"; 
			const string IETF_SESION_NO_INICIADA = "530"; 
			const string IETF_FALTA_CLAVE = "331";  
			const string IETF_NECESARIO_SESION = "332";  
			const string IETF_NECESARIO_SESION_PARA_OPERACION = "532";  
                                                                        
 			const string IETF_ACCION_COMPLETADA = "250"; 
			const string IETF_ACCION_PENDIENTE = "350";  
 			const string IETF_FICHERO_NO_DISPONIBLE = "450"; 
 			const string IETF_ACCION_NO_REALIZADA = "550";  
  			const string IETF_ACCION_ABORTADA = "451";  
 			const string IETF_ESPACIO_INSUFICIENTE = "452";  
 			const string IETF_ESPACIO_EXCEDIDO = "552";  
			const string IETF_ACCION_NO_PERMITIDA = "553"; 
  			const string IETF_INICIAR_CORREO = "354";  

  			const string IETF_DIRECTORIO = "257";  

		
			const string IETF_DESCONOCIDO = "999";
			
			
			bool EsCodigoIETF( const string & sCodigo );
			string ConstruirRespuestaIETF( const string & sCodigo, const string sMensaje = "" );
			bool ProcesarRespuestaIETF( const string & sRespuesta, string & sCodigo, string & sMensaje );
			string ConstruirMensajeIETF( const string sMensaje );
			string ProcesarMensajeIETF( const string & sMensaje );
		
 			}
		}
	}
}


#endif