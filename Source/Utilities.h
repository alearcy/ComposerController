#pragma once
#include <JuceHeader.h>

namespace Utility
{

	static void setRoundedPosition(juce::Component& component, const int approximationConstant)
	{
		int x = component.getPosition().getX();
		int y = component.getPosition().getY();
		int roundedX = x + abs((x % approximationConstant) - approximationConstant);
		int roundedY = y + abs((y % approximationConstant) - approximationConstant);
		int w = component.getWidth();
		int h = component.getHeight();
		component.setBounds(roundedX, roundedY, w, h);
	}

	static void setRoundedSizes(juce::Component& component, const int approximationConstant)
	{
		int x = component.getPosition().getX();
		int y = component.getPosition().getY();
		int w = component.getWidth();
		int h = component.getHeight();
		int roundedW = w + abs((w % approximationConstant) - approximationConstant);
		int roundedH = h + abs((h % approximationConstant) - approximationConstant);
		component.setBounds(x, y, roundedW, roundedH);
	}

	inline juce::ValueTree store()
	{
		static juce::Identifier CCState("CCState");
		juce::ValueTree store(CCState);
		static juce::Identifier isEditing("isEditing");
		store.setProperty(isEditing, false, nullptr);
		return store;
	}

	inline void setProperty(juce::ValueTree& v, juce::Identifier id, juce::var newValue)
	{
		v.setProperty(id, newValue, nullptr);
	}
}