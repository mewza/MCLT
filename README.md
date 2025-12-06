MCLTReal v1.61
(c) 2025 Dmitry Boldyrev

NEW (v1.61): Because of bugs in FFTReal assoicated w/ SQ2_2, the gains have 
             have been fixed / adjusted in MCLT to proper F_SQRT(2.0 / N) for
             both analysis and synthesis
             
Written by Dmitry Boldyrev with assistance of AI (claude.ai and GROK)

Forward / Reverse MCLT (Modulated complex lapped transform by H. Malvar) C++ class 
templatable with either a scalar or SIMD vector with NEON optimizations.

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
