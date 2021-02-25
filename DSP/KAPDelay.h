/*
  ==============================================================================

    KAPDelay.h
    Created: 21 Feb 2021 2:25:08pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "../Helpers/KAPhelper.h"

class KAPDelay
{
public:
    KAPDelay();
    ~KAPDelay();

    void setSampleRate (float sampleRate) { sampleRate_ = sampleRate; }

    void reset();
    void process (const float* audioIn,
                  float delayTimeInSec,
                  float feedback,
                  float wetDry,
                  float* modBufferIn,
                  float* audioOut,
                  float numSamplesToRender);

private:
    double getInterpolatedSample (double delayTimeInSamples);

    double sampleRate_;
    double buffer_ [MAX_BUFFER_SIZE];
    double feedbackSample_;
    int delayIndex_;
    float timeSmoothed_;
};
