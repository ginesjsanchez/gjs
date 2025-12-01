#set($includeConfig = "${capitalizedName}Config.h")

#include "${includeConfig}"
#include "<SampleType.h>"

// Methods and functions implementation here
SampleType * SmpTypCrear ( const char * p_cName )
{
	SampleType * p_smpTypObj;

	if ( ES_VALIDO ( p_cName ) )
	{
		p_smpTypObj = (SampleType *) MemReservar ( sizeof ( SampleType ) );
		if ( ES_VALIDO ( p_smpTypObj ) )
		{
			p_smpTypObj->p_cName = CadDuplicar ( p_cName );
		}
	}
	else
	{
		p_smpTypObj = NULL;
	}
	return ( p_smpTypObj );
}

void SmpTypDestruir ( SampleType ** p_p_smpTypObj )
{
	SampleType * p_smpTypObj;

	if ( ES_VALIDO ( p_p_smpTypObj ) )
	{
		p_smpTypObj = * p_p_smpTypObj;
		if ( ES_VALIDO ( p_smpTypObj ) )
		{
			MemLiberar ( (void **) &(p_smpTypObj->p_cName [0]) );
			MemLiberar ( (void **) &p_smpTypObj );
		}
		* p_p_smpTypObj = NULL;
	}
}

const char * SmpTypGetName ( SampleType * p_smpTypObj )
{
	const char * p_cRes;

	if ( ES_VALIDO ( p_smpTypObj ) )
	{
		p_cRes = p_smpTypObj->p_cName;
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

void SmpTypSetName ( SampleType * p_smpTypObj, const char * p_cName )
{
	if ( ES_VALIDO ( p_smpTypObj ) )
	{
        p_smpTypObj->p_cName = CadDuplicar ( p_cName );
	}
}

