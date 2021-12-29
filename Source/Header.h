#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Header  : public juce::Component 
{
public:
    Header(juce::ValueTree& store);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::TextButton editBtn { "Edit" };
    juce::TextButton addFader { "Add fader" };
    juce::TextButton addPad{ "Add pad" };
    juce::Label logoName;
    bool isEditingMode;

private:
    //void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::DropShadower shadow = juce::DropShadower(juce::DropShadow());
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
