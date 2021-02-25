/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "../Panels/KAPMainPanel.h"

//==============================================================================
/**
*/
class KadenzeAdvancedPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KadenzeAdvancedPluginAudioProcessorEditor (KadenzeAdvancedPluginAudioProcessor&);
    ~KadenzeAdvancedPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    KadenzeAdvancedPluginAudioProcessor& audioProcessor;

    std::unique_ptr<KAPMainPanel> mainPanel_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeAdvancedPluginAudioProcessorEditor)
};
