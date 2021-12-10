#include <JuceHeader.h>
#include "Pad.h"
#include "Utilities.h"

//==============================================================================
Pad::Pad(juce::ValueTree& v)
{
    init(v, "default");
}

Pad::Pad(juce::ValueTree& v, juce::String name)
{
    init(v, name);
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
    
}

void Pad::init(juce::ValueTree& v, juce::String name)
{
    v.addListener(this);
    // add mouse lister to the resizable corner
    resizableCorner.addMouseListener(this, false);
    // create constraints for resize and position
    movableConstraints.setMinimumOnscreenAmounts(padHeight, padWidth, padHeight, padWidth);
    resizableConstraints.setMinimumSize(padWidth, padHeight);
    resizableConstraints.setMaximumSize(padWidth * 2, padHeight * 2);

    // create resizable corner component to add to pad
    if (isEditingMode)
        addAndMakeVisible(resizableCorner);


    addAndMakeVisible(button);
    button.setButtonText(name);
    button.setColour(juce::TextButton::buttonColourId, color);
    
}

void Pad::mouseDown(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        if (event.eventComponent == this)
        {
            startDraggingComponent(this, event);
        }
    }
}

void Pad::mouseDrag(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        if (event.eventComponent == this)
        {
            dragComponent(this, event, &movableConstraints);
            Utility::setRoundedPosition(*this, 20);
        }
        if (event.eventComponent == &resizableCorner)
        {
            Utility::setRoundedSizes(*this, 20);
        }
    }
}

void Pad::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged,
    const juce::Identifier& property)
{
    auto value = (bool)(treeWhosePropertyHasChanged.getProperty(property));
    isEditingMode = value;
    if (value)
    {
        addAndMakeVisible(resizableCorner);
    }
    else
    {
        resizableCorner.setVisible(false);
    }
}