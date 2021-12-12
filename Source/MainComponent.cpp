#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{   
    initializeStore();
    auto fader = std::make_unique<Fader>(store, "Fader");
    fader->tabId = "1";
    fader->ccNumber = 11;
    fader->ccValue = 50;
    fader->setBounds(20, 90, fader->faderWidth, fader->faderHeight);
    faders.push_back(std::move(fader));

    auto fader2 = std::make_unique<Fader>(store, "Fader");
    fader2->tabId = "1";
    fader2->ccNumber = 1;
    fader2->ccValue = 50;
    fader2->setBounds(130, 90, fader2->faderWidth, fader2->faderHeight);
    faders.push_back(std::move(fader2));
    
    for (auto &f : faders)
        addAndMakeVisible(*f);



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


    for (auto &f : faders)
    {
        int x = f->getBounds().getX();
        int y = f->getBounds().getY();
        f->setBounds(x, y, f->getWidth(), f->getHeight());
    }

    for (auto &p : pads)
    {
        p->setBounds(p->x, p->y, p->w, p->h);
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
    store.addListener(this);

    DBG(juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + juce::File::getSeparatorString() + "CCStore.xml");

    juce::File storeFile = juce::File(juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + "CCStore.xml");
    auto xml(juce::XmlDocument::parse(storeFile));

    if (!storeFile.existsAsFile() || xml == nullptr) {
        DBG("Non esiste");
        return;
    }

    // Replace default store ValueTree with the loaded one
    store.copyPropertiesAndChildrenFrom(juce::ValueTree::fromXml(*xml), nullptr);
    auto padsArray = store.getChildWithName("Pads");
    if (padsArray.isValid())
    {
        for (auto& pad : padsArray)
        {
            auto newPad = Utility::createPadFromStore(pad, store, false);
            pads.push_back(std::move(newPad));
            for (auto& p : pads)
            {
                addAndMakeVisible(*p);
            }
        }
    }
    else
    {
        DBG("Non valido");
    }
    
}

void MainComponent::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged,
    const juce::Identifier& property)
{
    auto value = (bool)(treeWhosePropertyHasChanged.getProperty(property));
}

void MainComponent::valueTreeChildAdded(juce::ValueTree& parentTree, juce::ValueTree& childWhichHasBeenAdded)
{
    DBG(store.getRoot().toXmlString());
    DBG(juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + juce::File::getSeparatorString() + "CCStore.xml");
    std::unique_ptr<juce::XmlElement> xml(store.createXml());
    xml->writeTo(juce::File(juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + "CCStore.xml"), juce::XmlElement::TextFormat());
    
    auto newPad = Utility::createPadFromStore(childWhichHasBeenAdded, store, true);
    pads.push_back(std::move(newPad));
    for (auto& p : pads)
    {
        addAndMakeVisible(*p);
    }
}