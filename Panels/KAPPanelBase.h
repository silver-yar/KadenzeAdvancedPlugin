/*
  ==============================================================================

    KAPPanelBase.h
    Created: 25 Feb 2021 12:38:03am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "../Source/PluginProcessor.h"
#include "../Helpers/KAPInterfaceDefines.h"

class KAPPanelBase
        : public juce::Component
{
public:
    KAPPanelBase(KadenzeAdvancedPluginAudioProcessor&);
    ~KAPPanelBase();

    void paint(juce::Graphics& g) override;
protected:
    KadenzeAdvancedPluginAudioProcessor& audioProcessor_;
};
