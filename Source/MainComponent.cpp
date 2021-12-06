#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{   
    initializeStore();
    auto fader = std::make_unique<Fader>(store, "c11");
    fader->tabId = "1";
    fader->ccNumber = 11;
    fader->ccValue = 50;
    //fader->addChangeListener(this);
    faders.push_back(std::move(fader));

    auto fader2 = std::make_unique<Fader>(store, "c1");
    fader2->tabId = "1";
    fader2->ccNumber = 1;
    fader2->ccValue = 50;
    //fader2->addChangeListener(this);
    //fader2->setBounds(300, 100, 90, 450);
    faders.push_back(std::move(fader2));
    
    for (auto &f : faders)
        addAndMakeVisible(*f);

    auto pad = std::make_unique<Pad>("Play");
    pad->tabId = "1";
    pad->ccNumber = 11;
    pad->ccValue = 50;
    //pad->addChangeListener(this);
    pads.push_back(std::move(pad));

    for (auto &p : pads)
        addAndMakeVisible(*p);

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
    //for (auto &f : faders)
    //    f->removeAllChangeListeners();
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


    for (auto &f : faders)
    {
        int x = f->getBounds().getX();
        int y = f->getBounds().getY();
        f->setBounds(x, y, f->getWidth(), f->getHeight());
    }

    for (auto &p : pads)
    {
        int x = p->getBounds().getX();
        int y = p->getBounds().getY();
        p->setBounds(x, y, p->getWidth(), p->getHeight());
    }

    // TODO: move this in tab component in a FlexBox like header
    for (auto &t : tabs)
    {
        t->setBounds(mainArea.removeFromTop(tabsHeight));
    }
}

void MainComponent::initializeStore()
{
    store = Utility::store();
}