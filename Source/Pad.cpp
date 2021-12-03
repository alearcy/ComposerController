/*
  ==============================================================================

    Pad.cpp
    Created: 28 Nov 2021 6:51:00pm
    Author:  arcid

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Pad.h"
#include "Utilities.h"

//==============================================================================
Pad::Pad()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    init("default");
}

Pad::Pad(juce::String name)
{
    init(name);
}

Pad::~Pad()
{

}

void Pad::paint (juce::Graphics& g)
{
    g.setFont(juce::Font(16.0f));
    g.setColour(juce::Colours::white);
    
}

void Pad::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    button.setBounds(0, 0, getWidth(), getHeight() - 50);
    setTopLeftPosition(20, 90);
}

void Pad::init(juce::String name)
{
    // create constraints for resize and position
    movableConstraints.setMinimumOnscreenAmounts(padHeight, padWidth, padHeight, padWidth);
    resizableConstraints.setMinimumSize(padWidth, padHeight);
    resizableConstraints.setMaximumSize(padWidth * 2, getParentHeight() - 35);

    // create resizable corner component to add to fader
    addAndMakeVisible(resizableCorner);

    addAndMakeVisible(button);
    button.setButtonText(name);
    button.setColour(juce::TextButton::buttonColourId, color);

    setSize(padWidth, padHeight);
    
}

void Pad::mouseDown(const juce::MouseEvent& event)
{
    startDraggingComponent(this, event);
}

void Pad::mouseDrag(const juce::MouseEvent& event)
{
    dragComponent(this, event, &movableConstraints);
    Utility::setRoundedPosition(*this, 20);
}