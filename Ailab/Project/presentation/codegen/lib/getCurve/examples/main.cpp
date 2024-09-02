//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include files
#include "main.h"
#include "TrajectoryGenerator.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static double argInit_real_T();

// Function Definitions
static double argInit_real_T()
{
  return 0.0;
}

int main(int, char **)
{
  TrajectoryGenerator *classInstance;
  classInstance = new TrajectoryGenerator;
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_getCurve(classInstance);
  delete classInstance;
  return 0;
}

void main_getCurve(TrajectoryGenerator *instancePtr)
{
  coder::array<double, 2U> ddlds;
  coder::array<double, 2U> dlds;
  coder::array<double, 2U> kappa;
  coder::array<double, 2U> l;
  coder::array<double, 2U> s;
  coder::array<double, 2U> theta;
  double sf_tmp;
  // Initialize function 'getCurve' input arguments.
  sf_tmp = argInit_real_T();
  // Call the entry-point 'getCurve'.
  instancePtr->getCurve(sf_tmp, sf_tmp, sf_tmp, s, l, dlds, ddlds, theta,
                        kappa);
}

// End of code generation (main.cpp)
