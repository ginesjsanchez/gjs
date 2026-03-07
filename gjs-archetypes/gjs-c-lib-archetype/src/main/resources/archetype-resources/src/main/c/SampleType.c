#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
#set( $includeConfig = "${capitalizedName}Config.h")
#set( $subpackages = ${package.split(".")})
#set( $tagFile = "_" + ${package.replace('.','_').toUpperCase()} + "_" + ${shortName.toUpperCase()} + "_SAMPLE_H")

${symbol_pound}include "${includeConfig}"
${symbol_pound}include "SampleType.h"




SampleType * SmpCrear ()
{
	SampleType * p_smpObj;
	
	p_smpObj = (SampleType *) MemReservar ( sizeof ( SampleType ) );
	if ( ES_VALIDO ( p_smpObj ) )
	{
		// Inicializar atributos
		p_smpObj->iValue = 0;
	}
	return ( p_smpObj );
}

void SmpDestruir ( SampleType ** p_p_smpObj )
{
	SampleType * p_smpObj;
	
	if ( ES_VALIDO ( p_p_smpObj ) )
	{
		p_smpObj = *p_p_smpObj;

		if ( ES_VALIDO ( p_smpObj ) )
		{
			MemLiberar ( (void **) p_p_smpObj );
		}
	}
}

int SmpEsValido ( SampleType * p_smpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_smpObj ) )
	{
		// Condiciones de validez de los atributos
		if ( p_smpObj->iValue >= 0  )
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



