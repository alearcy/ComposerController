#pragma once

#include <JuceHeader.h>
#include "Config.h"
#include "CustomDragComponent.h"
#include "ControllerObject.h"

//==============================================================================
/*
*/

class Fader  : public juce::Component, 
               public juce::ValueTree::Listener,
               public ControllerObject
{
public:
    Fader(juce::ValueTree& store);
 
    Fader(juce::ValueTree& store, juce::String name);
    
    ~Fader() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    juce::Label faderLabel;

private:
    juce::ValueTree i_store;
    void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::ComponentBoundsConstrainer movableConstraints;
    juce::ComponentBoundsConstrainer resizableConstraints;
    juce::ResizableCornerComponent resizableCorner = juce::ResizableCornerComponent(this, &resizableConstraints);
    juce::Slider slider;
    CustomDragComponent dragComponent;
    void init(juce::ValueTree& store, juce::String name);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Fader)
};
