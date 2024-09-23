#include <stdio.h>
#include "hthres.h"


float thrabs(float f)
{
    float v1;
    double v2;
    double v3;
    double v4;
    
    v1 = f / 1000.0;
    v2 = pow((double)v1, -0.7) * 4.0;
    v3 = pow((double)v1 - 3.3, 2.0);
    v4 = v2 - exp((double)v3 * -0.6) * 6.5;
    return pow((double)v1, 3.5) * 0.0034 + v4;
}

#define _DWORD long

static int Bh[25] = {100, 200, 300, 400, 510, 630, 770, 920, 1080, 1270, 1480, 1720, 2000,2320, 2700, 3150, 3700, 4400, 5300, 6400, 7700, 9500, 12000, 15500, 22200 };
  // was:    22050};
static float Sbu[NFREQ];
static float ilow[NFREQ];
static float iup[NFREQ];
static float Sb[NFREQ];

float		fm_lookup[NFREQ];		// precomputed fletcher munson

void hthres(float *Ht, float *X, int Nbands, long fs)
{
    int i;
    int m;
    int n;
    int v8;
    int v9;
     int v10;
    float v11;
     int v12;
    float v13;
    float v14;
    float v15;
    int v16;
    int v17;
     int v18;
     int j;
     int k;
     int l;
    float v22;
    float v23;
    
    v10 = 0;
    v18 = 0;
    v16 = 0;
    while ( !v10 && v18 < 25 )
    {
        double v4 = ((double)Nbands + (double)Nbands) / (double)fs;
        v8 = ((int)(double)Bh[v18] * v4 + 0.5) - 1; // not sure
        if ( v8 > Nbands - 1 )
        {
            v8 = Nbands - 1;
            v10 = 1;
        }
        ilow[v18] = v16;
        iup[v18] = v8;

        v23 = 0.0;
        for ( i = v16; i <= v8; ++i )
            v23 = v23 + X[i];
        Sbu[v18] = log10(v23 / (double)(v8 - v16 + 1) + 1.0e-16) * 10.0 - 10.0;
        v16 = v8 + 1;
        ++v18;
    }
    v12 = v18;
    v13 = -100.0;
    for ( j = 0; j < 25; ++j )
        Sb[j] = Sbu[j];
    v11 = Sbu[0]; // dbx: [0] was: v11=Sbu
    for ( k = 0; k < v12; ++k )
    {
        if ( k >= v12 )
            v22 = -100.0;
        else
            v22 = Sbu[k + 1] - 25.0;
        if ( v11 > (double)v13 )
            v13 = v11;
        v13 = v13 - 10.0;
        if ( v13 > (double)Sb[k] )
            Sb[k] = v13;
        if ( v22 > (double)Sb[k] )
            Sb[k] = v22;
        v11 = Sbu[k];
    }
    //_printf("fm_lookup: %d\n", sizeof(fm_lookup));
    for ( l = 0; l < v12; ++l )
    {
        v17 = (int)ilow[l];
        v9 = (int)iup[l];
        v14 = 0.0;
        for ( m = v17; m <= v9; ++m )
            v14 += fm_lookup[m];
        v15 = v14 / ((double)(v9 - v17 + 1)) / 1.2 - 70.0;
        if ( Sb[l] < (double)v15 )
            Sb[l] = v15;
        if ( Sb[l] < -80.0 )
           Sb[l] = -80.0;
        Sb[l] = pow(10.0, (double)Sb[l] / 10.0);
        for ( n = v17; n <= v9; ++n )
            Ht[n] = Sb[l];
    }
}
