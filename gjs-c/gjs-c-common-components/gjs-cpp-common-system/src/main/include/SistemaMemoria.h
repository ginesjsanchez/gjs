/******************************************************************************/
/*                              SistemaMemoria.h                              */
/*----------------------------------------------------------------------------*/
/* Librería:  Sistema                                                         */
/* Versión:   3.0.0                                                           */
/* Fecha:     25/03/2008                                                      */
/* Autor:     Ginés Jiménez Sánchez                                           */
/*----------------------------------------------------------------------------*/
/* Descripción:                                                               */
/* Fichero de cabecera que contiene los prototipos de algunas rutinas de      */
/* de carácter general de reserva y liberación de espacios de memoria.        */
/*----------------------------------------------------------------------------*/
/*                        gines_jimenez@safe-mail.net                         */
/******************************************************************************/

#ifndef _ORG_GJS_C_CC_CPP_SISTEMAMEMORIA_H
#define _ORG_GJS_C_CC_CPP_SISTEMAMEMORIA_H






using namespace std;

namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {



unsigned long SisMemoriaTotal ();
unsigned long SisMemoriaDisponible ();
unsigned long SisMemoriaOcupada ();

double SisMemoriaDisponiblePorc ();
double SisMemoriaOcupadaPorc ();

unsigned long SisMemoriaFisicaTotal ();
unsigned long SisMemoriaFisicaDisponible ();
unsigned long SisMemoriaFisicaOcupada ();

unsigned long SisMemoriaFicPaginacionTotal ();
unsigned long SisMemoriaFicPaginacionDisponible ();
unsigned long SisMemoriaFicPaginacionOcupada ();



 			}
		}
	}
}


#endif




