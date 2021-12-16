/*
  ==============================================================================

    PadSettings.h
    Created: 16 Dec 2021 9:50:15pm
    Author:  arcid

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PadModal : public juce::Component
{
public:
    PadModal();
    ~PadModal() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PadModal)
};
