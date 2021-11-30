/*
  ==============================================================================

    Header.cpp
    Created: 19 Nov 2021 6:57:03pm
    Author:  arcid

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Header.h"

//==============================================================================
Header::Header()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    shadow.setOwner(this);
}

Header::~Header()
{
}

void Header::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (juce::Colour(0xff37383c));

    g.setColour (juce::Colours::white);

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Composer Controller", getLocalBounds(),
                juce::Justification::centredLeft, true);   // draw some placeholder text
}

void Header::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
