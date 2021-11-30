/*
  ==============================================================================

    Fader.cpp
    Created: 16 Nov 2021 7:35:16pm
    Author:  arcid

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Fader.h"

//==============================================================================
Fader::Fader()
{
    init("default");
}

Fader::Fader(juce::String name)
{
    init(name);
}

Fader::~Fader()
{
}

void Fader::init(juce::String name)
{
    // create constraints for resize and position
    movableConstraints.setMinimumOnscreenAmounts(faderHeight, faderWidth, faderHeight, faderWidth);
    resizableConstraints.setMinimumSize(faderWidth, faderHeight);
    resizableConstraints.setMaximumSize(faderWidth * 2, getParentHeight() - 200);

    // create resizable corner component to add to fader
    addAndMakeVisible(resizableCorner);

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

    // set fader sizes from default values
    setSize(faderWidth, faderHeight);
}


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
    setTopLeftPosition(20, 90);
}

void Fader::mouseDown(const juce::MouseEvent& event)
{
    startDraggingComponent(this, event);
}

void Fader::mouseDrag(const juce::MouseEvent& event)
{
    dragComponent(this, event, &movableConstraints);
}