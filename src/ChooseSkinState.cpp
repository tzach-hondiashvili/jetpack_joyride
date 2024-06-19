#include "ChooseSkinState.h"
#include "Menu.h"
#include "KingSkinOption.h"
#include "OriginalSkinOption.h"
#include "ScientistBerrySkin.h"
#include "SoldierBerrySkin.h"

ChooseSkinState::ChooseSkinState(Menu* menu)
{
    updateMenu(menu);

    m_ChooseSkin.setFont(Resources::instance().getFont());
    m_ChooseSkin.setString("CHOOSE SKIN");
    m_ChooseSkin.setCharacterSize(100);
    m_ChooseSkin.setPosition({ 500,200 });
    m_ChooseSkin.setFillColor(sf::Color(77,120,125));
    m_ChooseSkin.setOutlineThickness(3);
    m_ChooseSkin.setOutlineColor(sf::Color(77, 132, 196));

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
    getMenu()->getWindow().draw(m_ChooseSkin);


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
