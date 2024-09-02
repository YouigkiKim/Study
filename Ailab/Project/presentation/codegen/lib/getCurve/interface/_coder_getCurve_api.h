//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_getCurve_api.h
//
// Code generation for function 'getCurve'
//

#ifndef _CODER_GETCURVE_API_H
#define _CODER_GETCURVE_API_H

// Include files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void getCurve(real_T sf, real_T dtheta, real_T y_offset,
              coder::array<real_T, 2U> *s, coder::array<real_T, 2U> *l,
              coder::array<real_T, 2U> *dlds, coder::array<real_T, 2U> *ddlds,
              coder::array<real_T, 2U> *theta, coder::array<real_T, 2U> *kappa);

void getCurve_api(const mxArray *const prhs[3], int32_T nlhs,
                  const mxArray *plhs[6]);

void getCurve_atexit();

void getCurve_initialize();

void getCurve_terminate();

void getCurve_xil_shutdown();

void getCurve_xil_terminate();

#endif
// End of code generation (_coder_getCurve_api.h)
