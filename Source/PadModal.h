#pragma once

#include <JuceHeader.h>
#include "ButtonCustomStyle.h"
//==============================================================================

class PadModal : public juce::Component, public juce::ChangeListener
{
public:
    PadModal();
    ~PadModal() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    

private:
    juce::Label name;
    juce::Label ccValue;
    juce::Label ccNumber;
    juce::Label color;
    juce::TextEditor nameEditor;
    juce::TextEditor ccValueEditor;
    juce::TextEditor ccNumberEditor;
    ButtonCustomStyle buttonCustomStyle;
    juce::TextButton saveButton;
    juce::TextButton colorChange;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PadModal)
};