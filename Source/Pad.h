/*
  ==============================================================================

    Pad.h
    Created: 28 Nov 2021 6:51:00pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Config.h"

//==============================================================================
/*
*/
class Pad  : public juce::Component,
             public juce::ComponentDragger
{
public:
    Pad();
    Pad(juce::String name);
    ~Pad() override;

    static int const padWidth = 120;
    static int const padHeight = 100;

    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;

    // properties
    juce::Label padLabel;
    juce::String id; // exadecimal ID
    juce::String tabId; // tab where is created on
    int midiChannel = 1; // midi channel
    int ccNumber; // cc number like cc11
    int ccValue; // cc value like 127
    MidiType midiType = MidiType::NoteOn;
    juce::Colour color = juce::Colours::coral; // default fader color

private:
    juce::ComponentBoundsConstrainer movableConstraints;
    juce::ComponentBoundsConstrainer resizableConstraints;
    juce::ResizableCornerComponent resizableCorner = juce::ResizableCornerComponent(this, &resizableConstraints);
    juce::TextButton button;
    void init(juce::String name);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pad)
};
