/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 25 Feb 2021 12:39:48am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"

KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeAdvancedPluginAudioProcessor& p)
        : KAPPanelBase (p)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}

KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{

}

