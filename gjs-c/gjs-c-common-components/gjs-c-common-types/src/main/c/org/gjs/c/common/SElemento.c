#include "SElemento.h"


#include "TiposBasicosConfig.h"




SElemento * SElmCrear ( int iTam )
{
	SElemento * p_elmObj;
	
	if ( iTam > 0 )
	{
		p_elmObj = (SElemento *) MemReservar ( sizeof ( SElemento ) );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			p_elmObj->p_elmAnt = NULL;
			p_elmObj->p_elmSig = NULL;

			p_elmObj->p_blqDatos = SBlqCrear ( iTam );
			if ( ES_VALIDO ( p_elmObj->p_blqDatos ) )
			{
				p_elmObj->iLiberar = 1;
			}
			else
			{
				p_elmObj->iLiberar = 0;
			}
		}
	}
	else
	{
		p_elmObj = NULL;
	}
	return ( p_elmObj );
}

SElemento * SElmCrearEntero ()
{
	return ( SElmCrear ( sizeof ( int ) ) );
}

SElemento * SElmCrearEnteroLargo ()
{
	return ( SElmCrear ( sizeof ( long ) ) );
}

SElemento * SElmCrearReal ()
{
	return ( SElmCrear ( sizeof ( float ) ) );
}

SElemento * SElmCrearRealDoble ()
{
	return ( SElmCrear ( sizeof ( double ) ) );
}

SElemento * SElmCrearCadena ()
{
	return ( SElmCrear ( sizeof ( char * ) ) );
}

SElemento * SElmEncapsular ( SBloque * p_blqDatos )
{
	SElemento * p_elmObj;
	
	if ( ES_VALIDO ( p_blqDatos ) )
	{
		p_elmObj= (SElemento *) MemReservar ( sizeof ( SElemento ) );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			p_elmObj->p_elmAnt = NULL;
			p_elmObj->p_elmSig = NULL;

			p_elmObj->p_blqDatos = p_blqDatos;
			p_elmObj->iLiberar = SBlqLiberacionMemoriaActivada ( p_blqDatos );
		}
	}
	else
	{
		p_elmObj = NULL;
	}
	return ( p_elmObj );
}

SElemento * SElmEncapsularDir ( byte * p_byDirDatos, int iTamDatos, int iLiberar )
{
	SElemento * p_elmObj;
	
	if ( ES_VALIDO ( p_byDirDatos ) && ( iTamDatos > 0 ) && BOOL_VALIDO ( iLiberar ) )
	{
		p_elmObj= (SElemento *) MemReservar ( sizeof ( SElemento ) );
		if ( ES_VALIDO ( p_elmObj ) )
		{
			p_elmObj->p_elmAnt = NULL;
			p_elmObj->p_elmSig = NULL;

			p_elmObj->p_blqDatos = SBlqAsignar ( p_byDirDatos, iTamDatos, iLiberar );
			if ( ES_VALIDO ( p_elmObj->p_blqDatos ) )
			{
				p_elmObj->iLiberar = SBlqLiberacionMemoriaActivada ( p_elmObj->p_blqDatos );
			}
			else
			{
				p_elmObj->iLiberar = 0;
			}
		}
	}
	else
	{
		p_elmObj = NULL;
	}
	return ( p_elmObj );
}

void SElmDestruir ( SElemento ** p_p_elmObj )
{
	SElemento * p_elmObj;
	
	if ( ES_VALIDO ( p_p_elmObj ) )
	{
		p_elmObj = *p_p_elmObj;

		if ( ES_VALIDO ( p_elmObj ) )
		{
			if ( p_elmObj->iLiberar == 1 )
			{
				SBlqDestruir ( &(p_elmObj->p_blqDatos) );
			}
			MemLiberar ( (void **) p_p_elmObj );
		}
	}
}

int SElmEsValido ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_blqDatos ) )
		{
			if ( SBlqEsValido ( p_elmObj->p_blqDatos ) == 1 )
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SBloque * SElmDatos ( SElemento * p_elmObj )
{
	SBloque * p_blqRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		p_blqRes = p_elmObj->p_blqDatos;
	}
	else
	{
		p_blqRes = NULL;
	}
	return ( p_blqRes );
}

int SElmEntero ( SElemento * p_elmObj )
{
	int	iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEntero ( p_elmObj->p_blqDatos );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

long SElmEnteroLargo ( SElemento * p_elmObj )
{
	long lRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		lRes = SBlqEnteroLargo ( p_elmObj->p_blqDatos );
	}
	else
	{
		lRes = 0;
	}
	return ( lRes );
}

float SElmReal ( SElemento * p_elmObj )
{
	float fRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		fRes = SBlqReal ( p_elmObj->p_blqDatos );
	}
	else
	{
		fRes = 0;
	}
	return ( fRes );
}

double SElmRealDoble ( SElemento * p_elmObj )
{
	double dRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		dRes = SBlqRealDoble ( p_elmObj->p_blqDatos );
	}
	else
	{
		dRes = 0;
	}
	return ( dRes );
}

