#include "CommonSupportConfig.h"
#include "Calculo.h"

#include <cstdlib>
#include <random>



using namespace std;


namespace org
{
	namespace gjs
	{
		namespace cpp
		{
            namespace common
            {

const double EPSILON = numeric_limits<double>::epsilon();

double Epsilon()
{
	return ( EPSILON );
}

double GenerarNumeroAleatorio()
{
    srand ( time(0) );
    int iNumAl = rand();
	return ( iNumAl / RAND_MAX );
}


bool EsIgual( double dA, double dB )
{
	return ( fabs( dA - dB ) <= EPSILON );
}

bool EsMayor( double dA, double dB )
{
	return ( fabs( dA - dB ) > EPSILON );
}

bool EsMenor( double dA, double dB )
{
	return ( fabs( dB - dA ) > EPSILON );
}

 			}
		}
	}
}
