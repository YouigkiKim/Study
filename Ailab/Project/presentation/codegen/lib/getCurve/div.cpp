//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// div.cpp
//
// Code generation for function 'div'
//

// Include files
#include "div.h"
#include "getCurve_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 2U> &in2,
                      const coder::array<double, 2U> &in4)
{
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  in1.set_size(1, in1.size(1));
  if (in4.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in4.size(1);
  }
  in1.set_size(in1.size(0), loop_ub);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in4.size(1) != 1);
  for (int i{0}; i < loop_ub; i++) {
    double varargin_1;
    varargin_1 = in4[i * stride_1_1];
    in1[i] = in2[i * stride_0_1] / rt_powd_snf(varargin_1, 3.0);
  }
}

// End of code generation (div.cpp)
