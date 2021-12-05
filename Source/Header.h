/*
  ==============================================================================

    Header.h
    Created: 19 Nov 2021 6:57:03pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Header  : public juce::Component
{
public:
    Header();
    ~Header() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::TextButton editBtn;
    juce::Label logoName;

private:
    juce::DropShadower shadow = juce::DropShadower(juce::DropShadow());
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