char * SElmCadena ( SElemento * p_elmObj )
{
	char * p_cRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		p_cRes = SBlqCadena ( p_elmObj->p_blqDatos );
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SElmTieneDatos ( SElemento * p_elmObj )
{
	int iRes;

	if ( SElmEsValido ( p_elmObj ) )
	{
		if ( SBlqTam ( p_elmObj->p_blqDatos ) > 0 )
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

int SElmModificar ( SElemento * p_elmObj, SBloque * p_blqDatos )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) && ES_VALIDO ( p_blqDatos ) )
	{
		if ( p_elmObj->iLiberar == 1 )
		{
			SBlqDestruir ( &(p_elmObj->p_blqDatos) );
		}

		p_elmObj->p_blqDatos = p_blqDatos;
		p_elmObj->iLiberar = SBlqLiberacionMemoriaActivada ( p_blqDatos );
		iRes = 1;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmModificarDir ( SElemento * p_elmObj, byte * p_byDirDatos, int iTamDatos, int iLiberar )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) && ES_VALIDO ( p_byDirDatos ) && ( iTamDatos > 0 ) && 
		 BOOL_VALIDO ( iLiberar ) )
	{
		if ( p_elmObj->iLiberar == 1 )
		{
			SBlqDestruir ( &(p_elmObj->p_blqDatos) );
		}

		p_elmObj->p_blqDatos = SBlqAsignar ( p_byDirDatos, iTamDatos, iLiberar );
		if ( ES_VALIDO ( p_elmObj->p_blqDatos ) )
		{
			iRes = 1;
			p_elmObj->iLiberar = SBlqLiberacionMemoriaActivada ( p_elmObj->p_blqDatos );
		}
		else
		{
			iRes = 0;
			p_elmObj->iLiberar = 0;
		}
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirByte ( SElemento * p_elmObj, int iPos, byte byValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirByte ( p_elmObj->p_blqDatos, iPos, byValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirEntero ( SElemento * p_elmObj, int iValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirEntero ( p_elmObj->p_blqDatos, iValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirEnteroLargo ( SElemento * p_elmObj, long lValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirEnteroLargo ( p_elmObj->p_blqDatos, lValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirReal ( SElemento * p_elmObj, float fValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirReal ( p_elmObj->p_blqDatos, fValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirRealDoble ( SElemento * p_elmObj, double dValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirRealDoble ( p_elmObj->p_blqDatos, dValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEscribirCadena ( SElemento * p_elmObj, const char * p_cValor )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = SBlqEscribirCadena ( p_elmObj->p_blqDatos, p_cValor );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

SElemento * SElmAntecesor ( SElemento * p_elmObj )
{
	SElemento * p_elmRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		p_elmRes = (SElemento *) p_elmObj->p_elmAnt;
	}
	else
	{
		p_elmRes = NULL;
	}
	return ( p_elmRes );
}

SElemento * SElmSucesor ( SElemento * p_elmObj )
{
	SElemento * p_elmRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		p_elmRes = (SElemento *) p_elmObj->p_elmSig;
	}
	else
	{
		p_elmRes = NULL;
	}
	return ( p_elmRes );
}

int SElmTieneAntecesor ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_elmAnt ) )
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

int SElmTieneSucesor ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_elmSig ) )
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

int SElmEncadenarAntecesor ( SElemento * p_elmObj, SElemento * p_elmAnt )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) && ES_VALIDO ( p_elmAnt ) )
	{
		p_elmObj->p_elmAnt = (void *) p_elmAnt;
		SElmEncadenarSucesor ( p_elmAnt, p_elmObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmEncadenarSucesor ( SElemento * p_elmObj, SElemento * p_elmSuc )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) && ES_VALIDO ( p_elmSuc ) )
	{
		p_elmObj->p_elmSig = (void *) p_elmSuc;
		SElmEncadenarAntecesor ( p_elmSuc, p_elmObj );
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmDesencadenarAntecesor ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_elmAnt ) )
		{
			SElmDesencadenarSucesor ( (SElemento *) p_elmObj->p_elmAnt );
		}
		p_elmObj->p_elmAnt = NULL;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmDesencadenarSucesor ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_elmSig ) )
		{
			SElmDesencadenarAntecesor ( (SElemento *) p_elmObj->p_elmSig );
		}
		p_elmObj->p_elmSig = NULL;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int SElmDesencadenar ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		if ( ES_VALIDO ( p_elmObj->p_elmSig ) )
		{
			SElmDesencadenarAntecesor ( (SElemento *) p_elmObj->p_elmSig );
		}
		if ( ES_VALIDO ( p_elmObj->p_elmAnt ) )
		{
			SElmDesencadenarSucesor ( (SElemento *) p_elmObj->p_elmAnt );
		}

		p_elmObj->p_elmAnt = NULL;
		p_elmObj->p_elmSig = NULL;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

int	SElmLiberacionMemoriaActivada ( SElemento * p_elmObj )
{
	int iRes;

	if ( ES_VALIDO ( p_elmObj ) )
	{
		iRes = p_elmObj->iLiberar;
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}

// NOTA:Retorna un elemento duplicado pero desencadenado:
SElemento * SElmDuplicar ( SElemento * p_elmObj )
{
	SBloque *	p_blqDatos;
	SElemento * p_elmDup;

	if ( SElmEsValido ( p_elmObj ) == 1 )
	{
		p_blqDatos = p_elmObj->p_blqDatos;
		if ( ES_VALIDO ( p_blqDatos ) )
		{
			p_elmDup = SElmCrear ( SBlqTam ( p_blqDatos ) );
			if ( ES_VALIDO ( p_elmDup ) )
			{
				p_elmDup->p_blqDatos = SBlqDuplicar ( p_blqDatos );
				p_elmDup->iLiberar = 1;
			}
		}
		else
		{
			p_elmDup = NULL;
		}
	}
	else
	{
		p_elmDup = NULL;
	}
	return ( p_elmDup );
}


