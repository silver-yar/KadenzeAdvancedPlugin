/*
  ==============================================================================

    KAPGain.cpp
    Created: 21 Feb 2021 2:24:36pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#include <JuceHeader.h>
#include "KAPGain.h"

KAPGain::KAPGain()
{

};
KAPGain::~KAPGain()
{

};

void KAPGain::process (float* audioIn, float gain, float* audioOut, float numSamplesToRender)
{
    auto gainMapped = juce::jmap(gain,-24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f);

    for (auto i = 0; i < numSamplesToRender; ++i)
    {
        audioOut[i] = audioIn[i] * gainMapped;
    }
};
