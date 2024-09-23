#include "fxform.h"
#include <string.h>
#include <math.h>

void mlt_sine_window(float *h, int n)
{
    int i; // [sp+Ch] [bp-4h]@1
    
    for ( i = 0; i < n; ++i )
        h[i] = sin(((double)i + 0.5) * (3.141592653589793 / (double)(2 * n)));
}

void fdctiv(float *x, int n)
{
    float v2; // ST30_4@3
    double v3; // st7@4
    float v4; // ST28_4@4
    float v5; // ST48_4@6
    float v6; // ST2C_4@6
    float v7; // ST48_4@6
    float v8; // ST48_4@9
    float v9; // ST2C_4@9
    float v10; // ST48_4@9
    float v11; // ST30_4@12
    int v12; // [sp+20h] [bp-2Ch]@1
    int v13; // [sp+20h] [bp-2Ch]@10
    int nfft; // [sp+24h] [bp-28h]@1
    float v15; // [sp+34h] [bp-18h]@4
    float v16; // [sp+34h] [bp-18h]@7
    float v17; // [sp+38h] [bp-14h]@4
    signed int v18; // [sp+3Ch] [bp-10h]@1
    int i; // [sp+3Ch] [bp-10h]@4
    int j; // [sp+3Ch] [bp-10h]@7
    signed int v21; // [sp+3Ch] [bp-10h]@10
    float v22; // [sp+40h] [bp-Ch]@4
    float v23; // [sp+40h] [bp-Ch]@7
    float v24; // [sp+44h] [bp-8h]@4
    
    nfft = n / 2;
    v18 = 1;
    v12 = n - 1;
    while ( v18 < nfft )
    {
        v2 = x[v18];
        x[v18] = x[v12];
        x[v12] = v2;
        v18 += 2;
        v12 -= 2;
    }
    v3 = sqrt(2.0 / (double)n);
    v4 = v3;
    v22 = cos(3.141592653589793 / (double)(4 * n)) * v3;
    v15 = sin(3.141592653589793 / (double)(4 * n)) * -v4;
    v17 = cos(3.141592653589793 / (double)n);
    v24 = -sin(3.141592653589793 / (double)n);
    for ( i = 0; i < n; i += 2 )
    {
        v5 = x[i];
        v6 = x[i + 1];
        x[i] = v22 * v5 - v15 * v6;
        x[i + 1] = v22 * v6 + v15 * v5;
        v7 = v22;
        v22 = v17 * v22 - v24 * v15;
        v15 = v17 * v15 + v24 * v7;
    }
    fft(x, nfft);
    v23 = v17;
    v16 = v24;
    x[1] = -x[1];
    for ( j = 2; j < n; j += 2 )
    {
        v8 = x[j];
        v9 = x[j + 1];
        x[j] = v23 * v8 - v16 * v9;
        x[j + 1] = -v23 * v9 - v16 * v8;
        v10 = v23;
        v23 = v17 * v23 - v24 * v16;
        v16 = v17 * v16 + v24 * v10;
    }
    v21 = 1;
    v13 = n - 1;
    while ( v21 < nfft )
    {
        v11 = x[v21];
        x[v21] = x[v13];
        x[v13] = v11;
        v21 += 2;
        v13 -= 2;
    }
}

