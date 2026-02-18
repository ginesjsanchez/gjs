#include "ExpresionesRegulares.h"
#include "Cadenas.h"

#include "TextoConfig.h"




int ExpRegSeCumple ( const char * p_cExpReg, const char * p_cCadena )
{
	int				iRes;
	int				iCarReg;
	int				iCarCad;
	int				iTamReg;
	int				iTamCad;
	char			cReg;
	char			cCad;
	const char *	p_cSubExpReg;
	const char *	p_cSubCadena;
	char *			p_cSubExpRegAux;
	char *			p_cSubCadenaAux;
	int				iCumple;
	int				iLiteral;
	int				iIniSubPat;
	int				iFinSubPat;
	int				iSubPats;
	int				iCarIniSubPat;
	int				iCarFinSubPat;
	int				iIncCarCad;

	if ( ES_VALIDO ( p_cExpReg ) && ES_VALIDO ( p_cCadena ) )
	{
		iTamCad = CadLongitud ( p_cCadena );
		if ( iTamCad > 0 )
		{
			iTamReg = CadLongitud ( p_cExpReg );
			if ( ( iTamReg == 1 ) && ( p_cExpReg [ 0 ] == '*' ) )
			{
				iRes = 1;
			}
			else if ( iTamReg > 0 ) 
			{
				iCarCad = 0;
				iCarReg = 0;
				iIniSubPat = -1;
				iFinSubPat = -1;
				iCarIniSubPat = -1;
				iRes = 1;
				while ( ( iCarCad < iTamCad ) && ( iCarReg < iTamReg ) && ( iRes == 1 ) )
				{
					iLiteral = 0;
					cReg = p_cExpReg [ iCarReg ];
					if ( ( (int)cReg == ASCII_COMILLA_SIMPLE ) && ( iCarReg + 2 < iTamReg ) )
					{
						if ( p_cExpReg [ iCarReg + 2 ] == ASCII_COMILLA_SIMPLE ) 
						{
							cReg = p_cExpReg [ iCarReg + 1 ];
							iCarReg = iCarReg + 2;
							iLiteral = 1;
						}
					}
					else if ( cReg == '(' )
					{
						iSubPats = 1;
						iIniSubPat = iCarReg;
						iFinSubPat = iIniSubPat + 1;
						while ( ( iSubPats > 0 ) && ( iFinSubPat < iTamReg ) )
						{
							if ( ( p_cExpReg [ iFinSubPat ]== ASCII_COMILLA_SIMPLE ) && ( iFinSubPat + 2 < iTamReg ) )
							{
								if ( p_cExpReg [ iFinSubPat + 2 ] == ASCII_COMILLA_SIMPLE ) 
								{
									iFinSubPat = iFinSubPat + 2;
								}
							}
							else if ( p_cExpReg [ iFinSubPat ] == ')' ) 
							{
								iSubPats = iSubPats - 1;
							}
							else if ( p_cExpReg [ iFinSubPat ] == '(' ) 
							{
								iSubPats = iSubPats + 1;
							}
							iFinSubPat = iFinSubPat + 1;
						} 
						if ( ( iSubPats == 0 ) && ( iFinSubPat - iIniSubPat - 1 > 1 ) )
						{
							// Hay subpatron:
							iCarIniSubPat = iCarCad;
							iCarReg = iFinSubPat;
							if ( iCarReg < iTamReg ) 
							{
								cReg = p_cExpReg [ iCarReg ];
							}
							else
							{
								iRes = 0;
							}
						}
						else
						{
							iCarReg = iFinSubPat;
							cReg = p_cExpReg [ iCarReg ];
							iIniSubPat = -1;
							iFinSubPat = -1;
						}
					}

					if ( iCarReg < iTamReg ) 
					{
						cCad = p_cCadena [ iCarCad ];

						if ( iLiteral == 1 )
						{
							if ( cReg != cCad )
							{
								iRes = 0;
							}
						}
						else if ( cReg == '*' )
						{
							// Saltar posibles * seguidos:
							while ( ( cReg == '*' ) && ( iCarReg < iTamReg - 1 ) )
							{
								iCarReg = iCarReg + 1;
								cReg = p_cExpReg [ iCarReg ];
							} 

							// Si la espreg termina por * ya está.
							if ( cReg != '*' )
							{
								// Si no se verifica el resto de la cadena:
								p_cSubExpReg = &(p_cExpReg [ iCarReg ]);
								iIncCarCad = 0;
								iCumple = 0;
								while ( ( iRes == 1 ) && ( iCumple == 0 ) )
								{
									while ( ( iCarCad + iIncCarCad < iTamCad ) && ( iCumple == 0 ) )
									{
										p_cSubCadena = &(p_cCadena [ iCarCad  + iIncCarCad ]);
										if ( ExpRegSeCumple ( p_cSubExpReg, p_cSubCadena ) == 1 )
										{
											iCumple = 1;
										}
										iIncCarCad = iIncCarCad + 1;
									}
									if ( iCumple == 0 )
									{
										if ( p_cSubExpReg [ 0 ] == '(' )
										{
											iSubPats = 1;
											iFinSubPat = 1;
											while ( ( iSubPats > 0 ) && ( iFinSubPat + iCarReg < iTamReg ) )
											{
												if ( ( p_cSubExpReg [ iFinSubPat ]== ASCII_COMILLA_SIMPLE ) && ( iFinSubPat + iCarReg + 2 < iTamReg ) )
												{
													if (p_cSubExpReg [ iFinSubPat + 2 ] == ASCII_COMILLA_SIMPLE ) 
													{
														iFinSubPat = iFinSubPat + 2;
													}
												}
												else if ( p_cSubExpReg [ iFinSubPat ] == ')' ) 
												{
													iSubPats = iSubPats - 1;
												}
												else if ( p_cSubExpReg [ iFinSubPat ] == '(' ) 
												{
													iSubPats = iSubPats + 1;
												}
												iFinSubPat = iFinSubPat + 1;
											} 
											if ( iSubPats == 0 )
											{
												if ( iFinSubPat + iCarReg < iTamReg - 1 )
												{
													p_cSubExpReg = &(p_cExpReg [ iCarReg + iFinSubPat + 1 ]);
													iIncCarCad = 0;
												}
												else
												{
													iCumple = 1;
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
									}
								}
								if ( iCumple == 1 ) 
								{
									iCarCad = iTamCad;
									iCarReg = iTamReg;
								}
							}
						}
						else if ( cReg != '?' )
						{
							if ( cReg != cCad )
							{
								iRes = 0;
							}
						}

						iCarReg = iCarReg + 1;
						iCarCad = iCarCad + 1;
					}
				}

				if ( iRes == 1 )
				{
					if ( iCarReg < iTamReg )
					{
						while ( ( iCarReg < iTamReg ) && ( p_cExpReg [ iCarReg ] == '*' ) )
						{
							iCarReg = iCarReg + 1;
						} 
						if ( iCarReg < iTamReg )
						{
							iRes = 0;
						}
					}
					else if ( ( iCarCad < iTamCad ) && ( cReg != '*' ) )
					{
						iRes = 0;
					}
				}
				else if ( iIniSubPat >= 0 )
				{
					// Procesamiento con subpatrón:
					if ( iFinSubPat < iTamReg )
					{
						p_cSubExpReg = &(p_cExpReg [ iFinSubPat ]);
						iCumple = 0;
						iCarFinSubPat = iCarIniSubPat;
						while ( ( iCarFinSubPat < iTamCad ) && ( iCumple == 0 ) )
						{
							p_cSubCadena = &(p_cCadena [ iCarFinSubPat ]);
							if ( ExpRegSeCumple ( p_cSubExpReg, p_cSubCadena ) == 1 )
							{
								iCumple = 1;
							}
							else
							{
								iCarFinSubPat = iCarFinSubPat + 1;
							}
						}
					}
					else
					{
						iCumple = 1;
						iCarFinSubPat = iTamCad;
					}
					if ( iCumple == 1 )
					{
						// Comprobar repeticion subpatrón:
						p_cSubExpRegAux = CadExtraer ( p_cExpReg, iIniSubPat + 1, iFinSubPat - iIniSubPat - 2 );
						p_cSubCadenaAux = CadExtraer ( p_cCadena, iCarIniSubPat, iCarFinSubPat - iCarIniSubPat );
						if ( ES_VALIDO ( p_cSubExpRegAux ) && ES_VALIDO ( p_cSubCadenaAux ) )
						{
							iTamCad = CadLongitud ( p_cSubCadenaAux );
							iCarCad = 0;
							while ( ( iCumple == 1 ) && ( iCarCad < iTamCad ) )
							{
								iIncCarCad = ExpRegSeCumpleAlInicio ( p_cSubExpRegAux, &(p_cSubCadenaAux [ iCarCad ]) );
								if ( iIncCarCad > 0 )
								{
									iCarCad = iCarCad + iIncCarCad;
								}
								else
								{
									iCumple = 0;
								}
							}
							iRes = iCumple;
						}
						MemLiberar ( (void **) &p_cSubExpRegAux );
						MemLiberar ( (void **) &p_cSubCadenaAux );
					}
					else
					{
						iRes = 0;
					}
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}


int ExpRegSeCumpleAlInicio ( const char * p_cExpReg, const char * p_cCadena )
{
	int				iRes;
	int				iCarReg;
	int				iCarCad;
	int				iTamReg;
	int				iTamCad;
	char			cReg;
	char			cCad;
	const char *	p_cSubExpReg;
	const char *	p_cSubCadena;
	char *			p_cSubExpRegAux;
	char *			p_cSubCadenaAux;
	int				iCumple;
	int				iLiteral;
	int				iIniSubPat;
	int				iFinSubPat;
	int				iSubPats;
	int				iCarIniSubPat;
	int				iCarFinSubPat;
	int				iIncCarCad;

	if ( ES_VALIDO ( p_cExpReg ) && ES_VALIDO ( p_cCadena ) )
	{
		iTamCad = CadLongitud ( p_cCadena );
		if ( iTamCad > 0 )
		{
			iTamReg = CadLongitud ( p_cExpReg );
			if ( ( iTamReg == 1 ) && ( p_cExpReg [ 0 ] == '*' ) )
			{
				iRes = iTamCad;
			}
			else if ( iTamReg > 0 ) 
			{
				iCarCad = 0;
				iCarReg = 0;
				iIniSubPat = -1;
				iFinSubPat = -1;
				iCarIniSubPat = -1;
				iRes = 1;
				while ( ( iCarCad < iTamCad ) && ( iCarReg < iTamReg ) && ( iRes == 1 ) )
				{
					iLiteral = 0;
					cReg = p_cExpReg [ iCarReg ];
					if ( ( (int)cReg == ASCII_COMILLA_SIMPLE ) && ( iCarReg + 2 < iTamReg ) )
					{
						if ( p_cExpReg [ iCarReg + 2 ] == ASCII_COMILLA_SIMPLE ) 
						{
							cReg = p_cExpReg [ iCarReg + 1 ];
							iCarReg = iCarReg + 2;
							iLiteral = 1;
						}
					}
					else if ( cReg == '(' )
					{
						iSubPats = 1;
						iIniSubPat = iCarReg;
						iFinSubPat = iIniSubPat + 1;
						while ( ( iSubPats > 0 ) && ( iFinSubPat < iTamReg ) )
						{
							if ( ( p_cExpReg [ iFinSubPat ]== ASCII_COMILLA_SIMPLE ) && ( iFinSubPat + 2 < iTamReg ) )
							{
								if ( p_cExpReg [ iFinSubPat + 2 ] == ASCII_COMILLA_SIMPLE ) 
								{
									iFinSubPat = iFinSubPat + 2;
								}
							}
							else if ( p_cExpReg [ iFinSubPat ] == ')' ) 
							{
								iSubPats = iSubPats - 1;
							}
							else if ( p_cExpReg [ iFinSubPat ] == '(' ) 
							{
								iSubPats = iSubPats + 1;
							}
							iFinSubPat = iFinSubPat + 1;
						} 
						if ( ( iSubPats == 0 ) && ( iFinSubPat - iIniSubPat - 1 > 1 ) )
						{
							// Hay subpatron:
							iCarIniSubPat = iCarCad;
							iCarReg = iFinSubPat + 1;
							if ( iCarReg < iTamReg ) 
							{
								cReg = p_cExpReg [ iCarReg ];
							}
							else
							{
								iRes = 0;
							}
						}
						else
						{
							iIniSubPat = -1;
							iFinSubPat = -1;
						}
					}

					if ( iCarReg < iTamReg ) 
					{
						cCad = p_cCadena [ iCarCad ];

						if ( iLiteral == 1 )
						{
							if ( cReg != cCad )
							{
								iRes = 0;
							}
						}
						else if ( cReg == '*' )
						{
							// Saltar posibles * seguidos:
							while ( ( cReg == '*' ) && ( iCarReg < iTamReg - 1 ) )
							{
								iCarReg = iCarReg + 1;
								cReg = p_cExpReg [ iCarReg ];
							} 

							// Si la espreg termina por * ya está.
							if ( cReg != '*' )
							{
								// Si no se verifica el resto de la cadena:
								p_cSubExpReg = &(p_cExpReg [ iCarReg ]);

								iCumple = 0;
								while ( ( iCarCad < iTamCad ) && ( iCumple == 0 ) )
								{
									p_cSubCadena = &(p_cCadena [ iCarCad ]);
									if ( ExpRegSeCumple ( p_cSubExpReg, p_cSubCadena ) == 1 )
									{
										iCumple = 1;
									}
									iCarCad = iCarCad + 1;
								}

								// Debe finalizar siempre el bucle:
								if ( iCumple == 1 )
								{
									iCarCad = iTamCad;
									iCarReg = iTamReg;
								}
								else
								{
									iRes = 0;
								}
							}
						}
						else if ( cReg != '?' )
						{
							if ( cReg != cCad )
							{
								iRes = 0;
							}
						}

						iCarReg = iCarReg + 1;
						iCarCad = iCarCad + 1;
					}
				}

				if ( iRes == 1 )
				{
					if ( iCarReg < iTamReg )
					{
						while ( ( iCarReg < iTamReg ) && ( p_cExpReg [ iCarReg ] == '*' ) )
						{
							iCarReg = iCarReg + 1;
						} 
						if ( iCarReg < iTamReg )
						{
							iRes = 0;
						}
					}
					else if ( ( iCarCad < iTamCad ) && ( cReg == '*' ) )
					{
						iCarCad = iTamCad;
					}
					if ( iRes == 1 )
					{
						iRes = iCarCad;
					}
				}
				else if ( iIniSubPat >= 0 )
				{
					// Procesamiento con subpatrón:
					if ( iFinSubPat < iTamReg )
					{
						p_cSubExpReg = &(p_cExpReg [ iFinSubPat ]);
						iCumple = 0;
						iCarFinSubPat = iCarIniSubPat;
						while ( ( iCarFinSubPat < iTamCad ) && ( iCumple == 0 ) )
						{
							p_cSubCadena = &(p_cCadena [ iCarFinSubPat ]);
							iIncCarCad = ExpRegSeCumpleAlInicio ( p_cSubExpReg, p_cSubCadena );
							if ( iIncCarCad > 0 )
							{
								iRes = iCarFinSubPat + iIncCarCad;
								iCumple = 1;
							}
							else
							{
								iCarFinSubPat = iCarFinSubPat + 1;
							}
						}
					}
					else
					{
						iCumple = 1;
						iCarFinSubPat = iTamCad;
						iRes = iTamCad;
					}
					if ( iCumple == 1 )
					{
						// Comprobar repeticion subpatrón:
						p_cSubExpRegAux = CadExtraer ( p_cExpReg, iIniSubPat + 1, iFinSubPat - iIniSubPat - 2 );
						p_cSubCadenaAux = CadExtraer ( p_cCadena, iCarIniSubPat, iCarFinSubPat - iCarIniSubPat );
						if ( ES_VALIDO ( p_cSubExpRegAux ) && ES_VALIDO ( p_cSubCadenaAux ) )
						{
							iTamCad = CadLongitud ( p_cSubCadenaAux );
							iCarCad = 0;
							while ( ( iCumple == 1 ) && ( iCarCad < iTamCad ) )
							{
								iIncCarCad = ExpRegSeCumpleAlInicio ( p_cSubExpRegAux, &(p_cSubCadenaAux [ iCarCad ]) );
								if ( iIncCarCad > 0 )
								{
									iCarCad = iCarCad + iIncCarCad;
								}
								else
								{
									iCumple = 0;
								}
							}
							iRes = iCumple;
						}
						MemLiberar ( (void **) &p_cSubExpRegAux );
						MemLiberar ( (void **) &p_cSubCadenaAux );
					}
					else
					{
						iRes = 0;
					}
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
	}
	else
	{
		iRes = 0;
	}
	return ( iRes );
}
