/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 25 Feb 2021 12:38:43am
    Author:  Johnathan Handy

  ==============================================================================
*/

#include "KAPGainPanel.h"

KAPGainPanel::KAPGainPanel(KadenzeAdvancedPluginAudioProcessor& p)
        : KAPPanelBase (p)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

KAPGainPanel::~KAPGainPanel()
{

}
