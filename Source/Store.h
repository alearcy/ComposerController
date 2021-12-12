#pragma once

#include <JuceHeader.h>
#include "Pad.h"
#include "Fader.h"

namespace Store
{

	inline std::unique_ptr<Pad> createPadFromStore(juce::ValueTree& pad, juce::ValueTree& store, bool isEditing)
	{
		auto newPad = std::make_unique<Pad>(store, pad.getProperty("name"));
		newPad->id = pad.getProperty("id");
		newPad->tabId = pad.getProperty("tabId");
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

	inline std::unique_ptr<Fader> createFaderFromStore(juce::ValueTree& fader, juce::ValueTree& store, bool isEditing)
	{
		auto newFader = std::make_unique<Fader>(store, fader.getProperty("name"));
		newFader->id = fader.getProperty("id");
		newFader->tabId = fader.getProperty("tabId");
		newFader->ccNumber = (int)fader.getProperty("ccNumber");
		newFader->ccValue = (int)fader.getProperty("ccValue");
		newFader->x = (int)fader.getProperty("x");
		newFader->y = (int)fader.getProperty("y");
		newFader->w = (int)fader.getProperty("w");
		newFader->h = (int)fader.getProperty("h");
		newFader->isEditingMode = isEditing;
		newFader->setBounds(newFader->x, newFader->y, newFader->w, newFader->h);
		return newFader;
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

	inline void setProperty(juce::ValueTree& store, juce::Identifier id, juce::var newValue)
	{
		store.setProperty(id, newValue, nullptr);
	}

	inline void exportStoreToXML(juce::ValueTree& store)
	{
		std::unique_ptr<juce::XmlElement> xml(store.createXml());
		xml->writeTo(juce::File(juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + "CCStore.xml"), juce::XmlElement::TextFormat());
	}

}