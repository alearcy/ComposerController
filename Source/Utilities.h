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
		component.setBounds(roundedX, roundedY, component.getWidth(), component.getHeight());
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