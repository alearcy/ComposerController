/*
  ==============================================================================

    Fader.h
    Created: 16 Nov 2021 7:35:16pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Config.h"


//==============================================================================
/*
*/

class Fader  : public juce::Component, 
               public juce::ValueTree::Listener,
               public juce::ComponentDragger
{
public:
    Fader(juce::ValueTree& v);
 
    Fader(juce::ValueTree& v, juce::String name);
    
    ~Fader() override;

    void paint (juce::Graphics&) override;
    //void sendMidiMessage()
    void resized() override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;

    // properties
    juce::Label faderLabel;
    juce::String id; // exadecimal ID
    juce::String tabId; // tab where is created on
    int midiChannel = 1; // midi channel
    int ccNumber; // cc number like cc11
    int ccValue; // cc value like 127
    int minValue = 0;
    int maxValue = 127;
    Config::MidiType midiType = Config::MidiType::CONTROLCHANGE;
    juce::Colour color = juce::Colours::coral; // default fader color
    int faderWidth = Config::ComponentSizes::FADERWIDTH;
    int faderHeight = Config::ComponentSizes::FADERHEIGHT;


private:
    void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::ComponentBoundsConstrainer movableConstraints;
    juce::ComponentBoundsConstrainer resizableConstraints;
    juce::ResizableCornerComponent resizableCorner = juce::ResizableCornerComponent(this, &resizableConstraints);
    juce::Slider slider;
    void init(juce::ValueTree& v, juce::String name);
    bool isEditingMode = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Fader)
};
