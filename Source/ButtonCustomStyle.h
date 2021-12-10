#pragma once
#include <JuceHeader.h>

class ButtonCustomStyle : public juce::LookAndFeel_V4
{
public:
    ButtonCustomStyle()
    {
        setColour(juce::Slider::thumbColourId, juce::Colours::red);
    }

    void drawButtonBackground(juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
        bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();

        g.setColour(isButtonDown ? backgroundColour.darker(0.5f) : backgroundColour);
        g.fillRect(buttonArea);

        g.fillRect(buttonArea);
    }

};