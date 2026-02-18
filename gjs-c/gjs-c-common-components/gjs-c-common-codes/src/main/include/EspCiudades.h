
#ifndef _ORG_GJS_C_CC_ESPCIUDADES_H
#define _ORG_GJS_C_CC_ESPCIUDADES_H



#define CIUD_ESP_NINGUNO				0

#define CIUD_ESP_MADRID					0
#define CIUD_ESP_BARCELONA				1



#define CIUD_ESP_COD_MADRID				"MAD"
#define CIUD_ESP_COD_BARCELONA			"BCN"



#define CIUD_ESP_TXT_MADRID				"Madrid"
#define CIUD_ESP_TXT_BARCELONA			"Barcelona"


#define CIUD_ESP_LAT_MADRID				402600
#define CIUD_ESP_LAT_BARCELONA			412300

#define CIUD_ESP_LON_MADRID				-34115
#define CIUD_ESP_LON_BARCELONA			21100

#define CIUD_ESP_ALT_MADRID				667
#define CIUD_ESP_ALT_BARCELONA			25




const char * CiudEspLiteral ( int iId );
const char * CiudEspCodigo ( int iId );
int CiudEspId ( const char * p_cLit );
int CiudEspIdPorCodigo ( const char * p_cCod );
int CiudEspEsValida ( int iId );

long CiudEspLongitud ( int iId );
long CiudEspLatitud ( int iId );
long CiudEspAltitud ( int iId );





#endif
