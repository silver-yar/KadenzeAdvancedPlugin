/*
  ==============================================================================

    KAPdelay.cpp
    Created: 21 Feb 2021 2:25:08pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPDelay.h"
#include <JuceHeader.h>

KAPDelay::KAPDelay() : sampleRate_ (-1.0),
                       feedbackSample_ (0.0),
                       delayIndex_ (0),
                       timeSmoothed_ (0.0f)
{

}

KAPDelay::~KAPDelay()
{

}

void KAPDelay::reset()
{
    timeSmoothed_ = 0.0f ;
    juce::zeromem(buffer_, sizeof(double) * MAX_BUFFER_SIZE);
}

void KAPDelay::process (const float* audioIn,
              float delayTimeInSec,
              float feedback,
              float wetDry,
              float* modBufferIn,
              float* audioOut,
              float numSamplesToRender)
{
    const float wet = wetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = juce::jmap(feedback, 0.0f, 0.95f);

    // Block Level Smoothing (Not as good)
//    const double delayTimeMod = 0.003 + 0.002 * modBufferIn[0];
//    timeSmoothed_ -= kParamSmoothCoeff_Generic * (timeSmoothed_ - (delayTimeInSec * delayTimeMod));

    for (auto i = 0; i < numSamplesToRender; ++i)
    {
        const double delayTimeMod = delayTimeInSec + 0.002 * modBufferIn[i];
        timeSmoothed_ -= kParamSmoothCoeff_Fine * (timeSmoothed_ - delayTimeMod);

        const double delayTimeInSamples = timeSmoothed_ * sampleRate_;
        const double sample = getInterpolatedSample (delayTimeInSamples);

        buffer_[delayIndex_] = audioIn[i] + feedbackSample_ * feedbackMapped;
        feedbackSample_ = sample;

        audioOut[i] = audioIn[i] * dry + sample * wet;

        delayIndex_++;
        if (delayIndex_ >= MAX_BUFFER_SIZE)
        {
            delayIndex_ -= MAX_BUFFER_SIZE;
        }
    }
}

double KAPDelay::getInterpolatedSample(double delayTimeInSamples) {
    double readPosition = (double) delayIndex_ - delayTimeInSamples;

    if (readPosition < 0.0f)
    {
        readPosition += MAX_BUFFER_SIZE;
    }

    int index_y0 = (int) readPosition - 1;
    if (index_y0 <= 0)
    {
        index_y0 += MAX_BUFFER_SIZE;
    }

    int index_y1 = (int) readPosition;
    if (index_y1 > MAX_BUFFER_SIZE)
    {
        index_y1 -= MAX_BUFFER_SIZE;
    }

    const float sample_y0 = buffer_[index_y0];
    const float sample_y1 = buffer_[index_y1];
    const float t = readPosition - (int) readPosition;

    double sampleOut = kap_linear_interp(sample_y0, sample_y1, t);
    return sampleOut;
}
