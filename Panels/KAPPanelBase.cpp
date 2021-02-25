/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 25 Feb 2021 12:38:03am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPPanelBase.h"

KAPPanelBase::KAPPanelBase(KadenzeAdvancedPluginAudioProcessor& p) : audioProcessor_ (p)
{

};

KAPPanelBase::~KAPPanelBase()
{

};

void KAPPanelBase::paint(juce::Graphics& g)
{
    // BG
    g.fillAll(juce::Colours::whitesmoke);

    // Border
    g.setColour(juce::Colours::black);
    g.drawRect(1, 1, getWidth() - 1, getHeight() - 1, 2);
};
