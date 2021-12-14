#pragma once

#include <JuceHeader.h>
#include "Store.h"

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
}