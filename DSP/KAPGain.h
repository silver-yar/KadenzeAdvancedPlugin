/*
  ==============================================================================

    KAPGain.h
    Created: 21 Feb 2021 2:24:36pm
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

class KAPGain
{
public:
    KAPGain();
    ~KAPGain();

    void process (float* audioIn, float gain, float* audioOut, float numSamplesToRender);
private:
};
