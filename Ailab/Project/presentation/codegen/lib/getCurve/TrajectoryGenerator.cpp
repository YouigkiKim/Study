//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// TrajectoryGenerator.cpp
//
// Code generation for function 'TrajectoryGenerator'
//

// Include files
#include "TrajectoryGenerator.h"
#include "div.h"
#include "getCurve_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
TrajectoryGenerator::TrajectoryGenerator() = default;

TrajectoryGenerator::~TrajectoryGenerator() = default;

void TrajectoryGenerator::getCurve(double sf, double dtheta, double y_offset,
                                   coder::array<double, 2U> &s,
                                   coder::array<double, 2U> &l,
                                   coder::array<double, 2U> &dlds,
                                   coder::array<double, 2U> &ddlds,
                                   coder::array<double, 2U> &theta,
                                   coder::array<double, 2U> &kappa)
{
  coder::array<double, 2U> Q;
  double apnd;
  double cdiff;
  double d;
  double d1;
  double ndbl;
  int nm1d2;
  if (std::isnan(sf)) {
    s.set_size(1, 1);
    s[0] = rtNaN;
  } else if (sf < 0.0) {
    s.set_size(1, 0);
  } else {
    ndbl = std::floor(sf / 0.1 + 0.5);
    apnd = ndbl * 0.1;
    cdiff = apnd - sf;
    if (std::abs(cdiff) < 4.4408920985006262E-16 * sf) {
      ndbl++;
      apnd = sf;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * 0.1;
    } else {
      ndbl++;
    }
    s.set_size(1, static_cast<int>(ndbl));
    if (static_cast<int>(ndbl) > 0) {
      s[0] = 0.0;
      if (static_cast<int>(ndbl) > 1) {
        s[static_cast<int>(ndbl) - 1] = apnd;
        nm1d2 = (static_cast<int>(ndbl) - 1) / 2;
        for (int k{0}; k <= nm1d2 - 2; k++) {
          cdiff = (static_cast<double>(k) + 1.0) * 0.1;
          s[k + 1] = cdiff;
          s[(static_cast<int>(ndbl) - k) - 2] = apnd - cdiff;
        }
        if (nm1d2 << 1 == static_cast<int>(ndbl) - 1) {
          s[nm1d2] = apnd / 2.0;
        } else {
          cdiff = static_cast<double>(nm1d2) * 0.1;
          s[nm1d2] = cdiff;
          s[nm1d2 + 1] = apnd - cdiff;
        }
      }
    }
  }
  ndbl = std::tan(dtheta);
  cdiff = sf * sf;
  apnd = -2.0 * ndbl / sf + 3.0 * y_offset / cdiff;
  cdiff = -(ndbl + 2.0 * apnd * sf) / (3.0 * cdiff);
  dlds.set_size(1, s.size(1));
  nm1d2 = s.size(1);
  l.set_size(1, s.size(1));
  for (int k{0}; k < nm1d2; k++) {
    d = s[k];
    d1 = d * d;
    dlds[k] = d1;
    l[k] = (ndbl * d + apnd * d1) + cdiff * rt_powd_snf(d, 3.0);
  }
  dlds.set_size(1, s.size(1));
  d = 2.0 * apnd;
  d1 = 3.0 * cdiff;
  nm1d2 = s.size(1) - 1;
  for (int k{0}; k <= nm1d2; k++) {
    dlds[k] = (ndbl + d * s[k]) + d1 * dlds[k];
  }
  ddlds.set_size(1, s.size(1));
  d1 = 6.0 * cdiff;
  nm1d2 = s.size(1);
  theta.set_size(1, dlds.size(1));
  Q.set_size(1, dlds.size(1));
  for (int k{0}; k < nm1d2; k++) {
    ddlds[k] = d + d1 * s[k];
    cdiff = dlds[k];
    theta[k] = std::atan(cdiff);
    Q[k] = cdiff * cdiff + 1.0;
  }
  nm1d2 = Q.size(1);
  for (int k{0}; k < nm1d2; k++) {
    Q[k] = std::sqrt(Q[k]);
  }
  if (ddlds.size(1) == Q.size(1)) {
    kappa.set_size(1, ddlds.size(1));
    nm1d2 = ddlds.size(1);
    for (int k{0}; k < nm1d2; k++) {
      cdiff = Q[k];
      kappa[k] = ddlds[k] / rt_powd_snf(cdiff, 3.0);
    }
  } else {
    binary_expand_op(kappa, ddlds, Q);
  }
}

// End of code generation (TrajectoryGenerator.cpp)