void fdstiv(float *x, int n)
{
    float v2;
    float v3;
    double v4;
    float v5;
    float v6;
    float v7;
    float v8;
    float v9;
    float v10;
    float v11;
    float v12;
    int v13;
    int v14;
    int nfft;
    float v16;
    float v17;
    float v18;
    int v19;
    int i;
    int j;
    int k;
    int v23;
    float v24;
    float v25;
    float v26;
    
    nfft = n / 2;
    v19 = 1;
    v13 = n - 1;
    while ( v19 < nfft )
    {
        v2 = x[v19];
        x[v19] = x[v13];
        x[v13] = v2;
        v19 += 2;
        v13 -= 2;
    }
    for ( i = 0; i < n; i += 2 )
    {
        v3 = x[i];
        x[i] = x[i + 1];
        x[i + 1] = v3;
    }
    v4 = sqrt(2.0 / (double)n);
    v5 = v4;
    v24 = cos(3.141592653589793 / (double)(4.0 * n)) * v4;
    v16 = sin(3.141592653589793 / (double)(4.0 * n)) * -v5;
    v18 = cos(3.141592653589793 / (double)n);
    v26 = -sin(3.141592653589793 / (double)n);
    for ( j = 0; j < n; j += 2 )
    {
        v6 = x[j];
        v7 = x[j + 1];
        x[j] = v24 * v6 - v16 * v7;
        x[j + 1] = v24 * v7 + v16 * v6;
        v8 = v24;
        v24 = v18 * v24 - v26 * v16;
        v16 = v18 * v16 + v26 * v8;
    }
    fft(x, nfft);
    v25 = v18;
    v17 = v26;
    for ( k = 2; k < n; k += 2 )
    {
        v9 = x[k];
        v10 = x[k + 1];
        x[k] = v25 * v9 - v17 * v10;
        x[k + 1] = v25 * v10 + v17 * v9;
        v11 = v25;
        v25 = v18 * v25 - v26 * v17;
        v17 = v18 * v17 + v26 * v11;
    }
    v23 = 1;
    v14 = n - 1;
    while ( v23 < nfft )
    {
        v12 = x[v23];
        x[v23] = x[v14];
        x[v14] = v12;
        v23 += 2;
        v14 -= 2;
    }
}

void fimclt(float *Xc, float *Xs, float *x, float *ys, float *hs, int n)
{
    float v6; // ST14_4@3
    float v7; // ST1C_4@3
    int v8; // [sp+0h] [bp-14h]@1
    int v9; // [sp+4h] [bp-10h]@1
    int v10; // [sp+Ch] [bp-8h]@1
    
    v9 = n / 2;
    fdctiv(Xc, n);
    fdstiv(Xs, n);
    memcpy(ys, Xc, 4 * (n / 2));
    memcpy(Xc, &Xc[v9], 4 * v9);
    memcpy(&Xc[v9], &ys[v9], 4 * v9);
    memcpy(&ys[v9], ys, 4 * v9);
    memcpy(ys, Xs, 4 * (n / 2));
    memcpy(Xs, &Xs[v9], 4 * v9);
    memcpy(&Xs[v9], &ys[n], 4 * v9);
    memcpy(&ys[n], ys, 4 * (n / 2));
    v10 = 0;
    v8 = n - 1;
    while ( v10 < v9 )
    {
        v6 = hs[v10] * 0.5;
        v7 = hs[v8] * 0.5;
        x[v10] = v7 * Xc[v8] - v6 * Xc[v10];
        x[v8] = v7 * Xc[v10] + v6 * Xc[v8];
        x[v10] = v7 * Xs[v8] + v6 * Xs[v10] + x[v10];
        x[v8] = v7 * Xs[v10++] - v6 * Xs[v8] + x[v8];
        --v8;
    }
}


int brswap(float *a1, int a2)
{
    int result; // eax@1
    float v3; // ST10_4@4
    float v4; // ST10_4@4
    float v5; // ST10_4@4
    float v6; // ST10_4@4
    float v7; // ST10_4@5
    float v8; // ST10_4@5
    signed int v9; // [sp+0h] [bp-18h]@1
    int j; // [sp+8h] [bp-10h]@5
    int v11; // [sp+Ch] [bp-Ch]@1
    signed int i; // [sp+14h] [bp-4h]@1
    
    result = a2 + 2;
    v11 = a2 + 2;
    v9 = 0;
//    _printf("sizeof(float)=%d", sizeof(float));
    for ( i = 0; i < a2; i += 4 )
    {
        if ( i < v9 )
        {
            v3 = a1[i];
            a1[i] = a1[v9];
            a1[v9] = v3;
            v4 = a1[i+1];
            a1[i+1]=a1[v9+1];
            a1[v9+1] = v4;
            v5 = a1[v11+i];
            a1[v11+i] = a1[v11+v9];
            a1[v11+v9]=v5;
            v6 = a1[v11+i+1];
            a1[v11+i+1] = a1[v11+v9+1];
            a1[v11+v9+1]=v6;
        }
        v7 = a1[i+2];
        a1[i+2] = a1[a2+v9];
        a1[a2+v9]=v7;
        v8 = a1[i+3];
        a1[i+3] = a1[a2+v9+1];
        result = v8;
        a1[a2+v9+1] = v8;
        for ( j = a2 / 2; j <= v9; j /= 2 )
        {
            v9 -= j;
            result = j / 2;
        }
        v9 += j;
    }
    return result;
}


