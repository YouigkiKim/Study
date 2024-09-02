//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_getCurve_api.cpp
//
// Code generation for function 'getCurve'
//

// Include files
#include "_coder_getCurve_api.h"
#include "_coder_getCurve_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "getCurve",                                           // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

void getCurve_api(const mxArray *const prhs[3], int32_T nlhs,
                  const mxArray *plhs[6])
{
  coder::array<real_T, 2U> ddlds;
  coder::array<real_T, 2U> dlds;
  coder::array<real_T, 2U> kappa;
  coder::array<real_T, 2U> l;
  coder::array<real_T, 2U> s;
  coder::array<real_T, 2U> theta;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T dtheta;
  real_T sf;
  real_T y_offset;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  sf = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "sf");
  dtheta = emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "dtheta");
  y_offset = emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "y_offset");
  // Invoke the target function
  getCurve(sf, dtheta, y_offset, s, l, dlds, ddlds, theta, kappa);
  // Marshall function outputs
  s.no_free();
  plhs[0] = emlrt_marshallOut(s);
  if (nlhs > 1) {
    l.no_free();
    plhs[1] = emlrt_marshallOut(l);
  }
  if (nlhs > 2) {
    dlds.no_free();
    plhs[2] = emlrt_marshallOut(dlds);
  }
  if (nlhs > 3) {
    ddlds.no_free();
    plhs[3] = emlrt_marshallOut(ddlds);
  }
  if (nlhs > 4) {
    theta.no_free();
    plhs[4] = emlrt_marshallOut(theta);
  }
  if (nlhs > 5) {
    kappa.no_free();
    plhs[5] = emlrt_marshallOut(kappa);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void getCurve_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  getCurve_xil_terminate();
  getCurve_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void getCurve_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void getCurve_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (_coder_getCurve_api.cpp)
