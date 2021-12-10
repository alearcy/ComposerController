/*
  ==============================================================================

    DragComponent.h
    Created: 10 Dec 2021 4:37:53pm
    Author:  arcid

  ==============================================================================
*/

#pragma once
#pragma once

#include <JuceHeader.h>
#include "Config.h"
#include "ButtonCustomStyle.h"

//==============================================================================
/*
*/
class DragComponent : public juce::Component,
                      public juce::ComponentDragger
{
public:
    DragComponent() 
    {
        button.setButtonText("M");
        addAndMakeVisible(button);
        setSize(20, 20);

    };
    ~DragComponent() override {};

    void paint(juce::Graphics& g) override
    {
        g.setColour(juce::Colours::white);
    };
    void resized() override {
        button.setBounds(getParentWidth(), getParentHeight(), 20, 20);
    };

private:
    //juce::ComponentBoundsConstrainer movableConstraints;
    juce::TextButton button;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DragComponent)
};
