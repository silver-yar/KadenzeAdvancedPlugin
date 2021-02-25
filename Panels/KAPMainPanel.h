/*
  ==============================================================================

    KAPMainPanel.h
    Created: 25 Feb 2021 12:38:24am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPMainPanel
        : public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAdvancedPluginAudioProcessor&);
    ~KAPMainPanel();

    void paint(juce::Graphics& g) override;
private:
//    KadenzeAdvancedPluginAudioProcessor& audioProcessor_;
};