void fft(float *u, int nfft)
{
    int v2; // ST30_4@5
    float v3; // ST44_4@5
    float v4; // ST2C_4@5
    float v5; // ST44_4@5
    float v6; // ST2C_4@5
    int v7; // ST30_4@10
    float v8; // ST44_4@10
    float v9; // ST2C_4@10
    float v10; // ST44_4@10
    float v11; // ST2C_4@10
    float v12; // ST44_4@16
    float v13; // ST2C_4@16
    signed int k; // [sp+Ch] [bp-3Ch]@6
    int m; // [sp+Ch] [bp-3Ch]@14
    signed int i; // [sp+10h] [bp-38h]@1
    signed int v17; // [sp+14h] [bp-34h]@3
    float v18; // [sp+18h] [bp-30h]@1
    int j; // [sp+1Ch] [bp-2Ch]@3
    int l; // [sp+1Ch] [bp-2Ch]@8
    float v21; // [sp+20h] [bp-28h]@3
    float v22; // [sp+24h] [bp-24h]@3
    float v23; // [sp+28h] [bp-20h]@3
    int v24; // [sp+34h] [bp-14h]@1
    float v25; // [sp+38h] [bp-10h]@1
    float v26; // [sp+3Ch] [bp-Ch]@3
    float v27; // [sp+40h] [bp-8h]@3
    
    v25 = cos(3.141592653589793 / (double)nfft);
    v18 = sin(-3.141592653589793 / (double)nfft);
    v24 = 2 * nfft;
    for ( i = 2 * nfft; i > 4; i >>= 1 )
    {
        v17 = i >> 1;
        v21 = 1.0;
        v26 = 0.0;
        v22 = 1.0 - 2.0 * v18 * v18;
        v27 = 2.0 * v18 * v25;
        v25 = v22;
        v18 = v27;
        v23 = 2.0 * v27;
        for ( j = 0; j < v24; j += i )
        {
            v2 = v17 + j;
            v3 = u[j] - u[v17 + j];
            v4 = u[j + 1] - u[v17 + 1 + j];
            u[j] = u[j] + u[v17 + j];
            u[j + 1] = u[j + 1] + u[v17 + 1 + j];
            u[v2] = v3;
            u[v2 + 1] = v4;
            v5 = u[j + 2] - u[v17 + 2 + j];
            v6 = u[j + 3] - u[v17 + 3 + j];
            u[j + 2] = u[j + 2] + u[v17 + 2 + j];
            u[j + 3] = u[j + 3] + u[v17 + 3 + j];
            u[v2 + 2] = v22 * v5 - v27 * v6;
            u[v2 + 3] = v22 * v6 + v27 * v5;
        }
        for ( k = 4; k < v17; k += 4 )
        {
            v21 = v21 - v23 * v27;
            v26 = v23 * v22 + v26;
            v22 = v22 - v23 * v26;
            v27 = v23 * v21 + v27;
            for ( l = k; l < k + v24; l += i )
            {
                v7 = v17 + l;
                v8 = u[l] - u[v17 + l];
                v9 = u[l + 1] - u[v17 + 1 + l];
                u[l] = u[l] + u[v17 + l];
                u[l + 1] = u[l + 1] + u[v17 + 1 + l];
                u[v7] = v21 * v8 - v26 * v9;
                u[v7 + 1] = v21 * v9 + v26 * v8;
                v10 = u[l + 2] - u[v17 + 2 + l];
                v11 = u[l + 3] - u[v17 + 3 + l];
                u[l + 2] = u[l + 2] + u[v17 + 2 + l];
                u[l + 3] = u[l + 3] + u[v17 + 3 + l];
                u[v7 + 2] = v22 * v10 - v27 * v11;
                u[v7 + 3] = v22 * v11 + v27 * v10;
            }
        }
    }
    if ( i > 2 )
    {
        for ( m = 0; m < v24; m += 4 )
        {
            v12 = u[m] - u[m + 2];
            v13 = u[m + 1] - u[m + 3];
            u[m] = u[m] + u[m + 2];
            u[m + 1] = u[m + 1] + u[m + 3];
            u[m + 2] = v12;
            u[m + 3] = v13;
        }
    }
    if ( v24 > 4 ) {
        brswap(u, nfft);
    }
}

