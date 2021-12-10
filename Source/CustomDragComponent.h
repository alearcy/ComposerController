#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class CustomDragComponent  : public juce::Component, public juce::ComponentDragger
{
public:
    CustomDragComponent() {};
    ~CustomDragComponent() override {};

    void paint(juce::Graphics& g) override
    {
        g.setColour(juce::Colours::white);
        juce::Path path;
        path.addRectangle(getLocalBounds());
        juce::PathStrokeType pathStrokType(1.0);
        float dashedLenght[2];
        dashedLenght[0] = 4;
        dashedLenght[1] = 4;
        pathStrokType.createDashedStroke(path, path, dashedLenght, 2);
        g.strokePath(path, pathStrokType);

        g.fillAll(juce::Colour::fromRGBA(0, 0, 0, 1));

        g.setColour(juce::Colours::white);

    };
    void resized() override {};

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomDragComponent)
};
