/*
  ==============================================================================

    KAPhelper.h
    Created: 21 Feb 2021 2:24:21pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#define kParamSmoothCoeff_Generic 0.04
#define kParamSmoothCoeff_Fine 0.002

constexpr static int MAX_BUFFER_SIZE = 192000;
const static double kPI = 3.14159265359;
const static double k2PI = 6.28318530718;


inline float kap_linear_interp (float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}
