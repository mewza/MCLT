MCLTReal v1.6
(c) 2025 Dmitry Boldyrev

Written by Dmitry Boldyrev with assistance of AI (claude.ai and GROK)

Forward / Reverse MCLT (Modulated complex lapped transform by H. Malvar) C++ class 
templatable with either a scalar or SIMD vector with NEON optimizations.

<b>NEW</b>: Added MCLTRealHybrid auto-optimizer class so you can continue constructing 
     MCLTReal with scalars or simd type vectors, and it will auto-optimize it with
     best possible vector SIMD to get maximum performane. So if you were to pass
     MCLTRealHybrid<float> it would actually process MCLTReal internally with simd_float8
     but you will see data resulting from forward transform as cmplxT<float>. So,
     this is essentially an optimizer class for float, simd_float2, simd_float4, double,
     simd_double2 types utilizing SIMD architecture. Only interface via real_mclt/mclt and
     real_imclt/imclt are supported at the moment.
     
Originally published by H. Malvar in 1999, see:

    H. Malvar, "A Modulated Complex Lapped Transform And Its Applications to Audio Processing". Proc. International Conference on Acoustics, Speech and Signal Processing, 1999.
    H. Malvar, "Fast Algorithm for the Modulated Complex Lapped Transform", IEEE Signal Processing Letters, vol. 10, No. 1, 2003.
    
  Features include:
    
        • Hybrid TDAC/COLA-based scaling with explicit overlap compensation
        • Supports arbitrary HOP sizes with proper WOLA (Weighted Overlap-Add)
        • Uses FFT-to-MCLT mapping for efficiency (based on FFTReal highly optimized and accurate FFT)
        • 3-buffer architecture for flexible overlap
        • Optimized overlap-add for common hop sizes
        • NEON optimizations

LICENSE: FREE for Commercial and non-commercial use, but would appreciate
credits in About box and/or documentation, or READMEs

This software is a PEACEWARE by using it you accept that this will not be used
for any purposes related to harming innocent people. Violation of the terms
of useage agreement will be punishable by GOD.
