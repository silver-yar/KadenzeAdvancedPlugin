/*
  ==============================================================================

    KAPlfo.h
    Created: 21 Feb 2021 2:24:46pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "../Helpers/KAPhelper.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();

    void setSampleRate (float sampleRate) { sampleRate_ = sampleRate; }
    float* getBuffer() { return buffer_; };

    void reset();
    void process (float rateIn,
                  float depthIn,
                  int numSamples);

private:
    double sampleRate_;
    float phase_;
    float buffer_ [MAX_BUFFER_SIZE];
};
