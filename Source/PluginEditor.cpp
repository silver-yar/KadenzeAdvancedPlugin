/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KadenzeAdvancedPluginAudioProcessorEditor::KadenzeAdvancedPluginAudioProcessorEditor (KadenzeAdvancedPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    mainPanel_ = std::make_unique<KAPMainPanel> (audioProcessor);
    addAndMakeVisible (mainPanel_.get());
}

KadenzeAdvancedPluginAudioProcessorEditor::~KadenzeAdvancedPluginAudioProcessorEditor()
{
}

//==============================================================================
void KadenzeAdvancedPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void KadenzeAdvancedPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
