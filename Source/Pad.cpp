#include <JuceHeader.h>
#include "Pad.h"
#include "Utilities.h"

//==============================================================================
Pad::Pad(juce::ValueTree& store)
{
    init(store, "Pad");
}

Pad::Pad(juce::ValueTree& store, juce::String name)
{
    init(store, name);
}

Pad::~Pad()
{
    button.setLookAndFeel(nullptr);
}

void Pad::init(juce::ValueTree& store, juce::String name)
{
    i_store = store;
    i_store.addListener(this);
    // add mouse lister to the resizable corner and drag components
    resizableCorner.addMouseListener(this, false);
    dragComponent.addMouseListener(this, false);
    // create constraints for resize and position
    if (h != 0 && w != 0)
    {
        movableConstraints.setMinimumOnscreenAmounts(h, w, h, w);
        resizableConstraints.setMinimumSize(w, h);
        resizableConstraints.setMaximumSize(w * 2, h * 2);
    }

    addAndMakeVisible(button);
    button.setLookAndFeel(&buttonCustomStyle);
    button.setButtonText(name);
    button.setColour(juce::TextButton::buttonColourId, color);
}
//==============================================================================

void Pad::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::white);
}

void Pad::resized()
{
    if (isEditingMode)
    {
        addAndMakeVisible(resizableCorner);
        addAndMakeVisible(dragComponent);
        button.setEnabled(false);
    }
    button.setBounds(getLocalBounds());
    resizableCorner.setBounds(button.getWidth() - 15, button.getHeight() - 15, 15, 15);
    dragComponent.setBounds(5, button.getHeight() - 20, 15, 15);
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

void Pad::mouseUp(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        auto padsFromStore = i_store.getChildWithName("Pads");
        if (padsFromStore.getNumChildren() > 0)
        {
            for (auto& pad : padsFromStore)
            {
                if (pad.getProperty("id") == id)
                {
                    pad.setProperty("x", getBounds().getX(), nullptr);
                    pad.setProperty("y", getBounds().getY(), nullptr);
                    pad.setProperty("w", getBounds().getWidth(), nullptr);
                    pad.setProperty("h", getBounds().getHeight(), nullptr);

                }
            }
        }
    }
}

void Pad::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged,
    const juce::Identifier& property)
{
    if (property.toString() == "isEditing")
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
}