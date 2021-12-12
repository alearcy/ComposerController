#pragma once

namespace Config
{
    enum MidiType {
        CONTROLCHANGE,
        NOTEON,
        PITCH
    };

    enum ComponentSizes
    {
        FADERWIDTH = 90,
        FADERHEIGHT = 430,
        PADWIDTH = 120,
        PADHEIGHT = 70
    };

    struct PAD
    {
        juce::String name;
        int tabId;
        int ccNumber;
        int ccValue;
        int x;
        int y;
        int w;
        int h;
    };
}