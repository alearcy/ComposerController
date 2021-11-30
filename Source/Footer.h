/*
  ==============================================================================

    Footer.h
    Created: 19 Nov 2021 6:57:19pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Footer  : public juce::Component
{
public:
    Footer();
    ~Footer() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Footer)
};
