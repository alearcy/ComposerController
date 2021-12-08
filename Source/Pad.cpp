#include <JuceHeader.h>
#include "Pad.h"
#include "Utilities.h"

//==============================================================================
Pad::Pad()
{
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
    button.setBounds(0, 0, getWidth(), getHeight() - 50);
    resizableCorner.setBounds(getWidth() - 20, getHeight() - 20, 15, 15);
    //setTopLeftPosition(20, 90);
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