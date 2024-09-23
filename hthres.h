#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define	MAXN			2048 		// max length of MCLT block
#define	C_EPS       	1e-16
#define	C_NCBANDS   	25			// No. of Bark subbands
#define	Dabs        	70.
#define	Rfac		  	10.			// dB masking @ same frequency
#define	Thmin		  	80.

#ifdef __cplusplus
extern "C" {
#endif

float thrabs( float f);
void hthres(float *Ht, float *X, int Nbands, long fs);

#ifdef __cplusplus
}
#endif
