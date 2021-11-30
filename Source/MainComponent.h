#pragma once

#include <JuceHeader.h>
#include "Fader.h"
#include "Header.h"
#include "Footer.h"
#include "Tab.h"
#include "Pad.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, 
                       public juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void changeListenerCallback(juce::ChangeBroadcaster* source);
    void resized() override;

    std::vector<std::unique_ptr<Fader>> faders;
    std::vector<std::unique_ptr<Pad>> pads;
    std::vector<std::unique_ptr<Tab>> tabs;
    Header header;
    Footer footer;

private:
    //==============================================================================
    // Your private member variables go here...
    //Fader cc1 {"cc1"};
    //Fader cc11 {"cc11"};
    //Fader cc2 {"cc2"};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
