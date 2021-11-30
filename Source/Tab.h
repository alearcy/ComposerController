/*
  ==============================================================================

    Tab.h
    Created: 19 Nov 2021 6:57:33pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Tab  : public juce::Component
{
public:
    Tab();
    ~Tab() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    juce::String id;

private:
    juce::DropShadower shadow = juce::DropShadower(juce::DropShadow());
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tab)
};
