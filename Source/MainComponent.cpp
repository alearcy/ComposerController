#include "MainComponent.h"
#include "Store.h"
#include "Utilities.h"

//==============================================================================
MainComponent::MainComponent()
{   
    initializeStore();

    //TODO: make active tab and generate UUID
    auto tab = std::make_unique<Tab>();
    tab->id = "1";
    tabs.push_back(std::move(tab));

    for (auto &t : tabs)
        addAndMakeVisible(*t);

    addAndMakeVisible(header);

    setSize(1024, 768);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff27282c));
    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
}

void MainComponent::resized()
{  
    auto mainArea = getLocalBounds();
    auto headerHeight = 40;
    auto tabsHeight = 40;
    header.setBounds(mainArea.removeFromTop(headerHeight));
    if (pads.size() > 0)
    {
        //TODO:: valutare se è più efficiente leggere direttamente da x e non fare il getBounds
        for (auto &p : pads)
        {
            p->setBounds(p->getBounds().getX(), p->getBounds().getY(), p->getBounds().getWidth(), p->getBounds().getHeight());
        }
    }

    if (faders.size() > 0)
    {
        for (auto& f : faders)
        {
            f->setBounds(f->getBounds().getX(), f->getBounds().getY(), f->getBounds().getWidth(), f->getBounds().getHeight());
        }
    }

    // TODO: move this in tab component in a FlexBox like header
    for (auto &t : tabs)
    {
        t->setBounds(mainArea.removeFromTop(tabsHeight));
    }
}

void MainComponent::initializeStore()
{
    store = Store::store();
    store.addListener(this);

    auto padsFromStore = store.getChildWithName("Pads");
    auto fadersFromStore = store.getChildWithName("Faders");
    if (padsFromStore.getNumChildren() > 0)
    {
        for (auto& pad : padsFromStore)
        {
            auto newPad = Store::createPadFromStore(pad, store, false);
            pads.push_back(std::move(newPad));
            for (auto& p : pads)
            {
                addAndMakeVisible(*p);
            }
        }
    }
    if (fadersFromStore.getNumChildren() > 0)
    {
        for (auto& fader : fadersFromStore)
        {
            auto newFader = Store::createFaderFromStore(fader, store, false);
            faders.push_back(std::move(newFader));
            for (auto& p : faders)
            {
                addAndMakeVisible(*p);
            }
        }
    }
}

void MainComponent::valueTreeChildAdded(juce::ValueTree& parentTree, juce::ValueTree& childWhichHasBeenAdded)
{
    DBG(store.getRoot().toXmlString());
    juce::String componentType = childWhichHasBeenAdded.getType().toString();
    if (componentType == "Pad")
    {
        auto newPad = Store::createPadFromStore(childWhichHasBeenAdded, store, true);
        pads.push_back(std::move(newPad));
        for (auto& p : pads)
        {
            addAndMakeVisible(*p);
        }
    }
    if (componentType == "Fader")
    {
        auto newFader = Store::createFaderFromStore(childWhichHasBeenAdded, store, true);
        faders.push_back(std::move(newFader));
        for (auto& p : faders)
        {
            addAndMakeVisible(*p);
        }
    }

}