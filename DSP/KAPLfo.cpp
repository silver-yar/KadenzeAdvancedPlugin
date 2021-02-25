/*
  ==============================================================================

    KAPlfo.cpp
    Created: 21 Feb 2021 2:24:46pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPlfo.h"
#include "JuceHeader.h"

KAPLfo::KAPLfo()
{
    reset();
}

KAPLfo::~KAPLfo()
{

}

void KAPLfo::reset()
{
    phase_ = 0.0f;
    juce::zeromem(buffer_, sizeof(float) * MAX_BUFFER_SIZE);
}

void KAPLfo::process (float rateIn, float depthIn, int numSamples)
{
    const float rate = juce::jmap(rateIn, 0.01f, 10.0f);

    for (auto i = 0; i < numSamples; ++i) {
        phase_ += (rate / sampleRate_);


        if (phase_ > 1.0f) {
            phase_ -= 1.0f;
        }

        const float lfoPosition = sinf(phase_ * k2PI) * depthIn;
        buffer_[i] = lfoPosition;
    }
}
