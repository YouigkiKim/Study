//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_getCurve_mex.h
//
// Code generation for function 'getCurve'
//

#ifndef _CODER_GETCURVE_MEX_H
#define _CODER_GETCURVE_MEX_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_getCurve_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs,
                                 const mxArray *prhs[3]);

#endif
// End of code generation (_coder_getCurve_mex.h)
