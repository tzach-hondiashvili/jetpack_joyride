#include "ChooseSkinState.h"
#include "Menu.h"
#include "KingSkinOption.h"
#include "OriginalSkinOption.h"
#include "ScientistBerrySkin.h"
#include "SoldierBerrySkin.h"

ChooseSkinState::ChooseSkinState(Menu* menu)
{
    updateMenu(menu);

    if (menu->finishedLoading())
    {
        m_backGround.setTexture(Resources::instance().getOtherTexture(3));

        m_skins.emplace_back(std::make_pair("KingSkinOption", std::make_unique<KingSkinOption>(getMenu())));
        m_skins.emplace_back(std::make_pair("OriginalSkinOption", std::make_unique<OriginalSkinOption>(getMenu())));
        m_skins.emplace_back(std::make_pair("SoldierBerrySkin", std::make_unique<SoldierBerrySkin>(getMenu())));
        m_skins.emplace_back(std::make_pair("ScientistBerrySkin", std::make_unique<ScientistBerrySkin>(getMenu())));
    }
}

void ChooseSkinState::update(float deltaTime)
{
}

void ChooseSkinState::print()
{
 
    getMenu()->getWindow().draw(m_backGround);

    for (int i = 0; i < m_skins.size(); i++)
    {

        getMenu()->getWindow().draw(m_skins[i].second->getSprite());
    }
}

void ChooseSkinState::handleClick(const sf::Event::MouseButtonEvent& event)
{
    for (int i = 0; i < m_skins.size(); i++)
    {
        if (m_skins[i].second->getSprite().getGlobalBounds().contains(getMenu()->getWindow().mapPixelToCoords({ event.x, event.y })))
        {
            m_skins[i].second->execute();
            return;
        }
    }
}


void ChooseSkinState::hoverButton(sf::Vector2i position)
{
}
