/*
  ==============================================================================

    Tab.cpp
    Created: 19 Nov 2021 6:57:33pm
    Author:  arcid

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Tab.h"

//==============================================================================
Tab::Tab()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    shadow.setOwner(this);
}

Tab::~Tab()
{
}

void Tab::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (juce::Colour(0xff5a5a5a));

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Tab", getLocalBounds(),
                juce::Justification::centred, true);
}

void Tab::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
