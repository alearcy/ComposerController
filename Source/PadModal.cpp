#include <JuceHeader.h>
#include "PadModal.h"
#include "Utilities.h"

//==============================================================================
PadModal::PadModal()
{
    addAndMakeVisible(name);
    addAndMakeVisible(nameEditor);
    addAndMakeVisible(ccValue);
    addAndMakeVisible(color);
    addAndMakeVisible(ccValueEditor);
    addAndMakeVisible(ccNumber);
    addAndMakeVisible(ccNumberEditor);
    addAndMakeVisible(saveButton);
    addAndMakeVisible(colorChange);

    colorChange.onClick = [&]()
    {
        auto colourSelector = std::make_unique<juce::ColourSelector>(juce::ColourSelector::showAlphaChannel
            | juce::ColourSelector::showColourAtTop
            | juce::ColourSelector::editableColour
            | juce::ColourSelector::showSliders
            | juce::ColourSelector::showColourspace);

        colourSelector->setName("background");
        colourSelector->setCurrentColour(findColour(juce::TextButton::buttonColourId));
        colourSelector->addChangeListener(this);
        colourSelector->setColour(juce::ColourSelector::backgroundColourId, juce::Colours::transparentBlack);
        colourSelector->setSize(300, 400);

        juce::CallOutBox::launchAsynchronously(std::move(colourSelector), getScreenBounds(), nullptr);
    };


    saveButton.setLookAndFeel(&buttonCustomStyle);
    saveButton.setButtonText("Save");
    colorChange.setLookAndFeel(&buttonCustomStyle);

    name.setText("Pad name:", juce::NotificationType::dontSendNotification);
    name.setJustificationType(juce::Justification::centredLeft);
    name.setColour(juce::Label::textColourId, juce::Colours::white);
    name.attachToComponent(&nameEditor, false);

    nameEditor.setCaretVisible(false);
    nameEditor.setColour(juce::TextEditor::ColourIds::backgroundColourId, juce::Colour(0xff5a5a5a));
    nameEditor.setColour(juce::TextEditor::ColourIds::outlineColourId, juce::Colour(0x00));

    ccValue.setText("CC value (1-127):", juce::NotificationType::dontSendNotification);
    ccValue.setJustificationType(juce::Justification::centredLeft);
    ccValue.setColour(juce::Label::textColourId, juce::Colours::white);
    ccValue.attachToComponent(&ccValueEditor, false);

    ccValueEditor.setCaretVisible(false);
    ccValueEditor.setColour(juce::TextEditor::ColourIds::backgroundColourId, juce::Colour(0xff5a5a5a));
    ccValueEditor.setColour(juce::TextEditor::ColourIds::outlineColourId, juce::Colour(0x00));

    ccNumber.setText("CC number (1-127):", juce::NotificationType::dontSendNotification);
    ccNumber.setJustificationType(juce::Justification::centredLeft);
    ccNumber.setColour(juce::Label::textColourId, juce::Colours::white);
    ccNumber.attachToComponent(&ccNumberEditor, false);

    ccNumberEditor.setCaretVisible(false);
    ccNumberEditor.setColour(juce::TextEditor::ColourIds::backgroundColourId, juce::Colour(0xff5a5a5a));
    ccNumberEditor.setColour(juce::TextEditor::ColourIds::outlineColourId, juce::Colour(0x00));

    color.attachToComponent(&colorChange, false);
    color.setText("Colore del pad:", juce::NotificationType::dontSendNotification);

    setSize(300, 400);
}

PadModal::~PadModal()
{
}

void PadModal::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff27282c));
    g.setColour(juce::Colours::grey);
    g.setColour(juce::Colours::white);
    g.setFont(16.0f);
}

void PadModal::resized()
{
    const int marginBottom = 20;
    const int labelHeight = 30;
    const int offset = 20;
    const int spaceBetween = marginBottom + labelHeight + offset;
    nameEditor.setBounds(20, 40, getWidth() - 40, 30);
    ccNumberEditor.setBounds(20, nameEditor.getY() + spaceBetween, getWidth() - 40, 30);
    ccValueEditor.setBounds(20, ccNumberEditor.getY() + spaceBetween, getWidth() - 40, 30);
    colorChange.setBounds(20, ccValueEditor.getY() + spaceBetween, getWidth() - 40, 30);
    saveButton.setBounds(20, colorChange.getY() + spaceBetween, getWidth() - 40, 30);
}

void PadModal::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (auto* cs = dynamic_cast<juce::ColourSelector*> (source))
        colorChange.setColour(juce::TextButton::buttonColourId, cs->getCurrentColour());
}