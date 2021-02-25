/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 25 Feb 2021 12:40:41am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeAdvancedPluginAudioProcessor& p)
        : KAPPanelBase (p)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

KAPTopPanel::~KAPTopPanel()
{

}

void KAPTopPanel::paint(juce::Graphics& g)
{
    KAPPanelBase::paint (g);

    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth() - 10,
                     getHeight(), juce::Justification::centredRight, 1);
}