void fimlt(float *x, float *ys, float *hs, int n)
{
    float v4;
    float v5;
    float v6;
    int v7;
    int v8;
    int v9;
    
    v8 = n / 2;
    fdctiv(x, n);
    memcpy(ys, x, 4 * (n / 2));
    memcpy(x, &x[v8], 4 * v8);
    memcpy(&x[v8], &ys[v8], 4 * v8);
    memcpy(&ys[v8], ys, 4 * v8);
    v9 = 0;
    v7 = n - 1;
    while ( v9 < v8 )
    {
        v4 = hs[v9];
        v5 = hs[v7];
        v6 = v5 * x[v7] - v4 * x[v9];
        x[v7] = v5 * x[v9] + v4 * x[v7];
        x[v9++] = v6;
        --v7;
    }
}

void fmlt(float *x, float *ya, float *ha, int n)
{
    float v4;
    float v5;
    float v6;
    int v7;
    int v8;
    int v9;
    
    v8 = n / 2;
    v9 = 0;
    v7 = n - 1;
    while ( v9 < v8 )
    {
        v4 = ha[v9];
        v5 = ha[v7];
        v6 = v5 * x[v7] - v4 * x[v9];
        x[v7] = v5 * x[v9] + v4 * x[v7];
        x[v9++] = v6;
        --v7;
    }
    memcpy(ya, x, 4 * v8);
    memcpy(x, &x[v8], 4 * v8);
    memcpy(&x[v8], &ya[v8], 4 * v8);
    memcpy(&ya[v8], ya, 4 * v8);
    fdctiv(x, n);
}


void fmclt(float *Xc, float *Xs, float *x, float *ya, float *ha, int n)
{
    float v6;
    float v7;
    int v8;
    int v9;
    int v10;
    
   // _printf("fmclt\n");
    v9 = n / 2;
    v10 = 0;
    v8 = n - 1;
    while ( v10 < v9 )
    {
        v6 = ha[v10];
        v7 = ha[v8];
        Xc[v10] = v7 * x[v8]    - v6 * x[v10];
        Xc[v8]  = v7 * x[v10]   + v6 * x[v8];
        Xs[v10] = v7 * x[v8]    + v6 * x[v10];
        Xs[v8]  = v7 * x[v10]   - v6 * x[v8];
        v8--; v10++;
    }
    memcpy(ya, Xc, 4 * v9);
    memcpy(Xc, &Xc[v9], 4 * v9);
    memcpy(&Xc[v9], &ya[v9], 4 * v9);
    memcpy(&ya[v9], ya, 4 * v9);
    memcpy(ya, Xs, 4 * v9);
    memcpy(Xs, &Xs[v9], 4 * v9);
    memcpy(&Xs[v9], &ya[n], 4 * v9);
    memcpy(&ya[n], ya, 4 * v9);
    fdctiv(Xc, n);
    fdstiv(Xs, n);
}
