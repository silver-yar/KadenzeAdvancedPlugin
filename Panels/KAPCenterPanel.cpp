/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 25 Feb 2021 12:39:28am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPCenterPanel.h"

KAPCenterPanel::KAPCenterPanel(KadenzeAdvancedPluginAudioProcessor& p)
        : KAPPanelBase (p)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);

    centerPanelMenuBar_ = std::make_unique<KAPCenterPanelMenuBar> (p);
    centerPanelMenuBar_ -> setTopLeftPosition (0,0);
    addAndMakeVisible (centerPanelMenuBar_.get());
}

KAPCenterPanel::~KAPCenterPanel()
{

}
