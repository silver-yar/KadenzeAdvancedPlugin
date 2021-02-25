/*
  ==============================================================================

    KAPTopPanel.h
    Created: 25 Feb 2021 12:40:41am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel
        : public KAPPanelBase
{
public:
    KAPTopPanel(KadenzeAdvancedPluginAudioProcessor&);
    ~KAPTopPanel();

    void paint(juce::Graphics&) override;

private:
};
