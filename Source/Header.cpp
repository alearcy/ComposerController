#include <JuceHeader.h>
#include "Header.h"
#include "Utilities.h"

//==============================================================================
Header::Header(juce::ValueTree& v)
{
    addAndMakeVisible(editBtn);
    editBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
    editBtn.onClick = [&]() 
    { 
        auto buttonState = editBtn.getToggleState();
        if (!buttonState) {
            editBtn.setToggleState(true, juce::NotificationType::dontSendNotification);
            v.setProperty("isEditing", true, nullptr);
            addAndMakeVisible(addPad);
            addAndMakeVisible(addFader);
        }
        else {
            editBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
            v.setProperty("isEditing", false, nullptr);
            addPad.setVisible(false);
            addFader.setVisible(false);
        }
    };
    addPad.onClick = [&]()
    {
        v.setProperty("isEditing", true, nullptr);
    };
    addAndMakeVisible(logoName);
    logoName.setText(juce::String("Composer Controller"), juce::NotificationType::dontSendNotification);
    shadow.setOwner(this);
}

Header::~Header()
{
}

//==============================================================================
void Header::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff37383c));
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
}

void Header::resized()
{
    juce::FlexBox mainFb;
    juce::FlexBox rightFb;
    mainFb.justifyContent = juce::FlexBox::JustifyContent::spaceBetween;
    mainFb.alignItems = juce::FlexBox::AlignItems::center;
    mainFb.alignContent = juce::FlexBox::AlignContent::center;

    rightFb.justifyContent = juce::FlexBox::JustifyContent::flexEnd;
    rightFb.alignItems = juce::FlexBox::AlignItems::center;
    rightFb.alignContent = juce::FlexBox::AlignContent::center;

    mainFb.items.add(juce::FlexItem(logoName).withHeight(20).withWidth(150).withMargin(20));
    mainFb.items.add(juce::FlexItem(rightFb).withFlex(1.0f));
    rightFb.items.add(juce::FlexItem(addFader).withHeight(20).withWidth(50).withMargin(10));
    rightFb.items.add(juce::FlexItem(addPad).withHeight(20).withWidth(50).withMargin(10));
    rightFb.items.add(juce::FlexItem(editBtn).withHeight(20).withWidth(50).withMargin(10));
    mainFb.performLayout(getLocalBounds());
}

void Header::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged,
    const juce::Identifier& property)
{
    auto value = (bool)(treeWhosePropertyHasChanged.getProperty(property));
    isEditingMode = value;
    if (value)
    {

    }
    else
    {

    }
}