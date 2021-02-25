/*
  ==============================================================================

    KAPMainPanel.h
    Created: 25 Feb 2021 12:38:24am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
        : public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAdvancedPluginAudioProcessor&);
    ~KAPMainPanel();

private:
    std::unique_ptr<KAPTopPanel> topPanel_;
    std::unique_ptr<KAPGainPanel> inputGainPanel_;
    std::unique_ptr<KAPGainPanel> outputGainPanel_;
    std::unique_ptr<KAPCenterPanel> centerPanel_;
};