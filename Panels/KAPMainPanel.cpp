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
}

KAPMainPanel::~KAPMainPanel()
{

}
