#pragma once

#include <JuceHeader.h>
#include "Config.h"

//==============================================================================
/*
*/
class Pad  : public juce::Component,
             public juce::ComponentDragger,
             public juce::ValueTree::Listener
{
public:
    Pad(juce::ValueTree& v);
    Pad(juce::ValueTree& v, juce::String name);
    ~Pad() override;

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
    Config::MidiType midiType = Config::MidiType::NOTEON;
    juce::Colour color = juce::Colours::coral; // default fader color
    int padWidth = Config::ComponentSizes::PADWIDTH;
    int padHeight = Config::ComponentSizes::PADHEIGHT;

private:
    void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::ComponentBoundsConstrainer movableConstraints;
    juce::ComponentBoundsConstrainer resizableConstraints;
    juce::ResizableCornerComponent resizableCorner = juce::ResizableCornerComponent(this, &resizableConstraints);
    juce::TextButton button;
    void init(juce::ValueTree& v, juce::String name);
    bool isEditingMode = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pad)
};
