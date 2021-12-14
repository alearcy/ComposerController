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
                       public juce::ValueTree::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void initializeStore();

    juce::ValueTree store;

    std::vector<std::unique_ptr<Fader>> faders;
    std::vector<std::unique_ptr<Pad>> pads;
    std::vector<std::unique_ptr<Tab>> tabs;
    Header header = Header(store);
    Footer footer;


private:
    //void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    void valueTreeChildAdded(juce::ValueTree& parentTree, juce::ValueTree& childWhichHasBeenAdded) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
