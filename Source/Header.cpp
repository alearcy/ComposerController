#include <JuceHeader.h>
#include "Header.h"

//==============================================================================
Header::Header()
{
    addAndMakeVisible(editBtn);
    editBtn.setButtonText("edit");
    addAndMakeVisible(logoName);
    logoName.setText(juce::String("Composer Controller"), juce::NotificationType::dontSendNotification);
    shadow.setOwner(this);
}

Header::~Header()
{
}

void Header::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff37383c));
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
}

void Header::resized()
{
    juce::FlexBox fb;
    fb.justifyContent = juce::FlexBox::JustifyContent::spaceBetween;
    fb.alignItems = juce::FlexBox::AlignItems::center;
    fb.alignContent = juce::FlexBox::AlignContent::center;
    fb.items.add(juce::FlexItem(logoName).withHeight(20).withWidth(150).withMargin(20));
    fb.items.add(juce::FlexItem(editBtn).withHeight(20).withWidth(50).withMargin(20));
    fb.performLayout(getLocalBounds());
}
