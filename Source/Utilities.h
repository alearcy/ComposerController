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
}