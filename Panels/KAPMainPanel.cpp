/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 25 Feb 2021 12:38:24am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPMainPanel.h"

KAPMainPanel::KAPMainPanel(KadenzeAdvancedPluginAudioProcessor& p)
        : KAPPanelBase (p)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    topPanel_ = std::make_unique<KAPTopPanel>(p);
    topPanel_ -> setTopLeftPosition (0, 0);
    addAndMakeVisible (topPanel_.get());

    inputGainPanel_ = std::make_unique<KAPGainPanel>(p);
    inputGainPanel_ -> setTopLeftPosition (0, TOP_PANEL_HEIGHT);
    addAndMakeVisible (inputGainPanel_.get());

    outputGainPanel_ = std::make_unique<KAPGainPanel>(p);
    outputGainPanel_ -> setTopLeftPosition (MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH,
                                            TOP_PANEL_HEIGHT);
    addAndMakeVisible (outputGainPanel_.get());

    centerPanel_ = std::make_unique<KAPCenterPanel>(p);
    centerPanel_ -> setTopLeftPosition (GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible (centerPanel_.get());
}

KAPMainPanel::~KAPMainPanel()
{

}
