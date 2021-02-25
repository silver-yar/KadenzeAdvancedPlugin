/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 25 Feb 2021 12:39:28am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPCenterPanelMenuBar.h"

class KAPCenterPanel
        : public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAdvancedPluginAudioProcessor&);
    ~KAPCenterPanel();

private:
    std::unique_ptr<KAPCenterPanelMenuBar> centerPanelMenuBar_;
};
