#pragma once

#include <JuceHeader.h>
#include "ButtonCustomStyle.h"
//==============================================================================

class PadModal : public juce::Component, public juce::ChangeListener
{
public:
    PadModal(juce::String id, juce::String padToEdit, juce::String ccValueToEdit, juce::String ccNumberToEdit, juce::String colorToEdit);
    ~PadModal() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    

private:
    juce::TextEditor nameEditor;
    juce::TextEditor ccValueEditor;
    juce::TextEditor ccNumberEditor;
    juce::Label name;
    juce::Label ccValue;
    juce::Label ccNumber;
    juce::Label color;
    ButtonCustomStyle buttonCustomStyle;
    juce::TextButton saveButton;
    juce::TextButton colorSelector;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PadModal)
};