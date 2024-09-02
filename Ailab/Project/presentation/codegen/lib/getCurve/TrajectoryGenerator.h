//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// TrajectoryGenerator.h
//
// Code generation for function 'TrajectoryGenerator'
//

#ifndef TRAJECTORYGENERATOR_H
#define TRAJECTORYGENERATOR_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class TrajectoryGenerator {
public:
  TrajectoryGenerator();
  ~TrajectoryGenerator();
  void getCurve(double sf, double dtheta, double y_offset,
                coder::array<double, 2U> &s, coder::array<double, 2U> &l,
                coder::array<double, 2U> &dlds, coder::array<double, 2U> &ddlds,
                coder::array<double, 2U> &theta,
                coder::array<double, 2U> &kappa);
};

#endif
// End of code generation (TrajectoryGenerator.h)
