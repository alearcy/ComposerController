#include <JuceHeader.h>
#include <cmath>
#include "Fader.h"
#include "Utilities.h"

//==============================================================================
Fader::Fader(juce::ValueTree& v)
{
    init(v, "CC1");
}

Fader::Fader(juce::ValueTree& v, juce::String name)
{
    init(v, name);
}

Fader::~Fader()
{
}

void Fader::init(juce::ValueTree& v, juce::String name)
{
    v.addListener(this);
    // add mouse lister to the resizable corner
    resizableCorner.addMouseListener(this, false);
    dragComponent.addMouseListener(this, false);
    // create constraints for resize and position
    movableConstraints.setMinimumOnscreenAmounts(faderHeight, faderWidth, faderHeight, faderWidth);
    resizableConstraints.setMinimumSize(faderWidth, faderHeight);
    resizableConstraints.setMaximumSize(faderWidth * 2, getParentHeight() - 200);

    // create resizable corner component to add to fader
    if (isEditingMode)
    {
        addAndMakeVisible(resizableCorner);
        addAndMakeVisible(dragComponent);
        slider.setEnabled(false);
    }

    // create slider component
    addAndMakeVisible(slider);
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    slider.setTextBoxIsEditable(false);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50.0f, 20.0f);
    slider.setRange(minValue, maxValue, 1.0f);
    slider.setValue(ccValue);
    slider.setColour(juce::Slider::trackColourId, color);

    // create label
    addAndMakeVisible(faderLabel);
    faderLabel.setText(name, juce::NotificationType::dontSendNotification);
    faderLabel.setJustificationType(juce::Justification::centred);
    faderLabel.setColour(juce::Label::textColourId, juce::Colours::white);
}
//==============================================================================

void Fader::paint (juce::Graphics& g)
{
    g.setFont(juce::Font(16.0f));
    g.setColour(juce::Colours::white);
}

void Fader::resized()
{
    slider.setBounds(0, 0, getWidth(), getHeight() - 50);
    faderLabel.setBounds(10, getHeight() - 25, getWidth() - 20, 30);
    resizableCorner.setBounds(getWidth() - 20, getHeight() - 20, 15, 15);
    dragComponent.setBounds(5, slider.getHeight() - 20, 15, 15);
}

void Fader::mouseDown(const juce::MouseEvent& event)
{
    if (isEditingMode)
    {
        if (event.eventComponent == &dragComponent)
        {
            dragComponent.startDraggingComponent(this, event);
        }
    }
}

void Fader::mouseDrag(const juce::MouseEvent& event)
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

void Fader::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged,
    const juce::Identifier& property)
{
    auto value = (bool)(treeWhosePropertyHasChanged.getProperty(property));
    isEditingMode = value;
    if (value)
    {
        addAndMakeVisible(resizableCorner);
        addAndMakeVisible(dragComponent);
        slider.setEnabled(false);
    }
    else
    {
       resizableCorner.setVisible(false);
       dragComponent.setVisible(false);
       slider.setEnabled(true);
    }
}