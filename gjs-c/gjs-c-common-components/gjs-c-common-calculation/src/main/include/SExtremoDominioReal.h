#ifndef _ORG_GJS_C_CC_EXTREMODOMINIOREAL_H
#define _ORG_GJS_C_CC_EXTREMODOMINIOREAL_H







typedef struct
{
	int		iIncluido;
	int		iInfinito;
	double	dValor;

} SExtremoDominioReal;


SExtremoDominioReal * SExdRCrear ( double dValor, int iIncluido );
SExtremoDominioReal * SExdRCrearInfinito ();
SExtremoDominioReal * SExdRCrearMenosInfinito ();
void SExdRDestruir ( SExtremoDominioReal ** p_p_exdObj );

int SExdREsValido ( SExtremoDominioReal * p_exdObj );

double SExdRValor ( SExtremoDominioReal * p_exdObj );
int SExdREstaIncluido ( SExtremoDominioReal * p_exdObj );
int SExdREsInfinito ( SExtremoDominioReal * p_exdObj );
int SExdREsMenosInfinito ( SExtremoDominioReal * p_exdObj );

SExtremoDominioReal * SExdRDuplicar ( SExtremoDominioReal * p_exdObj );

#endif

