#ifndef _GJS_BNF_LIB_SARBOLCADENAS_H
#define _GJS_BNF_LIB_SARBOLCADENAS_H




#include <SArbolPtr.h>

#include <SCadena.h>



typedef struct
{
	SArbolPtr * p_arbContenido;

} SArbolCadenas;





SArbolCadenas * SArbCadCrear ();

void SArbCadDestruir ( SArbolCadenas ** p_p_arbObj );

SCadena * SArbCadRaiz ( SArbolCadenas * p_arbpObj );

int SArbCadEstablecerRaiz ( SArbolCadenas * p_arbpObj, SCadena * p_cadObj );

int SArbCadEstaVacio ( SArbolCadenas * p_arbpObj );
int SArbCadNiveles ( SArbolCadenas * p_arbpObj );
int SArbCadNumNodos ( SArbolCadenas * p_arbpObj );

int SArbCadVaciar ( SArbolCadenas * p_arbpObj );

SCadena * SArbCadActual ( SArbolCadenas * p_arbpObj );

void SArbCadMoverARaiz ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAPadre ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAHijo ( SArbolCadenas * p_arbpObj, int iHijo );
void SArbCadMoverAPrimHijo ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAUltHijo ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAPrimHermano ( SArbolCadenas * p_arbpObj );
void SArbCadMoverASigHermano ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAAntHermano ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAUltHermano ( SArbolCadenas * p_arbpObj );

void SArbCadMoverAPrimPreorden ( SArbolCadenas * p_arbpObj );
void SArbCadMoverASigPreorden ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAAntPreorden ( SArbolCadenas * p_arbpObj );
void SArbCadMoverAUltPreorden ( SArbolCadenas * p_arbpObj );

void SArbCadDesposicionar ( SArbolCadenas * p_arbpObj );
int	SArbCadEstaPosicionado ( SArbolCadenas * p_arbpObj );

int SArbCadEnraizar ( SArbolCadenas * p_arbpObj, SCadena * p_cadValor );

int SArbCadActualEsValido ( SArbolCadenas * p_arbObj );
int SArbCadActualTieneDatos ( SArbolCadenas * p_arbObj );

int SArbCadActualModificar ( SArbolCadenas * p_arbObj, SCadena * p_cadValor );

int SArbCadActualNumHijos ( SArbolCadenas * p_arbObj );
SCadena * SArbCadActualPadre ( SArbolCadenas * p_arbObj );
SCadena * SArbCadActualHijo ( SArbolCadenas * p_arbObj, int iHijo );

int SArbCadActualTienePadre ( SArbolCadenas * p_arbObj );
int SArbCadActualTieneHijos ( SArbolCadenas * p_arbObj );
int SArbCadActualTieneHermanos ( SArbolCadenas * p_arbObj );
int SArbCadActualTieneHermanosIzq ( SArbolCadenas * p_arbObj );
int SArbCadActualTieneHermanosDer ( SArbolCadenas * p_arbObj );

int SArbCadActualNodosInferiores ( SArbolCadenas * p_arbObj );
int SArbCadActualProfundidad ( SArbolCadenas * p_arbObj );
int SArbCadActualNivelesInferiores ( SArbolCadenas * p_arbObj );

int SArbCadActualInsertarHijo ( SArbolCadenas * p_arbObj, SCadena * p_cadValor );
int SArbCadActualEliminarHijo ( SArbolCadenas * p_arbObj, int iHijo );
int SArbCadActualEstablecerHijo ( SArbolCadenas * p_arbObj, int iHijo, SCadena * p_cadValor );
void SArbCadActualLimpiarHijos ( SArbolCadenas * p_arbObj  );

int	SArbCadActualEsHijo ( SArbolCadenas * p_arbObj );

int SArbCadVerificar ( SArbolCadenas * p_arbpObj, int iCorregir );




#endif

