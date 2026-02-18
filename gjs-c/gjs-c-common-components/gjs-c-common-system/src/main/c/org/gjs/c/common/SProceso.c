
#include "SProceso.h"

#include "SistemaConfig.h"





static void SPrcInicializar ( SProceso * p_prcObj );



SProceso * SPrcCrear ()
{
	SProceso * p_prcObj;
	
	p_prcObj = (SProceso *) MemReservar ( sizeof ( SProceso ) );
	if ( ES_VALIDO ( p_prcObj ) )
	{
		SPrcInicializar ( p_prcObj );
	}
	return ( p_prcObj );
}

void SPrcDestruir ( SProceso ** p_p_prcObj )
{
	SProceso * p_prcObj;
	
	if ( ES_VALIDO ( p_p_prcObj ) )
	{
		p_prcObj = *p_p_prcObj;
		if ( ES_VALIDO ( p_prcObj ) )
		{
			MemLiberar ( (void **) p_p_prcObj );
		}
	}
}



int SPrcPID ( SProceso * p_prcObj )
{
	int iRes;

	if ( ES_VALIDO ( p_prcObj ) )
	{
		iRes = p_prcObj->iPID;
	}
	else
	{
		iRes = -1;
	}
	return ( iRes );
}

void SPrcInicializar ( SProceso * p_prcObj )
{
	if ( ES_VALIDO ( p_prcObj ) )
	{
# if ( defined ( WIN ) )
		p_prcObj->iPID = (int) GetCurrentProcessId ();
# else
		p_prcObj->iPID = getpid ();
# endif
	}
}






