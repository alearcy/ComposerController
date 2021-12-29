#include <JuceHeader.h>
#include "Header.h"
#include "Utilities.h"
#include "Config.h"
#include "Store.h"

//==============================================================================
Header::Header(juce::ValueTree& store)
{
    //store.addListener(this);
    addAndMakeVisible(editBtn);
    editBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
    editBtn.onClick = [&]() 
    { 
        auto buttonState = editBtn.getToggleState();
        if (!buttonState) {
            isEditingMode = true;
            editBtn.setToggleState(true, juce::NotificationType::dontSendNotification);
            store.setProperty("isEditing", true, nullptr);
            addAndMakeVisible(addPad);
            addAndMakeVisible(addFader);
            
        }
        else {
            isEditingMode = false;
            editBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
            store.setProperty("isEditing", false, nullptr);
            addPad.setVisible(false);
            addFader.setVisible(false);
            Store::exportStoreToXML(store);
        }
    };
    addPad.onClick = [&]()
    {
        juce::String UUID = juce::Uuid::Uuid().toString();
        auto pads = store.getChildWithName("Pads");
        juce::Identifier pad("Pad");
        juce::ValueTree newPad(pad);
        newPad.setProperty("id", UUID, nullptr);
        newPad.setProperty("name", "Pad", nullptr);
        newPad.setProperty("tabId", 1, nullptr);
        newPad.setProperty("x", 20, nullptr);
        newPad.setProperty("y", 90, nullptr);
        newPad.setProperty("w", Config::PADWIDTH, nullptr);
        newPad.setProperty("h", Config::PADHEIGHT, nullptr);
        newPad.setProperty("ccNumber", 11, nullptr);
        newPad.setProperty("ccValue", 50, nullptr);
        pads.appendChild(newPad, nullptr);
    };

    addFader.onClick = [&]()
    {
        juce::String UUID = juce::Uuid::Uuid().toString();
        auto faders = store.getChildWithName("Faders");
        juce::Identifier fader("Fader");
        juce::ValueTree newFader(fader);
        newFader.setProperty("id", UUID, nullptr);
        newFader.setProperty("name", "Fader", nullptr);
        newFader.setProperty("tabId", 1, nullptr);
        newFader.setProperty("x", 20, nullptr);
        newFader.setProperty("y", 90, nullptr);
        newFader.setProperty("w", Config::FADERWIDTH, nullptr);
        newFader.setProperty("h", Config::FADERHEIGHT, nullptr);
        newFader.setProperty("ccNumber", 11, nullptr);
        newFader.setProperty("ccValue", 50, nullptr);
        faders.appendChild(newFader, nullptr);
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