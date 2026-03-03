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
	SSampleType * p_smpObj;
	
	p_smpObj = (SSampleType *) MemReservar ( sizeof ( SSampleType ) );
	if ( ES_VALIDO ( p_smpObj ) )
	{
		// Inicializar atributos
	}
	return ( p_smpObj );
}

void SSmpDestruir ( SSampleType ** p_p_smpObj )
{
	SSampleType * p_smpObj;
	
	if ( ES_VALIDO ( p_p_smpObj ) )
	{
		p_smpObj = *p_p_smpObj;

		if ( ES_VALIDO ( p_smpObj ) )
		{
			MemLiberar ( (void **) p_p_smpObj );
		}
	}
}

int SSmpEsValido ( SSampleType * p_smpObj )
{
	int iRes;

	if ( ES_VALIDO ( p_smpObj ) )
	{
		// Condiciones de validez de los atributos
		if ( 1 = 1  )
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



