
#include "Bits.h"


byte ByMascaraBitsSuperiores ( int iNumBits )
{
	byte byMasc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte ) ) )
	{
		byMasc = 0xFF << iNumBits;
	}
	else
	{
		byMasc = 0x00;
	}
	return ( byMasc );
}

byte2 By2MascaraBitsSuperiores ( int iNumBits ) 
{
	byte2 by2Masc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte2 ) ) )
	{
		by2Masc = 0xFFFF << iNumBits;
	}
	else
	{
		by2Masc = 0x0000;
	}
	return ( by2Masc );
}

byte4 By4MascaraBitsSuperiores ( int iNumBits ) 
{
	byte4 by4Masc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte4 ) ) )
	{
		by4Masc = 0xFFFFFFFF << iNumBits;
	}
	else
	{
		by4Masc = 0x00000000;
	}
	return ( by4Masc );
}

byte ByMascaraBitsInferiores ( int iNumBits ) 
{
	byte byMasc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte ) ) )
	{
		byMasc = 0xFF >> ( sizeof ( byte ) - iNumBits );
	}
	else
	{
		byMasc = 0x00;
	}
	return ( byMasc );
}

byte2 By2MascaraBitsInferiores ( int iNumBits ) 
{
	byte2 by2Masc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte2 ) ) )
	{
		by2Masc = 0xFFFF >> ( sizeof ( byte2 ) - iNumBits );
	}
	else
	{
		by2Masc = 0x0000;
	}
	return ( by2Masc );
}

byte4 By4MascaraBitsInferiores ( int iNumBits ) 
{
	byte4 by4Masc;

	if ( ( iNumBits > 0 ) && ( iNumBits < sizeof ( byte4 ) ) )
	{
		by4Masc = 0xFFFFFFFF >> ( sizeof ( byte4 ) - iNumBits );
	}
	else
	{
		by4Masc = 0x00000000;
	}
	return ( by4Masc );
}

