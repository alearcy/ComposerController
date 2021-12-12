#pragma once

#include <JuceHeader.h>
#include "Config.h"
#include "ButtonCustomStyle.h"
#include "CustomDragComponent.h"
#include "ControllerObject.h"

//==============================================================================
class Pad  : public juce::Component,
             public juce::ValueTree::Listener,
             public ControllerObject
{
public:
    Pad(juce::ValueTree& v);
    Pad(juce::ValueTree& v, juce::String name);
    ~Pad() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;

private:
    void valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property) override;
    juce::ComponentBoundsConstrainer movableConstraints;
    juce::ComponentBoundsConstrainer resizableConstraints;
    juce::ResizableCornerComponent resizableCorner = juce::ResizableCornerComponent(this, &resizableConstraints);
    juce::TextButton button;
    juce::TextButton moveButton;
    void init(juce::ValueTree& v, juce::String name);
    ButtonCustomStyle buttonCustomStyle;
    CustomDragComponent dragComponent;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pad)
};
