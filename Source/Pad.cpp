#include <JuceHeader.h>
#include "Pad.h"
#include "Utilities.h"

//==============================================================================
Pad::Pad(juce::ValueTree& v)
{
    init(v, "Pad");
}

Pad::Pad(juce::ValueTree& v, juce::String name)
{
    init(v, name);
}

Pad::~Pad()
{
    button.setLookAndFeel(nullptr);
}

void Pad::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::white);
}

void Pad::resized()
{
    button.setBounds(getLocalBounds());
    resizableCorner.setBounds(button.getWidth() - 15, button.getHeight() - 15, 15, 15);
    dragComponent.setBounds(5, button.getHeight() - 20, 15, 15);
}

void Pad::init(juce::ValueTree& v, juce::String name)
{
    v.addListener(this);
    // add mouse lister to the resizable corner and drag components
    resizableCorner.addMouseListener(this, false);
    dragComponent.addMouseListener(this, false);
    // create constraints for resize and position
    movableConstraints.setMinimumOnscreenAmounts(padHeight, padWidth, padHeight, padWidth);
    resizableConstraints.setMinimumSize(padWidth, padHeight);
    resizableConstraints.setMaximumSize(padWidth * 2, padHeight * 2);

    // create resizable corner component to add to pad
    if (isEditingMode)
    {
        addAndMakeVisible(resizableCorner);
        addAndMakeVisible(dragComponent);
        button.setEnabled(false);
    }

    addAndMakeVisible(button);
    button.setLookAndFeel(&buttonCustomStyle);
    button.setButtonText(name);
    button.setColour(juce::TextButton::buttonColourId, color);


}

void Pad::mouseDown(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        if (event.eventComponent == &dragComponent)
        {
            dragComponent.startDraggingComponent(this, event);
        }
    }
}

void Pad::mouseDrag(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        if (event.eventComponent == &dragComponent)
        {
            dragComponent.dragComponent(this, event, &movableConstraints);
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
        addAndMakeVisible(dragComponent);
        button.setEnabled(false);
    }
    else
    {
        resizableCorner.setVisible(false);
        dragComponent.setVisible(false);
        button.setEnabled(true);
    }
}