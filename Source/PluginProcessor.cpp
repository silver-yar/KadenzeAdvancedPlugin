/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KadenzeAdvancedPluginAudioProcessor::KadenzeAdvancedPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    init();
}

KadenzeAdvancedPluginAudioProcessor::~KadenzeAdvancedPluginAudioProcessor()
{
}

//==============================================================================
const juce::String KadenzeAdvancedPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KadenzeAdvancedPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAdvancedPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAdvancedPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KadenzeAdvancedPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KadenzeAdvancedPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KadenzeAdvancedPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KadenzeAdvancedPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String KadenzeAdvancedPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void KadenzeAdvancedPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void KadenzeAdvancedPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (auto i = 0; i < 2; ++i)
    {
        delay_[i]->setSampleRate (sampleRate);
        lfo_[i]->setSampleRate (sampleRate);
    }
}

void KadenzeAdvancedPluginAudioProcessor::releaseResources()
{
    for (auto i = 0; i < 2; ++i)
    {
        delay_[i]->reset();
        lfo_[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KadenzeAdvancedPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void KadenzeAdvancedPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
//        auto* cD = buffer.getReadPointer (channel);
        auto* channelData = buffer.getWritePointer (channel);

        gain_[channel]->process(channelData, 0.5f, channelData, (float) (buffer.getNumSamples()));

        // Chorus (Only applies to one channel to be chorus)
        auto rate = channel == 0 ? 0.0f : 0.25f;

        lfo_[channel]->process(rate, 0.5f, buffer.getNumSamples());

        delay_[channel]->process(channelData, 0.25f, 0.5f,
                                 0.35f, lfo_[channel]->getBuffer(),
                                 channelData, (float) (buffer.getNumSamples()));
    }
}

//==============================================================================
bool KadenzeAdvancedPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* KadenzeAdvancedPluginAudioProcessor::createEditor()
{
    return new KadenzeAdvancedPluginAudioProcessorEditor (*this);
}

//==============================================================================
void KadenzeAdvancedPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void KadenzeAdvancedPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void KadenzeAdvancedPluginAudioProcessor::init() {
    for (auto i = 0; i < 2; ++i)
    {
        gain_[i] = std::make_unique<KAPGain>();
        delay_[i] = std::make_unique<KAPDelay>();
        lfo_[i] = std::make_unique<KAPLfo>();
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KadenzeAdvancedPluginAudioProcessor();
}
