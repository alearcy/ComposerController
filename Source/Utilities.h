#pragma once

#include <JuceHeader.h>
#include "Pad.h"

namespace Utility
{

	inline void setRoundedPosition(juce::Component& component, const int approximationConstant)
	{
		int x = component.getPosition().getX();
		int y = component.getPosition().getY();
		int roundedX = x + abs((x % approximationConstant) - approximationConstant);
		int roundedY = y + abs((y % approximationConstant) - approximationConstant);
		int w = component.getWidth();
		int h = component.getHeight();
		component.setBounds(roundedX, roundedY, w, h);
	}

	inline void setRoundedSizes(juce::Component& component, const int approximationConstant)
	{
		int x = component.getPosition().getX();
		int y = component.getPosition().getY();
		int w = component.getWidth();
		int h = component.getHeight();
		int roundedW = w + abs((w % approximationConstant) - approximationConstant);
		int roundedH = h + abs((h % approximationConstant) - approximationConstant);
		component.setBounds(x, y, roundedW, roundedH);
	}

	inline std::unique_ptr<Pad> createPadFromStore(juce::ValueTree& pad, juce::ValueTree& store, bool isEditing)
	{
		auto newPad = std::make_unique<Pad>(store, pad.getProperty("name"));
		newPad->tabId = pad.getProperty("tabId").toString();
		newPad->ccNumber = (int)pad.getProperty("ccNumber");
		newPad->ccValue = (int)pad.getProperty("ccValue");
		newPad->x = (int)pad.getProperty("x");
		newPad->y = (int)pad.getProperty("y");
		newPad->w = (int)pad.getProperty("w");
		newPad->h = (int)pad.getProperty("h");
		newPad->isEditingMode = isEditing;
		newPad->setBounds(newPad->x, newPad->y, newPad->w, newPad->h);
		return newPad;
	}


	inline juce::ValueTree store()
	{
		static juce::Identifier CCState("CCState");
		static juce::Identifier Tabs("Tabs");
		static juce::Identifier Faders("Faders");
		static juce::Identifier Pads("Pads");
		juce::ValueTree store(CCState);
		static juce::Identifier isEditing("isEditing");
		store.setProperty(isEditing, false, nullptr);
		juce::ValueTree tabs(Tabs);
		juce::ValueTree faders(Faders);
		juce::ValueTree pads(Pads);
		store.appendChild(tabs, nullptr);
		store.appendChild(faders, nullptr);
		store.appendChild(pads, nullptr);
		return store;
	}

	inline void setProperty(juce::ValueTree& v, juce::Identifier id, juce::var newValue)
	{
		v.setProperty(id, newValue, nullptr);
	}
}