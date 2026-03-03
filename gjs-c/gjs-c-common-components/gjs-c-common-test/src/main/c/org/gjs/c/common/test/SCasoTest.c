#include "SCasoTest.h"
#include "CTestConfig.h"



SCasoTest * SCasTstCrear ( const char * p_cId, PFUNINTV p_fTest )
{
	SCasoTest * p_caststObj;

	if ( CadEsToken ( p_cId ) && ES_VALIDO ( p_fTest ) )
	{
		p_caststObj = ( SCasoTest * ) MemReservar ( sizeof ( SCasoTest ) );
		if ( ES_VALIDO ( p_caststObj ) )
		{
			p_caststObj->p_cIdCaso = CadDuplicar ( p_cId );
			p_caststObj->p_fTestCaso = p_fTest;
		}
	}
	else
	{
		p_caststObj = NULL;
	}
	return ( p_caststObj );
}


void SCasTstDestruir ( SCasoTest ** p_p_caststObj )
{
	SCasoTest * p_caststObj;

	if ( ES_VALIDO ( p_p_caststObj ) )
	{
		p_caststObj = *p_p_caststObj;
		if ( ES_VALIDO ( p_caststObj ) )
		{
			MemLiberar ( ( void ** ) &( p_caststObj->p_cIdCaso ) );
		}
		*p_p_caststObj = NULL;
	}
}

char * SCasTstObtenerId ( SCasoTest * p_caststObj ) 
{
	char * p_cRes;

	if ( ES_VALIDO ( p_caststObj ) )
	{
		p_cRes = p_caststObj->p_cIdCaso;
	}
	else
	{
		p_cRes = NULL;
	}
	return ( p_cRes );
}

int SCasTstEjecutar ( SCasoTest * p_caststObj )
{
	int iRes;

	if ( ES_VALIDO ( p_caststObj ) )
	{
		iRes = RESULTADO_CASO_TEST_OK;
		AplicLogAnotar( "" );
		AplicLogAnotar ( "-Caso %s:", p_caststObj->p_cIdCaso );
		if ( ES_VALIDO ( p_caststObj->p_fTestCaso ) )
		{
			if ( p_caststObj->p_fTestCaso() == 0)
			{
				iRes = RESULTADO_CASO_TEST_KO;
			}
		}
		else
		{
			AplicLogAnotarError ( "Funcion no definida para el caso" );
			iRes = RESULTADO_CASO_TEST_FAIL;
		}
	}
	else
	{
		iRes = RESULTADO_CASO_TEST_FAIL;
	}
	if ( iRes == RESULTADO_CASO_TEST_OK )
	{
		AplicLogAnotar ( "Caso terminado correctamente" );
	}
	else
	{
		AplicLogAnotarError ( "Caso terminado con errores" );
	}
	return ( iRes );
}		
