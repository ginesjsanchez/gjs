#ifndef _ORG_GJS_C_CC_SDIRECTORIO_H
#define _ORG_GJS_C_CC_SDIRECTORIO_H




	/*

#include <SCadena.h>
//#include <SPath.h>
#include <SListaPtr.h>
#include <SEntradaDirectorio.h>



typedef struct  
{
	//SSistemaFicheros 
	//SListaPtr
	//SPath
	char * p_cNombre;
	
} SDirectorio;


SDirectorio ();
SDirectorio ( const char * _ORG_GJS_C_CC_p_cDirectorio );
SDirectorio ( SCadena * _ORG_GJS_C_CC_p_cadDirectorio );

~SDirectorio ();

SPath * Ruta ();
SCadena * Valor ();

void Cambiar ( const char * _ORG_GJS_C_CC_p_cDirectorio );
void Cambiar ( SCadena * _ORG_GJS_C_CC_p_cadDirectorio );
void Refrescar ();

int NumEntradas ();
SEntradaDirectorio * Entrada ( int _ORG_GJS_C_CC_iEntrada );

int CrearSubdirectorio ( const char * _ORG_GJS_C_CC_p_cSubdirectorio );
int CrearSubdirectorio ( SCadena * _ORG_GJS_C_CC_p_cadSubdirectorio );

void LiberarEntradas ();


int CopiarFicheroA ( const char * _ORG_GJS_C_CC_p_cDirDestino );
int CopiarFicheroA ( SCadena * _ORG_GJS_C_CC_p_cadDirDestino );
int CopiarFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino );
int CopiarFicheroA ( SPath * _ORG_GJS_C_CC_p_pathRuta );
int CopiarFicheroA ( const char * _ORG_GJS_C_CC_p_cDirDestino, const char * _ORG_GJS_C_CC_p_cFichero );
int CopiarFicheroA ( SCadena * _ORG_GJS_C_CC_p_cadDirDestino, SCadena * _ORG_GJS_C_CC_p_cadFichero );
int CopiarFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino, const char * _ORG_GJS_C_CC_p_cFichero );
int CopiarFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino,  SCadena * _ORG_GJS_C_CC_p_cadFichero );
int CopiarFicheroDesde ( SPath * _ORG_GJS_C_CC_p_pathRuta );
int CopiarFicheroDesde ( const char * _ORG_GJS_C_CC_p_cDirOrigen, const char * _ORG_GJS_C_CC_p_cFichero );
int CopiarFicheroDesde ( SCadena * _ORG_GJS_C_CC_p_cadDirOrigen, SCadena * _ORG_GJS_C_CC_p_cadFichero );
int CopiarFicheroDesde ( SDirectorio * _ORG_GJS_C_CC_p_dirOrigen, const char * _ORG_GJS_C_CC_p_cFichero );
int CopiarFicheroDesde ( SDirectorio * _ORG_GJS_C_CC_p_dirOrigen, SCadena * _ORG_GJS_C_CC_p_cadFichero );
int MoverFicheroA ( const char * _ORG_GJS_C_CC_p_cDirDestino );
int MoverFicheroA ( SCadena * _ORG_GJS_C_CC_p_cadDirDestino );
int MoverFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino );
int MoverFicheroA ( SPath * _ORG_GJS_C_CC_p_pathRuta );
int MoverFicheroA ( const char * _ORG_GJS_C_CC_p_cDirDestino, const char * _ORG_GJS_C_CC_p_cFichero );
int MoverFicheroA ( SCadena * _ORG_GJS_C_CC_p_cadDirDestino, SCadena * _ORG_GJS_C_CC_p_cadFichero );
int MoverFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino, const char * _ORG_GJS_C_CC_p_cFichero );
int MoverFicheroA ( SDirectorio * _ORG_GJS_C_CC_p_dirDestino,  SCadena * _ORG_GJS_C_CC_p_cadFichero );
int MoverFicheroDesde ( SPath * _ORG_GJS_C_CC_p_pathRuta );
int MoverFicheroDesde ( const char * _ORG_GJS_C_CC_p_cDirOrigen, const char * _ORG_GJS_C_CC_p_cFichero );
int MoverFicheroDesde ( SCadena * _ORG_GJS_C_CC_p_cadDirOrigen, SCadena * _ORG_GJS_C_CC_p_cadFichero );
int MoverFicheroDesde ( SDirectorio * _ORG_GJS_C_CC_p_dirOrigen, const char * _ORG_GJS_C_CC_p_cFichero );
int MoverFicheroDesde ( SDirectorio * _ORG_GJS_C_CC_p_dirOrigen, SCadena * _ORG_GJS_C_CC_p_cadFichero );


private:
int CargarEntradas ();
void VaciarLista ();


*/


#endif



