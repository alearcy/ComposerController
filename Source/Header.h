#pragma once

#include <JuceHeader.h>
#include "PadModal.h"

//==============================================================================
/*
*/
class Header  : public juce::Component 
                //public juce::ValueTree::Listener
{
public:
    Header(juce::ValueTree& store);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::TextButton editBtn { "Edit" };
    juce::TextButton addFader { "Add fader" };
    juce::TextButton addPad { "Add pad" };
    juce::TextButton openModal { "Open modal" };
    juce::Label logoName;
    bool isEditingMode;

private:
    //void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::DropShadower shadow = juce::DropShadower(juce::DropShadow());
    PadModal padModal;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
