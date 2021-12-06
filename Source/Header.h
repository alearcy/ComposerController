#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Header  : public juce::Component
{
public:
    Header(juce::ValueTree& v);
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::TextButton editBtn { "Edit" };
    juce::Label logoName;

private:
    juce::DropShadower shadow = juce::DropShadower(juce::DropShadow());
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
